#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <math.h>

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

void getBinary(int num, char *str)
{
  *(str+4) = '\0';
  int mask = 0x10 << 1;
  while(mask >>= 1)
    *str++ = !!(mask & num) + '0';
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

void printBinary(unsigned short int value){ // affiche les 4 bits de poids faible de la valeur

	unsigned short a= 0x1;
	int i;

	
	printf("\n");
	
	for(i=3; i >= 0; i--){	// test bit à bit de gauche à droite
	
		a = (value >> i) & 1;
		printf("%d", a);
		
	}
	
	printf("\n");
	
}
unsigned short int ** parcours(unsigned short int ** array, int entreeX, int entreeY,int sortieX , int sortieY){

int finie=0;

// On ne connait pas le nom d'étapes
while(!finie){
	// le point de départ du programme.
	
	/*
	On va selectionner les 4 derniers bits de la cellule actuelle 
		-envoyer le tableau contenant les 4 murs sur les 4 fonctions de test 
		partir dans l'ordre (droite bas gauche haut) dans la case selectionnée apres avoir muré le mur en question.
		Boucler
		Puis recommencer l'opération . verifier le nb de murs ouverts. Etc...

	*/
}

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
				printf("------------------Affichage des variables-------------------\n");
				printf("sizeX:%d sizeY:%d, entreeX:%d,entreY:%d,sortieX:%d,sortieY:%d\n",sizeX,sizeY,entreeX,entreeY,sortieX,sortieY);
				AfficheTableau(sizeX,sizeY,array);
				printf("------------------Conversion binaire-------------------------\n");
				printCells_Binary(array,sizeX,sizeY);
				}
/*
****************************************** Initialisation SDL*************************************************************************
*/
			
			/*
			--------------Definition variables pour affichage-----------------------------
			*/
			int screenSizeX=500;
			int screenSizeY=500;
			/*
			int tailleCarresX=0;
			int tailleCarresY=0;
			int nombreCarresX=0;
			int nombreCarresY=0;
			*/
			//----------------------------------------------------------------------------
			SDL_Surface *screen;
		    if( SDL_Init( SDL_INIT_VIDEO ) == -1 )
		    {
		        printf( "Can't init SDL:  %s\n", SDL_GetError( ) );
		        return EXIT_FAILURE;
		    }

		    atexit( SDL_Quit ); 
		    screen = SDL_SetVideoMode(screenSizeX,screenSizeY,16, SDL_HWSURFACE );
		    SDL_WM_SetCaption("Labyrinthe Generator", NULL);


		    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format,46,140,34));
		    // Mise a jour de la couleur de l'écran.
		    SDL_Flip(screen);

		    if( screen == NULL )
		    {
		        printf( "Can't set video mode: %s\n", SDL_GetError( ) );
		        return EXIT_FAILURE;
		    }   
		 

		    SDL_Delay( 10000 );
		}	
	}
	for (i = 0; i < sizeX; ++i)
	{
		free(array[i]);
	}

	free(array);
	return 0;
}
