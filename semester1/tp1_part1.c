#include <stdio.h>
#include <math.h>

/*
   ====================================================================
   EXERCICE 1
   ====================================================================
*/

void exercice1() {
    int a, b;
    float c;

    printf("--- Exercice 1 ---\n");
    printf("donner la valeur de a : ");
    scanf("%d", &a);
    printf("donner la valeur de b : ");
    scanf("%d", &b);

    a = a % b;
    c = (float)a / b;

    printf("La valeur de a est : %d\n", a);
    printf("La valeur de b est : %d\n", b);
    printf("La valeur de c est : %f\n", c);
}

/*
   ====================================================================
   EXERCICE 2
   ====================================================================
*/
void exercice2() {
    int a, b;

    printf("\n--- Exercice 2 ---\n");
    printf("Entrez le premier entier (a) : ");
    scanf("%d", &a);
    printf("Entrez le deuxieme entier (b != 0) : ");
    scanf("%d", &b);

    if (b != 0) {
        int quotient_entier = a / b;
        int reste = a % b;
        float quotient_rationnel = (float)a / b;

        printf("Quotient entier (a / b) = %d\n", quotient_entier);
        printf("Reste de la division (a %% b) = %d\n", reste);
        printf("Quotient rationnel (a / b) = %.2f\n", quotient_rationnel);
    } else {
        printf("Erreur : division par zéro impossible !\n");
    }
}

/*
   ====================================================================
   EXERCICE 3
   ====================================================================
*/
void exercice3() {
    int A, B, C, temp;

    printf("\n--- Exercice 3 ---\n");
    printf("Entrez A : ");
    scanf("%d", &A);
    printf("Entrez B : ");
    scanf("%d", &B);
    printf("Entrez C : ");
    scanf("%d", &C);

    printf("Avant permutation : A = %d, B = %d, C = %d\n", A, B, C);

    temp = A;
    A = B;
    B = C;
    C = temp;

    printf("Apres permutation (A<-B, B<-C, C<-A) : A = %d, B = %d, C = %d\n", A, B, C);
}

/*
   ====================================================================
   EXERCICE 4
   ====================================================================
*/
void exercice4() {
    char car;
    int ascii_code;

    printf("\n--- Exercice 4 ---\n");
    printf("Entrez un caractere : ");
    scanf(" %c", &car);

    ascii_code = (int)car;
    printf("Le code ASCII de '%c' est : %d\n", car, ascii_code);
}

/*
   ====================================================================
   EXERCICE 5
   ====================================================================
*/
void exercice5() {
    int XA, YA, XB, YB;
    double DIST;

    printf("\n--- Exercice 5 ---\n");
    printf("Entrez les coordonnees du point A (XA YA) : ");
    scanf("%d %d", &XA, &YA);
    printf("Entrez les coordonnees du point B (XB YB) : ");
    scanf("%d %d", &XB, &YB);

    DIST = sqrt(pow(XB - XA, 2) + pow(YB - YA, 2));
    printf("La distance DIST entre A et B est : %.2lf\n", DIST);
}

int main() {
    printf("===========================================\n");
    printf("            TP 1 - PARTIE I                \n");
    printf("===========================================\n");

    exercice1();
    exercice2();
    exercice3();
    exercice4();
    exercice5();

    return 0;
}