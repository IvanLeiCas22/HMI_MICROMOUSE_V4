#include "unerbusparser.h"
#include <QDebug>

UnerbusParser::UnerbusParser(QObject *parent)
    : QObject(parent)
{
    reset();
}

/**
 * @brief Procesa los datos crudos recibidos del puerto serie.
 * @param data QByteArray con los nuevos datos.
 */
void UnerbusParser::processData(const QByteArray &data)
{
    // Agrega los nuevos datos al buffer interno para procesarlos
    buffer.append(data);

    // Itera sobre el buffer mientras haya bytes para procesar
    while (!buffer.isEmpty())
    {
        // Extrae el primer byte del buffer para analizarlo
        quint8 byte = buffer.at(0);

        switch (currentState)
        {
        case State::WaitingForU:
            if (static_cast<char>(byte) == Unerbus::HEADER[0])
            {
                currentState = State::WaitingForN;
                calculatedChecksum = byte; // Inicia el cálculo del checksum
            }
            break;

        case State::WaitingForN:
            if (static_cast<char>(byte) == Unerbus::HEADER[1])
            {
                currentState = State::WaitingForE;
                calculatedChecksum ^= byte;
            }
            else
            {
                reset(); // Secuencia incorrecta, reinicia
            }
            break;

        case State::WaitingForE:
            if (static_cast<char>(byte) == Unerbus::HEADER[2])
            {
                currentState = State::WaitingForR;
                calculatedChecksum ^= byte;
            }
            else
            {
                reset();
            }
            break;

        case State::WaitingForR:
            if (static_cast<char>(byte) == Unerbus::HEADER[3])
            {
                currentState = State::WaitingForLength;
                calculatedChecksum ^= byte;
            }
            else
            {
                reset();
            }
            break;

        case State::WaitingForLength:
            expectedLength = byte;
            calculatedChecksum ^= byte;
            currentState = State::WaitingForToken;
            break;

        case State::WaitingForToken:
            if (static_cast<char>(byte) == Unerbus::TOKEN)
            {
                calculatedChecksum ^= byte;
                // Si el payload tiene longitud 0, el siguiente byte es el checksum
                if (expectedLength <= 1)
                { // Length = 1 (solo checksum)
                    currentState = State::ReadingPayloadAndChecksum;
                }
                else
                {
                    // Si hay payload, nos preparamos para leerlo
                    currentState = State::ReadingPayloadAndChecksum;
                }
            }
            else
            {
                reset(); // Token incorrecto
            }
            break;

        case State::ReadingPayloadAndChecksum:
            // El paquete completo (CMD + Payload + Checksum) debe estar en el buffer
            // Longitud total del paquete = 7 (cabecera) + N (payload) + 1 (checksum)
            // Longitud en el protocolo = 1 (CMD) + N (payload) + 1 (checksum)
            // Bytes restantes a leer = expectedLength
            if (buffer.size() >= expectedLength)
            {
                // Extraemos el paquete completo (CMD, Payload, Checksum)
                QByteArray fullPacket = buffer.left(expectedLength);
                buffer.remove(0, expectedLength); // Quitamos el paquete del buffer

                // El comando es el primer byte del paquete
                quint8 command = fullPacket.at(0);
                // El payload son los bytes intermedios
                QByteArray payload = fullPacket.mid(1, expectedLength - 2);
                // El checksum es el último byte
                quint8 receivedChecksum = fullPacket.back();

                // Calculamos el checksum del CMD y el Payload
                calculatedChecksum ^= command;
                for (char payloadByte : payload)
                {
                    calculatedChecksum ^= static_cast<quint8>(payloadByte);
                }

                // Verificamos si el checksum es correcto
                if (calculatedChecksum == receivedChecksum)
                {
                    // ¡Paquete válido! Emitimos la señal
                    emit packetReceived(command, payload);
                }
                else
                {
                    // Error de checksum
                    emit parsingError(QString("Error de Checksum. Calculado: 0x%1, Recibido: 0x%2")
                                          .arg(calculatedChecksum, 2, 16, QChar('0'))
                                          .arg(receivedChecksum, 2, 16, QChar('0')));
                }
                // Reiniciamos para buscar el siguiente paquete
                reset();
                continue; // Volvemos al inicio del while para procesar el resto del buffer
            }
            else
            {
                // No han llegado todos los datos del payload, salimos y esperamos más
                return;
            }
            break;
        }

        // Si llegamos aquí, el byte fue procesado, lo removemos del buffer
        // excepto si estamos esperando más datos del payload.
        if (currentState != State::ReadingPayloadAndChecksum)
        {
            buffer.remove(0, 1);
        }
    }
}

/**
 * @brief Reinicia la máquina de estados a su estado inicial.
 */
void UnerbusParser::reset()
{
    currentState = State::WaitingForU;
    expectedLength = 0;
    calculatedChecksum = 0;
    // No limpiamos el buffer aquí, porque puede haber un paquete válido más adelante
}