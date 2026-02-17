# RÉCAPITULATIF : LES POINTEURS EN C

## 1. LE CONCEPT DE BASE

Un pointeur est une variable spéciale. Au lieu de stocker une valeur 
(comme 10, 'A', ou 3.14), il stocke une **ADRESSE MÉMOIRE**.

Imagine la mémoire comme une immense armoire à casiers :
- **La Variable** : C'est le casier. Il contient un objet (la valeur).
- **L'Adresse** : C'est le numéro écrit sur la porte du casier.
- **Le Pointeur** : C'est un post-it sur lequel tu as noté le numéro du casier.

## 2. LES 3 SYMBOLES À CONNAÎTRE PAR CŒUR

### A. DÉCLARATION (*)
Quand on crée le pointeur. On met l'étoile pour dire "Ceci est un pointeur".

```c
int *p;    // "p" est un pointeur destiné à viser un entier.
```

### B. L'ADRESSE (&)
Pour récupérer l'adresse d'une variable existante.

```c
int age = 20;
p = &age;  // "p prend l'adresse de age".
           // Maintenant, p "pointe" sur age.
```

### C. L'INDIRECTION / DÉRÉFÉRENCEMENT (*)
L'étoile utilisée DEVANT un pointeur déjà déclaré. 
Elle signifie : "Va voir ce qu'il y a à cette adresse".

```c
printf("%d", *p); // Affiche 20 (le contenu de la boîte).
*p = 30;          // Ouvre la boîte pointée et remplace 20 par 30.
```

### RÉSUMÉ VISUEL :

```
variable  :  [ 20 ]   <-- La valeur
&variable :  0x1234   <-- L'adresse (Où ça se trouve)

pointeur p:  [ 0x1234 ] <-- Le pointeur contient l'adresse
*p        :  20       <-- *p remonte à la valeur
```

## 3. LES 3 CAS D'UTILISATION PRINCIPAUX

### CAS N°1 : MODIFIER UNE VARIABLE VIA UNE FONCTION (SWAP)
En C, les fonctions travaillent sur des copies. Pour modifier la vraie 
variable du main, il faut envoyer son adresse.

```c
void echanger(int *a, int *b) {
    int temp = *a; // Je sauvegarde la valeur pointée par a
    *a = *b;       // Je mets la valeur pointée par b dans a
    *b = temp;     // Je mets temp dans b
}
// Appel : echanger(&x, &y);
```

### CAS N°2 : LES TABLEAUX SONT DES POINTEURS
Le nom d'un tableau est juste l'adresse du premier élément.

```c
int tab[3] = {10, 20, 30};

tab       == &tab[0]   // (L'adresse du début)
*tab      == tab[0]    // (La première valeur : 10)
*(tab + 1) == tab[1]   // (La deuxième valeur : 20)
```

### CAS N°3 : LES STRUCTURES ET LA FLÈCHE (->)
Quand on manipule une structure via un pointeur, on ne peut pas utiliser 
le point "." (réservé aux variables directes). On utilise la flèche "->".

```c
Etudiant e = {"Toto", 20};
Etudiant *p = &e;

// Méthode lourde (déconseillée) : (*p).age = 21;
// Méthode propre (conseillée)   : p->age = 21;
```

## 4. BONNES PRATIQUES ET PIÈGES

- **Initialisation**: Si un pointeur ne pointe sur rien, mets-le toujours à NULL.
  ```c
  int *ptr = NULL;
  ```

- **Le Type** : Un pointeur "int *" ne doit pointer que sur des "int". 
  Le typage est strict.

- **Segmentation Fault** : Si tu essaies d'accéder à une adresse interdite 
  (ou non initialisée), le programme plante immédiatement.