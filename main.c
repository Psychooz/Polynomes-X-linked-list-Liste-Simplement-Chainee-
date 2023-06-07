#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Made by : Ziad BKL

struct monome {
    float coef;
    int ex;
    struct monome* next;
};

typedef struct monome Monome;

//Made by : Ziad BKL

Monome* saisirPolynome() {
    Monome* tete = NULL;
    Monome* courant = NULL;
    int ex;

    printf("Saisie du polynome (pour arreter entrer n'import coef mais avec un exp negative):\n");
    do {
        Monome* nouveau = (Monome*)malloc(sizeof(Monome));

        printf("Coef : ");
        scanf("%f", &(nouveau->coef));
        printf("Exposant : ");
        scanf("%d", &(nouveau->ex));

        if (nouveau->ex < 0) {
            free(nouveau);
            break;
        }

        nouveau->next = NULL;

        if (tete == NULL) {
            tete = nouveau;
            courant = nouveau;
        } else {
            courant->next = nouveau;
            courant = courant->next;
        }
    } while (1);

    return tete;
}

void affichePolynome(Monome* P) {
    Monome* courant = P;

    if (courant == NULL) {
        printf("Polynome vide\n");
        return;
    }

    while (courant != NULL) {
        printf("%.2f X(^%d) ", courant->coef, courant->ex);
        courant = courant->next;
    }

    printf("\n");
}

float evaluer(Monome* P, float x) {
    float resultat = 0.0;
    Monome* courant = P;

    while (courant != NULL) {
        resultat += courant->coef * pow(x, courant->ex);
        courant = courant->next;
    }

    return resultat;
}

Monome* derivePolynome(Monome* P) {
    Monome* derive = NULL;
    Monome* courant = P;

    while (courant != NULL) {
        if (courant->ex > 0) {
            Monome* nouveau = (Monome*)malloc(sizeof(Monome));
            nouveau->coef = courant->coef * courant->ex;
            nouveau->ex = courant->ex - 1;
            nouveau->next = NULL;

            if (derive == NULL) {
                derive = nouveau;
            } else {
                Monome* temp = derive;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = nouveau;
            }
        }
        courant = courant->next;
    }

    return derive;
}


Monome* additionPolynome(Monome* P, Monome* Q) {
    Monome* somme = NULL;
    Monome* courantP = P;
    Monome* courantQ = Q;

    while (courantP != NULL && courantQ != NULL) {
        Monome* nouveau = (Monome*)malloc(sizeof(Monome));

        if (courantP->ex == courantQ->ex) {
            nouveau->coef = courantP->coef + courantQ->coef;
            nouveau->ex = courantP->ex;
            courantP = courantP->next;
            courantQ = courantQ->next;
        } else if (courantP->ex > courantQ->ex) {
            nouveau->coef = courantP->coef;
            nouveau->ex = courantP->ex;
            courantP = courantP->next;
        } else {
            nouveau->coef = courantQ->coef;
            nouveau->ex = courantQ->ex;
            courantQ = courantQ->next;
        }

        nouveau->next = NULL;

        if (somme == NULL) {
            somme = nouveau;
        } else {
            Monome* temp = somme;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = nouveau;
        }
    }

    if (courantP != NULL) {
        while (courantP != NULL) {
            Monome* nouveau = (Monome*)malloc(sizeof(Monome));
            nouveau->coef = courantP->coef;
            nouveau->ex = courantP->ex;
            nouveau->next = NULL;

            if (somme == NULL) {
                somme = nouveau;
            } else {
                Monome* temp = somme;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = nouveau;
            }

            courantP = courantP->next;
        }
    }

    if (courantQ != NULL) {
        while (courantQ != NULL) {
            Monome* nouveau = (Monome*)malloc(sizeof(Monome));
            nouveau->coef = courantQ->coef;
            nouveau->ex = courantQ->ex;
            nouveau->next = NULL;

            if (somme == NULL) {
                somme = nouveau;
            } else {
                Monome* temp = somme;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = nouveau;
            }

            courantQ = courantQ->next;
        }
    }

    return somme;
}

Monome* produitPolynomeMonome(Monome* P, Monome* m) {
    Monome* produit = NULL;
    Monome* courant = P;

    while (courant != NULL) {
        Monome* nouveau = (Monome*)malloc(sizeof(Monome));
        nouveau->coef = courant->coef * m->coef;
        nouveau->ex = courant->ex + m->ex;
        nouveau->next = NULL;

        if (produit == NULL) {
            produit = nouveau;
        } else {
            Monome* temp = produit;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = nouveau;
        }

        courant = courant->next;
    }

    return produit;
}

void produitPolynomes(Monome* P, Monome* Q) {
    Monome* resultat = NULL;
    Monome* courantQ = Q;

    while (courantQ != NULL) {
        Monome* produit = produitPolynomeMonome(P, courantQ);
        resultat = additionPolynome(resultat, produit);
        courantQ = courantQ->next;
    }
    affichePolynome(resultat);
}

int main() {
    Monome* polynome1 = NULL;
    Monome* polynome2 = NULL;

    printf("Saisie du premier polynome :\n");
    polynome1 = saisirPolynome();

    printf("Saisie du deuxieme polynome :\n");
    polynome2 = saisirPolynome();

    printf("Affichage du premier polynome :\n");
    affichePolynome(polynome1);

    printf("Affichage du deuxieme polynome :\n");
    affichePolynome(polynome2);

    float x;
    printf("Evaluation du premier polynome :\n");
    printf("Veuillez entrer la valeur de x : ");
    scanf("%f", &x);
    float valeur1 = evaluer(polynome1, x);
    printf("Valeur du premier polynome pour x=%.2f : %.2f\n", x, valeur1);

    printf("Evaluation du deuxieme polynome :\n");
    printf("Veuillez entrer la valeur de x : ");
    scanf("%f", &x);
    float valeur2 = evaluer(polynome2, x);
    printf("Valeur du deuxieme polynome pour x=%.2f : %.2f\n", x, valeur2);

    printf("Derivee du premier polynome :\n");
    Monome* derivee1 = derivePolynome(polynome1);
    affichePolynome(derivee1);

    printf("Derivee du deuxieme polynome :\n");
    Monome* derivee2 = derivePolynome(polynome2);
    affichePolynome(derivee2);

    printf("Somme des polynomes :\n");
    Monome* somme = additionPolynome(polynome1, polynome2);
    affichePolynome(somme);

    printf("Produit des polynomes :\n");
    produitPolynomes(polynome1, polynome2);

    return 0;
}

