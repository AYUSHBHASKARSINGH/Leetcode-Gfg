//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
struct TrieNode {
    struct TrieNode *children[26];
    bool isLeaf;
    int ew = 0;
    int cp = 0;
};

class Trie{
private:
    TrieNode* root;

public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string key)
    {
        // code here
        TrieNode* node = root;
        for(int i=0;i<key.length();i++){
            if(node->children[key[i]-'a']==NULL){
                node->children[key[i]-'a'] = new TrieNode();
            }
            node = node->children[key[i]-'a'];
            node->cp++;
        }
        node->isLeaf = true;
        node->ew++;
    }
    
    bool search(string word){
        TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            if(node->children[word[i]-'a']==NULL){
                return false;
            }
            node = node->children[word[i]-'a'];
        }
        
        if(node->isLeaf == true){
            return true;
        }
        else{
            return false;
        }
    }
    
    
    int word_starting_with(string word){
        TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            if(node->children[word[i]-'a'] == NULL){
                return 0;
            }
            else{
                node = node->children[word[i]-'a'];
            }
        }
        return node->cp;
    }
};


class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        Trie tr;
        vector<string> ans;
        
        for(int i=0;i<n;i++){
            tr.insert(arr[i]);
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<arr[i].length();j++){
                string temp = arr[i].substr(0,j+1);
                // cout<<temp<<endl;
                if(tr.word_starting_with(temp)==1){
                    ans.push_back(temp);
                    break;
                }
            }
        }
        
        return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}

// } Driver Code Ends