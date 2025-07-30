class Solution {
public:
    //using recursion
    int helper(vector<int>&nums,int start,int mid,int end){
        int leftSum = 0 , maxLeftSum = INT_MIN;
        int rightSum = 0, maxRightSum = INT_MIN;

        for(int i=mid; i>=start; i--){
            leftSum += nums[i];
            maxLeftSum = max(maxLeftSum , leftSum);
        }

        for(int i=mid+1; i<=end; i++){
            rightSum += nums[i];
            maxRightSum = max(maxRightSum, rightSum);
        }

        return (maxRightSum + maxLeftSum);
    }

    int solve(vector<int>&nums,int start,int end){
        //single element case
        if(start == end) return nums[start];
        //find the mid and divide
        int mid = start + (end - start)/2;

        int leftMax = solve(nums,start,mid);
        int rightMax = solve(nums,mid+1,end);
        int crossBorderSum = helper(nums,start,mid,end);
        return max(leftMax,max(rightMax,crossBorderSum));
    }
    int maxSubArray(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int ans = solve(nums,start,end);
        return ans;
    }
};