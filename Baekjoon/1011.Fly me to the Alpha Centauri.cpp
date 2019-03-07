#include<stdio.h>
typedef long long int lli;
lli tcn, x, y, z, m;
int main() {
	scanf("%lld", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%lld %lld", &x, &y);
		z = y - x;
		m = 1;
		for (int i = 1; ; i++) {
			if (z <= m) {
				printf("%lld\n", i);
				break;
			}
			m += ((i / 2) + 1);
		}
	}
} //2019.03.07

/* 2019.01.05 ¼Ò½º
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
*/