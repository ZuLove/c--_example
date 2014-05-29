#include <iostream>
#include <mysql++.h>
#include <iomanip>
using namespace std;
int main()
{
	mysqlpp::Connection conn(false);
	if (conn.connect("xytx_qiyuan", "127.0.0.1", "root", "yuli"))
	{
		mysqlpp::Query query = conn.query("select role_name from login");
		if (mysqlpp::StoreQueryResult res = query.store())
		{
			cout << "we have:" << endl;
			mysqlpp::StoreQueryResult::const_iterator it;
			for (it = res.begin(); it != res.end(); ++it)
			{
				mysqlpp::Row row = *it;
				cout << '\t' << row[0] << endl;
			}
		}
	}
	//mysqlpp::sql_bigint_unsigned
	system("pause");
	return 0;
}
