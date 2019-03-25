#include<stdio.h>
int a[100010], order[200010];
int num_cnt = 1, order_num, i, n, k;
int stack[100010], top = -1;
void push(int k) {
	stack[++top] = k;
	order[++order_num] = 1;
}
int pop() {
	order[++order_num] = -1;
	return stack[top--];
}
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &k);
		while (k>=num_cnt) 
			push(num_cnt++);
		if (stack[top] == k) 
			int temp = pop();
		else break;
	}
	if (i == n + 1) {
		for (int i = 1; i <= order_num; i++) {
			if (order[i] == 1) printf("+\n");
			else if (order[i] == -1) printf("-\n");
		}
	}
	else
		printf("NO\n");
	return 0;
}