#include <stdlib.h>
#include <stdio.h>

#include "brocdx.h"

int main(int argc, char **argv) {
    printf("[APP] Starting application\n");
    bdx_open();

    bdx_close();
    printf("[APP] Stopping application\n");
    return EXIT_SUCCESS;
}
