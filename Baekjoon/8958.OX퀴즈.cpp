#include<stdio.h>
#include<string.h>
int i, j, n, k, sum, cnt;
char a[100];
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf(" %s", &a);
		k = strlen(a);
		sum = 0;
		cnt = 0;
		for (j = 0; j < k; j++) {
			if (a[j] == 'O') cnt++;
			else cnt = 0;
			sum+=cnt;
		}
		printf("%d\n", sum);
	}
	scanf("%d", &n);
}