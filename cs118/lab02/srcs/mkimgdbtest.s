#NAME:		Mingyun Kim
#PURPOSE:	simple program to try out basic asm
#			and the Gnu Debugger (GDB)

#INPUT		NONE

#OUTPUT:	returns a status code which can be
#			checked by using gdb

#VARIABLES:	%eax holds the system call number
#			%ebx holds the return status

#DATA SECTION - NONE TO DECLARE
.data

#INSTRUCTION SECTION
.text
.globl _start

_start:
		mov $1, %eax	#this is the linux kernal command
						#to exit a program

		mov $0, %ebx	#

		int $0x80		#this sends an interrupt message to processor
						#to run as indicated by the value in eax

#END OF PROGRAM for Mingyun Kim's gdbtest lab program
