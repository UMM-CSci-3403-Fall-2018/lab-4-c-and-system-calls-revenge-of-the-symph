#include <ftw.h>
#include <stdlib.h>
#include <stdio.h>


static int regular_files;
static int directory_count;

static int callback(const char *fpath, const struct stat *sb, int typeflag){
	if(typeflag == FTW_F){
		regular_files++;
	} else if(typeflag == FTW_D){
		directory_count++;
	} else {
		printf("Something went wrong, we shouldn't be here");
		return -1;
	}

	return 0;
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv){

	if (argc != 2) {
    printf ("Usage: %s <path>\n", argv[0]);
    printf ("       where <path> is the file or root of the tree you want to summarize.\n");
    return 1;
  }
	directory_count = 0;
	regular_files = 0;

	ftw(argv[1], callback, MAX_FTW_DEPTH);

	printf("There were %d directories.\n", directory_count);
	printf("There were %d regular files.\n", regular_files);
}
