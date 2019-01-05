#include<stdio.h>
int tcn, i, j, n, m, k, val, x, y;
__int64 sum;
int main() {
	scanf("%d", &tcn);
	for (i = 1; i <= tcn; i++) {
		scanf("%d %d", &x, &y);
		n = y - x;
		sum = 1;
		val = 1;
		for (j = 1; ; j++) {
			if (n <= sum) {
				printf("%d\n", j);
				break;
			}
			if (j % 2 == 0) val++;
			sum += val;
		}			
	}
	scanf("%d", &tcn);
}