# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mkimarray.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+         #
#    GitHub:  https://github.com/mikim42          +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 10:21:17 by Mingyun K         #+#    #+#              #
#    Updated: 2018/03/02 17:45:16 by Mingyun K        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME:		Mingyun Kim
#PURPOSE:	Counting letters in strings

#INPUT:		Strings	
#			Letter to find

#OUTPUT:	Each / total counts of the letters (consonant / vowel / unique)

#VARIABLES:
#DATA SECTION
.data
.equ	len1, (. - str1)	# The length of str1

str1: .ascii "Assembly Language is fun"
str2: .ascii "Chocolate is delicious"
.equ	len2, (. - str2)	# The length of str2

search:		.byte 'c'		# Keyword for consonant

consonant:	.long 0			# Counter for consonant
vowel_a:	.long 0			# Counter for vowel a
vowel_e:	.long 0			# Counter for vowel e
vowel_i:	.long 0			# Counter for vowel i
vowel_o:	.long 0			# Counter for vowel o
vowel_u:	.long 0			# Counter for vowel u
unique:		.long 0			# Counter for unique

total_cons:	.long 0			# Total consonant
total_a:	.long 0			# Total vowel a
total_e:	.long 0			# Total vowel e
total_i:	.long 0			# Total vowel i
total_o:	.long 0			# Total vowel o
total_u:	.long 0			# Total vowel u
total_uniq:	.long 0			# Counter for unique in str1 and str2

strings:	.long 1			# Number of strings (start from 0)

.bss						# size: 4 byte * 26 letters
.lcomm counter1, (4 * 26)	# To store the number of counts for string 1
.lcomm counter2, (4 * 26)	# To store the number of counts for string 2

#INSTRUCTION SECTION
.text
.globl _start
_start:
	cmp $1, strings				# Check which string need to search
	je _string1					# If equal, jump to string 1
	jmp _string2				# If not, jump to string 2

_string1:
	lea counter1, %edi			# Store the address of counter to EDI
	lea str1, %esi				# Store the address of str to ESI
	movl $len1, %ecx			# Move the length of the string to ECX
								# It will loop 'the length' times
	jmp _count					# Start loop

_string2:
	movl $0, unique				# Reset unique counter
	lea counter2, %edi			# Store the address of counter to EDI
	lea str2, %esi				# Store the address of str to ESI
	movl $len2, %ecx			# Move the length of the string to ECX
								# It will loop 'the length' times

_count:
	movl %ecx, %edx				# Using EDX as index
	decl %edx					# This program will traverse the
								# string backward (end >> 0)
								# Since the index starts from 0 and
								# EDX starts from the length, decrease 1
	movb (%esi, %edx, 1), %al	# Move the letter index of EDX to AL
								# Need to use al since a letter is one byte
	or $32, %al					# Change the letter to lowercase
	cmp $'a', %al				# Check if the letter is between 'a' and 'z'
	jb _countLoop				# If not, jump to where loop commnad is
	cmp $'z', %al
	ja _countLoop
	sub $97, %al				# 97 is the ascii number of 'a'
								# AL will be 0 if it was 'a' and now I can
								# use it as index for the array 'counter'
	incl (%edi, %eax, 4)		# Increase the value in the index of counter
	# After this, it will run	# If the letter was 'a', it will increase
	# the loop command below 	# first one (index 0) and so on
_countLoop:
	loop _count					# It will loop until ECX gets 0

_getConsonant:
	movb search, %al			# Take the letter in search
	or $32, %al					# Change it to lowercase
	sub $97, %al				# subtract 97 to use as index
	movl (%edi, %eax, 4), %ebx	# Take the count in counter array
	movl %ebx, consonant		# Since index reference is a memory access,
								# I need to move the value through a register
	addl %ebx, total_cons		# Add the result to total

_getVowel:
	movl $0, %ebx				# Clear EBX first, will be used as sum of counts
	movl 0(%edi), %ebx			# Add the count of 'a'
	movl %ebx, vowel_a			# Move the sum to vowel
	addl %ebx, total_a			# Add the result to total
	movl 16(%edi), %ebx			# Add the count of 'e'
	movl %ebx, vowel_e			# Move the sum to vowel
	addl %ebx, total_e			# Add the result to total
	movl 32(%edi), %ebx			# Add the count of 'i'
	movl %ebx, vowel_i			# Move the sum to vowel
	addl %ebx, total_i			# Add the result to total
	movl 56(%edi), %ebx			# Add the count of 'o'
	movl %ebx, vowel_o			# Move the sum to vowel
	addl %ebx, total_o			# Add the result to total
	movl 80(%edi), %ebx			# Add the count of 'u'
	movl %ebx, vowel_u			# Move the sum to vowel
	addl %ebx, total_u			# Add the result to total

_getUnique:
	movl $26, %ecx				# Using ECX as loop counter

_getUniqueLoop:
	movl %ecx, %edx				# Using EDX as index
	decl %edx					# The same reason with _count
	cmp $0, (%edi, %edx, 4)		# If it is above 0, the string has at least one
								# letter of this index
	je _endGetUniqueLoop		# If it is 0, skip the operations
	incl unique					# Increase unique

_endGetUniqueLoop:
	loop _getUniqueLoop

_theOtherStr:
								# Debugging break point line 140
	cmp $0, strings				# Check if there is more strings to search
	je _getTotalUnique			# If left is 0, jump to _getTotalUnique
	decl strings				# Decrease string count
	jmp _start					# Start again

_getTotalUnique:
	lea counter1, %esi			# Using ESI and EDI to acceess the two results
	lea counter2, %edi			# and count the total unique letters
	movl $26, %ecx				# Using ECS as loop counter

_getTotalUniqueLoop:
	movl %ecx, %edx				# Using EDX as index
	decl %edx					# The same reason with _count
	cmp $0, (%esi, %edx, 4)		# If it is above 0, the string has at least one
	ja _countTotalUnique		# letter of this index, so jump to count label
	cmp $0, (%edi, %edx, 4)		# Same for str2
	ja _countTotalUnique 
	jmp _endGetTotalUniqueLoop	# If there is no letters in the index of EDX,
								# Jump to the end of this loop

_countTotalUnique:
	incl total_uniq				# Increase the count and loop again

_endGetTotalUniqueLoop:
	loop _getTotalUniqueLoop

_end:
	
					# Debugging break point line 169
	mov $1, %eax	# Set system call to exit
	mov $0, %ebx	# Set error code to 0
	int $0x80		# Inturrupt eax to call 'exit'
.end
#END OF PROGRAM for Mingyun Kim's Lab 4 program
