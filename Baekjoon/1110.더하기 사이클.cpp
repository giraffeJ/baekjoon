#include<stdio.h>
int n, m, temp, k, cnt;
int main() {
	scanf("%d", &n);
	m = n;
	cnt = 1;
	while (1) {
		temp = m;
		k = 0;
		while (temp > 0) {
			k += temp % 10;
			temp /= 10;
		}
		m = ((m % 10) * 10) + k % 10;
		if (m == n) {
			printf("%d\n", cnt);
			break;
		}
		cnt++;
	}
}