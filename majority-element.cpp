#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> map_occurance_value;
        // < numnber, number_of_occurance >
        // initialization, all the #occurance = 0;
        for (int i=0; i<nums.size(); i++){
            map_occurance_value[nums[i]] = 0;
        }
        for (int i=0; i<nums.size(); i++){
            if (map_occurance_value.find(nums[i]) != map_occurance_value.end()){
                map_occurance_value[nums[i]] ++;
            }
        }
        int max_occurance = 0;
        int max_element = 0;
        for (auto it = map_occurance_value.begin(); it != map_occurance_value.end(); ++it){
            if (it->second > max_occurance) {
                it->second = max_occurance;
            }
        }
        for (auto it = map_occurance_value.begin(); it != map_occurance_value.end(); ++it){
            if (it->second == max_occurance) {
                max_element = it->first;
            }
        }
        return max_element;
    }
};

int main(){
    Solution mySolution;
    vector<int> v = {10,2,5,8,8,8,8,8,8,8,10,12};
    cout << "Majority element: " << mySolution.majorityElement(v) << " \n";
    return 0;
}