#include <stdio.h>
#include <string.h>

int main(){

	int numTestes, numCidades, numVisiveis, a, b;
	int i, j;
	int cidades[100];
	int result;

	scanf("%d", &numTestes);
	for(i = 0; i < numTestes; ++i){
		memset (cidades, 0, sizeof(cidades));
		result = 0;
		scanf("%d %d", &numCidades, &numVisiveis);
		for(j = 0; j < numVisiveis; ++j){
			scanf("%d %d", &a, &b);
			cidades[a] += 1;
			cidades[b] += 1;
		}
		for(j = 0; j < numCidades; ++j){
			if(cidades[j] == numCidades-1)
				++result;
		}
		printf("%d\n", result);
	}

	return 0;
}