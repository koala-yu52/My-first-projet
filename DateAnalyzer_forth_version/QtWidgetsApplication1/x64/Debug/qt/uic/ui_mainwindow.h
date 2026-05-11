/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_7;
    QStackedWidget *mainStackedWidget;
    QWidget *page_home;
    QGridLayout *gridLayout;
    QPushButton *btn_go_fit;
    QPushButton *btn_go_mean;
    QPushButton *btn_go_stats;
    QPushButton *btn_go_ind;
    QPushButton *btn_go_B;
    QPushButton *btn_go_A;
    QWidget *page_mean;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QGroupBox *group_input_mean;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *table_mean;
    QPushButton *btn_add_mean;
    QPushButton *btn_del_mean;
    QPushButton *btn_calc_mean;
    QGroupBox *group_process_mean;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *text_res_mean;
    QPushButton *btn_back_mean;
    QWidget *page_stats;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *group_input_stats;
    QVBoxLayout *verticalLayout;
    QTableWidget *table_stats;
    QPushButton *btn_add_stats;
    QPushButton *btn_del_stats;
    QPushButton *btn_calc_stats;
    QGroupBox *group_res_statsox;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *text_res_stats;
    QPushButton *btn_back_stats;
    QWidget *page_typeA;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *leftPanel_A;
    QVBoxLayout *verticalLayout_10;
    QTableWidget *table_A;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn_add_A;
    QPushButton *btn_del_A;
    QLabel *label;
    QLineEdit *edit_t_A;
    QPushButton *btn_calc_A;
    QGroupBox *rightPanel_A;
    QVBoxLayout *verticalLayout_7;
    QTextEdit *text_res_A;
    QPushButton *btn_back_A;
    QWidget *page_typeB;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *group_B_res;
    QVBoxLayout *verticalLayout_13;
    QTextEdit *text_res_B;
    QGroupBox *group_B_input;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_2;
    QLineEdit *edit_delta_B;
    QLabel *label_3;
    QLineEdit *edit_k_B;
    QPushButton *btn_calc_B;
    QPushButton *btn_back_B;
    QWidget *page_indirect;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *leftPanel_ind;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_4;
    QLineEdit *edit_formula_ind;
    QLabel *label_help;
    QLabel *label_help_2;
    QTableWidget *table_ind;
    QPushButton *btn_add_ind;
    QPushButton *btn_del_ind;
    QPushButton *btn_calc_ind;
    QGroupBox *rightPanel_ind;
    QVBoxLayout *verticalLayout_16;
    QTextEdit *text_res_ind;
    QPushButton *btn_back_ind;
    QWidget *page_fitting;
    QVBoxLayout *verticalLayout_17;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *leftPanel_fit;
    QVBoxLayout *verticalLayout_18;
    QTableWidget *table_fit;
    QPushButton *btn_add_fit;
    QPushButton *btn_del_fit;
    QLabel *label_5;
    QComboBox *combo_fit_type;
    QPushButton *btn_run_fit;
    QGroupBox *rightPanel_fit;
    QVBoxLayout *verticalLayout_11;
    QCustomPlot *plotWidget_fit;
    QHBoxLayout *horizontalLayout_10;
    QTextEdit *text_res_fit;
    QPushButton *btn_back_fit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1074, 847);
        MainWindow->setStyleSheet(QString::fromUtf8("/* 1. \350\256\276\347\275\256\345\205\250\345\261\200\345\272\225\350\211\262\357\274\210\346\270\205\346\226\260\346\267\241\351\233\205\347\201\260\357\274\211 */\n"
"QMainWindow {\n"
"    background-color: #f2f2f2;\n"
"}\n"
"\n"
"/* 2. \347\273\231\345\244\232\351\241\265\351\235\242\345\256\271\345\231\250\350\256\276\347\275\256\346\260\264\345\215\260\357\274\214\344\275\277\345\205\266\345\234\250\346\257\217\344\270\200\351\241\265\347\232\204\346\255\243\344\270\255\345\244\256\346\230\276\347\244\272 */\n"
"#mainStackedWidget {\n"
"    background-image: url(:/new/images/nankai_watermark.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-attachment: fixed;\n"
"}\n"
"\n"
"/* 3. \350\256\251\351\241\265\351\235\242\350\203\214\346\231\257\351\200\217\346\230\216\357\274\214\347\241\256\344\277\235\350\203\275\347\234\213\345\210\260\345\272\225\345\261\202\347\232\204\346\240\241\345\276\275 */\n"
"#mainStackedWidget > QWidget {\n"
"    background: trans"
                        "parent;\n"
"}\n"
"\n"
"/* 4. \346\214\211\351\222\256\347\262\276\344\277\256\357\274\232\347\231\275\345\272\225 + \345\215\227\345\274\200\347\264\253\347\272\277\346\235\241 */\n"
"QPushButton {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #741B47;  /* \345\215\227\345\274\200\347\264\253\346\240\207\345\207\206\350\211\262 */\n"
"    border-radius: 6px;\n"
"    color: #741B47;\n"
"    font-family: \"Microsoft YaHei\";\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    min-height: 55px; /* \350\256\251\346\214\211\351\222\256\347\234\213\350\265\267\346\235\245\345\216\232\345\256\236\344\272\233 */\n"
"}\n"
"\n"
"/* \346\214\211\351\222\256\351\274\240\346\240\207\346\202\254\345\201\234\346\225\210\346\236\234\357\274\232\345\217\230\350\211\262\345\217\215\350\275\254 */\n"
"QPushButton:hover {\n"
"    background-color: #741B47;\n"
"    color: #ffffff;\n"
"}\n"
"\n"
"/* 5. \350\241\250\346\240\274\343\200\201\350\276\223\345\205\245\346\241\206\343\200\201\346\226\207\346\234\254"
                        "\346\241\206\357\274\232\345\215\212\351\200\217\346\230\216\347\231\275\357\274\210\350\213\245\351\232\220\350\213\245\347\216\260\347\234\213\345\210\260\346\260\264\345\215\260\357\274\211 */\n"
"QTableWidget, QLineEdit, QTextEdit {\n"
"    background-color: rgba(255, 255, 255, 150); /* 150/255 \347\232\204\351\200\217\346\230\216\345\272\246 */\n"
"    border: 1px solid #d1d1d1;\n"
"    border-radius: 4px;\n"
"    color: #333333;\n"
"}\n"
"\n"
"/* 6. \351\230\262\346\255\242\346\260\264\345\215\260\345\234\250\346\214\211\351\222\256\346\210\226\345\260\217\351\233\266\344\273\266\345\206\205\351\203\250\351\207\215\345\244\215\345\207\272\347\216\260 */\n"
"QPushButton, QLineEdit, QHeaderView, QLabel {\n"
"    background-image: none;\n"
"}\n"
"#centralWidget {\n"
"    background-color: #fdfaf2; /* \350\261\241\347\211\231\346\232\226\347\261\263\350\211\262 */\n"
"    background-image: url(:/images/nankai_watermark.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"}\n"
""
                        "QPushButton {\n"
"    /* \344\275\277\347\224\250 rgba\357\274\214\346\234\200\345\220\216\347\232\204 150 \350\241\250\347\244\272\350\203\214\346\231\257\345\217\252\346\234\211\347\272\246 60% \347\232\204\344\270\215\351\200\217\346\230\216\345\272\246 */\n"
"    background-color: rgba(255, 255, 255, 150); \n"
"    border: 1px solid #741B47;\n"
"    border-radius: 8px;\n"
"    color: #741B47;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    /* \346\202\254\345\201\234\346\227\266\347\250\215\345\276\256\345\212\240\346\267\261\351\200\217\346\230\216\345\272\246\357\274\214\344\272\247\347\224\237\344\272\244\344\272\222\346\204\237 */\n"
"    background-color: rgba(116, 27, 71, 40); \n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setStyleSheet(QString::fromUtf8("#centralWidget {\n"
"    background-color: #f4f4f9; /* \346\236\201\346\267\241\347\232\204\347\264\253\347\201\260\350\211\262\357\274\214\345\271\262\345\207\200\344\270\224\346\234\211\350\264\250\346\204\237 */\n"
"    background-image: url(:/images/nankai_watermark.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"}\n"
"/* 1. \346\214\211\351\222\256\347\232\204\345\270\270\346\200\201\357\274\232\345\270\246\346\234\211\350\264\250\346\204\237\347\232\204\345\215\227\345\274\200\347\264\253 */\n"
"QPushButton {\n"
"    /* \346\270\220\345\217\230\345\272\225\350\211\262\357\274\232\350\256\251\346\214\211\351\222\256\347\234\213\350\265\267\346\235\245\346\234\211\347\253\213\344\275\223\346\204\237 */\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                      stop:0 rgba(255, 255, 255, 255), \n"
"                      stop:1 rgba(240, 230, 245, 255));\n"
"    \n"
"    border: 2px solid #741B47;       /* \345\215\227\345\274"
                        "\200\347\264\253\350\276\271\346\241\206 */\n"
