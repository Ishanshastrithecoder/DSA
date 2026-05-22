//PROBLEM STATEMENT STRIVERS DSA
/*
You are given two fractions as strings in the form "a/b" and "c/d" where a, b, c, and d are positive integers and b ≠ 0, d ≠ 0.
Your task is to add the two fractions and return their sum in the simplest form as a string "x/y".
Example 1
Input: frac1 = "3/4", frac2 = "1/7"
Output: "25/28"
Explanation: 3/4 + 1/7 = (3×7 + 1×4)/(4×7) = 25/28
Example 2
Input: frac1 = "5/2", frac2 = "1/2"
Output: "3/1"
Explanation: 5/2 + 1/2 = 6/2 = 3/1
Constraints
The inputs frac1 and frac2 are valid strings in the form "a/b" where 1 ≤ a, b ≤ 104
The final answer must be fully simplified
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    string addFractions(string frac1, string frac2) {
        // Parse first fraction
        int pos1 = frac1.find('/');
        int a = stoi(frac1.substr(0, pos1));
        int b = stoi(frac1.substr(pos1 + 1));

        // Parse second fraction
        int pos2 = frac2.find('/');
        int c = stoi(frac2.substr(0, pos2));
        int d = stoi(frac2.substr(pos2 + 1));

        // Add fractions
        int numerator = a * d + c * b;
        int denominator = b * d;

        // Simplify fraction
        int g = gcd(numerator, denominator);

        numerator /= g;
        denominator /= g;

        return to_string(numerator) + "/" + to_string(denominator);
    }
};

int main()
{
  Solution s;
  string f1,f2;
  cin>>f1>>f2;
  s.addFractions(f1,f2);
  return 0;
}
