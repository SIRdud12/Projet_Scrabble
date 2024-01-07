#include "head.h"

int main() {
    int nombre;
    char tab[15][15]; // initialisation du tableau
    int choixmenu;
    int taille;
    char Mot[50];


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

    joueurs tab1[4];

    saisirjoueur(tab1, nombre);
    printf("\n");
    afficherjoueur(tab1, nombre);
    printf("\n");
    printf("Pour commencer, les joueurs qui commenceront seront :\n");
    printf("\n");
    ordredepassage(tab1, nombre);
    printf("\n");


    printf("Iniitialisation de la pioche :\n");
    jeton pioche[102]; // declaration de la pioche
    initialisationpioche(pioche, sizeof(pioche) / sizeof(pioche[0]));

    // declaration du chevalet du joueur
    int taillepioche = sizeof(pioche) / sizeof(pioche[0]);
    int tailleChevalet = 7; // taille maximal pour le chevalet
    jetonChevalet chevalet[tailleChevalet];

    // initialisation du chevalet du joueur
    initialisationducChevalet(chevalet, pioche, &taillepioche, tailleChevalet);

    // affichage du chevalet du joueur
    for (int i = 0; i < nombre; i++) {
        initialisationducChevalet(chevalet, pioche, &taillepioche, tailleChevalet);
        //printf("Chevalet du joueur[%d] :\n",i);
        printf("Chevalet de %s est :", tab1[i].nom);// Les 7 jetons de chaque nom s'affiche
        for (int i = 0; i < tailleChevalet; i++) {
            printf("%c%d ", chevalet[i].jeton.lettre, chevalet[i].jeton.valeur);
        }
        printf("\n");
    }

    for (int i = 0; i < nombre; i++) {
        printf("%s :\n", tab1[i].nom);

        placerMot(tab, chevalet, tailleChevalet);
    }
    printf("\n");

    // calcule score du mot apres chaque coup
    for (int i = 0; i < nombre; i++) {
        int resultat = calculscorechaquejoueur(Mot);
        printf("Le score du joueur %s est:%d\n", tab1[i].nom, resultat);
    }
    printf("\n");

    do {
        affichermenu();
        printf("\n");
        printf("Veuillez choisir une option du Menu (1-4): ");
        scanf("%d", &choixmenu);

        joueurs tab2[4];

        switch (choixmenu) {
            case 1:
                nouvellepartie(tab2, nombre, tab);
                break;
            case 2:
                afficheraide();
                break;
            case 3:
                for (int i = 0; i < nombre; i++) {
                    int resultat = calculscorechaquejoueur(Mot);
                    printf("Le score du joueur %s est %d points\n", tab1[i].nom,
                           resultat); // Probleme !!!! : Le score des Joueurs ne f'affichent pas quand je choisi 3 ils affichent 0
                }

                break;
            case 4:
                printf("Quitter le jeu...\n");
                return 0;
            default:
                printf("Option invalide. Veuillez choisir une option valide.\n");

        }
    } while (choixmenu != 4);
    return 0;
}
