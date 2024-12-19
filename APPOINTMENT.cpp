#include<iostream>
using namespace std;

class slot{
public:
    int startTime, endTime, min, max;
    bool status;
    slot*next;

    slot(int start, int end, int min, int max){
        startTime = start;
        endTime = end;
        this->min = min;
        this->max = max;
        status = 0;
        next = NULL;
    }
};
slot* head;
void display(){
    cout<<"Sr.No\tStartTime\tEndTime\tMin\tMax\tStatus"<<endl;
    int i= 1;
    slot*temp = head;
    while(temp!= NULL){
        cout<<i<<"\t"<<temp->startTime<<"\t"<<temp->endTime<<"\t"<<temp->max<<"\t"<<temp->min<<"\t";
        if(temp->status == 0){
            cout<<"Free."<<endl;
        }
        else{
            cout<<"Booked."<<endl;
        }
        i++;
        temp = temp->next;
    }
}

void bookAppointment(){
    int start;
    cout<<"Enter the start time of booking appointment : ";
    cin>>start;
    slot*temp = head;
    while (temp!= NULL)
    {
        /* code */
        if(temp->startTime = start){
            if(temp->status = 0){
                temp->status= 2;
                cout<<"Slot booked succesfully!!!"<<endl;
                break;
            }
            else if(temp->status = 1){
                cout<<"Sorry, slot is already booked.."<<endl;
                break;
            }
        }
        temp = temp->next;
    }    
}

void cancelAppointment(){
    int start;
    cout<<"Enter the start time for cancelling the  appointment : ";
    cin>>start;
    slot*temp = head;
    while (temp!= NULL)
    {
        /* code */
        if(temp->startTime == start){
            if(temp->status = 1){
                temp->status= 0;
                cout<<"Slot cancelled successfully."<<endl;
                break;
            }
            else if(temp->status == 0){
                cout<<"Slot is already free..."<<endl;
                break;
            }
        }
        temp = temp->next;
    }    
}
void sortAppointment(){
    slot* temp = head;
    while(temp->next!= NULL){
        slot* current = temp->next;
        while(current!= NULL){
            if(current->startTime < temp->startTime){
                int val;
                val= current->startTime;
                current->startTime= temp->startTime;
                temp->startTime= val;

                val= current->endTime;
                current->endTime= temp->endTime;
                temp->endTime= val;

                val = current->min;
                current->min = temp->min;
                temp->min= val;

                val = current->max;
                current->max = temp->max;
                temp->max = val;

                bool stat = current->status;
                current->status = temp->status;
                temp->status = stat;  
            }
            current = current->next;
        }
        temp = temp->next;
    }
    cout<<"Slots are sorted successfully..."<<endl;
    display();
}
int main(){
    int n;
    cout<<"Number of sslots: ";
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        /* code */
        int start, end, min, max;
        cout<<"Enter start time of slot: ";
        cin>>start;
        cout<<"Enter end time of slot: ";
        cin>>end;
        cout<<"Enter max duration: ";
        cin>>max;
        cout<<"Enter min duration: ";
        cin>>min;

        slot* newNode = new slot(start,end,min,max);
        if(head == NULL){
            head = newNode;
        }
        else{
            slot*temp = head;
            while(temp->next!= NULL){
               temp = temp->next; 
            }
            temp->next = newNode;
        }
    }
    display();
    char cont;
    int choice;
    do{
        cout<<"\nMENU \n1. Display appointment List\n2. Book Appointment\n3. Cancel Appointment\n4. Sort Appointment\nEnter the choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                display();
                break;
            case 2:
                bookAppointment();
                break;
            case 3:
                cancelAppointment();
                break;
            case 4:
                sortAppointment();
                break;
            default:
                cout<<"Invalid choice..."<<endl;
        }
        cout<<"Do you want to continue? (y/n): ";
        cin>>cont;
    }while(cont=='y' || cont=='Y');
    return 0;
}
