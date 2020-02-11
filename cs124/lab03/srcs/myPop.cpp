/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myPop.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:06:50 by mikim             #+#    #+#             */
/*   Updated: 2018/03/09 11:30:41 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#include <lab.h>

bool	myPop(MyStack &stack, Fragment &item)
{
	if (stack.sp == 0)
		return (false);
	item = stack.buf[--stack.sp];
	return (true);
}

#ifdef UNIT_TEST

TEST_CASE("Stack Pop")
{
	MyStack 	stack;
	Fragment	item;
	Fragment	res;

	myCreate(stack, 2);

	item.st = 10; item.end = 15;
	myPush(stack, item);
	item.st = 20; item.end = 25;
	myPush(stack, item);
	
	REQUIRE(myPop(stack, res));
	REQUIRE((res.st == 20 && res.end == 25));

	REQUIRE(myPop(stack, res));
	REQUIRE((res.st == 10 && res.end == 15));

	REQUIRE_FALSE(myPop(stack, res));
	myDestroy(stack);
}

#endif
