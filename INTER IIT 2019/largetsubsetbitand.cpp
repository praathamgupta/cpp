#include <bits/stdc++.h>
using namespace std;
#define int long long
void largestSubsetbitwiseand(int a[], int N)
{
    // Stores the number of set bits
    // at each bit position
    int bit[32] = { 0 };
 
    // Traverse the given array arr[]
    for (int i = 0; i < N; i++) {
 
        // Current bit position
        int x = 31;
 
        // Loop till array element
        // becomes zero
        while (a[i] > 0) {
 
            // If the last bit is set
            if (a[i] & 1 == 1) {
 
                // Increment frequency
                bit[x]++;
            }
 
            // Divide array element by 2
            a[i] = a[i] >> 1;
 
            // Decrease the bit position
            x--;
        }
    }
 
    // Size of the largest possible subset
    cout << *max_element(bit, bit + 32);
}
