class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n=nums.size();
        int index=0;
        int left=0;
        int right=n-1;

        while(index<=right){
            if(nums[index]==0){
                swap(nums[index],nums[left]);
                left++;
                index++;
            }
            else if(nums[index]==2){
                swap(nums[index],nums[right]);
                right--;
            }
            else{
                index++;
            }
        }
        // int zerocount=0,onecount=0,twocount=0;
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i]==0){
        //         zerocount++;
        //     }
        //     if(nums[i]==1){
        //         onecount++;
        //     }
        //     if(nums[i]==2){
        //         twocount++;
        //     }
        // }

        // for(int i=0; i<nums.size(); i++){
        //     for(int i=0; i<zerocount; i++){
        //        nums[i]=0;
        //     }
        //     for(int j=zerocount; j<zerocount+onecount; j++){
        //         nums[j]=1;
        //     }
        //     for(int k=zerocount+onecount; k<nums.size(); k++){
        //         nums[k]=2;
        //     }
        // }
    }
};