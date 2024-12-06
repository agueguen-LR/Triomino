/**
 * @file       triomino-generate.c
 *
 * @author     Adrien Gueguen <adrien.gueguen@etudiant.univ-lr.fr>
 * @date       2024
 * @copyright
 */

#include <stdlib.h>
#include <stdio.h>

#include "triomino.h"

#include "triomino.inc"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Please add name of target file"); // NOLINT build/include_what_you_use
    return 1;
  }

  FILE *file = fopen(argv[1], "wb");
  if (!file) {
    perror("Error opening file");
    return EXIT_FAILURE;
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
