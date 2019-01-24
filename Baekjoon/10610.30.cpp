#include<stdio.h>
#include<string.h>
int i, j, k, n, m, d[20], sum = 0;
char a[200001];
int main() {
	scanf("%s", &a);
	n = strlen(a);
	for (i = 0; i <= n; i++) {
		m = a[i] - '0';
		d[m]++;
		sum += m;
	}
	if (d[0] == 0 || sum % 3 != 0) {
		printf("-1\n");
	}
	else {
		for (i = 9; i >= 0; i--) {
			for (j = 1; j <= d[i]; j++) {
				printf("%d", i);
			}
		}
		printf("\n");
	}
	scanf("%s", &a);
}