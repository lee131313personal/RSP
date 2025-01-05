#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length() > 10000) return 0;
        int length = 0;
        int i = s.length() - 1;
        while (s[i] == ' ' && i>=0) { i--; }
        while (s[i] != ' ' && i>=0) {
            i--;
            length++;
            // std::cout << "i = " << i << " , length = " << length << endl; 
        }
        return length;
    }
};


int main(){
    Solution my_solution;
    std::cout << "Result : " << my_solution.lengthOfLastWord("a ") << endl;
    return 0;
}