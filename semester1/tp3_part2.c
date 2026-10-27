#include <stdio.h>
#include <stdlib.h>

// Exercice 4
void exercice4() {
    int n, x, i, j;
    printf("Entrez la taille du tableau : ");
    scanf("%d", &n);
    int *A = (int *)malloc(n * sizeof(int));
    printf("Entrez les elements :\n");
    for (i = 0; i < n; i++) {
        scanf("%d", A + i);
    }
    printf("Entrez l'entier X a eliminer : ");
    scanf("%d", &x);

    i = 0;
    while (i < n) {
        if (*(A + i) == x) {
            for (j = i; j < n - 1; j++) {
                *(A + j) = *(A + j + 1);
            }
            n--;
        } else {
            i++;
        }
    }

    printf("Tableau apres tassement : ");
    for (i = 0; i < n; i++) {
        printf("%d ", *(A + i));
    }
    printf("\n");
    free(A);
}

// Exercice 5
void exercice5() {
    int n, aide;
    printf("Entrez le nombre d'elements : ");
    scanf("%d", &n);
    int *A = (int *)malloc(n * sizeof(int));
    printf("Entrez les elements :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", A + i);
    }

    int *p1 = A;
    int *p2 = A + n - 1;
    while (p1 < p2) {
        aide = *p1;
        *p1 = *p2;
        *p2 = aide;
        p1++;
        p2--;
    }

    printf("Tableau inverse : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(A + i));
    }
    printf("\n");
    free(A);
}

// Exercice 6
void exercice6() {
    int n, m, i;
    printf("Entrez la dimension de A : ");
    scanf("%d", &n);
    printf("Entrez la dimension de B : ");
    scanf("%d", &m);

    int *A = (int *)malloc((n + m) * sizeof(int));
    int *B = (int *)malloc(m * sizeof(int));

    printf("Entrez les elements de A :\n");
    for (i = 0; i < n; i++) {
        scanf("%d", A + i);
    }
    printf("Entrez les elements de B :\n");
    for (i = 0; i < m; i++) {
        scanf("%d", B + i);
    }

    int *pa = A + n;
    int *pb = B;
    for (i = 0; i < m; i++) {
        *pa = *pb;
        pa++;
        pb++;
    }

    printf("Tableau resultant A : ");
    for (i = 0; i < n + m; i++) {
        printf("%d ", *(A + i));
    }
    printf("\n");

    free(A);
    free(B);
}

// Exercice 7
void exercice7() {
    int n, i, j;
    float temp;
    printf("Entrez la dimension n : ");
    scanf("%d", &n);
    float *T = (float *)malloc(n * sizeof(float));

    printf("Entrez les elements du tableau de reels :\n");
    for (i = 0; i < n; i++) {
        scanf("%f", T + i);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (*(T + j) > *(T + j + 1)) {
                temp = *(T + j);
                *(T + j) = *(T + j + 1);
                *(T + j + 1) = temp;
            }
        }
    }

    printf("Tableau trie : ");
    for (i = 0; i < n; i++) {
        printf("%.2f ", *(T + i));
    }
    printf("\n");

    free(T);
}

int main() {

    printf("===========================================\n");
    printf("            TP 3 - Part II     \n");
    printf("===========================================\n\n");


    exercice4();
    exercice5();
    exercice6();
    exercice7();
    return 0;
}