#include <iostream>
const int Max = 5;

int main()
{
	using namespace std;
	double fish[Max];
	int i =0;
	cout << "fish #" << i+1 << ":";
	while (i < Max && cin >> fish[i])
	{
		if(++i < Max)
			cout << "fish #" << i+1 << ":";
	}
	double total = 0.0;
	for (int j = 0; j<i; j++)
	{
		total += fish[j];
	}
	if (i == 0)
		cout << "No fish\n" << endl;
	else
		cout << total/i << " = average weight of " << i << " Done\n"<< endl;
	if (!cin)
	{
		cin.clear();
		cin.get();
	}
	cin.get();
	cin.get();
	return 0;
}