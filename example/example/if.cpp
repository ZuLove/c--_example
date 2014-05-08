#include <iostream>
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	char ch;
	int spaces = 0;
	int total =0;
	while(cin.get(ch))
	{
		if(ch == ' ')
		{
			++spaces;
		}
		++total;
	}
	cout << spaces <<' ' << total <<endl;
	getchar();
	return 0;
}