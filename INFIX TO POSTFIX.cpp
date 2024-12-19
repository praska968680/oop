#include<iostream>
#include<conio.h>
#include<ctype.h>   
using namespace std;
class stack
{
 public:
  char stack_array[50];
  int top;
  stack()
  {
    top=-1;
  }
void push(char symbol)
{  
    if(full())
        cout<<"\nStack overflow:\n";
    else
    { 
        top=top+1;
        stack_array[top]=symbol;
    }
}
char pop()
{   
    if(empty())
        return('#');         
    else
        return(stack_array[top--]);
}
int empty()
{    
    if(top==-1)
        return(1);
    else
        return(0);
}
int full()
{    
    if(top==49)
        return(1);
    else
        return(0);
}
private:
  char infix[50];
  char postfix[50];
public:
    void readInfix()
    {
        cout<<"\nEnter an infix expression: ";
        cin>>infix;
    }
    void readPostfix()
    {
        cout<<"\nEnter a postfix expression: ";
        cin>>postfix;
    }
    int white_space(char symbol)
    {  
        if(symbol==' ' || symbol=='\t' || symbol=='\0')
            return 1;
        else
            return 0;
    }
    void ConvertToPostfix()
    {    
        int prev, p = 0;
        char entry;
        p = 0;
        for(int i = 0; infix[i] != '\0'; i++)
        {
            if(!white_space(infix[i]))
            { 
                switch(infix[i])
                {
                    case '(': 
                        push(infix[i]);
                        break;
                    case ')': 
                        while((entry = pop()) != '(')
                            postfix[p++] = entry;
                        break;
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                        if(!empty())
                        {  
                            prev = prior(infix[i]);
                            entry = pop();
                            while(prev <= prior(entry))
                            {  
                                postfix[p++] = entry;
                                if(!empty())
                                    entry = pop();
                                else
                                    break;
                            }
                            if(prev > prior(entry))
                                push(entry);
                        }
                        push(infix[i]);
                        break;
                    default:
                        postfix[p++] = infix[i];
                        break;
                }
            }
        }
        while(!empty())                
            postfix[p++] = pop();
        postfix[p] = '\0';
        cout<<"\nThe postfix expression is: "<<postfix<<endl;
    }
    int prior(char symbol)
    {  
        switch(symbol)
        { 
            case '/': return(4);          
            case '*': return(3);          
            case '+': return(2);          
            case '-': return(1);          
            case '(': return(0);          
            default: return(-1);
        }
    }
    void EvaluatePostfix()
    {
        stack eval_stack;
        int i = 0;
        char symbol;
        int op1, op2, result;        
        while(postfix[i] != '\0')
        {
            symbol = postfix[i];
            if(isdigit(symbol))    
            {
                eval_stack.push(symbol - '0');  
            }
            else  
            {
                op2 = eval_stack.pop();
                op1 = eval_stack.pop();
                switch(symbol)
                {
                    case '+': result = op1 + op2; break;
                    case '-': result = op1 - op2; break;
                    case '*': result = op1 * op2; break;
                    case '/': result = op1 / op2; break;
                    default: cout << "Invalid operator!" << endl; return;
                }
                eval_stack.push(result);  
            }
            i++;
        }
        result = eval_stack.pop();   
        cout << "\nThe result of postfix evaluation is: " << result << endl;
    }
};
int main()
{  
    int choice;
    stack expr;
    do {
        cout<<"\nMenu:\n";
        cout<<"1. Convert Infix to Postfix\n";
        cout<<"2. Evaluate Postfix Expression\n";
        cout<<"3. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                expr.readInfix();
                expr.ConvertToPostfix();
                break;
            case 2:
                expr.readPostfix();
                expr.EvaluatePostfix();
                break;
            case 3:
                cout<<"Exiting program...\n";
                break;
            default:
                cout<<"Invalid choice! Please try again.\n";
        }
    } while(choice != 3);
    return 0;
}
