#include "head.h"

int main() {
    int nombre;
    char tab[15][15]; // initialisation du tableau

    printf("PLATEAU DE JEU :\n");
    remplirtableau(tab); // appel du sous programme de remplissage du tableau
    affichertab(tab); // appel du sous programme d'ffichage du tableau

    printf("\n");
    printf("JOUEURS :\n");
    printf("\n");

    srand(time(NULL));

    do {
        printf("Veuillez entrer le nombre de Joueurs: ");
        scanf("%d", &nombre);
    } while (nombre < 2 || nombre > 4);

    struct joueurs tab1[4];

    saisirjoueur(tab1, nombre);
    printf("\n");
    afficherjoueur(tab1, nombre);
    printf("\n");
    printf("Pour commencer, les joueurs qui commenceront seront :\n");
    printf("\n");
    ordredepassage(tab1,nombre);

    return 0;
}
