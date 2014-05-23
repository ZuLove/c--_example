#include <iostream>
#include <vector>
#include <memory>


class Sales_data {
public:
	Sales_data() = default;//默认构造函数
	Sales_data(const Sales_data&);//构造函数初始化类对象的非static数据成员，成员初始化是按照在类中出现的顺序在函数体执行之前完成
	~Sales_data() = default;//析构函数释放对象使用的资源，并销毁非类对象的非static数据成员，析构函数不接受参数，故不能被重载，
	//成员销毁顺序是按照初始化的逆序销毁的
	Sales_data& operator=(const Sales_data &rhs);
private:
	std::string bookNo;
	int units_sold = 0;//C++11新特性....以前只能是static const 整形变量才能在类内部初始化
	double revenue = 0.0;
};


Sales_data::Sales_data(const Sales_data &orig):bookNo(orig.bookNo),
                                           units_sold(orig.units_sold),
										   revenue(orig.revenue)
{}
Sales_data& Sales_data::operator=(const Sales_data &rhs)
{
	bookNo = rhs.bookNo;
	units_sold = rhs.units_sold;
	revenue = rhs.revenue;
	return *this;
}