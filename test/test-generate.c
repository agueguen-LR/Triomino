/**
* @file       test-triomino-generate.c
 *
 * @author     Adrien Gueguen <adrien.gueguen@etudiant.univ-lr.fr>
 * @date       2024
 * @copyright
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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

  // Verify: Check the contents of the file
  assert(file != NULL);
  Triomino* triomino;
  while (fread(triomino, sizeof(Triomino), 1, file) == 1) {
      // Add assertions to verify the contents of each triomino
      assert(triomino->a >= 0 && triomino->a <= 5);
      assert(triomino->b >= triomino->a && triomino->b <= 5);
      assert(triomino->c >= triomino->b && triomino->c <= 5);
  }
  fclose(file); // NOLINT build/include_what_you_use

  triomino_finish();
}
