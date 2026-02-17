# RÉCAPITULATIF : ALLOCATION DYNAMIQUE (MALLOC / FREE)

## 1. LE PROBLÈME : POURQUOI ON FAIT ÇA ?

Les tableaux classiques (statiques) ont une taille fixe décidée AVANT 
de lancer le programme (ex: `int tab[10]`).

**Problème** : Si tu demandes à l'utilisateur "Combien d'étudiants ?", 
et qu'il répond 1000 alors que tu as prévu `tab[10]`, ça plante.

**Solution** : L'Allocation Dynamique. On demande à la RAM de nous prêter 
un bloc de mémoire sur mesure PENDANT que le programme tourne.

## 2. LES OUTILS INDISPENSABLES (`<stdlib.h>`)

Il faut absolument inclure : `#include <stdlib.h>`

### A. MALLOC (Memory Allocation)
Commande : "Réserve-moi X octets".
```c
void* malloc(size_t taille);
```

### B. FREE (Libération)
Commande : "Je n'ai plus besoin de ce bloc, tu peux le reprendre".
```c
void free(void* pointeur);
```

### C. SIZEOF (Taille de...)
Commande : "Combien d'octets pèse un int/float/struct ?"
Indispensable car un int fait souvent 4 octets, un char 1 octet, etc.

## 3. LA RECETTE EN 4 ÉTAPES (TABLEAU DYNAMIQUE)

### ÉTAPE 1 : DÉCLARATION DU POINTEUR
On ne déclare pas un tableau `int tab[]`, mais un pointeur `int *tab`.

### ÉTAPE 2 : L'ALLOCATION (LA FORMULE MAGIQUE)
On calcule la taille totale : (Nombre d'éléments * Taille d'un élément).

```c
int n = 5; // L'utilisateur veut 5 cases
int *tab = malloc(n * sizeof(int));
```

### ÉTAPE 3 : VÉRIFICATION (SÉCURITÉ)
Si la RAM est pleine, malloc renvoie NULL. Il faut toujours vérifier !

```c
if (tab == NULL) {
    exit(1); // On arrête tout, erreur critique
}
```

### ÉTAPE 4 : UTILISATION ET LIBÉRATION
On utilise tab comme un tableau normal.

```c
tab[0] = 10;

// TRES IMPORTANT : À la fin, on rend la mémoire.
free(tab);
```

## 4. LA RECETTE POUR LES STRUCTURES

On peut créer un étudiant "à la volée".

```c
// 1. Allocation de la taille d'une structure Etudiant
Etudiant *e = malloc(sizeof(Etudiant));

if (e != NULL) {
    // 2. Remplissage (Attention : on utilise la FLÈCHE ->)
    strcpy(e->prenom, "Bob");
    e->age = 20;

    // 3. Utilisation
    printf("%s a %d ans", e->prenom, e->age);

    // 4. Libération
    free(e);
}
```

## 5. LES PIÈGES MORTELS (À ÉVITER)

1. **La Fuite de Mémoire (Memory Leak)** :
   Oublier de faire `free()`. La mémoire reste occupée jusqu'à la fin 
   du programme (ou redémarrage du PC).

2. **Utiliser après Libération** :
   Faire `free(tab)` puis essayer d'écrire `tab[0] = 5`.
   -> Crash immédiat (Segmentation Fault).

3. **Oublier sizeof** :
   `malloc(10)` réserve 10 octets.
   `malloc(10 * sizeof(int))` réserve 40 octets (pour 10 entiers).
   Si tu oublies sizeof, ton tableau sera trop petit !