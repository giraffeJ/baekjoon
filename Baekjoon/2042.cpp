#include<stdio.h>
long long int ind[3000001], i, j, n, m, k, x, y, siz, s, sum, dif, z;
long long int settree(long long int pos) {
	if (pos >= s && pos < siz) {
		return ind[pos];
	}
	else {
		ind[pos] = settree(pos * 2) + settree(pos * 2 + 1);
		return ind[pos];
	}
}
void chgtree(long long int pos, long long int val) {
	while (1) {
		ind[pos] += val;
		pos /= 2;
		if (pos == 0) break;
	}
}
long long int getval(long long int s, long long int e) {
	long long int sum = 0;
	while (s <= e) {
		if (s % 2 == 1) sum += ind[s];
		s = (s + 1) / 2;
		if (e % 2 == 0) sum += ind[e];
		e = (e - 1) / 2;
	}
	return sum;
}
int main() {
	scanf("%lld %lld %lld", &n, &m, &k);
	siz = 1;
	while (siz < n) {
		siz *= 2;
	}
	s = siz;
	siz *= 2;
	for (i = 1; i <= n; i++) {
		scanf("%lld", &ind[s + i - 1]);
	}
	for (i = s + n; i < siz; i++) {
		ind[i] = 0;
	}
	sum = settree(1);
	for (i = 1; i <= m + k; i++) {
		scanf("%lld %lld %lld", &x, &y, &z);
		if (x == 1) {
			dif = z - ind[y + s - 1];
			chgtree(y + s - 1, dif);
		}
		else if (x == 2) {
			printf("%lld\n", getval(y + s - 1, z + s - 1));
		}
	}
	scanf("%lld %lld %lld", &n, &m, &k);
}