#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>


int main (int argc, char **argv) {
    // Fonction main de base
    SDL_version nb;
    SDL_VERSION(&nb);

    printf("SDL Version : %d.%d.%d\nTaille des long long int : %d", nb.major, nb.minor, nb.patch, sizeof(long long int));

    return 0;
}