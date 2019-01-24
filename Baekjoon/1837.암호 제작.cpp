#include<stdio.h>
#include<string.h>
int i, j, k, m, a[1000030], re;
char n[1001];
int check(int pn) {
	int i;
	long long int sum = 0;
	for (i = 0; i <m; i++) {
		sum = (sum * 10 + (n[i] - '0')) % pn;
	}
	return sum;
}
int main() {
	scanf("%s %d", &n, &k);
	m = strlen(n);
	for (i = 2; i <= k; i++) {
		a[i] = 1;
	}
	for (i = 2; i < k; i++) {
		if (a[i] == 1) {
			re = check(i);
			if (re == 0) {
				printf("BAD %d\n", i);
				break;
			}
			else {
				for (j = i; j <= k; j += i) {
					a[j] = 0;
				}
			}
		}
	}
	if (i == k) {
		printf("GOOD\n");
	}
	scanf("%d %d", &n, &k);
}