#include<stdio.h>
#include<vector>
using namespace std;
int i, j, k, n, m, a[1100001], p[1100001], s, e, re[1100001];
vector<pair<int, int>> d;
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	p[1] = -1;
	d.push_back({ -2000000000, -1 });
	d.push_back({ a[1],1 });
	for (i = 2; i <= n; i++) {
		if (d[d.size() - 1].first < a[i]) {
			d.push_back({ a[i], i });
			p[i] = d[d.size() - 2].second;
		}
		else {
			s = 0;
			e = d.size() - 1;
			m = (s + e) / 2;
			while (s < e) {
				m = (s + e) / 2;
				if (d[m].first == a[i] || d[m].first<a[i] && d[m + 1].first>a[i]) break;
				if (d[m].first >= a[i]) e = m;
				else s = m + 1;
			}
			if (d[m].first == a[i]) {
				p[i] = d[m - 1].second;
			}
			else if (d[m].first<a[i] && d[m + 1].first>a[i]) {
				d[m + 1].first = a[i];
				d[m + 1].second = i;
				p[i] = d[m].second;
			}
		}
	}
	m = d.size();
	printf("%d\n", m - 1);
	i = d[m - 1].second;
	while (1) {
		re[--m] = a[i];
		i = p[i];
		if (i == -1) break;
	}
	for (i = 1; i < d.size(); i++) {
		printf("%d ", re[i]);
	}
	printf("\n");
	scanf("%d", &n);
}