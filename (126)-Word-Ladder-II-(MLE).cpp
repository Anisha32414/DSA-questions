class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        vector<vector<string>>ans;
        q.push({beginWord});
        vector<string>used;
        used.push_back(beginWord);
        int level=0;

        while(!q.empty()){
            vector<string> vec=q.front();
            q.pop();

            if(vec.size()>level){
                level++;
                for(auto it:used){
                    st.erase(it);
                }
                used.clear();
            }

            string word=vec.back();
            if(word==endWord){
                if(ans.size()==0){
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }

            for(int i=0;i<word.size();i++){
                string original=word;
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        vec.push_back(word);
                        q.push(vec);
                        used.push_back(word);
                        vec.pop_back();
                    }
                }
                word=original;
            }
        }
        return ans;
    }
};
