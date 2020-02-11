/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customerType.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:21:02 by mikim             #+#    #+#             */
/*   Updated: 2018/04/23 18:21:53 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#ifndef CUSTOMER_TYPE_H
# define CUSTOMER_TYPE_H

# include <iostream> 
# include <string>

using namespace std; 
  
class customerType
{
	friend ostream& operator<<(ostream&, const customerType&);

	public:
		customerType(void);
		customerType(string first, string last, int n);
		~customerType(void);
		void	setCustomerInfo(string fisrt, string last, int n);
		void	rentDVD(string title);
		void	returnDVD(void);
		string	getFirstname(void) const;
		string	getLastname(void) const;
		int		getAccountNo(void) const;
		string	getRent(void) const;

		customerType	&operator=(const customerType &rhs);
		bool	operator==(const customerType &rhs);

	private:
		string		_firstname;
		string		_lastname;
		int			_accountNo;
		string		_rent;
};

#endif 
