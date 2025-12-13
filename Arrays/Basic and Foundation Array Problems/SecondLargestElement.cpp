//Second Largest and Second Smallest Element
//1.Brute
// Sort the array in ascending order.
// The element at the second index (index 1) is the second smallest element.
// The element at the second index from the end (index length-2) is the second largest element.
void getElements(int arr[], int n)
{
    // Edge case when the array has less than 2 elements
    if(n == 0 || n == 1)
        cout << -1 << " " << -1 << endl;  // Print -1 for both second smallest and second largest if the array has less than 2 elements
    // Sort the array to easily find the second smallest and second largest elements
    sort(arr, arr + n);
    // Second smallest element is at index 1 after sorting
    int small = arr[1]; 
    // Second largest element is at index n-2 after sorting
    int large = arr[n - 2]; 
    // Output the second smallest and second largest elements
    cout << "Second smallest is " << small << endl;
    cout << "Second largest is " << large << endl;
}


//Better:
// Perform a single traversal to find the smallest and largest elements in the array.
// After that, traverse the array again to find the element just greater than the smallest element (this will be the second smallest).
// Similarly, find the element just smaller than the largest element (this will be the second largest).
void getElements(int arr[], int n)
{
    // Edge case: when the array has less than 2 elements
    if (n == 0 || n == 1)
        cout << -1 << " " << -1 << endl;  // If only one element, print -1 for both second smallest and second largest

    // Initialize variables to track the smallest, second smallest, largest, and second largest elements
    int small = INT_MAX, second_small = INT_MAX;
    int large = INT_MIN, second_large = INT_MIN;
    int i;

    // Find the smallest and largest elements in the array
    for (i = 0; i < n; i++) {
        small = min(small, arr[i]);  // Update the smallest element
        large = max(large, arr[i]);  // Update the largest element
    }

    // Find the second smallest and second largest elements
    for (i = 0; i < n; i++) {
        // If the current element is smaller than second_small and not equal to the smallest, update second_small
        if (arr[i] < second_small && arr[i] != small)
            second_small = arr[i];
        
        // If the current element is larger than second_large and not equal to the largest, update second_large
        if (arr[i] > second_large && arr[i] != large)
            second_large = arr[i];
    }

    // Output the second smallest and second largest elements
    cout << "Second smallest is " << second_small << endl;
    cout << "Second largest is " << second_large << endl;
}

//optimal:

class Solution {
public:
    vector<int> secondLargestAndSmallestElement(vector<int>& nums) {
        //your code goes here
        int small = INT_MAX;
        int second_small = INT_MAX;
        int largest = INT_MIN;
        int second_largest = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] > largest){
                largest = nums[i];
                second_largest = nums[i];
            }else if(nums[i] > second_largest && nums[i] != largest){
                second_largest = nums[i];
            }

            if(nums[i] < small){
                small = nums[i];
                second_small = nums[i];
            }
            else if(nums[i] < second_small && nums[i] != small){
                second_small = nums[i];
            }
        }

        return {second_largest,second_small};
    }
};