class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board) {
        if (board[i][j] != 'O') {
            return;
        }

        board[i][j] = '1';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int newRow = i + dr[k];
            int newCol = j + dc[k];

            if (newRow >= 0 && newRow < board.size() &&
                newCol >= 0 && newCol < board[0].size() &&
                board[newRow][newCol] == 'O') {
                dfs(newRow, newCol, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        int i = 0;
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'O') {
                dfs(i, j, board);
            }
        }

        int k = n - 1;
        for (int j = 0; j < m; j++) {
            if (board[k][j] == 'O') {
                dfs(k, j, board);
            }
        }

        int p = 0;
        for (int t = 0; t < n; t++) {
            if (board[t][p] == 'O') {
                dfs(t, p, board);
            }
        }

        int z = m - 1;
        for (int t = 0; t < n; t++) {
            if (board[t][z] == 'O') {
                dfs(t, z, board);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
