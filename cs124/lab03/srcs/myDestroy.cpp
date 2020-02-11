/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myDestroy.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:07:08 by mikim             #+#    #+#             */
/*   Updated: 2018/03/09 10:58:27 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#include <lab.h>

void	myDestroy(MyStack &stack)
{
	delete stack.buf;
	stack.buf = NULL;
}

#ifdef UNIT_TEST

TEST_CASE("Stack Destroy")
{
	MyStack	stack;

	myCreate(stack, 10);
	myDestroy(stack);
	REQUIRE_FALSE(stack.buf);
}

#endif
