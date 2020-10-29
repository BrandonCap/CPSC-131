
// Illustrating a simple singly linked list

#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int element ){
        data = element;
        next = nullptr;
        
    } 

};


int main()
{
    
    //creating a regular struct node
    /*Node s(6);
    
    std::cout<<"Node's data: "<<s.data<<std::endl;*/
    
    
    Node* ptr;
    Node* head;
    Node* tail;

    //Creating an empty SLL
    head = nullptr;
    tail = nullptr;
    
    // Creating a node
    ptr = new Node(7);
    
    std::cout<<"Node's data: "<< (*ptr).data<<std::endl;
    // Node's data : also written as ptr->data;
    
    // Adding the newly created node to the previously empty SLL
    head = ptr;
    tail = ptr;
    
    
    
    char answer;
    std::cout<<"Add more elements to the SLL ? Answer y or n "<<std::endl;
    std::cin>>answer;
    
    while (answer == 'y'){
         
         int a;
         std::cout<<"Enter element: ";
         std::cin>>a;
         ptr = new Node(a);
         
         tail->next = ptr;
         tail = ptr;
         
         std::cout<<"Add more elements to the SLL ? Answer y or n "<<std::endl;
         std::cin>>answer;
        
    }
    
    ptr = head;
    
    std::cout<<"Printing the list ";
    
    while(ptr!=nullptr){
        std::cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    
    return 0;
}