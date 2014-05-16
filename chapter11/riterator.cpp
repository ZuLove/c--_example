#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec;
	for (vector<int>::size_type i = 0;i != 10;i++)
	{
		vec.push_back(i);
	}
	vector<int>::reverse_iterator riter;
	//sort(vec.rbegin(),vec.rend());
	for (riter = vec.rbegin(); riter != vec.rend(); riter++)
	{
		cout << *riter << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}