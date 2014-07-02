#include <iostream>
using namespace std;
class SmallInt{
public:
	SmallInt(int i = 0) :val(i)
	{
		if (i<0||i>25)
		{
			throw std::out_of_range("bad value");
		}
	}
	explicit operator int() const { return val; }
private:
	std::size_t val;
};

int main()
{
	SmallInt si = 3;

	std::cout << static_cast<int>(si)+3 << std::endl;
	if (static_cast<int>(si)+3)
	{

	}
	system("pause");
	return 0;
}