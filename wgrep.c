//file will look for specified term that user inputs (NOT CASE SENSITIVE)

//INCLUSIONS
#//INCLUSIONS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

//VARIABLES
char fName[MAX_SIZE];
char str[MAX_SIZE];
char word[MAX_SIZE];

FILE *fp;

int i, j, found;
int strLen, wordLen;


int wgrep()
{

	//hardcoded address  
	fName == "C:\Users\jcmer\source\Archangels.txt";
	printf("Fetching File...\n");

	//Try to open file and read it
	//if read then write
	fp = fopen(fName, "r");
	fp = fopen("C:\Users\jcmer\source", "w+");

	//if file can not be opened or does not exist then exit 
	if (fp == NULL)
	{
		printf("Error: Unable to open file or file DNE!.\n");
		exit(0);
	}//end if()

	else
	{

		strLen = strlen(fp);  //length of the string
		wordLen = strlen(word); //length of word 

		fgets(str, MAX_SIZE, fp);
		printf("Enter input to search: ");
		scanf("%s", word);


		//Run a loop from starting index of string to
		//length of string - word length

		for (i = 0; i < strLen - wordLen; i++)
		{
			// Match word at current position
			found = 1;
			for (j = 0; j < wordLen; j++)
			{
				// If word is not matched
				if (str[i + j] != word[j])
				{
					found = 0;
					printf("Input not found...");
					break;
				}//end if()

			}//end for()

			// If word have been found then print found message
			if (found == 1)
			{
				printf("%s found \n at index: %d \n", word, i);
			}//end if()

		}//end for()

	}//end else()
	
	return 0;

	/*
	//ATTEMPT 3
	else
	{

		words == (fp, "w");

		//Input a word, or character to search in the text file
		printf("\n\nEnter word to search in file: ");
		scanf("%s", term);

		//loop through text file
		for (count = 0; count < strlen(words); count++)
		{
			getc(words);
			if (words[count] == term)
			{
				printf("\n '%c' is Found at Position %d ", term, count + 1);
			}//end if()

			else
			{
				printf("Error: Term is not in text file");
			}//end else()

		}//end for()

	}//end else()

	*/

	/*

		ATTEMPT 2

		else
		{
			// Find index of word in fp by calling a function
			indexOf(fp, term, &line, &col);

			if (line != -1)
			{
				printf("'%s' found at line: %d, col: %d\n", term, line + 1, col + 1);
			}//end if()
			else
			{
				printf("'%s' does not exists.", term);
			}//end else

		}//end else()

		// Close file
		fclose(fp);

		return 0;
	}//end wgrep()

	//FUNCTION
	//Finds, first index of a word in given file. First index is represented
	// using line and column.
int indexOf(FILE *fptr, const char *word, int *line, int *col)
{
	char str[1000];
	char *pos;

	*line = -1;
	*col = -1;

	while ((fgets(str, 1000, fptr)) != NULL)
	{
		*line += 1;

		// Find first occurrence of word in str
		pos = strstr(str, word);

		if (pos != NULL)
		{
			// First index of word in str is
			// Memory address of pos - memory
			// address of str.
			*col = (pos - str);
			break;
		}//end if()


	}//end while()


	// If word is not found then set line index to -1
	if (*col == -1)
	{
		*line = -1;
	}//end if()

		return *col;

		*/

	/*

			ATTEMPT 1

			NextChar = fgetc(fp);
			while (NextChar != EOF)
			{

				if (term == NextChar)
				{
					printf("The Location was found at line %d", index );
				}//end if()

				else
				{
					printf("Error: Location can not be found\n");
					exit(0);
				}//end else


			}//end while()

			fclose("C:\Users\jcmer\source\Archangels.txt");
			return 0;
			*/

	/*
					Reference Code from previous project I did
					Used the logic and manipulated it for this purpose

					int index = 0;
					*h == term;

					for (NULL; *h != '\0'; h++)
					{
						index++;

						if (*h == *n)
						{
							printf("First occurrence was found at %s, %d ", h, index);

							int y = malloc(sizeof(int));
							y = h;
							return y;
						}//end if()
					}//end for()
					printf("NULL, first occurrence was not found...");

					int *z = malloc(sizeof(unsigned int));
					z = NULL;
					return z;

					*/

}//end wgrep()
