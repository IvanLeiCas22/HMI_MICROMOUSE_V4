/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *navigationFrame;
    QVBoxLayout *verticalLayout;
    QLabel *logoLabel;
    QFrame *line;
    QPushButton *btnHome;
    QPushButton *btnSensors;
    QPushButton *btnConfig;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedScreens;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QLabel *titleHome;
    QGroupBox *groupConnection;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupSerie;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *portLabel;
    QComboBox *comboBoxPorts;
    QPushButton *btnRefreshPorts;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnConnectSerie;
    QPushButton *btnDisconnectSerie;
    QGroupBox *groupUDP;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout;
    QLabel *localPortLabel;
    QLineEdit *localPortLineEdit;
    QLineEdit *RemoteIpLineEdit;
    QLabel *RemoteIPLabel;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnConnectUDP;
    QPushButton *btnDisconnectUDP;
    QLabel *labelCommStatus;
    QGroupBox *groupCMDSend;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *CMDTitleLabel;
    QComboBox *CMDComboBox;
    QPushButton *btnSendCMD;
    QPlainTextEdit *commsLog;
    QWidget *page_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        navigationFrame = new QFrame(centralwidget);
        navigationFrame->setObjectName("navigationFrame");
        QFont font;
        font.setPointSize(12);
        navigationFrame->setFont(font);
        navigationFrame->setStyleSheet(QString::fromUtf8("QFrame#navigationFrame {\n"
"  background-color: rgb(45, 58, 75);\n"
"  border-radius: 12px;\n"
"  margin: 8px;\n"
"}"));
        navigationFrame->setFrameShape(QFrame::StyledPanel);
        navigationFrame->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(navigationFrame);
        verticalLayout->setObjectName("verticalLayout");
        logoLabel = new QLabel(navigationFrame);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setMinimumSize(QSize(0, 60));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setItalic(false);
        logoLabel->setFont(font1);
        logoLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-weight: bold;\n"
"text-align: center;"));
        logoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(logoLabel);

        line = new QFrame(navigationFrame);
        line->setObjectName("line");
        line->setStyleSheet(QString::fromUtf8("background-color: #3e5063;"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        btnHome = new QPushButton(navigationFrame);
        btnHome->setObjectName("btnHome");
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        btnHome->setFont(font2);
        btnHome->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: #2d3a4b;\n"
"  color: white;\n"
"  border-radius: 4px;\n"
"  padding: 10px;\n"
"  font-weight: bold;\n"
"  text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  background-color: rgb(174, 188, 191);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"  background-color: rgb(28, 39, 54);\n"
"}"));
        btnHome->setCheckable(true);
        btnHome->setChecked(true);

        verticalLayout->addWidget(btnHome);

        btnSensors = new QPushButton(navigationFrame);
        btnSensors->setObjectName("btnSensors");
        btnSensors->setFont(font2);
        btnSensors->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: #2d3a4b;\n"
"  color: white;\n"
"  border-radius: 4px;\n"
"  padding: 10px;\n"
"  font-weight: bold;\n"
"  text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  background-color: rgb(174, 188, 191);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"  background-color: rgb(28, 39, 54);\n"
"}"));
        btnSensors->setCheckable(true);

        verticalLayout->addWidget(btnSensors);

        btnConfig = new QPushButton(navigationFrame);
        btnConfig->setObjectName("btnConfig");
        btnConfig->setFont(font2);
        btnConfig->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color: #2d3a4b;\n"
