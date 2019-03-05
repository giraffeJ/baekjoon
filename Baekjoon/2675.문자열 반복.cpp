#include<stdio.h>
#include<string.h>
int tcn, n, m;
char a[22];
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%d", &m);
		scanf(" %s", &a);
		n = strlen(a);
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= m; j++) {
				printf("%c", a[i]);
			}
		}
		printf("\n");
	}
	scanf("%d", &tcn);
}