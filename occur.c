//
// Created by 18001534 on 20/04/2020.
//

/* LIB */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* DEF */
#define BUFFER_SIZE 500     /* buffer size for reading file */
#define SN C02VTQZ8HTD5


int main (int argc, char *argv[]){
    int counter = 0;
    char *ch;
    char buffer[BUFFER_SIZE];
    int i;
    char *position;
    char SN;
    FILE *fileptr;
    fileptr = fopen(argv[1], "r");
    if (fileptr==NULL){
        return EXIT_FAILURE;
    }
    /* get stream of BUFFER_SIZE from file */
    ch = fgets(buffer, BUFFER_SIZE, fileptr);
        /* read until end of file */
        while (ch != NULL){
            i = 0;
            /* find next occurrence of specified character/word */
            while ((position = strstr(buffer + i, argv[3])) != NULL) {
                /* index of the character/word in buffer is:
                 * memory address of position - memory address of buffer */
                i= (int) ((position - buffer) + 1);
                counter++;
            }
            /* get next stream of BUFFER_SIZE from file */
            ch = fgets(buffer, BUFFER_SIZE, fileptr);
        }
    fclose(fileptr);
    printf("%d\n", counter);

    /* for testing purposes*/
    //printf("result: %d\n", counter);
    //printf("%s\n%s\n%s\n", argv[0], argv[1], argv[2]);
    //printf("option: %s\n", argv[2]);
    //printf("word/char: %s\n", argv[3]);
    //printf("word equal to test:%d\n", ((strcmp(argv[3], "test"))==0));
    return EXIT_SUCCESS;
}