/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:37:27 by mikim             #+#    #+#             */
/*   Updated: 2018/03/09 10:38:04 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#ifndef LAB_H
# define LAB_H

# include <iostream>
# include <fstream>
# include <catch.hpp>
# include <vector>
# include <string>
# include <cstring>
# include <abc.h>

# define MAX_FRAGMENT 255

using namespace std;

extern double	TEMPO;

struct			Note
{
	string		tone;
	float		duration;
	string		frag;
};

struct			Fragment
{
	int			st;
	int			end;
};

struct			MyStack
{
	int			size;
	Fragment	*buf;
	int			sp;
};


/*
**		ABC Play functions
*/

bool	readABCfile(string fileName, vector<string> &v);
void	playSong(const vector<Note> &soxVector);
void	convertABCtoSOX(const vector<string> &abc, vector<Note> &sox);
string	createPlayCmd(const Note &n);

/*
**		Stack functions
*/

bool	myCreate(MyStack &stack, size_t size);
bool	myPush(MyStack &stack, Fragment item);
bool	myPop(MyStack &stack, Fragment &item);
void	myDestroy(MyStack &stack);

#endif
