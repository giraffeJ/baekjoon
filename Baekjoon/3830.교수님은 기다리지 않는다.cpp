#include<stdio.h>
long long int i, j, k, n, m, root[100050], val[100050], x, y, z;
char mod;
struct node {
	long long int root;
	long long int val;
};
long long int calc(long long int pos, long long int parent);
node parent(long long int pos) {
	node a;
	if (root[pos] == pos) {
		return{ pos, 0 };
	}
	else {
		a = parent(root[pos]);
		root[pos] = a.root;
		val[pos] = a.val + val[pos];
		return{ a.root, val[pos] };
	}
}
void make(long long int x, long long int y, long long int dif) {
	node px, py;
	px = parent(x);
	py = parent(y);
	if (px.root != py.root) {
		val[px.root] = val[y] + dif - val[x];
		root[px.root] = py.root;
	}
}
void finddif(long long int x, long long int y) {
	node px, py;
	px = parent(x);
	py = parent(y);
	if (px.root != py.root) {
		printf("UNKNOWN\n");
	}
	else {
		printf("%lld\n", px.val - py.val);
	}
}
int main() {
	while (1) {
		scanf("%lld %lld", &n, &m);
		if (n == 0 && m == 0) break;
		for (i = 1; i <= n; i++) {
			val[i] = 0;
			root[i] = i;
		}
		for (i = 1; i <= m; i++) {
			scanf(" %c ", &mod);
			if (mod == '?') {
				scanf("%lld %lld", &x, &y);
				finddif(x, y);
			}
			else {
				scanf("%lld %lld %lld", &x, &y, &z);
				make(x, y, z);
			}
		}
	}
}