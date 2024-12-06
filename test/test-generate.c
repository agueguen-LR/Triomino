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
#include <string.h>

#include "triomino.h"
#include "triomino.inc"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Please add name of target file"); // NOLINT build/include_what_you_use
    return 1;
  }

  FILE *file = fopen(argv[1], "rb");
  if (!file) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  triomino_init();

  // Verify: Check the contents of the file
  assert(file != NULL);

  int triomino_count = 0;
  int triomino_count_expected = 56;
  Triomino* triomino = triomino_create_default();
  Triomino* unique_triominos[56];

  while (fread(triomino, sizeof(Triomino), 1, file) == 1) {
      // Add assertions to verify the contents of each triomino
      assert(triomino->a >= 0 && triomino->a <= 5);
      assert(triomino->b >= triomino->a && triomino->b <= 5);
      assert(triomino->c >= triomino->b && triomino->c <= 5);

      // Ensure each triomino is unique
      for (int i = 0; i < triomino_count; i++) {
        assert(triomino->a != unique_triominos[i]->a || triomino->b != unique_triominos[i]->b || triomino->c != unique_triominos[i]->c);
      }
      unique_triominos[triomino_count] = triomino_clone(triomino);

      triomino_count++;
  }
  fclose(file); // NOLINT build/include_what_you_use
  assert(triomino_count == triomino_count_expected);
  triomino_destroy(triomino);
  for (int i = 0; i < triomino_count; i++) {
    triomino_destroy(unique_triominos[i]);
  }

  triomino_finish();
}
