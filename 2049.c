#include <stdio.h>
#include <string.h>

int casamentoBruto(char* texto, long int textoSize, char* padrao, long int padraoSize){
	long int i, j, k;
	for(i = 1; i <= (textoSize-padraoSize+1); i++){
		k = i;
		j = 1;
		while(texto[k-1] == padrao[j-1] && j <= padraoSize){
			j++;
			k++;
		}
		if(j > padraoSize){
			return 1;
		}
	}
	return 0;
}

int main(){

	char padrao[1000001];
	char texto[300001];
	long int padraoSize;
	long int textoSize;
	int i = 0;


	while(1){
		
		scanf("%s", padrao);
		if(padrao[0] == '0' && padrao[1] == '\0'){
			break;
		}
		if(i != 0){
			printf("\n");
		}
		scanf("%s", texto);

		padraoSize = strlen(padrao);
		textoSize = strlen(texto);

		if(casamentoBruto(texto, textoSize, padrao, padraoSize) == 1){
			printf("Instancia %d\nverdadeira\n", i+1);
		}
		else{
			printf("Instancia %d\nfalsa\n", i+1);
		}

		++i;
	}



	return 0;
}