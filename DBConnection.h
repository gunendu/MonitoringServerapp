/* 
 * File:   DBConnection.h
 * Author: Gunendu Das
 *
 * Created on 10 September, 2012, 2:53 PM
 */

#include "dataTypes.h"
#include "Monitoring.h"

#ifndef DBCONNECTION_H
#define	DBCONNECTION_H



#endif	/* DBCONNECTION_H */

class DBConnection {
private:
    static PGconn *conn;
    static PGresult *res;
    static int row_count;
    static int col_count;
    char connectionBuffer[30];


public:
    DBConnection();
    ~DBConnection();
    int static inline getNoOfTapServer() {
        return row_count;
    }
    int getQueryResult(tapServerInfoMap& m_MapObject, char dbUserName[20], char dbPassword[20], char dbName[20], char dbPort[20], char hostAdress[20], char lineType[8]);
    int getFoPiQueryResult(char dbUserName[20], char dbPassword[20], char dbName[20], char dbPort[20], char hostAdress[20],lineDetails& ld);
    void Close();
    
};
