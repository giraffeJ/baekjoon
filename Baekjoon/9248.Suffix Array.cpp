#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int i, j, k, n, m, ran[500030], x, y;
char a[500030];
int lcp[500030];
struct list {
	int fr;
	int sr;
	int idx;
	bool operator<(const list &a) const {
		return fr == a.fr ? sr < a.sr : fr < a.fr;
	}
}arr[500030];
int main() {
	scanf("%s", a + 1);
	n = strlen(a + 1);
	//arr�� ���ڸ� fr��, sr�� 0���� �ʱⰪ ����.
	for (i = 1; i <= n; i++) {
		arr[i] = { a[i] - 'a', 0, i };
	}
	//���λ��� ù ���ڸ� �������� ����.
	sort(arr + 1, arr + n + 1);
	for (i = 1; i < n; i *= 2) {
		ran[arr[1].idx] = 1;
		for (j = 2; j <= n; j++) {
			if (arr[j].fr == arr[j - 1].fr && arr[j].sr == arr[j - 1].sr)
				ran[arr[j].idx] = ran[arr[j - 1].idx];
			else
				ran[arr[j].idx] = ran[arr[j - 1].idx] + 1;
		}
		for (j = 1; j <= n; j++) {
			if (arr[j].idx + i <= n)
				arr[j] = { ran[arr[j].idx], ran[arr[j].idx + i], arr[j].idx };
			else
				arr[j] = { ran[arr[j].idx], 0, arr[j].idx };
		}
		//���� ������ fr�� sr�� �������� ����.
		sort(arr + 1, arr + n + 1);
	}
	//suffix array ���
	for (i = 1; i <= n; i++) {
		ran[arr[i].idx] = i;
		printf("%d ", arr[i].idx);
	}
	printf("\n");
	j = 0;
	//lcp���.
	for (i = 1; i < n; i++) {
		x = arr[ran[i] - 1].idx;
		while (i + j <= n && x + j <= n && a[i + j] == a[x + j]) {
			j++;
		}
		lcp[ran[i]] = j;
		if (j > 0) j--;
	}
	//lcp ���
	printf("x ");
	for (i = 2; i <= n; i++) {
		printf("%d ", lcp[i]);
	}
}