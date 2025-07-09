// Binary Search Example
// This code implements a binary search algorithm to find an element in a sorted array.
// LeetCode Problem: https://leetcode.com/problems/binary-search/
// Time Complexity: O(log n)
// Space Complexity: O(1)

int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents overflow
        if (arr[mid] == target)
            return mid; // Found
        else if (arr[mid] < target)
            low = mid + 1; // Search right half
        else
            high = mid - 1; // Search left half
    }
    return -1; // Not found
}