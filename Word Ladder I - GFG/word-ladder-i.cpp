//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Code here
        int flag=0;
        for(int i=0;i<wordList.size();i++){
            if(endWord == wordList[i]){
                flag=1;
                break;
            }
        }   
        if(!flag){
            return 0;
        }

        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch = 'a';ch<='z';ch++){
                    word[i] = ch;

                    // WORD EXISTS IN WORDLIST
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,step+1});

                        if(word == endWord){
                            return step+1;
                        }
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends