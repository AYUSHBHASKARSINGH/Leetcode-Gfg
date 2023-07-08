//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
	public:
	    
	    struct Node{
	        int data;
	        Node* left;
	        Node* right;
	        
	        Node(int val){
	            data = val;
	            left = NULL;
	            right = NULL;
	        }
	    };
	    
	    struct comp{
	        bool operator()(Node* l,Node* r){
	            return (l->data > r->data);
	        }
	    };
	    
	    void preorder(Node* root , string S , vector<string> &ans){
	        if(root == NULL){
	            return;
	        }
	        
	        if(root->left ==NULL && root->right == NULL){
	            ans.push_back(S);
	        }
	        
	        preorder(root->left,S+"0",ans);
	        preorder(root->right,S+"1",ans);
	    }
	    
	    
		vector<string> huffmanCodes(string S,vector<int> f,int n)
		{
		    // Code here
		  //  initialising min heap
		  priority_queue<Node* , vector<Node*> , comp > mh;
		    
		  //  Storing all frequencies in min heap
		  for(int i=0;i<n;i++){
		      Node* temp = new Node(f[i]);
		      mh.push(temp);
		  }
		  
		  
		  while(mh.size() > 1){
		      Node* left = mh.top();
		      mh.pop();
		      Node* right = mh.top();
		      mh.pop();
		      Node* parent = new Node(left->data+right->data);
		      parent->left = left;
		      parent->right = right;
		      mh.push(parent);
		  }
		  
		  Node* root = mh.top();
		  vector<string> ans;
		  preorder(root,"",ans);
		  
		  return ans;
		}
		
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends