class Solution {
public:
    vector<char> curr;
    bool dfs(vector<vector<char>>& board,int i, int j, string word){
       if(!word.size())
           return true;
       if(i< 0 || j < 0 || i >= board.size() || j >=board[0].size() || board[i][j]!=word[0])
           return false;
        
        char c = board[i][j];
        board[i][j] = '*';
        
        string s = word.substr(1);
        bool res = dfs(board, i+1, j, s) || dfs(board, i-1, j, s) || dfs(board, i, j+1, s) ||  dfs(board, i, j-1, s);
        
        board[i][j] = c;
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                    if(dfs(board, i, j, word))
                        return true;   
        
        return false;
        }
};