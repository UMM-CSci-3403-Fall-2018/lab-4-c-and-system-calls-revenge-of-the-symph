#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "disemvowel.h"

// Determines if a character is a vowel or not
bool isVowel(char letter) 
{
  // Look for capital and lowercase vowels
  switch(letter)
  {
    // All vowels
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return true;
      break;
    
    // Otherwise it isn't a vowel
    default:
      return false;
      break;
  }
}

//Counts the number of values the string
int countVowel(char *str)
{
  int count = 0;
  for(unsigned int i = 0; i < strlen(str); i++)
  {
    if(isVowel(str[i]))
    {
        count++;
    }
  }
  return count;
}

char *disemvowel(char *str)
{
	//COMPILING SHORTCUT
	// g++ -Wall -g -o disemvowel_test disemvowel_test.cpp disemvowel.c -lgtest
	// g++ -Wall -g -o main main.c disemvowel.c
	// valgrind --leak-check=full ./disemvowel_test
	// valgrind --leak-check=full ./main < sample_input.txt


	//Store length of string
	int old_string_length = strlen(str);
	
	//Test if string contains content
	if(old_string_length > 0)
	{
		//Determine amount of memory to allocate
		int old_string_vowels = countVowel(str);
		int new_string_length = old_string_length - old_string_vowels;
		char *result = (char*) calloc(new_string_length + 1, sizeof(char)); //Null terminator is NOT included in the size of a string.

		//Create pointer so we can 'append' letters to the end of our string
		int resultIndex = 0;

		//Start looking through all the letters of the old string to determine what characters we keep for the new string
		for (int i = 0; i < old_string_length; i++)
		{
			//Check to see if it is NOT a vowel
			if(!isVowel(str[i]))
			{
				//If it isn't, add it to the next spot in our string
				result[resultIndex] = str[i];
				resultIndex++;
			}
		}
		
		//All characters added, now finally add null terminator
		result[new_string_length] = '\0';
		return result; 
	}

	//String is empty, do nothing
	else
	{
		
		return str;
	}

}
