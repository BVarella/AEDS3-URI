#include <stdio.h>

int calc_index(char c){
	return ((int)c - (int)'A');
}

int main(){

	int numTestes;
	int numLinhas;
	char palavra[51];
	int i, j, k;
	int resposta;

	scanf("%d", &numTestes);

	for(i = 0; i < numTestes; ++i){
		resposta = 0;
		scanf("%d", &numLinhas);
		for(j = 0; j < numLinhas; ++j){
			scanf("%s", palavra);
			for(k = 0; k < 51; ++k){
				if(palavra[k] == '\0')
					break;
				else{
					resposta += ((calc_index(palavra[k])) + j + k);
				}
			}
		}
		printf("%d\n", resposta);
	}

	return 0;
}