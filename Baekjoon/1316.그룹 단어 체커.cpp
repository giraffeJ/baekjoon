#include<stdio.h>
#include<string.h>
int i, n, res, tcn, c[26];
char a[102];
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%s", &a);
		n = strlen(a);
		for (i = 0; i <= 25; i++) c[i] = 0;
		c[a[0] - 'a'] = 1;
		for (i = 1; i < n; i++) {
			if (a[i] != a[i - 1]) {
				if (c[a[i] - 'a'] != 0) {
					break;
				}
				c[a[i] - 'a'] = 1;
			}
		}
		if (i == n) {
			res++;
		}
	}
	printf("%d\n", res);
	scanf("%d", &tcn);
}