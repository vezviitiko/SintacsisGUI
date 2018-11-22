#ifndef _sintacsisGUI_Postgres_h_
#define _sintacsisGUI_Postgres_h_

#include <Core/Core.h>
using namespace Upp;

#include <PostgreSQL/PostgreSQL.h>

class PostgreSQLTest {
public:
    typedef PostgreSQLTest CLASSNAME;
    bool OpenDB();
    bool CloseDB();
protected:
    PostgreSQLSession m_session;
};

#endif
