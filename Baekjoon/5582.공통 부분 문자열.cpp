#include<stdio.h>
#include<string.h>
int i, j, k, n, m, d[4020][4020], max;
char a[4021];
char b[4021];
int main() {
	scanf("%s ", &a);
	scanf("%s", &b);
	n = strlen(a);
	m = strlen(b);
	max = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (a[i] == b[j])
				d[i + 1][j + 1] = d[i][j] + 1;
			if (d[i + 1][j + 1] > max) max = d[i + 1][j + 1];
		}
	}
	printf("%d\n", max);
	scanf("%d", &n);
}