"    border-radius: 12px;             /* \345\244\247\345\234\206\350\247\222\357\274\214\346\233\264\346\234\211\346\270\270\346\210\217UI\346\204\237 */\n"
"    color: #741B47;                  /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    font-family: \"Microsoft YaHei\";\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    padding: 10px;\n"
"    min-height: 55px;\n"
"}\n"
"\n"
"/* 2. \351\274\240\346\240\207\346\202\254\345\201\234\346\200\201\357\274\232\344\272\247\347\224\237\342\200\234\345\217\221\345\205\211\342\200\235\346\225\210\346\236\234 */\n"
"QPushButton:hover {\n"
"    /* \350\203\214\346\231\257\345\217\230\344\272\256 */\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"                      stop:0 rgba(116, 27, 71, 20), \n"
"                      stop:1 rgba(116, 27, 71, 50));\n"
"    \n"
"    /* \350\276\271\346\241\206\345\217\230\344\270\272\344\272\256\347\264\253\350\211\262\357\274"
                        "\210\351\234\223\350\231\271\345\205\211\357\274\211 */\n"
"    border: 2px solid #a000ff;       \n"
"    color: #a000ff;                  /* \346\226\207\345\255\227\344\271\237\350\267\237\347\235\200\344\272\256\350\265\267\346\235\245 */\n"
"    \n"
"    /* \346\250\241\346\213\237\345\244\226\345\217\221\345\205\211\357\274\232\345\242\236\345\212\240\350\276\271\346\241\206\345\216\232\345\272\246\346\204\237 */\n"
"    padding-left: 11px;\n"
"    padding-top: 11px;\n"
"}\n"
"\n"
"/* 3. \346\214\211\351\222\256\346\214\211\344\270\213\346\200\201\357\274\232\345\217\215\351\246\210\346\225\210\346\236\234 */\n"
"QPushButton:pressed {\n"
"    background-color: #741B47;       /* \346\214\211\344\270\213\346\227\266\350\203\214\346\231\257\345\241\253\346\273\241\345\215\227\345\274\200\347\264\253 */\n"
"    border: 2px solid #00f0ff;       /* \350\276\271\346\241\206\351\227\252\347\203\201\351\235\222\350\211\262\345\205\211\350\212\222\357\274\210\350\265\233\345\215\232\347\202\271\347\274\200\357\274\211"
                        " */\n"
