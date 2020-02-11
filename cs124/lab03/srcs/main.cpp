/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:37:59 by mikim             #+#    #+#             */
/*   Updated: 2018/03/09 10:08:24 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#ifndef UNIT_TEST

# include <lab.h>

bool	configInput(int ac, char **av, vector<string> &abcVector, string &song);

int		main(int ac, char **av)
{
	vector<string>	abcVector;
	string			song;

	if (!configInput(ac, av, abcVector, song))
		return (0);

	vector<Note>	soxVector(abcVector.size());

	convertABCtoSOX(abcVector, soxVector);
	system(("abcm2ps -E " + song).c_str());
	system("display -alpha off Out001.eps &");
	playSong(soxVector);
	system("pkill -9 display");
	return (0);
}

bool	configInput(int ac, char **av, vector<string> &abcVector, string &song)
{
	bool	ret;

	if (ac == 1)
	{
		cout << "Enter the path to abc file: ";
		getline(cin, song);
		ret = readABCfile(song, abcVector);
	}
	else if (ac == 2)
		ret = readABCfile((song = av[1]), abcVector);
	else
	{
		cerr << "Argument Error" << endl;
		ret = false;
	}
	if (!ret)
		cerr << "Error opening file" << endl;;
	return ret;
}

#endif
