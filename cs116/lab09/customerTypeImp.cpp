/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customerTypeImp.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:27:22 by mikim             #+#    #+#             */
/*   Updated: 2018/04/23 18:21:47 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#include "customerType.h"
  
customerType::customerType(void)
{
}

customerType::customerType(string fisrt, string last, int n) 
{	// constructor
	setCustomerInfo(fisrt, last, n);
}

customerType::~customerType() 
{	// destructor
}

void	customerType::setCustomerInfo(string first, string last, int n)
{	// setter for customer
	_firstname = first;
	_lastname = last;
	_accountNo = n;
	_rent = "";
}

void	customerType::rentDVD(string title)
{	// setter for rent
	if (_rent.empty())
		_rent = title;
	else
		cout << "This account already rented a DVD: " << _rent << endl;
}

void	customerType::returnDVD(void)
{	// returns the DVD
	if (_rent.empty())
		cout << "Nothing to return" << endl;
	else
	{
		cout << _rent << " has been returned" << endl;
		_rent = "";
	}
}

string	customerType::getFirstname(void) const
{	// getter for first name
	return _firstname;
}

string	customerType::getLastname(void) const
{	// getter for last name
	return _lastname;
}

int		customerType::getAccountNo(void) const
{	// getter for account number
	return _accountNo;
}

string	customerType::getRent(void) const
{	// getter for rent dvd
	if (_rent.empty())
		return "None";
	else
		return _rent;
}

customerType	&customerType::operator=(const customerType &rhs)
{	// operator overloading
	_firstname = rhs._firstname;
	_lastname = rhs._lastname;
	_accountNo = rhs._accountNo;
	_rent = rhs._rent;
	return *this;
}

bool	customerType::operator==(const customerType &rhs)
{	// operator overloading
	if (_firstname == rhs._firstname &&
		_lastname == rhs._lastname &&
		_accountNo == rhs._accountNo)
		return true;
	else
		return false;
}

ostream		&operator<<(ostream &o, const customerType &rhs)
{	// operator overloading for cout
	o << "[" << rhs.getAccountNo() << "] " <<
		rhs.getFirstname() << " " << rhs.getLastname() <<
		" | Rent: "<< rhs.getRent();
	return o;
}
