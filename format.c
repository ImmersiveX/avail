//
// Created by 18001534 on 23/04/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SN C02VTQZ8HTD5


int main (int argc, char *argv[]){
    int ch;
    char SN;
    char buffer;
    char scase;
    int ch1;
    FILE *fileptr;
    FILE *fileptr2;
    fileptr = fopen(argv[1], "r");
    fileptr2 = fopen(argv[2], "w");
    // if file cannot be opened, exit
    if (fileptr==NULL || fileptr2==NULL){
        return EXIT_FAILURE;
    }
    ch = fgetc(fileptr);
    // check which [OPTION] to exec
    if (strcmp(argv[3] , "-u") ==0 || (strcmp(argv[2] ,  "-U") )==0 || (strcmp(argv[2] ,  "-uppercase") )==0) {
        // read until end of file
        while (ch !=  EOF) {
            // assign read character to buffer
            buffer = (char) ch;
            // call toupper() on buffer to convert to uppercase
            buffer = (char) toupper(buffer);
            // write buffer to output file
            fputc(buffer, fileptr2);
            // next character
            ch = fgetc(fileptr);
        }
    }else if (strcmp(argv[3] , "-l") ==0 || (strcmp(argv[2] ,  "-L") )==0 || (strcmp(argv[2] ,  "-lowercase") )==0) {
        while (ch !=  EOF) {
            buffer = (char) ch;
            // call tolower() on buffer to convert to lowercase
            buffer = (char) tolower(buffer);
            fputc(buffer, fileptr2);
            ch = fgetc(fileptr);
        }
    }else if (strcmp(argv[3] , "-sc") ==0 || (strcmp(argv[2] ,  "-SC") )==0 || (strcmp(argv[2] ,  "-snakecase") )==0) {
        while (ch !=  EOF) {
            buffer = (char) ch;
            scase = '_';
            // if character is space
            if (buffer == ' '){
                // write scase to output file
                fputc(scase, fileptr2);
            } else {
                fputc(buffer, fileptr2);
            }
            ch = fgetc(fileptr);
        }
    }else if (strcmp(argv[3] , "-cc") ==0 || (strcmp(argv[2] ,  "-CC") )==0 || (strcmp(argv[2] ,  "-camelcase") )==0) {
        /*int counter = 0;
        char *ch2;
        char buffer2[500];
        int i;
        char *p;
        ch2 = fgets(buffer, 500, fileptr);
        while (ch2 != NULL){
            i = 0;
            char sc;
            while ((p = strstr(buffer2 + i, ' ')) != NULL) {
                i= (int) ((p - buffer2) + 1);
                for (int j = 0; j<500 ; ++j) {
                    if (buffer2[j] == ' '){
                        fputc(toupper(buffer2[i-1]), fileptr2);
                    }
                }

            }
            ch2 = fgets(buffer, 500, fileptr);
        }*/
        /*
        while (ch != (char *) EOF) {
            buffer = (char) ch;
            scase = '_';
            if (buffer == ' '){
                fputc(scase, fileptr2);
            } else {
                fputc(buffer, fileptr2);
            }
            ch = fgetc(fileptr);
        }*/
        printf("option camelcase is not implemented");
    }
    fclose(fileptr);
    fclose(fileptr2);

    /* for testing purposes*/
    //printf("%s\n%s\n%s\n", argv[0], argv[1], argv[2]);
    //printf("option: %s\n", argv[3]);
    return EXIT_SUCCESS;
}