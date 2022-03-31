#ifndef _BITSTDC_
#define _BITSTDC_
#include<bits/stdc++.h>
#endif

#include "../sqlit3Header/sqlite3.h"

#ifndef DBCONNECTION_H
#define DBCONNECTION_H
class DbConnection
{
private:
    // pointer to hold location of Db file
    const char *DirectoryLocation;

    // pointer to hold object created by static function connect , only one object is created
    static DbConnection *ptr;

    // constructor for DbConnection
    DbConnection(const char *_DirectoryLocation) : DirectoryLocation{_DirectoryLocation}
    {
        std::cout << "creating constructor, for DbConnection" << std::endl;
        this->CreateDb();    // when object is created ,data base is created with help of CreateDb function on location DirectoryLocation
        this->CreateTable(); // when object is created ,table is created with help of CreateTable  function on location DirectoryLocation
    }
    // function to create DB
    void CreateDb()
    {
        sqlite3 *db;
        int open = 0;
        open = sqlite3_open(DirectoryLocation, &db);
        sqlite3_close(db);
    }
    // function to create table in Db
    void CreateTable()
    {
        sqlite3 *db;
        // sql query to create table having field ID NUM1 NUM2 OPERATOR	RESULT
        std::string sql = "CREATE TABLE IF NOT EXISTS CALCULATOR("
                          "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                          "NUM1 TEXT NOT NULL,"
                          "NUM2 TEXT NOT NULL,"
                          "OPERATOR TEXT NOT NULL,"
                          "RESULT TEXT NOT NULL);";

        try
        {
            int open = 0;
            char *ErrorMessage;
            open = sqlite3_open(DirectoryLocation, &db);
            open = sqlite3_exec(db, sql.c_str(), nullptr, 0, &ErrorMessage);
            if (open != SQLITE_OK)
            {
                std::cerr << "error while creating table" << std::endl;
                // cout<<ErrorMessage<<endl;
                sqlite3_free(ErrorMessage);
            }
            else
            {
                std::cerr << "Table created successfully " << std::endl;
            }
            sqlite3_close(db);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    /* argc: holds the number of results, argv: holds each value in array, azColName: holds each column returned in array, */
    static int callback(void *NotUsed, int argc, char **argv, char **azColName)
    {
        for (int i = 0; i < argc; i++)
        {
            // column name and value
            std::cout << azColName[i] << ": " << argv[i] << std::endl;
        }
        std::cout << std::endl;
        return 0;
    }

    

public:
    ~DbConnection()
    {
        std::cout << "calling destructor for DbConnection !" << std::endl;
        ptr = nullptr;
    }
    // static method to to envoke constructor to create object;
    static DbConnection *start(const char *connection)
    {
        if (ptr == nullptr)
        {
            ptr = new DbConnection(connection);
        }
        return ptr;
    }
    // Dbconnection should not be copy
    DbConnection(DbConnection &val) = delete;

    // Dbconnection should not assign
    DbConnection &operator=(DbConnection &val) = delete;

    // function to insert data in sqlite3 db
    void InsertData(std::string _num1, std::string _num2, std::string _op, std::string _result)
    {
        sqlite3 *db;
        char *ErrorMessage;
        int open = 0;
        open = sqlite3_open(DirectoryLocation, &db);
        // sql query to insert value in Calculator db
        std::string sql = "INSERT INTO CALCULATOR (NUM1, NUM2, OPERATOR, RESULT) VALUES(" + _num1 + "," + _num2 + ",'" + _op + "'," + _result + ");";
        open = sqlite3_exec(db, sql.c_str(), NULL, 0, &ErrorMessage);
        if (open != SQLITE_OK)
        {
            std::cerr << "Error while inserting data" << std::endl;
            sqlite3_free(ErrorMessage);
        }
        else
        {
            std::cerr << "Data inserted successfully " << std::endl;
        }
        sqlite3_close(db);
    }

    // function to update data base based on input parameter 
    void updateData(int _id, std::string _num1, std::string _num2)
    {
        sqlite3 *db;
        char *ErrorMessage;
        std::string id = std::to_string(_id);
        int open = sqlite3_open(DirectoryLocation, &db);
        // sql query to update database num1 and num2 field by id
        std::string sql = "UPDATE CALCULATOR SET NUM1=" + _num1 + ",NUM2=" + _num2 + " WHERE ID=" + id;
        open = sqlite3_exec(db, sql.c_str(), NULL, 0, &ErrorMessage);
        if (open != SQLITE_OK)
        {
            std::cerr << "Error while update dating data." << std::endl;
            sqlite3_free(ErrorMessage);
        }
        else
            std::cout << "Records updated Successfully!" << std::endl;
        sqlite3_close(db);
    }
    // function to update data base based on input parameter
    void updateData( int _id ,std::string _num1, std::string _num2,std::string _result)
    {
        sqlite3 *db;
        char *ErrorMessage;
        std::string id = std::to_string(_id);
        int open = sqlite3_open(DirectoryLocation, &db);
        // sql query to update database num1 ,num2 and result field by id
        std::string sql = "UPDATE CALCULATOR SET NUM1=" + _num1 + ",NUM2=" + _num2 + ",RESULT="+_result+" WHERE ID=" + id;
        open = sqlite3_exec(db, sql.c_str(), NULL, 0, &ErrorMessage);
        if (open != SQLITE_OK)
        {
            std::cerr << "Error while update dating data." << std::endl;
            sqlite3_free(ErrorMessage);
        }
        else
            
            std::cout << "Records updated Successfully!" << std::endl;
        sqlite3_close(db);
    }
    // retrieve contents of database used by selectData()
    void selectData()
    {
        sqlite3 *db;
        char *ErrorMessage;
        int open = sqlite3_open(DirectoryLocation, &db);
        std::string sql = "SELECT * FROM CALCULATOR;";
        open = sqlite3_exec(db, sql.c_str(), callback, NULL, &ErrorMessage);
        if (open != SQLITE_OK)
        {
            std::cerr << "Error in selectData function." << std::endl;
            sqlite3_free(ErrorMessage);
        }
        else
        {
            std::cout << "Records selected Successfully!" << std::endl;
        }
        sqlite3_close(db);
    }

    // function to delete data in db
    void DeleteData()
    {
        sqlite3 *db;
        char *ErrorMessage;
        int open = sqlite3_open(DirectoryLocation, &db);
        std::string sql = "DELETE FROM CALCULATOR;";
        open = sqlite3_exec(db, sql.c_str(), callback, NULL, &ErrorMessage);
        if (open != SQLITE_OK)
        {
            std::cerr << "Error in deleteData function." << std::endl;
            sqlite3_free(ErrorMessage);
        }
        else
        {
            std::cout << "Records deleted Successfully!" << std::endl;
        }
        sqlite3_close(db);
    }
};

DbConnection *DbConnection::ptr = nullptr;

#endif

