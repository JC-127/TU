//file will look for specified term that user inputs (NOT CASE SENSITIVE)

//INCLUSIONS
#//INCLUSIONS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//VARIABLES
char term[20], str[20], fName[50], words[50];
FILE *fp;
int count;

int wgrep()
{
	//hardcoded address  
	fName == "C:\Users\jcmer\source\Archangels.txt";

	gets(fName);
	printf("Fetching File...");

	//Try to open file and read it
	fp = fopen(fName, "r");

	//if file can not be opened or does not exist then exit 
	if (fp == NULL)
	{
		printf("Error: Unable to open file or file DNE!.\n");
		exit(0);
	}//end if()

	else
	{
		//Input a word, or character to search in the text file 
		printf("\n\nEnter word to search in file: ");
		scanf("%s", term);

		//loop through text file 
		for (count = 0; count < strlen(fp); count++)
		{
			getline();
			if (fp[count] == term)
			{
				printf("\n '%c' is Found at Position %d ", term, count + 1);
			}//end if()

			else
			{
				printf("Error: Term is not in text file");
			}//end else()

		}//end for()

	}//end else()

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
