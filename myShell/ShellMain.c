//Program will simulate a linux shell.

//INCLUSIIONS
#include <stdio.h>
#include <stdlib.h>

//these two probably wont be necessary, but i added them just in case
#include <string.h>
#include <ctype.h>

//Header Inclusion
#include "myShellHeader.h"

//MAIN 
//these are not really conditions,
//its really arguements but the term arg seemed redundant and overused
int main(int stringFile, char *condition1, char **condition2)
{
	//reminder for myself, in C 0 is false and 1 is true
	int WaitingForCommand = 1; //this has to be true at first

	char string1[150] = ""; //Empty character array initially
	

	while (WaitingForCommand) 
	{
		if ( IfFileIsBatch(string1, stringFile) )  
		{
			//if file is a batch then a function called "BatchExecute" will be called
			BatchExecute(stringFile, condition1, condition2, string1);
			exit(0);
		}//end if()

		ReadingCommand(stringFile, condition1, condition2, string1);

	}//end while
	
}//end main()

/*************************************************************************************************************************************************/
//FUNCTIONS

int IfFileIsBatch() 
{

}//end IfFileIsBatch()

void BatchExecute() 
{

}//end Batch Execute

void ReadingCommand()
{

}//end ReadingCommand

void InternalCommand() 
{

}//end InternalCommand()

void CurrentDirectoryCommand()
{

}//end CurrentDirectoryCommand

void ChangeDirectoryCommand() 
{

}//end ChangeDirectoryCommand()

void HelpCommand() 
{

}//end HelpCommand()

int IfCurrentlyInCommand() 
{

}//end IfCurrentlyInCommand




