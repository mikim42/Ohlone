/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myPush.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:02:44 by mikim             #+#    #+#             */
/*   Updated: 2018/03/09 11:29:59 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#include <lab.h>

bool	myPush(MyStack &stack, Fragment item)
{
	if (stack.size == stack.sp)
		return (false);
	stack.buf[stack.sp++] = item;
	return (true);
}

#ifdef UNIT_TEST

TEST_CASE("Stack Push")
{
	MyStack 	stack;
	Fragment	item;

	myCreate(stack, 2);

	item.st = 10; item.end = 15;
	REQUIRE(myPush(stack, item));
	REQUIRE((stack.buf[0].st == 10 && stack.buf[0].end == 15));

	item.st = 20; item.end = 25;
	REQUIRE(myPush(stack, item));
	REQUIRE((stack.buf[1].st == 20 && stack.buf[1].end == 25));
	
	REQUIRE_FALSE(myPush(stack, item));
	myDestroy(stack);
}

#endif
