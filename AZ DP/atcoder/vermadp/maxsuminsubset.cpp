#include <bits/stdc++.h>
using namespace std;
 
// Function to return the maximum
// difference between the subset sums
int maxDiffSubsets(int arr[], int N)
{
    // Stores the total
    // sum of the array
    int totalSum = 0;
 
    // Checks for positive
    // and negative elements
    bool pos = false, neg = false;
 
    // Stores the minimum element
    // from the given array
    int min = INT_MAX;
 
    // Traverse the array
    for (int i = 0; i < N; i++)
    {
        // Calculate total sum
        totalSum += abs(arr[i]);
 
        // Mark positive element
        // present in the set
        if (arr[i] > 0)
            pos = true;
 
        // Mark negative element
        // present in the set
        if (arr[i] < 0)
            neg = true;
 
        // Find the minimum
        // element of the set
        if (arr[i] < min)
            min = arr[i];
    }
 
    // If the array contains both
    // positive and negative elements
    if (pos && neg)
        return totalSum;
 
    // Otherwise
    else
        return totalSum - 2 * min;
}
 
// Driver Code
int main()
{
    // Given the array
    int S[] = {1, 2, 1};
 
    // Length of the array
    int N = sizeof(S) / sizeof(S[0]);
 
    if (N < 2)
        cout << ("Not Possible");
 
    else
        // Function Call
        cout << (maxDiffSubsets(S, N));
}
 