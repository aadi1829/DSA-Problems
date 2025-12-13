class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        // BRUTE FORCE APPRAOCH
        // set<vector<int>> st;
        // for(int i=0; i<nums.size(); i++){
        //     for(int j=i+1; j<nums.size();j++){
        //         for(int k=j+1; k<nums.size(); k++){
        //             for(int l=k+1; l<nums.size(); l++){
        //                 long long sum=nums[i]+nums[j];
        //                 sum+=nums[k];
        //                 sum+=nums[l];
        //                 if(sum==target){
        //                     vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
        //                     sort(temp.begin(),temp.end());
        //                     st.insert(temp);
        //                 }
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin(),st.end());
        // return ans;


        //better solution:using hashing
        int n = nums.size();
        set<vector<int>>st;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int target = target - nums[i] - nums[j];
                set<int>hash;
                for(int k=j+1; k<n; k++){
                    int rem = target - nums[k];
                    if(hash.find(rem) != hash.end()){
                        vector<int>temp = {nums[i],nums[j],nums[k],rem};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    else{
                        hash.insert(nums[k]);
                    }
                }
            }
        }
        


        //optimal solution:using two pointer
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                if( j!= (i+1) && nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;
                
                while(k<l){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};