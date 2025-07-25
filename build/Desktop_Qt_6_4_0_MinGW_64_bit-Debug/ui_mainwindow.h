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
#include <QtWidgets/QCheckBox>
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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
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
    QPushButton *btnControl;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedScreens;
    QWidget *pageHome;
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
    QLabel *RemotePortLabel;
    QLineEdit *RemotePortLineEdit;
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
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_10;
    QPlainTextEdit *commsLog;
    QWidget *pageSensors;
    QVBoxLayout *verticalLayout_7;
    QLabel *titleSensors;
    QGroupBox *groupIRSensors;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelDistanceSensors;
    QFrame *line_2;
    QGridLayout *layoutDistanceSensors;
    QProgressBar *progBarIrRightSide;
    QLabel *labelIrRightSide;
    QProgressBar *progBarIrLeftSide;
    QLabel *labelIrLeftSide;
    QLabel *label_10;
    QFrame *line_6;
    QGridLayout *gridLayout_2;
    QLabel *labelIrFrontRight;
    QProgressBar *progBarIrFrontRight;
    QLabel *labelIrFrontLeft;
    QProgressBar *progBarIrFrontLeft;
    QLabel *label_11;
    QFrame *line_7;
    QGridLayout *gridLayout_3;
    QLabel *labelIrRightDiag;
    QProgressBar *progBarIrLeftDiag;
    QLabel *labelIrLeftDiag;
    QProgressBar *progBarIrRightDiag;
    QLabel *label_9;
    QFrame *line_3;
    QGridLayout *layoutGroundSensors;
    QLabel *labelIrGroundFront;
    QLabel *labelIrGroundRear;
    QProgressBar *progBarIrGroundFront;
    QProgressBar *progBarIrGroundRear;
    QGroupBox *groupMPU6050;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QLineEdit *accelXLineEdit;
    QLabel *label_2;
    QLineEdit *accelYLineEdit;
    QLabel *label_3;
    QLineEdit *accelZLineEdit;
    QLabel *label_8;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *gyroXLineEdit;
    QLabel *label_5;
    QLineEdit *gyroYLineEdit;
    QLabel *label_6;
    QLineEdit *gyroZLineEdit;
    QPushButton *btnCalibrateMPU;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *btnRefreshSensorsValues;
    QCheckBox *chkBoxAutoRefreshSensorsValues;
    QSpacerItem *horizontalSpacer_2;
    QWidget *pageConfig;
    QVBoxLayout *verticalLayout_11;
    QLabel *titleConfig;
    QWidget *pageControl;
    QVBoxLayout *verticalLayout_12;
    QLabel *titleHome_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_12;
    QFrame *line_8;
    QGridLayout *gridLayout_4;
    QLabel *label_15;
    QLabel *label_13;
    QSlider *hSliderRightMotorNeg;
    QSlider *hSliderRightMotorPos;
    QSpinBox *spinBoxRightMotorPos;
    QSpinBox *spinBoxRightMotorNeg;
    QLabel *label_17;
    QFrame *line_9;
    QGridLayout *gridLayout_5;
    QLabel *label_19;
    QSlider *hSliderLeftMotorPos;
    QSlider *hSliderLeftMotorNeg;
    QLabel *label_18;
    QSpinBox *spinBoxLeftMotorPos;
    QSpinBox *spinBoxLeftMotorNeg;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *btnApplyPWM;
    QPushButton *btnStopMotor;
    QPushButton *btnGetPWM;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_14;
    QLineEdit *lineEditPwmPeriod;
    QPushButton *btnConfigurePeriod;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *chkAutoGetPWM;
    QCheckBox *chkRealTimeSetPWM;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 819);
        QFont font;
        font.setPointSize(11);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        navigationFrame = new QFrame(centralwidget);
        navigationFrame->setObjectName("navigationFrame");
        QFont font1;
        font1.setPointSize(12);
        navigationFrame->setFont(font1);
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
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setItalic(false);
        logoLabel->setFont(font2);
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
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(true);
        btnHome->setFont(font3);
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
        btnSensors->setFont(font3);
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
        btnConfig->setFont(font3);
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

        btnControl = new QPushButton(navigationFrame);
        btnControl->setObjectName("btnControl");
        btnControl->setFont(font3);
        btnControl->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btnControl->setCheckable(true);

        verticalLayout->addWidget(btnControl);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(navigationFrame);

        stackedScreens = new QStackedWidget(centralwidget);
        stackedScreens->setObjectName("stackedScreens");
        pageHome = new QWidget();
        pageHome->setObjectName("pageHome");
        verticalLayout_2 = new QVBoxLayout(pageHome);
        verticalLayout_2->setObjectName("verticalLayout_2");
        titleHome = new QLabel(pageHome);
        titleHome->setObjectName("titleHome");
        QFont font4;
        font4.setPointSize(18);
        font4.setBold(true);
        titleHome->setFont(font4);
        titleHome->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(titleHome);

        groupConnection = new QGroupBox(pageHome);
        groupConnection->setObjectName("groupConnection");
        QFont font5;
        font5.setPointSize(14);
        groupConnection->setFont(font5);
        verticalLayout_3 = new QVBoxLayout(groupConnection);
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupSerie = new QGroupBox(groupConnection);
        groupSerie->setObjectName("groupSerie");
        QFont font6;
        font6.setPointSize(13);
        groupSerie->setFont(font6);
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
        portLabel->setFont(font);
        portLabel->setMargin(0);

        horizontalLayout_4->addWidget(portLabel);

        comboBoxPorts = new QComboBox(groupSerie);
        comboBoxPorts->setObjectName("comboBoxPorts");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxPorts->sizePolicy().hasHeightForWidth());
        comboBoxPorts->setSizePolicy(sizePolicy1);
        comboBoxPorts->setFont(font);

        horizontalLayout_4->addWidget(comboBoxPorts);

        btnRefreshPorts = new QPushButton(groupSerie);
        btnRefreshPorts->setObjectName("btnRefreshPorts");
        btnRefreshPorts->setFont(font);

        horizontalLayout_4->addWidget(btnRefreshPorts);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        btnConnectSerie = new QPushButton(groupSerie);
        btnConnectSerie->setObjectName("btnConnectSerie");
        btnConnectSerie->setFont(font);

        horizontalLayout_5->addWidget(btnConnectSerie);

        btnDisconnectSerie = new QPushButton(groupSerie);
        btnDisconnectSerie->setObjectName("btnDisconnectSerie");
        btnDisconnectSerie->setFont(font);

        horizontalLayout_5->addWidget(btnDisconnectSerie);


        verticalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout_3->addWidget(groupSerie);

        groupUDP = new QGroupBox(groupConnection);
        groupUDP->setObjectName("groupUDP");
        groupUDP->setFont(font6);
        verticalLayout_5 = new QVBoxLayout(groupUDP);
        verticalLayout_5->setObjectName("verticalLayout_5");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        localPortLabel = new QLabel(groupUDP);
        localPortLabel->setObjectName("localPortLabel");
        localPortLabel->setFont(font);
        localPortLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        localPortLabel->setMargin(0);

        gridLayout->addWidget(localPortLabel, 0, 0, 1, 1);

        localPortLineEdit = new QLineEdit(groupUDP);
        localPortLineEdit->setObjectName("localPortLineEdit");
        localPortLineEdit->setFont(font);

        gridLayout->addWidget(localPortLineEdit, 0, 1, 1, 1);

        RemoteIpLineEdit = new QLineEdit(groupUDP);
        RemoteIpLineEdit->setObjectName("RemoteIpLineEdit");
        RemoteIpLineEdit->setFont(font);
        RemoteIpLineEdit->setReadOnly(true);

        gridLayout->addWidget(RemoteIpLineEdit, 1, 1, 1, 1);

        RemoteIPLabel = new QLabel(groupUDP);
        RemoteIPLabel->setObjectName("RemoteIPLabel");
        RemoteIPLabel->setFont(font);
        RemoteIPLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(RemoteIPLabel, 1, 0, 1, 1);

        RemotePortLabel = new QLabel(groupUDP);
        RemotePortLabel->setObjectName("RemotePortLabel");
        RemotePortLabel->setFont(font);

        gridLayout->addWidget(RemotePortLabel, 2, 0, 1, 1);

        RemotePortLineEdit = new QLineEdit(groupUDP);
        RemotePortLineEdit->setObjectName("RemotePortLineEdit");
        RemotePortLineEdit->setFont(font);
        RemotePortLineEdit->setReadOnly(true);

        gridLayout->addWidget(RemotePortLineEdit, 2, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        btnConnectUDP = new QPushButton(groupUDP);
        btnConnectUDP->setObjectName("btnConnectUDP");
        btnConnectUDP->setFont(font);

        horizontalLayout_7->addWidget(btnConnectUDP);

        btnDisconnectUDP = new QPushButton(groupUDP);
        btnDisconnectUDP->setObjectName("btnDisconnectUDP");
        btnDisconnectUDP->setFont(font);

        horizontalLayout_7->addWidget(btnDisconnectUDP);


        verticalLayout_5->addLayout(horizontalLayout_7);


        verticalLayout_3->addWidget(groupUDP);

        labelCommStatus = new QLabel(groupConnection);
        labelCommStatus->setObjectName("labelCommStatus");
        labelCommStatus->setFont(font6);
        labelCommStatus->setStyleSheet(QString::fromUtf8("color: red;"));
        labelCommStatus->setAlignment(Qt::AlignCenter);
        labelCommStatus->setMargin(10);

        verticalLayout_3->addWidget(labelCommStatus);


        verticalLayout_2->addWidget(groupConnection);

        groupCMDSend = new QGroupBox(pageHome);
        groupCMDSend->setObjectName("groupCMDSend");
        groupCMDSend->setFont(font5);
        verticalLayout_6 = new QVBoxLayout(groupCMDSend);
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        CMDTitleLabel = new QLabel(groupCMDSend);
        CMDTitleLabel->setObjectName("CMDTitleLabel");
        CMDTitleLabel->setFont(font);

        horizontalLayout_6->addWidget(CMDTitleLabel);

        CMDComboBox = new QComboBox(groupCMDSend);
        CMDComboBox->setObjectName("CMDComboBox");
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(CMDComboBox->sizePolicy().hasHeightForWidth());
        CMDComboBox->setSizePolicy(sizePolicy2);
        CMDComboBox->setFont(font);

        horizontalLayout_6->addWidget(CMDComboBox);


        verticalLayout_6->addLayout(horizontalLayout_6);

        btnSendCMD = new QPushButton(groupCMDSend);
        btnSendCMD->setObjectName("btnSendCMD");
        btnSendCMD->setFont(font);

        verticalLayout_6->addWidget(btnSendCMD);


        verticalLayout_2->addWidget(groupCMDSend);

        groupBox = new QGroupBox(pageHome);
        groupBox->setObjectName("groupBox");
        groupBox->setFont(font5);
        verticalLayout_10 = new QVBoxLayout(groupBox);
        verticalLayout_10->setObjectName("verticalLayout_10");
        commsLog = new QPlainTextEdit(groupBox);
        commsLog->setObjectName("commsLog");
        commsLog->setFont(font);
        commsLog->setReadOnly(true);

        verticalLayout_10->addWidget(commsLog);


        verticalLayout_2->addWidget(groupBox);

        stackedScreens->addWidget(pageHome);
        pageSensors = new QWidget();
        pageSensors->setObjectName("pageSensors");
        verticalLayout_7 = new QVBoxLayout(pageSensors);
        verticalLayout_7->setObjectName("verticalLayout_7");
        titleSensors = new QLabel(pageSensors);
        titleSensors->setObjectName("titleSensors");
        titleSensors->setFont(font4);
        titleSensors->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(titleSensors);

        groupIRSensors = new QGroupBox(pageSensors);
        groupIRSensors->setObjectName("groupIRSensors");
        QFont font7;
        font7.setPointSize(15);
        groupIRSensors->setFont(font7);
        verticalLayout_8 = new QVBoxLayout(groupIRSensors);
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        labelDistanceSensors = new QLabel(groupIRSensors);
        labelDistanceSensors->setObjectName("labelDistanceSensors");
        labelDistanceSensors->setFont(font6);

        horizontalLayout_2->addWidget(labelDistanceSensors);


        verticalLayout_8->addLayout(horizontalLayout_2);

        line_2 = new QFrame(groupIRSensors);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_2);

        layoutDistanceSensors = new QGridLayout();
        layoutDistanceSensors->setObjectName("layoutDistanceSensors");
        progBarIrRightSide = new QProgressBar(groupIRSensors);
        progBarIrRightSide->setObjectName("progBarIrRightSide");
        progBarIrRightSide->setFont(font);
        progBarIrRightSide->setMaximum(4095);
        progBarIrRightSide->setValue(0);
        progBarIrRightSide->setAlignment(Qt::AlignCenter);
        progBarIrRightSide->setTextVisible(true);

        layoutDistanceSensors->addWidget(progBarIrRightSide, 0, 1, 1, 1);

        labelIrRightSide = new QLabel(groupIRSensors);
        labelIrRightSide->setObjectName("labelIrRightSide");
        labelIrRightSide->setFont(font);

        layoutDistanceSensors->addWidget(labelIrRightSide, 0, 0, 1, 1);

        progBarIrLeftSide = new QProgressBar(groupIRSensors);
        progBarIrLeftSide->setObjectName("progBarIrLeftSide");
        progBarIrLeftSide->setFont(font);
        progBarIrLeftSide->setMaximum(4095);
        progBarIrLeftSide->setValue(0);
        progBarIrLeftSide->setAlignment(Qt::AlignCenter);
        progBarIrLeftSide->setTextVisible(true);

        layoutDistanceSensors->addWidget(progBarIrLeftSide, 5, 1, 1, 1);

        labelIrLeftSide = new QLabel(groupIRSensors);
        labelIrLeftSide->setObjectName("labelIrLeftSide");
        labelIrLeftSide->setFont(font);

        layoutDistanceSensors->addWidget(labelIrLeftSide, 5, 0, 1, 1);


        verticalLayout_8->addLayout(layoutDistanceSensors);

        label_10 = new QLabel(groupIRSensors);
        label_10->setObjectName("label_10");
        label_10->setFont(font6);

        verticalLayout_8->addWidget(label_10);

        line_6 = new QFrame(groupIRSensors);
        line_6->setObjectName("line_6");
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_6);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        labelIrFrontRight = new QLabel(groupIRSensors);
        labelIrFrontRight->setObjectName("labelIrFrontRight");
        labelIrFrontRight->setFont(font);

        gridLayout_2->addWidget(labelIrFrontRight, 0, 0, 1, 1);

        progBarIrFrontRight = new QProgressBar(groupIRSensors);
        progBarIrFrontRight->setObjectName("progBarIrFrontRight");
        progBarIrFrontRight->setFont(font);
        progBarIrFrontRight->setMaximum(4095);
        progBarIrFrontRight->setValue(0);
        progBarIrFrontRight->setAlignment(Qt::AlignCenter);
        progBarIrFrontRight->setTextVisible(true);

        gridLayout_2->addWidget(progBarIrFrontRight, 0, 1, 1, 1);

        labelIrFrontLeft = new QLabel(groupIRSensors);
        labelIrFrontLeft->setObjectName("labelIrFrontLeft");
        labelIrFrontLeft->setFont(font);

        gridLayout_2->addWidget(labelIrFrontLeft, 1, 0, 1, 1);

        progBarIrFrontLeft = new QProgressBar(groupIRSensors);
        progBarIrFrontLeft->setObjectName("progBarIrFrontLeft");
        progBarIrFrontLeft->setFont(font);
        progBarIrFrontLeft->setMaximum(4095);
        progBarIrFrontLeft->setValue(0);
        progBarIrFrontLeft->setAlignment(Qt::AlignCenter);
        progBarIrFrontLeft->setTextVisible(true);

        gridLayout_2->addWidget(progBarIrFrontLeft, 1, 1, 1, 1);


        verticalLayout_8->addLayout(gridLayout_2);

        label_11 = new QLabel(groupIRSensors);
        label_11->setObjectName("label_11");
        label_11->setFont(font6);

        verticalLayout_8->addWidget(label_11);

        line_7 = new QFrame(groupIRSensors);
        line_7->setObjectName("line_7");
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_7);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        labelIrRightDiag = new QLabel(groupIRSensors);
        labelIrRightDiag->setObjectName("labelIrRightDiag");
        labelIrRightDiag->setFont(font);

        gridLayout_3->addWidget(labelIrRightDiag, 0, 0, 1, 1);

        progBarIrLeftDiag = new QProgressBar(groupIRSensors);
        progBarIrLeftDiag->setObjectName("progBarIrLeftDiag");
        progBarIrLeftDiag->setFont(font);
        progBarIrLeftDiag->setMaximum(4095);
        progBarIrLeftDiag->setValue(0);
        progBarIrLeftDiag->setAlignment(Qt::AlignCenter);
        progBarIrLeftDiag->setTextVisible(true);

        gridLayout_3->addWidget(progBarIrLeftDiag, 1, 1, 1, 1);

        labelIrLeftDiag = new QLabel(groupIRSensors);
        labelIrLeftDiag->setObjectName("labelIrLeftDiag");
        labelIrLeftDiag->setFont(font);

        gridLayout_3->addWidget(labelIrLeftDiag, 1, 0, 1, 1);

        progBarIrRightDiag = new QProgressBar(groupIRSensors);
        progBarIrRightDiag->setObjectName("progBarIrRightDiag");
        progBarIrRightDiag->setFont(font);
        progBarIrRightDiag->setMaximum(4095);
        progBarIrRightDiag->setValue(0);
        progBarIrRightDiag->setAlignment(Qt::AlignCenter);
        progBarIrRightDiag->setTextVisible(true);

        gridLayout_3->addWidget(progBarIrRightDiag, 0, 1, 1, 1);


        verticalLayout_8->addLayout(gridLayout_3);

        label_9 = new QLabel(groupIRSensors);
        label_9->setObjectName("label_9");
        label_9->setFont(font6);

        verticalLayout_8->addWidget(label_9);

        line_3 = new QFrame(groupIRSensors);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_3);

        layoutGroundSensors = new QGridLayout();
        layoutGroundSensors->setObjectName("layoutGroundSensors");
        labelIrGroundFront = new QLabel(groupIRSensors);
        labelIrGroundFront->setObjectName("labelIrGroundFront");
        labelIrGroundFront->setFont(font);
        labelIrGroundFront->setMargin(0);

        layoutGroundSensors->addWidget(labelIrGroundFront, 0, 0, 1, 1);

        labelIrGroundRear = new QLabel(groupIRSensors);
        labelIrGroundRear->setObjectName("labelIrGroundRear");
        labelIrGroundRear->setFont(font);
        labelIrGroundRear->setLineWidth(1);
        labelIrGroundRear->setMargin(0);
        labelIrGroundRear->setIndent(-1);

        layoutGroundSensors->addWidget(labelIrGroundRear, 3, 0, 1, 1);

        progBarIrGroundFront = new QProgressBar(groupIRSensors);
        progBarIrGroundFront->setObjectName("progBarIrGroundFront");
        progBarIrGroundFront->setFont(font);
        progBarIrGroundFront->setMaximum(4095);
        progBarIrGroundFront->setValue(0);
        progBarIrGroundFront->setAlignment(Qt::AlignCenter);

        layoutGroundSensors->addWidget(progBarIrGroundFront, 0, 1, 1, 1);

        progBarIrGroundRear = new QProgressBar(groupIRSensors);
        progBarIrGroundRear->setObjectName("progBarIrGroundRear");
        progBarIrGroundRear->setFont(font);
        progBarIrGroundRear->setMaximum(4095);
        progBarIrGroundRear->setValue(0);
        progBarIrGroundRear->setAlignment(Qt::AlignCenter);

        layoutGroundSensors->addWidget(progBarIrGroundRear, 3, 1, 1, 1);


        verticalLayout_8->addLayout(layoutGroundSensors);


        verticalLayout_7->addWidget(groupIRSensors);

        groupMPU6050 = new QGroupBox(pageSensors);
        groupMPU6050->setObjectName("groupMPU6050");
        groupMPU6050->setFont(font7);
        verticalLayout_9 = new QVBoxLayout(groupMPU6050);
        verticalLayout_9->setObjectName("verticalLayout_9");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_7 = new QLabel(groupMPU6050);
        label_7->setObjectName("label_7");
        label_7->setFont(font6);

        horizontalLayout_9->addWidget(label_7);


        verticalLayout_9->addLayout(horizontalLayout_9);

        line_4 = new QFrame(groupMPU6050);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label = new QLabel(groupMPU6050);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout_8->addWidget(label);

        accelXLineEdit = new QLineEdit(groupMPU6050);
        accelXLineEdit->setObjectName("accelXLineEdit");
        accelXLineEdit->setFont(font);
        accelXLineEdit->setReadOnly(true);

        horizontalLayout_8->addWidget(accelXLineEdit);

        label_2 = new QLabel(groupMPU6050);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_8->addWidget(label_2);

        accelYLineEdit = new QLineEdit(groupMPU6050);
        accelYLineEdit->setObjectName("accelYLineEdit");
        accelYLineEdit->setFont(font);
        accelYLineEdit->setReadOnly(true);

        horizontalLayout_8->addWidget(accelYLineEdit);

        label_3 = new QLabel(groupMPU6050);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_8->addWidget(label_3);

        accelZLineEdit = new QLineEdit(groupMPU6050);
        accelZLineEdit->setObjectName("accelZLineEdit");
        accelZLineEdit->setFont(font);
        accelZLineEdit->setReadOnly(true);

        horizontalLayout_8->addWidget(accelZLineEdit);


        verticalLayout_9->addLayout(horizontalLayout_8);

        label_8 = new QLabel(groupMPU6050);
        label_8->setObjectName("label_8");
        label_8->setFont(font6);

        verticalLayout_9->addWidget(label_8);

        line_5 = new QFrame(groupMPU6050);
        line_5->setObjectName("line_5");
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(groupMPU6050);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        gyroXLineEdit = new QLineEdit(groupMPU6050);
        gyroXLineEdit->setObjectName("gyroXLineEdit");
        gyroXLineEdit->setFont(font);
        gyroXLineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(gyroXLineEdit);

        label_5 = new QLabel(groupMPU6050);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        horizontalLayout_3->addWidget(label_5);

        gyroYLineEdit = new QLineEdit(groupMPU6050);
        gyroYLineEdit->setObjectName("gyroYLineEdit");
        gyroYLineEdit->setFont(font);
        gyroYLineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(gyroYLineEdit);

        label_6 = new QLabel(groupMPU6050);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        horizontalLayout_3->addWidget(label_6);

        gyroZLineEdit = new QLineEdit(groupMPU6050);
        gyroZLineEdit->setObjectName("gyroZLineEdit");
        gyroZLineEdit->setFont(font);
        gyroZLineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(gyroZLineEdit);


        verticalLayout_9->addLayout(horizontalLayout_3);

        btnCalibrateMPU = new QPushButton(groupMPU6050);
        btnCalibrateMPU->setObjectName("btnCalibrateMPU");

        verticalLayout_9->addWidget(btnCalibrateMPU);


        verticalLayout_7->addWidget(groupMPU6050);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        btnRefreshSensorsValues = new QPushButton(pageSensors);
        btnRefreshSensorsValues->setObjectName("btnRefreshSensorsValues");
        btnRefreshSensorsValues->setFont(font);

        horizontalLayout_10->addWidget(btnRefreshSensorsValues);

        chkBoxAutoRefreshSensorsValues = new QCheckBox(pageSensors);
        chkBoxAutoRefreshSensorsValues->setObjectName("chkBoxAutoRefreshSensorsValues");
        chkBoxAutoRefreshSensorsValues->setFont(font);

        horizontalLayout_10->addWidget(chkBoxAutoRefreshSensorsValues);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);


        verticalLayout_7->addLayout(horizontalLayout_10);

        stackedScreens->addWidget(pageSensors);
        pageConfig = new QWidget();
        pageConfig->setObjectName("pageConfig");
        verticalLayout_11 = new QVBoxLayout(pageConfig);
        verticalLayout_11->setObjectName("verticalLayout_11");
        titleConfig = new QLabel(pageConfig);
        titleConfig->setObjectName("titleConfig");
        titleConfig->setFont(font4);
        titleConfig->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(titleConfig);

        stackedScreens->addWidget(pageConfig);
        pageControl = new QWidget();
        pageControl->setObjectName("pageControl");
        verticalLayout_12 = new QVBoxLayout(pageControl);
        verticalLayout_12->setObjectName("verticalLayout_12");
        titleHome_2 = new QLabel(pageControl);
        titleHome_2->setObjectName("titleHome_2");
        titleHome_2->setFont(font4);
        titleHome_2->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(titleHome_2);

        groupBox_2 = new QGroupBox(pageControl);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setFont(font7);
        verticalLayout_13 = new QVBoxLayout(groupBox_2);
        verticalLayout_13->setObjectName("verticalLayout_13");
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName("label_12");
        label_12->setFont(font6);

        verticalLayout_13->addWidget(label_12);

        line_8 = new QFrame(groupBox_2);
        line_8->setObjectName("line_8");
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_13->addWidget(line_8);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName("label_15");
        label_15->setFont(font);

        gridLayout_4->addWidget(label_15, 1, 0, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");
        label_13->setFont(font);

        gridLayout_4->addWidget(label_13, 0, 0, 1, 1);

        hSliderRightMotorNeg = new QSlider(groupBox_2);
        hSliderRightMotorNeg->setObjectName("hSliderRightMotorNeg");
        hSliderRightMotorNeg->setMaximum(10000);
        hSliderRightMotorNeg->setSingleStep(1000);
        hSliderRightMotorNeg->setPageStep(1000);
        hSliderRightMotorNeg->setOrientation(Qt::Horizontal);
        hSliderRightMotorNeg->setTickInterval(100);

        gridLayout_4->addWidget(hSliderRightMotorNeg, 1, 1, 1, 1);

        hSliderRightMotorPos = new QSlider(groupBox_2);
        hSliderRightMotorPos->setObjectName("hSliderRightMotorPos");
        hSliderRightMotorPos->setFont(font6);
        hSliderRightMotorPos->setMaximum(10000);
        hSliderRightMotorPos->setSingleStep(1000);
        hSliderRightMotorPos->setPageStep(1000);
        hSliderRightMotorPos->setSliderPosition(0);
        hSliderRightMotorPos->setTracking(true);
        hSliderRightMotorPos->setOrientation(Qt::Horizontal);
        hSliderRightMotorPos->setInvertedAppearance(false);
        hSliderRightMotorPos->setInvertedControls(false);
        hSliderRightMotorPos->setTickPosition(QSlider::NoTicks);
        hSliderRightMotorPos->setTickInterval(100);

        gridLayout_4->addWidget(hSliderRightMotorPos, 0, 1, 1, 1);

        spinBoxRightMotorPos = new QSpinBox(groupBox_2);
        spinBoxRightMotorPos->setObjectName("spinBoxRightMotorPos");
        spinBoxRightMotorPos->setFont(font);
        spinBoxRightMotorPos->setMaximum(10000);
        spinBoxRightMotorPos->setSingleStep(100);

        gridLayout_4->addWidget(spinBoxRightMotorPos, 0, 2, 1, 1);

        spinBoxRightMotorNeg = new QSpinBox(groupBox_2);
        spinBoxRightMotorNeg->setObjectName("spinBoxRightMotorNeg");
        spinBoxRightMotorNeg->setFont(font);
        spinBoxRightMotorNeg->setMaximum(10000);
        spinBoxRightMotorNeg->setSingleStep(100);

        gridLayout_4->addWidget(spinBoxRightMotorNeg, 1, 2, 1, 1);


        verticalLayout_13->addLayout(gridLayout_4);

        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName("label_17");
        label_17->setFont(font6);

        verticalLayout_13->addWidget(label_17);

        line_9 = new QFrame(groupBox_2);
        line_9->setObjectName("line_9");
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout_13->addWidget(line_9);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName("label_19");
        label_19->setFont(font);

        gridLayout_5->addWidget(label_19, 1, 0, 1, 1);

        hSliderLeftMotorPos = new QSlider(groupBox_2);
        hSliderLeftMotorPos->setObjectName("hSliderLeftMotorPos");
        hSliderLeftMotorPos->setFont(font);
        hSliderLeftMotorPos->setMaximum(10000);
        hSliderLeftMotorPos->setSingleStep(1000);
        hSliderLeftMotorPos->setPageStep(1000);
        hSliderLeftMotorPos->setOrientation(Qt::Horizontal);
        hSliderLeftMotorPos->setTickInterval(100);

        gridLayout_5->addWidget(hSliderLeftMotorPos, 0, 1, 1, 1);

        hSliderLeftMotorNeg = new QSlider(groupBox_2);
        hSliderLeftMotorNeg->setObjectName("hSliderLeftMotorNeg");
        hSliderLeftMotorNeg->setFont(font);
        hSliderLeftMotorNeg->setMaximum(10000);
        hSliderLeftMotorNeg->setSingleStep(1000);
        hSliderLeftMotorNeg->setPageStep(1000);
        hSliderLeftMotorNeg->setValue(0);
        hSliderLeftMotorNeg->setTracking(true);
        hSliderLeftMotorNeg->setOrientation(Qt::Horizontal);
        hSliderLeftMotorNeg->setTickPosition(QSlider::NoTicks);
        hSliderLeftMotorNeg->setTickInterval(100);

        gridLayout_5->addWidget(hSliderLeftMotorNeg, 1, 1, 1, 1);

        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName("label_18");
        label_18->setFont(font);

        gridLayout_5->addWidget(label_18, 0, 0, 1, 1);

        spinBoxLeftMotorPos = new QSpinBox(groupBox_2);
        spinBoxLeftMotorPos->setObjectName("spinBoxLeftMotorPos");
        spinBoxLeftMotorPos->setFont(font);
        spinBoxLeftMotorPos->setMaximum(10000);
        spinBoxLeftMotorPos->setSingleStep(100);

        gridLayout_5->addWidget(spinBoxLeftMotorPos, 0, 2, 1, 1);

        spinBoxLeftMotorNeg = new QSpinBox(groupBox_2);
        spinBoxLeftMotorNeg->setObjectName("spinBoxLeftMotorNeg");
        spinBoxLeftMotorNeg->setFont(font);
        spinBoxLeftMotorNeg->setMaximum(10000);
        spinBoxLeftMotorNeg->setSingleStep(100);

        gridLayout_5->addWidget(spinBoxLeftMotorNeg, 1, 2, 1, 1);


        verticalLayout_13->addLayout(gridLayout_5);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        btnApplyPWM = new QPushButton(groupBox_2);
        btnApplyPWM->setObjectName("btnApplyPWM");

        horizontalLayout_11->addWidget(btnApplyPWM);

        btnStopMotor = new QPushButton(groupBox_2);
        btnStopMotor->setObjectName("btnStopMotor");

        horizontalLayout_11->addWidget(btnStopMotor);

        btnGetPWM = new QPushButton(groupBox_2);
        btnGetPWM->setObjectName("btnGetPWM");

        horizontalLayout_11->addWidget(btnGetPWM);


        verticalLayout_13->addLayout(horizontalLayout_11);


        verticalLayout_12->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(pageControl);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setFont(font7);
        verticalLayout_14 = new QVBoxLayout(groupBox_3);
        verticalLayout_14->setObjectName("verticalLayout_14");
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName("label_14");
        label_14->setFont(font);

        horizontalLayout_13->addWidget(label_14);

        lineEditPwmPeriod = new QLineEdit(groupBox_3);
        lineEditPwmPeriod->setObjectName("lineEditPwmPeriod");
        lineEditPwmPeriod->setFont(font);

        horizontalLayout_13->addWidget(lineEditPwmPeriod);

        btnConfigurePeriod = new QPushButton(groupBox_3);
        btnConfigurePeriod->setObjectName("btnConfigurePeriod");
        btnConfigurePeriod->setFont(font);

        horizontalLayout_13->addWidget(btnConfigurePeriod);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_3);


        verticalLayout_14->addLayout(horizontalLayout_13);


        verticalLayout_12->addWidget(groupBox_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_3);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        chkAutoGetPWM = new QCheckBox(pageControl);
        chkAutoGetPWM->setObjectName("chkAutoGetPWM");
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(chkAutoGetPWM->sizePolicy().hasHeightForWidth());
        chkAutoGetPWM->setSizePolicy(sizePolicy3);

        horizontalLayout_12->addWidget(chkAutoGetPWM);

        chkRealTimeSetPWM = new QCheckBox(pageControl);
        chkRealTimeSetPWM->setObjectName("chkRealTimeSetPWM");

        horizontalLayout_12->addWidget(chkRealTimeSetPWM);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);


        verticalLayout_12->addLayout(horizontalLayout_12);

        stackedScreens->addWidget(pageControl);

        horizontalLayout->addWidget(stackedScreens);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedScreens->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logoLabel->setText(QCoreApplication::translate("MainWindow", "MICRO", nullptr));
        btnHome->setText(QCoreApplication::translate("MainWindow", "Inicio", nullptr));
        btnSensors->setText(QCoreApplication::translate("MainWindow", "Sensores", nullptr));
        btnConfig->setText(QCoreApplication::translate("MainWindow", "Configuraci\303\263n", nullptr));
        btnControl->setText(QCoreApplication::translate("MainWindow", "Control", nullptr));
        titleHome->setText(QCoreApplication::translate("MainWindow", "Inicio", nullptr));
        groupConnection->setTitle(QCoreApplication::translate("MainWindow", "Conexi\303\263n", nullptr));
        groupSerie->setTitle(QCoreApplication::translate("MainWindow", "Serie", nullptr));
        portLabel->setText(QCoreApplication::translate("MainWindow", "Puerto:", nullptr));
        btnRefreshPorts->setText(QCoreApplication::translate("MainWindow", "Actualizar", nullptr));
        btnConnectSerie->setText(QCoreApplication::translate("MainWindow", "Conectar", nullptr));
        btnDisconnectSerie->setText(QCoreApplication::translate("MainWindow", "Desconectar", nullptr));
        groupUDP->setTitle(QCoreApplication::translate("MainWindow", "UDP", nullptr));
        localPortLabel->setText(QCoreApplication::translate("MainWindow", "Puerto local:", nullptr));
        localPortLineEdit->setText(QCoreApplication::translate("MainWindow", "30010", nullptr));
        RemoteIPLabel->setText(QCoreApplication::translate("MainWindow", "IP remota:", nullptr));
        RemotePortLabel->setText(QCoreApplication::translate("MainWindow", "Puerto remoto:", nullptr));
        btnConnectUDP->setText(QCoreApplication::translate("MainWindow", "Conectar", nullptr));
        btnDisconnectUDP->setText(QCoreApplication::translate("MainWindow", "Desconectar", nullptr));
        labelCommStatus->setText(QCoreApplication::translate("MainWindow", "Estado Conexi\303\263n", nullptr));
        groupCMDSend->setTitle(QCoreApplication::translate("MainWindow", "Envio de comandos", nullptr));
        CMDTitleLabel->setText(QCoreApplication::translate("MainWindow", "Comando:", nullptr));
        btnSendCMD->setText(QCoreApplication::translate("MainWindow", "Enviar", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Log de comunicaciones", nullptr));
        titleSensors->setText(QCoreApplication::translate("MainWindow", "Sensores", nullptr));
        groupIRSensors->setTitle(QCoreApplication::translate("MainWindow", "TCRT5000", nullptr));
        labelDistanceSensors->setText(QCoreApplication::translate("MainWindow", "Laterales", nullptr));
        progBarIrRightSide->setFormat(QCoreApplication::translate("MainWindow", "%v", nullptr));
        labelIrRightSide->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        progBarIrLeftSide->setFormat(QCoreApplication::translate("MainWindow", "%v", nullptr));
        labelIrLeftSide->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Frontales", nullptr));
        labelIrFrontRight->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        progBarIrFrontRight->setFormat(QCoreApplication::translate("MainWindow", "%v", nullptr));
        labelIrFrontLeft->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        progBarIrFrontLeft->setFormat(QCoreApplication::translate("MainWindow", "%v", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Diagonales", nullptr));
        labelIrRightDiag->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        progBarIrLeftDiag->setFormat(QCoreApplication::translate("MainWindow", "%v", nullptr));
        labelIrLeftDiag->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        progBarIrRightDiag->setFormat(QCoreApplication::translate("MainWindow", "%v", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Suelo", nullptr));
        labelIrGroundFront->setText(QCoreApplication::translate("MainWindow", "F", nullptr));
        labelIrGroundRear->setText(QCoreApplication::translate("MainWindow", "T", nullptr));
        progBarIrGroundFront->setFormat(QCoreApplication::translate("MainWindow", "%v", nullptr));
        progBarIrGroundRear->setFormat(QCoreApplication::translate("MainWindow", "%v", nullptr));
        groupMPU6050->setTitle(QCoreApplication::translate("MainWindow", "MPU6050", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Aceler\303\263metro", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Ax", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Ay", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Az", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Giroscopio", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Gx", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Gy", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Gz", nullptr));
        btnCalibrateMPU->setText(QCoreApplication::translate("MainWindow", "Calibrar MPU", nullptr));
        btnRefreshSensorsValues->setText(QCoreApplication::translate("MainWindow", "Actualizar", nullptr));
        chkBoxAutoRefreshSensorsValues->setText(QCoreApplication::translate("MainWindow", "Actualizaci\303\263n autom\303\241tica", nullptr));
        titleConfig->setText(QCoreApplication::translate("MainWindow", "Configuraci\303\263n", nullptr));
        titleHome_2->setText(QCoreApplication::translate("MainWindow", "Control", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "PWM", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Motor Derecho", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Motor Izquierdo", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btnApplyPWM->setText(QCoreApplication::translate("MainWindow", "Aplicar PWM", nullptr));
        btnStopMotor->setText(QCoreApplication::translate("MainWindow", "Detener motores", nullptr));
        btnGetPWM->setText(QCoreApplication::translate("MainWindow", "Obtener PWM", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Configuraci\303\263n PWM", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Periodo TIM4 (ARR):", nullptr));
        lineEditPwmPeriod->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        btnConfigurePeriod->setText(QCoreApplication::translate("MainWindow", "Configurar", nullptr));
        chkAutoGetPWM->setText(QCoreApplication::translate("MainWindow", "Obtenci\303\263n autom\303\241tica", nullptr));
        chkRealTimeSetPWM->setText(QCoreApplication::translate("MainWindow", "Configuraci\303\263n en tiempo real", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
