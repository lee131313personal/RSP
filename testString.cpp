#include<string>
#include<iostream>
#include <algorithm> // For std::reverse
using std::string;
using std::cout;
using std::endl;

int main() {

    string long_string1 = "Hello this is only a    test";
    string long_string2 = "   What happen if there are space ahead?";

    // Reverse long_string1
    string reversed_string1 = long_string1;
    std::reverse(reversed_string1.begin(), reversed_string1.end());

    // Reverse long_string2
    string reversed_string2 = long_string2;
    std::reverse(reversed_string2.begin(), reversed_string2.end());

     // Output reversed strings
    cout << "Reversed string1: " << reversed_string1 << endl;
    cout << "Reversed string2: " << reversed_string2 << endl;



    for (string::iterator it = long_string1.begin();it != long_strin1.end(); ++it) {
        if (*it = ' ') (
    }

    return 0;


}


