#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Exercice 8
char * miroir(char * s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
    return s;
}

// Exercice 9
void transformerChaine(char * ch, int * maj, int * min) {
    *maj = 0;
    *min = 0;
    int i = 0;
    while (ch[i] != '\0') {
        if (ch[i] >= 'A' && ch[i] <= 'Z') {
            ch[i] = ch[i] + 32;
            (*maj)++;
        } else if (ch[i] >= 'a' && ch[i] <= 'z') {
            ch[i] = ch[i] - 32;
            (*min)++;
        }
        i++;
    }
}

// Exercice 10
void concatenerChaines(char * ch1, char * ch2, char * ch3) {
    int cmp = strcmp(ch1, ch2);
    if (cmp < 0) {
        strcpy(ch3, ch1);
        strcat(ch3, ch2);
    } else if (cmp > 0) {
        strcpy(ch3, ch2);
        strcat(ch3, ch1);
    } else {
        strcpy(ch3, ch1);
    }
}

// Exercice 11
int compterMots(char * ch, int N, char ** adresse_mot) {
    int count = 0;
    int in_word = 0;
    int i = 0;

    while (ch[i] != '\0') {
        if (ch[i] != ' ' && ch[i] != '\t' && ch[i] != '\n') {
            if (!in_word) {
                in_word = 1;
                count++;
                if (count == N) {
                    *adresse_mot = &ch[i];
                }
            }
        } else {
            in_word = 0;
        }
        i++;
    }

    if (count > N) {
        return 1;
    }
    return 0;
}

int main() {

    printf("===========================================\n");
    printf("            TP 3 - Part III     \n");
    printf("===========================================\n\n");


    // Tests de verification
    char s[100] = "insat";
    printf("Miroir : %s\n", miroir(s));

    char ch9[100] = "Atelier C";
    int maj, min;
    transformerChaine(ch9, &maj, &min);
    printf("Transformee : %s (Maj: %d, Min: %d)\n", ch9, maj, min);

    char ch1[] = "abc";
    char ch2[] = "xyz";
    char ch3[200];
    concatenerChaines(ch1, ch2, ch3);
    printf("Concatene : %s\n", ch3);

    char ch11[100] = "Le genie logiciel a l'insat";
    char *addr = NULL;
    int res = compterMots(ch11, 3, &addr);
    printf("Resultat mots (> N) : %d, Adresse mot : %s\n", res, addr ? addr : "NULL");

    return 0;
}