/*
Simple Queue, using a linkedlist data structure
*/
#include<iostream> 
#include<string>

using namespace std;


class LinkedListNode {
    protected:
        int node_data;
        LinkedListNode* ptr_to_next;
    public: 
        LinkedListNode() : node_data(0), ptr_to_next(nullptr){}
        LinkedListNode(int node_value) : node_data(node_value), ptr_to_next(nullptr) {}
        LinkedListNode(int node_value, LinkedListNode* next_ptr) : node_data(node_value), ptr_to_next(next_ptr) {}
        int get_node_data() { return node_data;}
        LinkedListNode* get_ptr_to_next() {return ptr_to_next;}
        void setData(int new_data) { node_data = new_data; }
        void setNext (LinkedListNode* next) {
            ptr_to_next = next;
        }
};

class LinkedList {
    protected: 
        LinkedListNode* head_node;
    public:
        LinkedList () : head_node(nullptr){}
        LinkedList (LinkedListNode* start) : head_node(start){}
        
        // insert_after by a pointer 
        void insert_after(LinkedListNode* insert_after_here, LinkedListNode* new_node) {
            LinkedListNode* traverse_ptr = new LinkedListNode();
            traverse_ptr->setNext(head_node);
            while (traverse_ptr->get_ptr_to_next() != insert_after_here) {
                traverse_ptr = traverse_ptr->get_ptr_to_next();
            }
            /**
             *                            
             *                                                          trav       [new_data | next ]
             *                                                             \ 
             *        head --->[ data | next] ----> [data | next] ------> [data | next]  ------> [data | next] 
            */
           traverse_ptr = traverse_ptr->get_ptr_to_next();
           LinkedListNode* temp = traverse_ptr->get_ptr_to_next();
           traverse_ptr->setNext(new_node);
           new_node->setNext(temp);
        }

        LinkedListNode* get_head() {
            return head_node;
        }

        void printListElement(){
            LinkedListNode *traverse_ptr = this->get_head();
            while (traverse_ptr != nullptr) {
                std::cout << traverse_ptr->get_node_data() << ", ";
                
                if (traverse_ptr->get_ptr_to_next() != nullptr) traverse_ptr = traverse_ptr->get_ptr_to_next();
                else break;
            }
            std::cout << std::endl;
        }

};




int main(){
    
    LinkedListNode* node1 = new LinkedListNode(10, nullptr);
    LinkedListNode* node2 = new LinkedListNode(12, nullptr);
    LinkedListNode* node3 = new LinkedListNode(13, nullptr);
    LinkedListNode* node4 = new LinkedListNode(14, nullptr);
    LinkedListNode* node5 = new LinkedListNode(15, nullptr);

    node1->setNext(node2);
    node2->setNext(node3);
    node3->setNext(node4);
    node4->setNext(node5);


    LinkedList *my_list = new LinkedList(node1);
    my_list->printListElement();
    
    return 0;
}