/********************************************************************************
** Form generated from reading ui file 'dashboard.ui'
**
** Created: Sat Dec 12 15:37:54 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDial>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DashboardWindow
{
public:
    QAction *actionQuit;
    QAction *actionOpen_AUVScript;
    QAction *actionSet_Logfile_Directory;
    QAction *actionGo;
    QAction *actionStop;
    QAction *actionKill;
    QAction *actionStart_Logging;
    QAction *actionStop_Logging;
    QAction *actionReset;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *statusGroupBox;
    QVBoxLayout *verticalLayout_6;
    QFormLayout *statusFormLayout;
    QLabel *label_4;
    QProgressBar *missionProgressBar;
    QLabel *depthLabel;
    QLabel *headingLabel;
    QLabel *stateLabelLabel;
    QLCDNumber *depthLcdNumber;
    QLCDNumber *headingLcdNumber;
    QLabel *stateLabel;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *controlStateLabel;
    QLabel *label_9;
    QFrame *line;
    QFormLayout *thrusterStatusFormLayout;
    QLabel *label_12;
    QProgressBar *leftThrusterProgressBar;
    QLabel *label_13;
    QProgressBar *rightThrusterProgressBar;
    QLabel *label_14;
    QProgressBar *vertThrusterProgressBar;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QDoubleSpinBox *thrustScaleSpinBox;
    QLabel *label_24;
    QGroupBox *controlGroupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *desiredDepthVerticalLayout;
    QLabel *desiredDepthLabel;
    QSpinBox *desiredDepthSpinBox;
    QHBoxLayout *depthSliderHorizontalLayout;
    QSlider *desiredDepthSlider;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QLabel *label_11;
    QVBoxLayout *desiredHeadingSpeedVerticalLayout;
    QLabel *desiredHeadingLabel;
    QDial *desiredHeadingDial;
    QSpinBox *desiredHeadingSpinBox;
    QLabel *desiredSpeedLabel;
    QSlider *desiredSpeedSlider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *minSpeedLabel;
    QSpinBox *desiredSpeedSpinBox;
    QLabel *maxSpeedLabel;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_19;
    QComboBox *cameraPosComboBox;
    QTabWidget *pathSaturationSpinBox;
    QWidget *controllersTab;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_7;
    QLabel *label_21;
    QDoubleSpinBox *fwdVelocitySpinBox;
    QLabel *label_22;
    QDoubleSpinBox *approachVelocitySpinBox;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *headingPGainLabel;
    QDoubleSpinBox *headingPGainSpinBox;
    QLabel *headingIGainLabel;
    QDoubleSpinBox *headingIGainSpinBox;
    QLabel *headingDGainLabel;
    QDoubleSpinBox *headingDGainSpinBox;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QLabel *depthPGainLabel;
    QLabel *depthIGainLabel;
    QLabel *depthDGainLabel;
    QDoubleSpinBox *depthPGainSpinBox;
    QDoubleSpinBox *depthIGainSpinBox;
    QDoubleSpinBox *depthDGainSpinBox;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_11;
    QFormLayout *formLayout_9;
    QLabel *headingPGainLabel_3;
    QDoubleSpinBox *pathHeadingPGainSpinBox;
    QLabel *headingIGainLabel_3;
    QDoubleSpinBox *pathHeadingIGainSpinBox;
    QLabel *headingDGainLabel_3;
    QDoubleSpinBox *pathHeadingDGainSpinBox;
    QGroupBox *groupBox_10;
    QFormLayout *formLayout_8;
    QLabel *depthPGainLabel_3;
    QLabel *depthIGainLabel_3;
    QLabel *depthDGainLabel_3;
    QDoubleSpinBox *pathYPGainSpinBox;
    QDoubleSpinBox *pathYIGainSpinBox;
    QDoubleSpinBox *pathYDGainSpinBox;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_6;
    QFormLayout *formLayout_3;
    QLabel *headingPGainLabel_2;
    QDoubleSpinBox *buoyHeadingPGainSpinBox;
    QLabel *headingIGainLabel_2;
    QDoubleSpinBox *buoyHeadingIGainSpinBox;
    QLabel *headingDGainLabel_2;
    QDoubleSpinBox *buoyHeadingDGainSpinBox;
    QGroupBox *groupBox_4;
    QFormLayout *formLayout_4;
    QLabel *depthPGainLabel_2;
    QLabel *depthIGainLabel_2;
    QLabel *depthDGainLabel_2;
    QDoubleSpinBox *buoyDepthPGainSpinBox;
    QDoubleSpinBox *buoyDepthIGainSpinBox;
    QDoubleSpinBox *buoyDepthDGainSpinBox;
    QWidget *visionTab;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_20;
    QDoubleSpinBox *doubleSpinBox_6;
    QPushButton *pushButton;
    QGroupBox *groupBox_5;
    QFormLayout *formLayout_6;
    QLabel *label_10;
    QDoubleSpinBox *pathHueHighSpinBox;
    QLabel *label_15;
    QDoubleSpinBox *pathHueLowSpinBox;
    QLabel *label_23;
    QDoubleSpinBox *pathSaturationSpinBox_2;
    QGroupBox *groupBox_7;
    QFormLayout *formLayout_5;
    QLabel *label_7;
    QLabel *label_8;
    QDoubleSpinBox *buoyHueHighSpinBox;
    QDoubleSpinBox *buoyHueLowSpinBox;
    QLabel *label_5;
    QDoubleSpinBox *buoySaturationSpinBox;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuLogging;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *DashboardWindow)
    {
    if (DashboardWindow->objectName().isEmpty())
        DashboardWindow->setObjectName(QString::fromUtf8("DashboardWindow"));
    DashboardWindow->resize(940, 821);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(DashboardWindow->sizePolicy().hasHeightForWidth());
    DashboardWindow->setSizePolicy(sizePolicy);
    DashboardWindow->setMinimumSize(QSize(200, 817));
    actionQuit = new QAction(DashboardWindow);
    actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
    actionOpen_AUVScript = new QAction(DashboardWindow);
    actionOpen_AUVScript->setObjectName(QString::fromUtf8("actionOpen_AUVScript"));
    actionSet_Logfile_Directory = new QAction(DashboardWindow);
    actionSet_Logfile_Directory->setObjectName(QString::fromUtf8("actionSet_Logfile_Directory"));
    actionGo = new QAction(DashboardWindow);
    actionGo->setObjectName(QString::fromUtf8("actionGo"));
    actionStop = new QAction(DashboardWindow);
    actionStop->setObjectName(QString::fromUtf8("actionStop"));
    actionKill = new QAction(DashboardWindow);
    actionKill->setObjectName(QString::fromUtf8("actionKill"));
    actionStart_Logging = new QAction(DashboardWindow);
    actionStart_Logging->setObjectName(QString::fromUtf8("actionStart_Logging"));
    actionStop_Logging = new QAction(DashboardWindow);
    actionStop_Logging->setObjectName(QString::fromUtf8("actionStop_Logging"));
    actionReset = new QAction(DashboardWindow);
    actionReset->setObjectName(QString::fromUtf8("actionReset"));
    centralwidget = new QWidget(DashboardWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setGeometry(QRect(0, 51, 940, 746));
    sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
    centralwidget->setSizePolicy(sizePolicy);
    verticalLayout = new QVBoxLayout(centralwidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    statusGroupBox = new QGroupBox(centralwidget);
    statusGroupBox->setObjectName(QString::fromUtf8("statusGroupBox"));
    statusGroupBox->setWindowModality(Qt::NonModal);
    sizePolicy.setHeightForWidth(statusGroupBox->sizePolicy().hasHeightForWidth());
    statusGroupBox->setSizePolicy(sizePolicy);
    statusGroupBox->setAcceptDrops(true);
    statusGroupBox->setFlat(false);
    statusGroupBox->setCheckable(false);
    verticalLayout_6 = new QVBoxLayout(statusGroupBox);
    verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
    statusFormLayout = new QFormLayout();
    statusFormLayout->setObjectName(QString::fromUtf8("statusFormLayout"));
    label_4 = new QLabel(statusGroupBox);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    statusFormLayout->setWidget(2, QFormLayout::LabelRole, label_4);

    missionProgressBar = new QProgressBar(statusGroupBox);
    missionProgressBar->setObjectName(QString::fromUtf8("missionProgressBar"));
    missionProgressBar->setValue(0);

    statusFormLayout->setWidget(2, QFormLayout::FieldRole, missionProgressBar);

    depthLabel = new QLabel(statusGroupBox);
    depthLabel->setObjectName(QString::fromUtf8("depthLabel"));

    statusFormLayout->setWidget(4, QFormLayout::LabelRole, depthLabel);

    headingLabel = new QLabel(statusGroupBox);
    headingLabel->setObjectName(QString::fromUtf8("headingLabel"));

    statusFormLayout->setWidget(5, QFormLayout::LabelRole, headingLabel);

    stateLabelLabel = new QLabel(statusGroupBox);
    stateLabelLabel->setObjectName(QString::fromUtf8("stateLabelLabel"));

    statusFormLayout->setWidget(3, QFormLayout::LabelRole, stateLabelLabel);

    depthLcdNumber = new QLCDNumber(statusGroupBox);
    depthLcdNumber->setObjectName(QString::fromUtf8("depthLcdNumber"));
    depthLcdNumber->setFrameShape(QFrame::NoFrame);
    depthLcdNumber->setSmallDecimalPoint(false);
    depthLcdNumber->setSegmentStyle(QLCDNumber::Flat);
    depthLcdNumber->setProperty("value", QVariant(0));

    statusFormLayout->setWidget(4, QFormLayout::FieldRole, depthLcdNumber);

    headingLcdNumber = new QLCDNumber(statusGroupBox);
    headingLcdNumber->setObjectName(QString::fromUtf8("headingLcdNumber"));
    headingLcdNumber->setFrameShape(QFrame::NoFrame);
    headingLcdNumber->setSegmentStyle(QLCDNumber::Flat);

    statusFormLayout->setWidget(5, QFormLayout::FieldRole, headingLcdNumber);

    stateLabel = new QLabel(statusGroupBox);
    stateLabel->setObjectName(QString::fromUtf8("stateLabel"));

    statusFormLayout->setWidget(3, QFormLayout::FieldRole, stateLabel);

    label_16 = new QLabel(statusGroupBox);
    label_16->setObjectName(QString::fromUtf8("label_16"));

    statusFormLayout->setWidget(6, QFormLayout::LabelRole, label_16);

    label_17 = new QLabel(statusGroupBox);
    label_17->setObjectName(QString::fromUtf8("label_17"));

    statusFormLayout->setWidget(1, QFormLayout::LabelRole, label_17);

    controlStateLabel = new QLabel(statusGroupBox);
    controlStateLabel->setObjectName(QString::fromUtf8("controlStateLabel"));

    statusFormLayout->setWidget(1, QFormLayout::FieldRole, controlStateLabel);

    label_9 = new QLabel(statusGroupBox);
    label_9->setObjectName(QString::fromUtf8("label_9"));

    statusFormLayout->setWidget(6, QFormLayout::FieldRole, label_9);


    verticalLayout_6->addLayout(statusFormLayout);

    line = new QFrame(statusGroupBox);
    line->setObjectName(QString::fromUtf8("line"));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    verticalLayout_6->addWidget(line);

    thrusterStatusFormLayout = new QFormLayout();
    thrusterStatusFormLayout->setObjectName(QString::fromUtf8("thrusterStatusFormLayout"));
    thrusterStatusFormLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    label_12 = new QLabel(statusGroupBox);
    label_12->setObjectName(QString::fromUtf8("label_12"));

    thrusterStatusFormLayout->setWidget(1, QFormLayout::LabelRole, label_12);

    leftThrusterProgressBar = new QProgressBar(statusGroupBox);
    leftThrusterProgressBar->setObjectName(QString::fromUtf8("leftThrusterProgressBar"));
    leftThrusterProgressBar->setMinimum(-127);
    leftThrusterProgressBar->setMaximum(127);
    leftThrusterProgressBar->setValue(0);
    leftThrusterProgressBar->setInvertedAppearance(false);

    thrusterStatusFormLayout->setWidget(1, QFormLayout::FieldRole, leftThrusterProgressBar);

    label_13 = new QLabel(statusGroupBox);
    label_13->setObjectName(QString::fromUtf8("label_13"));

    thrusterStatusFormLayout->setWidget(2, QFormLayout::LabelRole, label_13);

    rightThrusterProgressBar = new QProgressBar(statusGroupBox);
    rightThrusterProgressBar->setObjectName(QString::fromUtf8("rightThrusterProgressBar"));
    rightThrusterProgressBar->setMinimum(-127);
    rightThrusterProgressBar->setMaximum(127);
    rightThrusterProgressBar->setValue(0);

    thrusterStatusFormLayout->setWidget(2, QFormLayout::FieldRole, rightThrusterProgressBar);

    label_14 = new QLabel(statusGroupBox);
    label_14->setObjectName(QString::fromUtf8("label_14"));

    thrusterStatusFormLayout->setWidget(3, QFormLayout::LabelRole, label_14);

    vertThrusterProgressBar = new QProgressBar(statusGroupBox);
    vertThrusterProgressBar->setObjectName(QString::fromUtf8("vertThrusterProgressBar"));
    vertThrusterProgressBar->setMinimum(-127);
    vertThrusterProgressBar->setMaximum(127);
    vertThrusterProgressBar->setValue(0);

    thrusterStatusFormLayout->setWidget(3, QFormLayout::FieldRole, vertThrusterProgressBar);

    horizontalLayout_4 = new QHBoxLayout();
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    label_3 = new QLabel(statusGroupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    horizontalLayout_4->addWidget(label_3);

    label_2 = new QLabel(statusGroupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setAlignment(Qt::AlignCenter);

    horizontalLayout_4->addWidget(label_2);

    label = new QLabel(statusGroupBox);
    label->setObjectName(QString::fromUtf8("label"));
    label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    horizontalLayout_4->addWidget(label);

    horizontalSpacer = new QSpacerItem(37, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    horizontalLayout_4->addItem(horizontalSpacer);


    thrusterStatusFormLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_4);

    thrustScaleSpinBox = new QDoubleSpinBox(statusGroupBox);
    thrustScaleSpinBox->setObjectName(QString::fromUtf8("thrustScaleSpinBox"));

    thrusterStatusFormLayout->setWidget(5, QFormLayout::FieldRole, thrustScaleSpinBox);

    label_24 = new QLabel(statusGroupBox);
    label_24->setObjectName(QString::fromUtf8("label_24"));

    thrusterStatusFormLayout->setWidget(5, QFormLayout::LabelRole, label_24);


    verticalLayout_6->addLayout(thrusterStatusFormLayout);


    horizontalLayout->addWidget(statusGroupBox);

    controlGroupBox = new QGroupBox(centralwidget);
    controlGroupBox->setObjectName(QString::fromUtf8("controlGroupBox"));
    controlGroupBox->setEnabled(true);
    sizePolicy.setHeightForWidth(controlGroupBox->sizePolicy().hasHeightForWidth());
    controlGroupBox->setSizePolicy(sizePolicy);
    controlGroupBox->setCheckable(true);
    controlGroupBox->setChecked(false);
    gridLayout = new QGridLayout(controlGroupBox);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    desiredDepthVerticalLayout = new QVBoxLayout();
    desiredDepthVerticalLayout->setObjectName(QString::fromUtf8("desiredDepthVerticalLayout"));
    desiredDepthLabel = new QLabel(controlGroupBox);
    desiredDepthLabel->setObjectName(QString::fromUtf8("desiredDepthLabel"));

    desiredDepthVerticalLayout->addWidget(desiredDepthLabel);

    desiredDepthSpinBox = new QSpinBox(controlGroupBox);
    desiredDepthSpinBox->setObjectName(QString::fromUtf8("desiredDepthSpinBox"));
    desiredDepthSpinBox->setMaximum(18);

    desiredDepthVerticalLayout->addWidget(desiredDepthSpinBox);

    depthSliderHorizontalLayout = new QHBoxLayout();
    depthSliderHorizontalLayout->setObjectName(QString::fromUtf8("depthSliderHorizontalLayout"));
    desiredDepthSlider = new QSlider(controlGroupBox);
    desiredDepthSlider->setObjectName(QString::fromUtf8("desiredDepthSlider"));
    desiredDepthSlider->setCursor(QCursor(Qt::SizeVerCursor));
    desiredDepthSlider->setMaximum(18);
    desiredDepthSlider->setOrientation(Qt::Vertical);
    desiredDepthSlider->setInvertedAppearance(true);
    desiredDepthSlider->setTickPosition(QSlider::TicksBothSides);
    desiredDepthSlider->setTickInterval(1);

    depthSliderHorizontalLayout->addWidget(desiredDepthSlider);

    verticalLayout_5 = new QVBoxLayout();
    verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
    label_6 = new QLabel(controlGroupBox);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

    verticalLayout_5->addWidget(label_6);

    label_11 = new QLabel(controlGroupBox);
    label_11->setObjectName(QString::fromUtf8("label_11"));
    label_11->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

    verticalLayout_5->addWidget(label_11);


    depthSliderHorizontalLayout->addLayout(verticalLayout_5);


    desiredDepthVerticalLayout->addLayout(depthSliderHorizontalLayout);


    gridLayout->addLayout(desiredDepthVerticalLayout, 0, 1, 1, 1);

    desiredHeadingSpeedVerticalLayout = new QVBoxLayout();
    desiredHeadingSpeedVerticalLayout->setObjectName(QString::fromUtf8("desiredHeadingSpeedVerticalLayout"));
    desiredHeadingLabel = new QLabel(controlGroupBox);
    desiredHeadingLabel->setObjectName(QString::fromUtf8("desiredHeadingLabel"));

    desiredHeadingSpeedVerticalLayout->addWidget(desiredHeadingLabel);

    desiredHeadingDial = new QDial(controlGroupBox);
    desiredHeadingDial->setObjectName(QString::fromUtf8("desiredHeadingDial"));
    desiredHeadingDial->setEnabled(false);
    sizePolicy.setHeightForWidth(desiredHeadingDial->sizePolicy().hasHeightForWidth());
    desiredHeadingDial->setSizePolicy(sizePolicy);
    desiredHeadingDial->setMaximum(359);
    desiredHeadingDial->setValue(0);
    desiredHeadingDial->setSliderPosition(0);
    desiredHeadingDial->setTracking(false);
    desiredHeadingDial->setOrientation(Qt::Vertical);
    desiredHeadingDial->setInvertedAppearance(false);
    desiredHeadingDial->setInvertedControls(false);
    desiredHeadingDial->setWrapping(true);
    desiredHeadingDial->setNotchTarget(45);
    desiredHeadingDial->setNotchesVisible(true);

    desiredHeadingSpeedVerticalLayout->addWidget(desiredHeadingDial);

    desiredHeadingSpinBox = new QSpinBox(controlGroupBox);
    desiredHeadingSpinBox->setObjectName(QString::fromUtf8("desiredHeadingSpinBox"));
    desiredHeadingSpinBox->setWrapping(true);
    desiredHeadingSpinBox->setFrame(true);
    desiredHeadingSpinBox->setAlignment(Qt::AlignCenter);
    desiredHeadingSpinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
    desiredHeadingSpinBox->setMaximum(359);

    desiredHeadingSpeedVerticalLayout->addWidget(desiredHeadingSpinBox);

    desiredSpeedLabel = new QLabel(controlGroupBox);
    desiredSpeedLabel->setObjectName(QString::fromUtf8("desiredSpeedLabel"));
    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(desiredSpeedLabel->sizePolicy().hasHeightForWidth());
    desiredSpeedLabel->setSizePolicy(sizePolicy1);

    desiredHeadingSpeedVerticalLayout->addWidget(desiredSpeedLabel);

    desiredSpeedSlider = new QSlider(controlGroupBox);
    desiredSpeedSlider->setObjectName(QString::fromUtf8("desiredSpeedSlider"));
    desiredSpeedSlider->setCursor(QCursor(Qt::SizeHorCursor));
    desiredSpeedSlider->setMaximum(127);
    desiredSpeedSlider->setOrientation(Qt::Horizontal);
    desiredSpeedSlider->setInvertedAppearance(false);
    desiredSpeedSlider->setTickPosition(QSlider::TicksBothSides);
    desiredSpeedSlider->setTickInterval(13);

    desiredHeadingSpeedVerticalLayout->addWidget(desiredSpeedSlider);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    horizontalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
    minSpeedLabel = new QLabel(controlGroupBox);
    minSpeedLabel->setObjectName(QString::fromUtf8("minSpeedLabel"));
    sizePolicy1.setHeightForWidth(minSpeedLabel->sizePolicy().hasHeightForWidth());
    minSpeedLabel->setSizePolicy(sizePolicy1);

    horizontalLayout_2->addWidget(minSpeedLabel);

    desiredSpeedSpinBox = new QSpinBox(controlGroupBox);
    desiredSpeedSpinBox->setObjectName(QString::fromUtf8("desiredSpeedSpinBox"));

    horizontalLayout_2->addWidget(desiredSpeedSpinBox);

    maxSpeedLabel = new QLabel(controlGroupBox);
    maxSpeedLabel->setObjectName(QString::fromUtf8("maxSpeedLabel"));
    sizePolicy1.setHeightForWidth(maxSpeedLabel->sizePolicy().hasHeightForWidth());
    maxSpeedLabel->setSizePolicy(sizePolicy1);
    maxSpeedLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    horizontalLayout_2->addWidget(maxSpeedLabel);


    desiredHeadingSpeedVerticalLayout->addLayout(horizontalLayout_2);

    horizontalLayout_7 = new QHBoxLayout();
    horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
    label_19 = new QLabel(controlGroupBox);
    label_19->setObjectName(QString::fromUtf8("label_19"));

    horizontalLayout_7->addWidget(label_19);

    cameraPosComboBox = new QComboBox(controlGroupBox);
    cameraPosComboBox->setObjectName(QString::fromUtf8("cameraPosComboBox"));
    cameraPosComboBox->setEnabled(false);

    horizontalLayout_7->addWidget(cameraPosComboBox);


    desiredHeadingSpeedVerticalLayout->addLayout(horizontalLayout_7);


    gridLayout->addLayout(desiredHeadingSpeedVerticalLayout, 0, 0, 1, 1);


    horizontalLayout->addWidget(controlGroupBox);


    verticalLayout->addLayout(horizontalLayout);

    pathSaturationSpinBox = new QTabWidget(centralwidget);
    pathSaturationSpinBox->setObjectName(QString::fromUtf8("pathSaturationSpinBox"));
    pathSaturationSpinBox->setTabPosition(QTabWidget::North);
    controllersTab = new QWidget();
    controllersTab->setObjectName(QString::fromUtf8("controllersTab"));
    controllersTab->setGeometry(QRect(0, 0, 918, 332));
    horizontalLayout_6 = new QHBoxLayout(controllersTab);
    horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    formLayout_7 = new QFormLayout();
    formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
    formLayout_7->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    label_21 = new QLabel(controllersTab);
    label_21->setObjectName(QString::fromUtf8("label_21"));

    formLayout_7->setWidget(1, QFormLayout::LabelRole, label_21);

    fwdVelocitySpinBox = new QDoubleSpinBox(controllersTab);
    fwdVelocitySpinBox->setObjectName(QString::fromUtf8("fwdVelocitySpinBox"));

    formLayout_7->setWidget(1, QFormLayout::FieldRole, fwdVelocitySpinBox);

    label_22 = new QLabel(controllersTab);
    label_22->setObjectName(QString::fromUtf8("label_22"));

    formLayout_7->setWidget(2, QFormLayout::LabelRole, label_22);

    approachVelocitySpinBox = new QDoubleSpinBox(controllersTab);
    approachVelocitySpinBox->setObjectName(QString::fromUtf8("approachVelocitySpinBox"));

    formLayout_7->setWidget(2, QFormLayout::FieldRole, approachVelocitySpinBox);


    verticalLayout_2->addLayout(formLayout_7);

    groupBox = new QGroupBox(controllersTab);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    formLayout = new QFormLayout(groupBox);
    formLayout->setObjectName(QString::fromUtf8("formLayout"));
    formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    headingPGainLabel = new QLabel(groupBox);
    headingPGainLabel->setObjectName(QString::fromUtf8("headingPGainLabel"));

    formLayout->setWidget(1, QFormLayout::LabelRole, headingPGainLabel);

    headingPGainSpinBox = new QDoubleSpinBox(groupBox);
    headingPGainSpinBox->setObjectName(QString::fromUtf8("headingPGainSpinBox"));
    headingPGainSpinBox->setSingleStep(0.01);

    formLayout->setWidget(1, QFormLayout::FieldRole, headingPGainSpinBox);

    headingIGainLabel = new QLabel(groupBox);
    headingIGainLabel->setObjectName(QString::fromUtf8("headingIGainLabel"));

    formLayout->setWidget(2, QFormLayout::LabelRole, headingIGainLabel);

    headingIGainSpinBox = new QDoubleSpinBox(groupBox);
    headingIGainSpinBox->setObjectName(QString::fromUtf8("headingIGainSpinBox"));
    headingIGainSpinBox->setSingleStep(0.01);

    formLayout->setWidget(2, QFormLayout::FieldRole, headingIGainSpinBox);

    headingDGainLabel = new QLabel(groupBox);
    headingDGainLabel->setObjectName(QString::fromUtf8("headingDGainLabel"));

    formLayout->setWidget(3, QFormLayout::LabelRole, headingDGainLabel);

    headingDGainSpinBox = new QDoubleSpinBox(groupBox);
    headingDGainSpinBox->setObjectName(QString::fromUtf8("headingDGainSpinBox"));
    headingDGainSpinBox->setSingleStep(0.01);

    formLayout->setWidget(3, QFormLayout::FieldRole, headingDGainSpinBox);


    verticalLayout_2->addWidget(groupBox);

    groupBox_2 = new QGroupBox(controllersTab);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    formLayout_2 = new QFormLayout(groupBox_2);
    formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
    depthPGainLabel = new QLabel(groupBox_2);
    depthPGainLabel->setObjectName(QString::fromUtf8("depthPGainLabel"));

    formLayout_2->setWidget(0, QFormLayout::LabelRole, depthPGainLabel);

    depthIGainLabel = new QLabel(groupBox_2);
    depthIGainLabel->setObjectName(QString::fromUtf8("depthIGainLabel"));

    formLayout_2->setWidget(1, QFormLayout::LabelRole, depthIGainLabel);

    depthDGainLabel = new QLabel(groupBox_2);
    depthDGainLabel->setObjectName(QString::fromUtf8("depthDGainLabel"));

    formLayout_2->setWidget(2, QFormLayout::LabelRole, depthDGainLabel);

    depthPGainSpinBox = new QDoubleSpinBox(groupBox_2);
    depthPGainSpinBox->setObjectName(QString::fromUtf8("depthPGainSpinBox"));
    depthPGainSpinBox->setSingleStep(0.01);
	depthPGainSpinBox->setMinimum(-100);
	depthPGainSpinBox->setMaximum(100);

    formLayout_2->setWidget(0, QFormLayout::FieldRole, depthPGainSpinBox);

    depthIGainSpinBox = new QDoubleSpinBox(groupBox_2);
    depthIGainSpinBox->setObjectName(QString::fromUtf8("depthIGainSpinBox"));
    depthIGainSpinBox->setSingleStep(0.01);
	depthIGainSpinBox->setMinimum(-100);
	depthIGainSpinBox->setMaximum(100);

    formLayout_2->setWidget(1, QFormLayout::FieldRole, depthIGainSpinBox);

    depthDGainSpinBox = new QDoubleSpinBox(groupBox_2);
    depthDGainSpinBox->setObjectName(QString::fromUtf8("depthDGainSpinBox"));
    depthDGainSpinBox->setSingleStep(0.01);
	depthDGainSpinBox->setMinimum(-100);
	depthDGainSpinBox->setMaximum(100);

    formLayout_2->setWidget(2, QFormLayout::FieldRole, depthDGainSpinBox);


    verticalLayout_2->addWidget(groupBox_2);


    horizontalLayout_6->addLayout(verticalLayout_2);

    groupBox_9 = new QGroupBox(controllersTab);
    groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
    verticalLayout_7 = new QVBoxLayout(groupBox_9);
    verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
    groupBox_11 = new QGroupBox(groupBox_9);
    groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
    formLayout_9 = new QFormLayout(groupBox_11);
    formLayout_9->setObjectName(QString::fromUtf8("formLayout_9"));
    formLayout_9->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    headingPGainLabel_3 = new QLabel(groupBox_11);
    headingPGainLabel_3->setObjectName(QString::fromUtf8("headingPGainLabel_3"));

    formLayout_9->setWidget(0, QFormLayout::LabelRole, headingPGainLabel_3);

    pathHeadingPGainSpinBox = new QDoubleSpinBox(groupBox_11);
    pathHeadingPGainSpinBox->setObjectName(QString::fromUtf8("pathHeadingPGainSpinBox"));
    pathHeadingPGainSpinBox->setSingleStep(0.01);

    formLayout_9->setWidget(0, QFormLayout::FieldRole, pathHeadingPGainSpinBox);

    headingIGainLabel_3 = new QLabel(groupBox_11);
    headingIGainLabel_3->setObjectName(QString::fromUtf8("headingIGainLabel_3"));

    formLayout_9->setWidget(1, QFormLayout::LabelRole, headingIGainLabel_3);

    pathHeadingIGainSpinBox = new QDoubleSpinBox(groupBox_11);
    pathHeadingIGainSpinBox->setObjectName(QString::fromUtf8("pathHeadingIGainSpinBox"));
    pathHeadingIGainSpinBox->setSingleStep(0.01);

    formLayout_9->setWidget(1, QFormLayout::FieldRole, pathHeadingIGainSpinBox);

    headingDGainLabel_3 = new QLabel(groupBox_11);
    headingDGainLabel_3->setObjectName(QString::fromUtf8("headingDGainLabel_3"));

    formLayout_9->setWidget(2, QFormLayout::LabelRole, headingDGainLabel_3);

    pathHeadingDGainSpinBox = new QDoubleSpinBox(groupBox_11);
    pathHeadingDGainSpinBox->setObjectName(QString::fromUtf8("pathHeadingDGainSpinBox"));
    pathHeadingDGainSpinBox->setSingleStep(0.01);

    formLayout_9->setWidget(2, QFormLayout::FieldRole, pathHeadingDGainSpinBox);


    verticalLayout_7->addWidget(groupBox_11);

    groupBox_10 = new QGroupBox(groupBox_9);
    groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
    formLayout_8 = new QFormLayout(groupBox_10);
    formLayout_8->setObjectName(QString::fromUtf8("formLayout_8"));
    depthPGainLabel_3 = new QLabel(groupBox_10);
    depthPGainLabel_3->setObjectName(QString::fromUtf8("depthPGainLabel_3"));

    formLayout_8->setWidget(0, QFormLayout::LabelRole, depthPGainLabel_3);

    depthIGainLabel_3 = new QLabel(groupBox_10);
    depthIGainLabel_3->setObjectName(QString::fromUtf8("depthIGainLabel_3"));

    formLayout_8->setWidget(1, QFormLayout::LabelRole, depthIGainLabel_3);

    depthDGainLabel_3 = new QLabel(groupBox_10);
    depthDGainLabel_3->setObjectName(QString::fromUtf8("depthDGainLabel_3"));

    formLayout_8->setWidget(2, QFormLayout::LabelRole, depthDGainLabel_3);

    pathYPGainSpinBox = new QDoubleSpinBox(groupBox_10);
    pathYPGainSpinBox->setObjectName(QString::fromUtf8("pathYPGainSpinBox"));
    pathYPGainSpinBox->setSingleStep(0.01);

    formLayout_8->setWidget(0, QFormLayout::FieldRole, pathYPGainSpinBox);

    pathYIGainSpinBox = new QDoubleSpinBox(groupBox_10);
    pathYIGainSpinBox->setObjectName(QString::fromUtf8("pathYIGainSpinBox"));
    pathYIGainSpinBox->setSingleStep(0.01);

    formLayout_8->setWidget(1, QFormLayout::FieldRole, pathYIGainSpinBox);

    pathYDGainSpinBox = new QDoubleSpinBox(groupBox_10);
    pathYDGainSpinBox->setObjectName(QString::fromUtf8("pathYDGainSpinBox"));
    pathYDGainSpinBox->setSingleStep(0.01);

    formLayout_8->setWidget(2, QFormLayout::FieldRole, pathYDGainSpinBox);


    verticalLayout_7->addWidget(groupBox_10);


    horizontalLayout_6->addWidget(groupBox_9);

    groupBox_3 = new QGroupBox(controllersTab);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    verticalLayout_3 = new QVBoxLayout(groupBox_3);
    verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
    groupBox_6 = new QGroupBox(groupBox_3);
    groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
    formLayout_3 = new QFormLayout(groupBox_6);
    formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
    formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    headingPGainLabel_2 = new QLabel(groupBox_6);
    headingPGainLabel_2->setObjectName(QString::fromUtf8("headingPGainLabel_2"));

    formLayout_3->setWidget(0, QFormLayout::LabelRole, headingPGainLabel_2);

    buoyHeadingPGainSpinBox = new QDoubleSpinBox(groupBox_6);
    buoyHeadingPGainSpinBox->setObjectName(QString::fromUtf8("buoyHeadingPGainSpinBox"));
    buoyHeadingPGainSpinBox->setSingleStep(0.01);

    formLayout_3->setWidget(0, QFormLayout::FieldRole, buoyHeadingPGainSpinBox);

    headingIGainLabel_2 = new QLabel(groupBox_6);
    headingIGainLabel_2->setObjectName(QString::fromUtf8("headingIGainLabel_2"));

    formLayout_3->setWidget(1, QFormLayout::LabelRole, headingIGainLabel_2);

    buoyHeadingIGainSpinBox = new QDoubleSpinBox(groupBox_6);
    buoyHeadingIGainSpinBox->setObjectName(QString::fromUtf8("buoyHeadingIGainSpinBox"));
    buoyHeadingIGainSpinBox->setSingleStep(0.01);

    formLayout_3->setWidget(1, QFormLayout::FieldRole, buoyHeadingIGainSpinBox);

    headingDGainLabel_2 = new QLabel(groupBox_6);
    headingDGainLabel_2->setObjectName(QString::fromUtf8("headingDGainLabel_2"));

    formLayout_3->setWidget(2, QFormLayout::LabelRole, headingDGainLabel_2);

    buoyHeadingDGainSpinBox = new QDoubleSpinBox(groupBox_6);
    buoyHeadingDGainSpinBox->setObjectName(QString::fromUtf8("buoyHeadingDGainSpinBox"));
    buoyHeadingDGainSpinBox->setSingleStep(0.01);

    formLayout_3->setWidget(2, QFormLayout::FieldRole, buoyHeadingDGainSpinBox);


    verticalLayout_3->addWidget(groupBox_6);

    groupBox_4 = new QGroupBox(groupBox_3);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    formLayout_4 = new QFormLayout(groupBox_4);
    formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
    depthPGainLabel_2 = new QLabel(groupBox_4);
    depthPGainLabel_2->setObjectName(QString::fromUtf8("depthPGainLabel_2"));

    formLayout_4->setWidget(0, QFormLayout::LabelRole, depthPGainLabel_2);

    depthIGainLabel_2 = new QLabel(groupBox_4);
    depthIGainLabel_2->setObjectName(QString::fromUtf8("depthIGainLabel_2"));

    formLayout_4->setWidget(1, QFormLayout::LabelRole, depthIGainLabel_2);

    depthDGainLabel_2 = new QLabel(groupBox_4);
    depthDGainLabel_2->setObjectName(QString::fromUtf8("depthDGainLabel_2"));

    formLayout_4->setWidget(2, QFormLayout::LabelRole, depthDGainLabel_2);

    buoyDepthPGainSpinBox = new QDoubleSpinBox(groupBox_4);
    buoyDepthPGainSpinBox->setObjectName(QString::fromUtf8("buoyDepthPGainSpinBox"));
    buoyDepthPGainSpinBox->setSingleStep(0.01);

    formLayout_4->setWidget(0, QFormLayout::FieldRole, buoyDepthPGainSpinBox);

    buoyDepthIGainSpinBox = new QDoubleSpinBox(groupBox_4);
    buoyDepthIGainSpinBox->setObjectName(QString::fromUtf8("buoyDepthIGainSpinBox"));
    buoyDepthIGainSpinBox->setSingleStep(0.01);

    formLayout_4->setWidget(1, QFormLayout::FieldRole, buoyDepthIGainSpinBox);

    buoyDepthDGainSpinBox = new QDoubleSpinBox(groupBox_4);
    buoyDepthDGainSpinBox->setObjectName(QString::fromUtf8("buoyDepthDGainSpinBox"));
    buoyDepthDGainSpinBox->setSingleStep(0.01);

    formLayout_4->setWidget(2, QFormLayout::FieldRole, buoyDepthDGainSpinBox);


    verticalLayout_3->addWidget(groupBox_4);


    horizontalLayout_6->addWidget(groupBox_3);

    pathSaturationSpinBox->addTab(controllersTab, QString());
    visionTab = new QWidget();
    visionTab->setObjectName(QString::fromUtf8("visionTab"));
    visionTab->setGeometry(QRect(0, 0, 918, 332));
    horizontalLayout_5 = new QHBoxLayout(visionTab);
    horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
    groupBox_8 = new QGroupBox(visionTab);
    groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
    verticalLayout_4 = new QVBoxLayout(groupBox_8);
    verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
    label_20 = new QLabel(groupBox_8);
    label_20->setObjectName(QString::fromUtf8("label_20"));
    sizePolicy1.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
    label_20->setSizePolicy(sizePolicy1);

    verticalLayout_4->addWidget(label_20);

    doubleSpinBox_6 = new QDoubleSpinBox(groupBox_8);
    doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));

    verticalLayout_4->addWidget(doubleSpinBox_6);

    pushButton = new QPushButton(groupBox_8);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    verticalLayout_4->addWidget(pushButton);


    horizontalLayout_5->addWidget(groupBox_8);

    groupBox_5 = new QGroupBox(visionTab);
    groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
    formLayout_6 = new QFormLayout(groupBox_5);
    formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
    formLayout_6->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    label_10 = new QLabel(groupBox_5);
    label_10->setObjectName(QString::fromUtf8("label_10"));

    formLayout_6->setWidget(0, QFormLayout::LabelRole, label_10);

    pathHueHighSpinBox = new QDoubleSpinBox(groupBox_5);
    pathHueHighSpinBox->setObjectName(QString::fromUtf8("pathHueHighSpinBox"));

    formLayout_6->setWidget(0, QFormLayout::FieldRole, pathHueHighSpinBox);

    label_15 = new QLabel(groupBox_5);
    label_15->setObjectName(QString::fromUtf8("label_15"));

    formLayout_6->setWidget(1, QFormLayout::LabelRole, label_15);

    pathHueLowSpinBox = new QDoubleSpinBox(groupBox_5);
    pathHueLowSpinBox->setObjectName(QString::fromUtf8("pathHueLowSpinBox"));

    formLayout_6->setWidget(1, QFormLayout::FieldRole, pathHueLowSpinBox);

    label_23 = new QLabel(groupBox_5);
    label_23->setObjectName(QString::fromUtf8("label_23"));

    formLayout_6->setWidget(2, QFormLayout::LabelRole, label_23);

    pathSaturationSpinBox_2 = new QDoubleSpinBox(groupBox_5);
    pathSaturationSpinBox_2->setObjectName(QString::fromUtf8("pathSaturationSpinBox_2"));

    formLayout_6->setWidget(2, QFormLayout::FieldRole, pathSaturationSpinBox_2);


    horizontalLayout_5->addWidget(groupBox_5);

    groupBox_7 = new QGroupBox(visionTab);
    groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
    formLayout_5 = new QFormLayout(groupBox_7);
    formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
    formLayout_5->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
    label_7 = new QLabel(groupBox_7);
    label_7->setObjectName(QString::fromUtf8("label_7"));

    formLayout_5->setWidget(1, QFormLayout::LabelRole, label_7);

    label_8 = new QLabel(groupBox_7);
    label_8->setObjectName(QString::fromUtf8("label_8"));

    formLayout_5->setWidget(2, QFormLayout::LabelRole, label_8);

    buoyHueHighSpinBox = new QDoubleSpinBox(groupBox_7);
    buoyHueHighSpinBox->setObjectName(QString::fromUtf8("buoyHueHighSpinBox"));

    formLayout_5->setWidget(1, QFormLayout::FieldRole, buoyHueHighSpinBox);

    buoyHueLowSpinBox = new QDoubleSpinBox(groupBox_7);
    buoyHueLowSpinBox->setObjectName(QString::fromUtf8("buoyHueLowSpinBox"));

    formLayout_5->setWidget(2, QFormLayout::FieldRole, buoyHueLowSpinBox);

    label_5 = new QLabel(groupBox_7);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    formLayout_5->setWidget(3, QFormLayout::LabelRole, label_5);

    buoySaturationSpinBox = new QDoubleSpinBox(groupBox_7);
    buoySaturationSpinBox->setObjectName(QString::fromUtf8("buoySaturationSpinBox"));

    formLayout_5->setWidget(3, QFormLayout::FieldRole, buoySaturationSpinBox);


    horizontalLayout_5->addWidget(groupBox_7);

    pathSaturationSpinBox->addTab(visionTab, QString());

    verticalLayout->addWidget(pathSaturationSpinBox);

    DashboardWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(DashboardWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 940, 24));
    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    menuLogging = new QMenu(menubar);
    menuLogging->setObjectName(QString::fromUtf8("menuLogging"));
    DashboardWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(DashboardWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    statusbar->setGeometry(QRect(0, 797, 940, 24));
    DashboardWindow->setStatusBar(statusbar);
    toolBar = new QToolBar(DashboardWindow);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    toolBar->setGeometry(QRect(0, 24, 940, 27));
    toolBar->setMovable(false);
    toolBar->setFloatable(false);
    DashboardWindow->addToolBar(Qt::TopToolBarArea, toolBar);
    QWidget::setTabOrder(pathSaturationSpinBox, headingPGainSpinBox);
    QWidget::setTabOrder(headingPGainSpinBox, headingIGainSpinBox);
    QWidget::setTabOrder(headingIGainSpinBox, headingDGainSpinBox);
    QWidget::setTabOrder(headingDGainSpinBox, depthPGainSpinBox);
    QWidget::setTabOrder(depthPGainSpinBox, depthIGainSpinBox);
    QWidget::setTabOrder(depthIGainSpinBox, depthDGainSpinBox);
    QWidget::setTabOrder(depthDGainSpinBox, buoyHeadingPGainSpinBox);
    QWidget::setTabOrder(buoyHeadingPGainSpinBox, buoyHeadingIGainSpinBox);
    QWidget::setTabOrder(buoyHeadingIGainSpinBox, buoyHeadingDGainSpinBox);
    QWidget::setTabOrder(buoyHeadingDGainSpinBox, buoyDepthPGainSpinBox);
    QWidget::setTabOrder(buoyDepthPGainSpinBox, buoyDepthIGainSpinBox);
    QWidget::setTabOrder(buoyDepthIGainSpinBox, buoyDepthDGainSpinBox);
    QWidget::setTabOrder(buoyDepthDGainSpinBox, doubleSpinBox_6);
    QWidget::setTabOrder(doubleSpinBox_6, pathHueHighSpinBox);
    QWidget::setTabOrder(pathHueHighSpinBox, pathHueLowSpinBox);
    QWidget::setTabOrder(pathHueLowSpinBox, buoyHueHighSpinBox);
    QWidget::setTabOrder(buoyHueHighSpinBox, buoyHueLowSpinBox);
    QWidget::setTabOrder(buoyHueLowSpinBox, controlGroupBox);
    QWidget::setTabOrder(controlGroupBox, desiredHeadingDial);
    QWidget::setTabOrder(desiredHeadingDial, desiredHeadingSpinBox);
    QWidget::setTabOrder(desiredHeadingSpinBox, desiredSpeedSlider);
    QWidget::setTabOrder(desiredSpeedSlider, desiredSpeedSpinBox);
    QWidget::setTabOrder(desiredSpeedSpinBox, cameraPosComboBox);
    QWidget::setTabOrder(cameraPosComboBox, desiredDepthSpinBox);
    QWidget::setTabOrder(desiredDepthSpinBox, desiredDepthSlider);

    menubar->addAction(menuFile->menuAction());
    menubar->addAction(menuLogging->menuAction());
    menuFile->addAction(actionOpen_AUVScript);
    menuFile->addSeparator();
    menuFile->addAction(actionQuit);
    menuLogging->addAction(actionSet_Logfile_Directory);
    toolBar->addAction(actionGo);
    toolBar->addAction(actionStop);
    toolBar->addSeparator();
    toolBar->addAction(actionReset);
    toolBar->addAction(actionKill);
    toolBar->addSeparator();
    toolBar->addAction(actionStart_Logging);
    toolBar->addAction(actionStop_Logging);

    retranslateUi(DashboardWindow);
    QObject::connect(desiredHeadingSpinBox, SIGNAL(valueChanged(int)), desiredHeadingDial, SLOT(setValue(int)));
    QObject::connect(desiredHeadingDial, SIGNAL(valueChanged(int)), desiredHeadingSpinBox, SLOT(setValue(int)));
    QObject::connect(desiredDepthSpinBox, SIGNAL(valueChanged(int)), desiredDepthSlider, SLOT(setValue(int)));
    QObject::connect(desiredDepthSlider, SIGNAL(valueChanged(int)), desiredDepthSpinBox, SLOT(setValue(int)));
    QObject::connect(desiredSpeedSpinBox, SIGNAL(valueChanged(int)), desiredSpeedSlider, SLOT(setValue(int)));
    QObject::connect(desiredSpeedSlider, SIGNAL(valueChanged(int)), desiredSpeedSpinBox, SLOT(setValue(int)));

    pathSaturationSpinBox->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(DashboardWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DashboardWindow)
    {
    DashboardWindow->setWindowTitle(QApplication::translate("DashboardWindow", "AUVT Dashboard V0.2", 0, QApplication::UnicodeUTF8));
    actionQuit->setText(QApplication::translate("DashboardWindow", "Quit", 0, QApplication::UnicodeUTF8));
    actionOpen_AUVScript->setText(QApplication::translate("DashboardWindow", "Open AUVScript", 0, QApplication::UnicodeUTF8));
    actionSet_Logfile_Directory->setText(QApplication::translate("DashboardWindow", "Set Logfile Directory", 0, QApplication::UnicodeUTF8));
    actionGo->setText(QApplication::translate("DashboardWindow", "Go", 0, QApplication::UnicodeUTF8));
    actionStop->setText(QApplication::translate("DashboardWindow", "Stop", 0, QApplication::UnicodeUTF8));
    actionKill->setText(QApplication::translate("DashboardWindow", "Kill", 0, QApplication::UnicodeUTF8));
    actionStart_Logging->setText(QApplication::translate("DashboardWindow", "Start Logging", 0, QApplication::UnicodeUTF8));
    actionStop_Logging->setText(QApplication::translate("DashboardWindow", "Stop Logging", 0, QApplication::UnicodeUTF8));
    actionReset->setText(QApplication::translate("DashboardWindow", "Reset", 0, QApplication::UnicodeUTF8));
    statusGroupBox->setTitle(QApplication::translate("DashboardWindow", "AUV Status", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("DashboardWindow", "Mission Progress:", 0, QApplication::UnicodeUTF8));
    depthLabel->setText(QApplication::translate("DashboardWindow", "Depth:", 0, QApplication::UnicodeUTF8));
    headingLabel->setText(QApplication::translate("DashboardWindow", "Heading:", 0, QApplication::UnicodeUTF8));
    stateLabelLabel->setText(QApplication::translate("DashboardWindow", "Stateflow State:", 0, QApplication::UnicodeUTF8));
    stateLabel->setText(QString());
    label_16->setText(QApplication::translate("DashboardWindow", "Camera Position:", 0, QApplication::UnicodeUTF8));
    label_17->setText(QApplication::translate("DashboardWindow", "Controller State:", 0, QApplication::UnicodeUTF8));
    controlStateLabel->setText(QApplication::translate("DashboardWindow", "Stopped", 0, QApplication::UnicodeUTF8));
    label_9->setText(QApplication::translate("DashboardWindow", "Forward", 0, QApplication::UnicodeUTF8));
    label_12->setText(QApplication::translate("DashboardWindow", "Left Thruster:", 0, QApplication::UnicodeUTF8));
    leftThrusterProgressBar->setFormat(QApplication::translate("DashboardWindow", "%v", 0, QApplication::UnicodeUTF8));
    label_13->setText(QApplication::translate("DashboardWindow", "Right Thruster", 0, QApplication::UnicodeUTF8));
    rightThrusterProgressBar->setFormat(QApplication::translate("DashboardWindow", "%v", 0, QApplication::UnicodeUTF8));
    label_14->setText(QApplication::translate("DashboardWindow", "Vertical Thruster:", 0, QApplication::UnicodeUTF8));
    vertThrusterProgressBar->setFormat(QApplication::translate("DashboardWindow", "%v", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("DashboardWindow", "-127", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("DashboardWindow", "0", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("DashboardWindow", "127", 0, QApplication::UnicodeUTF8));
    label_24->setText(QApplication::translate("DashboardWindow", "Thust Scale Factor", 0, QApplication::UnicodeUTF8));
    controlGroupBox->setTitle(QApplication::translate("DashboardWindow", "AUV Control", 0, QApplication::UnicodeUTF8));
    desiredDepthLabel->setText(QApplication::translate("DashboardWindow", "Depth", 0, QApplication::UnicodeUTF8));
    desiredDepthSpinBox->setSuffix(QApplication::translate("DashboardWindow", " ft", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("DashboardWindow", "0", 0, QApplication::UnicodeUTF8));
    label_11->setText(QApplication::translate("DashboardWindow", "18", 0, QApplication::UnicodeUTF8));
    desiredHeadingLabel->setText(QApplication::translate("DashboardWindow", "Desired Heading", 0, QApplication::UnicodeUTF8));
    desiredHeadingSpinBox->setSuffix(QApplication::translate("DashboardWindow", " degrees", 0, QApplication::UnicodeUTF8));
    desiredSpeedLabel->setText(QApplication::translate("DashboardWindow", "Desired Speed", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_TOOLTIP
    desiredSpeedSlider->setToolTip(QApplication::translate("DashboardWindow", "Go Faster!", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP

    minSpeedLabel->setText(QApplication::translate("DashboardWindow", "0", 0, QApplication::UnicodeUTF8));
    maxSpeedLabel->setText(QApplication::translate("DashboardWindow", "Full Speed", 0, QApplication::UnicodeUTF8));
    label_19->setText(QApplication::translate("DashboardWindow", "Camera Position:", 0, QApplication::UnicodeUTF8));
    cameraPosComboBox->clear();
    cameraPosComboBox->insertItems(0, QStringList()
     << QApplication::translate("DashboardWindow", "Forward", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("DashboardWindow", "Up", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("DashboardWindow", "Down", 0, QApplication::UnicodeUTF8)
    );
    label_21->setText(QApplication::translate("DashboardWindow", "Forward Velocity:", 0, QApplication::UnicodeUTF8));
    label_22->setText(QApplication::translate("DashboardWindow", "Approach Velocity: ", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("DashboardWindow", "Heading PID", 0, QApplication::UnicodeUTF8));
    headingPGainLabel->setText(QApplication::translate("DashboardWindow", "Proportional", 0, QApplication::UnicodeUTF8));
    headingIGainLabel->setText(QApplication::translate("DashboardWindow", "Integral", 0, QApplication::UnicodeUTF8));
    headingDGainLabel->setText(QApplication::translate("DashboardWindow", "Derivative", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("DashboardWindow", "Depth PID", 0, QApplication::UnicodeUTF8));
    depthPGainLabel->setText(QApplication::translate("DashboardWindow", "Proportional", 0, QApplication::UnicodeUTF8));
    depthIGainLabel->setText(QApplication::translate("DashboardWindow", "IIntegral", 0, QApplication::UnicodeUTF8));
    depthDGainLabel->setText(QApplication::translate("DashboardWindow", "Derivative", 0, QApplication::UnicodeUTF8));
    groupBox_9->setTitle(QApplication::translate("DashboardWindow", "Path Approach Controller", 0, QApplication::UnicodeUTF8));
    groupBox_11->setTitle(QApplication::translate("DashboardWindow", "X-Axis PID", 0, QApplication::UnicodeUTF8));
    headingPGainLabel_3->setText(QApplication::translate("DashboardWindow", "Proportional", 0, QApplication::UnicodeUTF8));
    headingIGainLabel_3->setText(QApplication::translate("DashboardWindow", "Integral", 0, QApplication::UnicodeUTF8));
    headingDGainLabel_3->setText(QApplication::translate("DashboardWindow", "Derivative", 0, QApplication::UnicodeUTF8));
    groupBox_10->setTitle(QApplication::translate("DashboardWindow", "Y-Axis PID", 0, QApplication::UnicodeUTF8));
    depthPGainLabel_3->setText(QApplication::translate("DashboardWindow", "Proportional", 0, QApplication::UnicodeUTF8));
    depthIGainLabel_3->setText(QApplication::translate("DashboardWindow", "IIntegral", 0, QApplication::UnicodeUTF8));
    depthDGainLabel_3->setText(QApplication::translate("DashboardWindow", "Derivative", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("DashboardWindow", "Buoy Approach Controller", 0, QApplication::UnicodeUTF8));
    groupBox_6->setTitle(QApplication::translate("DashboardWindow", "X-Axis PID", 0, QApplication::UnicodeUTF8));
    headingPGainLabel_2->setText(QApplication::translate("DashboardWindow", "Proportional", 0, QApplication::UnicodeUTF8));
    headingIGainLabel_2->setText(QApplication::translate("DashboardWindow", "Integral", 0, QApplication::UnicodeUTF8));
    headingDGainLabel_2->setText(QApplication::translate("DashboardWindow", "Derivative", 0, QApplication::UnicodeUTF8));
    groupBox_4->setTitle(QApplication::translate("DashboardWindow", "Y-Axis PID", 0, QApplication::UnicodeUTF8));
    depthPGainLabel_2->setText(QApplication::translate("DashboardWindow", "Proportional", 0, QApplication::UnicodeUTF8));
    depthIGainLabel_2->setText(QApplication::translate("DashboardWindow", "IIntegral", 0, QApplication::UnicodeUTF8));
    depthDGainLabel_2->setText(QApplication::translate("DashboardWindow", "Derivative", 0, QApplication::UnicodeUTF8));
    pathSaturationSpinBox->setTabText(pathSaturationSpinBox->indexOf(controllersTab), QApplication::translate("DashboardWindow", "Controllers", 0, QApplication::UnicodeUTF8));
    groupBox_8->setTitle(QApplication::translate("DashboardWindow", "General", 0, QApplication::UnicodeUTF8));
    label_20->setText(QApplication::translate("DashboardWindow", "Magic Index", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("DashboardWindow", "Fix White-Balancing", 0, QApplication::UnicodeUTF8));
    groupBox_5->setTitle(QApplication::translate("DashboardWindow", "Paths", 0, QApplication::UnicodeUTF8));
    label_10->setText(QApplication::translate("DashboardWindow", "Hue (High)", 0, QApplication::UnicodeUTF8));
    label_15->setText(QApplication::translate("DashboardWindow", "Hue (Low)", 0, QApplication::UnicodeUTF8));
    label_23->setText(QApplication::translate("DashboardWindow", "Saturation", 0, QApplication::UnicodeUTF8));
    groupBox_7->setTitle(QApplication::translate("DashboardWindow", "Buoy", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("DashboardWindow", "Hue (High)", 0, QApplication::UnicodeUTF8));
    label_8->setText(QApplication::translate("DashboardWindow", "Hue (Low)", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("DashboardWindow", "Saturation", 0, QApplication::UnicodeUTF8));
    pathSaturationSpinBox->setTabText(pathSaturationSpinBox->indexOf(visionTab), QApplication::translate("DashboardWindow", "Vision", 0, QApplication::UnicodeUTF8));
    menuFile->setTitle(QApplication::translate("DashboardWindow", "File", 0, QApplication::UnicodeUTF8));
    menuLogging->setTitle(QApplication::translate("DashboardWindow", "Logging", 0, QApplication::UnicodeUTF8));
    toolBar->setWindowTitle(QApplication::translate("DashboardWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DashboardWindow: public Ui_DashboardWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
