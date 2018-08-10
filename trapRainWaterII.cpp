struct node
{
    int x,y;
    int h;
    node(int _x,int _y,int _h):x(_x),y(_y),h(_h){}
    bool operator <(const node& n)const
    {
        return h>n.h;
    }
};
class Solution {
public: 
    int dir[4][2]={1,0,0,1,-1,0,0,-1};
    int trapRainWater(vector<vector<int>>& heightMap) {
        
        int r=heightMap.size();
        if(r==0)return 0;
        int c=heightMap[0].size();
        if(c==0)return 0;
        int cnt=0;
        priority_queue<node,vector<node>> co;
        vector<vector<int>> vist(r,vector<int>(c,0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==0||j==0||i==r-1||j==c-1)   
                {
                     co.push(node(i,j,heightMap[i][j]));      
                    vist[i][j]=1; 
                }
            }
        }
        int curh=0;
        while(!co.empty())
        {
            node cur=co.top();
            co.pop();
            curh=max(curh,cur.h);          
            for(int i=0;i<4;i++)
            {
                int nx=cur.x+dir[i][0];
                int ny=cur.y+dir[i][1];
                if(nx<0||ny<0||nx>=r||ny>=c||vist[nx][ny])
                    continue;
                cnt+=max(0,curh-heightMap[nx][ny]);
                co.push(node(nx,ny,heightMap[nx][ny]));
                vist[nx][ny]=1; 
            }
        }
        return cnt;
    }
};
