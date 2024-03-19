#include "util.h"
#include <libgen.h>
#include <limits.h>

static char guess[] = "Guess who I am?\0";

void get_dir_path(char *path) {
        // 获取当前可执行文件的绝对路径
        int ret = readlink("/proc/self/exe", path, UTIL_MAX_LEN);
        if (ret < 0) {
                perror("readlink error");
                path = NULL;
                return;
        }

        path = dirname(path);
        // printf("Directory is %s\n", path);
}

void upper_print_str(char * str)
{
        const int cnt = 60;
        int i, padding, remain = 0;
        char upper_str[UTIL_MAX_LEN] = {0};

        // upper string
        for (int i = 0; str[i] != '\0'; i++) {
                upper_str[i] = toupper(str[i]);
        }

        padding = (cnt - 2 - strlen(str)) / 2;
        remain = (cnt - 2 - strlen(str)) % 2;

        // padding
        for (i = 0; i < padding; i++) {
                printf("=");
        }
        // print string
        printf(" %s ", upper_str);
        // padding
        for (i = 0; i < padding; i++) {
                printf("=");
        }
        if (remain) {
                printf("=");
        }
        printf("\n");
}


int print_image(char * pokemon_name, char * filename)
{
	char read_string[UTIL_MAX_LEN], file_path[UTIL_MAX_LEN];
	FILE * fptr = NULL;

        get_dir_path(file_path);
        // get file absolute path
        if (file_path == NULL) {
                return -1;
        }
        strcat(file_path, "/");
        strcat(file_path, filename);
        
        // open pokemon text art file
	if((fptr = fopen(file_path,"r")) == NULL) {
		fprintf(stderr, "error opening %s\n", file_path);
		return -1;
	}

        // print pokemon text art
        upper_print_str(guess);
	while(fgets(read_string, sizeof(read_string), fptr) != NULL)
		printf("%s", read_string);
	printf("\n");
        
        // print pokemon name
        upper_print_str(pokemon_name);
        fflush(stdout);

	fclose(fptr);
	return 0;
}
