class Solution {
   public:
    bool finder(int i, int j, vector<vector<char>>& board, string word, string& s,
                vector<vector<int>>& visited) {
        if (s == word) return true;

        visited[i][j] = 1;

        bool b1 = false, b2 = false, b3 = false, b4 = false;

        if (i + 1 < board.size() && !visited[i + 1][j]) {
            s.push_back(board[i + 1][j]);
            b1 = finder(i + 1, j, board, word, s, visited);
            s.pop_back();
        }

        if (i - 1 >= 0 && !visited[i - 1][j]) {
            s.push_back(board[i - 1][j]);
            b2 = finder(i - 1, j, board, word, s, visited);
            s.pop_back();
        }

        if (j + 1 < board[0].size() && !visited[i][j + 1]) {
            s.push_back(board[i][j + 1]);
            b3 = finder(i, j + 1, board, word, s, visited);
            s.pop_back();
        }

        if (j - 1 >= 0 && !visited[i][j - 1]) {
            s.push_back(board[i][j - 1]);
            b4 = finder(i, j - 1, board, word, s, visited);
            s.pop_back();
        }

        visited[i][j] = 0;

        return b1 || b2 || b3 || b4;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                string s = "";
                s.push_back(board[i][j]);

                if (finder(i, j, board, word, s, visited)) return true;
            }
        }

        return false;
    }
};
