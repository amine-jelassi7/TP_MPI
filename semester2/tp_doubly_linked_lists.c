#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud* suivant;
    struct Noeud* prev;
} Noeud;

typedef Noeud* liste;

liste creation() {
    return (NULL);
}

liste insert_deb(liste list, int val) {
    liste l = (liste)malloc(sizeof(Noeud));
    l->valeur = val;
    l->prev = NULL;
    l->suivant = NULL;
    if (list == NULL) return l;
    l->suivant = list;
    list->prev = l;
    return l;
}

void affichage(liste list) {
    liste li = list;
    if (li == NULL) {
        printf("liste vide\n");
        return;
    }
    while (li != NULL) {
        printf("%d ", li->valeur);
        li = li->suivant;
    }
    printf("\t");
}

void afficher(liste list) {
    liste li, l;
    li = list;
    if (li == NULL) {
        printf("liste vide\n");
        return;
    }
    while (li->suivant != NULL)
        li = li->suivant;
    l = li;
    while (l != NULL) {
        printf("%d ", l->valeur);
        l = l->prev;
    }
    printf("\n");
}

int longueur(liste list) {
    int lg = 0;
    liste li = list;
    while (li != NULL) {
        lg++;
        li = li->suivant;
    }
    return (lg);
}

liste insert_fin(liste list, int val) {
    liste li = list;
    liste lf = (liste)malloc(sizeof(Noeud));
    lf->valeur = val;
    lf->suivant = NULL;
    lf->prev = NULL;
    if (list == NULL) return lf;
    while (li->suivant != NULL) {
        li = li->suivant;
    }
    lf->prev = li;
    li->suivant = lf;
    return (list);
}

liste suppdeb(liste list) {
    if (list == NULL) return NULL;
    liste li = list->suivant;
    if (li != NULL) li->prev = NULL;
    free(list);
    return (li);
}

liste suppfin(liste list) {
    if (list == NULL) return NULL;
    if (list->suivant == NULL) {
        free(list);
        return NULL;
    }
    liste li = list;
    liste l = NULL;
    while (li->suivant != NULL) {
        l = li;
        li = li->suivant;
    }
    l->suivant = NULL;
    free(li);
    return (list);
}

liste inserpos(liste list, int pos, int val) {
    if (pos == 0) return insert_deb(list, val);
    int i;
    liste a = list;
    liste l = (liste)malloc(sizeof(Noeud));
    l->valeur = val;
    for (i = 0; i < pos - 1 && a != NULL; i++) {
        a = a->suivant;
    }
    if (a == NULL) return list;
    liste b = a->suivant;
    a->suivant = l;
    l->suivant = b;
    l->prev = a;
    if (b != NULL) b->prev = l;
    return (list);
}

liste insert(liste l, int p, int x) {
    if (p == 0) return insert_deb(l, x);
    if (p >= longueur(l) - 1) return insert_fin(l, x);
    return inserpos(l, p, x);
}

liste suppos(liste list, int pos) {
    if (pos == 0) return suppdeb(list);
    int i;
    liste a = list;
    for (i = 0; i < pos && a != NULL; i++) {
        a = a->suivant;
    }
    if (a == NULL) return list;
    liste l = a->prev;
    liste 11 = a->suivant;
    if (l != NULL) l->suivant = 11;
    if (11 != NULL) 11->prev = l;
    free(a);
    return (list);
}

liste supp(liste l, int p) {
    if (p == 0) return suppdeb(l);
    if (p >= longueur(l) - 1) return suppfin(l);
    return suppos(l, p);
}

void affiche_node(liste l, int p) {
    if (l == NULL) {
        printf("La liste est vide\n");
        return;
    }
    int i;
    liste 11 = l;
    for (i = 0; i < p && 11 != NULL; i++)
        11 = 11->suivant;
    if (11 == NULL) return;

    printf("Noeud = %d\t", 11->valeur);
    if (11->suivant == NULL) printf("Noeud suivant est vide\t\t");
    else printf("Noeud suivant = %d\t\t", (11->suivant)->valeur);

    if (11->prev == NULL) printf("Noeud precedent est vide\t\t");
    else printf("Noeud precedent = %d\t", (11->prev)->valeur);
    printf("\n");
}

int main() {
    liste li = NULL;
    li = insert_deb(li, 1);
    li = insert_deb(li, 2);
    li = insert_deb(li, 3);
    affichage(li);
    afficher(li);

    printf("la longueur de la liste %d\n", (longueur(li)));
    li = insert_fin(li, 1);
    li = insert_fin(li, 2);
    li = insert_fin(li, 3);
    affichage(li);
    afficher(li);

    li = (suppdeb(li));
    printf("apres la supp du debut : ");
    affichage(li);
    afficher(li);

    li = (suppfin(li));
    printf("apres la supp du fin : ");
    affichage(li);
    afficher(li);

    li = insert(li, 2, 99);
    printf("liste apres insertion : ");
    affichage(li);
    afficher(li);

    li = suppos(li, 1);
    printf("liste apres supp : ");
    affichage(li);
    afficher(li);

    affiche_node(li, 2);
    affiche_node(li, 0);
    affiche_node(li, longueur(li) - 1);

    return 0;
}