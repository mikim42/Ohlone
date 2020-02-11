/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:10:14 by mikim             #+#    #+#             */
/*   Updated: 2018/04/23 18:20:30 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#include "customerListType.h"
#include <fstream>

bool	readFile(customerListType	&list)
{
	fstream			f("cusDat.txt");
	customerType	customer;

	if (!f)
		return false;
	while (f)
	{
		string	first = "", last = "";
		int		n = 0;

		f >> first >> last >> n;
		if (first.empty())
			break ;
		customer = customerType(first, last, n);
		list.insertLast(customer);
	}
	return true;
}

int		main()
{
	customerListType	list;

	cout << "Loading data file..." << endl;
	if (!readFile(list))
	{
		cout << "Error" << endl;
		return (0);
	}
	cout << endl << "--- Customer List ---" << endl;
	list.customerList();

	cout << endl << "--- Search by Name ---" << endl;
	cout << "Mickey: " << endl;
	if (list.searchByName("Mickey"))
		cout << "Found" << endl;
	else
		cout << "Not Found" << endl;
	cout << "Disney: " << endl;
	if (list.searchByName("Disney"))
		cout << "Found" << endl;
	else
		cout << "Not Found" << endl;

	cout << endl << "--- Rent ---" << endl;
	cout << "Account No.2 | DVD title: Disney" << endl;
	cout << "Renting a DVD..." << endl;
	list.rented(2, "Disney");
	list.customerList();

	cout << endl << "--- test2 ---" << endl;
	cout << "Account No.2 | DVD title: Disneyi Part. 2" << endl;
	cout << "Renting a DVD..." << endl;
	list.rented(2, "Disney");
	list.customerList();

	cout << endl << "--- Return ---" << endl;
	cout << "Account No.2" << endl;
	cout << "Returning a DVD..." << endl;
	list.returned(2);
	list.customerList();

	cout << endl << "--- test2 ---" << endl;
	cout << "Account No.2" << endl;
	cout << "Returning a DVD..." << endl;
	list.returned(2);
	list.customerList();
}
