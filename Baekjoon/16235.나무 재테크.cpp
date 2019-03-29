#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[11][11], nut[11][11];
vector<int> tree[11][11];
int n, m, k, x, y, age, year, res;
void get_a() { 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			nut[i][j] = 5;
		}
	}
}
void get_trees() {
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &age);
		tree[x][y].push_back(age);
	}
}
void sort_trees() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sort(tree[i][j].begin(), tree[i][j].end());
		}
	}
}
void spring_summer() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int dead_tree_nut = 0;
			for (int l = 0; l < tree[i][j].size(); l++) {
				if (tree[i][j][l] <= nut[i][j]) {
					nut[i][j] -= tree[i][j][l];
					tree[i][j][l]++;
				}
				else {
					dead_tree_nut += (tree[i][j][l] / 2);
					tree[i][j].erase(tree[i][j].begin()+l);
					l--;
				}
			}
			nut[i][j] += dead_tree_nut;
		}
	}
}
void breed(int x, int y) {
	int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
	int dy[9] = { 0, 0, 1, 1, 1, 0, -1, -1, -1 };
	for (int i = 1; i <= 8; i++) {
		if (x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= n) {
			tree[x + dx[i]][y + dy[i]].push_back(1);
		}		
	}
}
void fall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int l = 0; l < tree[i][j].size(); l++) {
				if (tree[i][j][l] % 5 == 0) {
					breed(i, j);
				}
			}
		}
	}
}
void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			nut[i][j] += a[i][j];
		}
	}
}
int count_tree() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt += tree[i][j].size();
		}
	}
	return cnt;
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	get_a();
	get_trees();
	sort_trees();
	for (int year = 1; year <= k; year++) {
		spring_summer();
		fall();
		winter();
		sort_trees();
	}
	res = count_tree();
	printf("%d\n", res);
}