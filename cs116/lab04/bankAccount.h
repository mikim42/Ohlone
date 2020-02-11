/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bankAccount.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:43:15 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/03/04 17:43:20 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#ifndef H_bankAccount 
#define H_bankAccount

class bankAccount
{
public:
    void setAccountNumber(int acct);
    int getAccountNumber() const;
    double getBalance() const; 
    void withdraw(double amount);
    void deposit(double amount);
    void print() const;
    bankAccount(int acctNumber = -1, double bal = 0);

protected:
    int accountNumber;
    double balance;
};

#endif
