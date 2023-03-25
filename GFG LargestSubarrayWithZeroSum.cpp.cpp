int maxLen(int arr[], int N)
{
    // Map to store the previous sums
    unordered_map<int, int> presum;
 
    int sum = 0; // Initialize the sum of elements
    int max_len = 0; // Initialize result
 
    // Traverse through the given array
    for (int i = 0; i < N; i++) {
 
        // Add current element to sum
        sum += arr[i];
        if (sum == 0)
            max_len = i + 1;
 
        // Look for this sum in Hash table
        if (presum.find(sum) != presum.end()) {
 
            // If this sum is seen before, then update
            // max_len
            max_len = max(max_len, i - presum[sum]);
        }
        else {
            // Else insert this sum with index
            // in hash table
            presum[sum] = i;
        }
    }
 
    return max_len;
}
