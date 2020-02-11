/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createPlayCmd.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:14:52 by mikim             #+#    #+#             */
/*   Updated: 2018/03/09 09:47:49 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#include <lab.h>

string	createPlayCmd(const Note &n)
{
	return
	(
		"play -n synth " + to_string(n.duration) + " pluck " +
		n.tone + " tempo " + to_string(TEMPO)
	);
}
