class Solution {
public:
    bool solve(vector<int>& counts, vector<int>& quantity,int ithCustomer){
        if(ithCustomer >= quantity.size()){
            return true;
        }

        for(int i=0; i<counts.size(); i++){
            if(quantity[ithCustomer] <= counts[i]){
                counts[i] -= quantity[ithCustomer];
                bool ans = solve(counts,quantity,ithCustomer+1);
                if(ans){
                    return true;
                }
                counts[i] += quantity[ithCustomer];
            }
        }

        return false;//sari positons try krli maine counts ki, but customer ki requirement puri nhi ho payi
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int>mp;
        for(auto val:nums){
            mp[val]++;
        }

        vector<int>counts;//store the frequency of the repeated elements
        for(auto it:mp){
            counts.push_back(it.second);
        }
        sort(quantity.rbegin(),quantity.rend());//optimize kr diya decreasing order mai sort krke
        int ithCustomer = 0;//oth customer se start kr rhe hai
        return solve(counts,quantity,ithCustomer);
    }
};

/*suppose, mere pas counts ki array hai -> [2,2,1];
and quantity ki array hai -> [2,1,3];
instead of mai phle 0th customer ki 2 requirement puri kru -> jo ki ho jayengi qki mere ps itne same element h
fir mai 1st customer ki requirements puri kru,then 3rd ki 
but 3rd ke pass jake muje pta chlega ki iski requirement fullfil ho nhi skti qki mere pas itne elements hi nhi hai
then muje pta chlega ki yha muje false return krna pdega,qki mere customers ki requirements puri nhi ho pa rhi

thats why mai phle hi quantity wali array ko decreasing order mai sort krdeta hu and jis customer ki highest requirement
hoti hai, use sbse phle track krta hu and jisse muje ye pta chalta ki agr mere is customer ki requirements hi puri nhi ho payi
toh aage check krne ki need nhi hai, qki jo mera aim tha sbhi customers ki need ko pura krna wo fulffil nhi ho paeyag
so mai yhi pr FALSE return krdunga
*/