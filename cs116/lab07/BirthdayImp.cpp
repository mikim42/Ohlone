/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BirthdayImp.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 12:56:08 by mikim             #+#    #+#             */
/*   Updated: 2018/04/08 13:53:29 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

# include "Birthday.h"

// constructor
Birthday::Birthday(void)
{
}

// destructor
Birthday::~Birthday(void)
{
}

// setters
void	Birthday::setYear(int year)
{	// sets the year. throw an error when it's a negative number
	if (year < 0)
		throw Birthday::WrongDateException();
	else
		_year = year;
}

void	Birthday::setMonth(int month)
{	// sets the month. throw an error when it's not a proper month
	_month = month;
	switch (month)
	{
		case 1:
			_monthLetter = "Jan";
			break ;
		case 2:
			_monthLetter = "Feb";
			break ;
		case 3:
			_monthLetter = "Mar";
			break ;
		case 4:
			_monthLetter = "Apr";
			break ;
		case 5:
			_monthLetter = "May";
			break ;
		case 6:
			_monthLetter = "Jun";
			break ;
		case 7:
			_monthLetter = "Jul";
			break ;
		case 8:
			_monthLetter = "Aug";
			break ;
		case 9:
			_monthLetter = "Sep";
			break ;
		case 10:
			_monthLetter = "Oct";
			break ;
		case 11:
			_monthLetter = "Nov";
			break ;
		case 12:
			_monthLetter = "Dec";
			break ;
		default:
			throw Birthday::WrongDateException();
			break ;
	}
}

void	Birthday::setDay(int day)
{	// sets the day. throw an error when it's not a proper day
	if (_month == 1 || _month == 3 || _month == 5 || _month == 7 ||
		_month == 8 || _month == 10 || _month == 12)
	{
		if (day < 0 || 31 < day)
			throw Birthday::WrongDateException();
		else
			_day = day;
	}
	else if (_month == 4 || _month == 6 ||
			_month == 9 || _month == 11)
	{
		if (day < 0 || 30 < day)
			throw Birthday::WrongDateException();
		else
			_day = day;
	}
	else if (_month == 2)
	{
		if (Birthday::checkLeap(_year))
		{
			if (day < 0 || 29 < day)
				throw Birthday::WrongDateException();
			else
				_day = day;
		}
		else
		{
			if (day < 0 || 28 < day)
				throw Birthday::WrongDateException();
			else
				_day = day;
		}
	}
	else
		throw Birthday::WrongDateException();
}

// getters
int		Birthday::getYear(void)
{
	return _year;
}

string	Birthday::getMonth(void)
{
	return _monthLetter;
}

int		Birthday::getDay(void)
{
	return _day;
}

bool	Birthday::checkLeap(int year)
{	// check leap year
	if (year < 0)
		throw Birthday::WrongDateException();
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return true;
		}
	}
	return false;
}

Birthday::WrongDateException::WrongDateException(void)
{
}

Birthday::WrongDateException::~WrongDateException(void) throw()
{
}

const char	*Birthday::WrongDateException::what() const throw()
{
	return "Error: Wrong date";
}

ostream		&operator<<(ostream &o, Birthday &rhs)
{
	o << "Birth Day: ";
	o << rhs.getMonth() << " " << rhs.getDay() << ", " << rhs.getYear();
	return o;
}
