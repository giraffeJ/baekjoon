#include<stdio.h>
#include <queue> //�켱���� ť�� ���ͽ�Ʈ�� �̿��� �ִܰŸ��� ���Ѵ�. 
#include <vector> //�׸��� �ִܰŸ��� �ϳ� ���� ������ ī��Ʈ�� �������� k���� ��ġ�� ���� ���� ��� �������� ����Ѵ�.
#include <functional>
#include<algorithm>
using namespace std;
struct list {
	int x;
	int val;
} la, lb;
int i, j, k, n, m, x, y, z, val, cnt[2001], d[2001], c[2001];
bool operator<(const list a, const list b) {
	if (a.val > b.val) return true;
	else return false;
}
priority_queue <list> pq;
vector<list> a[2001];
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back({ y, z });
	}
	for (i = 1; i <= n; i++) {
		d[i] = -1;
	}
	pq.push({ 1, 0 });
	while (!pq.empty()) {
		x = pq.top().x;
		val = pq.top().val;
		cnt[x]++;
		if (cnt[x] == k) {
			d[x] = val;
			c[x] = 1;
			c[0]++;
		}
		if (c[0] == n) break; //�̰� ������ �ð��ʰ��� �߿�.
		pq.pop();
		for (j = 0; j < a[x].size(); j++) {
			if (c[a[x][j].x] == 0) {
				pq.push({ a[x][j].x, val + a[x][j].val });
			}
		}
	}
	for (i = 1; i <= n; i++) {
		printf("%d\n", d[i]);
	}
	scanf("%d", &n);
}