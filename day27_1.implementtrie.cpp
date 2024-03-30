/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


class Trie {
   
public:
      struct TrieNode{
         bool isEndOfword;
        TrieNode* children[26];
   };
   //create

    TrieNode* getNode(){
        TrieNode* newNode=new TrieNode();
        newNode->isEndOfword=false;
        for(int i=0;i<26;i++)
     { 
        newNode->children[i]=NULL;
     }
return newNode;
    }
    /** Initialize your data structure here. */
    TrieNode * root;
    Trie() {
      root= getNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
          TrieNode* crawler=root;
          for(int i=0;i<word.size();i++){
              int ind=word[i]-'a';
             if(crawler->children[ind]==NULL)
            {
                crawler->children[ind]=getNode();
            }
            crawler=crawler->children[ind];
          }
          crawler->isEndOfword=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
         TrieNode* crawler=root;
          for(int i=0;i<word.size();i++){
              int ind=word[i]-'a';
              if(crawler->children[ind]==NULL)return false;
              crawler=crawler->children[ind];
          }
          return (crawler->isEndOfword==true);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
            TrieNode* crawler=root;
            for(int i=0;i<prefix.size();i++){
            int ind=prefix[i]-'a';
            if(crawler->children[ind]==NULL)return false;
            crawler=crawler->children[ind];



            }
            return true;
    }
};
