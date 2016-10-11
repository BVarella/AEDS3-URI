#include <stdio.h>

int has_repeated_digit(int number){

	int digit_counter[10] = {0};
	int i;

	while(number){
		++digit_counter[number % 10];
		number /= 10;
	}
	
	for (i = 0; i < 10; ++i)
		if(digit_counter[i] > 1)
			return 1;

	return 0;
}

int main(){

	int N, M, i, answer;

	while(scanf("%d %d", &N, &M) == 2){

		answer = 0;

		for(i = N; i <= M; ++i)
			if(!has_repeated_digit(i))
				++answer;

		printf("%d\n", answer);
	}
	
	return 0;
}