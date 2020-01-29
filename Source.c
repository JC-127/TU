/*MAIN FILE THAT WILL CALL ALL THE FILES LISTED BELOW
1. wcat.c
2. wgrep.c
3. wzip.c & wunzip.c will be one file called wzipwunzip.c
*/

//INCLUSIONS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	//function will be called to read and print the text file for the user
	wcat();

	//function will be called to look for the specified term for the user and print the line number
	wgrep();

	//function will be called to compress a string input from user
	//unzip is also in this file
	wzipwunzip();

}//end main()


