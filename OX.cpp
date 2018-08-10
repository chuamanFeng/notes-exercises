class Solution {
public:
    int dir[4][2]={1,0,0,1,-1,0,0,-1};
    void solve(vector<vector<char>>& board) {
        
        if(board.empty())
            return;
        int r=board.size();
        int c=board[0].size();     
        if(c==0)
            return;
        vector<vector<int>> co(r,vector<int>(c,0));
        queue<pair<int,int>> vis;
        for(int i=0;i<r;i++)
        {
            if(board[i][0]=='O')  vis.push(make_pair(i,0));
            if(board[i][c-1]=='O') vis.push(make_pair(i,c-1));            
        }
        for(int i=0;i<c;i++)
        {
            if(board[0][i]=='O')vis.push(make_pair(0,i));
            if(board[r-1][i]=='O')vis.push(make_pair(r-1,i));
        }
        while(!vis.empty())
        {
              int cx=vis.front().first;
              int cy=vis.front().second;
              vis.pop();
              co[cx][cy]=1;
              for(int i=0;i<4;i++)
              {
                  int nx=cx+dir[i][0];
                  int ny=cy+dir[i][1];
                  if(nx<0||ny<0||nx>=r||ny>=c||co[nx][ny]||board[nx][ny]=='X')
                      continue;
                  vis.push(make_pair(nx,ny));
              }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='O'&&co[i][j]==0)
                    board[i][j]='X';
            }
        }
    }
};
