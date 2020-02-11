/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:50:37 by mikim             #+#    #+#             */
/*   Updated: 2018/05/15 15:17:31 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#include <lab.h>

int		main(int ac, char **av)
{
	// logo
	std::cout <<
	"/ ************************************* \\\n"
	"* CS124 - STOCK EXCHANGE       MADE BY. *\n"
	"* Dean Huang  : Gevorg Keshishian        *\n"
	"* Mingyun Kim : Muhammed Hassan Mahmood *\n"
	"\\ ************************************* /\n"
	<< std::endl;
	// end

	StockExchange	msft(10);
	StockExchange	goog(10);
	StockExchange	intl(10);

	msft.populate("MSFT");
	goog.populate("GOOG");
	intl.populate("INTL");

	Order item;

	for (int i = 0; i < 10; i++)
	{
		msft.removeSeller(item);
		std::cout << item.getSymbol() << " : " << item.getPrice() << " : " << item.getShare() << std::endl;
	}

	return (0);
}
