#include<stdio.h>
int hc[16][16], tcn, sum, k, n;
int main() {
	for (int i = 1; i <= 14; i++)
		hc[0][i] = i;
	for (int i = 1; i <= 14; i++) {
		sum = 0;
		for (int j = 1; j <= 14; j++) {
			sum += hc[i - 1][j];
			hc[i][j] = sum;
		}
	}
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%d %d", &k, &n);
		printf("%d\n", hc[k][n]);		
	}
}