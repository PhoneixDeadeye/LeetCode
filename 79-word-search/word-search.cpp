class Solution {
public:
    int rows;
    int cols;
    vector<vector<bool>> visited;

    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int i){
        if(i==word.size())return true;

        if(row<0 || col<0 || row>=rows || col>=cols || board[row][col]!=word[i] || visited[row][col]) return false;

        visited[row][col]=true;
        bool res = dfs(board, word, row+1, col, i+1) || dfs(board, word, row-1, col, i+1) || dfs(board, word, row, col+1, i+1) || dfs(board, word, row, col-1, i+1);

        visited[row][col]=false;
        return res; 
    }
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};