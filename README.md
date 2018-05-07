-----

### Copyrigth (C) 2018 by Lukoyanova Tatyana - Company of Nizhniy Novgorod

-----


####     Repository for the Final Assignment of Introduction to Embedded
####     Systems Software and Development Environments Course.


-----
 
####  Use: make [TARGET_NAME] [PLATFORM] [COURSE] [VERBOSE=yes]
 
* PLATFORM  -  The target platform ( HOST(default) , MSP432 )
* TARGET_NAME  -  The name .out file (default c1final.out)
* COURSE  -  The assignment selection 
    * COURSE1(default) - final assignment
    * C1M1 - week 1 assignment
    * C1M2 - week 2 assignment
* VERBOSE=yes    Enable debug printing

######  Build Targets:
* {FILE}.i - Build preprocessed file
* {FILE}.asm - Build assembly file
* {FILE}.o - Build object file 
* compile-all - Compile all object files
* build - Compile and link c1final.out
* clean - Remove all generated files
 
-----
