#ifndef myShellHeader
#define myShellHeader

//prototypes for the functions that will be in the main
//if i do separate c files for all of these, it will be too many
int IfFileIsBatch(char* stringFile, int position);
void BatchExecute(int position, char** envp, char* argv[], char* stringFile);
void ReadingCommand(int argc, char** envp, char* argv[], char* stringFile);
void InternalCommand(int command, char* stringFuke, char** envp);
void CurrentDirectoryCommand(char* stringFile); //this is dir
void ChangeDirectoryCommand(char* stringFile); //this is cd
void HelpCommand(char* stringFile); //this is help 
int isInCommand(char* stringFile);

enum Commands
{
	cd, clr, dir, env, echo, help, paus, quit
} internalCommand;

enum directives
{
	inputRed, outputRed
};



#endif