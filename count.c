//
// Created by 18001534 on 18/04/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SN C02VTQZ8HTD5

int main (int argc, char *argv[]){
    int counter = 0;
    char ch;
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
    ch = fgetc(fileptr);
    /*if (strcmp(argv[2] , "-h") ==0 || (strcmp(argv[2] ,  "-help") || (strcmp(argv[2] ,  "-H"))==0)){
        fprintf(stdout, "options manual\n");
    }else */
    if (strcmp(argv[2] , "-c") ==0 || (strcmp(argv[2] ,  "-C") )==0){
        while(ch !=EOF) {
            if (ch != ' ' && ch !='\n') {
                counter++;
            }
            ch=fgetc(fileptr);
        }
    } else if ((strcmp(argv[2] ,  "-l") ==0  || (strcmp(argv[2] ,  "-L")) ==0)) {
        while(ch !=EOF) {
            if (ch == '\n') {
                counter++;
            }
            if (ch == '5'){
                printf("working\n");
            }
            ch=fgetc(fileptr);
        }
    } else if (strcmp(argv[2], "-w") == 0 || (strcmp(argv[2], "-W")) == 0) {
        while (ch != EOF) {
            if (ch == ' ' || ch == '\n') {
                counter++;
            }
            ch=fgetc(fileptr);
        }
    }
    fclose(fileptr);
    //printf("%d\n", counter);
    /* for testing purposes*/
    printf("result: %d\n", counter);
    printf("%s\n%s\n%s\n", argv[0], argv[1], argv[2]);
    printf("option: %s\n", argv[2]);
    printf("option equal to -c:%d\n", ((strcmp(argv[2], "-c"))==0));
    return EXIT_SUCCESS;
}