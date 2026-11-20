#include <stdio.h>

#define FICHIER_MOTS "mots.txt"
#define NB_MOTS_MAX 20
#define LONGEUR_MAX 20

void interface()
{
    printf("Bienvenue dans le jeu du PENDU\n"); //<-mehdi
}


int est_lettre(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
} // renvoie 1 si c est une lettre

int migration_mots(char mots[][LONGEUR_MAX])
{
    FILE *f = fopen(FICHIER_MOTS, "r");
    if (f == 0)
    {
        printf("Impossible d'ouvrir le fichier mots");
        return 0;
    }

    int nb = 0;
    char ligne[LONGEUR_MAX];

    while (fgets(ligne, LONGEUR_MAX, f) != 0)
    {
        if (nb == NB_MOTS_MAX)
        {
            break;
        }

        if (ligne[strlen(ligne) - 1] == '\n')
        {
            ligne[strlen(ligne) - 1] = '\0';
        }

        if (strlen(ligne) > 0)
        {
            strcpy(mots[nb], ligne);
            nb++;
        }
    }
    fclose(f);
    return nb;

}

int main()
{
    interface();
    char mots[NB_MOTS_MAX][LONGEUR_MAX];

    int nb_mots = migration_mots(mots);
    if (nb_mots == 0) {
        printf("Aucun mot dans fichier texte");
        return 1;
    }


    for (int i = 0; i < nb_mots; i++)
        printf("%d : %s\n", i, mots[i]);

    return 0;

}