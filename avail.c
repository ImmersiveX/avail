//
// Created by 18001534 on 18/04/2020.
//

/* LIB */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


/* DEF */
#define SHELL_BUFFER_SIZE 256   /* stdin buffer size                     */
#define SHELL_MAX_ARGS 8        /* max number of args                    */
#define SN C02VTQZ8HTD5         /*                                       */

/* VARS */
enum { STATE_SPACE, STATE_NON_SPACE };	/* parser_state */


int shell_child(const char *path_to_exec, char *const *args)
{
    return execv(path_to_exec, args) ? -1 : 0;
}

void shell_parent(pid_t child_pid, int run_in_background)
{
    int child_return_val, child_error_code;
    fprintf(stderr,
            "  PARENT: CHILD(%d) forked\n",
            child_pid);
    if (run_in_background) {
        fprintf(stderr,
                "  PARENT: run_in_background=1 (not waiting for CHILD)\n");
        return;
    }
    wait(&child_return_val);
    child_error_code = WEXITSTATUS(child_return_val);
    fprintf(stderr,
            "  PARENT: CHILD(%d) finished (wait() returned)\n",
            child_pid);
    if (child_error_code != 0) {
        fprintf(stderr,
                "  PARENT: CHILD (%d) failed (%d)\n",
                child_pid, child_error_code);
    }
}

int main(int argc, char **argv) {
    pid_t shell_pid, pid_from_fork;
    int n_read, i, exec_argc, parser_state, run_in_background;
    char buffer[SHELL_BUFFER_SIZE];
    char SN;
    char *exec_argv[SHELL_MAX_ARGS + 1];
    shell_pid = getpid();
    while (1){
        fprintf(stdout, "avail(%d)> ", shell_pid);
        fflush(stdout);
        if (fgets(buffer, SHELL_BUFFER_SIZE, stdin) ==NULL){
            return EXIT_SUCCESS;
        }
        n_read = (int) strlen(buffer);
        run_in_background= n_read > 2 && buffer[n_read - 2] == '&';
        buffer[n_read - run_in_background - 1] = '\n';

        parser_state=STATE_SPACE;
        for (exec_argc = 0, i=0; (buffer[i] != '\n') && (exec_argc < SHELL_MAX_ARGS); i++){
            if (!isspace(buffer[i])){
                if (parser_state == STATE_SPACE)
                    exec_argv[exec_argc++] = &buffer[i];
                parser_state=STATE_NON_SPACE;
            } else{
                buffer[i]='\0';
                parser_state= STATE_SPACE;
            }

        }
        buffer[i] = '\0';
        if (!exec_argc){
            continue;
        }
        exec_argv[exec_argc]=NULL;
        if (!strcmp(exec_argv[0], "exit") || !strcmp(exec_argv[0], "quit")){
            printf("Goodbye\nExiting process %d\n", shell_pid);
            return EXIT_SUCCESS;
        } else if (!strcmp(exec_argv[0], "cd") && exec_argc >1) {
            if (chdir(exec_argv[1])) {
                fprintf(stderr, "cd: failed chdir %s", exec_argv[1]);
            }
        } else {
            pid_from_fork= fork();

            if ( pid_from_fork < 0){
                fprintf(stderr, "fork failed \n");
                continue;
            }
            if (pid_from_fork == 0){
                return shell_child(exec_argv[0], &exec_argv[0]);
            } else {
                shell_parent(pid_from_fork, run_in_background);
            }
        }
    }

    return EXIT_SUCCESS;
}