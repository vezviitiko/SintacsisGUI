#include <Core/Core.h>
#include "Postgres.h"

bool PostgreSQLTest::OpenDB()
{
    if(!m_session.Open("host=**** dbname=**** user=*** password=***"))
    {
        LOG(Format("Error in open: %s", m_session.GetLastError()));
        return false;
    }

#ifdef _DEBUG
	m_session.SetTrace();
#endif

	SQL = m_session;
	return true;
}

bool PostgreSQLTest::CloseDB()
{
    m_session.Close();
	return true;
}
