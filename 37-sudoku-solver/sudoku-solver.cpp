class Solution {
public:

    bool isSafe(vector<vector<char>> &board,int row,int col,char dig){
        for(int j=0;j<9;j++){
            if(board[row][j]==dig){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(board[i][col]==dig){
                return false;
            }
        }
        int sr=(row/3)*3;
        int sc=(col/3)*3;
        for(int r=sr;r<=sr+2;r++){
            for(int c=sc;c<=sc+2;c++){
                if(board[r][c]==dig){
                    return false;
                }
            }

        }
        return true;
    }

    bool helper(vector<vector<char>> &board, int row,int col){
        if(row==9){
            return true;
        }
        int nextr = row;
        int nextc = col+1;
        if(nextc==9){
            nextr=row+1;
            nextc=0;
        }
        if(board[row][col]!='.'){
            return helper(board,nextr,nextc);
        }
        for(char dig='1';dig<='9';dig++){
            if(isSafe(board,row,col,dig)){
                board[row][col]=dig;
                if(helper(board,nextr,nextc)){
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;

    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};