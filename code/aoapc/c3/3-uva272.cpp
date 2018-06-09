#include <stdio.h>

int main() {
	int c, lflag = 1;
	while((c = getchar()) != EOF) {
		if(c == '"') {printf("%s", lflag ? "``" : "''"); lflag = !lflag;}
		else printf("%c", c);
	}
	return 0;
}
