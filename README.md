
# Polynomials  X linked list (Liste Simplement Chainee)

Solution of our exercice about linked lists in the programming language "**C**"

# Ex (French)

L'objectif de ce problème est de représenter un polynôme à coefficient réels par une lise chainée simple chaque cellule est définie par la structure suivante :
```
struct monome{
float coef;
int ex;
struct monome *next;
};
typedef struct monome Monome;
```
Un polynôme P est une liste simplement chainée d'éléments de type monôme dont l'adresse du premier élément est dans P.


1. Écrire une fonction **Monome * saisirPolynome()** qui permet de créer et de saisir les éléments d'un polynôme, puis retourne la liste (l'adresse (pointeur) du premier élément de la liste ). La saisie s'arrête à la saisie d'un exposant négatif.
2. Écrire une fonction **void affiche_Polynome(Monome \*P)** qui affiche le polynôme P. 3. Écrire une fonction d'entête **float evaluer (Monome *P, float x)** qui renvoie la valeur du polynôme P pour la valeur x.
4. Écrire une fonction Monome* derive **Polynome(Monome \*P)** qui renvoie le polynôme dérivé de P.
5. Écrire une fonction **Monome \* addition Polynome(Monome \*P, Monome \*Q)** qui renvoie la somme des deux polynômes P et Q.
6. Écrire une fonction **Monome \* produitPolynomeMonome (Monome * P, Monome * m)** qui renvoie le produit du polynôme P par le monome m.
7. Écrire une fonction **void produitPolynomes (Monome \*P, Monome \*Q)** qui renvoie le polynôme résultat de la multiplication du polynôme P par le polynôme Q ( penser à utiliser les deux dernières fonctions)
