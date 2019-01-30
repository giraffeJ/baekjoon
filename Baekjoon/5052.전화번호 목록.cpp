#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int i, j, k, n, m, w, tcn, tc, sw;
char in[10010][12];
struct trie {
	trie *next[10];
	bool end = false;
};
trie *root = new trie();
int main() {
	scanf("%d", &tcn);
	for (tc = 1; tc <= tcn; tc++) {
		scanf("%d", &n);
		root = new trie();
		sw = 0;
		for (i = 1; i <= n; i++) {
			scanf("%s", &in[i]);
			if (sw == 0) {
				m = strlen(in[i]);
				trie *pos = root;
				for (j = 0; j < m - 1; j++) {
					w = in[i][j] - 48;
					if ((*pos).end == true) break;
					if (!(*pos).next[w]) {
						trie *temp = new trie();
						(*pos).next[w] = temp;
					}
					pos = (*pos).next[w];
					if ((*pos).end == true) break;
				}
				w = in[i][j] - 48;
				if (j != m - 1 || (*pos).next[w])
					sw = 1;
				trie *temp = new trie();
				(*pos).next[w] = temp;
				pos = (*pos).next[w];
				(*pos).end = true;
			}
		}
		if (sw == 1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	scanf("%d", &n);
}