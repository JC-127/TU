/*This file will read a file that the user specifically inputs for (CASE SENSITIVE) 
and it will print the containing file for the user
*/

//INCLUSIONS
#include <stdlib.h>
#include <stdio.h>


//VARIABLES
char fName[50], NextChar;
//SName = "C:\Users\jcmer\source\Archangels.txt";
FILE *fp;
 
wcat()
{
	printf("Enter file name (CASE SENSITIVE): \n");
	scanf("%s", fName);

	//ATTEMPT 4
	
	//The filename for me is called Archangels.txt 
	//Located in C:\Users\jcmer\source\Archangels.txt and this will be inputted by the user
	fp = fopen(fName, "r"); 
		
	//self explanatory, if S*** hits the fan, it tells you
	if (fp == NULL)
	{
		printf("Error: File DNE or Invalid File Name!\n");
		exit(0);
	}//end if()

	//If it doesn't it will read the next character as long as the its not the end of the file 
	// and it prints it.
	else 
	{
		NextChar = fgetc(fp);
		while (NextChar != EOF) 
		{
			printf("%c", NextChar);
			NextChar = fgetc(fp);
		}//end while()

		fclose(fName);
		return 0;

	}//end else()

	//PREVIOUS ATTEMPTS BELOW

	/*
	//ATTEMPT 3

	fp = fopen(SName, "r"); // reads the file (its hardcoded to my machine)

	if (fp == NULL) //if it doesnt not exist or theres a typo...self explanatory
	{
		printf("Error: File DNE or Invalid file name...\n");
		exit(0);
	}//end if()

	else
	{
		while ((ch == fgetc(fp)) != EOF)
		{
			printf("%c", ch);
		}//end while()
		printf("%c\n", SName);
	}//end else()
	*/

	/*

	//ATTEMPT 2
	while ((ch == fgetc(fp)) != EOF)
	{
		printf("%c", ch);
		fclose(fp);
	}//edn while()
	*/
	 
	 /*
	 //ATTEMPT 1

	printf("Enter name of file (CASE SENSITIVE): \n");
	scanf("%s", &fName);

	if (&fName == tName || &fName != NULL) 
	{
	
		fopen(tName, "r");

		while (tName != '\0')
		{
				for (i = 0; i < Sfile; i++)
				getch();
		}//end while()

		Sfile[i] = '\0';
		return Sfile;
		
	}//end if()
	
	else 
	{
		printf("Error: File DNE\n");
		exit(0);

	}//end else
	*/

}//end wcat()
