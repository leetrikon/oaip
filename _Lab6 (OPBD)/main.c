#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>

const char *sql = "CREATE TABLE IF NOT EXISTS Customer (" //запросы
            "Id integer PRIMARY KEY,"
            "FullName text NOT NULL,"
            "PhoneNumber text,"
            "IsRegularCustomer int,"
            "Gender text,"
            "Discount integer);"
            "CREATE TABLE IF NOT EXISTS Manager ("
            "Id integer PRIMARY KEY,"
            "FullName text NOT NULL,"
            "PhoneNumber text,"
            "Salary real);"
            "CREATE TABLE IF NOT EXISTS Branch ("
            "Id integer PRIMARY KEY,"
            "City text NOT NULL,"
            "PhoneNumber text,"
            "Address text,"
            "ManagerID integer,"
            "FOREIGN KEY (ManagerID) REFERENCES Manager (Id));"
            "CREATE TABLE IF NOT EXISTS Barber ("
            "Id integer PRIMARY KEY,"
            "FullName text NOT NULL,"
            "PhoneNumber text,"
            "BranchID integer,"
            "Salary real);"
            "CREATE TABLE IF NOT EXISTS Haircut ("
            "Id integer PRIMARY KEY,"
            "Name text NOT NULL,"
            "Gender integer,"
            "Price real,"
            "BarberID integer,"
            "FOREIGN KEY (BarberID) REFERENCES Barber (Id));"
            "CREATE TABLE IF NOT EXISTS TypeOfBill ("
            "Id integer PRIMARY KEY,"
            "BillType integer NOT NULL);"
            "CREATE TABLE IF NOT EXISTS Bill ("
            "Id integer PRIMARY KEY,"
            "Discount integer,"
            "Description TEXT,"
            "TimeDate TEXT,"
            "ManagerID  integer,"
            "Total REAL,"
            "TypeOfBillID integer,"
            "FOREIGN KEY (TypeOfBillID) REFERENCES TypeOfBill (Id));"
            "CREATE TABLE IF NOT EXISTS Bank ("
            "Id integer PRIMARY KEY,"
            "Name TEXT,"
            "BillID integer,"
            "FOREIGN KEY (BillID) REFERENCES Bill (Id));"
            "CREATE TABLE IF NOT EXISTS ServiceBill ("
            "Id integer PRIMARY KEY,"
            "Name TEXT,"
            "BillID integer,"
            "FOREIGN KEY (BillID) REFERENCES Bill (Id));"
            "CREATE TABLE IF NOT EXISTS Service ("
            "Id integer PRIMARY KEY,"
            "ManagerID integer,"
            "CustomerID integer,"
            "HaircutID integer,"
            "ServiceBillID integer,"
            "TimeRecieved TEXT,"
            "TimeCompleted TEXT,"
            "FOREIGN KEY (ManagerId) REFERENCES Manager (Id),"
            "FOREIGN KEY (CustomerID) REFERENCES Customer (Id),"
            "FOREIGN KEY (HaircutID) REFERENCES Haircut (Id),"
            "FOREIGN KEY (ServiceBillID) REFERENCES ServiceBill (Id));";

const char *sql_data = "INSERT INTO Manager (Id, FullName, PhoneNumber, Salary)"
           "VALUES (1, 'Ванин Никита Александрович', '88005553535', '7747');"
           "INSERT INTO Branch (Id, City, PhoneNumber, Address, ManagerID)"
           "VALUES (1, 'Томск', '88003335555', 'Герцена 18', 1);"
           "INSERT INTO Customer (Id, FullName, PhoneNumber, IsRegularCustomer, Gender, Discount)"
           "VALUES (1, 'Никитин Иван Александрович', '89998880099', 1, 'Мужчина', 15);"
           "INSERT INTO Barber (Id, FullName, PhoneNumber, BranchID , Salary)"
           "VALUES (1, 'Никитенко Александр Иванович', '88003535353', 1, '7747');"
           "INSERT INTO Haircut (Id, Name, Gender, Price, BarberID)"
           "VALUES (1, 'Андеркат', 1, 150, 1);"
           "INSERT INTO TypeOfBill (BillType)"
           "VALUES (1);"
           "INSERT INTO Bill (Id, Discount, Description, TimeDate, ManagerID, Total, TypeOfBillID)"
           "VALUES (1, 15, 'Описание', '11 ноября 2020', 1, 127, 1);"
           "INSERT INTO Bank (Id, Name, BillID)"
           "VALUES (1, 'Тинькофф', 1);"
           "INSERT INTO ServiceBill (Id, Name, BillID)"
           "VALUES (1, 'Андеркат-11.11.2020', 1);"
           "INSERT INTO Service (Id, ManagerID, CustomerID, HaircutID, ServiceBillID, TimeRecieved, TimeCompleted)"
           "VALUES (1, 1, 1, 1, 1, '11.11.2020 11:59', '11.11.2020 12:20');";

