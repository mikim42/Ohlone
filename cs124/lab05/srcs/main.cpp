/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:50:37 by mikim             #+#    #+#             */
/*   Updated: 2018/05/05 07:41:40 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                              Mingyun Kim   */
/*                                           https://www.github.com/mikim42   */
/* ************************************************************************** */

#include <lab.h>

void	cb_login(Fl_Widget *widget, void *data);
void	cb_findId(Fl_Widget *widget, void *data);
void	cb_findPass(Fl_Widget *widget, void *data);
void	cb_signUp(Fl_Widget *widget, void *data);
void	cb_send(Fl_Widget *widget, void *data);
void	cb_unread(Fl_Widget *widget, void *data);
void	cb_inbox(Fl_Widget *widget, void *data);
void	window_login(void);
void	window_user(void);

WINDOW	win;
SysOp	sysOp;
User	user;

int		main(void)
{
	fstream	users("data/users");
	window_login();
	win.W_main->show();
	Fl::run();
	return (0);
}

void	window_login(void)
{
	win.W_main = new Fl_Double_Window(WIDTH, HEIGHT, "eMail");
	win.B_login = new Fl_Button(WIDTH * 3 / 5, HEIGHT / 6,
									WIDTH / 3, HEIGHT / 4, "LOGIN");
	win.I_loginId = new Fl_Input(WIDTH / 5, HEIGHT / 6,
									WIDTH / 3, HEIGHT / 9, "ID ");
	win.I_loginPass = new Fl_Secret_Input(WIDTH / 5, HEIGHT / 3,
											WIDTH / 3, HEIGHT / 9, "PASSWORD ");
	win.B_findId = new Fl_Button(WIDTH / 5, HEIGHT / 2,
									WIDTH / 3, HEIGHT / 9, "Find ID");
	win.B_findPass = new Fl_Button(WIDTH * 3 / 5, HEIGHT / 2,
										WIDTH / 3, HEIGHT / 9, "Find Password");
	win.B_signUp = new Fl_Button(WIDTH / 5, HEIGHT * 5 / 8,
									WIDTH / 3, HEIGHT / 9, "Sigh Up");
	win.B_login->callback(cb_login, 0);
	win.B_findId->callback(cb_findId, 0);
	win.B_findPass->callback(cb_findPass, 0);
	win.B_signUp->callback(cb_signUp, 0);
}

void	cb_login(Fl_Widget *widget, void *data)
{
	if (sysOp.login(win.I_loginId->value(), win.I_loginPass->value()))
	{
		user.login = win.I_loginId->value();
		window_user();
	}
	else
		fl_alert("Failed to login: %s", win.I_loginId->value());


	std::cout << "login callback" << std::endl;
}

void	window_user(void)
{
	win.W_user = new Fl_Double_Window(WIDTH, HEIGHT, "eMail");
	win.B_send = new Fl_Button(WIDTH / 8, HEIGHT / 10,
									WIDTH / 3, HEIGHT / 4, "SEND");
	win.B_unread = new Fl_Button(WIDTH / 8, HEIGHT * 4 / 10,
									WIDTH / 3, HEIGHT / 4, "UNREAD");
	win.B_inbox = new Fl_Button(WIDTH / 8, HEIGHT * 7 / 10,
									WIDTH / 3, HEIGHT / 4, "INBOX");
	win.B_send->callback(cb_send, 0);
	win.B_unread->callback(cb_unread, 0);
	win.B_inbox->callback(cb_inbox, 0);
	win.W_user->show();
}

void	cb_findId(Fl_Widget *widget, void *data)
{


	std::cout << "find ID callback" << std::endl;
}

void	cb_findPass(Fl_Widget *widget, void *data)
{


	std::cout << "find Pass callback" << std::endl;
}

void	cb_signUp(Fl_Widget *widget, void *data)
{


	std::cout << "sign up callback" << std::endl;
}

void	cb_send(Fl_Widget *widget, void *data)
{
	Message	*tmp;

	std::cout << "send callback" << std::endl;
}

void	cb_unread(Fl_Widget *widget, void *data)
{


	std::cout << "unread callback" << std::endl;
}

void	cb_inbox(Fl_Widget *widget, void *data)
{


	std::cout << "inbox callback" << std::endl;
}
