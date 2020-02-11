/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readABCfile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:38:03 by mikim             #+#    #+#             */
/*   Updated: 2018/03/09 10:02:19 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#include <lab.h>

double	TEMPO = 0.25;
void	getTempo(string s);

bool	readABCfile(string fileName, vector<string> &v)
{
	ifstream	ifs(fileName);
	bool		ret = true, k = false;

	if (ifs)
	{
		string	s;

		while (!k)
		{
			getline(ifs, s);
			if (s[0] == 'L')
				getTempo(s);
			if (s == "K:C")
				k = true;
		}
		while (ifs >> s)
			v.push_back(s);
	}
	else
		ret = false;
	return ret;
}

void	getTempo(string s)
{
	double	n;
	double	d;

	n = atoi(strchr(s.c_str(), ':') + 1);
	d = atoi(strchr(s.c_str(), '/') + 1);
	n /= d;
	TEMPO /= n;
}
