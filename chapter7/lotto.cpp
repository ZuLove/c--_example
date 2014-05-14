#include <iostream>
#include <bitset>
#include <vector>
#include <map>
using namespace std;
void Printmap(map<string,int> &word_cnt);
long double probability(unsigned numbers,unsigned picks);

int main()
{
	
// 	double total,choices;
// 	vector <int> c(10,5);
// 	vector <int>::iterator iter = c.begin();
// 	/*cout << iter;*/
// 	cout << c.front() <<endl;
// 	map <string,int> wprd_count;
// 	wprd_count["Yu"]  = 1;
// 	map <string,int>::value_type;
// 	map <string,int>::iterator map_it = wprd_count.begin();
// 	cout << map_it->first;
// 	cout << " " << map_it->second;
// 	++map_it->second;
// 	cout << wprd_count["Yu"] << endl;
	map <string,int> word_count;
	string word;
 	while(cin >> word)//ctrl+z½áÊø
 	{
 	++word_count[word];
 	}
	Printmap(word_count);
// 	map <string,int>::iterator word_first = word_count.begin();
// 	map <string,int>::iterator word_last  =word_count.end();
// 	while(word_first != word_last)
// 	{
// 		cout << word_first->first << " " << word_first->second << endl;
// 		word_first++;
// 	}
	cin.clear();
	cin.sync();
	map <string,int> word2_count;
	string word2;
	while (cin >> word2)
	{
		pair <map<string,int>::iterator,bool> ret = word2_count.insert(make_pair(word2,1));
		if (!ret.second)
		{
			++ret.first->second;
		}
	}
	Printmap(word2_count);
// 	map <string,int>::iterator word2_first = word2_count.begin();
// 	map <string,int>::iterator word2_last  =word2_count.end();
// 	while(word2_first != word2_last)
// 	{
// 		cout << word2_first->first << " " << word2_first->second << endl;
// 		word2_first++;
// 	}
// 	string s("mysdff");
// 	s.append("ada");
// 	cout << s << endl;
// 	string river("Mississippi");
// 	cout << river.find("is") << river.rfind("is") << endl;
// 	cout << "Enter the total number of choices on the game card and\n"
// 		"the number of picks all allowed:\n";
// 	while ((cin >> total >> choices) && choices <= total)
// 	{
// 		cout << "You have one chance in ";
// 		cout << probability(total,choices) << endl;
// 		cout << "Next two numbers (q to quit): ";
// 	}
// 	bitset<30> yy;
// 	unsigned long xx =0;
// 	xx |= 1UL<<27;
// 	yy.set(27);
// 	cout << xx << endl;
// 	cout << yy <<endl;
// 	cout << "bye\n";
	system("pause");
	return 0;
}

void Printmap(map<string,int> &word_cnt)
{
	 map <string,int>::iterator word_first = word_cnt.begin();
	 map <string,int>::iterator word_last  = word_cnt.end();
	while(word_first != word_last)
	{
		cout << word_first->first << " " << word_first->second << endl;
		word_first++;
	}
}

long double probability(unsigned numbers,unsigned picks)
{
	long double result = 1.0;
	long double n;
	unsigned p;
	for (n = numbers, p = picks; p >0; n--,p--)
		result = result*n /p;
	return result;
}