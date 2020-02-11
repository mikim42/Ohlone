/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playSong.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:56:59 by mikim             #+#    #+#             */
/*   Updated: 2018/03/09 10:40:35 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#include <lab.h>

void	playSong(const vector<Note> &soxVector)
{
	MyStack	myStack;
	Fragment frag;
	size_t	curr = 0;
	size_t	tmp;
	size_t	end = soxVector.size() - 1;

	if (!myCreate(myStack, MAX_FRAGMENT))
	{
		cerr << "Failed to create stack." << endl;
		exit(0);
	}
	while (true)
	{
		if (!soxVector[curr].tone.empty() && curr < end)
			system(createPlayCmd(soxVector[curr++]).c_str());
		else if (!soxVector[curr].frag.empty() && curr < end)
		{
			if (soxVector[curr].frag == "REPEAT_BEGIN")
				tmp = ++curr;
			else if ((soxVector[curr].frag == "REPEAT_END") ||
				(soxVector[curr].frag == "REPEAT_BOTH"))
			{
				frag.st = curr + 1;
				frag.end = end;
				end = curr;
				curr = tmp;
				myPush(myStack, frag);
				if (soxVector[frag.st - 1].frag == "REPEAT_BOTH")
					tmp = frag.st;
			}
			else
				curr++;
		}
		else if (curr == end)
		{
			Fragment	frag_tmp;

			if (myPop(myStack, frag_tmp))
			{
				curr = frag_tmp.st;
				end = frag_tmp.end;
			}
			else
				break ;
		}
	}
}
