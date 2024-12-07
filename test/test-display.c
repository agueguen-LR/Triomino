/**
* @file       test-triomino-display.c
 *
 * @author     Adrien Gueguen <adrien.gueguen@etudiant.univ-lr.fr>
 * @date       2024
 * @copyright
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "triomino.h"

#include "triomino.inc"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Please add path to triomino-display and target file"); // NOLINT build/include_what_you_use
        return 1;
    }

    FILE *file = fopen(argv[2], "rb");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Redirect stdout to capture the output
    int stdout_fd = dup(STDOUT_FILENO);
    int pipe_fd[2];
    pipe(pipe_fd);
    dup2(pipe_fd[1], STDOUT_FILENO);
    close(pipe_fd[1]);

    // Run the application
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return EXIT_FAILURE;
    } else if (pid == 0) {
        execl(argv[1], argv[1], argv[2], NULL);
        perror("execl failed");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
            return EXIT_FAILURE;
        }
    }

    // Restore stdout and read the output
    dup2(stdout_fd, STDOUT_FILENO);
    close(stdout_fd);

    char buffer[512];
    read(pipe_fd[0], buffer, sizeof(buffer));
    close(pipe_fd[0]);

    // Check the output
    Triomino* triomino = triomino_create_default();
    while (fread(triomino, sizeof(Triomino), 1, file) == 1) {  // NOLINT build/include_what_you_use
        assert(strstr(buffer, triomino_to_string(triomino)) != NULL);
    }
    triomino_destroy(triomino);

    return 0;
}
