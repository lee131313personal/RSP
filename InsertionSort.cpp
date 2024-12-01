#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> readNumber();
vector<int> insertionSort(vector<int> myVector);
void printVector(vector<int> myVector);

vector<int> readNumber(){ // use i
    vector<int> myVector;
    int input;
    while (cin >> input) {
        if (input == 'M') break;
        myVector.push_back(input);
    }
    cout << "Before doing insertion sort : \n";
    //cout << "The size of the vector is : " << myVector.size() << endl;
    
    for (int i=0; i<myVector.size(); ++i) {
        cout << myVector[i] << " ";
    }
    cout << "\n";
    
    return myVector;
}



vector<int> insertionSort(vector<int> myVector){
    for (int j=myVector.size(); j>0; j--){    
        for (int i=0; i<myVector.size()-1; i++){
            if (myVector[i] > myVector[i+1]){
                std::swap(myVector[i], myVector[i+1]);
            }
        }
    }
    //printVector(myVector);
    return myVector;
}

void printVector(vector<int> myVector){
    for (int i=0; i<myVector.size(); ++i){
        cout << myVector[i] << " "; 
    }
    cout << "\n";
}


int main(){
    vector<int> intVector = readNumber();    
    vector<int> sorted_vector = insertionSort(intVector);
    cout << "After doing insertion sort : \n ";
    printVector(sorted_vector);

    return 0;
}
