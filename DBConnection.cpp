#include "includes.h"
extern CLogger g_cSystemLogger;

PGconn* DBConnection::conn = NULL;
PGresult* DBConnection::res = NULL;
int DBConnection::row_count = 0;
int DBConnection::col_count = 0;

DBConnection::DBConnection() {


}

DBConnection::~DBConnection() {

}

int DBConnection::getQueryResult(tapServerInfoMap& m_MapObject, char dbUserName[20], char dbPassword[20], char dbName[20], char dbPort[20], char hostAdress[20], char lineType[8]) {

    PGconn *conn;

    sprintf(connectionBuffer, "%s%s %s%s %s%s %s%s %s%s", "user=", dbUserName, "password=", dbPassword, "dbname=", dbName, "hostaddr=", hostAdress, "port=", dbPort);

    conn = PQconnectdb(connectionBuffer);

    if (PQstatus(conn) != CONNECTION_OK) {

        std::cout<<"DB not found"<<endl;
        return 0;

    }
    if (strcmp(lineType, "CM") == 0) {
        res = PQexec(conn, "select eq_userid,tap_server_ip from exchg_conn_table");
        col_count = 1;
    } else if ((strcmp(lineType, "FO") == 0) || (strcmp(lineType, "BSE") == 0)) {
        res = PQexec(conn, "select fo_userid,tap_server_ip from exchg_conn_table");
        col_count = 1;
    }
    else if (strcmp(lineType, "CM FO") == 0) {

        res = PQexec(conn, "select  eq_userid,fo_userid,tap_server_ip from exchg_conn_table");
        col_count = 2;
    }

    row_count = PQntuples(res);
    long userId;
    string ipAdress;
    if (col_count == 1) {
        for (int row = 0; row < row_count; row++) {
            for (int col = 0; col <= col_count; col++) {

                if (col == 0) {
                    userId = atoi(PQgetvalue(res, row, col));


                } else if (col == 1) {
                    ipAdress = PQgetvalue(res, row, col);

                }

            }
            m_MapObject.insert(std::pair<long, std::string > (userId, ipAdress));
	    
        }
    }
    else if (col_count == 2) {
        userId = atoi(PQgetvalue(res, 0, 0));

        ipAdress = PQgetvalue(res, 0, 2);
        m_MapObject.insert(std::pair<long, std::string > (userId, ipAdress));
        userId = atoi(PQgetvalue(res, 0, 1));

        ipAdress = PQgetvalue(res, 0, 2);
        m_MapObject.insert(std::pair<long, std::string > (userId, ipAdress));

    }
    
    else
    {
        
    }
    return 1;
}

int DBConnection::getFoPiQueryResult(char dbUserName[20], char dbPassword[20], char dbName[20], char dbPort[20], char hostAdress[20],lineDetails &ld) {

    PGconn *conn;
    std::cout<<"dbUserName" <<dbUserName<<endl;
    std::cout<<"dbPassword" <<dbPassword<<endl;
    std::cout<<"dbName" <<dbName<<endl;
    std::cout<<"dbPort" <<dbPort<<endl;
    sprintf(connectionBuffer, "%s%s %s%s %s%s %s%s %s%s", "user=", dbUserName, "password=", dbPassword, "dbname=", dbName, "hostaddr=", hostAdress, "port=", dbPort);

    conn = PQconnectdb(connectionBuffer);

    if (PQstatus(conn) != CONNECTION_OK) {

        std::cout<<"DB not found"<<endl;
        return 0;

    }
     
     res = PQexec(conn, "select fo_userid,fo_products from exchg_conn_table");
     row_count = PQntuples(res);
     ld.line_count=row_count;
     for (int row = 0; row < row_count; row++) {
         
            for (int col = 0; col < 2; col++) {
                if(col==0)
                {
                ld.ld[row].fo_id=atoi(PQgetvalue(res, row, col));
                }
                
                else if(col==1)
                {
                strcpy(ld.ld[row].product_details,PQgetvalue(res, row, col));
                }
                
            }
 
}
     return 1;
}
void DBConnection::Close() {
    if (CONNECTION_BAD == PQstatus(conn)) {
        g_cSystemLogger.LogMessage("(%s:%s:%d):: bad Connection", LOG_LOCATION);
    }

    if (conn != NULL) {
        /* close the current connection and free the PGconn data structure */
        g_cSystemLogger.LogMessage("(%s:%s:%d):: Closing connection to database '%s'...\n", LOG_LOCATION, PQdb(conn));
        PQfinish(conn);
        conn = NULL;
    }

    return;
}







