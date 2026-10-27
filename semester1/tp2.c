#include <stdio.h>

/*
   ====================================================================
   EXERCICE 1 : Tableaux à une dimension (Tableau d'entiers)
   ====================================================================
*/
void exercice1() {
    int T[50];
    int N, i;
    int somme = 0;
    int max, min, pos_max = 0, pos_min = 0;

    printf("--- Exercice 1 ---\n");

    do {
        printf("Entrez la dimension reelle N (entre 1 et 50) : ");
        scanf("%d", &N);
    } while (N < 1 || N > 50);

    printf("Entrez les %d elements du tableau :\n", N);
    for (i = 0; i < N; i++) {
        printf("T[%d] = ", i);
        scanf("%d", &T[i]);
    }

    printf("Tableau saisi : T = [ ");
    for (i = 0; i < N; i++) {
        printf("%d ", T[i]);
    }
    printf("]\n");

    max = T[0];
    min = T[0];
    pos_max = 0;
    pos_min = 0;
    somme = T[0];

    for (i = 1; i < N; i++) {
        somme += T[i];
        if (T[i] > max) {
            max = T[i];
            pos_max = i;
        }
        if (T[i] < min) {
            min = T[i];
            pos_min = i;
        }
    }

    printf("La somme des entiers est : %d\n", somme);
    printf("La position du maximum est : %d\n", pos_max + 1);
    printf("La position du minimum est : %d\n", pos_min + 1);

    for (i = 0; i < N / 2; i++) {
        int temp = T[i];
        T[i] = T[N - 1 - i];
        T[N - 1 - i] = temp;
    }

    printf("Tableau inverse : T = [ ");
    for (i = 0; i < N; i++) {
        printf("%d ", T[i]);
    }
    printf("]\n\n");
}

/*
   ====================================================================
   EXERCICE 2 : Tableau de caractères et recherche
   ====================================================================
*/
void exercice2() {
    char Tchar[50];
    int N, i;
    char car;
    int trouve = 0;

    printf("--- Exercice 2 ---\n");
    do {
        printf("Entrez le nombre de caracteres (entre 1 et 50) : ");
        scanf("%d", &N);
    } while (N < 1 || N > 50);

    printf("Entrez les caracteres :\n");
    for (i = 0; i < N; i++) {
        printf("Tchar[%d] = ", i);
        scanf(" %c", &Tchar[i]);
    }

    printf("Tableau : ");
    for (i = 0; i < N; i++) {
        printf("%c ", Tchar[i]);
    }
    printf("\n");

    // Recherche d'un caractère
    printf("Entrez un caractere à rechercher : ");
    scanf(" %c", &car);

    for (i = 0; i < N; i++) {
        if (Tchar[i] == car) {
            trouve = 1;
            break;
        }
    }

    if (trouve) {
        printf("Le caractere '%c' existe dans le tableau.\n\n", car);
    } else {
        printf("Le caractere '%c' n'existe pas dans le tableau.\n\n", car);
    }
}

/*
   ====================================================================
   EXERCICE 3 : Fusion de deux tableaux triés
   ====================================================================
*/
void exercice3() {
    float Tgr1[50], Tgr2[50], TAmphi[100];
    int N, M, i = 0, j = 0, k = 0;

    printf("--- Exercice 3 ---\n");

    do {
        printf("Nombre d'etudiants dans Tgr1 (N <= 50) : ");
        scanf("%d", &N);
    } while (N < 1 || N > 50);

    printf("Entrez les moyennes de Tgr1 (triees par ordre croissant) :\n");
    for (i = 0; i < N; i++) {
        scanf("%f", &Tgr1[i]);
    }

    do {
        printf("Nombre d'etudiants dans Tgr2 (M <= 50) : ");
        scanf("%d", &M);
    } while (M < 1 || M > 50);

    printf("Entrez les moyennes de Tgr2 (triees par ordre croissant) :\n");
    for (i = 0; i < M; i++) {
        scanf("%f", &Tgr2[i]);
    }

    i = 0;
    j = 0;
    k = 0;
    while (i < N && j < M) {
        if (Tgr1[i] < Tgr2[j]) {
            TAmphi[k++] = Tgr1[i++];
        } else {
            TAmphi[k++] = Tgr2[j++];
        }
    }
    while (i < N) {
        TAmphi[k++] = Tgr1[i++];
    }
    while (j < M) {
        TAmphi[k++] = Tgr2[j++];
    }

    printf("Tableau TAmphi fusionne et trie : [ ");
    for (i = 0; i < N + M; i++) {
        printf("%.2f ", TAmphi[i]);
    }
    printf("]\n");

    printf("La mauvaise moyenne dans l'amphi est : %.2f\n", TAmphi[0]);
    printf("La meilleure moyenne dans l'amphi est : %.2f\n\n", TAmphi[N + M - 1]);
}

/*
   ====================================================================
   EXERCICE 4 : Tableau à deux dimensions (4x4)
   ====================================================================
*/
void exercice4() {
    int T2D[4][4];
    int i, j, k;
    int trouve_point_selle = 0;

    printf("--- Exercice 4 ---\n");
    printf("Remplissage du tableau 4x4 :\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("T2D[%d][%d] = ", i, j);
            scanf("%d", &T2D[i][j]);
        }
    }

    printf("Tableau 4x4 :\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d\t", T2D[i][j]);
        }
        printf("\n");
    }

    printf("Recherche des elements max sur leur ligne et min sur leur colonne :\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            int element = T2D[i][j];

            int est_max_ligne = 1;
            for (k = 0; k < 4; k++) {
                if (T2D[i][k] > element) {
                    est_max_ligne = 0;
                    break;
                }
            }

            int est_min_col = 1;
            for (k = 0; k < 4; k++) {
                if (T2D[k][j] < element) {
                    est_min_col = 0;
                    break;
                }
            }
            
            if (est_max_ligne && est_min_col) {
                printf(" -> Element %d trouve a la position [%d][%d]\n", element, i, j);
                trouve_point_selle = 1;
            }
        }
    }

    if (!trouve_point_selle) {
        printf("Aucun element ne satisfait cette condition.\n");
    }
    printf("\n");
}

int main(void) {
    printf("===========================================\n");
    printf("            TP 2 - PROGRAMME PRINCIPAL     \n");
    printf("===========================================\n\n");

    exercice1();
    exercice2();
    exercice3();
    exercice4();

    return 0;
}