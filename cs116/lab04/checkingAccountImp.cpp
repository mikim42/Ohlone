/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkingAccountImp.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:43:31 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/03/04 17:43:32 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#include <iostream>
#include <iomanip>
#include "checkingAccount.h"

using namespace std;

checkingAccount::checkingAccount(int acctNumber, double bal, 
                                 double minBal, double intRate, double servC)
               : bankAccount(acctNumber, bal) 
{
	this->minimumBalance = minBal;
	this->interestRate = intRate;
	this->serviceCharge = servC;
}

double checkingAccount::getMinimumBalance() const 
{	//	accessor - getter
	return this->minimumBalance;
}

void checkingAccount::setMinimumBalance(double minBalance)
{	//	mutator - setter
	this->minimumBalance = minBalance;
}

double checkingAccount::getInterestRate() const
{	//	accessor - getter
	return this->interestRate;
}

void checkingAccount::setInterestRate(double intRate)
{	//	mutator - setter
	this->interestRate = intRate;
}

double checkingAccount::getServiceCharge() const
{	//	accessor - getter
	return this->serviceCharge;
}

void checkingAccount::setServiceCharge(double servC)
{	//	mutator - setter
	this->serviceCharge = servC;
}

void checkingAccount::postInterest()
{
	cout << "Interest Rate: " << this->interestRate << endl;
}

bool checkingAccount::verifyMinimumumBalance(double amount)
{	//	I am confused. The purpose of this function is
	//	checking if the balance is less than minimum (according to the textbook)
	//	but I am not sure what is 'amount' for
	(void)amount;

	//	Return true if the balance is less than minimum balance.
	bool	ret = false;

	if (this->balance < this->minimumBalance)
		ret = true;
	return ret;
}

 void checkingAccount::writeCheck(double amount)
{
	this->balance -= amount;
}

void checkingAccount::withdraw(double amount)
{
	this->balance -= amount;
}

void checkingAccount::print() const
{
	cout << "The account number: " << this->accountNumber << endl
		 << "Balance: " << this->balance << endl
		 << "Interest Rate: " << this->interestRate << endl
		 << "Minimum Balance: " << this->minimumBalance << endl
		 << "Service Charges: " << this->serviceCharge << endl;
}
