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
    tab[7][7] = '#A'; // A
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
    char t[50];
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
void initialisationpioche(jeton pioche[], int taille) {
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
    srand((unsigned int) time(NULL));
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

void initialisationducChevalet(jetonChevalet chevalet[], jeton pioche[], int *taillepioche, int tailleChevalet) {
    for (int i = 0; i < tailleChevalet; i++) {
        chevalet[i].jeton = tirerjeton(pioche, taillepioche); // A REVOIR
        chevalet[i].position = i + 1;
    }
}

int existemot(char Mot[50]) {
    char motdic[50];
    // creation d'un pointeur sur fichier
    // FILE *file = NULL;
    // ouverture du fichier texte
    FILE *file = fopen("../Dictionnaire.txt", "r");

    if (file == NULL) {
        perror("Erreur d'ouverture\n"); // perror pour verifier la raison de l'erreur de maniere specifique
    }

    while (fgets(motdic, sizeof(motdic), file) != NULL);
    if (strcmp(Mot, motdic) == 0) {
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}


int placerMot(char tab[15][15], jetonChevalet chevalet[], int tailleChevalet) {
    char Mot[50];
    int ligne;
    char colonnes;
    char orientation;
    int Motvalide;

    // saisie du mot
    printf("Entrez le mot à placer : ");
    scanf("%s", Mot);




    // saisie de l'emplacement
    printf("Entrer la ligne :");
    scanf("%d", &ligne);
    printf("Entrer la colonne(Lettres) :");
    scanf(" %c", &colonnes);
    printf("Entrez l'orientation (Vertical/Horizontal) :\n");
    scanf(" %c", &orientation);

    printf("ligne %d colonnes %c orientation %c\n", ligne, colonnes, orientation);
    // verification du placement
    if (orientation == 'V' && (ligne + strlen(Mot) - 1 > 15)) {
        printf("Le placement du mot est non valide : Le mot dépasse la limite du plateau.\n");
        return 0;
    } else if (orientation == 'H' && (colonnes - 'A' + strlen(Mot)) - 1 > 15) {
        printf("Le placement du mot est non valide : Le mot dépasse la limite du plateau.\n");
        return 0;
    }
    // testttttttt pour faire en sorte que le mot soit placer sur la case centrale #
    /* if (ligne == 7 && colonnes == 'H' && Mot[0] != 'A') {
         printf("Le 1er mot doit commencer sur la case centrale (motif #).\n ");
         return 0;
     }*/
    int motscore = 0;
    int multiplicateurmot = 1;

    for (int i = 0; i < strlen(Mot); i++) {
        int lettrescore = chevalet[i].jeton.valeur;

        // verification des multiplicateurs de lettres
        if (tab[ligne - 1 + i][colonnes - 'A'] == '&') {
            lettrescore *= 2;
        } else if (tab[ligne - 1 + i][colonnes - 'A'] == '%') {
            lettrescore *= 3;
        }
        // ajoute du score de la lettre aua score du mot
        motscore += lettrescore;
    }
    // verification des multiplicateurs de mot
    if (tab[ligne - 1][colonnes - 'A'] == '@') {
        multiplicateurmot *= 2;
        // motscore *= 2; // doubler le mot
    }
        // probleme d'affichage du charactere §
    else if (tab[ligne - 1][colonnes - 'A'] == '6') { // normalement §
        multiplicateurmot *= 3;
    }
    // calcul du score final du mot
    motscore *= multiplicateurmot;

    printf("score du mot |%s| avec multiplicateur : %d points\n", Mot, motscore);

    // prime pour un scrabble
    motscore = calculscorechaquejoueur(Mot);
    if (strlen(Mot) == tailleChevalet) {   // tout les mots sont deposés dans le tableau
        printf("SCRABBLE ! Vous obtenez une prime de 50 points.\n");
        motscore += 50;
        printf("score du mot |%s| avec prime : %d points\n", Mot, motscore);
    }

    int motexiste = 0;
    for (int i = 0; i < strlen(Mot); i++) {
        if (orientation == 'V') {
            if (tab[ligne - 1 + i][colonnes - 'A'] != ' ' && tab[ligne - 1 + i][colonnes - 'A'] != Mot[i]) {
                motexiste = 1;
                break;
            }
        } else if (orientation == 'H') {
            if (tab[ligne - 1][colonnes - 'A' + i] != ' ' && tab[ligne - 1][colonnes - 'A' + i] != Mot[i]) {
                motexiste = 1;
                break;
            }
        }
    }
    if (!motexiste) {
        printf("Le mot ne s'appuie sur aucun mot déjà placé.\n");
        return 0;
    }

    // A FAIRE : le mot à placer se situe toujours sur le plateau (aucune lettre en dehors du plateau)
//• le 1er mot se positionne sur la case centrale (motif #)
//• le mot à placer a au moins une lettre en commun avec les mots placés sur le plateau. Par contre, il ne
//pourra pas écraser les lettres du plateau existante qui ne correspondent pas quand il se positionne sur
//le plateau (placement selon les mots croisés)

    for (int i = 0; i < strlen(Mot); i++) {
        if (orientation == 'V') {
            tab[ligne - 1 + i][colonnes -
                               'A'] = Mot[i]; // je vais changer A par sa valeur ascii 65 pour voir si ça marche
        } else if (orientation == 'H') {
            tab[ligne - 1][colonnes - 'A' + i] = Mot[i];
        }
    }
    // affichage du tableau aprés placement
    //tab[ligne][colonnes];

    affichertab(tab);


    // verification du mot a partir du dictionnaire.txt

    if (!existemot(Mot)) {
        printf("Le Mot |%s| n'est pas valide selon le dictionnaire.\n", Mot);
        return 0; // O par defaut juste pour verifier que le mot n'est pas present dans le dictionnaire
    } else {
        printf("Le Mot |%s| est valide selon le dictionnaire.\n", Mot);
        return 1;
    }

    // calcule score du mot
    // calcul du score final du mot
    motscore *= multiplicateurmot;

    // prime pour un scrabble
    //motscore = calculscorechaquejoueur(Mot);
    if (strlen(Mot) == tailleChevalet) {   // tout les mots sont deposés dans le tableau
        printf("SCRABBLE ! Vous obtenez une prime de 50 points.");
        motscore += 50;
    }
    //printf("score du mot |%s| : %d points\n",Mot,motscore);

    int scoremot = calculscorechaquejoueur(Mot);
    printf("Le score du mot |%s| est :%d points\n", Mot, scoremot);

    // affichage du score totale du joueur qui est la somme des mots placés a partir du chevalet
    int scoretotal = 0;
    for (int i = 0; i < tailleChevalet; i++) { // A REVOIR
        scoretotal += scoremot;//calculscorechaquejoueur(Mot);
    }
    printf("Le score totale du joueur est :%d points\n", scoretotal);
    return 1;

}

void nouvellepartie(joueurs tab2[], int nombre, char tab[15][15]) {
    //char tab[15][15]; // initialisation du tableau
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
        printf("Chevalet de %s est :", tab1[i].nom);// Les 7 jetons de chaqe nom s'affiche
        for (int i = 0; i < tailleChevalet; i++) {
            printf("%c%d ", chevalet[i].jeton.lettre, chevalet[i].jeton.valeur);
        }
        printf("\n");
    }


    for (int i = 0; i < nombre; i++) {
        printf("%s :\n", tab1[i].nom);
        placerMot(tab, chevalet, tailleChevalet);
    }
    // calcul score

    for (int i = 0; i < nombre; i++) {
        printf("Le score du joueur %s est : %d points\n", tab1[i].nom, calculscorechaquejoueur(tab1[i].nom));
    }
}

void affichermenu() {
    printf("            MENU :        \n");
    printf("\n");
    printf("1. Lancer une nouvelle partie.\n");
    printf("2. Afficher l'aide.\n");
    printf("3. Afficher les scores des Joueurs.\n");
    printf("4. Quitter le Jeu.\n");
}

void afficheraide() {
    printf("Bienvenue dans le jeu Scrabble !\n");
    printf("Instructions :\n");
    printf("1. Le premier mot doit faire aumoins deux lettres et recouvrir la case centrale.\n ");
    printf("2. Le mot suivant doit s'appuyer sur des mots déjà placer comme des mots croisés.\n");
    printf("3. Les cases de couleurs sur la grille permettent de multiplier la valeur des lettres/mots.\n");
    printf("4. Il n'est pas possible de poser un mot en diagonale.\n");
    printf("5. Lorsque on place toutes ses lettres qui sont sur le chevalet on fait un SCRABBLE et on gagne 50 points supplementaire.\n");
    printf("6. Le vainqueur est le joueur qui cummule le plus de point a la fin de la partie.\n");
    printf("7. Chaque lettre saisie par le joueur doit être en majuscule.\n");
    printf("# : point de départ\n ");
    printf("& : lettre double\n");
    printf(" § : mot triple\n");
    printf(" @ : mot double\n");


}

int calculscorechaquejoueur(char Mot[50]) {
    // declaration des variables
    char lettre;
    int nombre;

    int valeursenpoints[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 10, 1, 2, 1, 1, 3, 8, 1, 1, 1, 1, 4, 10, 10, 10, 10,
                             0};//int valeurs_en_points_des_lettres[26] = {1,3,3,2,1,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    //placerMot(tab);
    int score = 0; // initialisation du score a zero
    for (int i = 0;
         i < strlen(Mot); i++) { // cette boucle permet calculer le score depuis la prémière letter jusqu'au dernier
        // lettre = Mot[i] - 'A'; // est utilisé pour convertir une lettre en majuscule en un nombre correspondant à sa position dans l'alphabet
        // score = score + valeursenpoints[lettre];
        lettre = Mot[i];
        if ((lettre >= 'A' && lettre <= 'Z') ||
            (lettre >= 'a' && lettre <= 'z')) { // si la lettre est une majuscule ou en minuscule le score sera ajouter
            if (lettre >= 'a' && lettre <= 'z') {
                lettre = lettre - 'a' + 'A';
            }
            score += valeursenpoints[lettre - 'A'];
        }

    }
    return score;
}

// temps de jeu aprés chaque coups // A VERIFIER
// Probleme : ne s'affiche pas
void jouertouravecchronometre(char tab[15][15], int tailleChevalet, jetonChevalet chevalet[]) {
    clock_t debut, fin;
    double tempsecoule;

    debut = clock();
    placerMot(tab, chevalet, tailleChevalet);

    fin = clock();
    tempsecoule = ((double) (fin - debut)) / CLOCKS_PER_SEC;
    // verification du temps écoulé
    if (tempsecoule > tempslimite) {
        printf("Le temps est écoulé. Fin de partie pour ce joueur.\n");

    }
}


double chrono() {
    return (double) clock() / CLOCKS_PER_SEC;
}

// lecture du dictionnaire creer dans Dictionnaire.txt



/* probleme :
- Le placement du mot se fait uniqument sur la ligne de K peu importe la valeur de la ligne qu'on indique ( probleme resolu )
- Aucune saisir n'est prit en compte pour l'orientation a la horizontal ( probleme resolu )
- Le importe la valeur de la ligne et la colonnes le palcement se fait uniquement sur la ligne de K ( probleme resolu )
- On a pas pu saisir les deux charactere #A
-probleme d'affichage du charactere §
- le choix 3 du menu n'affichent pas le score des differents joueur
 - J'arrive pas a integrer une logique pour la partie avec l'IA
 - Le temps pour chaque coup ne secoulent pas comme dans une montre


 decouverte :
 le tableau aprés le placement du mot commence a partir de 6 pour les lignes (probleme resolu )
 - LE score aprés l multiplication ne fonctionne pas sauf quand le score du mot placer est egal à 6 ( probleme resolu)
 - la multiplication n'est correcte que sur la vertical et fausse sur rla horizontal ( probleme resolu)

*/