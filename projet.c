#include <stdio.h>
#include <stdlib.h>

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

int main(int argc , char *argv[]){

	int sizeX;
	int sizeY;
	int entreeX;
	int entreeY;
	int sortieX;
	int sortieY;
	unsigned short int **array;
	int i,j,test;

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
			/*	
				printf("Veuillez rentrer le nom du fichier sorurce à ouvrir\n");
				scanf(%s,name);
			 */
			// Ouverture du ficher 
			FILE *input=NULL;
			input=fopen("lab1.txt","r");
			// Si tout c'est bien déroulé on va parser le fichier.
			if(input!=NULL){
				fscanf(input,"%d %d %d %d %d %d\n",&sizeX,&sizeY,&entreeX,&entreeY,&sortieX,&sortieY);
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
			}

		}	
	}
	// Pas bien fait a revoir
	for (i = 0; i < sizeX; ++i)
	{
		free(array[i]);
	}

	free(array);
	return 0;
}
