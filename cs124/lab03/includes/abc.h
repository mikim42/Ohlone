/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:37:15 by mikim             #+#    #+#             */
/*   Updated: 2018/03/08 17:49:31 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#ifndef ABC_H
# define ABC_H

/*
**	<Associative array>
**
**	Examples:
**	ABC: C, C  c  c' | C2    | C/2
**	SOX: C3 C4 C5 C6 | 2 sec | half sec
**
**	You can get sox notation following:
**	sox = abcToSox[abc];
**	it will get the corresponding notation
*/

# include <map>

typedef std::map<std::string, std::string> abc_t;
extern abc_t	abcToSox;
extern abc_t	abcToSox_fragment;

#endif
