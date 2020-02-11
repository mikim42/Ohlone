#ifndef ORDER_H
# define ORDER_H

enum	e_indicator
{
	BUY = 0,
	SELL
};

class	Order
{
	public:
		Order(void) {};
		Order(std::string name, std::string symbol, e_indicator indicator,
			  int share, double price);
		~Order(void) {}

		std::string	getCustomer(void) { return _name; }
		std::string	getSymbol(void) { return _symbol; }
		e_indicator	getIndicator(void) { return _indicator; }
		int			getShare(void) { return _share; }
		double		getPrice(void) { return _price; }

		bool	operator<(Order &rhs) { return (this->_price < rhs._price); }
		bool	operator>(Order &rhs) { return (this->_price > rhs._price); }

	private:
		std::string	_name;
		std::string	_symbol;
		e_indicator	_indicator;
		int			_share;
		double		_price;
};

Order::Order(std::string name, std::string symbol, e_indicator indicator,
			 int share, double price)
:	_name(name),
	_symbol(symbol),
	_indicator(indicator),
	_share(share),
	_price(price)
{
}

#endif
