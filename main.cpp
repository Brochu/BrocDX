#include <stdlib.h>
#include <stdio.h>

#include "brocdx.h"

int main(int argc, char **argv) {
    printf("[MAIN] Starting application\n");
    bdx_open();

    bdx_close();
    return EXIT_SUCCESS;
}
