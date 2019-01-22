#include<stdio.h>
#include<algorithm>
using namespace std;
long long int i, j, k, n, m, cnt, x, y, res;
long long int a[2001], b[2001], at[2001], bt[2001], as[600001], bs[600001];
struct list {
	long long int value;
	long long int count;
} ar[600001], br[600001];
long long int an, bn, asn, bsn, arn, brn;
bool comp(list a, list b) {
	if (a.value < b.value) return true;
	else return false;
}
int main() {
	scanf("%lld", &n);
	scanf("%lld", &an);
	for (i = 1; i <= an; i++) {
		scanf("%lld", &a[i]);
	}
	scanf("%lld", &bn);
	for (i = 1; i <= bn; i++) {
		scanf("%lld", &b[i]);
	}
	for (i = 1; i <= an; i++) {
		at[i] = at[i - 1] + a[i];
	}
	for (i = 1; i <= bn; i++) {
		bt[i] = bt[i - 1] + b[i];
	}
	for (i = 1; i <= an; i++) {
		for (j = i; j <= an; j++) {
			as[++asn] = at[j] - at[i - 1];
		}
	}
	for (i = 1; i <= bn; i++) {
		for (j = i; j <= bn; j++) {
			bs[++bsn] = bt[j] - bt[i - 1];
		}
	}
	sort(as + 1, as + asn + 1);
	sort(bs + 1, bs + bsn + 1);
	as[asn + 1] = -2100000000;
	bs[bsn + 1] = -2100000000;
	for (i = 1; i <= asn; i++) {
		j = i;
		cnt = 1;
		while (as[j] == as[j + 1]) {
			cnt++;
			j++;
		}
		i = j;
		ar[++arn].value = as[i];
		ar[arn].count = cnt;
	}
	for (i = 1; i <= bsn; i++) {
		j = i;
		cnt = 1;
		while (bs[j] == bs[j + 1]) {
			cnt++;
			j++;
		}
		i = j;
		br[++brn].value = bs[i];
		br[brn].count = cnt;
	}
	sort(ar + 1, ar + arn + 1, comp);
	sort(br + 1, br + brn + 1, comp);
	x = 1;
	y = brn;
	res = 0;
	while (1) {
		if (ar[x].value + br[y].value == n) {
			res = res + (ar[x].count*br[y].count);
			x++;
		}
		else if (ar[x].value + br[y].value < n) {
			x++;
		}
		else if (ar[x].value + br[y].value > n) {
			y--;
		}
		if (x == arn + 1 || y == 0) break;
	}
	printf("%lld\n", res);
	scanf("%lld", &n);
}