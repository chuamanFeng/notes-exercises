class Solution {
public:
    int dir[8][2]={1,2,1,-2,-2,1,2,1,-1,2,-1,-2,-2,-1,2,-1};
    double knightProbability(int N, int K, int r, int c) {
        
        vector<vector<double>> co(N,vector<double>(N,1));
        for(int i=0;i<K;i++)
        {
             vector<vector<double>> tp(N,vector<double>(N,0));
            for(int p=0;p<N;p++)
            {
                for(int q=0;q<N;q++)
                {
                    for(int j=0;j<8;j++)
                    {
                        int nx=p+dir[j][0];int ny=q+dir[j][1];
                        if(nx<0||ny<0||ny>=N||nx>=N)
                            continue;
                        tp[q][p]+=co[nx][ny];
                    }//j
                }//q
            }//p
            co=tp;
        }//i
        return co[r][c]/pow(8,K);
    }
};
