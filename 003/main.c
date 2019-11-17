#include <stdio.h>

char board[600][600] = {0};
int m, n, k;
int DIR[4][4] = {{-1, -1},
                 {-1, 1},
                 {1,  -1},
                 {1,  1}};
void bfs(int i, int j, int k);
int main() {


    scanf("%d %d %d", &m, &n, &k);
    m,n,k;
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%c", board[i][j]);
            if (board[i][j] == '.') {
                board[i][j] = 'X';
            }
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            bfs(i,j,k);
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%c",board[i][j]);
        }
    }
}

void bfs(int i, int j, int k) {
    if (k == 0 || i >= m || j >= n || board[i][j] != 'X') {
        return;
    }
    if (board[i][j] == 'X') {
        board[i][j] = '.';
    }
    int x;
    for (int x = 0; x < 4; x++) {
        i = i + DIR[x][0];
        j = j + DIR[x][1];
        bfs(i,j,k--);
    }

}