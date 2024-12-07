/**
 * @file       test-to-string.c
 *
 * @author     Christophe Demko <christophe.demko@univ-lr.fr>
 * @date       2024
 * @copyright  BSD 3-Clause License
 */

#include <stdlib.h>
#include <string.h>

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <assert.h>

#include "triomino.h"
#include "triomino.inc"

int main(void) {
  triomino_init();
  {
    Triomino* triomino = triomino_create_full(1, 2, 3);
    assert(strcmp(triomino_to_string(triomino), "1-2-3") == 0);
    triomino_destroy(triomino);
  }
  triomino_finish();

  return EXIT_SUCCESS;
}