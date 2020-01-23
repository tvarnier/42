# FDF [[Sujet](https://github.com/tvarnier/42/blob/master/graphic/fdf/subject.pdf)]

<br>

Ce project nous introduit à la programmation graphique, et en particulier, le placement de points dans l’espace, comment les relier avec des segments et surtout comment observer la scène depuis un certain point de vue.

Il nous fait également découvrir notre première bibliothèque graphique : La miniLibX.

Cette bibliothèque développée en interne rassemble le minimum nécéssaire pour ouvrir une fenêtre, allumer un pixel et gérer les évènements lié à cette fenêtre : le clavier et la souris.
L’occasion de nous initier à la programmation dite “evenementielle”.

<br>

<div>
  <img src="https://github.com/tvarnier/42/blob/master/graphic/fdf/img/france.png" align="middle">
</div>

<br>

## LANCER LE PROJET

<br>

Lancer la commande `make` pour compiler le projet.

Il suffit ensuite de lancer la commande `./fdf <map>` (vous trouverez des maps dans le dossier `maps`)

Une fois lancer vous aurez accès aux événements suivants:
 * **[a w d s]** ou **[◀ ▲ ▶ ▼]** => Deplacer la map
 * **[molette]** => Gérer le zoom
 * **[p]** => Changer de perspective
 * **[+] [-]** => Accentuer ou Atténuer les reliefs
 * **[f]** => Gérer le remplissage des faces
 * **[r]** => Reset la position, l'angle et le zoom de la map
 * **[Maintenir Left Click]** => Rotation sur l'axe Z
 * **[ESC]** => Quitter le programme

<br>

## EXEMPLES

<br>

<div>
  <img src="https://github.com/tvarnier/42/blob/master/graphic/fdf/img/pylone.png">
  <p align="center" font-size="x-small"><i>Map "polynome"</i></p>
</div>

<br>

<div>
  <img src="https://github.com/tvarnier/42/blob/master/graphic/fdf/img/pylone_filled.png">
  <p align="center" font-size="x-small"><i>Map "polynome" w/ le remplissage des faces</i></p>
</div>
