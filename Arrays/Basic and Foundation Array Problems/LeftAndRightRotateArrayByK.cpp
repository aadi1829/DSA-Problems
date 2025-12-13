//left Rotate by k
class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        vector<int>temp;
        for(int i=0; i<k; i++){
            temp.push_back(nums[i]);
        }

        for(int i=k; i<nums.size(); i++){
            num[i-k] = nums[i];
        }

        int index = 0;
        while(k--){
            nums.push_back(temp[index]);
            index++;
        }
    }
};

    vector<int> rotateArray(vector<int>& nums, int k, string direction) {
        int n = nums.size();

        // Edge case: empty or no rotation
        if (n == 0 || k == 0) return nums;

        // Normalize k
        k = k % n;

        if (direction == "right") {
            // Step 1: Reverse the whole array
            reverseArray(nums, 0, n - 1);

            // Step 2: Reverse first k elements
            reverseArray(nums, 0, k - 1);

            // Step 3: Reverse remaining n-k elements
            reverseArray(nums, k, n - 1);
        } 
        else if (direction == "left") {
            // Step 1: Reverse first k elements
            reverseArray(nums, 0, k - 1);

            // Step 2: Reverse remaining n-k elements
            reverseArray(nums, k, n - 1);

            // Step 3: Reverse the whole array
            reverseArray(nums, 0, n - 1);
        }

        return nums;
    }
};