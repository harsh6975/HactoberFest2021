/* By Harsh Sinha

Question : Given a string we need to find all permutaions

Intuition : We will take each character and swap it with all other characters.

Eg                                            ABC
     
                      swap(A,A) /           |swap(A,B)            \ swap(A,c)
                      ABC                 BAC                    CAB 
                                  
        swap(B,B) /     \swap(B,C)   /swap(A,A) \swap(A,c)    /swap(B,B)  \ swap(B,A)
              ABC       ACB         BAC         BCA         CBA            CAB
*/            






#include <iostream>
using namespace std;
 
// Function to find all permutations of a given string `str[i…n-1]`
// containing all distinct characters
void permutations(string str, int i, int n)
{
    // base condition
    if (i == n - 1)
    {
        cout << str << endl;
        return;
    }
 
    // process each character of the remaining string
    for (int j = i; j < n; j++)
    {
        // swap character at index `i` with the current character
        swap(str[i], str[j]);        // STL `swap()` used
 
        // recur for substring `str[i+1, n-1]`
        permutations(str, i + 1, n);
 
        // backtrack (restore the string to its original state)
        swap(str[i], str[j]);
    }
}
 
int main()
{
    string str = "ABC";
 
    permutations(str, 0, str.length());
 
    return 0;
}
