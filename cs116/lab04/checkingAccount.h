/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkingAccount.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:43:23 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/03/04 17:43:30 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#ifndef H_checkingAccount
#define H_checkingAccount
 
#include "bankAccount.h"

const double DEFAULT_INTEREST_RATE_CHECKING = 0.04;
const double DEFAULT_MIN_BALANCE = 500.00;
const double DEFAULT_SERVICE_CHARGE = 20;

class checkingAccount: public bankAccount 
{
public:
    double getMinimumBalance() const;
    void setMinimumBalance(double minBalance);
    double getInterestRate() const;
    void setInterestRate(double intRate);
    double getServiceCharge() const;
    void setServiceCharge(double intRate);
    void postInterest();
    bool verifyMinimumumBalance(double amount);
    void writeCheck(double amount);
    void withdraw(double amount);
    void print() const;

    checkingAccount(int acctNumber, double bal, 
                    double minBal = DEFAULT_MIN_BALANCE, 
                    double intRate = DEFAULT_INTEREST_RATE_CHECKING, 
                    double servC = DEFAULT_SERVICE_CHARGE);

protected:
    double interestRate;
    double minimumBalance;
    double serviceCharge;
};

#endif
