#include <iostream>
const int Max = 5;
int main()
{
	using namespace std;
	int golf[Max];
	cout << "Please enter your golf score.\n";
	cout << "You must enter " << Max << " rounds.\n";
	for (int i = 0; i < Max; i++)
	{
		cout << "round#" << i+1 << ": ";
		while(!(cin >> golf[i])){
			cin.clear();//清除错误标志，让我们可以重新输入...
			cin.sync();//清除数据流中的数据
//  			while (cin.get() != '\n')//依次读取输入的非数字字符串,直到结尾....
//  			    continue;
			cout << "Please enter a number:";
		}
	}
	double total = 0.0;
	for ( int i = 0; i < Max; i++)
		total += golf[i];
	cout << total/Max << " = average score "<< Max << " rounds\n";
	cin.get();
	cin.get();
	return 0;
}