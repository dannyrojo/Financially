//Include libraries needed for Qt
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QTimer>
#include <QPushButton>

// Variables for financial data
double Salary;
double Contributions;
double Taxes;
double NetPay;

// Operations for financial calculations

void calculateNetPay (){
    NetPay = (Salary - Contributions - Taxes);
}

// Slot functions for handling input

void handleSalaryInput (const QString &input)
{
    bool ok; //conditional bool created
    int number = input.toDouble(&ok); //temporary number created for string conversion
    if (ok) {Salary = number;} //assign number to variable
}

void handleContributionsInput (const QString &input)
{
    bool ok; 
    int number = input.toDouble(&ok);
    if (ok) {Contributions = number;}
}

void handleTaxesInput (const QString &input)
{
    bool ok; 
    int number = input.toDouble(&ok);
    if (ok) {Taxes = number;}
}

void handleCalculateNetPay(QLabel *label)  // Added a placeholder for an argument passed through a Qt slot
{
    calculateNetPay();
    std::cout <<"Net Pay:" << NetPay << std::endl;
    label->setText(QString::number(NetPay));  //Placeholder updates with the result of the calculation
}

// main loop

int main(int argc, char *argv[])
{

    // Create Qt Application Window

    QApplication app(argc, argv);

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Financially");

    // Parent widget for memory management
    QWidget *paycheckView = new QWidget(&mainWindow); //assigns mainwindow as parent

    // Create Qt labels and line edits

    QLabel *labelSalary = new QLabel("Enter your Salary:", paycheckView);  //first child to paycheckView, continue below
    QLineEdit *lineSalary = new QLineEdit(paycheckView);

    QLabel *labelContributions = new QLabel("Contributions:", paycheckView);
    QLineEdit *lineContributions = new QLineEdit(paycheckView);

    QLabel *labelTaxes = new QLabel("Taxes you paid:", paycheckView);
    QLineEdit *lineTaxes = new QLineEdit(paycheckView);

    QLabel *labelNetPay = new QLabel("Your NetPay:", paycheckView);
    QLabel *labelResultNetPay = new QLabel(paycheckView);

    // Create Qt buttons

    QPushButton *buttonCalculateNetPay = new QPushButton("Calculate Net Pay", paycheckView);

    //  Window layout specifications

    QVBoxLayout *layout = new QVBoxLayout(paycheckView);
    layout->addWidget(labelSalary);
    layout->addWidget(lineSalary);
    layout->addWidget(labelContributions);
    layout->addWidget(lineContributions);
    layout->addWidget(labelTaxes);
    layout->addWidget(lineTaxes);
    layout->addWidget(labelNetPay);
    layout->addWidget(labelResultNetPay);
    layout->addWidget(buttonCalculateNetPay);

   // Centralize layout and show

    QWidget *centralWidget = new QWidget(paycheckView);
    centralWidget->setLayout(layout);

    mainWindow.setCentralWidget(centralWidget);
    mainWindow.show();

    // Connect signals to slot functions

    QObject::connect(lineSalary, &QLineEdit::textChanged, handleSalaryInput);
    QObject::connect(lineContributions, &QLineEdit::textChanged, handleContributionsInput);
    QObject::connect(lineTaxes, &QLineEdit::textChanged, handleTaxesInput);

    QObject::connect(
        buttonCalculateNetPay, &QPushButton::clicked, [&]()
        {handleCalculateNetPay(labelResultNetPay);} // Pass the required label through my handler function
    );

    // Debug

    QTimer debugtimer;
    debugtimer.setInterval(5000);

    QObject::connect(&debugtimer, &QTimer::timeout, [&](){
        std::cout << "double Salary = " << Salary << std::endl;
        std::cout << "double Contributions = " << Contributions << std::endl;
        std::cout << "double Taxes = " << Taxes << std::endl;
        std::cout << "double NetPay = " << NetPay << std::endl;
    });
    debugtimer.start();

    // Release memory

    delete paycheckView;

    // Execute 
    
    return app.exec();

    
 
}