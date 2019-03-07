#include<stdio.h>
#include<string.h>
int nc[10], n, k, max;
char num[8];
int main() {
	scanf("%s", &num);
	n = strlen(num);
	for (int i = 0; i < n; i++) {
		k = num[i] - 48;
		if (k == 9) k = 6;
		nc[k]++;
	}
	nc[6] = (nc[6] + 1) / 2;
	max = -1;
	for (int i = 0; i <= 8; i++) {
		if (nc[i] > max) max = nc[i];
		nc[i] = 0;
	}
	printf("%d\n", max);
}