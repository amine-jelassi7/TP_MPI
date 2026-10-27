#include <stdio.h>
#include <stdlib.h>

typedef struct noeud {
    int val;
    struct noeud *next;
} noeud;

typedef noeud* liste;

liste creation() {
    return NULL;
}

liste insertion_deb(liste l, int x) {
    liste l1 = (liste)malloc(sizeof(noeud));
    if (l == NULL) {
        l1->val = x;
        l1->next = NULL;
        return l1;
    }
    l1->val = x;
    l1->next = l;
    return l1;
}

void affichage_list(liste l) {
    if (l == NULL) {
        printf("La liste est vide\n");
        return;
    }
    liste temp = l;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int longueur(liste l) {
    if (l == NULL) return 0;
    int s = 0;
    liste temp = l;
    while (temp != NULL) {
        s++;
        temp = temp->next;
    }
    return s;
}

liste insertion_fin(liste l, int x) {
    liste l1 = (liste)malloc(sizeof(noeud));
    l1->val = x;
    l1->next = NULL;
    if (l == NULL) return l1;
    liste l2 = l;
    while (l2->next != NULL) {
        l2 = l2->next;
    }
    l2->next = l1;
    return l;
}

liste suppression_deb(liste l) {
    if (l == NULL) return NULL;
    liste l1 = l->next;
    free(l);
    return l1;
}

liste suppression_fin(liste l) {
    if (l == NULL) return NULL;
    if (l->next == NULL) {
        free(l);
        return NULL;
    }
    liste l1 = l, l2 = NULL;
    while (l1->next != NULL) {
        l2 = l1;
        l1 = l1->next;
    }
    l2->next = NULL;
    free(l1);
    return l;
}

liste insertion_pos(liste l, int pos, int x) {
    liste l1 = (liste)malloc(sizeof(noeud));
    l1->val = x;
    if (pos == 0) {
        free(l1);
        return insertion_deb(l, x);
    }
    int s = 0;
    liste l2 = l, l3 = NULL;
    while (s < pos && l2 != NULL) {
        s++;
        l3 = l2;
        l2 = l2->next;
    }
    l3->next = l1;
    l1->next = l2;
    return l;
}

liste suppression_pos(liste l, int pos) {
    if (l == NULL) return NULL;
    if (pos == 0) return suppression_deb(l);
    int s = 1;
    liste l1 = l->next, l2 = l;
    while (s < pos && l1 != NULL) {
        s++;
        l2 = l1;
        l1 = l1->next;
    }
    if (l1 == NULL) return l;
    l2->next = l1->next;
    free(l1);
    return l;
}

liste insertion(liste l, int x, int pos) {
    if (pos == 0) return insertion_deb(l, x);
    if (pos >= longueur(l)) return insertion_fin(l, x);
    return insertion_pos(l, pos, x);
}

liste suppression(liste l, int pos) {
    if (pos == 0) return suppression_deb(l);
    if (pos >= longueur(l) - 1) return suppression_fin(l);
    return suppression_pos(l, pos);
}

int main() {
    liste l;
    printf("Tache 1 : \n");
    l = creation();
    printf("Insertion debut : \n");
    l = insertion_deb(l, 5);
    l = insertion_deb(l, 4);
    l = insertion_deb(l, 3);
    affichage_list(l);

    printf("Tache 2 : \n");
    printf("La longueur de la liste = %d\n", longueur(l));

    printf("Tache 3 : \n");
    printf("Insertion fin : \n");
    l = insertion_fin(l, 6);
    l = insertion_fin(l, 7);
    l = insertion_fin(l, 8);
    affichage_list(l);

    printf("Tache 4 : \n");
    printf("Suppression debut : \n");
    l = suppression_deb(l);
    affichage_list(l);
    printf("Suppression fin : \n");
    l = suppression_fin(l);
    affichage_list(l);

    printf("Tache 5 : \n");
    int x, x1;
    printf("Donnez la position : ");
    scanf("%d", &x);
    printf("Insertion de la valeur dans la position %d : \n", x);
    l = insertion(l, 99, x);
    affichage_list(l);

    printf("Donnez la position a supprimer : ");
    scanf("%d", &x1);
    printf("Suppression de la valeur dans la position %d : \n", x1);
    l = suppression(l, x1);
    affichage_list(l);

    return 0;
}