# FILLER [[Sujet](https://github.com/tvarnier/42/blob/master/algorithm/filler/subject.pdf)]

<br>

Filler est un jeu algorithmique qui consiste à remplir une grille d’une taille connue à l’avance avec des pièces de taille et de formes aléatoires, sans que les pièces ne se superposent de plus d’une seule case et sans qu’elles ne depassent de la grille. Si l’une de ces conditions n’est pas remplie, la partie s’arrête.

Chaque pièce posée avec succès rapporte un certain nombre de points, et a un seul joueur, le but du jeu pourrait être d’obtenir le meilleur score possible. Cepedant, c’est avec deux joueurs que le filler prend tout son intérêt. Chaque joueur a pour but de poser un maximum de pièces tout en tentant d’empêcher son adversaire de le faire. A la fin de la partie, celui avec le plus de point remporte le match...

<br>

<div>
  <img src="https://github.com/tvarnier/42/blob/master/algorithm/filler/img/filler_gif.gif" width="75%">
</div>

<br>

## LANCER LE PROJET

<br>

Lancer la commande `make` pour compiler le projet.

Il suffit ensuite de lancer la commande :

`./resources/filler_vm -f <map> -p1 <player> -p2 <player> | ./tvarnier.vm`
 * `<map>` dans le sous-dossier `./resources/maps`
 * `<player>` dans le sous-dossier `./resources/players`, mon player est à la racine `./tvarnier.filler`

<br>

Exemple de commande complète :
> ./resources/filler_vm -f ./resources/maps/map02 -p1 ./resources/players/carli.filler -p2 ./tvarnier.filler | ./tvarnier.vm

<br>

*N'hésitez pas à dezoomer votre terminal sur certaines maps*
