#define LOCAL

#include <stdio.h>

int idxMap(int i) {
	int res = 0;
	for(int j = 1; j < i; j++)
		res += ((1<<j) -1);
	return res;
}

bool readHead(char head[]) {
	char ch;
	int i = 0;
	
	do {
		ch = getchar();
	} while(ch == '\n' || ch == '\r');
	
	head[i++] = ch;
	
	while(true) {
		ch = getchar();
		if(ch == EOF) return false;
		if(ch == '\n' || ch == '\r') {
			head[i] = '\0';
			break;
		}
		
		head[i++] = ch;
	}
	return true;
}

int readInt(int nBits) {
	int res = 0;
	char ch;
	while(nBits) {
		ch = getchar();
		if(ch == '1') {
			res += (1<<(nBits - 1));
			nBits--;
		}
		else if(ch == '0')
			nBits--;
	}

	return res;
}

const int MAXH = (1<< 8);
char head[MAXH]; // 不知道字符串长度，且字符串只处理一次，可以一边读取一边处理，不需要存储。

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w",stdout);
	#endif

	int nBits;
	int idx;

	while(readHead(head)) {
		while((nBits = readInt(3)) != 0) {
			while((idx = readInt(nBits)) != ((1<<nBits) - 1)) {
				idx= idx + idxMap(nBits);
				printf("%c", head[idx]);
			}
		}
		printf("\n");
	}

}
