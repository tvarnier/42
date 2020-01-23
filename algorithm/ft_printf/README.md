### FT_PRINTF [[Sujet](https://github.com/tvarnier/42/blob/master/algorithm/ft_printf/subject.pdf)]

<br>

Le projet ft_printf consiste a re-coder la fonctions de la lib C `printf`, voir la [page manuel](http://manpagesfr.free.fr/man/man3/printf.3.html) pour plus d'informations.

La versatilité de la fonction printf en C représente pour nous un excellent exercice de programmation. Ce projet nous permet de découvrir les fonctions variadiques en C dans un contexte particulièrement adapté, et de voir un excellent exemple d’un “dispatcher” rudimentaire implémenté en C à l’aide d’un tableau de pointeurs sur fonctions.

<br>

## LANCER LE PROJET

<br>

Lancer la commande `make` pour compiler le projet.

Puis modifiez les arguments de de la fonction printf dans le fichier `main_test.c` et compilez le grâce à la commande `make test`.

<div>
  <img src="https://github.com/tvarnier/42/blob/master/algorithm/ft_printf/img/main_example.png" align="middle" width="75%">
</div>

<br>

Il vous suffit ensuite de lancer le programme `./test`.

<br>

### PARAMÈTRES

<br>

Gestion des conversions suivantes :
 * `b` | *unsigned long long (binaire)*
 * `c` | *unsigned char*
 * `C` | *wchar_t (unicode)*
 * `d` | *int*
 * `D` | *long long integer*
 * `e` | *double (forme scientifique)*
 * `E` | *long double (forme scientifique)*
 * `f` | *double*
 * `F` | *long double*
 * `g` | *double (conversion `f` ou `e` en fonction de l'exposant)*
 * `G` | *long double (conversion `F` ou `E` en fonction de l'exposant)*
 * `i` | *int*
 * `k` | *long (date)*
 * `o` | *unsigned int (octal)*
 * `O` | *unsigned long long int (octal)*
 * `p` | *void \* en hexadecimal (adresse)*
 * `r` | *char \* (chaîne de caractère non imprimable)*
 * `s` | *char \* (string)*
 * `S` | *wchar_t \* (unicode string)*
 * `t` | *long (heure)*
 * `u` | *unsigned int*
 * `U` | *unsigned long long int*
 * `x` | *unsigned int (hexadecimal)*
 * `X` | *unsigned long long int (hexadecimal)*
 
<br>

Gestion des modificateurs de longueur suivantes :
 * `j`
 * `h`
 * `hh`
 * `l`
 * `ll`
 * `L`
 * `z`
 
<br>

Gestion des flags suivants :
 * `#`
 * `0`
 * `-`
 * `+`
 
<br>

Gestion de la précision
