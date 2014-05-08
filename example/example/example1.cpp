#include <iostream>
#include <string>
const int maxsize = 20;
int main()
{
    using namespace std;
	std::cout << "Come up and C++ me some time.\n";
	std::cout << std::endl;
	std::cout << "You won't regret it!" << std::endl;
	std::cout << int ('a') <<std::endl;
	std::cout << static_cast<int>('a') << std::endl;//类型强制转换
	std::cout << int (19.99)+int (11.99) << std::endl;
	string word = "?ate";
	for (char ch = 'a'; word != "mate"; ch++)
	{
		std::cout << word <<std::endl;
		word[0] = ch;

	}
	char name[maxsize] ="YuLi";
// 	cout << "input your name:";
// 	cin >> name;
	int i = 0;
	while(name[i] != '\0')
	{
		cout << name[i] << ':' << int(name[i]) << endl;
		i++;
	}
	double prices[5] = {4.99,10.99,6.87,7.99,8.49};
	for (double x : prices)
		cout << x << std::endl;
    for (double &x : prices)
		x = x*0.80;
	for (double x : prices)
		cout << x << std::endl;
	getchar();
	return 0;
}