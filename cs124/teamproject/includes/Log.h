#ifndef LOG_H
# define LOG_H

# include <lab.h>

class	Log
{
	public:
		Log(std::string name, std::string symbol, e_indicator indicator,
			int share, double price)
		:	_name(name), _symbol(symbol), _indicator(indicator),
			_share(share), _price(price) {}
		~Log(void) {}

		void	setName(std::string name) { _name = name; }
		void	setSymbol(std::string symbol) { _symbol = symbol; }
		void	setIndicator(e_indicator ind) { _indicator = ind; }
		void	setShare(int share) { _share = share; }
		void	setPrice(double price) { _price = price; }

		std::string	getName(void) { return _name; }
		std::string	getSymbol(void) { return _symbol; }
		e_indicator	getIndicator(void) { return _indicator; }
		int			getShare(void) { return _share; }
		double		getPrice(void) { return _price; }

	private:
		std::string	_name;
		std::string	_symbol;
		e_indicator	_indicator;
		int			_share;
		double		_price;
};

#endif
