#include <stdio.h>

char grid[5][5] = {
    {'L','L','W','W','W'},
    {'L','L','W','W','L'},
    {'L','W','W','L','L'},
    {'W','W','W','W','W'},
    {'L','W','L','L','W'}
};

void dfs(int r, int c) {
    if (r < 0 || r >= 5 || c < 0 || c >= 5 ||
        grid[r][c] == 'W')
        return;

    grid[r][c] = 'W';

    dfs(r + 1, c);
    dfs(r - 1, c);
    dfs(r, c + 1);
    dfs(r, c - 1);
}

int main() {
    int i, j, count = 0;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (grid[i][j] == 'L') {
                count++;
                dfs(i, j);
            }
        }
    }

    printf("Number of islands = %d\n", count);
    return 0;
}