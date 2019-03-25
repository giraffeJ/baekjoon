#include<stdio.h>
#include<string.h>
char a[60];
int stack[100], top = -1;
void push(int k) {
	stack[++top] = k;
}
int pop() {
	return stack[top--];
}
int n, tcn, temp, i;
int main() {
	scanf("%d", &tcn);
	for (int tc = 1; tc <= tcn; tc++) {
		scanf("%s", &a);
		n = strlen(a);
		for (i = 0; i < n; i++) {
			if (a[i] == '(') {
				push(1);
			}
			if (a[i] == ')') {
				if (top == -1) break;
				else temp = pop();
			}
		}
		if (i == n && top == -1) printf("YES\n");
		else printf("NO\n");
		while (top != -1) {
			temp = pop();
		}
	}
	return 0;
}