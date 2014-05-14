//#include <iostream>
#include "textquery.h"

using namespace std;
void print_result(const set<TextQuery::line_no>& locs, const string& sought, const TextQuery &file);
string make_plural(size_t ctr, const string &word, const string &ending);

int main()
{   
    TextQuery tq;
	ifstream infile;
	if (!tq.open_file(infile,"exp.txt"))
	{
		std::cerr << "No such File!" << endl;
		//return EXIT_FAILURE;
	}
	tq.read_file(infile);
	while (true)
	{
		cout << "Enter word to look for, or q to quit: ";
		string s;
		cin >> s;
		if(!cin || s == "q")break;
		set<TextQuery::line_no> locs = tq.run_query(s);
		print_result(locs,s,tq);
	}
	system("pause");
	return 0;
}
void print_result(const set<TextQuery::line_no>& locs, const string& sought, const TextQuery &file)
{
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	cout << "\n" << sought << "occurs "<< size << " " << make_plural(size,"time","s") << endl;
	line_nums::const_iterator it = locs.begin();
	for (; it != locs.end(); ++it)
	{
		cout << "\t(line"
			<< (*it)+1 << ") "
			<< file.text_line(*it) << endl;
	}
}
string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr == 1) ? word : word + ending;
}
ifstream& TextQuery::open_file(ifstream &in, const string &file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}
void TextQuery::store_file(ifstream &is)
{
	string textline;
	while (getline(is,textline))
	{
		lines_of_text.push_back(textline);
	}
}
void TextQuery::bulid_map()
{
	for (line_no line_num = 0; line_num != lines_of_text.size(); ++line_num)
	{
		istringstream line(lines_of_text[line_num]);
		string word;
		while(line >> word)
			word_map[word].insert(line_num);
	}
}
set<TextQuery::line_no> TextQuery::run_query(const string &query_word) const
{
	map<string,set<line_no> >::const_iterator loc = word_map.find(query_word);
	if (loc == word_map.end())
		return set<line_no>();
	else
		return loc->second;
}
string TextQuery::text_line(line_no line) const
{
	if (line < lines_of_text.size())
		return lines_of_text[line];
	throw out_of_range("line number out of range");
}