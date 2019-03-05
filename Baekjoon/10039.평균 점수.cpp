#include<stdio.h>
int score, avg;
int main() {
	for (int i = 1; i <= 5; i++) {
		scanf("%d", &score);
		if (score < 40) score = 40;
		avg += (score / 5);
	}
	printf("%d\n", avg);
	scanf("%d", &score);
}