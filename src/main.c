/**
 * ----------------------------------------------
 *                     main.c
 * ----------------------------------------------
 * 
 * The main file of the program, everything
 * should be linked here and declared in separated
 * files.
 */

#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char **argv) {
    SDL_version nb;
    SDL_VERSION(&nb);

    printf("%d.%d.%d", nb.major, nb.minor, nb.patch);

    return 0;
}