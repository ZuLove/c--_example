#include <iostream>

class Quote{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :bookNo(book), price(sales_price)
	{ }
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n*price; }
	virtual ~Quote() = default;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Bulk_quote :public Quote{
	
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :
		Quote(book, p), min_qty(qty), discount(disc){ }
	double net_price(std::size_t) const override;
	~Bulk_quote() = default;
private:
	std::size_t min_qty = 0;//实用折扣的最低数量
	double discount = 0.0;//以小数表示的折扣额
};

class MetaData
{
public:
	MetaData( int size, const std::string& name)
	: _name( name )
	, _size( size )
	{}

	MetaData(const MetaData& other)
		:_name( other._name )
		, _size( other._size )
	{}
	MetaData(MetaData&& other)
		:_name( other._name )
		, _size( other._size )
	{}
	std::string getName() const { return _name; }
	int getSize() const { return _size; }
private:
	std::string _name;
	int _size;
};

class ArrayWrapper{
public:
	ArrayWrapper()
		:_p_vals( new int[64] )
		, _metadata(64, "ArrayWrapper")
	{}
	ArrayWrapper(int n)
		:_p_vals(new int[n])
		, _metadata(n, "ArrayWrapper")
	{}
	ArrayWrapper(ArrayWrapper && other)//移动构造函数.other是一个右值引用，所以要用std::move
		:_p_vals( other._p_vals )
		, _metadata(std::move(other._metadata))
	{
		other._p_vals = NULL;
	}
	ArrayWrapper(const ArrayWrapper& other)//复制构造函数
		:_p_vals(new int[ other._metadata.getSize() ])
		, _metadata( other._metadata )
	{
		for (int i = 0; i < _metadata.getSize();++i)
	{
			_p_vals[i] = other._p_vals[i];
	}
	}
	~ArrayWrapper()
	{
		delete[] _p_vals;
	}
private:
	int *_p_vals;
	MetaData _metadata;
};