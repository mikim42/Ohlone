/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Birthday.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 12:41:43 by mikim             #+#    #+#             */
/*   Updated: 2018/04/08 13:43:03 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#ifndef BIRTHDAY_H
# define BIRTHDAY_H

# include <iostream>

using namespace std;

class	Birthday
{
	public:
		// constructor and destructor
		Birthday(void);
		~Birthday(void);

		// exception class
		class WrongDateException : public std::exception
		{
			public:
				WrongDateException(void);
				virtual ~WrongDateException(void) throw();

				virtual const char *what() const throw();
		};
		// setters and getters
		void	setYear(int year);
		void	setMonth(int month);
		void	setDay(int day);
		int		getYear(void);
		string	getMonth(void);
		int		getDay(void);
		bool	checkLeap(int year);

	private:
		// variables
		int		_year;
		int		_month;
		string	_monthLetter;
		int		_day;
};

ostream		&operator<<(ostream &o, Birthday &rhs);

#endif
