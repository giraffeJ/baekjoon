#include<stdio.h>
int a[5010], n, m, pos, cnt;
int main() {
	scanf("%d %d", &n, &m);
	pos = 1;
	printf("<");
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		while (cnt < m) {
			if (pos == n + 1) pos = 1;
			if (a[pos++] == 0) cnt++;
		}
		a[pos - 1] = 1;
		printf("%d", pos - 1);
		if (i < n) printf(", ");
	}
	printf(">\n");
}