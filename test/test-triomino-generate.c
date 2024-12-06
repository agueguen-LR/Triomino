/**
* @file       test-triomino-generate.c
 *
 * @author     Adrien Gueguen <adrien.gueguen@etudiant.univ-lr.fr>
 * @date       2024
 * @copyright
 */

#ifdef NDEBUG
#undef NDEBUG
#endif

#include "triomino.h"
#include "triomino.inc"

int main(void) {
    for (int a = 0; a <= 5; a++) {
        for (int b = a; b <= 5; b++) {
            for (int c = b; c <= 5; c++) {
                Triomino* triomino = triomino_create_full(a, b, c);
                if (triomino) {
                    printf("%s\n", triomino_to_string(triomino)); // NOLINT build/include_what_you_use
                    triomino_free(triomino);
                }
            }
        }
    }
    return 0;
}
