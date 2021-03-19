#include<iostream>
using namespace std ;

class node {

public :
node* previous ;
int data ;
node* next ;

   node(int value){
     this -> data = value ;
     this -> next = NULL ;
     this -> previous = NULL;
   }
};

class DoubleLinkedList {
  private :
  node* head ;

  public :
  DoubleLinkedList(){
    this -> head = NULL ;
  }

  void insertAtBegin(int value){
    node* newNode = new node(value);

    if(this -> head == NULL){
      this -> head = newNode;
      return ;
    }

    // point next to first element
    newNode -> next = head;
    // point previous of first element to new node
    head -> previous = newNode ;
    // point head to new node
    this -> head = newNode;
    return;
  }

  void insertAtEnd(int value){
    node* newNode = new node(value);

    if(this -> head == NULL){
      this -> head = newNode ;
      return ;
    }

    node* temp = head ;
    // go to last element
    while(temp -> next != NULL){
      temp = temp -> next ;
    }
    //last element points to new node
    temp -> next = newNode ;
    //new node previous points to last element
    newNode -> previous = temp ;
  }

  void insertAtK(int value , int pos){
    node* newNode = new node(value);

    if(this -> head == NULL){
      head = newNode ;
    }

    node* temp = head ;
    while((--pos > 1) && temp != NULL){
      temp = temp -> next ;
    }

    // previous of new node points to pos - 1 element
    newNode -> previous = temp ;
    // next of new node points to pos element
    newNode -> next = temp -> next ;
    // previous of pos element points to new node
    temp -> next -> previous = newNode ;
    // next of pos - 1 element points to new node
    temp -> next = newNode ;
  }

  void deleteAtBegin(){
    if(this -> head == NULL){
      return ;
    }

    node* temp = head ;
    //point head to second element
    head = head -> next ;
    head -> previous = NULL;
    delete temp ;
  }

  void deleteAtEnd(){
    if(this -> head == NULL){
      return ;
    }

    node* temp = head ;
    while(temp -> next != NULL){
      temp = temp -> next ;
    }
    //second last elements next points to null
    temp -> previous -> next = NULL ;
    delete temp ;
  }

  void deleteAtK(int pos){
    if(this -> head == NULL){
      return ;
    }

    if(pos == 1){
      node* temp = head ;
      // point head to next element
      head = head -> next ;
      // second elements previous stores null
      head -> previous = NULL ;
      delete temp ;
      return ;
    }

    node* temp = head;
    while(temp->next && (pos-- > 1)){
      temp = temp -> next ;
    }
    // the pos - 1 nodes next stores the pos + 1 elements adress
    temp -> previous -> next = temp -> next ;
   // if the node is not last node then point pos + 1 previous to pos - 1 node
    if(temp -> next){
    temp -> next -> previous = temp -> previous ;
     }
    delete temp ;
    return ;
  }

  void display(){
    node* node = this->head;
    while(node -> next != NULL){
     cout<<node->previous<<"|"<<node->data<<"|"<<node->next<<" <-> ";
     node = node->next ;
    }
     cout<<node->previous<<"|"<<node->data<<"|"<<node->next<<"\n";
    return;
  }
};

int main(){
DoubleLinkedList dll ;
dll.insertAtBegin(1);
dll.insertAtBegin(2);
dll.insertAtBegin(3);
dll.insertAtBegin(4);
dll.insertAtEnd(10);
dll.insertAtEnd(9);
dll.insertAtK(100 , 3);
dll.display();
dll.deleteAtBegin();
dll.display();
dll.deleteAtEnd();
dll.display();
dll.deleteAtK(5);
dll.display();
}