"    color: white;                    /* \346\226\207\345\255\227\345\217\215\347\231\275 */\n"
"}\n"
"QPushButton, QLabel, QLineEdit, QTableWidget {\n"
"    background-image: none;\n"
"}"));
        horizontalLayout_7 = new QHBoxLayout(centralWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        mainStackedWidget = new QStackedWidget(centralWidget);
        mainStackedWidget->setObjectName("mainStackedWidget");
        page_home = new QWidget();
        page_home->setObjectName("page_home");
        gridLayout = new QGridLayout(page_home);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(100, 100, 100, 100);
        btn_go_fit = new QPushButton(page_home);
        btn_go_fit->setObjectName("btn_go_fit");

        gridLayout->addWidget(btn_go_fit, 1, 2, 1, 1);

        btn_go_mean = new QPushButton(page_home);
        btn_go_mean->setObjectName("btn_go_mean");

        gridLayout->addWidget(btn_go_mean, 1, 0, 1, 1);

        btn_go_stats = new QPushButton(page_home);
        btn_go_stats->setObjectName("btn_go_stats");

        gridLayout->addWidget(btn_go_stats, 1, 1, 1, 1);

        btn_go_ind = new QPushButton(page_home);
        btn_go_ind->setObjectName("btn_go_ind");

        gridLayout->addWidget(btn_go_ind, 3, 2, 1, 1);

        btn_go_B = new QPushButton(page_home);
        btn_go_B->setObjectName("btn_go_B");

        gridLayout->addWidget(btn_go_B, 3, 1, 1, 1);

        btn_go_A = new QPushButton(page_home);
        btn_go_A->setObjectName("btn_go_A");

        gridLayout->addWidget(btn_go_A, 3, 0, 1, 1);

        mainStackedWidget->addWidget(page_home);
        page_mean = new QWidget();
        page_mean->setObjectName("page_mean");
        verticalLayout_6 = new QVBoxLayout(page_mean);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        group_input_mean = new QGroupBox(page_mean);
        group_input_mean->setObjectName("group_input_mean");
        group_input_mean->setMaximumSize(QSize(300, 16777215));
        verticalLayout_3 = new QVBoxLayout(group_input_mean);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        table_mean = new QTableWidget(group_input_mean);
        if (table_mean->columnCount() < 1)
            table_mean->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_mean->setHorizontalHeaderItem(0, __qtablewidgetitem);
        table_mean->setObjectName("table_mean");

        verticalLayout_3->addWidget(table_mean);

        btn_add_mean = new QPushButton(group_input_mean);
        btn_add_mean->setObjectName("btn_add_mean");

        verticalLayout_3->addWidget(btn_add_mean);

        btn_del_mean = new QPushButton(group_input_mean);
        btn_del_mean->setObjectName("btn_del_mean");

        verticalLayout_3->addWidget(btn_del_mean);

        btn_calc_mean = new QPushButton(group_input_mean);
        btn_calc_mean->setObjectName("btn_calc_mean");

        verticalLayout_3->addWidget(btn_calc_mean);


        horizontalLayout->addWidget(group_input_mean);

        group_process_mean = new QGroupBox(page_mean);
        group_process_mean->setObjectName("group_process_mean");
        verticalLayout_2 = new QVBoxLayout(group_process_mean);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        text_res_mean = new QTextEdit(group_process_mean);
        text_res_mean->setObjectName("text_res_mean");
        text_res_mean->setReadOnly(true);

        verticalLayout_2->addWidget(text_res_mean);


        horizontalLayout->addWidget(group_process_mean);


        verticalLayout_6->addLayout(horizontalLayout);

        btn_back_mean = new QPushButton(page_mean);
        btn_back_mean->setObjectName("btn_back_mean");

        verticalLayout_6->addWidget(btn_back_mean);

        mainStackedWidget->addWidget(page_mean);
        page_stats = new QWidget();
        page_stats->setObjectName("page_stats");
        verticalLayout_5 = new QVBoxLayout(page_stats);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        group_input_stats = new QGroupBox(page_stats);
        group_input_stats->setObjectName("group_input_stats");
        group_input_stats->setMaximumSize(QSize(300, 16777215));
        verticalLayout = new QVBoxLayout(group_input_stats);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        table_stats = new QTableWidget(group_input_stats);
        if (table_stats->columnCount() < 1)
            table_stats->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_stats->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        table_stats->setObjectName("table_stats");

        verticalLayout->addWidget(table_stats);

        btn_add_stats = new QPushButton(group_input_stats);
        btn_add_stats->setObjectName("btn_add_stats");

        verticalLayout->addWidget(btn_add_stats);

        btn_del_stats = new QPushButton(group_input_stats);
        btn_del_stats->setObjectName("btn_del_stats");

        verticalLayout->addWidget(btn_del_stats);

        btn_calc_stats = new QPushButton(group_input_stats);
        btn_calc_stats->setObjectName("btn_calc_stats");

        verticalLayout->addWidget(btn_calc_stats);


        horizontalLayout_3->addWidget(group_input_stats);

        group_res_statsox = new QGroupBox(page_stats);
        group_res_statsox->setObjectName("group_res_statsox");
        verticalLayout_4 = new QVBoxLayout(group_res_statsox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        text_res_stats = new QTextEdit(group_res_statsox);
        text_res_stats->setObjectName("text_res_stats");
        text_res_stats->setReadOnly(true);

        verticalLayout_4->addWidget(text_res_stats);


        horizontalLayout_3->addWidget(group_res_statsox);


        verticalLayout_5->addLayout(horizontalLayout_3);

        btn_back_stats = new QPushButton(page_stats);
        btn_back_stats->setObjectName("btn_back_stats");

        verticalLayout_5->addWidget(btn_back_stats);

        mainStackedWidget->addWidget(page_stats);
        page_typeA = new QWidget();
        page_typeA->setObjectName("page_typeA");
        verticalLayout_9 = new QVBoxLayout(page_typeA);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName("verticalLayout_9");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        leftPanel_A = new QGroupBox(page_typeA);
        leftPanel_A->setObjectName("leftPanel_A");
        leftPanel_A->setMaximumSize(QSize(300, 16777215));
        verticalLayout_10 = new QVBoxLayout(leftPanel_A);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName("verticalLayout_10");
        table_A = new QTableWidget(leftPanel_A);
        if (table_A->columnCount() < 1)
            table_A->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_A->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        table_A->setObjectName("table_A");

        verticalLayout_10->addWidget(table_A);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        btn_add_A = new QPushButton(leftPanel_A);
        btn_add_A->setObjectName("btn_add_A");

        horizontalLayout_5->addWidget(btn_add_A);

        btn_del_A = new QPushButton(leftPanel_A);
        btn_del_A->setObjectName("btn_del_A");

        horizontalLayout_5->addWidget(btn_del_A);


        verticalLayout_10->addLayout(horizontalLayout_5);

        label = new QLabel(leftPanel_A);
        label->setObjectName("label");

        verticalLayout_10->addWidget(label);

        edit_t_A = new QLineEdit(leftPanel_A);
        edit_t_A->setObjectName("edit_t_A");

        verticalLayout_10->addWidget(edit_t_A);

        btn_calc_A = new QPushButton(leftPanel_A);
        btn_calc_A->setObjectName("btn_calc_A");

        verticalLayout_10->addWidget(btn_calc_A);


        horizontalLayout_2->addWidget(leftPanel_A);

        rightPanel_A = new QGroupBox(page_typeA);
        rightPanel_A->setObjectName("rightPanel_A");
        verticalLayout_7 = new QVBoxLayout(rightPanel_A);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName("verticalLayout_7");
        text_res_A = new QTextEdit(rightPanel_A);
        text_res_A->setObjectName("text_res_A");
        text_res_A->setReadOnly(true);

        verticalLayout_7->addWidget(text_res_A);


        horizontalLayout_2->addWidget(rightPanel_A);


        verticalLayout_9->addLayout(horizontalLayout_2);

        btn_back_A = new QPushButton(page_typeA);
        btn_back_A->setObjectName("btn_back_A");

        verticalLayout_9->addWidget(btn_back_A);

        mainStackedWidget->addWidget(page_typeA);
        page_typeB = new QWidget();
        page_typeB->setObjectName("page_typeB");
        horizontalLayout_6 = new QHBoxLayout(page_typeB);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName("verticalLayout_8");
        group_B_res = new QGroupBox(page_typeB);
        group_B_res->setObjectName("group_B_res");
        verticalLayout_13 = new QVBoxLayout(group_B_res);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName("verticalLayout_13");
        text_res_B = new QTextEdit(group_B_res);
        text_res_B->setObjectName("text_res_B");
        text_res_B->setReadOnly(true);

        verticalLayout_13->addWidget(text_res_B);

        group_B_input = new QGroupBox(group_B_res);
        group_B_input->setObjectName("group_B_input");
        group_B_input->setMaximumSize(QSize(600, 16777215));
        verticalLayout_12 = new QVBoxLayout(group_B_input);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName("verticalLayout_12");
        label_2 = new QLabel(group_B_input);
        label_2->setObjectName("label_2");

        verticalLayout_12->addWidget(label_2);

        edit_delta_B = new QLineEdit(group_B_input);
        edit_delta_B->setObjectName("edit_delta_B");

        verticalLayout_12->addWidget(edit_delta_B);

        label_3 = new QLabel(group_B_input);
        label_3->setObjectName("label_3");

        verticalLayout_12->addWidget(label_3);

        edit_k_B = new QLineEdit(group_B_input);
        edit_k_B->setObjectName("edit_k_B");

        verticalLayout_12->addWidget(edit_k_B);

        btn_calc_B = new QPushButton(group_B_input);
        btn_calc_B->setObjectName("btn_calc_B");

        verticalLayout_12->addWidget(btn_calc_B);


        verticalLayout_13->addWidget(group_B_input);

        btn_back_B = new QPushButton(group_B_res);
        btn_back_B->setObjectName("btn_back_B");

        verticalLayout_13->addWidget(btn_back_B);


        verticalLayout_8->addWidget(group_B_res);


        horizontalLayout_6->addLayout(verticalLayout_8);

        mainStackedWidget->addWidget(page_typeB);
        page_indirect = new QWidget();
        page_indirect->setObjectName("page_indirect");
        verticalLayout_14 = new QVBoxLayout(page_indirect);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName("verticalLayout_14");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        leftPanel_ind = new QGroupBox(page_indirect);
        leftPanel_ind->setObjectName("leftPanel_ind");
        leftPanel_ind->setMaximumSize(QSize(350, 16777215));
        verticalLayout_15 = new QVBoxLayout(leftPanel_ind);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName("verticalLayout_15");
        label_4 = new QLabel(leftPanel_ind);
        label_4->setObjectName("label_4");

        verticalLayout_15->addWidget(label_4);

        edit_formula_ind = new QLineEdit(leftPanel_ind);
        edit_formula_ind->setObjectName("edit_formula_ind");

        verticalLayout_15->addWidget(edit_formula_ind);

        label_help = new QLabel(leftPanel_ind);
        label_help->setObjectName("label_help");
        QFont font;
        font.setItalic(true);
        label_help->setFont(font);

        verticalLayout_15->addWidget(label_help);

        label_help_2 = new QLabel(leftPanel_ind);
        label_help_2->setObjectName("label_help_2");
        label_help_2->setFont(font);

        verticalLayout_15->addWidget(label_help_2);

        table_ind = new QTableWidget(leftPanel_ind);
        if (table_ind->columnCount() < 3)
            table_ind->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_ind->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_ind->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_ind->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        table_ind->setObjectName("table_ind");

        verticalLayout_15->addWidget(table_ind);

        btn_add_ind = new QPushButton(leftPanel_ind);
        btn_add_ind->setObjectName("btn_add_ind");

        verticalLayout_15->addWidget(btn_add_ind);

        btn_del_ind = new QPushButton(leftPanel_ind);
        btn_del_ind->setObjectName("btn_del_ind");

        verticalLayout_15->addWidget(btn_del_ind);

        btn_calc_ind = new QPushButton(leftPanel_ind);
        btn_calc_ind->setObjectName("btn_calc_ind");

        verticalLayout_15->addWidget(btn_calc_ind);


        horizontalLayout_4->addWidget(leftPanel_ind);

        rightPanel_ind = new QGroupBox(page_indirect);
        rightPanel_ind->setObjectName("rightPanel_ind");
        verticalLayout_16 = new QVBoxLayout(rightPanel_ind);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName("verticalLayout_16");
        text_res_ind = new QTextEdit(rightPanel_ind);
        text_res_ind->setObjectName("text_res_ind");

        verticalLayout_16->addWidget(text_res_ind);


        horizontalLayout_4->addWidget(rightPanel_ind);


        verticalLayout_14->addLayout(horizontalLayout_4);

        btn_back_ind = new QPushButton(page_indirect);
        btn_back_ind->setObjectName("btn_back_ind");

        verticalLayout_14->addWidget(btn_back_ind);

        mainStackedWidget->addWidget(page_indirect);
        page_fitting = new QWidget();
        page_fitting->setObjectName("page_fitting");
        verticalLayout_17 = new QVBoxLayout(page_fitting);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName("verticalLayout_17");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        leftPanel_fit = new QGroupBox(page_fitting);
        leftPanel_fit->setObjectName("leftPanel_fit");
        leftPanel_fit->setMaximumSize(QSize(300, 16777215));
        verticalLayout_18 = new QVBoxLayout(leftPanel_fit);
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setContentsMargins(11, 11, 11, 11);
        verticalLayout_18->setObjectName("verticalLayout_18");
        table_fit = new QTableWidget(leftPanel_fit);
        if (table_fit->columnCount() < 2)
            table_fit->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_fit->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_fit->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        table_fit->setObjectName("table_fit");

        verticalLayout_18->addWidget(table_fit);

        btn_add_fit = new QPushButton(leftPanel_fit);
        btn_add_fit->setObjectName("btn_add_fit");

        verticalLayout_18->addWidget(btn_add_fit);

        btn_del_fit = new QPushButton(leftPanel_fit);
        btn_del_fit->setObjectName("btn_del_fit");

        verticalLayout_18->addWidget(btn_del_fit);

        label_5 = new QLabel(leftPanel_fit);
        label_5->setObjectName("label_5");

        verticalLayout_18->addWidget(label_5);

        combo_fit_type = new QComboBox(leftPanel_fit);
        combo_fit_type->addItem(QString());
        combo_fit_type->addItem(QString());
        combo_fit_type->addItem(QString());
        combo_fit_type->addItem(QString());
        combo_fit_type->addItem(QString());
        combo_fit_type->addItem(QString());
        combo_fit_type->addItem(QString());
        combo_fit_type->addItem(QString());
        combo_fit_type->setObjectName("combo_fit_type");

        verticalLayout_18->addWidget(combo_fit_type);

        btn_run_fit = new QPushButton(leftPanel_fit);
        btn_run_fit->setObjectName("btn_run_fit");

        verticalLayout_18->addWidget(btn_run_fit);


        horizontalLayout_8->addWidget(leftPanel_fit);

        rightPanel_fit = new QGroupBox(page_fitting);
        rightPanel_fit->setObjectName("rightPanel_fit");
        verticalLayout_11 = new QVBoxLayout(rightPanel_fit);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName("verticalLayout_11");
        plotWidget_fit = new QCustomPlot(rightPanel_fit);
        plotWidget_fit->setObjectName("plotWidget_fit");
        horizontalLayout_10 = new QHBoxLayout(plotWidget_fit);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName("horizontalLayout_10");

        verticalLayout_11->addWidget(plotWidget_fit);

        text_res_fit = new QTextEdit(rightPanel_fit);
        text_res_fit->setObjectName("text_res_fit");
        text_res_fit->setMaximumSize(QSize(16777215, 250));

        verticalLayout_11->addWidget(text_res_fit);


        horizontalLayout_8->addWidget(rightPanel_fit);


        verticalLayout_17->addLayout(horizontalLayout_8);

        btn_back_fit = new QPushButton(page_fitting);
        btn_back_fit->setObjectName("btn_back_fit");

        verticalLayout_17->addWidget(btn_back_fit);

        mainStackedWidget->addWidget(page_fitting);

        horizontalLayout_7->addWidget(mainStackedWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1074, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_go_fit->setText(QCoreApplication::translate("MainWindow", "\346\233\262\347\272\277\346\213\237\345\220\210\344\270\216\347\273\230\345\233\276", nullptr));
        btn_go_mean->setText(QCoreApplication::translate("MainWindow", "\345\271\263\345\235\207\345\200\274\350\256\241\347\256\227", nullptr));
        btn_go_stats->setText(QCoreApplication::translate("MainWindow", "\347\273\237\350\256\241\345\255\246 (\346\226\271\345\267\256/\346\240\207\345\207\206\345\267\256)", nullptr));
        btn_go_ind->setText(QCoreApplication::translate("MainWindow", "\351\227\264\346\216\245\350\256\241\347\256\227\344\270\215\347\241\256\345\256\232\345\272\246", nullptr));
        btn_go_B->setText(QCoreApplication::translate("MainWindow", "B\347\261\273\344\270\215\347\241\256\345\256\232\345\272\246", nullptr));
        btn_go_A->setText(QCoreApplication::translate("MainWindow", "A\347\261\273\344\270\215\347\241\256\345\256\232\345\272\246", nullptr));
        group_input_mean->setTitle(QCoreApplication::translate("MainWindow", "\346\265\213\351\207\217\346\225\260\346\215\256\345\275\225\345\205\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table_mean->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\346\265\213\351\207\217\345\200\274", nullptr));
        btn_add_mean->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\225\260\346\215\256\350\241\214", nullptr));
        btn_del_mean->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\351\200\211\344\270\255\350\241\214", nullptr));
        btn_calc_mean->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220\350\256\241\347\256\227\350\277\207\347\250\213", nullptr));
        group_process_mean->setTitle(QCoreApplication::translate("MainWindow", "\350\257\246\347\273\206\350\256\241\347\256\227\350\277\207\347\250\213", nullptr));
        btn_back_mean->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
        group_input_stats->setTitle(QCoreApplication::translate("MainWindow", "\347\273\237\350\256\241\346\225\260\346\215\256\345\275\225\345\205\245", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_stats->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\350\247\202\346\265\213\345\200\274", nullptr));
        btn_add_stats->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\225\260\346\215\256", nullptr));
        btn_del_stats->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\346\225\260\346\215\256", nullptr));
        btn_calc_stats->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227\346\226\271\345\267\256\344\270\216\346\240\207\345\207\206\345\267\256", nullptr));
        group_res_statsox->setTitle(QCoreApplication::translate("MainWindow", "\347\273\237\350\256\241\345\210\206\346\236\220\346\212\245\345\221\212", nullptr));
        btn_back_stats->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
        leftPanel_A->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\275\225\345\205\245\344\270\216\344\277\256\346\255\243\345\233\240\345\255\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_A->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\346\265\213\351\207\217\345\200\274", nullptr));
        btn_add_A->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\241\214", nullptr));
        btn_del_A->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\241\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\255\243\345\233\240\345\255\220 (t):", nullptr));
        edit_t_A->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btn_calc_A->setText(QCoreApplication::translate("MainWindow", "\346\211\247\350\241\214 A\347\261\273\344\270\215\347\241\256\345\256\232\345\272\246\350\256\241\347\256\227", nullptr));
        rightPanel_A->setTitle(QCoreApplication::translate("MainWindow", "A\347\261\273\344\270\215\347\241\256\345\256\232\345\272\246\350\256\241\347\256\227\346\212\245\345\221\212", nullptr));
        btn_back_A->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
        group_B_res->setTitle(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227\347\273\223\346\236\234", nullptr));
        group_B_input->setTitle(QCoreApplication::translate("MainWindow", "\344\273\252\345\231\250\345\217\202\346\225\260\345\275\225\345\205\245", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\344\273\252\345\231\250\350\257\257\345\267\256 (\316\224):", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\214\205\345\220\253\345\233\240\345\255\220 (k):", nullptr));
        edit_k_B->setText(QCoreApplication::translate("MainWindow", "1.732", nullptr));
        btn_calc_B->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227 B\347\261\273\344\270\215\347\241\256\345\256\232\345\272\246", nullptr));
        btn_back_B->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
        leftPanel_ind->setTitle(QCoreApplication::translate("MainWindow", "\345\205\254\345\274\217\344\270\216\345\210\206\351\207\217\350\276\223\345\205\245", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\205\254\345\274\217\350\276\223\345\205\245\357\274\232", nullptr));
        label_help->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\263\225\357\274\232\344\271\230\346\263\225\345\277\205\345\241\253* (a*b)\357\274\233\346\254\241\346\226\271\347\224\250^ (x^2)\357\274\233", nullptr));
        label_help_2->setText(QCoreApplication::translate("MainWindow", "\346\240\271\345\217\267\347\224\250sqrt(x)\357\274\233\344\273\273\346\204\217\346\254\241\346\226\271\346\240\271\347\224\250x^(1/n)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_ind->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\345\217\230\351\207\217\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_ind->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\345\271\263\345\235\207\345\200\274 (xi)\n"
"", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table_ind->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\344\270\215\347\241\256\345\256\232\345\272\246 (ui)\n"
"", nullptr));
        btn_add_ind->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\241\214", nullptr));
        btn_del_ind->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\241\214", nullptr));
        btn_calc_ind->setText(QCoreApplication::translate("MainWindow", "\346\211\247\350\241\214\350\207\252\345\212\250\345\220\210\346\210\220\350\256\241\347\256\227", nullptr));
        rightPanel_ind->setTitle(QCoreApplication::translate("MainWindow", "\345\220\210\346\210\220\345\210\206\346\236\220\346\212\245\345\221\212", nullptr));
        btn_back_ind->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
        leftPanel_fit->setTitle(QCoreApplication::translate("MainWindow", "\351\205\215\347\275\256\346\213\237\345\220\210\346\225\260\346\215\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table_fit->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "x\346\225\260\346\215\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = table_fit->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "y\346\225\260\346\215\256", nullptr));
        btn_add_fit->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\225\260\346\215\256", nullptr));
        btn_del_fit->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\346\225\260\346\215\256", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\213\237\345\220\210\346\250\241\345\236\213", nullptr));
        combo_fit_type->setItemText(0, QCoreApplication::translate("MainWindow", "\347\272\277\346\200\247\346\213\237\345\220\210 (y = ax + b)", nullptr));
        combo_fit_type->setItemText(1, QCoreApplication::translate("MainWindow", "\344\272\214\346\254\241\345\244\232\351\241\271\345\274\217 (y = ax\302\262 + bx + c)\n"
"", nullptr));
        combo_fit_type->setItemText(2, QCoreApplication::translate("MainWindow", "\344\270\211\346\254\241\345\244\232\351\241\271\345\274\217 (y = ax\302\263 + bx\302\262 + cx + d)\n"
"", nullptr));
        combo_fit_type->setItemText(3, QCoreApplication::translate("MainWindow", "\345\233\233\346\254\241\345\244\232\351\241\271\345\274\217 (y = ax\342\201\264 + ...)", nullptr));
        combo_fit_type->setItemText(4, QCoreApplication::translate("MainWindow", "\344\272\224\346\254\241\345\244\232\351\241\271\345\274\217 (y = ax\342\201\265 + ...)", nullptr));
        combo_fit_type->setItemText(5, QCoreApplication::translate("MainWindow", "\346\214\207\346\225\260\345\207\275\346\225\260 (y = a * e^(bx))", nullptr));
        combo_fit_type->setItemText(6, QCoreApplication::translate("MainWindow", "\345\257\271\346\225\260\345\207\275\346\225\260 (y = a * ln(x) + b)", nullptr));
        combo_fit_type->setItemText(7, QCoreApplication::translate("MainWindow", "\345\271\202\345\207\275\346\225\260 (y = a * x^b)\n"
"", nullptr));

        btn_run_fit->setText(QCoreApplication::translate("MainWindow", "\346\211\247\350\241\214\346\213\237\345\220\210\344\270\216\347\273\230\345\233\276", nullptr));
        rightPanel_fit->setTitle(QCoreApplication::translate("MainWindow", "\346\233\262\347\272\277\345\233\276\345\275\242\344\270\216\346\225\260\345\255\246\346\250\241\345\236\213", nullptr));
        btn_back_fit->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
