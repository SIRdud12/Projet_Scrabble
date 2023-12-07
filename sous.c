//
// Created by ENELI ENELI ULRICH YANN ALAN on 07/12/2023.
//

#include "head.h"
// sous programme pour le remplissage
void remplirtableau(char tab[15][15]) {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            tab[i][j] = ' ';
        }
    }
    tab[1][1] = '6';
    tab[1][4] = '&';
    tab[1][8] = '6';
    tab[1][12] = '&';
    tab[1][15] = '6';
    tab[2][2] = '@';
    tab[2][6] = '%';
    tab[2][10] = '%';
    tab[2][14] = '@';
    tab[3][3] = '@';
    tab[3][7] = '&';
    tab[3][9] = '&';
    tab[3][13] = '@';
    tab[4][1] = '&';
    tab[4][4] = '@';
    tab[4][8] = '&';
    tab[4][12] = '@';
    tab[4][15] = '&';
    tab[5][5] = '@';
    tab[5][10] = '@';
    tab[6][2] = '%';
    tab[6][6] = '%';
    tab[6][10] = '%';
    tab[6][14] = '%';
    tab[7][3] = '&';
    tab[7][7] = '&';
    tab[7][9] = '&';
    tab[7][13] = '&';
    tab[8][1] = '6';
    tab[8][4] = '&';
    tab[8][6] = 'P';
    tab[8][7] = 'L';
    tab[8][8] = '#A';
    tab[8][9] = 'N';
    tab[8][10] = 'E';
    tab[8][12] = 'T';
    tab[8][13] = '&E';
    tab[8][15] = '6';
    tab[9][3] = '&';
    tab[9][7] = '&';
    tab[9][9] = '&';
    tab[9][13] = '&';
    tab[10][2] = '%';
    tab[10][6] = '%';
    tab[10][10] = '%';
    tab[10][14] = '%';
    tab[11][5] = '@';
    tab[11][11] = '@';
    tab[12][1] = '&';
    tab[12][4] = '@';
    tab[12][8] = '&';
    tab[12][12] = '@';
    tab[13][3] = '@';
    tab[13][7] = '&';
    tab[13][9] = '&';
    tab[13][13] = '@';
    tab[14][2] = '@';
    tab[14][6] = '%';
    tab[14][10] = '%';
    tab[14][14] = '@';
    tab[15][1] = '6';
    tab[15][4] = '&';
    tab[15][8] = '6';
    tab[15][12] = '&';
    tab[15][15] = '6';

}

void affichertab(char tab[15][15]) {
    printf("     A   B   C   D   E   F   G   H   I   J   K   L   M   N   O\n");
    for (int i = 0; i < 15; i++) {
        printf("%2d |", i + 1);
        for (int j = 0; j < 15; j++) {
            printf(" %c |", tab[i][j]);
        }
        printf("\n");
    }
}

