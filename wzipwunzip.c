//file will compress the file that the user has selected (CASE SENSITIVE)

//INCLUSIONS
#include <stdlib.h>
#include <stdio.h>

//VARIABLES
char str[100], cur;
int ctr, i;

int wzip() 
{
	printf("Input a string:\n");
	gets(str); //another way of getting user input

	//We will hardcode that the 1st letter is the current index so the count is 1
	cur = str[0];
	ctr = 1;

	//this will read the string input and keep reading until the end of the string
	for (i = 1; str[i] != '\0'; i++)
	{
		//if there is a character in the index at the current position, 
		//increase the counter by 1
		if (str[i] == cur)
		{
			ctr++;
		}//end if()
		
		//self explanatory
		else 
		{
			printf("%c%d", cur, ctr);
			cur = str[i];
			ctr = 1;
		}//end else()
		
	}//end for()

	printf("%c%d", cur, ctr);

	//THIS will decompress the user input.
	
	for (i = '\0'; str[i] != 1; i--)
	{

		if (str[i] == cur)
		{
			ctr--;
		}//end if()

		else
		{//file will compress the file that the user has selected (CASE SENSITIVE)

//INCLUSIONS
#include <stdlib.h>
#include <stdio.h>

//VARIABLES
			char str[100], cur;
			int ctr, i;

			int wzip()
			{
				printf("Input a string:\n");
				gets(str); //another way of getting user input

				//We will hardcode that the 1st letter is the current index so the count is 1
				cur = str[0];
				ctr = 1;

				//this will read the string input and keep reading until the end of the string
				for (i = 1; str[i] != '\0'; i++)
				{
					//if there is a character in the index at the current position, 
					//increase the counter by 1
					if (str[i] == cur)
					{
						ctr++;
					}//end if()

					//self explanatory
					else
					{
						printf("%c%d", cur, ctr);
						cur = str[i];
						ctr = 1;
					}//end else()

				}//end for()

				printf("%c%d", cur, ctr);

				//THIS will decompress the user input.

				for (i = '\0'; str[i] != 1; i--)
				{

					if (str[i] == cur)
					{
						ctr--;
					}//end if()

					else
					{

						printf("%c%d", cur, ctr);
						cur = str[i];
						ctr = '\0';

					}//end else()

				}//end for()

				printf("%c%d", cur, ctr);

			}//end wzipwunzip()

			printf("%c%d", cur, ctr);
			cur = str[i];
			ctr = '\0';
			
		}//end else()

	}//end for()
	
	printf("%c%d", cur, ctr);
	
}//end wzipwunzip()