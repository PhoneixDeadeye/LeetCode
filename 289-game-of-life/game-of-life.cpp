class Solution {
public:
    int countLive(int i, int j, vector<vector<int>>& board){
        int live = 0;
        int n = board.size();
        int m = board[0].size();
        vector<int> dirs = {-1, 0, 1};

        for(int x : dirs){
            for(int y : dirs){
                if(x==0 && y==0) continue;
                int ni = i+x;
                int ny = j+y;
                if(ni>=0 && ni<n && ny>=0 && ny<m){
                    if(board[ni][ny]==1 || board[ni][ny]==2){
                        live++;
                    }
                }
            }
        }
        return live;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int live = countLive(i, j, board);
                if(board[i][j]== 1 && (live<2 || live>3)) board[i][j] = 2;
                if(board[i][j]== 0 && live==3) board[i][j] = -1;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==2) board[i][j]=0;
                if(board[i][j]==-1) board[i][j]=1;
            }
        }
    }
};