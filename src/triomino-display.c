/**
* @file       triomino-display.c
 *
 * @author     Adrien Gueguen <adrien.gueguen@etudiant.univ-lr.fr>
 * @date       2024
 * @copyright  None
 * @brief      Generate all triominos in a file.
 * @details    File must contain triominos in binary format.
 * @details    File name must be given as an argument, file cannot already exist.
 */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#include "triomino.h"

#include "triomino.inc"

/**
 * @brief Main function of the Triomino Display application.
 * @param argc The number of arguments, must be 2.
 * @param argv The arguments.
 * @return int: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[]) {
  if (argc != 2) {
    perror("Please add name of target file");
    return EXIT_FAILURE;
  }

  int fd = open(argv[1], O_RDONLY | O_NOFOLLOW);  // flawfinder: ignore
  if (fd == -1) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }
  FILE *file = fdopen(fd, "rb");  // flawfinder: ignore
  if (file == NULL) {
    perror("Error opening file stream");
    close(fd);
    return EXIT_FAILURE;
  }

  triomino_init();

  Triomino* triomino = triomino_create_default();
  while (fread(triomino, sizeof(Triomino), 1, file) == 1) {
    printf("%u-%u-%u\n", triomino->a, triomino->b, triomino->c);  // NOLINT build/include_what_you_use
  }

  triomino_finish();
  fclose(file);  // NOLINT build/include_what_you_use
  return EXIT_SUCCESS;
}
