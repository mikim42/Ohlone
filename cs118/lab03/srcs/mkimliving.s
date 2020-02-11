# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mkimliving.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+         #
#    GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 11:52:39 by Mingyun K         #+#    #+#              #
#    Updated: 2018/02/13 09:14:53 by Mingyun K        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME:		Mingyun Kim
#PURPOSE:	a program to calculate annual living expenses

#INPUT:		Housing per month
#			Food and transportation (one amount) per week
#			Education cost per term
#			One annual miscellaneous cost for "incidentals"

#OUTPUT:	Total annual cost

#VARIABLES: 

#DATA SECTION
.data
week: 		.long 52
term:		.long 3
month:		.long 12
housing:	.long 1000
food_trans:	.long 350
edu:		.long 800
incidental:	.long 500
total:		.long 0

#INSTRUCTION SECTION
.text
.globl _start

_start:
	movl housing, %eax	# Move housing per month to eax
	imul month, %eax	# Multiplication instruction
	addl month, total	# Add the results

	movl food_trans, %eax	# Move food and transportation per week to eax
	imul week, %eax			# Multiplication instruction
	addl %eax, total		# Add the results

	movl edu, %eax		# Move education cost per term to eax
	imul term, %eax		# Multiplication instruction
	addl %eax, total	# Add the results

	movl total, %eax		# Move total to eax
	addl incidental, %eax	# Add instruction
	movl %eax, total		# Move the result

	mov $1, %eax	#Set system call to exit
	mov $0, %ebx	#Set error code to 0
	int $0x80		#Inturrupt eax to call 'exit'
.end
#END OF PROGRAM for Mingyun Kim's Lab 3 program

