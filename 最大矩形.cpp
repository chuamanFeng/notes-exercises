void createHistogram(const vector<vector<char> >& matrix, vector<int>&heights, int row)
    {
        int col = matrix[0].size();//列
        for (int j = 0; j < col; j++)
        {
            heights[j] = matrix[row][j] == '0' ? 0 : (heights[j] + 1);
        }
    }

    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        vector<int>heights(matrix[0].size() + 1);//init
        int maxRow = matrix.size();
        int maxSize = 0;
        //int rowSize = 0;
        //对每一行使用上一题的算法
        for (int row = 0; row < maxRow; row++)
        {
            createHistogram(matrix, heights, row);//生成柱状图
            stack<int>index;
            int i = 0;
            while (i < heights.size())
            {
                if (index.empty() || heights[i] > heights[index.top()])
                {
                    index.push(i);
                    ++i;
                }
                else
                {
                    int j = index.top();
                    index.pop();
                    maxSize = max(maxSize, heights[j] * (index.empty() ? i : (i - index.top() - 1)));
                }
            }
        }
        return maxSize;
    }
