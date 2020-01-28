/*MAIN FILE THAT WILL CALL ALL THE FILES LISTED BELOW
1. wcat.c
2. wgrep.c
3. wzipwunzip. (zip and unzip are cominbed)
*/

//INCLUSIONS
#include <stdlib.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

 
int main()
{
	//function will be called to read and print the text file for the user
	wcat();
	
	//fnction will be called to look for the specified term for the user and print the line number
	wgrep();
	
	//function will be called to compress and decompress a string from the user 
	wzipwunzip();
	
}//end main()


