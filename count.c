//
// Created by 18001534 on 18/04/2020.
//

/* LIB */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* DEF */
#define SN C02VTQZ8HTD5         /*                                       */

int main(int argc, char *argv[]) {
    int counter = 0;
    char ch;
    char SN;
    FILE *fileptr;
    fileptr = fopen(argv[1], "r");
    /* if file cannot be opened, exit */
    if (fileptr == NULL) {
        return EXIT_FAILURE;
    }
    /* get character from file */
    ch = fgetc(fileptr);
    /* check which [OPTION] to exec */
    if (strcmp(argv[2], "-c") == 0 || (strcmp(argv[2], "-C")) == 0) {
        /* read until end of file */
        while (ch != EOF) {
            /* if character is a letter */
            if (ch != ' ' && ch != '\n') {
                counter++;
            }
            /* LIB */
            ch = fgetc(fileptr);
        }
    } else if ((strcmp(argv[2], "-l") == 0 || (strcmp(argv[2], "-L")) == 0)) {
        while (ch != EOF) {
            /* if character is newline  */
            if (ch == '\n') {
                counter++;
            }
            ch = fgetc(fileptr);
        }
    } else if (strcmp(argv[2], "-w") == 0 || (strcmp(argv[2], "-W")) == 0) {
        while (ch != EOF) {
            /* if character is space or newline (word after spac, after newline) */
            if (ch == ' ' || ch == '\n') {
                counter++;
            }
            ch = fgetc(fileptr);
        }
    }
    fclose(fileptr);
    printf("%d\n", counter);
    /* for testing purposes*/
    //printf("result: %d\n", counter);
    //printf("%s\n%s\n%s\n", argv[0], argv[1], argv[2]);
    //printf("option: %s\n", argv[2]);
    //printf("option equal to -c:%d\n", ((strcmp(argv[2], "-c"))==0));
    //printf("%s", (char *) SN);
    return EXIT_SUCCESS;
}