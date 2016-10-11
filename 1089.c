#include <stdio.h>
#include <stdlib.h>

int main(){

	int N;
	int picos;
	int i;

	while(1){
		
		scanf("%d", &N);
		if(N == 0){
			break;
		}

		int *magnitude = (int *) malloc(N * sizeof(int));

		for(i = 0; i < N; ++i){
			scanf("%d", &magnitude[i]);
		}

		if(N == 2 && (magnitude[0] != magnitude[1])){
			printf("2\n");
			free(magnitude);
		}
		else{
			picos = 0;
			for(i = 1; i < N-1; ++i){
				if(((magnitude[i-1] < magnitude[i]) && (magnitude[i] > magnitude[i+1]))
				 || (magnitude[i-1] > magnitude[i]) && (magnitude[i] < magnitude[i+1])){
					++picos;
				}
			}
	        //Penultimo - Ultimo / Ultimo - Primeiro
			if(((magnitude[N-2] < magnitude[N-1]) && (magnitude[N-1] > magnitude[0]))
			 || (magnitude[N-2] > magnitude[N-1]) && (magnitude[N-1] < magnitude[0])){
				++picos;
			}
	        //Ultimo - Primeiro / Primeiro - Segundo
			if(((magnitude[N-1] < magnitude[0]) && (magnitude[0] > magnitude[1]))
			 || (magnitude[N-1] > magnitude[0]) && (magnitude[0] < magnitude[1])){
				++picos;
			}

			printf("%d\n", picos);
			free(magnitude);
		}
	}
	return 0;
}