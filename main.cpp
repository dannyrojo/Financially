//Include libraries needed for Qt
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QTimer>

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

// main loop

int main(int argc, char *argv[])
{

    // Create Qt Application Window

    QApplication app(argc, argv);

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Financially");

    // Create Qt labels and line edits

    QLabel *labelSalary = new QLabel("Enter your Salory:");
    QLineEdit *lineSalary = new QLineEdit;

    QLabel *labelContributions = new QLabel("Contributions:");
    QLineEdit *lineContributions = new QLineEdit;

    QLabel *labelTaxes = new QLabel("Taxes you paid:");
    QLineEdit *lineTaxes = new QLineEdit;

    QLabel *labelNetPay = new QLabel("Your NetPay:");
    QLabel *labelResultNetPay;

    //  Window layout specifications

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(labelSalary);
    layout->addWidget(lineSalary);
    layout->addWidget(labelContributions);
    layout->addWidget(lineContributions);
    layout->addWidget(labelTaxes);
    layout->addWidget(lineTaxes);
    layout->addWidget(labelNetPay);
    layout->addWidget(labelResultNetPay);
   
   // Centralize layout and show

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);

    mainWindow.setCentralWidget(centralWidget);
    mainWindow.show();

    // Connect signals to slot functions

    QObject::connect(lineSalary, &QLineEdit::textChanged, handleSalaryInput);
    QObject::connect(lineContributions, &QLineEdit::textChanged, handleContributionsInput);
    QObject::connect(lineTaxes, &QLineEdit::textChanged, handleTaxesInput);

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

  // Execute 
    
    return app.exec();

    
 
}