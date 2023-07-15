#include <bits/stdc++.h>
using namespace std;

// Function to find all the unique characters in a subsequence of length k
string uniqueSubsequence(string s, int n, int k)
{
    stack<char> st;
    vector<int> visited(26, 0), cnt(26, 0);

    // Find the number of occurrences of
    // the character s[i]
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < n; i++)
    {

        // Decrease the character count
        // in remaining string
        cnt[s[i] - 'a']--;

        // If character is already present
        // in the stack
        if (visited[s[i] - 'a'])
        {
            continue;
        }

        // If the stack size is already k,
        // then we need to pop the top element
        if (st.size() == k)
        {
            visited[st.top() - 'a'] = 0;
            st.pop();
        }

        // Push the current character
        st.push(s[i]);
        visited[s[i] - 'a'] = 1;
    }

    // Stores the resultant string
    string s1;

    // Generate the string
    while (!st.empty())
    {
        s1 = st.top() + s1;
        st.pop();
    }

    // Return the resultant string
    return s1;
}

// Driver Code
int main()
{
    string S = "ababc";
    int N = S.length();
    int k = 3;
    cout << uniqueSubsequence(S, N, k);

    return 0;
}