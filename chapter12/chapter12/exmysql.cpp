#include <iostream>
#include <mysql++.h>
#include <string>

using namespace std;

int main()
{
	mysqlpp::Connection conn(false);
	conn.set_option(new mysqlpp::SetCharsetNameOption("gbk"));
	cout << "hello world" << endl;
	if (conn.connect("xytx_qiyuan", "127.0.0.1", "root", "yuli", 3306))
	{

		//cout << conn.count_rows("login") << endl;//获取表login中的数据
		//conn.create_db("mysqlpp");//创建数据库mysqlpp
		mysqlpp::Query query = conn.query("select role_name,ip from login");
		//conn.
		//query =conn.query("select role_name,ip from login default set names 'gbk'");
		if (mysqlpp::StoreQueryResult res = query.store())
		{
			cout << "we have: " << res.num_fields() << endl;
			//system("pause");
			//res.size();
			mysqlpp::StoreQueryResult::const_iterator it;
			for (it = res.begin(); it != res.end(); ++it)
			{
				mysqlpp::Row row = *it;

				cout << row[0].c_str() << " " << row[1] << endl;
			}
			cout << "完了" << endl;
		}
	}
	system("pause");
	return 0;
}
