<h1>Projet C</h1>
<h2>Création d'un labyrinthe</h2>
<h3>TO DO</h3>
On va selectionner les 4 derniers bits de la cellule actuelle 
		-envoyer le tableau contenant les 4 murs sur les 4 fonctions de test 
			partir dans l'ordre (droite bas gauche haut) dans la case selectionnée apres avoir muré le mur en question.
			Boucler
			Puis recommencer l'opération . verifier le nb de murs ouverts. Etc...

		Fonctions a faire
		-modifier binary pour retourner tableau des 4 bits pour les murs
		-4 fonctions de test pour chaque bit (droite bas gauche haut)
		-Fonction qui rajoute un mur sur le bit selectionné dans le tableau selectionnée ( et dans le secondaire des 4 bits)

<h3>Objectifs</h3>
L’objectif de ce projet est de modéliser en C, un labyrinthe en 2D. Ensuite, faire une recherche
d’un chemin quelconque entre l’entrée et la sortie, puis le plus court chemin dans ce laby-
rinthe. On considère le labyrinthe comme un tableau bidimensionnel d’entiers courts, de
taille donnée. On doit pouvoir générer le labyrinthe de plusieurs façons :
	
	1. En fixant dès le départ tous les paramètres du labyrinthe (taille du tableau, entiers,
	position de l’entrée, etc.), afin de bien débuter et bien contrôler votre programme.

	2. Générer aléatoirement un labyrinthe avec toutes ses caractéristiques de base.

	3. On doit pouvoir également charger un labyrinthe depuis un fichier texte, contenant
	toutes les caractéristiques nécessaires. Le format de fichier choisi sera le suivant :

— La 1ère ligne contiendra le nombre de lignes et de colonnes du labyrinthe, puis les
	coordonnées de l’entrée et de la sortie du labyrinthe.

— Ensuite, le fichier contiendra un tableau de valeurs indiquant la configuration ini-
	tiale de chaque cellule.

<h3>Fig.1</h3>
![Imgur](http://i.imgur.com/B8DB0f1.jpg)