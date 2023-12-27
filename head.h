//
// Created by ENELI ENELI ULRICH YANN ALAN on 07/12/2023.
//

#ifndef PROJET_SCRABBLE_HEAD_H
#define PROJET_SCRABBLE_HEAD_H

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    char nom[50];
    int numero;
}joueurs;
typedef struct {
    char lettre;
    int valeur;
}jeton;
typedef struct { // structure representant un jeton du chevalet du joueur
    jeton jeton;
    int position; // position sur le chevalet
    int pioche[];
}jetonChevalet;

void remplirtableau(char tab[15][15]);

void affichertab(char tab[15][15]);

void saisirjoueur(joueurs tab1[], int nombre);

void afficherjoueur(joueurs tab1[], int nombre);

void ordredepassage( joueurs tab1[], int nombre);

void initialisationpioche(jeton pioche[],int taille);

jeton tirerjeton(jeton pioche[], int *taillepioche);

void initialisationducChevalet(jetonChevalet chevalet[],jeton structjetons[], int *taillepioche, int tailleChevalet);


#endif //PROJET_SCRABBLE_HEAD_H
