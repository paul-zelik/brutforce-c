#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

char motdepasse[50]; // ! Mot de passe enregstré
char newchaine[50] = "";  // ? Nouvelle Chaine de Caractère
char chaine[] = "abcdefghijklmnopqrstuvwxyz";  // * Liste des Char disponibles
int longueurmdp, possibilite, iteration = 0, count = 0;
char tentative[50];


bool lookchar() {

    int nb = 0;

    printf("\nLa longueur de mot de passe est %ld\n", strlen(motdepasse));
    for (int i=0; motdepasse[i] != '\0'; i++) {
        for (int j = 0; chaine[j] != '\0'; j++) {
            if (motdepasse[i] == chaine[j]) {
                nb++;
            }
        }
    }
    if (nb == strlen(motdepasse)) {
        return true;
    } else {
        return false;
    }
}

bool longueur() {
    if (strlen(motdepasse) >= 0) {
        return true;
    } else {
        return false;
    }
}


char* gen() {

    int longalpha = 26;
    char localchaine[50];
    int index;


    int local_count = count; // * sqhdqsidq
    int indice;


    for(int i=0; i < longueurmdp; i++) {
        index = local_count % longalpha;
        localchaine[i] = chaine[index];
        local_count /= longalpha;
        indice = i;
    }

    count++;
    localchaine[indice + 1] = '\0';
    printf("%s", localchaine);

    return localchaine;
}


bool checkmdp() {
    if (longueur() & lookchar()) {
        return true;
    } else {
        return false;
    }
}


int main()
{
    printf("Votre mot de passe : ");
    scanf("%s", motdepasse);

    while (!(checkmdp()))
    {
        printf("\nVotre mot de passe ne respecte pas les règles. Nouveau Mot de passe :");
        scanf("%s", motdepasse); 
    }
    

    printf("\nMots de passe corecte. Mot de passe enregistré.");

    longueurmdp = strlen(motdepasse);
    int literation = 0;

    while (strcmp(motdepasse, newchaine) != 0)
    {

        tentative[50] = gen();

        strcpy(newchaine, tentative);

        literation++;
        printf("\nNouvelle tentative, tentative n°%d : %s", literation, tentative);
    }
        

    printf("\nFin du Code");
    return 0;
}
