#include <iostream>
#include <cctype>
int main()
{
	using namespace std;
	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int puncts = 0;
	int others = 0;
	cin.get(ch);
	while(ch != '@')
	{
		if(isalpha(ch))
			chars++;
		else if(isspace(ch))
		whitespace++;
		else if(isdigit(ch))
			digits++;
		else if(ispunct(ch))
			puncts++;
		else
			others++;
		cin.get(ch);
	}
	cout << chars << endl;
	cout << whitespace << endl;
	cout << digits << endl;
	cout << puncts << endl;
	cout << others << endl;

	getchar();
	getchar();
    return  0;
}