long merge(vector<int>&arr,int start,int end,int mid,vector<int>&temp){
    int k = start;
    int i=start,j=mid+1;
    long c = 0;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }else{ // arr[i] > arr[j]
            temp[k] = arr[j];
            k++;
            j++;
            c += (mid - i + 1);
        }   
    }
    
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    
    while(j <= end){
        temp[k++] = arr[j++];
    }
    
    while(start <= end){
        arr[start] = temp[start];
        start++;
    }
    return c;
 }
 
 long mergeSort(vector<int>&arr,int start,int end,vector<int>&temp){
    if(start >= end) return 0;
    int mid = start + (end - start)/2;
    
    long c = 0;
    c += mergeSort(arr,start,mid,temp);
    c += mergeSort(arr,mid+1,end,temp);
    c += merge(arr,start,end,mid,temp);
    
    return c;
 }

long countInversions(vector<int> arr) {
    long c = 0;
    int start = 0;
    int end = arr.size()-1;
    vector<int>temp(arr.size());
    c = mergeSort(arr,start,end,temp);
    return c;
}