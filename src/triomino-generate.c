/**
 * @file       triomino-generate.c
 *
 * @author     Adrien Gueguen <adrien.gueguen@etudiant.univ-lr.fr>
 * @date       2024
 * @copyright  None
 * @brief      Generate all possible combinations of triominos and write them to a file.
 * @details    Triominos are written in binary format.
 * @details    File name must be given as an argument, file cannot already exist.
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#include "triomino.h"

#include "triomino.inc"


/**
 * @brief Main function of the Triomino Generator application.
 * @param argc The number of arguments, must be 2.
 * @param argv The arguments.
 * @return int: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[]) {
  if (argc != 2) {
    perror("Please add name of target file");  // LCOV_EXCL_LINE
    return EXIT_FAILURE;  // LCOV_EXCL_LINE Is covered by test-generate[no_args], not detected for some reason
  }

  int fd = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);  // flawfinder: ignore
  if (fd == -1) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  FILE *file = fdopen(fd, "wb");
  if (!file) {
    perror("Error converting file descriptor to FILE*");  // LCOV_EXCL_LINE
    close(fd);  // LCOV_EXCL_LINE
    return EXIT_FAILURE;  // LCOV_EXCL_LINE Not covered by a test, don't know how to simulate this case
  }

  triomino_init();

  for (int a = 0; a <= 5; a++) {
    for (int b = a; b <= 5; b++) {
      for (int c = b; c <= 5; c++) {
        Triomino* triomino = triomino_create_full(a, b, c);
        if (triomino) {
          fwrite(triomino, sizeof(Triomino), 1, file); // NOLINT build/include_what_you_use
          triomino_free(triomino);
        }
      }
    }
  }

  triomino_finish();
  fclose(file); // NOLINT build/include_what_you_use

  return EXIT_SUCCESS;
}
