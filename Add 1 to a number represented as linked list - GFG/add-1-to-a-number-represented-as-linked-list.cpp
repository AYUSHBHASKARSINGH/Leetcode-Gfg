//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    Node* reverse(Node* head){
        
        if(head == NULL || head->next ==NULL){
            return head;
        }
        
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr!=NULL){
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* temp = reverse(head);
        Node* gg;
        int carry = 1,cc;
        Node* curr = temp;
        while(curr!=NULL){
            cc = curr->data + carry;
            if(cc>=10){
                carry = 1;
            }
            else{
                carry = 0;
            }
            
            cc = cc%10;
            curr->data = cc;
            
            gg = curr;
            curr = curr->next;
            
        }
        if(carry>0){
            gg->next = new Node(carry);
        }
        temp = reverse(temp);
    return temp;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends