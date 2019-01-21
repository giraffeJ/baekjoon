#include<stdio.h>
#include<algorithm>
#include<functional>
using namespace std;
int n, m, a[1000030], i, j, k, cnt, cut, cutt;
long long int sum;
int main() {
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1, greater<int>());
	if (a[1]>m) cut = a[1] - m;
	else cut = 0;
	for (i = 1; i <= n; i++) {
		if (a[i] < cut) break;
		sum += a[i] - cut;
		if (sum > m) {
			cutt = (sum - m) / i;
			sum = sum - i * cutt;
			cut += cutt;
		}
	}
	printf("%d\n", cut);
}