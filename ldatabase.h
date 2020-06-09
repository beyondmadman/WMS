#ifndef LDATABASE_H
#define LDATABASE_H

#include <QSqlDatabase>

class LDataBase
{
public:
    LDataBase();

private:
    bool initDB();
    bool connectDB();
};

#endif // LDATABASE_H
