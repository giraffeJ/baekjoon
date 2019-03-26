#include<stdio.h>
int a[1010], n, m, cnt, j;
int main() {
	scanf("%d %d", &n, &m);
	printf("<");
	j = 0;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		j++;
		for ( ; ; j++) {
			if (j == n + 1) j = 1;
			if (a[j] == 0) cnt++;
			if (cnt == m) break;
		}
		printf("%d", j);
		a[j] = 1;
		if (i < n) printf(", ");
	}
	printf(">\n");
}