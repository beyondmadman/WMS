#include "ldatabase.h"

LDataBase::LDataBase()
{

}

bool LDataBase::initSql()
{

}


bool mySqlite::connectDB()
{
    QSqlDatabase myDB = QSqlDatabase::addDatabase("QSQLITE");
    myDB.setDatabaseName(QApplication::applicationDirPath() + "/Database/"+"myWMS.db");
    if(!myDB.open())
        return false;
    return true;
}
