class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        int k = pow(2, n);
        
        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            
            vector<int> v;
            for(int j = 0;j<n;j++){
                if(i & (1<<j)){
                    v.push_back(nums[j]);
                }
            }
                res.push_back(v);
        }
        return res;
    }
};