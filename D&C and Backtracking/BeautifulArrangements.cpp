class Solution {
public:
    void solve(vector<int>&arr,int&n,int&cnt,int currNum){
        //base case
        if(currNum == n+1){//age currNum yha tk phuch gya it means ek beautiful arrangement prepare ho gyi
            cnt++;
            return;
        }

        //ab mai currNum ko hr ek position pr rkhne ka try krunga from 1 to n;
        for(int i=1; i<=n; i++){//i represent the postion in the array, jha mai number ko put krke baki aage ka answer find krne ka try kr rha hu
            if(arr[i] == 0){//agr is position pr koi bhi element abhi present nhi hai
                if(currNum % i == 0 || i % currNum == 0){
                    arr[i] = currNum;
                    solve(arr,n,cnt,currNum+1);
                    arr[i] = 0; //agr recursive call krke , aage ka solution nhi milta hai, toh backtrack
                }
            }
        }
    }
    int countArrangement(int n) {
        vector<int>arr(n+1); //muje is Quesiton mai 1-based indexing use krni hai, thats why
        int cnt = 0;//used to count the number of beautiful arrangements
        int currNum = 1; //mai is number se apni positions fill krna start krunga
        solve(arr,n,cnt,currNum);
        return cnt;
    }
};