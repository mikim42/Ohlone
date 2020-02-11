/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bankAccountImp.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:43:17 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/03/04 17:43:22 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#include <iostream>
#include <iomanip>
#include "bankAccount.h"

using namespace std;

bankAccount::bankAccount(int acctNumber, double bal) 
{	//	constructor
	this->accountNumber = acctNumber;
	this->balance = bal;
}

void bankAccount::setAccountNumber(int acct) 
{	//	mutator - setter
	this->accountNumber = acct;
}

int bankAccount::getAccountNumber() const
{	//	accessor - getter
	return this->accountNumber;
}

double bankAccount::getBalance() const
{	//	accessor - getter
	return this->balance;
}

void bankAccount::withdraw(double amount)
{	//	mutator
	this->balance -= amount;
}

void bankAccount::deposit(double amount)
{	//	mutator
	this->balance += amount;
}

void bankAccount::print() const
{
	cout << "The account Number: " << this->accountNumber << endl
		 << "The balance: " << this->balance << endl;
}
