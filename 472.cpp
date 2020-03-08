class Solution {
public:
    unordered_map<string, int> exist;
    struct Trie {
        unordered_map<char,Trie*> adj;
        bool isWord = false;
    } *trie;
    
    
    void add(string str) {
        Trie* cur = trie;
        for(char c: str) {
            if(cur->adj.count(c) == 0)
                cur->adj[c] = new Trie();
            cur = cur->adj[c];
        }
        if(str.size())
            cur->isWord = true;
    }
    
    bool check(int pos, string& word, bool isStart) {
        
        Trie* cur = trie;
        bool temp = false;
        for(int i = pos; i < word.size(); i++) {
            if(cur->isWord) {
                temp = check(i , word, 0);
                if(temp)
                    return true;
            }
            if(cur->adj.count(word[i]) == 0)
                return false;
            cur = cur->adj[word[i]];
        }
        if(isStart)
            return false;
        return cur->isWord;
        
    }
    
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        trie = new Trie();
        
        for(string word: words) {
            add(word);
        }
        
        vector<string> res;
        for(string word: words) {
            if(check(0, word, 1))
                res.push_back(word);
        }
        
        return res;
    }
};
