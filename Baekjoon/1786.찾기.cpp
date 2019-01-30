#include<stdio.h>
#include<string.h>
int i, j, k, n, m, f[1000030], res[1000030];
char t[1000030], p[1000030];
int main() {
	scanf("%[^\n]", &t);
	getchar();
	n = strlen(t);
	for (i = n; i >= 1; i--) t[i] = t[i - 1];
	scanf("%[^\n]", &p);
	m = strlen(p);
	for (i = m; i >= 1; i--) p[i] = p[i - 1];
	j = 0;
	for (i = 1; i <= m; i++) {
		while (j != 0 && p[i + 1] != p[j + 1])
			j = f[j];
		if (p[i + 1] == p[j + 1]) {
			f[i + 1] = j + 1;
			j++;
		}
	}
	for (i = 0, j = 0; i < n; i++) {
		while (j != 0 && t[i + 1] != p[j + 1])
			j = f[j];
		if (t[i + 1] == p[j + 1])
			j++;
		if (j == m) {
			res[++res[0]] = i - m + 2;
			j = f[j];
		}
	}
	printf("%d\n", res[0]);
	for (i = 1; i <= res[0]; i++)
		printf("%d ", res[i]);
	scanf("%d", &n);
}