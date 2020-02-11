/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myCreate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:01:12 by mikim             #+#    #+#             */
/*   Updated: 2018/03/09 10:35:34 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#include <lab.h>

bool	myCreate(MyStack &stack, size_t size)
{
	stack.buf = new Fragment[size];
	if (!stack.buf)
		return (false);
	stack.size = size;
	stack.sp = 0;
	return (true);
}

#ifdef UNIT_TEST

TEST_CASE("Stack Create")
{
	MyStack stack;

	REQUIRE(myCreate(stack, 10));
	myDestroy(stack);

	REQUIRE(myCreate(stack, 1));
	myDestroy(stack);

	REQUIRE(myCreate(stack, 100));
	myDestroy(stack);

	REQUIRE(myCreate(stack, 1000));
	myDestroy(stack);
}

#endif
