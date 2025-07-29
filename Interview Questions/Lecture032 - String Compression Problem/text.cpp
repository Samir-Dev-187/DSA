#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::to_string

using namespace std;

int compress(vector<char> &chars)
{
    int n = chars.size();
    if (n == 0) {
        return 0;
    }

    int idx = 0; // This pointer writes the compressed characters

    for (int i = 0; i < n; ) // 'i' is the read pointer
    {
        char currentChar = chars[i];
        int count = 0;

        // Count occurrences of the current character
        while (i < n && chars[i] == currentChar)
        {
            count++;
            i++;
        }

        // Write the character
        chars[idx++] = currentChar;

        // If count is greater than 1, append the count as digits
        if (count > 1)
        {
            string countStr = to_string(count);
            for (char digit : countStr)
            {
                chars[idx++] = digit;
            }
        }
        // No need for 'i--' or explicit 'i++' in outer loop, as 'i' is advanced by the inner while loop.
    }

    // Resize the vector to the new compressed size
    chars.resize(idx);
    return idx; // Return the new length
}

int main()
{
    // C-style array ko vector mein convert kiya
    char c_chars_arr[] = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    vector<char> chars_vec(c_chars_arr, c_chars_arr + sizeof(c_chars_arr) / sizeof(c_chars_arr[0]));

    cout << "Original vector: ";
    for (char ch : chars_vec) {
        cout << ch << " ";
    }
    cout << endl;

    int newLength = compress(chars_vec);

    cout << "New length of compressed vector: " << newLength << endl;

    cout << "Compressed vector: ";
    for (char ch : chars_vec) {
        cout << ch << " ";
    }
    cout << endl;

    // Aap additional test cases bhi add kar sakte hain logic ko fully check karne ke liye:
    // vector<char> test1 = {'a'};
    // compress(test1); // Should be 'a'
    // vector<char> test2 = {'a', 'b', 'c'};
    // compress(test2); // Should be 'a', 'b', 'c'

    return 0;
}