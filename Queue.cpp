#include <iostream>
using namespace std;



class Node{
    public:
    // Data 
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node(){
        next = NULL;
    }
};

class LinkedList{
    // Head + Circles inside linked with each other
    public:
    // Head -> Node type ptr
    Node * head;
    Node * tail;
    // Construct
    LinkedList(){
        head = NULL;
        tail = NULL;
    } 

    // Circles inside linked with each other
    // Rules how circles will be linked
    // Insert
    void insert(int value){
       // If 1st Node is added
       Node * temp = new Node; 
       // Insert value in the node
       temp->data = value;
       // 1st Node only.
       if(head == NULL){
            head = temp;
       }
       // Any other Node only.
       else{
            tail->next = temp;
       }
       tail = temp;
    } 
    void insertAt(int pos, int value){
	//if it is first position
	if(pos==1)
	{
		//creating a new node
		Node * temp= new Node;
		temp->data = value;
		//linking the new node to the 1st node
		temp->next= head;
		//pointing the head to the new node
		head= temp;
	}
	//for other positions
	else{	        
      	// Reach the place before the pos
		Node * current = head;
		int i =1;
		while(i < pos-1){
		    i++;
		    current = current->next;
		    if(current == NULL)
			break;
		}
		if(current != NULL){
			// Create a node
			Node * temp = new Node;
			temp -> data = value;
			// Moving ptrs like magic ! if not head
			temp->next = current->next;
			current->next = temp;
		}
		else
      		cout<<"Linked List does not have "<<pos<<" elements"<<endl;
	}
 }

    // Deletion of last element
    void delet(){
       if(head == tail){
	   	     Node *temp = head;
	   	     head= NULL;
	   	     tail= NULL;
	   	     delete temp;
	   }
	   else{
		    // store the tail in temp
	        Node * temp = tail;
	        // before tail has to point to null
	        Node * current = head;
	        while(current->next != tail){
	            current = current->next;
	        }
	        current->next = NULL; 
	        // update tail
	        tail = current;
	        // delete temp
	         delete temp;
	   }
	}   

	//deleting a node from a particular position	
	void deletAt(int pos){
		if(pos==1){
				Node *temp= head->next;
				delete head;
				head= temp;
		}
		else
		{
				Node * current = head;
				int i=1;
				while(i< pos-1){
					i++;
					current= current->next;
					if(current == NULL)
						break;		
				}
				if(current != NULL){
					Node *temp= current-> next;
					//linking the current node to the next 2nd node
					current->next= temp->next;
					delete temp;	
				}
				else
					cout<<"Linked List does not have "<<pos<<" position"<<endl;
		}
					
	}

	// to count the number of items
	int countItems(){
		Node *current = head;
		int i=0;
		while(current != NULL){
			i++;
			current= current->next;
		}
		return i;
	}

    // Display
    void display(){
        Node * current = head;
        while(current != NULL){
            cout << current->data << "->";
            current = current->next;
        }
        cout <<"NULL" << endl;
    }
};

class QueueLL{
	public:
	Node * end;
	Node * front;
	LinkedList l1;
	
	QueueLL(){
		end = l1.head;	
		front = l1.tail;
	}
	
	void Enqueue(int value){
		//same as insertAt pos One
		l1.insertAt(1, value);
		//end = New_head
		end = l1.head;
		//tail doesn't change
	}
	
	void Dequeue(){
		int a= size();
		if(a==0)
			cout<<"dequeing from an empty queue"<<endl;
		else{
			//same as delet function
			l1.delet();
			//front = new_tail
			front = l1.tail;
			//head doesn't change
	    }
	}
		
	
	bool isEmpty(){
		if(end == NULL) return true;
		return false;
	}
	
	int size(){
		return l1.countItems();
	}
	
	int display(){
		l1.display();
	}
	
};

int main(){
	QueueLL q1;
	for(int i =0; i<5; i++){ 
		q1.Enqueue(i);
	}
	
	for(int i=0; i<7; i++){
		if(q1.isEmpty()){
            cout<<"Queue is empty"<<endl;
		}
		else{
			q1.Dequeue();
			q1.display();
		}
	}	
}
