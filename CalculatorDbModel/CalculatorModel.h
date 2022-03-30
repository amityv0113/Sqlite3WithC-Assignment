#include<bits/stdc++.h>
using namespace std;
#include "../sqlit3Header/sqlite3.h"

class DbConnection{
    private:
        const char* DirectoryLocation;

        // pointer to hold object created by static function connect , only one object is created 
        static DbConnection* ptr;

        DbConnection(const char* _DirectoryLocation):DirectoryLocation{_DirectoryLocation} // constructor for DbConnect 
        {
            cout<<"creating constructor, for DbConnection"<<endl;
            this->CreateDb();   //when object is created ,data base is created with help of CreateDb function on location DirectoryLocation
            this->CreateTable();//when object is created ,table is created with help of CreateTable  function on location DirectoryLocation
        }
        // function to create DB
        void CreateDb()
        {
            sqlite3 *db;
            int open = 0;
            open=sqlite3_open(DirectoryLocation,&db);
            // if(open)
            // {
            //     cout<<"database not created"<<endl;
            // }
            // else
            // {
            //     cout<<"database created "<<endl;
            // }
            sqlite3_close(db);
        }
        // function to create table in Db
        void CreateTable()
        {
            sqlite3 *db;
            string sql = "CREATE TABLE IF NOT EXISTS CALCULATOR("
            "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
            "NUM1 TEXT NOT NULL,"
            "NUM2 TEXT NOT NULL,"
            "OPERATOR TEXT NOT NULL,"
            "RESULT TEXT NOT NULL);";
            
            try{
                int open =0;
                char*ErrorMessage;
                open = sqlite3_open(DirectoryLocation,&db);
                open = sqlite3_exec(db,sql.c_str(),nullptr ,0,&ErrorMessage);
                if (open!=SQLITE_OK)
                {
                    cerr<<"error while creating table"<<endl;
                    //cout<<ErrorMessage<<endl;
                    sqlite3_free(ErrorMessage);

                }
                else
                {
                    cerr<<"Table created successfully "<<endl;
                }
                sqlite3_close(db);
                
            }
            catch(const exception &e)
            {
                cout<<e.what()<<endl;
            }  
            
        }

        /* argc: holds the number of results, argv: holds each value in array, azColName: holds each column returned in array, */
        static int callback(void* NotUsed, int argc, char** argv, char** azColName)
        {
            for (int i=0;i<argc;i++) {
                // column name and value
                cout << azColName[i] << ": " << argv[i] << endl;
            }
            cout << endl;
            return 0;
        }

    public:
        ~DbConnection()
        {
            cout<<"calling destructor for DbConnection !"<<endl;
            // delete ptr;
            ptr =nullptr;
        }
        // static method to to envoke constructor to create object;
        static DbConnection* start(const char* connection)
        {
            if (ptr==nullptr)
            {
                ptr =new DbConnection(connection);
            }
            return ptr;
        }
        // Dbconnection should not be copy 
        DbConnection(DbConnection& val)=delete;
        
        //Dbconnection should not assign
        DbConnection& operator=(DbConnection& val)=delete;

        void InsertData(string _num1,string _num2,string _op,string _result)
        {
            sqlite3*db;
            char*ErrorMessage;
            int open=0;
            open=sqlite3_open(DirectoryLocation,&db);
            // sql query for insert value in Calculator DB
            string sql="INSERT INTO CALCULATOR (NUM1, NUM2, OPERATOR, RESULT) VALUES("+_num1+","+_num2+",'"+_op+"',"+_result+");";
            open = sqlite3_exec(db,sql.c_str(),NULL ,0,&ErrorMessage);
            if (open!=SQLITE_OK)
            {
                cerr<<"Error while inserting data"<<endl;
                sqlite3_free(ErrorMessage);
            }
            else
            {
                cerr<<"Data inserted successfully "<<endl;
            }
            sqlite3_close(db);

        }
        // void updateData(string _num1)
        // {
        //     sqlite3 *db;
        //     char* ErrorMessage;
        //     int open=sqlite3_open(DirectoryLocation,&db);
        //     string sql = "UPDATE CALCULATOR SET NUM1="+_num1+" WHERE ID=1";
        //     open=sqlite3_exec(db,sql.c_str(),NULL,0,&ErrorMessage);
        //     if (open!= SQLITE_OK) {
        //         cerr<<"Error while update dating data."<<endl;
        //         sqlite3_free(ErrorMessage);
        //     }
        //     else
        //         cout<<"Records updated Successfully!"<<endl;
        // }

        // retrieve contents of database used by selectData()
        void selectData()
        {
            sqlite3*db;
            char*ErrorMessage;
            int open=sqlite3_open(DirectoryLocation,&db);
            string sql = "SELECT * FROM CALCULATOR;";
            open = sqlite3_exec(db, sql.c_str(), callback, NULL, &ErrorMessage);
            if(open!=SQLITE_OK)
            {
                cerr<<"Error in selectData function."<< endl;
                sqlite3_free(ErrorMessage);
            }
            else
            {
                cout<<"Records selected Successfully!"<<endl;
            }
        }

        void DeleteData()
        {
            sqlite3*db;
            char*ErrorMessage;
            int open =sqlite3_open(DirectoryLocation,&db);
            string sql = "DELETE FROM CALCULATOR;";
            open=sqlite3_exec(db,sql.c_str(),callback,NULL,&ErrorMessage);
            if(open!=SQLITE_OK)
            {
                cerr<<"Error in deleteData function."<< endl;
                sqlite3_free(ErrorMessage);
            }
            else
            {
                cout<<"Records deleted Successfully!"<< endl;
            }
        }
};

DbConnection* DbConnection::ptr=nullptr;