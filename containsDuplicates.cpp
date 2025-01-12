/*
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for (int i=1; i<n; i++){
            if (nums[i-1] == nums[i]){
                cout << nums[i];
                return true;
            }
        }
        return false;
    }
};

*/


class Solution{
    public:
        bool containsDuplicate(vector<int>& nums){
            int n = nums.size();
            unordered_set<int> _set;
            for (int i=0; i<n; i++){
            if (_set.find(nums[i]) != _set.end()) 
                return true;

            else  _set.insert(nums[i]);

            }
            return false;
        }
};
