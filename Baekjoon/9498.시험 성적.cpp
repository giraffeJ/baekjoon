#include<stdio.h>
int score, i, standard[6] = { 0, 90, 80, 70, 60, 0 };
char rank[7] = " ABCDF";
int main() {
	scanf("%d", &score);
	for (i = 1; i <= 5; i++) {
		if (score >= standard[i]) {
			printf("%c\n", rank[i]);
			break;
		}
	}
}