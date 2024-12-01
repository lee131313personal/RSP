#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

typedef struct node{
    int data;
     node *left;
     node *right;
     int height;
}Node;

// visit the root node to visit the whole tree
typedef struct {
    Node* root;
}Tree;

///functions declarations
Node* insertTree(Node* root, int value);
int get_tree_height(node* root);
bool search_element(Node* root, int value);

Node* singleRightRotation(Node* root);
Node* singleLeftRotation(Node* root);
Node* leftRightRotation(Node* root);
Node* rightLeftRotation(Node* root);

Node* delete_node(Node* root, int value);

void preorder(Node* node);
void inorder(Node* node);
void postorder(Node* node);


int main(){

    Node* root = nullptr;
    // Read and parse the input in the main function
    string input;
    string tranverse = "";
    int i = 0;
    vector<string> operation_vector;
    while(cin >> input){
        if (input == "IN"){
            tranverse = "IN";
            break;
        }
        if (input == "PRE"){
            tranverse = "PRE";
            break;
        }
        if (input == "POST"){
            tranverse = "POST";
            break;
        }
        // If did not read the tranverse operation, push the operation into the vector
        operation_vector.push_back(input);
    }
    // tranverse the operation vector and do operations accordingly
    vector<string>::iterator iter = operation_vector.begin();
    for(iter=operation_vector.begin(); iter<operation_vector.end(); iter++){
        string operation_and_value = *iter;
        string operation = operation_and_value.substr(0,1); // substring operation, the first letter of every operations
        string value_STR = operation_and_value.substr(1); // substring operation, the string-type integers in the operations
        int _value = stoi(value_STR); // convert the string to 'int'

        if (operation == "A"){
            // add element into the tree
            root = insertTree(root, _value);
        }
        if (operation == "D"){
            // delete element from the tree
             root = delete_node(root, _value);
        }
    }
    
    // the variable 'tranverse' will tell us the way to tranverse the tree
    if (tranverse == "PRE") preorder(root);
    else if (tranverse == "IN") inorder(root);
    else if (tranverse == "POST") postorder(root);
    else{}
    // special: if there is no element in the tree:
    if (root == nullptr) cout << "EMPTY";
    return 0;
}

int get_height(node* root){
    if (root == nullptr) return 0;
    else return root->height;
}


bool search_element(Node* root, int value){
    Node* traverse = root;
    while (traverse != nullptr) {
        if (traverse->data == value)    return true;
        else if (value < traverse->data)    traverse = traverse->left;
        else    traverse = traverse->right;
    }
    return false; //value not found
}



Node* insertTree(Node* root, int value){
    if (root == nullptr){
        root = new Node();
        root->left = root->right = nullptr;
        root->height = 1;
        root->data = value;
    }
    else if (value < root->data){
        
        if (search_element(root, value)) return root; // if the element is already in the tree
        root->left = insertTree(root->left, value);
        //update height
        root->height = max(get_height(root->left), get_height(root->right)) + 1;
        //see if balanced
        // if we insert to the left subtree, than, the tree becomes unbalanced:
        if (get_height(root->left) - get_height(root->right) == 2){
            if ( root->left->data > value ){
                // need to perform single right rotation
                root = singleRightRotation(root);
            }
            else {
                root = leftRightRotation(root);
            }
        }
    }
    else {
        if (search_element(root, value)) return root; // if the element is already in the tree
        root->right = insertTree(root->right, value);
        //update height
        root->height = max(get_height(root->left), get_height(root->right))+ 1;
        // if we insert to the right subtree, than, the tree becomes unbalanced:
        if (get_height(root->left) - get_height(root->right) == -2){
            if ( root->right->data < value ) {
                // need to perform single left rotation
                root = singleLeftRotation(root);
            }
            else {
                root = rightLeftRotation(root);
            }
        }
    }
    return root;
}


Node* singleRightRotation(Node* root){
    Node* _copy = root->left;
    root->left = _copy->right;
    _copy->right = root;
    root->height = max(get_height(root->left), get_height(root->right)) + 1;
    _copy->height = max(get_height(_copy->left), get_height(_copy->right)) + 1;
    return _copy;
}

Node* singleLeftRotation(Node* root){
    // NOTE: after single left rotation, the heights of nodes will change, so always do a
    //       height update after rotation
    Node* _copy = root->right;
    root->right = _copy->left;
    _copy->left = root;
    root->height = max(get_height(root->left), get_height(root->right)) + 1;
    _copy->height = max(get_height(_copy->left), get_height(_copy->right)) + 1;
    return _copy;
}

Node* leftRightRotation(Node* root){
    root->left = singleLeftRotation(root->left);
    root = singleRightRotation(root);
    return root;
}


Node* rightLeftRotation(Node* root){
    root->right = singleRightRotation(root->right);
    root = singleLeftRotation(root);
    return root;
}

Node* delete_node(Node* root, int value){
    if (root == nullptr) return root;
    else if (value < root->data)    root->left = delete_node(root->left, value);
    else if (value > root->data)    root->right = delete_node(root->right, value);
    else{ // Search the target node in the tree
        if (root->left == nullptr && root->right == nullptr){ // Case 1: leaf node
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr){ //Case 2: has one child (right)
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == nullptr){ //Case 2: has one child (left)
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else{ //Case 3: has two children(subtrees)
            // We are going to find the largest element in the left subtree
            Node* largest = root->left;
            while (largest->right != nullptr){
                largest = largest->right;
            }
            // Replace the target node with the largest element
            root->data = largest->data;
            // remove the largest element from the left-subTree
            root->left = delete_node(root->left, largest->data);
        }
    }
    if (root == nullptr) {
        return root;
    }
    // Always remember to update the height
    root->height = max(get_height(root->left), get_height(root->right)) + 1;
    // For every deletion operation, we need to check whether the tree is still balanced after the operation
    if (get_height(root->left) - get_height(root->right) == 2){
        if ( get_height(root->left->left) >= get_height(root->left->right) ){
            root = singleRightRotation(root);
        }
        else root = leftRightRotation(root);
    }
    else if (get_height(root->left) - get_height(root->right) == -2){
        if(get_height(root->right->right) >= get_height(root->right->left))
            root = singleLeftRotation(root);
        else root = rightLeftRotation(root);
    }
    return root;
}


//////Tranverse//////
void preorder(Node* node){ // can consider node as root
    if (node != nullptr){
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Node* node){ // can consider node as root
    if (node!=nullptr){
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void postorder(Node* node){ // can consider node as root
    if (node != nullptr){
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}




