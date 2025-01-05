#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    // void rotate(vector<int>& nums, int k) {
    //     vector<int> :: iterator start = nums.begin();
    //     int length = nums.size()-1;
    //     for (int i=0; i<k; i++){
    //         int temp = nums[length];
    //         nums.pop_back();
    //         nums.insert(nums.begin(), temp);
    //     }
    // }
    void rotate(vector<int>& nums, int k) {
        int temp = 0;
        vector<int> shift_array;
        int length = nums.size();
        if (k > length) k %= length;
        for (int i=k;i>0;i--){
            temp = nums[length-i];
            shift_array.push_back(temp);
        }
        int rest_length = length - shift_array.size();
        for (int i=0; i<rest_length; i++){
            shift_array.push_back(nums[i]);
        }
        nums.clear();
        for (int i=0; i<shift_array.size();i++){
            nums.push_back(shift_array[i]);
        }
    }
};


int main(){
    Solution mySolution;
    vector<int> v = {-1};
    for (int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";

    mySolution.rotate(v, 3);
    for (int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}