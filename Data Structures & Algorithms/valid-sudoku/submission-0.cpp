class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {

            unordered_set<char> s;

            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.') continue;

                if(s.find(board[i][j]) != s.end()) {
                    return false;
                }

                s.insert(board[i][j]);
            }
        }

        for(int i = 0; i < 9; i++) {

            unordered_set<char> s;

            for(int j = 0; j < 9; j++) {

                if(board[j][i] == '.') continue;

                if(s.find(board[j][i]) != s.end()) {
                    return false;
                }

                s.insert(board[j][i]);
            }
        }

        for(int row = 0; row < 9; row += 3) {

            for(int col = 0; col < 9; col += 3) {

                unordered_set<char> s;

                for(int i = 0; i < 3; i++) {

                    for(int j = 0; j < 3; j++) {

                        char ch = board[row + i][col + j];

                        if(ch == '.') continue;

                        if(s.find(ch) != s.end()) {
                            return false;
                        }

                        s.insert(ch);
                    }
                }
            }
        }

        return true;
    }
};