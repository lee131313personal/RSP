/*
 *

Questino: 
Given an array, we want to find all the triplets such that nums[i] + nums[j] + nums[k] = 0, and these three numbers are not the same in pairs. 

Test cases: 

input: [-1, 0, 1, 2, 0, -1, 4]  Output: Output: [[-1,-1,2],[-1,0,1]]

input: [1,2,3,4]     Output: []

intput: [-1, 1, 0, -1, 1, 0]   Ouput: [ [-1, 0, 1] ]



Constraints:
size of the input: 
range limitation for the element in the input 


Complexity : 

O(n^2) 

 *
 * 
 
 [-1, 0, 1, 2, 0, -1, 4] 
  i   j ------- > --- > |
      i   j --- > --- > |
          i  j --> -- > |



 [-1, 0, 1, 2, 0, -1, 4] 
  
 [-1, -1, 0, 0, 1, 2, 4]
   i      j     k



 *
 * */

#include<iostream>
#include<vector>
using namespace std;
using std::vector;

vector<vector<int>> threeSum(vector<int>& nums){

    vector<vector<int>> results;
    std::sort (nums.begin(), nums.end());


    for (int i=0; i<nums.size(); i++){
        
        if (i > 0 && nums[i] == nums[i-1]) continue;

        int j = i + 1;
        int k = nums.size() - 1;

         while (j < k) {
            int total = nums[i] + nums[j] + nums[k];
            if (total > 0) k--;
            else if (total < 0 ) j++;
            else {  
                results.push_back({nums[i], nums[j], nums[k]});
                j++;
                while (nums[j] == nums[j-1] && j<k) j++;

            }
         }
     }
    // filter out the repeat triples

    
    return results;
}


int main(){

    vector<int> input = {-4, 0, 4, -4, 0, 4, -4 ,0, 4}; 
    vector<vector<int>> test1 = threeSum(input);

    for (const auto& triplet : test1) {
        for (int num : triplet) {
            cout << num << "  ";
        }
        cout<< "\n";
    }

    return 0;

}
