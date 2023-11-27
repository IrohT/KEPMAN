#include <stdio.h>
#include <stdlib.h>


typedef struct Kep{
    int magassag;
    int szelesseg;
    int szzinek;
    int** pontok;

}Kep;

void mentes(Kep* kep, char* file){

    FILE* ki = fopen(file, "w");
    fprintf(ki, "%s\n", "P2");
    fprintf(ki,"%d %d\n%d\n", kep->szelesseg, kep->magassag, kep->szzinek);
    for (int i = 0; i < kep->magassag; ++i) {
        for (int j = 0; j < kep->szelesseg; ++j) {
            fprintf(ki, "%d\n", kep->pontok[i][j]);
        }
    }

    fclose(ki);

}

int main() {

    Kep kep;
    kep.magassag = 255;
    kep.szelesseg = 255;
    kep.szzinek = 255;

    kep.pontok = (int**)malloc(sizeof(int*) *kep.magassag);

    for (int i = 0; i < kep.magassag; ++i) {
        kep.pontok[i] = (int*) malloc(sizeof(int) * kep.szelesseg);
    }

    for (int i = 0; i < kep.magassag; ++i) {
        for (int j = 0; j < kep.szelesseg; ++j) {
            kep.pontok[i][j] = (i*i + j*j % kep.szzinek);
        }
    }

    mentes(&kep, "ki.pgm");

    return 0;
}
