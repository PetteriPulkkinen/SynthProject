/*
  ==============================================================================

    Database.cpp
    Created: 28 Nov 2017 6:14:15pm
    Author:  Petteri Pulkkinen

  ==============================================================================
*/

#include "Database.h"



static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}



Database::Database()
{
    filename = "savedsounds.db";
    openConnection();
    
    string sql =\
    "CREATE TABLE Sounds ("\
    "ID INT NOT NULL,"\
    "name CHAR(15) NOT NULL,"\
    "value FLOAT,"\
    "PRIMARY KEY(ID,name)"\
    ");";
    
    char *cstr = new char[sql.length() + 1];
    strcpy(cstr, sql.c_str());
    
    executeSQL(cstr);
    
    closeConnection();
    delete [] cstr;
}

void Database::openConnection()
{
    if(sqlite3_open(filename, &db) != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        closeConnection();
        throw sqlite3_errmsg(db);
    }
};

void Database::closeConnection()
{
    sqlite3_close(db);
}


void Database::insertToDB(int ID, string name, double value)
{
    openConnection();
    std::string sql =\
    "INSERT INTO Sounds (ID,name,value) "\
    "VALUES ("+std::to_string(ID)+", '"+name+"', "+std::to_string(value)+")";
    
    std::cout << sql << std::endl;
    char *cstr = new char[sql.length() + 1];
    strcpy(cstr, sql.c_str());
    
    executeSQL(cstr);
    
    delete [] cstr;
    closeConnection();
}

double Database::getFromDB(int ID, string name)
{
    double retValue = 0;
    sqlite3_stmt* stmt;
    stringstream ss;
    
    
    // create sql statement string
    ss << "select value from Sounds where id = " << ID << " and name = '" << name << "';";
    
    string sql(ss.str());
    std::cout << sql << std::endl;
    
    
    openConnection();
    
    // compile sql statement to binary
    if(sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) != SQLITE_OK) {
        printf("ERROR: while compiling sql: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        sqlite3_finalize(stmt);
        throw sqlite3_errmsg(db);
    }
    
    // execute sql statement, and while there are rows returned, print ID
    int ret_code = 0;
    while((ret_code = sqlite3_step(stmt)) == SQLITE_ROW) {
        retValue = sqlite3_column_double(stmt, 0);
        printf("TEST: Value = %f\n", retValue);
    }
    if(ret_code != SQLITE_DONE) {
        //this error handling could be done better, but it works
        printf("ERROR: while performing sql: %s\n", sqlite3_errmsg(db));
        printf("ret_code = %d\n", ret_code);
        throw sqlite3_errmsg(db);
    }
    
    
    //release resources
    sqlite3_finalize(stmt);
    closeConnection();
    
    return retValue;
}



void Database::executeSQL(const char* sql)
{
    char *zErrMsg = 0;
    int rc;
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
}

void Database::updateValue(int ID, string name, double value)
{
    stringstream ss;
    char *zErrMsg = 0;
    ss << "UPDATE Sounds set value = " << value << ";";
    
    string sql = ss.str();
    
    std::cout << sql << std::endl;
    
    openConnection();
    
    int rc;
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    
    if( rc != SQLITE_OK){
        sqlite3_free(zErrMsg);
        throw "ValueUpdate";
    }
    
    closeConnection();
}

void Database::removeSound(int ID)
{
    stringstream ss;
    char *zErrMsg = 0;
    ss << "DELETE FROM Sounds WHERE ID = " << ID << ";";
    
    string sql = ss.str();
    
    std::cout << sql << std::endl;
    
    openConnection();
    
    int rc;
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    
    if (rc != SQLITE_OK){
        std::cout << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
        throw "IDremove";
    }
    closeConnection();
}

vector<int> Database::getIDs()
{
    vector<int> retValue;
    sqlite3_stmt* stmt;
    stringstream ss;
    
    
    // create sql statement string
    ss << "select distinct id from Sounds;";
    
    string sql(ss.str());
    std::cout << sql << std::endl;
    
    
    openConnection();
    
    // compile sql statement to binary
    if(sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) != SQLITE_OK) {
        printf("ERROR: while compiling sql: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        sqlite3_finalize(stmt);
        throw sqlite3_errmsg(db);
    }
    
    // execute sql statement, and while there are rows returned, print ID
    int ret_code = 0;
    while((ret_code = sqlite3_step(stmt)) == SQLITE_ROW) {
        retValue.push_back(sqlite3_column_int(stmt, 0));
        printf("TEST: ID = %d\n", sqlite3_column_int(stmt, 0));
    }
    if(ret_code != SQLITE_DONE) {
        //this error handling could be done better, but it works
        printf("ERROR: while performing sql: %s\n", sqlite3_errmsg(db));
        printf("ret_code = %d\n", ret_code);
        throw sqlite3_errmsg(db);
    }
    
    
    //release resources
    sqlite3_finalize(stmt);
    closeConnection();
    
    return retValue;
}


