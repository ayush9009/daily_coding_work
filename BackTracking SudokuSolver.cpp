class Solution {
public:

//bahatreen question on recusion and backtracking
    bool isValid(int row,int col,vector<vector<char>>& board,char c){
        for(int i=0;i<9;i++){  //maxrow=9,maxcol=9
        if(board[i][col]==c)return false;  //kisi row ko traverse karte samay column change hove
        // na ki row ,row to vo hi rahegi bas agey peeche karne se col badl ja
        
        if(board[row][i]==c)return false;//kisi col ko traverse karte samay row change hove
        // na ki column ,column to vo hi rahegi bas agey peeche karne se col badl ja

        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)return false;  //box mai number fill karne kai liye
        }
        return true;
    }
    bool SudokuSolve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                for(char t='1';t<='9';t++){
                    if(isValid(i,j,board,t)){
// ek box fill hogya ,lakin ho sake usi row mai aur koi empty box ,to use bhi fill karna hoga,toho sake 
// jo phale box mai number fill kar vo dusre box mai fill hona ho isliye dubare sudokuSolve(board) check
// hoga,aur 1-9 koi bhi values ho sake,conditions:agr 1 fill kiya to is row mai koi 1 ni hona chaiye
// aur is column mai koi 1 ni hona chiaye ,aur jis block mai ye hai ,usme 1 koi aur na ho
//agr pahle block ka element kai liye false return huha to usme fir . dal do
                    board[i][j]=t;

                    if(SudokuSolve(board))return true;
                    else board[i][j]='.';  //backtracking
                    }
                }
                return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        SudokuSolve(board);
    }
};
