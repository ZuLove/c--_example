#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <iterator>
#include <list>
#include <algorithm>
#include <sstream>
using namespace std;
bool isShorter(const string &s1, const string &s2);
bool GT6(const string &s);
string make_plural(vector <string>::size_type wc,string s1,string s2);
int main()
{
	
	vector <int> vec(10,5);
	vector <int>::iterator iters = vec.begin();
	while (iters != vec.end())
	{
		cout << *iters++ << endl;
	}
	int sum = accumulate( vec.begin(), vec.end(), 20);
	cout << sum << endl;
	/************************************************************************/
	/*    accumulate                                                        */
	/************************************************************************/
	vector<string> strc;
	strc.insert(strc.begin(),(string("my name is Yu")));
	string strsum = accumulate(strc.begin(),strc.end(),string("yuns"));
	cout << strsum << endl;
	/************************************************************************/
	/*           back_inserter                                              */
	/************************************************************************/
	vector <int> vecx;
	fill_n(back_inserter(vecx),10,1);
	vector <int>::iterator itersx = vecx.begin();
	while (itersx != vecx.end())
	{
		cout << *itersx++ << endl;
	}
	/************************************************************************/
	/*       copy                                                           */
	/************************************************************************/
	int num[10] = {1,2,3,4,5,6,7,8,8,9};
	list <int> ilst;
	ilst.insert(ilst.begin(),num,num+10);
	vector <int> vecc;
	copy(ilst.begin(),ilst.end(),back_inserter(vecc));//效率低
	//vector <int> vecc(ilst.begin(),ilst.end());//效率高
	vector <int>::iterator itersc = vecc.begin();
	while (itersc != vecc.end())
	{
		cout << *itersc++ << endl;
	}
	/************************************************************************/
	/*       replace & replace_copy                                         */
	/************************************************************************/
	replace(ilst.begin(),ilst.end(),1,23);
	list <int>::iterator it = ilst.begin();
	while (it != ilst.end())
	{
		cout << *it++ << " ";
	}
	cout << endl;
	vector <int> vec_copy;
	replace_copy(ilst.begin(),ilst.end(),back_inserter(vec_copy),8,50);
	vector <int>::iterator iters_copy = vec_copy.begin();
	while (iters_copy != vec_copy.end())
	{
		cout << *iters_copy++ << " ";
	}
	cout << endl;
	vector <string> words;
	string s = "the quick red fox jumps over the slow red turtle";
	istringstream line(s);
	string word;
	while (line >> word)
	{
		words.push_back(word);
	}
	sort(words.begin(),words.end());
	vector <string>::iterator end_unique = unique(words.begin(),words.end());//将未重复的放在前面，重复的放在后面，并返回重复的第一个元素的迭代器
	words.erase(end_unique, words.end());//删除重复的元素

	vector <string>::iterator iterm = words.begin();
	while (iterm != words.end())
	{
		cout << *iterm++ << " ";
	}
	cout << endl;
	stable_sort(words.begin(),words.end(),isShorter);
	vector <string>::size_type wc = count_if(words.begin(), words.end(), GT6);
	cout << wc << " " << make_plural(wc,"word","s") << " charactors or longer" << endl;
	system("pause");
	return 0;
}

string make_plural(vector <string>::size_type wc,string s1,string s2)
{
	return (wc > 1) ? (s1+s2) : s1;
}
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

bool GT6(const string &s)
{
	return s.size() >= 6;
}