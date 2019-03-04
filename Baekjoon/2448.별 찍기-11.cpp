#include<stdio.h>
int i, j, k, n, m, a[5001][10001];
void star(int size, int x, int y) {
	if (size == 3) {
		a[x][y] = a[x + 1][y - 1] = a[x + 1][y + 1] = a[x + 2][y - 2] = a[x + 2][y - 1] = a[x + 2][y] = a[x + 2][y + 1] = a[x + 2][y + 2] = 1;
		return;
	}
	star(size / 2, x, y);
	star(size / 2, x + (size / 2), y - (size / 2));
	star(size / 2, x + (size / 2), y + (size / 2));
}
int main() {
	scanf("%d", &n);
	star(n, 1, n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n * 2; j++) {
			if (a[i][j] == 1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	scanf("%d", &n);
}