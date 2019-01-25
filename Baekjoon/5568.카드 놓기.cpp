#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int i, j, k, n, m, card[12], temp[6], c[12], cnt = 0;
vector<int> a;
void makeseq(int pos) {
	int i, sum;
	if (pos == k + 1) {
		sum = 0;
		for (i = 1; i <= k; i++) {
			if (temp[i] >= 10) sum *= 10;
			sum = sum * 10 + temp[i];
		}
		a.push_back(sum);
	}
	else {
		for (i = 1; i <= n; i++) {
			if (c[i] == 0) {
				temp[pos] = card[i];
				c[i] = 1;
				makeseq(pos + 1);
				c[i] = 0;
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++) {
		scanf("%d", &card[i]);
	}
	makeseq(1);
	m = a.size();
	sort(a.begin(), a.end());
	cnt = 1;
	for (i = 1; i < m; i++) {
		if (a[i] != a[i - 1]) cnt++;
	}
	printf("%d\n", cnt);
	scanf("%d %d", &n, &k);
}
