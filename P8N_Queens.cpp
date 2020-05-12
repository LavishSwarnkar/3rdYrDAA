#include<bits/stdc++.h>
const int N = 4;
void sol_printer(int board[N][N]);
bool check_safety(int board[N][N], int row, int col);
bool helper(int board[N][N], int col);
void solve();

int main() {
    solve();
    return 0;
}

void sol_printer(int board[N][N]) {
    static int k = 1;
    printf("%d : \n",k++);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool check_safety(int board[N][N], int row, int col) {
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;
    return true;
}

bool helper(int board[N][N], int col) {
    if (col == N) {
        sol_printer(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if ( check_safety(board, i, col) ){
            board[i][col] = 1;
            res = helper(board, col + 1) || res;
            board[i][col] = 0;
        }
    }

    return res;
}

void solve() {
    int board[N][N];
    memset(board, 0, sizeof(board));
    if (!helper(board, 0)) {
        printf("Solution does not exist");
        return ;
    }
}