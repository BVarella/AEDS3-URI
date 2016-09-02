#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){

	int numTestes;
	char senha[32];
	int letrasEspeciais, letrasNormais, resposta;

	int i, j;
	scanf("%d", &numTestes);
	for(i = 0; i < numTestes; ++i){
		scanf("%s", senha);
		letrasEspeciais = 0;
		letrasNormais = 0;
		for(j = 0; j < 32; ++j){
			if(senha[j] == '\0'){
				break;
			}
			else if(senha[j] == 'a' || senha[j] == 'A'
					|| senha[j] == 'e' || senha[j] == 'E'
					|| senha[j] == 'i' || senha[j] == 'I'
					|| senha[j] == 'o' || senha[j] == 'O'
					|| senha[j] == 's' || senha[j] == 'S'){
				
				++letrasEspeciais;
			}
		}
		letrasNormais = strlen(senha) - letrasEspeciais;
		resposta = pow(2, letrasNormais) * pow(3, letrasEspeciais);
		printf("%d\n", resposta);
	}
}