#include<stdio.h>
#include<algorithm>
using namespace std;
int n, a[1010];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}