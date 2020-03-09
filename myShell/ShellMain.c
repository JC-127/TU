//Program will simulate a linux shell.

//INCLUSIIONS
#include <stdio.h>
#include <stdlib.h>

//these two probably wont be necessary, but i added them just in case
#include <string.h>
#include <ctype.h>

//Header Inclusion
#include "myShellHeader.h"

//cant get it to work
//#define TRUE == 1;
//#define FALSE == 0;

//MAIN 
//these are not really conditions,
//its really arguements but the term arg seemed redundant and overused
int main(int stringFile, char *condition1, char **condition2)
{
	//reminder for myself, in C 0 is false and 1 is true
	//int WaitingForCommand = true;
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

int IfFileIsBatch(int tempStr, char* tempString1)
{
	//for this to be a batch file, the amount of arguments it needs to has is 2
	if (tempStr == 2 && (strstr (tempString1, ".txt") != NULL) )
	{
		//its a batch file, return true.
		printf("File is a batch file!\n");
		//return true;
		return 1; //return true

	}//end if()

	else 
	{
		//return false
		//return false;
		return 0;
	}

}//end IfFileIsBatch()

void BatchExecute(int tempStr, char* tempString1[], char** tempString2, char* tempString3) 
{

	FILE* myFile;
	myFile = fopen(tempString1[1], "r");

	//self Explanatory
	if (myFile == NULL) 
	{
		printf("Error: File not found!\n");
		printf("Exiting...\n");
		exit(0);
	}//end if()

	else 
	{
		char str;
		int ix = 0;

		//while its reading and it is does not equal the end of file
		while ( (str = getchar() ) != EOF) 
		{
			//while string does not detect a next line 
			while (str != '\n')
			{
				//the position of the tempString3 at index IX is equal to the character STR
				tempString3[ix] = str;
				ix++;
			}//end while()

			//read if there is a command in the string that the user inputted			
			ReadingCommand(tempStr, tempString1, tempString2, tempString3);
			
			//reset the index of the array to the first place holder
			//reset the str to get the next character if there is one 
			//this is for the next time it will be used
			ix = 0;
			str = getchar();

		}//end while()
	
	}//end else()

	//close the file
	fclose(myFile);

}//end Batch Execute

void ReadingCommand(int tempString1, char* condtion1[], char** condition2, char* tempString2)
{

}//end ReadingCommand

void InternalCommand(char* tempStr) 
{
	char* inCom[] = { "cd", "clr", "dir", "environ", "echo", "help", "pause", "quit" };
	int index = 0;
	char* scan; //this is going to be used to check if the command is contained in the string

	while (index < 0)
	{
		scan = strstr(inCom[index], tempStr);

		if (scan != NULL)
		{
			//remind that true is 1 and false is 0
			return 1;

		}//end if()

		index++;

	}//end while()

	return 0;

}//end InternalCommand()

void CurrentDirectoryCommand()
{

}//end CurrentDirectoryCommand

void ChangeDirectoryCommand() 
{

}//end ChangeDirectoryCommand()

void HelpCommand(char* tempString) 
{

	FILE* myFile;
	myFile = fopen(".txt", "r");

	//if the file cant be opened or does not exist, print an error message
	if (myFile == NULL)
	{
	
		printf("Error: File does not exist or can't be opened...\n");
		exit(0);

	}//end if()

	else
	{
		char tempStr;
		
		while ( (tempStr = fgetc(myFile) ) != EOF)
		{
			printf("%c", tempStr);
		}//end while()

	}//end else()

	fclose(myFile);

}//end HelpCommand()

int IfCurrentlyInCommand() 
{

}//end IfCurrentlyInCommand




