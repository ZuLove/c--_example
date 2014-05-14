#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
//using namespace  std;
class TextQuery {
public:
	typedef std::vector<std::string>::size_type line_no;
	void read_file(std::ifstream &is)
	{
		store_file(is);
		bulid_map();
	}
	std::set<line_no> run_query(const std::string&) const;
	std::string text_line(line_no) const;
	std::ifstream& open_file(std::ifstream &in, const std::string &file);
private:
	void store_file(std::ifstream&);
	void bulid_map();
	
	std::vector<std::string> lines_of_text;
	std::map<std::string,std::set<line_no> > word_map;
};