int callback(void *, int, char **, char **);

int main() {
    system("chcp 65001 && cls");

    sqlite3 *db = 0;
    char *err = 0;
    char *sql_table = "0";

    int rc = sqlite3_open("BarberShop.db", &db);
    if (rc != SQLITE_OK) {
        printf("Ошибка SQL: %s\n", err);
    }
    rc = sqlite3_exec(db, sql, 0, 0, &err); //выполняем основные запросы
    if (rc != SQLITE_OK) {
        printf("Ошибка SQL: %s\n", err);
    }

    rc = sqlite3_exec(db, sql_data, 0, 0, &err); //заполняем данными
    if (rc != SQLITE_OK) {
        printf("Ошибка SQL: %s\n", err);
    }

    printf("База данных BarberShop создана успешно.\n");
    printf("Созданные таблицы:\n");
    printf("1.Bank\n2.Bill\n3.Customer\n4.Manager\n5.ServiceBill\n6.Barber\n7.Branch\n8.Haircut\n");
    printf("9.Service\n10.TypeOfBill\n");

    while (1){
        printf("\n\n________________________________\n");
        printf("Вы можете ввести название таблицы, чтобы узнать, какие данные в ней хранятся\n");
        printf("Вы можете ввести 0 для выхода, 11 для повторного вывода таблиц.\n");
        printf("Ваш выбор:");
        int table = 0;
        scanf("%i", &table);
        printf("\n\n");
        switch (table) {
            case 0:
                rc = sqlite3_close(db); // закрываем соединение
                return 0;
            case 1:
                printf("Bank:\n");
                sql_table = "SELECT * FROM Bank;";
                rc = sqlite3_exec(db, sql_table, callback, 0, &err);
                break;
            case 2:
                printf("Bill:\n");
                sql_table = "SELECT * FROM Bill;";
                rc = sqlite3_exec(db, sql_table, callback, 0, &err);
                break;
            case 3:
                printf("Customer:\n");
                sql_table = "SELECT * FROM Customer;";
                rc = sqlite3_exec(db, sql_table, callback, 0, &err);
                break;
            case 4:
                printf("Manager:\n");
                sql_table = "SELECT * FROM Manager;";
                rc = sqlite3_exec(db, sql_table, callback, 0, &err);
                break;
            case 5:
                printf("ServiceBill:\n");
                sql_table = "SELECT * FROM ServiceBill;";
                rc = sqlite3_exec(db, sql_table, callback, 0, &err);
                break;
            case 6:
                printf("Barber:\n");
                sql_table = "SELECT * FROM Barber;";
                rc = sqlite3_exec(db, sql_table, callback, 0, &err);
                break;
            case 7:
                printf("Branch:\n");
                sql_table = "SELECT * FROM Branch;";
                rc = sqlite3_exec(db, sql_table, callback, 0, &err);
                break;
            case 8:
                printf("Haircut:\n");
                sql_table = "SELECT * FROM Haircut;";
                rc = sqlite3_exec(db, sql_table, callback, 0, &err);
                break;
            case 9:
                printf("Service:\n");
                sql_table = "SELECT * FROM Service;";
                rc = sqlite3_exec(db, sql_table, callback, 0, &err);
                break;
            case 10:
                printf("TypeOfBill:\n");
                sql_table = "SELECT * FROM TypeOfBill;";
                rc = sqlite3_exec(db, sql_table, callback, 0, &err);
                break;
            case 11:
                printf("\n\nСозданные таблицы:\n");
                printf("1. Bank\n2.Bill\n3.Customer\n4.Manager\n5.ServiceBill\n6.Barber\n7.Branch\n8.Haircut\n");
                printf("9.Service\n10.TypeOfBill\n");
                break;
            default:
                printf("\n");
                break;
        }
    }
}

int callback(void *NotUsed, int argc, char **argv, char **ColName) {
    NotUsed = 0;
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", ColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}