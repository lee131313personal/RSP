/**
 

  Question number 43 

  Given two non-negative int     num1,    num2    ====> string type 
  return product of num1 and num2    ===> string type




Test cases : 

1. 
Input : 
num1 = "2"    num2 = "3"     
Output = "6" 

2. 
Input :     num1 = "123456"    num2 = "98"
Output: "12098688"

3. Input : num1 = "123",    num2 = "456"     Ouput : "56088"


4. Input: num1 = "1"    , num2 = "123123123"    Output : "123123123"

5. Input : num1 = "0",     num2 = "2233"      Output: "0"



Constraints : 

num1 length and num2 length <= 10000  ,  digit only,   non-negative 

num1 and num2 does not have anyy leading zero 


Time complexity : 
num1 : n digit 
num2 : n digit
Time complexity :  - - - - - - n - - - - - - 
                   |
                   |
                   |
                   |
                   |
                   |         N square 
                   n         O(n ^ 2) 
                   |
                   |
                   |
                   |
                   

 *
 * /
 *
 *
 *
 
Better Solution : 

 x = x1*Base^m + x0
 y = y1*Base^m + y0

 x * y = x1•y1•Base^2m + (x1•y0 + x0•y1)*Base^m + x0•y0 
 
z0 =  x0*y0
z2 =  x1*y1
z3 = (x1+x0)*(y1+y0)

So, in this way we dont need to calculate " x1•y0 + x0•y1 " 
x1•y0 + x0•y1 = z3 - z2 - z0 

x * y = z2 * B^2m  + (z3 - z2 - z0) * B^m + z0;

This time, Theta ( N^(log 3) ) 


 *
 *
 *
 *
 *
 *
 *
 */

#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::endl;


string basicMutiplication(string num1, string num2){

    /* 
     *   • • • • • •  length 1
     *     • • • • •  length 2
     * */

    int num1_length = num1.size();
    int num2_length = num2.size();
    string result(num1_length + num2_length , '0');

    for (int i=num1_length - 1; i>= 0 ; i--){
        int carry = 0;
        for (int j=num2_length -1; j>=0; j--){
            int temp_result = (num1[i]-'0')*(num2[j]-'0')+carry+ (result[i+j+1] - '0');
            carry = temp_result / 10;
            result[i+j+1] = temp_result % 10 + '0'; 
        }
        result[i] += carry;
        cout << "TEST : " << result[i] << endl;
    }

    int non_zero_index = 0;
    while (result[non_zero_index] == '0' && non_zero_index < result.size())
        non_zero_index ++;
    if (non_zero_index == string::npos)
        non_zero_index = result.size() - 1;
    result.erase(0 , non_zero_index);

    return result;
}


int main(){

    cout << basicMutiplication ("123456" , "0") << endl;
    return 0;

}






