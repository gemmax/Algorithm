#define LOCAL

#include <stdio.h>

bool operation(char grid[][5], int *xidx, int *yidx, char cmd) {
	if(cmd == 'A' && (*xidx) != 0) {
		grid[(*xidx)][(*yidx)] = grid[(*xidx) - 1][(*yidx)];
		(*xidx) -= 1;
	} else if(cmd == 'B' && (*xidx) != 4) {
		grid[(*xidx)][(*yidx)] = grid[(*xidx) + 1][(*yidx)];
		(*xidx) += 1;
	} else if(cmd == 'L' && (*yidx) != 0) {
		grid[(*xidx)][(*yidx)] = grid[(*xidx)][(*yidx) - 1];
		(*yidx) -= 1; 
	} else if(cmd == 'R' && (*yidx) != 4) {
		grid[(*xidx)][(*yidx)] = grid[(*xidx)][(*yidx) + 1];
		(*yidx) += 1;
	} else {
		return false;
	}
	grid[(*xidx)][(*yidx)] = ' '; 
	return true;
}

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	char grid[5][5];
	char cmd;
	bool isValid, first = true;
	int count = 0;
	int xidx, yidx;

	while(true) {
		xidx = 0, yidx = 0;
		grid[0][0] = getchar();
		if(grid[0][0] == 'Z') break;
		count++;
		// init puzzle
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				if(i == 0 && j == 0) continue;
				grid[i][j] = getchar();
				if(grid[i][j] == ' ') {
					xidx = i;
					yidx = j;
				}
			}
			getchar();
		}
		
		//print
		/* printf("\nprint:\n");
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++)
				printf("%c ", grid[i][j]);

			printf("\n");
		}
		printf("\n");
		*/

		// init cmd
		isValid = true;
		while(true) {
			cmd = getchar();
			if(cmd == '0') {getchar(); break;}
			if(isValid && (cmd == 'A' || cmd == 'B' || cmd == 'L' || cmd == 'R'))
				isValid = operation(grid, &xidx, &yidx, cmd);
			else if(cmd != '\n') isValid = false;
		}
		
		if(first) first = false;
		else printf("\n");

		printf("Puzzle #%d:\n", count);
		if(isValid)
			for(int i = 0; i < 5; i++) {
				for(int j = 0; j < 4; j++)
					printf("%c ", grid[i][j]);
				printf("%c\n", grid[i][4]);
			}
		else
			printf("This puzzle has no final configuration.\n");
	}
}
