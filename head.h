//
// Created by ENELI ENELI ULRICH YANN ALAN on 07/12/2023.
//

#ifndef PROJET_SCRABBLE_HEAD_H
#define PROJET_SCRABBLE_HEAD_H

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct joueurs {
    char nom[50];
    int numero;
};

void remplirtableau(char tab[15][15]);

void affichertab(char tab[15][15]);

void saisirjoueur(struct joueurs tab1[], int nombre);

void afficherjoueur(struct joueurs tab1[], int nombre);

void ordredepassage(struct joueurs tab1[], int nombre);


#endif //PROJET_SCRABBLE_HEAD_H
