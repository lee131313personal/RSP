#include<iostream>
#include<string>
#include<cmath>

using namespace std;
using std::string;

class Solution {
public:
    int readPositive(string& s) {
        int result = 0;
        int valid_length = 0;
        for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
            if (*it == '-') {
                s.erase(0, 1);
            }
            else break;

            if (!std::isdigit(*it)) break;
            else valid_length++;
            std::cout << "valid_length:" << valid_length << endl;
        }        
        cout << "In Read Positive func, before removing: " << s << endl;
        s = s.substr(0, valid_length);
        
        // remove leading zero 
        while (s[0] == '0') s = s.erase(0, 1);
        cout << "In Read Positive func: " << s << endl;

        int multiplier = valid_length - 1;
        for (char c : s) {
            int digit = c - '0';
            result += digit * pow(10, multiplier);
            multiplier --;
        }
        return result;
    }


    int myAtoi(string s) {
        int result = 0; 
        if (s[0] == '-') return (-1) * readPositive(s);
        else return readPositive(s);
        
    }
};


int main(int argc, char* argv[]){
    Solution my_solution; 
    string test_string1 = "-042";
    std::cout << my_solution.myAtoi(test_string1) << endl;
    return 0;
}