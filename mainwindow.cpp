#include "mainwindow.h"
#include "ui_mainwindow.h"

QString usersTable = "users";
QString ticketsTable = "tickets";

void MainWindow::Add_widget_to_layout(QWidget *object)
{
    ui->verticalLayout->addWidget(object);
}

void MainWindow::createConnection()
{
    database.reset(new Database("tickets_system", "127.0.0.1", "root", "1234", this));
}

bool MainWindow::insertData(QString table_name, std::vector<QString> data)
{
    return database->insertData(table_name, data);
}

bool MainWindow::showAllTables()
{
    return database->showAllTables();
}

int MainWindow::getUserIdByEmail(QString email)
{
    return database->getUserIdByEmail(email);
}

int MainWindow::getTicketIdByInfo(QString info)
{
    return database->getTicketIdByInfo(info);
}

bool MainWindow::showTableDataById(QString table_name, int id)
{
    return database->showTableDataById(table_name, id);
}

bool MainWindow::showOrderedTicketsByUserId(int id)
{
    return database->showOrderedTicketsByUserId(id);
}

bool MainWindow::showBookedTicketsByUserId(int id)
{
    return database->showBookedTicketsByUserId(id);;
}

bool MainWindow::addNewTicket(QString ticketInfo)
{
    std::vector<QString> ticketsData;
    ticketsData.push_back("NULL");
    ticketsData.push_back( "'" + ticketInfo + "'");
    ticketsData.push_back("NULL");
    ticketsData.push_back("NULL");
    return database->insertData(ticketsTable, ticketsData);
}

bool MainWindow::removeTicket(QString ticketInfo)
{
    return database->Remove_raw(ticketsTable, "ticket_info", ticketInfo);
}

bool MainWindow::addNewUser(QString email)
{
    std::vector<QString> usersData;
    usersData.push_back("NULL");
    usersData.push_back( "'" + email + "'");
    return database->insertData(usersTable, usersData);
}

bool MainWindow::removeUser(QString email)
{
    return database->Remove_raw(usersTable, "user_email", email);
}

bool MainWindow::setBooked(int tiketId, int userId)
{
    return database->setBooked(tiketId, userId);
}

bool MainWindow::setOrdered(int tiketId, int userId)
{
    return database->setOrdered(tiketId, userId);
}

bool MainWindow::Remove_raw(QString table_name, QString column, QString data)
{
    return database->Remove_raw(table_name, column, data);
}

bool MainWindow::Close_database()
{
    return database->Close_database();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

