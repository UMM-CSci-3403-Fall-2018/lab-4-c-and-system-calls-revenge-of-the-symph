#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  char *line;
  size_t size;
  
  FILE *readFile;
  FILE *writeFile;

  
  if(argc == 1){
	  size = 100;
	  line = (char*) malloc (size + 1);
  
	  while (getline(&line, &size, stdin) > 0) {
	    char* output = disemvowel(line, sizeof(line)/sizeof(char));
	    printf("%s\n", output);
	    free(output);
  	}
  	free(line);

  } else if(argc == 2) {
	  readFile = fopen(argv[1], "r");

	  char* readOutput = (char* )calloc(BUF_SIZE, sizeof(char));
          int lastReadSize = fread(readOutput, sizeof(char), BUF_SIZE, readFile);
         
          while(lastReadSize != 0){
                  char* disemvowledFile = disemvowel(readOutput, lastReadSize);
		  printf("%s\n", disemvowledFile);
		  lastReadSize = fread(readOutput, sizeof(char), BUF_SIZE, readFile);
          }

	  free(readOutput);
          fclose(readFile);
  } else {
	  readFile = fopen(argv[1], "r");
	  writeFile = fopen(argv[2], "w");

	  char* readOutput = (char *)calloc(BUF_SIZE, sizeof(char));
	  int lastReadSize = fread(readOutput, sizeof(char), BUF_SIZE, readFile);

	  while(lastReadSize != 0){
		  char* disemvowledFile = disemvowel(readOutput, lastReadSize);
		  fwrite(disemvowledFile, 1024, 1, writeFile);
		  lastReadSize = fread(readOutput, sizeof(char), BUF_SIZE, readFile);
	  }

	  free(readOutput);
	  fclose(readFile);
	  fclose(writeFile);
  }
	  

}
