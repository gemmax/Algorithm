//#define LOCAL

#include <stdio.h>
#include <math.h>
#include <stack>
#include <stdlib.h> // for generate random number to test function.

using namespace std;

void opFunc(stack<double> & num, stack<char> & op) {
	double v1, v2;
	char op_ch;
	if(num.size() > 1) {
		if(op.top() == '(') return;
		v2 = num.top();
		num.pop();
		v1 = num.top();
		num.pop();
		op_ch = op.top();
		op.pop();
		
//		printf("%.2f %c %.2f\n", v1, op_ch, v2);
		
		if(op_ch == '-') {
			num.push(v1 - v2);
		}
		else if(op_ch == '+') {
			num.push(v1 + v2);
		}
		else if(op_ch == '*'){
			num.push(v1 * v2);
		}
//		printf("size:%lu\n", num.size());
//		printf("top:%.2f\n", num.top());
	}
}

double calculate(stack<double> & num, stack<char> & op) {
	// return rand()%10;
	int ch;
	double t;

	// avoid get null value
	do {
		ch = getchar(); 
	} while(ch == '\r' || ch == '\n');

	while(ch != '\r' && ch != '\n') {
		if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
			t = ch;
			num.push(t);
			opFunc(num, op); // alpha calculate ,num pop 2, op pop 1
		}
		else if(ch >= '0' && ch <= '9') {
			t = ch - '0';
			num.push(t);
			opFunc(num, op); // num calculate, num pop 2, op pop 1
		}
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '(' || ch == ')') {
			op.push(ch);
			if(ch == ')') {
				op.pop();
				op.pop();
				opFunc(num, op);
			}
		}

		ch = getchar();
	}
	
	return num.top();
}

double calculateVal() {
	stack<double> num;
	stack<char> op;
	return calculate(num, op);
}

bool isEqualFunction(double v1, double v2) {
//	printf("v1:%.2f - v2:%.2f\n", v1, v2);
	return fabs(v1-v2) < 1 ? true : false;
}

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	double res1, res2;
	bool isEqual;

	scanf("%d", &n);

	while(n--) {
		res1 = calculateVal();
		res2 = calculateVal();
		isEqual = isEqualFunction(res1, res2);
		printf("%s\n", isEqual? "YES":"NO");
	}
}
