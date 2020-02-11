#ifndef STOCK_EXCHANGE_H
# define STOCK_EXCHANGE_H

class	StockExchange
{
	public:
		StockExchange(void) {}
		StockExchange(int size);
		~StockExchange(void);

		void	populate(std::string symbol);
		bool	saveSeller(std::string file);
		bool	saveBuyer(std::string file);
		bool	loadSeller(std::string file);
		bool	loadBuyer(std::string file);

		bool	saveLog(std::string file);
		bool	loadLog(std::string file);

		int		getSize(void) { return _size; }
		double	getTotal(void) { return _total; }
		void	setTotal(double total) { _total = total; }
		void	addTotal(double price) { _total += price; }
		void	subTotal(double price) { _total -= price; }

		int		getSellernNodes(void) { return _seller->getnNodes(); }
		bool	insertSeller(Order item) { return _seller->insert(item); }
		bool	removeSeller(Order &item) { return _seller->remove(item); }
		double	getPriceSeller(void);

		int		getBuyernNodes(void) { return _buyer->getnNodes(); }
		bool	insertBuyer(Order item) { return _buyer->insert(item); }
		bool	removeBuyer(Order &item) { return _buyer->remove(item); }
		double	getPriceBuyer(void);

	private:
		MinHeap<Order>		*_seller;
		MaxHeap<Order>		*_buyer;
		std::vector<Log>	_log;
		int					_size;
		double				_total;
};

StockExchange::StockExchange(int size)
{
	_seller = new MinHeap<Order>(size);
	_buyer = new MaxHeap<Order>(size);
	_size = size;
	_total = 0;
}

StockExchange::~StockExchange(void)
{
	delete _seller;
	delete _buyer;
}

double	StockExchange::getPriceSeller(void)
{
	Order	item;

	if (_seller->peek(item))
		return item.getPrice();
	else
		return (0);
}

double	StockExchange::getPriceBuyer(void)
{
	Order	item;

	if (_buyer->peek(item))
		return item.getPrice();
	else
		return (0);
}

void	StockExchange::populate(std::string symbol)
{
	for (int i = 0; i < _size; i++)
	{
		_buyer->insert(Order("Buyer", symbol, BUY, rand() % 3000,
					  static_cast<double>(rand() % 10000) / 100));
		_seller->insert(Order("Seller", symbol, SELL, rand() % 3000,
					  static_cast<double>(rand() % 10000) / 100));
	}
}

bool	StockExchange::saveSeller(std::string file)
{
	std::fstream	f(file.c_str());
	Order	tmp;

	if (!f)
		return false;
	f << _seller->getnNodes() << std::endl;
	while (_seller->remove(tmp))
	{
		f <<
		tmp.getCustomer() << "\t" <<
		tmp.getSymbol() << "\t" <<
		(tmp.getIndicator()) ? "SELL\t" : "BUY\t";
		f << tmp.getShare();
		f << "\t";
		f << tmp.getPrice() << std::endl;
	}
	return true;
}

bool	StockExchange::saveBuyer(std::string file)
{
	std::fstream	f(file.c_str());
	Order	tmp;

	if (!f)
		return false;
	f << _buyer->getSize() << std::endl;
	while (_buyer->remove(tmp))
	{
		f <<
		tmp.getCustomer() << "\t" <<
		tmp.getSymbol() << "\t" <<
		(tmp.getIndicator()) ? "SELL\t" : "BUY\t";
		f << tmp.getShare();
		f << "\t";
		f << tmp.getPrice() << std::endl;
	}
	return true;
}

bool	StockExchange::loadSeller(std::string file)
{
	std::fstream	f(file.c_str());

	if (!f)
		return false;
	int	size;
	f >> size;
	if (!(_seller = new MinHeap<Order> (size)))
		return false;

	std::string	name, symbol, inds;
	e_indicator	ind;
	int			share;
	double		price;

	while (f.is_open())
	{
		f >> name >> symbol >> inds >> share >> price;
		ind = (inds == "SELL") ? SELL : BUY;
		_seller->insert(Order(name, symbol, ind, share, price));
	}
}

bool	StockExchange::loadBuyer(std::string file)
{
	std::fstream	f(file.c_str());

	if (!f)
		return false;
	int	size;
	f >> size;
	if (!(_buyer = new MaxHeap<Order> (size)))
		return false;

	std::string	name, symbol, inds;
	e_indicator	ind;
	int			share;
	double		price;

	while (f.is_open())
	{
		f >> name >> symbol >> inds >> share >> price;
		ind = (inds == "SELL") ? SELL : BUY;
		_buyer->insert(Order(name, symbol, ind, share, price));
	}
}

bool	StockExchange::saveLog(std::string file)
{
	std::fstream	f(file.c_str());

	if (!f)
		return false;

	for (size_t i = 0; i < _log.size(); i++)
	{
		f <<
		_log[i].getName() << "\t" <<
		_log[i].getSymbol() << "\t" <<
		(_log[i].getIndicator() == SELL) ? "SELL\t" : "BUY\t";
		f << _log[i].getShare();
		f << "\t" <<
		_log[i].getPrice() << "\t" << std::endl;
	}
}

bool	StockExchange::loadLog(std::string file)
{
	std::fstream	f(file.c_str());

	if (!f)
		return false;

	std::string	name, symbol, inds;
	e_indicator	ind;
	int			share;
	double		price;

	while (f.is_open())
	{
		f >> name >> symbol >> inds >> share >> price;
		ind = (inds == "SELL") ? SELL : BUY;
		_log.push_back(Log(name, symbol, ind, share, price));
		_total += price;
	}
	return true;
}

#endif
