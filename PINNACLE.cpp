#include<iostream>
using namespace std;

struct node{
    int prn;
    string name;
    node* next;
    node(int val, const std::string& n) : prn(val), name(n), next(NULL) {}

};
class list{
    node* head;
public:
    list(): head(NULL){}

    node* create(int val, string n){
        node*newNode = new node(val,n);
        if(newNode == NULL){
            cout<<"Memeroy allocation failed"<<endl;
            return NULL;
        }
        else{
            newNode->prn = val;
            newNode->name = n;
            newNode->next = NULL;
            return newNode;
        }
    }

    void insertAtEnd(){
        int val;
        string n;
        cout<<"ENter your prn: ";
        cin>>val;
        cout<<"Enter your name : ";
        cin.ignore();
        getline(cin, n);

        node*newNode = create(val,n);
        if(head == NULL){
            head= newNode;
        }
        else{
            node* temp = head;
            while(temp->next!= NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        
        }
        cout<<"Element inserted at the end.";
    }

    void insertAt(){

        int val,pos;
        string n;

        cout<<"Enter the position u want to insert : ";
        cin>>pos;
        cout<<"Enter prn number : ";
        cin>>val;
        cout<<"Enter name : ";
        cin.ignore();
        getline(cin,n);

        if(pos == 1){
            insertAtbeg();
        }
        else{
            node*temp = head;
            int counter = 1;
            while(temp->next!=NULL && counter < pos-1){
                temp = temp->next;
                counter++;
            }
            if(temp == NULL){
                cout<<"Position is out of stock..,"<<endl;
            }
            else{
                node* newNode = create(val,n);
                newNode->next= temp->next;
                temp->next = newNode;
                cout<<"Member inserted at position.."<<pos<<endl;
            }
        }
    }

    void insertAtbeg(){
        int val;
        string n;
        cout<<"Enter prn number : ";
        cin>>val;
        cout<<"Enter name: ";
        cin.ignore();
        getline(cin,n);

        node*newNode = create(val,n);
        newNode->next = head;
        head = newNode;
        cout<<"Presindent inserted..."<<endl;
    }

    void display(){
        if(head == NULL){
            cout<<"List is empty.."<<endl;
        }

        node*temp = head;
        cout<<"List: "<<endl;

        int pos = 1;
        while(temp!=NULL){
            if(pos == 1){
                cout<<"President: ";
            }
            else if(temp->next == NULL){
                cout<<"Secretary: ";
            }
            else{
                cout<<"Member "<<pos-1<<": ";
            }
            cout<<temp->prn<<" - "<<temp->name<<endl;
            temp = temp->next;
            pos++;
        }
    }
    void concatenate(list&other){
        if (head == NULL){
            head = other.head;
        }
        else{
            node*temp = head;
            while(temp -> next != NULL){
                temp = temp->next;
            }
            temp->next = other.head;
        }
        cout<<"Lists have been concatenated."<<endl;
        display();
    }

    void del(){
        int r;
        cout<<"Enter prn number to be deleted : ";
        cin>>r;

        if(head == NULL){
            cout<<"List is empty..";
        }

        node*temp = head;
        node*prev = NULL;

        if(temp!= NULL && temp->prn == r){
            head = temp->next;
            delete temp;
            cout<<"Member with prn "<<r<<" is deleted;";
        }
        while(temp!= NULL && temp->prn!= r){
            prev = temp;
            temp=temp->next;
        }
        if(temp == NULL){
            cout<<"Member with prn "<<r<<" is not found";
        }
        prev->next = temp->next;
        delete temp;
        cout<<"Member with prn "<<r<<" is deleted.";
    }

    void op(){
        while(true){
            int choice;
            cout<<"\nEnter: \n1. Add president \n2. Add secretary \n3. Add member at position \n4. display \n5. delete member \n0. Exit"<<endl;
            cin>>choice;
            switch ((choice))
            {
            case 1:
                insertAtbeg();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAt();
                break;
            case 4:
                display();
                break;
            // case 5:
            //     {
            //         list otherlist;
            //         cout<<"Enter details of other list: "<<endl;
            //         otherlist.op();
            //         concatenate(otherlist);
            //     }
            //     break;
            case 5:
                del();
                break;
            case 0:
                return;
            default:
                cout<<"Invalid choice. Please try again.."<<endl;
                break;
            }
        }
    }
};


int main() {
    list listA, listB;
    while (true) {
        int choice;
        cout << "\nMain Menu: \n"
             << "1. Operate on List A \n"
             << "2. Operate on List B \n"
             << "3. Concatenate List A and List B \n"
             << "0. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "\nOperating on List A:" << endl;
            listA.op();
            break;
        case 2:
            cout << "\nOperating on List B:" << endl;
            listB.op();
            break;
        case 3:
            cout << "\nConcatenating List A and List B:" << endl;
            listA.concatenate(listB);
            break;
        case 0:
            cout << "Exiting the program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}
