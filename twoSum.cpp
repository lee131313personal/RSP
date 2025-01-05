/*
 
   Question Description:

   Given an array of integer numners and an integer target, return indices of the two numbers such that they add up to target 

   sample input : 
    nums = [2,7,11,15],  target = 9
   Sample output: [0, 1]


    sample input:
        nums = [2, 3, 4],    target = 6 
    sample output: 
        [1, 2]


 *
 * */

#include<iostream>
#include<string>
#include<vector>
using namespace std;


vector<int> twoSum(vector<int> nums, int target)
{
    unordered_map<int, int> myMap;
    vector<int> result;

    for (int i=0; i<nums.size(); i++){
        if (mp.find(target - nums[i] != mp.end(){
            result.emplace_back(i);
            result.emplace_back(myMap[target-nums[i]]);
            break;
        }
        myMap[nums[i]] = i;
    }
    return results;
}




int main(){



    reutrn 0;
}
