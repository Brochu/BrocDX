#include <stdio.h>

#include "brocdx.h"

int main(int argc, char **argv) {
    printf("[APP] Starting application\n");
    bdx_start();

    printf("[APP] Running logic here\n");

    bdx_stop();
    printf("[APP] Stopping application\n");
    return 0;
}
