#include <stdlib.h>
#include <stdio.h>

int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
int Div(int a, int b) {
	if (b == 0) {
		printf("Error: Division by zero\n");
		return 0;
	}
	return a / b;
}
int mod(int a, int b) {
	if (b == 0) {
		printf("Error: Division by zer\n");
		return 0;
	}
	return a % b;
}
