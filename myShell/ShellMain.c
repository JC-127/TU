//Program will simulate a linux shell.

//INCLUSIIONS
#include <stdio.h>
#include <stdlib.h>

//these probably wont be necessary, but i added them just in case
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <errno.h>

//these headers are in linux but not in MSVS
#include <dirent.h>
#include <unistd.h>

//Header Inclusion
#include "myShellHeader.h"

//cant get it to work
//#define TRUE == 1;
//#define FALSE == 0;

int WaitingForCommand = 1; //this has to be true at first

//MAIN 
//these are not really conditions,
//its really arguements but the term arg seemed redundant and overused
int main(int stringFile, char *condition1, char **condition2)
{
	//reminder for myself, in C 0 is false and 1 is true
	//int WaitingForCommand = true;

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

int IfFileIsBatch(char* stringBatchFile, int BatchPosition)
{
	//for this to be a batch file, the amount of arguments it needs to has is 2
	if (BatchPosition == 2 && (strstr (stringBatchFile, ".txt") != NULL) )
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

void BatchExecute(int BEPosition, char* BECondition1[], char** BECondition2, char* BEstringFile) 
{

	FILE* myFile;
	myFile = fopen(BECondition1[1], "r");

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
				BEstringFile[ix] = str;
				ix++;
			}//end while()

			//read if there is a command in the string that the user inputted			
			ReadingCommand(BEPosition, BECondition1, BECondition2, BEstringFile);
			
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

//ERROR could be here
void ReadingCommand(int ReadPosition, char* ReadCondtion1[], char** ReadCondition2, char* ReadStringFile)
{

	char *line = ReadStringFile;
	char* inCom[] = { "cd", "clr", "dir", "environ", "echo", "help", "pause", "quit" }; //8 elements in the array
	int index = 0;
	
	printf("%c ", getcwd(ReadStringFile, 150) ); 

	fgets(ReadStringFile, 150, stdin);
	
	if( (line = strchr(ReadStringFile,'\n') ) ) 
	{
		*line = '\0';
	}//end if()

	fflush(stdout);
	
	while (index < 8) 
	{
	
		if (strstr( ReadStringFile, inCom[index]) != NULL) 
		{
		
			ExecuteInCommand(ReadCondition2, index, ReadStringFile);
			return;
		
		}//end if()
		
		index++;

	}//end while()
	
	if (strstr(inCom[index - 1], ReadStringFile) == NULL)
	{
		puts("Error: invalid command!");
	}//end if()
		
}//end ReadingCommand

void ExecuteInternalCommand(int ICPosition, char* ICStringFile, char** ICCondition)
{

	cmd = ICPosition;

	switch (cmd) 
	{
		
	case cd: 
		ChangeDirectoryCommand(ICStringFile);
		break;

	case clr:
		printf("\033[H\033[2J");
		break;

	case dir:
		CurrentDirectoryCommand(ICStringFile);
		break;

	case env:
		while (*ICCondition)
		{
			print("%s\n", *ICCondition++);
			break;
		}//end while()

	case echo:;
		int index = 5;

		for(index = 5; index <strlen(ICStringFile); index++) 
		{
			printf("%c", ICStringFile[index]);
		}//end for()

		puts("");
		break;

	case help:
		HelpCommand(ICStringFile);
		break;

	case paus:;

		char c;

		scanf("%c", &c);

		while (c != '\n') 
		{
			c = getchar();
		}//end while()

		break;
		
	case quit:
		WaitingForCommand = 0;
		exit(0);
		break;
		
	}//end switch
	
}//end IfCurrentlyInCommand

//ISSUES HERE BECAUSE OF MSVS LIBRARY AND LINUX LIBRARY CONFLICTIONS
void CurrentDirectoryCommand(char* CDir)
{
	//this will be the character that will be stored in "dir" and sees if it matches "dir in the text file
	char* CurrDir = strstr(CDir, "dir");

	int index1 = 0, index2 = 0, condition = 0;

	//will compare the dir from the command manual in the textfile and the char pointer str
	while (index1 < strlen(CurrDir) - 1) 
	{
		char searchBlank = CurrDir[index1];
		char searchNonBlank = CurrDir[index2];

		if ( isspace(searchBlank) && !isspace(searchNonBlank) ) 
		{
			condition++;
		}//end if()

		index1++;
		index2++;

	}//end while()

	index1 = 0, index2 = 4;
	
	if (condition == 1) 
	{
		while ( CDir[index1] != '\0' )
		{
			CurrDir[index1] = CDir[index2];
			index1++;
			index2++;

		}//end while()

		struct dirent* DirEntry;
		
		DIR *dirdir;

		dirdir = opendir(".");

		if (dirdir == NULL) 
		{
			printf("Directory DNE or Not Found! %s\n", dir);
		}//end if()

		else 
		{
			while ( (DirEntry = readdir(dridir) != NULL ) 
			{
				printf("%s ", DirEntry->d_name);
			}//end while()

			puts("");
			closedir(dirdir);

		}//end else()

	}//end if()

	else 
	{
		printf("Directory is taking one condition...\n");
	}//end else()


}//end CurrentDirectoryCommand

//Issues here because of MSVS and Linux Library Conflications
void ChangeDirectoryCommand(char* CDStringFile) 
{
	char* dirFileName = CDStringFile;
	char* dirSearch = CDStringFile;

	dirFileName = strstr(CDStringFile, "Cd"); //cd in the original string file
	dirSearch = strstr(CDStringFile, "cd"); //cd in the original string file

	int condition = 0, index1 = 0, index2 = 1;
	//index 2 is the space behind the character, thats why it is initialized to 1.

	while ( index1 < strlen(dirSearch) - 2 ) 
	{
		char space = dirSearch[index1];
		char nonSpace = dirSearch[index2];

		if ( isspace(space) && !isspace(nonSpace) ) 
		{
			condition++;
		}//end if()

		index1++;
		index2++;
		
	}//end while()

	char NewDir[150];

	if(condition == 1) 
	{
		index1 = 0;
		index2 = 3; //this is after cd

		while (index2 < strlen(dirFileName) && !isspace(dirFileName[index2] ) ) 
		{
			NewDir[index1] = dirFileName[index2];
			index1++;
			index2++;
		}//end while()

		NewDir[index1] = '\0';

	}//end if()

	if (condition > 1) 
	{
		printf("Error: More than one agruement...\n");
	}//end if()

	else 
	{
		DIR* dir = opendir(NewDir);

		if (dir) 
		{
			chdir(NewDir);
		}//end if()

		else if (condition == 0) 
		{
			chrdir(".");
			return;
		}//end else if()

		else if ( (!IfInternalCommand(NewDir) ) || (ENOENT == errno) )  
		{
			printf("Error: Directory %s is invalid or does not exist!\n", NewDir);
		}//end elseif()

		else 
		{
			printf("Error: Could not open directory!\n");
			exit(0);
		}//end else()

	}//end else()


}//end ChangeDirectoryCommand()

//textfile of help commands will be found here.
void HelpCommand(char* HelpStringFile) 
{

	FILE* myFile;
	myFile = fopen("manual.txt", "r");

	//if the file cant be opened or does not exist, print an error message
	if (myFile == NULL)
	{
	
		printf("Error: File does not exist or can't be opened...\n");
		exit(0);

	}//end if()

	else
	{
		char HelptempStr;
		
		while ( (HelptempStr = fgetc(myFile) ) != EOF)
		{
			printf("%c", HelptempStr);
		}//end while()

	}//end else()

	fclose(myFile);
T
}//end HelpCommand()

int IfInCommand(char* IfInComStrFile)
{

	char* inCom[] = { "cd", "clr", "dir", "env", "echo", "help", "pause", "quit" };
	int index = 0;
	char* scan; //this is going to be used to check if the command is contained in the string

	while (index < 0)
	{
		scan = strstr(inCom[index], IfInComStrFile);

		if (scan != NULL)
		{
			//remind that true is 1 and false is 0
			return 1;

		}//end if()

		index++;

	}//end while()

	return 0;

}//end InternalCommand()
