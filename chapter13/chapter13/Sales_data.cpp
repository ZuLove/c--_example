//#include <iostream>
#include "Sale_data.h"


using namespace std;
int main()
{
	cout << "hello world" << endl;
	Sales_data *p = new Sales_data;
	auto p2 = make_shared<Sales_data>();
	Sales_data item(*p);
	vector<Sales_data> vec;
	vec.push_back(*p2);
	delete p;
	system("pause");
	return 0;
}