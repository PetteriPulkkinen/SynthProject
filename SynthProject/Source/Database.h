/*
  ==============================================================================

    Database.h
    Created: 28 Nov 2017 6:14:15pm
    Author:  Petteri Pulkkinen

  ==============================================================================
*/

#pragma once

#include "sqlite3.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>


using std::string;
using std::stringstream;
using std::vector;
/*
 References: https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
 
 To get the program build properly sqlite library needs to be installed and linked to the project.
 */

class Database
{
public:
    Database();
    ~Database(){}
    
    //–––––––––––––––
    // Public funtions
    void insertToDB(int ID, string name, double value);
    double getFromDB(int ID, string name);
    void updateValue(int ID, string name, double value);
    void removeSound(int ID);
    vector<int> getIDs();
    
    
    //–––––––––––––––
private:
    // Private variables and functions
    sqlite3* db;
    const char* filename;
    
    void openConnection();
    void closeConnection();
    
    void executeSQL(const char* sql);
    
};