#include <list>
#include <stdio.h>
using namespace std;

#define maxd 201

void printList(list<int> l) {
	for(list<int>::iterator i = l.begin(); i != l.end(); i++)
		printf("%d", *i);
	printf("\n");
}

void cvrInt(char * s, list<int> & l) {
	for(int i = 0; s[i] != '\0'; i++)
		l.push_back(s[i] - '0');
	// printList(l);
}

void addMulti(list<int> tmp, int lmv, list<int> & res) {
	list<int>::reverse_iterator i, j, cvtr;
	i = tmp.rbegin(); j = res.rbegin();
	int t, plus = 0;
	
	for(int k = 0; k < lmv; k++) {
		j++;
		if(j == res.rend())
			res.push_front(0);
	}

	for(; i != tmp.rend(); i++, j++) {
		if(!lmv) res.push_front(*i);
		else {				
			if(j != res.rend()) {
				t = (*j + *i + plus);
				plus = t/10;
				*j = t%10;
			} else {
				t = *i + plus;
				plus = t/10;
				res.push_front(t%10);
			}
		}
	}
	while(j != res.rend()) {
		*j = *j+plus;
		plus = *j/10;
		*j = *j%10;

		j++;
	}
	if(plus) res.push_front(plus);

	int kase = 0;
	// printf("#%d:\n", ++kase);
	// printList(tmp);
	// printList(res);
}

void multiply(list<int> l1, list<int> l2, list<int> & l3) {
	list<int> tmp;
	list<int>::reverse_iterator p, q;
	int t, plus, i = 0;
	// p = l1.rbegin();
	// q = l2.rbegin();
	for(q = l2.rbegin(); q != l2.rend(); q++) {
		plus = 0;
		tmp.clear();
		for(p = l1.rbegin(); p != l1.rend(); p++) {
			t = ((*p) * (*q)) % 10 + plus;
			plus = t / 10 + (*p)*(*q)/10;
			t = t%10;
			tmp.push_front(t);
		}
		if(plus) tmp.push_front(plus);
		// printf("tmp %d: ", i);
		// printList(tmp);
		addMulti(tmp, i++, l3);
	}
}

int main() {
	char s[maxd];
	list<int> l1, l2, res;
	
	scanf("%s", s);
	cvrInt(s, l1);
	// printList(l1);

	scanf("%s", s);
	cvrInt(s, l2);
	// printList(l2);

	multiply(l1, l2, res);
	printList(res);
}
