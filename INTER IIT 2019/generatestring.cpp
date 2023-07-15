#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;
    int sum;
    cin >> sum;

    char arr[size];

    // Fill the array with 'a'
    for (int i = 0; i < size; i++)
    {
        arr[i] = 'a';
        sum--;
    }

    int i = size - 1;

    while (sum > 0)
    {
        // If the remaining sum is less than or equal to 25, add it to the current character
        if (sum <= 'z' - 'a')
        {
            arr[i] += sum;
            sum = 0;
        }
        else
        {
            // Otherwise, set the current character to 'z' and reduce the sum by 25
            arr[i] = 'z';
            sum -= ('z' - 'a');
        }
        i--;

        // If we have reached the beginning of the array, break the loop
        if (i < 0)
            break;
    }

    // Print the resulting string
    for (int i = 0; i < size; i++)
        cout << arr[i];
        
    cout << endl;

    return 0;
}
