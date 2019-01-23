#include<stdio.h>
#include<string.h>
int i, j, n, m, stack[100001], top = -1, x, y, z, w, sum;
char a[100001];
void push(int k) {
	stack[++top] = k;
}
int pop() {
	if (top == -1) return -1;
	else return stack[top--];
}
int main() {
	scanf("%s", &a);
	n = strlen(a);//[][[]([])[][[]()[[]()[[[]]]]]]
	x = y = z = w = 0;
	for (i = 0; i < n; i++) {
		if (a[i] == '(') x++;
		else if (a[i] == ')') y++;
		else if (a[i] == '[') z++;
		else if (a[i] == ']') w++;
		else break;
	}
	if (i < n || x != y || z != w) printf("0\n");
	else {
		for (i = 0; i < n; i++) {
			x = a[i];
			if (x == '(') push(2);
			else if (x == '[') push(3);
			else if (x == ')') {
				y = pop();
				if (y == 2) push(-2);
				else {
					sum = y;
					while (1) {
						y = pop();
						if (y == 2) {
							sum *= 2;
							push(sum);
							break;
						}
						else if (top == -1) break;
						sum += y;
					}
					if (top == -1) break;
				}
			}
			else {
				y = pop();
				if (y == 3) push(-3);
				else {
					sum = y;
					while (1) {
						y = pop();
						if (y == 3) {
							sum *= 3;
							push(sum);
							break;
						}
						else if (top == -1) break;
						sum += y;
					}
					if (top == -1) break;
				}
			}
		}
		sum = 0;
		while (top != -1) {
			y = pop();
			if (y == '[' || y == ']' || y == '(' || y == ')') {
				i--;
				break;
			}
			sum += y;
		}
		push(sum);
		if (i != n) printf("0\n");
		else printf("%d\n", stack[top] * -1);
	}
	scanf("%d", &n);
}