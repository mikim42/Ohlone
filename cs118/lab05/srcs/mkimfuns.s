# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mkimfuns.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/28 12:36:07 by mikim             #+#    #+#              #
#    Updated: 2018/03/30 16:53:58 by mikim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                               Mingyun Kim    #
#                                            https://www.github.com/mikim42    #
# **************************************************************************** #

#NAME:		Mingyun Kim
#PURPOSE:	Counting letters in strings using string instructions and functions

#INPUT:		Strings
#			Letter to find

#OUTPUT:	Each / total counts of the letters (consonant / unique)

#VARIABLES:
#DATA SECTION
.data
str1:
	.ascii "ygbclAjumqzioAYNmwvsp"
	.equ	len1, (. - str1)	# The length of str1
str2:
	.ascii "mgfNtwzpkIqTipZUgTzlV"
	.equ	len2, (. - str2)	# The length of str2

search1:	.byte 'm'
search2:	.byte 'i'
search3:	.byte 'n'

consA1:		.long 0		# consonant counter for search1 in str1
consB1:		.long 0		# consonant counter for search1 in str2
consA2:		.long 0		# consonant counter for search2 in str1
consB2:		.long 0		# consonant counter for search2 in str2
consA3:		.long 0		# consonant counter for search3 in str1
consB3:		.long 0		# consonant counter for search3 in str2
totalCons1:	.long 0		# total consonant for search1
totalCons2:	.long 0		# total consonant for search2
totalCons3:	.long 0		# total consonant for search3
uniq1:		.long 0		# unique counter for str1
uniq2:		.long 0		# unique counter for str2
totalUniq:	.long 0		# total unique

#INSTRUCTION SECTION
.text
.globl	_start
_start:
	pushl	$len2				# pushes str2 and len2. these two variables
	pushl	$str2				# will stay here until the end because it will
								# be used again and again
	pushl	$len1				# pushes str1 and len1
	pushl	$str1				#
	calll	_toLower			# calls toLower function

	addl	$8, %esp			# moves esp to str2
	calll	_toLower			# calls toLower function

	xor		%eax, %eax			# clears EAX
	movb	search1, %al		# moves search1 to AL

	pushl	$len1				# pushes str1 and len1
	pushl	$str1				#
	calll	_countConsonant		# calls conuntConsonant function
	movl	%ebx, consA1		# stores the result
	movl	%ebx, totalCons1	# moves the result to total

	addl	$8, %esp			# moves esp to str2
	calll	_countConsonant		# calls conuntConsonant function
	movl	%ebx, consB1		# stores the result
	addl	%ebx, totalCons1	# adds the result to total

	movb	search2, %al		# moves search2 to AL

	pushl	$len1				# pushes str1 and len1
	pushl	$str1				#
	calll	_countConsonant		# calls conuntConsonant function
	movl	%ebx, consA2		# stores the result
	movl	%ebx, totalCons2	# adds the result to total

	addl	$8, %esp			# moves esp to str2
	calll	_countConsonant		# calls conuntConsonant function
	movl	%ebx, consB2		# stores the result
	addl	%ebx, totalCons2	# adds the result to total

	movb	search3, %al		# moves search3 to AL

	pushl	$len1				# pushes str1 and len1
	pushl	$str1				#
	calll	_countConsonant		# calls conuntConsonant function
	movl	%ebx, consA3		# stores the result
	movl	%ebx, totalCons3	# adds the result to total

	addl	$8, %esp			# moves esp to str2
	calll	_countConsonant		# calls conuntConsonant function
	movl	%ebx, consB3		# stores the result
	addl	%ebx, totalCons3	# adds the result to total

	pushl	$len1				# pushes str1 and len1
	pushl	$str1				#
	calll	_countUniq			# calls countUniq function
	movl	%ebx, uniq1			# stores the result

	addl	$8, %esp			# moves esp to str2
	calll	_countUniq			# calls countUniq function
	movl	%ebx, uniq2			# stores the result

	movl	$len1, %ebx			# adds up the len of 2 strings so that
	addl	$len2, %ebx			# it can combine two strings
	pushl	%ebx				# pushes str1 and the total len
	pushl	$str1				#
	calll	_countUniq			# calls countUniq function
	movl	%ebx, totalUniq		# stores the result

_end:
	mov $1, %eax				# sets system call to exit
	mov $0, %ebx				# sets error code to 0
	int $0x80					# inturrupts eax to call 'exit'

# Function 1
_toLower:
	pushl	%ebp				# pushes the bp of caller
	movl	%esp, %ebp			# takes the bp of callee

	xor		%eax, %eax			# clears EAX
	movl	8(%ebp), %edi		# stores str to EDI
	movl	12(%ebp), %ecx		# moves length to ECX

	_toLowerLoop:
		or		$32, (%edi, %eax, 1)	# changes it to lower case
		inc		%eax					# increases index
		loop	_toLowerLoop			# repeat this loop

	popl	%ebp				# takes back the caller's bp
	retl						# return ;

# Function 2
_countConsonant:
	pushl	%ebp				# pushes the bp of caller
	movl	%esp, %ebp			# takes the bp of callee

	xor		%ebx, %ebx			# clears EBX
	movl	8(%ebp), %edi		# moves str to EDI
	movl	12(%ebp), %ecx		# moves len to ECX

	_consLoop:
		cld
		repne	scasb			# scans AL in EDI
		jne	_consExit			# if not found, exits this function
		inc		%ebx			# increases counter
		jmp	_consLoop			# keep scanning

	_consExit:
		popl	%ebp			# takes back the caller's bp
		retl					# return ;

# Function 3
_countUniq:
	pushl	%ebp				# pushes the bp of caller
	movl	%esp, %ebp			# takes the bp of callee

	movb	$'a', %al			# moves 'a' to AL
	xor		%ebx, %ebx			# clears EBX

	_uniqLoop:
		movl	8(%ebp), %edi	# moves str to EDI
		movl	12(%ebp), %ecx	# moves len to ECX
		cld
		repne	scasb			# scans AL in EDI
		jne		_uniqNext		# if not found, skips counting
		inc		%ebx			# increases counter

	_uniqNext:
		inc		%eax			# increases EAX (next letter)
		cmp		$123, %al		# check if AL hit the end
		jb		_uniqLoop

	popl	%ebp				# takes back the caller's bp
	retl						# return ;

.end
#END OF PROGRAM for Mingyun Kim's Lab 5 program
