#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 50000

void partial_reverse(int array[], int i, int j){
	int temp;
	while(i < j){
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i += 1;
		j -= 1;
	}
}

int main(){

	int num_genes;
	int num_inversoes;
	int begin, end;
	int num_consultas;
	int gene;
	int genome = 1;
	int array[ARRAY_SIZE];

	int i, j;

	while(1){
		
		scanf("%d", &num_genes);
		if(num_genes == 0)
			break;

		printf("Genome %d\n", genome);

		for(i = 0; i < ARRAY_SIZE; ++i){
			array[i] = i+1;
		}

		scanf("%d", &num_inversoes);
		for(i = 0; i < num_inversoes; ++i){
			scanf("%d %d", &begin, &end);
			partial_reverse(array, begin-1, end-1);
		}

		scanf("%d", &num_consultas);
		for(i = 0; i < num_consultas; ++i){
			scanf("%d", &gene);
			for(j = 0; j < ARRAY_SIZE; ++j){
				if(array[j] == gene){
					printf("%d\n", j+1);
					break;
				}
			}
		}

		++genome;
	}

	return 0;
}