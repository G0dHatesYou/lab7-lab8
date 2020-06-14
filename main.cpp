#include <QDebug>
#include <QApplication>

#include <memory>
#include <vector>

#include "mainwindow.h"

#include "gtest/gtest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString usersTable = "users";
    QString ticketsTable = "tickets";

    w.createConnection();

    w.showAllTables();

    //w.showTableDataById(usersTable);

    //w.showBookedTicketsByUserId(4);


//    w.addNewTicket("new ticket");
//    w.setOrdered(w.getTicketIdByInfo("new ticket"), w.getUserIdByEmail("max@mail.ru"));
//    w.showTableDataById(ticketsTable);


//     w.addNewUser("new user");
//     w.showTableDataById(usersTable);


    //w.showTableDataById(table_position);


    ::testing::InitGoogleTest (&argc, argv);
    int returnCode = RUN_ALL_TESTS();

    return a.exec();
}


TEST (Business_Logic, addNewTicketTest)
{
    MainWindow w;
    w.createConnection();

    EXPECT_TRUE(w.addNewTicket("new ticket"));

    w.Close_database();
    w.close();
}

TEST (Business_Logic, removeTicketTest)
{
    MainWindow w;
    w.createConnection();

    EXPECT_TRUE(w.removeTicket("new ticket"));

    w.Close_database();
    w.close();
}

TEST (Business_Logic, addNewUserTest)
{
    MainWindow w;
    w.createConnection();

    EXPECT_TRUE(w.addNewUser("new user"));

    w.Close_database();
    w.close();
}

TEST (Business_Logic, removeUserTest)
{
    MainWindow w;
    w.createConnection();

    EXPECT_TRUE(w.removeUser("new user"));

    w.Close_database();
    w.close();
}

TEST (Repository_logic, Show_tables)
{
    MainWindow w;
    w.createConnection();

    EXPECT_TRUE(w.showAllTables());

    w.Close_database();
    w.close();
}


TEST (Repository_logic, showTableDataById)
{
    MainWindow w;
    w.createConnection();

    EXPECT_TRUE(w.showTableDataById("users"));
    EXPECT_TRUE(w.showTableDataById("tickets"));

    w.Close_database();
    w.close();
}

TEST (Repository_logic, showOrderedTicketsByUserIdTest)
{
    MainWindow w;
    w.createConnection();

    EXPECT_TRUE(w.database->showOrderedTicketsByUserId(1));

    w.Close_database();
    w.close();
}


TEST (Repository_logic, showBookedTicketsByUserIdTest)
{
    MainWindow w;
    w.createConnection();

    EXPECT_TRUE(w.database->showBookedTicketsByUserId(1));

    w.Close_database();
    w.close();
}

TEST (Repository_logic, getTicketIdByInfoTest)
{
    MainWindow w;
    w.createConnection();

    EXPECT_EQ(w.database->getTicketIdByInfo("Kyiv - Minsk"), 1);
    EXPECT_EQ(w.database->getTicketIdByInfo("Kyiv - Lisbon"), 5);

    w.Close_database();
    w.close();
}

TEST (Repository_logic, getUserIdByEmailTest)
{
    MainWindow w;
    w.createConnection();

    EXPECT_EQ(w.database->getUserIdByEmail("max@mail.ru"), 1);
    EXPECT_EQ(w.database->getUserIdByEmail("errik@loli.com"), 4);

    w.Close_database();
    w.close();
}
