#include<stdio.h>
int n, sum, cnt;
int main() {
	while (scanf("%d", &n) != EOF) {
		sum = 0;
		cnt = 0;
		while (1) {
			cnt++;
			sum = sum * 10 + 1;
			sum = sum % n;
			if (sum == 0) break;
		}
		printf("%d\n", cnt);
	}
}