#include <iostream>
#include <unordered_map>

int main()
{
	std::unordered_map<int, std::string> test;
	test.insert(std::make_pair(23,"123asds"));
    //auto iter = test.find(23);
    test.erase(23);
	test.insert(std::make_pair(23,"sffasdasd"));
	for (auto &it:test)
	{
        std::cout << it.first << " " << it.second.c_str() << std::endl;
	}
    system("pause");
	return 0;
}