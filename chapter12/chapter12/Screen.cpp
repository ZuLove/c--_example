#include "Screen.h"

char Screen::get(index r, index c) const
{
	index row = r*width;
	return contents[row+c];
}
inline Screen::index Screen::get_cursor() const
{
	return cursor;
}