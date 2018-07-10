#include <list>
#include <stdio.h>
#define maxd 302

using namespace std;

typedef struct {
	int fac;
	int pow;
}Data;

// 统一处理 fac为0情况 怀疑有问题 确实，为什么？
void printList(list<Data> l) {
	list<Data>::iterator i = l.begin();
//	if((*i).fac == 0) i = l.erase(i);
	printf("[ %d %d ]", (*i).fac, (*i).pow);
	i++;
	for(; i != l.end(); i++) {
//		if((*i).fac == 0) i = l.erase(i);
		printf(" [ %d %d ]", (*i).fac, (*i).pow);
	}
	printf("\n");
}

void printListV2(list<Data> l) {
	for(list<Data>::iterator i = l.begin(); i != l.end(); i++) {
		if((*i).fac == 0) continue;
		printf("[ %d %d ] ", (*i).fac, (*i).pow);
	}
	printf("\n");
}
int readInt(char & ch) { //必须引用，接收最后一个非数字字母
	int t = 0, p = 1;
	if(ch == '-') p = -1;
	else t = ch - '0';

	do {
		ch = getchar();
		if(ch >= '0' && ch <= '9')
			t = t * 10 + ch - '0';
	}while(ch >= '0' && ch <= '9');
	
	t = t * p;
	// printf("%d", t);
	return t;
}

bool readData(int & d1, int & d2) {
	char ch;
	do {
		ch = getchar();	
	}while(ch != '-' && (ch < '0' || ch > '9'));
	
	d1 = readInt(ch);
        
	do {
                ch = getchar();
        }while(ch != '-' && (ch < '0' || ch > '9'));

        d2 = readInt(ch);
	
	if(d2 <0) {
		while(ch != '\n' && ch != '\r')
			ch = getchar();
	}
	return true;
}

void addDatatoList(Data a, list<Data> & l) {
	if(l.empty()) l.push_front(a);
	else {
		bool isInsert = false;  // 若没在中间插入，则插入末尾。
		for(list<Data>::iterator i = l.begin(); i != l.end(); i++) {
			if(a.pow > (*i).pow) {
				l.insert(i, a);
				isInsert = true;
				break;
			}
			// 可能幂数相同，合并
			if(a.pow == (*i).pow) {
				(*i).fac += a.fac;
				isInsert = true;
				if((*i).fac == 0) i = l.erase(i); // way2  处理系数为0
				break;
			}
		}
		if(!isInsert) l.push_back(a);
	}

}
void createList(list<Data> & l) { //必须加&，不然返回空
	int d1, d2, idx = 0;
	bool isInsert;
	/*
	while(readData(d1, d2) && d2 >= 0) {
		Data a;
		a.fac = d1;
		a.pow = d2;
		addDatatoList(a, l);
		
	}
	*/
	char s[300];
	Data a;
	while(scanf("%d%d", &d1, &d2) == 2 && d2 >= 0) {
		a.fac = d1;
		a.pow = d2;
		addDatatoList(a, l);
	}
	scanf("%[^\n]", s);
	// printf("\n");
	// printList(l);
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		list<Data> l1, l2;
		createList(l1);
		createList(l2);

		list<Data>::iterator p, q;
		//printList(l1);
		//printList(l2);

		p = l1.begin();
		q = l2.begin();
		while(p != l1.end() && q != l2.end()) {
			if(p->pow == q->pow) {
				p->fac = (p->fac + q-> fac);
				q++;
				if(p->fac == 0) p = l1.erase(p); // 处理系数为0
				else p++;
				
			}
			else if(p->pow < q->pow) {
				Data a;
				a.fac = q->fac;
				a.pow = q->pow;
				p = l1.insert(p, a);
				p++;
				q++;
			}
			else p++;
			//printList(l1);
			//printList(l2);
		}
		if(p == l1.end()) {
			while(q != l2.end()) {
				Data a;
				a.fac = q->fac;
				a.pow = q->pow;
				l1.push_back(a);
				q++;
			}
		}
		//printList(l1);
		printListV2(l1);
	}
}
