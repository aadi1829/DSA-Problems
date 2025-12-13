// Check if Array Is Sorted and Rotated -- Leetcode
class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i])
            count++;
        }
        if(nums[n-1]>nums[0])
        count++;
        return count<=1;
    }
};

bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])  // If any element is smaller than the previous one, return false
            return false;
    }

    return true;  // Return true if the array is sorted
}