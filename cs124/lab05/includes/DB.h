/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DB.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:17:51 by mikim             #+#    #+#             */
/*   Updated: 2018/05/05 06:17:21 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#ifndef DB_H
# define DB_H

# include <lab.h>

class	Message
{
	public:
		Message(void);
		Message(std::string subject, std::string msg, std::string to,
				std::string from);
		~Message(void);

		void	setSubject(std::string subject);
		void	setMsg(std::string msg);
		void	setTo(std::string to);
		void	setFrom(std::string from);

		std::string	getSubject(void);
		std::string	getMsg(void);
		std::string	getTo(void);
		std::string	getFrom(void);

		bool	operator==(const Message &rhs) const;

	private:
		std::string	_subject;
		std::string	_msg;
		std::string	_to;
		std::string	_from;
};

Message::Message(void)
{
}

Message::Message(std::string subject, std::string msg, std::string to,
				std::string from) : _subject(subject), _msg(msg), _to(to), 
				_from(from)
{
}

Message::~Message(void)
{
}

void	Message::setSubject(std::string subject)
{
	_subject = subject;
}

void	Message::setMsg(std::string msg)
{
	_msg = msg;
}

void	Message::setTo(std::string to)
{
	_to = to;
}

void	Message::setFrom(std::string from)
{
	_from = from;
}

std::string	Message::getSubject(void)
{
	return (_subject);
}

std::string	Message::getMsg(void)
{
	return (_msg);
}

std::string	Message::getTo(void)
{
	return (_to);
}

std::string	Message::getFrom(void)
{
	return (_from);
}

bool	Message::operator==(const Message &rhs) const
{
	return (_subject == rhs._subject && _msg == rhs._msg &&
			_to == rhs._to && _from == rhs._from);
}

class	Account
{
	public:
		Account(void);
		Account(std::string login);
		Account(std::string login, std::string name, std::string passwd,
				std::string passQ, std::string passA, size_t bill);
		~Account(void);

		void	setName(std::string name);
		void	setPasswd(std::string passwd);
		void	setPassQ(std::string passQ);
		void	setPassA(std::string passA);
		void	setBill(size_t bill);

		std::string	getLogin(void);
		std::string	getName(void);
		std::string	getPasswd(void);
		std::string	getPassQ(void);
		std::string	getPassA(void);
		size_t		getBill(void);

		bool	operator==(const Account &rhs) const;
		bool	operator<(const Account &rhs) const;

	private:
		std::string			_login;
		std::string			_name;
		std::string			_passwd;
		std::string			_passQ;
		std::string			_passA;
		size_t				_bill;
		LLQueue<Message>	_unread;
		LList<Message>		_inbox;
};

Account::Account(void)
{
}

Account::Account(std::string login) : _login(login)
{
}

Account::Account(std::string login, std::string name, std::string passwd,
				std::string passQ, std::string passA, size_t bill) :
				_login(login), _name(name), _passwd(passwd), _passQ(passQ),
				_passA(passA), _bill(bill)
{
}

Account::~Account(void)
{
}

void	Account::setName(std::string name)
{
	_name = name;
}

void	Account::setPasswd(std::string passwd)
{
	_passwd = passwd;
}

void	Account::setPassQ(std::string passQ)
{
	_passQ = passQ;
}

void	Account::setPassA(std::string passA)
{
	_passA = passA;
}

void	Account::setBill(size_t bill)
{
	_bill = bill;
}

std::string	Account::getLogin(void)
{
	return _login;
}

std::string	Account::getName(void)
{
	return _name;
}

std::string	Account::getPasswd(void)
{
	return _passwd;
}

std::string	Account::getPassQ(void)
{
	return _passQ;
}

std::string	Account::getPassA(void)
{
	return _passA;
}

size_t		Account::getBill(void)
{
	return _bill;
}

bool	Account::operator==(const Account &rhs) const
{
	return (_login == rhs._login);
}

bool	Account::operator<(const Account &rhs) const
{
	return (_login < rhs._login);
}

#endif
