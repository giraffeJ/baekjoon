#include<stdio.h>
#include<string.h>
long long int i, j, k, n, m, de, nu, temp, temp2;
char te[201][101], inp;
long long int gcd(long long int a, long long int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int main() {
	scanf("%lld", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", &te[i]);
		m = strlen(te[i]);
		de = 1;
		nu = 0;
		temp = 0;
		temp2 = 0;
		for (j = 2; j < m; j++) {
			if (te[i][j] != '(') {
				nu = nu * 10 + (te[i][j] - '0');
				de *= 10;
			}
			else break;
		}
		if (j != m) {
			j++;
			de *= 9;
			temp = de;
			temp2 = nu;
			de = 0;
			for (; j < m - 1; j++) {
				nu = nu * 10 + (te[i][j] - '0');
				de = de * 10 + temp;
			}
			nu -= temp2;
		}
		temp = gcd(de, nu);
		printf("%lld/%lld\n", nu/temp, de/temp);
	}
	scanf("%lld", &n);
}