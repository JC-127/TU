#ifndef myShellHeader
#define myShellHeader

//prototypes for the functions that will be in the main
//if i do separate c files for all of these, it will be too many
int IfFileIsBatch(char* stringFile, int position);
void BatchExecute(int position, char* condition1[], char** condition2, char* stringFile);
void ReadingCommand(int position, char* condition1[], char** condition2, char* stringFile);
void InternalCommand(int command, char* stringFile, char** condition2);
void CurrentDirectoryCommand(char* stringFile); //this is dir
void ChangeDirectoryCommand(char* stringFile); //this is cd
void HelpCommand(char* stringFile); //this is help 
int IfCurrentlyInCommand(char* stringFile);

enum Commands
{
	cd, clr, dir, env, echo, help, paus, quit
} internalCommand;

enum directives
{
	RedirectedInput, RedirectedOutput
};



#endif
