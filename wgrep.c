//file will look for specified term that user inputs (NOT CASE SENSITIVE)

//INCLUSIONS
#//INCLUSIONS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//VARIABLES
char term[20], *h, *n;
FILE *fp;

int wgrep()
{
	
	printf("Enter a term to find: \n");
	scanf("%c", term);
	   
	fp = fopen("C:\Users\jcmer\source\Archangels.txt", "r");

	/*
	NextChar = fgetc(fp);
	while (NextChar != EOF)
	{
		

		if ()
		{
			printf("The Location was found at line %d", );
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
		
	int index = 0;
	*h == term;
	
	for (; *h != '\0'; h++)
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

}//end *ptr_to()