"  color: white;\n"
"  border-radius: 4px;\n"
"  padding: 10px;\n"
"  font-weight: bold;\n"
"  text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  background-color: rgb(174, 188, 191);\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"  background-color: rgb(28, 39, 54);\n"
"}"));
        btnConfig->setCheckable(true);

        verticalLayout->addWidget(btnConfig);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(navigationFrame);

        stackedScreens = new QStackedWidget(centralwidget);
        stackedScreens->setObjectName("stackedScreens");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName("verticalLayout_2");
        titleHome = new QLabel(page);
        titleHome->setObjectName("titleHome");
        QFont font3;
        font3.setPointSize(18);
        font3.setBold(true);
        titleHome->setFont(font3);
        titleHome->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(titleHome);

        groupConnection = new QGroupBox(page);
        groupConnection->setObjectName("groupConnection");
        groupConnection->setFont(font);
        verticalLayout_3 = new QVBoxLayout(groupConnection);
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupSerie = new QGroupBox(groupConnection);
        groupSerie->setObjectName("groupSerie");
        verticalLayout_4 = new QVBoxLayout(groupSerie);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        portLabel = new QLabel(groupSerie);
        portLabel->setObjectName("portLabel");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(portLabel->sizePolicy().hasHeightForWidth());
        portLabel->setSizePolicy(sizePolicy);
        portLabel->setMargin(0);

        horizontalLayout_4->addWidget(portLabel);

        comboBoxPorts = new QComboBox(groupSerie);
        comboBoxPorts->setObjectName("comboBoxPorts");

        horizontalLayout_4->addWidget(comboBoxPorts);

        btnRefreshPorts = new QPushButton(groupSerie);
        btnRefreshPorts->setObjectName("btnRefreshPorts");

        horizontalLayout_4->addWidget(btnRefreshPorts);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        btnConnectSerie = new QPushButton(groupSerie);
        btnConnectSerie->setObjectName("btnConnectSerie");

        horizontalLayout_5->addWidget(btnConnectSerie);

        btnDisconnectSerie = new QPushButton(groupSerie);
        btnDisconnectSerie->setObjectName("btnDisconnectSerie");

        horizontalLayout_5->addWidget(btnDisconnectSerie);


        verticalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout_3->addWidget(groupSerie);

        groupUDP = new QGroupBox(groupConnection);
        groupUDP->setObjectName("groupUDP");
        verticalLayout_5 = new QVBoxLayout(groupUDP);
        verticalLayout_5->setObjectName("verticalLayout_5");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        localPortLabel = new QLabel(groupUDP);
        localPortLabel->setObjectName("localPortLabel");
        localPortLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        localPortLabel->setMargin(0);

        gridLayout->addWidget(localPortLabel, 0, 0, 1, 1);

        localPortLineEdit = new QLineEdit(groupUDP);
        localPortLineEdit->setObjectName("localPortLineEdit");

        gridLayout->addWidget(localPortLineEdit, 0, 1, 1, 1);

        RemoteIpLineEdit = new QLineEdit(groupUDP);
        RemoteIpLineEdit->setObjectName("RemoteIpLineEdit");
        RemoteIpLineEdit->setReadOnly(true);

        gridLayout->addWidget(RemoteIpLineEdit, 1, 1, 1, 1);

        RemoteIPLabel = new QLabel(groupUDP);
        RemoteIPLabel->setObjectName("RemoteIPLabel");
        RemoteIPLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(RemoteIPLabel, 1, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        btnConnectUDP = new QPushButton(groupUDP);
        btnConnectUDP->setObjectName("btnConnectUDP");

        horizontalLayout_7->addWidget(btnConnectUDP);

        btnDisconnectUDP = new QPushButton(groupUDP);
        btnDisconnectUDP->setObjectName("btnDisconnectUDP");

        horizontalLayout_7->addWidget(btnDisconnectUDP);


        verticalLayout_5->addLayout(horizontalLayout_7);


        verticalLayout_3->addWidget(groupUDP);

        labelCommStatus = new QLabel(groupConnection);
        labelCommStatus->setObjectName("labelCommStatus");
        QFont font4;
        font4.setPointSize(10);
        labelCommStatus->setFont(font4);
        labelCommStatus->setStyleSheet(QString::fromUtf8("color: red;"));
        labelCommStatus->setAlignment(Qt::AlignCenter);
        labelCommStatus->setMargin(10);

        verticalLayout_3->addWidget(labelCommStatus);


        verticalLayout_2->addWidget(groupConnection);

        groupCMDSend = new QGroupBox(page);
        groupCMDSend->setObjectName("groupCMDSend");
        groupCMDSend->setFont(font);
        verticalLayout_6 = new QVBoxLayout(groupCMDSend);
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        CMDTitleLabel = new QLabel(groupCMDSend);
        CMDTitleLabel->setObjectName("CMDTitleLabel");

        horizontalLayout_6->addWidget(CMDTitleLabel);

        CMDComboBox = new QComboBox(groupCMDSend);
        CMDComboBox->setObjectName("CMDComboBox");
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CMDComboBox->sizePolicy().hasHeightForWidth());
        CMDComboBox->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(CMDComboBox);


        verticalLayout_6->addLayout(horizontalLayout_6);

        btnSendCMD = new QPushButton(groupCMDSend);
        btnSendCMD->setObjectName("btnSendCMD");

        verticalLayout_6->addWidget(btnSendCMD);


        verticalLayout_2->addWidget(groupCMDSend);

        commsLog = new QPlainTextEdit(page);
        commsLog->setObjectName("commsLog");
        commsLog->setReadOnly(true);

        verticalLayout_2->addWidget(commsLog);

        stackedScreens->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedScreens->addWidget(page_2);

        horizontalLayout->addWidget(stackedScreens);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedScreens->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logoLabel->setText(QCoreApplication::translate("MainWindow", "Micromouse", nullptr));
        btnHome->setText(QCoreApplication::translate("MainWindow", "Inicio", nullptr));
        btnSensors->setText(QCoreApplication::translate("MainWindow", "Sensores", nullptr));
        btnConfig->setText(QCoreApplication::translate("MainWindow", "Configuraci\303\263n", nullptr));
        titleHome->setText(QCoreApplication::translate("MainWindow", "Inicio", nullptr));
        groupConnection->setTitle(QCoreApplication::translate("MainWindow", "Conexi\303\263n", nullptr));
        groupSerie->setTitle(QCoreApplication::translate("MainWindow", "Serie", nullptr));
        portLabel->setText(QCoreApplication::translate("MainWindow", "Puerto:", nullptr));
        btnRefreshPorts->setText(QCoreApplication::translate("MainWindow", "Actualizar", nullptr));
        btnConnectSerie->setText(QCoreApplication::translate("MainWindow", "Conectar", nullptr));
        btnDisconnectSerie->setText(QCoreApplication::translate("MainWindow", "Desconectar", nullptr));
        groupUDP->setTitle(QCoreApplication::translate("MainWindow", "UDP", nullptr));
        localPortLabel->setText(QCoreApplication::translate("MainWindow", "Puerto local:", nullptr));
        RemoteIPLabel->setText(QCoreApplication::translate("MainWindow", "IP remota:", nullptr));
        btnConnectUDP->setText(QCoreApplication::translate("MainWindow", "Conectar", nullptr));
        btnDisconnectUDP->setText(QCoreApplication::translate("MainWindow", "Desconectar", nullptr));
        labelCommStatus->setText(QCoreApplication::translate("MainWindow", "Estado Conexi\303\263n", nullptr));
        groupCMDSend->setTitle(QCoreApplication::translate("MainWindow", "Test envio de comandos", nullptr));
        CMDTitleLabel->setText(QCoreApplication::translate("MainWindow", "Comando:", nullptr));
        btnSendCMD->setText(QCoreApplication::translate("MainWindow", "Enviar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
