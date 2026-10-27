#include <stdio.h>
#include <stdlib.h>

typedef struct pile
{
    int valeur;
    struct pile *suivant;
}pile;

pile* creer(){
    return NULL;}
int estVide(pile *p){
    return !p;
}
pile * empiler(pile *p,int x){
    pile * new_nd=(pile*)malloc(sizeof(pile));
    new_nd->valeur=x;
    new_nd->suivant=NULL;

    if(estVide(p)) return new_nd;
    new_nd->suivant=p;

    return new_nd;
}
int depiler(pile **p){
    if(estVide(*p)) return -1;
    pile *temp=*p;
    int x=temp->valeur;
    *p=(*p)->suivant;
    free(temp);
    return x;}
int tete(pile *p){
    if(estVide(p)) return -1;
    return p->valeur;
}
int length(pile **p){
    pile *q=creer();
    int i=0;
    while(!estVide(*p)){
        int x=depiler(p);
        i++;
        q=empiler(q,x);
    }
    while(!estVide(q)){
        int x=depiler(&q);
        *p=empiler(*p,x);
    }
    return i;
}
void afficher(pile **p){
    pile *q=creer();
    while(!estVide(*p)){
        int x=depiler(p);
        printf("%d |",x);
        q=empiler(q,x);
    }
    while(!estVide(q)){
        int x=depiler(&q);
        *p=empiler(*p,x);
    }
    printf("\n");

}
int main() {
    pile *maPile = creer();

    printf("--- Phase d'empilage ---\n");
    for(int i = 0; i < 3; i++) {
        maPile = empiler(maPile,i);
    }

    printf("\nLongueur de la pile : %d\n", length(&maPile));

    printf("Contenu de la pile : ");
    afficher(&maPile);

    int v = tete(maPile);
    if(v != -1) {
        printf("L'element au sommet est : %d\n", v);
    }

    printf("\n--- Phase de depilage ---\n");
    int supp = depiler(&maPile);
    if(supp != -1) {
        printf("Element retire : %d\n", supp);
    }

    printf("Pile apres depilage : ");
    afficher(&maPile);

    return 0;
}