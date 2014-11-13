#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Ces fonctions permettent de tester la présence de mur
// retourne 1 si présent sur le bit 0 sinon

#define droite(x) ((x) & 0x4 ? (1) : (0) )
#define   haut(x) ((x) & 0x8 ? (1) : (0) )
#define gauche(x) ((x) & 0x1 ? (1) : (0) )
#define    bas(x) ((x) & 0x2 ? (1) : (0) )

// Cree un tableau 2D de unsigned short de la taille fournie par les entrees.
unsigned short int** Make2DintArray(int sizeX, int sizeY) {
	unsigned short int** theArray;
	theArray = (unsigned short int**) malloc(sizeX*sizeof(unsigned short int*));
	int i;
	for (i = 0; i < sizeX; i++)
	{
		theArray[i] = (unsigned short int *) malloc(sizeY*sizeof(unsigned short int ));
	}
	return theArray;
}
// Affiche un tableau 2D
void AfficheTableau(int sizeX,int sizeY, unsigned short int  **array){
	int i,j;

	for (i = 0; i < sizeX; i++) {
		for (j = 0; j < sizeY; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

void printCells_Binary(unsigned short int **board, int lines, int columns){ // print les 4 bits de poids faible de chaque valeur de cellule du tab

	int i,j; 	// parcours lignes colones
	int k;	// parcours bits
	unsigned short a= 0x1; 	// masque pour tester les bits
	
	for(i=0; i < columns; i++){ 	// parcours tableau (colones)

		for(j=0; j < lines; j++){ 	// parcours tableau (lignes)

			for(k=3; k >= 0; k--){ 		// affichage des 4 bits

				a= (board[i][j] >> k) & 1;
				printf("%d", a);
			}
			
			printf("  ");
		}
		
		printf("\n");

	}
	
	printf("\n");

}

void print_current_position(unsigned short **board,int lines, int columns, unsigned short startx, unsigned short int starty){
	
	int i,j; // variables de parcours
	unsigned short d= 0x4, b= 0x2; // masques
	unsigned short temp;

	printf(".");
	
	for(i=0; i < lines; i++) // affichage de la première ligne (cadre)
		printf("....");

	for(j=0; j < columns; j++){ // parcours colonnes			

		printf("\n|");		

		for(i=0; i < lines; i++){ // parcours lignes
			
			temp= board[j][i] & d;

			if((startx == i && starty == j) && temp ==d)
				printf(" + |");

			else if(startx ==i && starty ==j)
				printf(" +  ");
			
			else if(temp == d)
				printf(" o |"); // mettre un mur a droite
			else
				printf(" o  ");
		}

		printf("\n.");

		for(i=0; i < lines; i++){

			temp= board[j][i] & b;
			if(temp == b)
				printf("...."); // mettre un mur en bas
			else
				printf("    ");	
		}		
	}
	
	printf("\n\n");
}
// Cette fonction va résoudre le labyrinthe de manière récursive
// x et y représentent le point d'entre du labyrinthe.
//value servira a propager notre position acutelle dans le tableau path
void solver(unsigned short **board, int lines, int columns, int y, int x, unsigned short int **path,int value ,int sortieX,int sortieY){
	int i,j;
	int temp;
	// Condition d'arret => sortie trouvée
	
	// TESTE
	printf("Valeur en int de la position actuelle: %d\n",board[x][y]);
	if (x==sortieX && y==sortieY)
	{
		printf("Le chemin à été trouvé \n");
		path[0][value]=x;
		path[1][value]=y;
		return;
	}
	
	
	printf("droite: %d et %d\n",droite(board[x][y]),board[x][y]);
	printf("haut: %d et %d\n",haut(board[x][y]),board[x][y]);
	printf("gauche: %d et %d\n",gauche(board[x][y]),board[x][y]);
	printf("bas: %d et %d\n",bas(board[x][y]),board[x][y]);
	
	// Condition d'arret => pas de sortie
	if( droite(board[x][y]) &&  gauche(board[x][y]) && haut(board[x][y]) && bas(board[x][y]) ){
		printf("La condition d'arret a été rencontrée - aucun chemin a partir de cette case \n");
		// on efface le tableau pour ne pas avoir de faussses donnees -> il va y avoir un pb plus tard
		for (i = 0; i < 2; ++i)
		{
			for (j = 0; i < 20; ++j)
			{
				path[i][j]=0;
			}
		}
		printf("blallz\n");
		return;
	}

	// on insere dans le tabeau des chemins la postion  actuelle.
	path[0][value]=y;
	path[1][value]=x;

	printf("test valeur de board[x][y+1]=%d et resultat: %d\n",board[x][y+1],board[x][y+1] | 0x1);

	// la fonction va tester les murs ouverts puis rentrer dans le premier disponible
	if( ( droite(board[x][y]) == 0) &&   y != columns -1){
		// on crée un mur a droite
		printf("On entre a droite\n");
		// On cree a mur a droite => donc a gauche de la cellule de droite.
		board[x][y+1]=(board[x][y+1] & ~1) | 1; // set the last bit to 001;
		print_current_position(board,lines,columns,y+1,x);
		solver(board,lines,columns,y+1,x,path,value+1,sortieX,sortieY);
	}
	if( (gauche(board[x][y]) == 0 ) && y!= 0){
		printf("on entre a gauche\n");
		board[x][y-1]=( board[x][y-1] & ~4) | 1;
		print_current_position(board,lines,columns,y-1,x);
		solver(board,lines,columns,y-1,x,path,value+1,sortieX,sortieY);
	}
	if( ( haut(board[x][y])==0) && x!= 0){
		printf("on entre en haut\n");
		board[x-1][y]=( board[x-1][y] & ~2 ) | 1;
		print_current_position(board,lines,columns,y,x-1);
		solver(board,lines,columns,y,x-1,path,value+1,sortieX,sortieY);
	}
	if( (bas(board[x][y])==0) && x != lines-1){
		printf("on entre en bas\n");
		board[x+1][y]=( board[x+1][y]  & ~8) | 1;
		print_current_position(board,lines,columns,y,x+1);
		solver(board,lines,columns,y,x+1,path,value+1,sortieX,sortieY);
	}
	printf("Probleme\n");
}
// PAS ENCORE TESTE //
unsigned short** Generate_Random_Lab(int lines, int columns){ // genere un labyrinthe aleatoire de taille fixee

	int i,j; // variables de parcours tableau
	unsigned short aleatoire = 0; // prend la valeur de 0 ou 1
	unsigned short h,b,g,d; // masques pour les murs du cadre 
	
	unsigned short **board;


	//********************************* MALLOC TABLEAU 2D *****************************************************************

	board= (unsigned short**)malloc(sizeof(unsigned short*)*columns);
	
	if(!board){ // verifie sil'allocation s'est bien passee, eteint le programme si non
		printf("erreur lors de l'allocation du tableau random (**)"); exit(-1);;
}


	for(i=0; i < columns; i++){ // malloc pour generer le tab de pointeurs

		board[i]= (unsigned short*)malloc(sizeof(unsigned short)*lines);
		
		if(!board[i]){

			printf("erreur lors de l'allocation du taleau random (*)"); exit(-1);
		}
	}

	//************************************** FIN MALLOC *******************************************************************


	for(i=0; i < columns; i++){ // initialisation du tableau a 0 (necessaire)
		
		for(j=0; j < lines; j++)
			board[i][j]= 0;
	}


	for(i=0; i < columns; i++){ // determination des valeurs / murs

		for(j=0; j < lines; j++){

			// mettre un mur en bas aleatoirement
			aleatoire = rand() % 2;
			aleatoire << 1;
			board[i][j] = aleatoire | (board[i][j]);
			// mettre un mur a droite aleatoirement
			aleatoire = rand() % 2;
			aleatoire << 2;
			board[i][j] = aleatoire | (board[i][j]);

			// murs pour les contours (le cadre du labyrinthe)
			if(i==0){
				h= 0x1;
				h << 3;
				board[i][j] |= h;
			}

			if(i == columns-1)
				b=0x1;
			b << 1;
			board[i][j] |= b;

			if(j == 0){
				g= 0x1;
				g << 2;
				board[i][j] |= g; 
			}

			if(j == lines-1){
				d= 0x1;
				board[i][j] |= d;
			}			
		}
	}

	return board;
}

int main(int argc , char *argv[]){

	int sizeX;
	int sizeY;
	int entreeX;
	int entreeY;
	int sortieX;
	int sortieY;
	unsigned short int **array;
	int i,j;
	char name[10];
	int retour=0;

	//  On récpère les options fornies si présentes
	if (argc==7)
	{
		sizeX=(int)argv[0];
		sizeY=(int)argv[1];
		entreeX=(int)argv[2];
		entreeY=(int)argv[3];
		sortieX=(int)argv[4];
		sortieY=(int)argv[5];

		array=Make2DintArray(sizeX,sizeY);
		// Dans ce cas nous devons generer le tableau aléatoirement.
	}
	else{
		/*
		   Si aucun argument n'est fourni en entree -> fichier texte.
		 */
		   if(argc==1){
		//	printf("Veuillez rentrer le nom du fichier sorurce à ouvrir\n");
		//	scanf(%s,name);

			// Ouverture du ficher 
		   	FILE *input=NULL;
		   	input=fopen("lab1.txt","r");
			// Si tout c est bien déroulé on va parser le fichier.
		   	if(input!=NULL){
		   		retour=fscanf(input,"%d %d %d %d %d %d\n",&sizeX,&sizeY,&entreeX,&entreeY,&sortieX,&sortieY);

		   		if (retour)
		   		{
		   			printf("Données bien lues\n");
		   		}

		   		array=Make2DintArray(sizeX,sizeY);
		   		for(i = 0; i < sizeX; i++)
		   		{
		   			for(j = 0; j < sizeY; j++) 
		   			{
						//Use lf format specifier, %c is for character
		   				if (!fscanf(input, "%hu", &array[i][j])) 
		   					break;

		   			}

		   		}
				// Le tableau va contenir les solutions, faudrait creer une liste en fait
		   		unsigned short int **path;
		   		path=Make2DintArray(20,2);
				// value va contenir la postion x dans path
		   		int value=0;
				//
		   		printf("------------------Affichage des variables-------------------\n");
		   		printf("sizeX:%d sizeY:%d, entreeX:%d,entreY:%d,sortieX:%d,sortieY:%d\n",sizeX,sizeY,entreeX,entreeY,sortieX,sortieY);
		   		printf("affichage du tableau\n");
		   		//print_labyrinthe(array,sizeX,sizeY);
		   		printf("\n");
		   		printf("------------------Conversion binaire-------------------------\n");
		   		printCells_Binary(array,sizeX,sizeY);
		   		printf("Affichage de la position de départ\n");
		   		print_current_position(array,sizeX,sizeY,0,0);
		   		printf("Test du parcours de tableau\n");
			//  solver(unsigned short **board, int lines, int columns, int x, int y, int **path,int value ,int sortieX,int sortieY)
		   		solver(array, sizeX, sizeY, 0, 0,path,value ,sortieX, sortieY);
		   		/*int test;
		   		test=gauche(array[entreeX][entreeY]);
		   		printf("%d\n",test);
		   		*/
		   	}	
		   }
		   for (i = 0; i < sizeX; ++i)
		   {
		   	free(array[i]);
		   }

		   free(array);
		   return 0;
		}
	}