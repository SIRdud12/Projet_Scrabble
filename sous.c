//
// Created by ENELI ENELI ULRICH YANN ALAN on 07/12/2023.
//

#include "head.h"

// sous programme pour le remplissage du tableau
void remplirtableau(char tab[15][15]) { // tableau bidimensionelle
    for (int i = 0; i < 15; i++) {  // boucles pour les lignes
        for (int j = 0; j < 15; j++) {  // boucles pour les colums
            tab[i][j] = ' ';
        }
    }
    // remplissage manuelle de chaque charactere specifique
    tab[0][0] = '6';

    tab[0][3] = '&';
    tab[0][7] = '6';
    tab[0][11] = '&';
    tab[0][14] = '6';
    tab[1][1] = '@';
    tab[1][5] = '%';
    tab[1][9] = '@';
    tab[1][13] = '@';
    tab[2][2] = '@';
    tab[2][6] = '&';
    tab[2][8] = '&';
    tab[2][12] = '@';
    tab[3][0] = '&';
    tab[3][3] = '@';
    tab[3][7] = '&';
    tab[3][11] = '@';
    tab[3][14] = '&';
    tab[4][4] = '@';
    tab[4][10] = '@';
    tab[5][1] = '%';
    tab[5][5] = '%';
    tab[5][9] = '@';
    tab[6][2] = '&';
    tab[6][6] = '&';
    tab[6][8] = '&';
    tab[6][12] = '&';
    tab[7][0] = '6';
    tab[7][3] = '&';
    tab[7][5] = 'P';
    tab[7][6] = 'L';
    tab[7][7] = '#A';
    tab[7][8] = 'N';
    tab[7][9] = 'E';
    tab[7][10] = 'T';
    tab[7][11] = '&E';
    tab[7][14] = '6';
    tab[8][2] = '&';
    tab[8][6] = '&';
    tab[8][8] = '&';
    tab[8][12] = '&';
    tab[9][1] = '%';
    tab[9][5] = '%';
    tab[9][9] = '%';
    tab[9][13] = '%';
    tab[10][4] = '@';
    tab[10][10] = '@';
    tab[11][0] = '&';
    tab[11][3] = '@';
    tab[11][7] = '&';
    tab[11][11] = '@';
    tab[11][14] = '&';
    tab[12][2] = '@';
    tab[12][6] = '&';
    tab[12][8] = '&';
    tab[12][12] = '@';
    tab[13][1] = '@';
    tab[13][5] = '%';
    tab[13][9] = '%';
    tab[13][13] = '&';
    tab[14][0] = '6';
    tab[14][3] = '&';
    tab[14][7] = '6';
    tab[14][11] = '&';
    tab[14][14] = '6';

}

// boucle d'affichage du tableau
void affichertab(char tab[15][15]) { // tableau bidimensionelle
    printf("     A   B   C   D   E   F   G   H   I   J   K   L   M   N   O\n"); // titre de chaque lignes du tableau
    for (int i = 0; i < 15; i++) { // parcour les lignes
        printf("%2d |", i + 1); // affiche le numero de ligne (index + 1)
        for (int j = 0; j < 15; j++) { // parcours les colonnes
            printf(" %c |",
                   tab[i][j]); // affichage du tableau a l'index [i][j] et création de colonnes suivant le tableau
        }
        printf("\n"); // ajoute une nouvelle ligne la creation de chaque ligne du tableau
    }
}

// sous programme des joueurs

void saisirjoueur(joueurs tab1[], int nombre) {

    for (int i = 0; i < nombre; i++) {
        printf("Veuillez entrer le nom du joueur %d:", i + 1);
        scanf("%s", tab1[i].nom);
    }
    for (int i = 0; i < nombre; i++) {
        tab1[i].numero = rand() % (6 - 1 + 1) + 1;// genere des nombre aleatoire de 1 a 6
    }
}

void afficherjoueur(joueurs tab1[], int nombre) {

    for (int i = 0; i < nombre; i++) {
        printf("Le nombre de %s est :%d\n", tab1[i].nom, tab1[i].numero);
    }
}

void ordredepassage(joueurs tab1[], int nombre) {
    char t[4];
    for (int i = 0; i < nombre; i++) {
        for (int j = i + 1; j < nombre; j++) {
            if (tab1[i].numero > tab1[j].numero) { // comparaison par le nombre aléatoire
                strcpy(t, tab1[i].nom);
                strcpy(tab1[i].nom, tab1[j].nom);
                strcpy(tab1[j].nom, t);

                int temp = tab1[i].numero;
                tab1[i].numero = tab1[j].numero;
                tab1[j].numero = temp;
            } else if (tab1[i].numero == tab1[j].numero) {// comparaison par le nom
                if (strcmp(tab1[i].nom, tab1[j].nom) > 0) {
                    strcpy(t, tab1[i].nom);
                    strcpy(tab1[i].nom, tab1[j].nom);
                    strcpy(tab1[j].nom, t);

                    int temp = tab1[i].numero;
                    tab1[i].numero = tab1[j].numero;
                    tab1[j].numero = temp;
                }
            }
        }
    }
    for (int i = 0; i < nombre; i++) {
        printf("Le joueur %d est %s avec le nombre %d\n", i + 1, tab1[i].nom, tab1[i].numero);
    }
}

// sous programme d'initialisation de la pioche
void initialisationpioche(jeton  pioche[], int taille) {
    // liste des jetons avec les occurences
    char lettres[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                      'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '?'};
    int occurence[] = {9, 2, 2, 3, 15, 2, 2, 2, 8, 1, 1, 5, 3, 6, 6, 2, 1, 6, 6, 6, 6, 2, 1, 1, 1, 1, 2};
    int valeursenpoints[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 10, 1, 2, 1, 1, 3, 8, 1, 1, 1, 1, 4, 10, 10, 10, 10, 0};

    // initialisation de la pioche en fonctions des occurrences
    int index = 0;
    for (int i = 0; i < sizeof(occurence) / sizeof(occurence[0]); i++) {
        for (int j = 0; j < occurence[i]; j++) {
            pioche[index].lettre = lettres[i];
            pioche[index].valeur = valeursenpoints[i];
            index++;
        }
    }
    // melange de la pioche
    srand((unsigned int)time(NULL));
    for (int i = taille - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // echange de la pioche de maniere aleatoire entre i et j
        jeton temp = pioche[i];
        pioche[i] = pioche[j];
        pioche[j] = temp;
    }
}

// fonction pour tirer un jeton de la pioche
jeton tirerjeton(jeton pioche[], int *taillepioche) {
    jeton jetontire = pioche[*taillepioche - 1];
    (*taillepioche)--;
    return jetontire;
}

void initialisationducChevalet(jetonChevalet chevalet[],jeton pioche[], int *taillepioche,int tailleChevalet) {
    for (int i = 0; i < tailleChevalet; i++) {
        chevalet[i].jeton = tirerjeton(pioche, taillepioche); // A REVOIR
        chevalet[i].position = i + 1;
    }
}