#include <stdio.h>

/*
   ====================================================================
   EXERCICE 6
   ====================================================================
*/
void exercice6() {
    int n, choix;

    printf("--- Exercice 6 ---\n");
    printf("Donner un entier : ");
    scanf("%d", &n);

    printf("\nMenu :\n");
    printf("1. Addition de 2\n");
    printf("2. Soustraction de 2\n");
    printf("3. Multiplier par 2\n");
    printf("4. Diviser par 2\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            printf("Resultat : %d + 2 = %d\n", n, n + 2);
            break;
        case 2:
            printf("Resultat : %d - 2 = %d\n", n, n - 2);
            break;
        case 3:
            printf("Resultat : %d * 2 = %d\n", n, n * 2);
            break;
        case 4:
            printf("Resultat : %d / 2 = %.2f\n", n, (float)n / 2);
            break;
        default:
            printf("Erreur : Choix invalide !\n");
            break;
    }
}

/*
   ====================================================================
   EXERCICE 7
   ====================================================================
*/
void exercice7() {
    float moyenne;

    printf("\n--- Exercice 7 ---\n");
    printf("Saisissez votre moyenne : ");
    scanf("%f", &moyenne);

    if (moyenne < 10.0 || moyenne > 20.0) {
        printf("Erreur : La moyenne doit etre comprise entre 10 et 20.\n");
    } else {
        int tranche = (int)moyenne;
        switch (tranche) {
            case 10:
            case 11:
                printf("Mention : Passable\n");
                break;
            case 12:
            case 13:
                printf("Mention : Assez Bien\n");
                break;
            case 14:
            case 15:
                printf("Mention : Bien\n");
                break;
            default: // de 16 a 20
                printf("Mention : Tres Bien\n");
                break;
        }
    }
}

/*
   ====================================================================
   EXERCICE 8
   ====================================================================
*/
void exercice8() {
    int N, i, val;
    int somme = 0, max = 0, pos_max = 1;
    float moyenne;

    printf("\n--- Exercice 8 ---\n");
    do {
        printf("Entrez un nombre N (positif) : ");
        scanf("%d", &N);
    } while (N <= 0);

    for (i = 1; i <= N; i++) {
        do {
            printf("Entrez le nombre %d (entre -100 et 100) : ", i);
            scanf("%d", &val);
        } while (val < -100 || val > 100);

        somme += val;

        if (i == 1 || val > max) {
            max = val;
            pos_max = i;
        }
    }

    moyenne = (float)somme / N;

    printf("\nResultats :\n");
    printf("Somme : %d\n", somme);
    printf("Moyenne : %.2f\n", moyenne);
    printf("Le plus grand nombre est : %d (saisi en position %d)\n", max, pos_max);
}

/*
   ====================================================================
   EXERCICE 9 (Nombre Premier)
   ====================================================================
*/
void exercice9() {
    int n, i, est_premier = 1;

    printf("\n--- Exercice 9 ---\n");
    printf("Entrez un entier positif : ");
    scanf("%d", &n);

    if (n <= 1) {
        est_premier = 0;
    } else {
        for (i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                est_premier = 0;
                break;
            }
        }
    }

    if (est_premier) {
        printf("%d est un nombre premier.\n", n);
    } else {
        printf("%d n'est pas un nombre premier.\n", n);
    }
}

/*
   ====================================================================
   EXERCICE 10 (Tables de Multiplication)
   ====================================================================
*/
void exercice10_question1() {
    int i, j;
    printf("\n--- Exercice 10 (Question 1) ---\n");
    for (i = 1; i <= 9; i++) {
        printf("x%d = ", i);
        for (j = 1; j <= 9; j++) {
            printf("%d ", i * j);
        }
        printf("\n");
    }
}

void exercice10_question2() {
    int m, n, i, j;

    printf("\n--- Exercice 10 (Question 2) ---\n");
    do {
        printf("Entrez m (nombre de tables, m <= 20) : ");
        scanf("%d", &m);
    } while (m < 1 || m > 20);

    printf("Entrez n (nombre d'elements par table) : ");
    scanf("%d", &n);

    for (i = 1; i <= m; i++) {
        printf("x%d = ", i);
        for (j = 1; j <= n; j++) {
            printf("%d ", i * j);
        }
        printf("\n");
    }
}

int main(void) {
    printf("===========================================\n");
    printf("            TP 1 - PARTIE II               \n");
    printf("===========================================\n");

    exercice6();
    exercice7();
    exercice8();
    exercice9();
    exercice10_question1();
    exercice10_question2();

    return 0;
}