#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void Add_at_start(node *&head , int val){
    if(head == NULL){
        head = new node(val);
        return;

    }else{
        node *temp = new node(val);
        temp -> next = head;
        head = temp;
    }
}

void Add_at_end(node *&head , int val){
    if (head == NULL){
        head = new node(val);
        return;
    }else{
        node *temp = head;
        while (temp -> next != NULL){
            temp = temp -> next;

        }
        temp -> next = new node(val);
    }
    

}

void Add_at_anyPlace(node *&head , int val , int place){
    if (place == 1){
        Add_at_start(head , val);
        return;
    }

    node *temp = head;
    int currentPlace =1;
    while(temp != NULL &&  currentPlace < place - 1){
        temp = temp -> next;
        currentPlace++;
    }
    if(temp == NULL){
        cout << "position is out of bound";
        return;
    }

    node *newNode = new node(val);
    newNode -> next = temp ->next;
    temp -> next = newNode; 
}
void Delete_at_first(node *&head){
    if (head == NULL){
        return;
    }
    node *temp = head;
    head = head -> next;
    delete temp;
    
}
void Delete_at_end(node *&head)
{
    if ( head == NULL){
        return;
    }
    if(head -> next == NULL){
        delete head;
        head = NULL;
        return;
    }
    node *temp = head;

    while (temp -> next -> next != NULL){
        temp = temp -> next;
    }

    delete temp -> next;
    temp -> next = NULL;

}
void Delete_at_any(node *&head , int place){
    if (place  == 1){
        Delete_at_first(head);
    }
    node *temp = head;
    int count = 1;
    while (temp != NULL && count < place -1){
        //traversing to the node just before the target
        temp = temp -> next;
        count++;
    }
    if ( temp == NULL || count > place){
        cout << "invalid position";
    }

    node *target = temp -> next;
    temp->next = target -> next;
    delete target;
    
}





int main(){
    node *head = NULL;
    
    

    int arr[5] = {2,4,6,8,10};

    for (int i = 4; i>=0; i--)
    {
        Add_at_end(head , arr[i]);
    }

    Add_at_end(head , 0);
    //Add_at_start(head , 12);
    //Add_at_anyPlace(head , 14 , 1);
    //delete_atfirst(head);
    //delete_atend(head);
    Delete_at_any(head , 2);


    
    node *temp = head;
    while (temp != NULL){
        cout << temp -> data << "\n";
        temp = temp->next;
    }

}