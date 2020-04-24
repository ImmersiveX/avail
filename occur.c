//
// Created by 18001534 on 20/04/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 500     /* buffer size for reading file */
#define SN C02VTQZ8HTD5


int main (int argc, char *argv[]){
    int counter = 0;
    char *ch;
    char buffer[BUFFER_SIZE];
    int i;
    char *p;
    char SN;
    FILE *fileptr;
    /*if (strcmp(argv[1] , "-h") ==0 || (strcmp(argv[1] ,  "-help") || (strcmp(argv[1] ,  "-H"))==0)){
        fprintf(stdout, "options manual\n");
    } else{ */
    fileptr = fopen(argv[1], "r");
    //}
    if (fileptr==NULL){
        return EXIT_FAILURE;
    }
    ch = fgets(buffer, BUFFER_SIZE, fileptr);
    //if (strcmp(argv[2] , "-c") ==0 || (strcmp(argv[2] ,  "-C") ) == 0|| (strcmp(argv[2] ,  "-char"))==0) {
        while (ch != NULL){
            i = 0;
            while ((p = strstr(buffer + i, argv[3])) != NULL) {
                i= (int) ((p - buffer) + 1);
                counter++;
            }
            ch = fgets(buffer, BUFFER_SIZE, fileptr);
        }
    //}
    fclose(fileptr);
    //printf("%d\n", counter);

    /* for testing purposes*/
    printf("result: %d\n", counter);
    printf("%s\n%s\n%s\n", argv[0], argv[1], argv[2]);
    printf("option: %s\n", argv[2]);
    printf("word/char: %s\n", argv[3]);
    printf("word equal to test:%d\n", ((strcmp(argv[3], "test"))==0));
    return EXIT_SUCCESS;
}