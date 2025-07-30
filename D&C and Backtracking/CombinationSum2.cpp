class Solution {
public:
    void solve(vector<int>&nums,int target,vector<int>&output,vector<vector<int>>&ans,int sum,int index){
        if(sum == target){
            ans.push_back(output);
            return;
        }
        if(sum > target) return;

        for(int i=index; i<nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]){
                continue;
            }
            output.push_back(nums[i]);
            solve(nums,target,output,ans,sum+nums[i],i+1); //maine yha glti ki thi, i ki jgh index ko hi pass kr rha tha
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>output;
        int sum = 0;
        int index = 0;
        solve(nums,target,output,ans,sum,index);
        return ans;
    }
};