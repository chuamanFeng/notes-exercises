class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        nums.push_back(0);
        int n=nums.size();        
     
        for(int i=0;i<n;i++)
        {
             if(nums[i]<0||nums[i]>=n)             //get rid of those useless
                 nums[i]=0;
        }
        for(int i=0;i<n;i++)
        {
                 nums[nums[i]%n]+=n;               //count frequency whith step "n",keep the idx message of each element;
        }
        for(int i=1;i<n;i++)
        {
            if(nums[i]/n==0)
                return i;
        }
        return n;
    }
};
/*
     Basic idea:
    1. for any array whose length is l, the first missing positive must be in range [1,...,l+1], 
        so we only have to care about those elements in this range and remove the rest.
    2. we can use the array index as the hash to restore the frequency of each number within 
         the range [1,...,l+1] 
*/

