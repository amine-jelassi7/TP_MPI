#include <stdio.h>
#include <string.h>

// Exercice 1
void exercice1() {
    char ch[100];
    int i = 0, maj = 0, min = 0;
    printf("Entrez une chaine : ");
    scanf(" %[^\n]", ch);
    while (ch[i] != '\0') {
        if (ch[i] >= 'A' && ch[i] <= 'Z') {
            maj++;
        } else if (ch[i] >= 'a' && ch[i] <= 'z') {
            min++;
        }
        i++;
    }
    printf("Nombre de majuscules : %d\n", maj);
    printf("Nombre de minuscules : %d\n", min);
}

// Exercice 2
void exercice2() {
    char ch[100], res[100];
    int i = 0, j = 0;
    printf("Entrez une chaine : ");
    scanf(" %[^\n]", ch);
    while (ch[i] != '\0') {
        if (ch[i] != ' ') {
            res[j++] = ch[i];
        }
        i++;
    }
    res[j] = '\0';
    printf("Sortie : \"%s\"\n", res);
}

// Exercice 3
void exercice3() {
    char ch1[100], ch2[100];
    int i = 0, egales = 1;
    printf("Entrez la premiere chaine : ");
    scanf(" %[^\n]", ch1);
    printf("Entrez la deuxieme chaine : ");
    scanf(" %[^\n]", ch2);

    while (ch1[i] != '\0' && ch2[i] != '\0') {
        if (ch1[i] != ch2[i]) {
            egales = 0;
            break;
        }
        i++;
    }
    if (ch1[i] != '\0' || ch2[i] != '\0') {
        egales = 0;
    }

    if (egales) {
        printf("Les chaines sont identiques.\n");
    } else {
        printf("Les chaines sont différentes.\n");
    }
}

int main() {

    printf("===========================================\n");
    printf("            TP 3 - Part I     \n");
    printf("===========================================\n\n");


    exercice1();
    exercice2();
    exercice3();
    return 0;
}