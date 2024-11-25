#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

struct sdata {
    char buffer[64];
};

struct sfp {
    int (*fp)();
};

void f_entrar() {
    printf("Pasando\n");
}

void f_espero_fuera() {
    printf("Esperando fuera\n");
}

int main(int argc, char **argv) {
    struct sdata *smidat;
    struct sfp *f;

    smidat = malloc(sizeof(struct sdata));
    f = malloc(sizeof(struct sfp));
    f->fp = f_espero_fuera;

    printf("data: está en [%p], el puntero fp está en [%p]\n", smidat, f);

    strcpy(smidat->buffer, argv[1]);
    f->fp();

    return 0;
}

