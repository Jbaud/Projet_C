#include <stdio.h>
#include <stdlib.h>

int** Make2DintArray(int arraySizeX, int arraySizeY) {
	int** theArray;
	theArray = (int**) malloc(arraySizeX*sizeof(int*));
	int i;
	for (i = 0; i < arraySizeX; i++)
	{
		theArray[i] = (int*) malloc(arraySizeY*sizeof(int));
	}
	return theArray;
}
int main(int argc , char *argv[]){

	int sizeX;
	int sizeY;
	int entreeX;
	int entreeY;
	int sortieX;
	int sortieY;
	int **array;
	int i;
	int j;
	int test;

	//Pour skipper la 1 ligne
	char buffer[100]
		// faire demande nom fichier


		//  On récpère les options fornies si présentes
		if (argc==6)
		{
			sizeX=(int)argv[0];
			sizeY=(int)argv[1];
			entreeX=(int)argv[2];
			entreeY=(int)argv[3];
			sortieX=(int)argv[4];
			sortieY=(int)argv[5];

			array=Make2DintArray(sizeX,sizeY);

		}
		else{

			if (argc!=0 && argc!=6){
				printf("Entrees mal formatées\n");
			}
			if(argc==0){
				/*	
					printf("Veuillez rentrer le nom du fichier sorurce à ouvrir\n");
					scanf(%s,name);
				 */
				// Ouverture du ficher 
				FILE *input=NULL;
				fopen("test.txt","r");
				// Si tout c'est bien déroulé on va parser le fichier.
				if(input!=NULL){
					fscanf(input,"%d %d %d %d %d %d\n",&sizeX,sizeY,entreeX,entreeY,sortieX,sortieY);
					array=Make2DintArray(sizeX,sizeY);
					fgets(buffer, 100, pointer);
					for (i = 0; i < sizeX; ++i)
					{
						for (j = 0; j < sizeY; ++j)
						{
							test = fgetc(input);
							if(test != '\n' && test != '\r') // test pour retour a la ligne + espace
								array[i][j] = test;

							else
								j--;
						}
					}
				}

			}	
		}




	return 0;
}
