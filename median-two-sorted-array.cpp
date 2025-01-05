#include<iostream>
#include<string>
#include<vector>


using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // first we need to merge two vectors
        std::vector<int>::iterator it1 = nums1.begin();
        std::vector<int>::iterator it2 = nums2.begin();
        std::vector<int> total;
        while ( it1 != nums1.end() && it2 != nums2.end() ) {
            if (*it1 < *it2){
                total.push_back(*it1);
                cout << *it1 << " pushed into total, it1 smaller\n";
                it1++;
            }
            else if (*it1 > *it2){
                total.push_back(*it2);
                cout << *it2 << " pushed into total, it2 smaller\n";
                it2++;
            }
            else {
                total.push_back(*it1);
                cout << *it1 << " pushed into total, equal\n";
                it1++;
            }
        }
        // now, the shorter one may run out elements earlier
        if (it2 == nums2.end()){ // nums2 run out, fill the total with the rest of number 1 
            std::cout << "nums2 ran out\n";
            while (it1 != nums1.end() ){
                total.push_back(*it1);
                it1++;
            }
        }
        else {
            std::cout << "nums1 ran out\n";
            while (it2 != nums2.end()){
                total.push_back(*it2);
                it2++;
            }
        }
        cout << "SIZE: " << total.size() << endl;
        for (int i=0; i<20; i++){
            cout << total.at(i) << " ";

        }

        double med = 0.0;
        if (total.size() % 2 == 0 ) {
            med = (total.at(total.size()/2 - 1) + total.at(total.size()/2)) / 2.0;
        }
        else { 
            med = total.at(total.size()/2);
        }
        return med;
    }
};

int main(){
    vector<int> num1 = {1,1,1,1,1,1,1,1,1,1,4,4};
    vector<int> num2 = {1,3,4,4,4,4,4,4,4,4,4};
    Solution mySolution;
    double med = mySolution.findMedianSortedArrays(num1, num2);
    cout << med << endl;
    return 0;
}