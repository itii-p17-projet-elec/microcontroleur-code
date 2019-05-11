# Dépôt code microcontrôleur

![GitHub open issues](https://img.shields.io/github/issues/itii-p17-projet-elec/microcontroller-main.svg?color=blueviolet) ![GitHub closed issues](https://img.shields.io/github/issues-closed/itii-p17-projet-elec/microcontroller-main.svg?color=success) [![Build Status](https://travis-ci.org/itii-p17-projet-elec/microcontroller-main.svg?branch=master)](https://travis-ci.org/itii-p17-projet-elec/microcontroller-main)


## Liens utiles

+ [Suivi des tâches (privé)](https://github.com/orgs/itii-p17-projet-elec/projects/1)
+ [Site documentation projet](https://itii-p17-projet-elec.github.io/documentation/)
+ [Serveur d'intégration continue (résultats)](https://travis-ci.org/itii-p17-projet-elec/microcontroller-main)


## How To
### Récupération du code source

Le code se récupère en effectuant un clone du dépôt Git. Pour ce faire, sous Linux :
~~~~~~~~~{bash}
~$ git clone https://github.com/itii-p17-projet-elec/microcontroller-main.git
~~~~~~~~~

### Installation initiale des dépendances

**__Nota :__** Uniquement disponible pour l'environnement de référence (Linux Ubuntu, cf. serveur d'intégration continue).

L'installation des dépendances se fait au moyen d'un script Bash, également utilisé par la VM d'intégration continue.

~~~~~~~~~{bash}
~$ cd microcontroller-main
~$ sudo bash scripts/dependencies-install-linux.sh
~~~~~~~~~


### Liste (non exhaustive) des cibles disponibles dans le Makefile

| Cible 	| Description	|
| :--: 		| :-- 		|
| `clean`  	| Suppression des fichiers intermédiaires (dossier `build`) |
| `distclean`	| `clean` + suppression de tous les fichiers générés (dossier `out`).|
| `default`	| Cible par défaut ; construit le binaire principal. |
| `deploy`	| Cible permettant de téléverser le programme sur un microcontrôleur. |
| `doc`		| Cible appelant Doxygen pour produire la documentation de développement. |


***
*Ecrit avec l'éditeur de fichiers Markdown `remarkable`*