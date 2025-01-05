#include<math.h>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
         long int result = 0;
        // if out of range, return 0
        if (x >= pow(2,31)-1 || x <= -pow(2,31)) return result;
        // if negative number:
        if (x<0){
            // we work on the abs of x
            int positive_x = -x;
            int copy_x = -x;
            int length = 1;
            while (positive_x/10 >= 1){
                positive_x /= 10;
                length++;
            }
            for (int i=0; i<=length; i++){
                int digit = copy_x % 10;
                result += digit * pow(10, length-i-1);
                copy_x /= 10;
            }
            result = -result;
        }
        else {
            int copy_x = x;
            int length = 1;
            while (x/10 >= 1){
                x /= 10;
                length++;
            }
            for (int i=0; i<=length; i++){
                long int digit = copy_x % 10;
                result += digit * pow(10, length-i-1);
                copy_x /= 10;
            }
        }

        if (result > pow(2,31)-1 || result < -pow(2,31)) result = 0;
        return result;
    }
};
