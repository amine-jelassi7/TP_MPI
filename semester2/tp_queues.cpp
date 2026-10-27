#include <stdio.h>
#include <stdlib.h>


typedef struct Noeud{
    int val;
    struct Noeud *suivant;
}Noeud;
typedef struct filee{
    Noeud*tete;
    Noeud*queue;
}filee;
typedef filee* file;


file creer(){
    return NULL;}

int estVide(file f){
    return !f || !f->tete;
}
file enfiler(file f,int x){
    if (f == NULL) {
        f = (file)malloc(sizeof(filee));
        f->tete = f->queue = NULL;
    }
    Noeud *new_node=(Noeud*)malloc(sizeof(Noeud));
    new_node->val=x;
    new_node->suivant=NULL;
    if(estVide(f)){
        f->tete=new_node;
        f->queue=new_node;
    }else{
    f->queue->suivant=new_node;
    f->queue=new_node;
}
    return f;
}
int  defiler(file *f){
    if(estVide(*f)) return -1;
    Noeud *temp=(*f)->tete;
    int x=temp->val;
    (*f)->tete=(*f)->tete->suivant;
    if ((*f)->tete == NULL) {
        (*f)->queue = NULL;
    }
    free(temp);
    return x;
}
int tete(file f){
    if(estVide(f)) return -1;
    return f->tete->val;
}
int length(file *f){
    file g=creer();
    int i=0;
    while(!estVide(*f)){
        int x=defiler(f);
        i++;
        g=enfiler(g,x);
    }
    while(!estVide(g)){
        int x=defiler(&g);
        *f=enfiler(*f,x);
    }
    return i;
}
void afficher(file *f){
    file g=creer();
    while(!estVide(*f)){
        int x=defiler(f);
        printf("%d |",x);
        g=enfiler(g,x);
    }
    while(!estVide(g)){
        int x=defiler(&g);
        *f=enfiler(*f,x);
    }
}
int main() {
    file my_file = (file)malloc(sizeof(filee));
    my_file->tete = NULL;
    my_file->queue = NULL;

    printf("--- Enfilage ---\n");
    my_file = enfiler(my_file, 10);
    my_file = enfiler(my_file, 20);
    my_file = enfiler(my_file, 30);

    printf("tete : %d\n", tete(my_file));

    printf("--- Affichage ---\n");
    afficher(&my_file);
    printf("\n");

    printf("longeur: %d\n", length(&my_file));

    printf("--- Defilage ---\n");
    int val = defiler(&my_file);
    printf("supprime !: %d\n", val);

    printf("apres :\n");
    afficher(&my_file);
    printf("\n");

    return 0;
}