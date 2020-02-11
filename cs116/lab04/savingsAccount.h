/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savingsAccount.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:43:56 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/03/04 17:44:03 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#ifndef H_savingsAccount
#define H_savingsAccount
   
#include "bankAccount.h"

const double DEFAULT_INTEREST_RATE_SAVINGS = 0.06;

class savingsAccount: public bankAccount
{ 
public:
    double getInterestRate() const;
    void setInterestRate(double rate);
    void withdraw(double amount);
    void postInterest();
    void print() const;
    savingsAccount(int acctNumber, double bal, 
                   double intRate = DEFAULT_INTEREST_RATE_SAVINGS);

protected:
    double interestRate;
};

#endif
