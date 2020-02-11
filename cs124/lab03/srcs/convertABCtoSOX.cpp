/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertABCtoSOX.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:00:26 by mikim             #+#    #+#             */
/*   Updated: 2018/03/09 11:10:25 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#include <lab.h>

void	convertABCtoSOX(const vector<string> &abc, vector<Note> &sox)
{
	for (size_t i = 0; i < abc.size(); i++)
	{
		if (abcToSox_fragment.find(abc[i]) != abcToSox_fragment.end())
		{
			sox[i].tone = "";
			sox[i].duration = 0;
			sox[i].frag = abcToSox_fragment[abc[i]];
			continue ;
		}
		size_t j = 0;
		if ((abc[i][j] >= 'A' && abc[i][j] <= 'G') ||
			(abc[i][j] >= 'a' && abc[i][j] <= 'g'))
		{
			sox[i].tone += abc[i][j++];
			if (abc[i][j] == ',' || abc[i][j] == '\'')
			{
				sox[i].tone += (abc[i][j] == ',') ? "3" : " 6";
				j++;
			}
			else
				sox[i].tone += sox[i].tone[0] < 97 ? "4" : "5";
			if (abc[i][j] == '/')
				sox[i].duration = 1.0 / atoi(&abc[i][j + 1]); 
			else
				sox[i].duration = atoi(&abc[i][j]);
			sox[i].duration == 0 ? sox[i].duration = 1 : 0;
			sox[i].tone[0] &= -33;
			sox[i].frag = "";
		}
	}
}
