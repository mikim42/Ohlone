/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savingsAccountImp.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:43:45 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/03/04 17:43:46 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#include <iostream>
#include <iomanip>
#include "savingsAccount.h"
  
using namespace std; 

savingsAccount::savingsAccount(int acctNumber, double bal, double intRate)
       :bankAccount(acctNumber, bal)
{	//	constructor
	this->interestRate = intRate;
}

double savingsAccount::getInterestRate() const
{	//	accessor - getter
	return this->interestRate;
}

void savingsAccount::setInterestRate(double rate)
{	//	accessor - mutator
	this->interestRate = rate;
}

void savingsAccount::withdraw(double amount)
{
	this->balance -= amount;
}

void savingsAccount::postInterest()
{
	cout << "Interest Rate: " << this->interestRate << endl;
}

void savingsAccount::print() const
{
	cout << "The account Number: " << this->accountNumber << endl
		 << "Balance: " << this->balance << endl
		 << "Interest Rate: " << this->interestRate << endl;
}
