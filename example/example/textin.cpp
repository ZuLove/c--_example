#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;
	//cin.get(ch);
	//while(!cin.fail())
	//while(cin.fail()==false)//windows 7 下按下ctrl+z为EOF,cin.fail() == true
	while(cin.get(ch))
	{
		cout << ch;
		++count;
		//cin.get(ch);
	}
	cout << endl << count << ch << endl;
	getchar();
	return 0;
}