#ifndef myShellHeader
#define myShellHeader

//prototypes for the functions that will be in the main
//if i do separate c files for all of these, it will be too many
int IfFileIsBatch(char* stringBatchFile, int BatchPosition);
void BatchExecute(int BEPosition, char* BECondition1[], char** BECondition2, char* BEstringFile);
void ReadingCommand(int ReadPosition, char* ReadCondition1[], char** ReadCondition2, char* ReadStringFile);
void InternalCommand(int ICPosition, char* ICStringFile, char** ICCondition);
void CurrentDirectoryCommand(char* CDir); //this is dir
void ChangeDirectoryCommand(char* CDStringFile); //this is cd
void HelpCommand(char* HelpStringFile); //this is help 
int IfCurrentlyInCommand(char* IFCICstringFile);

enum Commands
{
	cd, clr, dir, env, echo, help, paus, quit
} internalCommand;

enum directives
{
	RedirectedInput, RedirectedOutput
};



#endif
