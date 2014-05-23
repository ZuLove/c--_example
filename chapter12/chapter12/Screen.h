#include <iostream>

class Screen{
public:
	typedef std::string::size_type index;
	char get() const {return contents[cursor]; }
	char get(index ht, index wd) const;
	index get_cursor() const;
private:
	std::string contents;
	index cursor;
	index height, width;
}; 
class Sales_item {


};