#simple make file
#author: Marion Baumgartner

#=====================================================================================================================================
#basic consept of a make file:
#   a target (usually a file)
#   the dependencies (files which the target depends on)
#   and commands to run, based on the target and dependencies.
#
#	<target>: [ <dependency > ]*		dependency line->determine when to rebuild target (left) depends on the source (right)
#		[ <TAB> <command> <endl> ]+ 
#   backslash followed by a newline to indicate a continuing line.
#=====================================================================================================================================

#use of MACROD:
#	<macro_name> = <macro_string>
#Anithing with of the form $(<macro_name>) or ${<macro_name>} is replaced by <macro_string>
#comon macros in C++
#
#    CC		The name of the compiler
#    DEBUG 	The debugging flag. This is -g in both g++ and cxx. The purpose of the flag is to include debugging information into the executable, #		so that you can use utilities such as gdb to debug the code.
#    LFLAGS 	The flags used in linking. As it turns out, you don't need any special flags for linking. The option listed is "-Wall" which tells #		the compiler to print all warnings. But that's fine. We can use that.
#    CFLAGS 	The flags used in compiling and creating object files. This includes both "-Wall" and "-c". The "-c" option is needed to create #		object files, i.e. .o files. 

OBJS = hellomake.o hellofunc.o
CC=g++ #compiler to use
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

#creates the macro DEPS, which is the set of .h files on which the .c files depend. Then we define a rule that applies to all files ending in the .o #suffix. The rule says that the .o file depends upon the .c version of the file and the .h files included in the DEPS macro

all: hello.exe

#create executable with the first target
hello.exe: $(OBJS)
	$(CC) $(OBJS) -o run

hellomake.o: hellomake.c hellofunc.o
	$(CC) $(CFLAGS) hellomake.c

hellofunc.o: hellofunc.c hellomake.h
	$(CC) $(CFLAGS) hellofunc.c


#a file depends on all of the .h files which are includes in it  (#include "...") and the files wich are in cluded in the .h files on which the .c file depends.-> can be difficult
#to solve this write
#	Vector.h: Foo.h (no target is needed) :=> THis means that Vector.h depends on Foo.h


clean:
	\rm *.o run

tar:
	tar cfv task.tar hellomake.c hellofunc.c hellomake.h

