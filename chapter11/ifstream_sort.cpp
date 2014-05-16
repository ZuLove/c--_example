#include <iostream>
#include <vector>
#include <fstream>
#include <ostream>
#include <string>
#include <algorithm>
using namespace std;
ifstream &open_file(ifstream &cin, string file_name);
void print_vector(vector<int> &vec);

int main()
{
	ifstream cin;
	string file_name = "cin.txt";
	if (!open_file(cin,file_name))
		cerr << "Open file error...." ;
	istream_iterator<int> cin_iter(cin);
	istream_iterator<int> end_of_stream;
	vector<int> vec(cin_iter,end_of_stream);
	print_vector(vec);
	sort(vec.begin(),vec.end());
	ofstream cout;
	string file_out = "cout.txt";
	cout.clear();
	cout.close();
	cout.open(file_out.c_str());
	ostream_iterator<int> output(cout," ");
	unique_copy(vec.begin(),vec.end(),output);
	system("pause");
	return 0;
}
void print_vector(vector<int> &vec)
{
	vector<int>::iterator iter = vec.begin();
	while (iter != vec.end())
	{
		cout << *iter++ << " ";
	}
	cout << endl;
}
ifstream &open_file(ifstream &cin, string file_name)
{
cin.clear();
cin.close();
cin.open(file_name.c_str());
return cin;
}