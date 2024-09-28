#include <stdlib.h>
#include <stdio.h>

#include "brocdx.h"

int main(int argc, char **argv) {
    printf("[MAIN] Starting application\n");
    broc_open();

    broc_close();
    return EXIT_SUCCESS;
}
