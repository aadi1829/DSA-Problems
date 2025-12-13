void reverseArray_Manual(std::vector<int>& arr) {
    // Initialize a left pointer at the start (index 0)
    int left = 0;
    
    // Initialize a right pointer at the end (last index)
    int right = arr.size() - 1;

    // Continue swapping as long as the left pointer is before the right pointer
    while (left < right) {
        // Swap the elements at the left and right pointers
        // Note: std::swap(a, b) can also be used
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        //or

        swap(arr[left],arr[right]);
        
        // Move the pointers inwards
        left++;
        right--;
    }
}