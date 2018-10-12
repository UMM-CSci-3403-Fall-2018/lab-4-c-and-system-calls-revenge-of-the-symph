#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "disemvowel.h"

#define BUF_SIZE 1024

bool is_vowel(char c) { 
//	printf("Entered is_vowel\n");
    switch(c) {
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

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
//	printf("Entered copy_non_vowels\n");
	int out_buf_index = 0;

	for( int i = 0; i < num_chars; i++) {
		if(!is_vowel(in_buf[i])){
				out_buf[out_buf_index] = in_buf[i];
				out_buf_index++;
		}
	}
	
	return out_buf_index;
}

void disemvowelFile(FILE* inputFile, FILE* outputFile) { 
    
//	printf("Entered disemvowel\n");
	//fopen(inputFile, "r");
	//fopen(outputFile, "w");

	char* in_buf = (char*)calloc(BUF_SIZE, sizeof(char));
	char* out_buf = (char*) calloc(BUF_SIZE, sizeof(char));
	
	int resultOfRead = fread(in_buf, sizeof(char), BUF_SIZE, inputFile);

	while(resultOfRead != 0){
//		printf("Entered while loop\n");
		int numNonVowels = copy_non_vowels(resultOfRead, in_buf, out_buf);
		fwrite(out_buf, sizeof(char), numNonVowels, outputFile);
		resultOfRead = fread(in_buf, sizeof(char), BUF_SIZE, inputFile);
	}

	fclose(inputFile);
	fclose(outputFile);
	free(in_buf);
	free(out_buf);
	/*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out. 
     */
}

int main(int argc, char *argv[]) { 
    FILE *inputFile; 
    FILE *outputFile;

    if(argc == 1) {
	   // printf("Setting up input output files\n");
	    char *line;
	    size_t size;
	    char *disemvoweled;

	    size = 100;
	    line = (char*) malloc(size + 1);
	    
	    while(getline(&line, &size, stdin) > 0){
		    disemvoweled = disemvowel(line);
		    printf("%s\n", disemvoweled);
		    free(disemvoweled);
	    }

	    free(line);

    }

    if(argc == 2) {
	    inputFile = fopen(argv[1], "r");
	    outputFile = stdout;
    }

    if(argc == 3) {
	    inputFile = fopen(argv[1], "r");
	    outputFile = fopen(argv[2], "w");
    }

  //  printf("Calling disemvowel\n");
    disemvowelFile(inputFile, outputFile);

    return 0; 
}

