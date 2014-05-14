#include <iostream>
#include<string>
#include <map>
using namespace std;
void printmultimap(multimap <string, string> &authors);
void printmultimap1(multimap <string, string> &authors);
void printmultimap2(multimap <string, string> &authors);
int main()
{
	
	multimap<string, string> authors;
    //multimap<string,string>::value_type(string("Barth, John"),string("Sot-Weed Factor"));
	authors.insert(make_pair("Barth, John","Sot-Weed Factor"));
	authors.insert(make_pair("Barth, John","Lost in the Funhouse"));
	authors.insert(make_pair("Barth","Lost Funhouse"));
	authors.insert(make_pair("John","Lost inFunhouse"));
	//multimap <string, string>::size_type count = authors.erase("Barth, John");
	printmultimap2(authors);
	system("pause");
	return 0;
}
void printmultimap2(multimap <string, string> &authors)
{
	typedef multimap<string,string>::iterator authors_it;
	pair< authors_it, authors_it > val_type = authors.equal_range("Barth, John");
	//multimap<string,string>::iterator val_type = authors.equal_range("Barth, John");
	while (val_type.first != val_type.second)
	{
		cout << val_type.first->first << "----->" << val_type.first->second << endl;
		++val_type.first;
	}
}
void printmultimap1(multimap <string, string> &authors)
{
	typedef multimap <string, string>::iterator iters;
	iters iterb = authors.lower_bound("Barth, John");//指向关键字的第一个数据
	iters itere = authors.upper_bound("Barth, John");//最后一个的下一个数据
	while (iterb!=itere)
	{
		cout << iterb->first << "--->" << iterb->second << endl;
		++iterb;
	}
}
void printmultimap(multimap <string, string> &authors)
{
	typedef multimap <string, string>::size_type sz_type;
	sz_type co = authors.count("Barth, John");
	//cout << count;
	multimap <string, string>::iterator iter = authors.find("Barth, John");
	for (sz_type cnt = 0; cnt != co; ++cnt,++iter)
	{
		cout << iter->first << ":--->" << iter->second << endl;
	}
}