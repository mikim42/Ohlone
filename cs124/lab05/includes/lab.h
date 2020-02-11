/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:17:07 by mikim             #+#    #+#             */
/*   Updated: 2018/05/05 07:34:58 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#ifndef	LAB_H
# define LAB_H

# include <iostream>
# include <fstream>
# include <vector>
# include <list>
# include <ctime>
# include <cstdlib>

# include <FL/Fl.H>
# include <FL/Fl_Window.H>
# include <FL/Fl_Double_Window.H>
# include <FL/Fl_Button.H>
# include <FL/Fl_Input.H>
# include <FL/Fl_Secret_Input.H>
# include <FL/Fl_Text_Display.H>
# include <FL/fl_ask.H>

# include <llist.h>
# include <llqueue.h>
# include <btree.h>
# include <DB.h>
# include <User.h>

const int		WIDTH = 600;
const int		HEIGHT = 400;

const double	PRICE = 0.20;

using namespace std;

class	SysOp
{
	public:
		SysOp(void);
		~SysOp(void);

		bool	login(std::string login, std::string passwd);

	private:
		Btree<Account>	_account;
		LList<Message>	_unread;
		LList<Message>	_inbox;
};

SysOp::SysOp(void)
{
	fstream	users("data/users");
	fstream	unread("data/unread");
	fstream	inbox("data/inbox");

	if (users)
	{
		Account		*newAccount;
		std::string	buf;

		while (getline(users, buf))
		{
			if (buf.empty())
				continue ;
			std::string	loginId = buf.substr(0, buf.find(">\t<"));
			buf.erase(0, buf.find(">\t<") + 3);
			std::string	name = buf.substr(0, buf.find(">\t<"));
			buf.erase(0, buf.find(">\t<") + 3);
			std::string	passwd = buf.substr(0, buf.find(">\t<"));
			buf.erase(0, buf.find(">\t<") + 3);
			std::string	passQ = buf.substr(0, buf.find(">\t<"));
			buf.erase(0, buf.find(">\t<") + 3);
			std::string	passA = buf.substr(0, buf.find(">\t<"));
			buf.erase(0, buf.find(">\t<") + 3);
			size_t		bill = atoi(buf.substr(0, buf.find(">\t<")).c_str());
			newAccount = new Account(loginId, name, passwd, passQ, passA, bill);
			_account.insert(newAccount);
		}
	}
	if (unread)
	{
		Message		*newMessage;
		std::string	buf;

		while (getline(unread, buf))
		{
			if (buf.empty())
				continue ;
			std::string	subject = buf.substr(0, buf.find(">\t<"));
			buf.erase(0, buf.find(">\t<") + 3);
			std::string	msg = buf.substr(0, buf.find(">\t<"));
			buf.erase(0, buf.find(">\t<") + 3);
			std::string	to = buf.substr(0, buf.find(">\t<"));
			buf.erase(0, buf.find(">\t<") + 3);
			std::string	from = buf.substr(0, buf.find(">\t<"));
			newMessage = new Message(subject, msg, to, from);
			_unread.insert(newMessage);
		}
	}
	if (inbox)
	{
	}
	std::cout << "SysOp constructor" << std::endl;
}

SysOp::~SysOp(void)
{
	fstream	users("data/users", fstream::out | fstream::trunc);
	fstream	unread("data/unread", fstream::out | fstream::trunc);
	fstream	inbox("data/inbox", fstream::out | fstream::trunc);

	if (users)
	{
		Account	*tmp;
		while ((tmp = _account.pop()))
		{
			users << tmp->getLogin() << ">\t<" << tmp->getName() << ">\t<" <<
				tmp->getPasswd() << ">\t<" << tmp->getPassQ() << ">\t<" <<
				tmp->getPassA() << ">\t<" << tmp->getBill() << std::endl;
			_account.remove(tmp);
		}
	}
	if (unread)
	{
		Message	*tmp;
		while ((tmp = _unread.pop()))
		{
			unread << tmp->getSubject() << ">\t<" << tmp->getMsg() << ">\t<" <<
				tmp->getTo() << ">\t<" << tmp->getFrom() << std::endl;
			_unread.remove(tmp);
		}

	}
	if (inbox)
	{
	}
	std::cout << "SysOp destructor" << std::endl;
}

bool	SysOp::login(std::string login, std::string passwd)
{
	Account	tmp(login);
	Account	*res;

	res = _account.search(&tmp);
	if (!res || res->getPasswd() != passwd)
		return false;
	return true;
}

struct	WINDOW
{
	Fl_Double_Window	*W_main;
	Fl_Button			*B_login;
	Fl_Input			*I_loginId;
	Fl_Secret_Input		*I_loginPass;
	Fl_Button			*B_findId;
	Fl_Button			*B_findPass;
	Fl_Button			*B_signUp;

	Fl_Double_Window	*W_user;
	Fl_Button			*B_unread;
	Fl_Button			*B_inbox;
	Fl_Button			*B_send;

	Fl_Double_Window	*W_unread;
	Fl_Text_Display		*T_unreadMsg;

//	Fl_Double_Window	*W_findId;

//	Fl_Double_Window	*W_findPass;
};

/*
	int choice = ft_choice(msg1, msg2, msg3, 2);
	switch(choice){
		case:
	}

	Fl_Text_Display		*text;
		msg = new Fl_Text_Display(x, y, w, h);

	Fl_Text_Buffer		*msgBuf;
		msgBuf = new Fl_Text_Buffer();
		msg->buffer(msgBuf);
		msgBuf->text("Hello");
};
*/

extern WINDOW	win;
extern SysOp	sysOp;

#endif
