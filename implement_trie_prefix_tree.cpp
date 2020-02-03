const int Alphabet_count = 26;
struct Node{
  bool isEndOfWord;
  Node* children[Alphabet_count];
};

class Trie {
public:
  /** Initialize your data structure here. */

   bool isEndOfWord;
      Trie* children[Alphabet_count];
Node* root;

  Trie() {
root = new Node();
  //  cout << "hyr";
    root->isEndOfWord = false;
      for(unsigned i=0;i<Alphabet_count;i++){
      root->children[i]=NULL;

      }
  }

  Node* getNode(){

      Node* new_node = new Node();
      new_node->isEndOfWord = false;
      for(unsigned i=0;i<Alphabet_count;i++){
          new_node->children[i]=NULL;

      }
      return new_node;
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
//root = getNode();
 Node* temp = root;
     for(unsigned i=0;i<word.length();i++){
         int index = word[i] - 'a';
         if(temp->children[index] == NULL){
            temp->children[index] = getNode();
         }
         temp = temp->children[index];
     }
      temp->isEndOfWord = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
  //  root = getNode();
  if(root==NULL){
    return false;
  }
    Node* temp = root;
  for(int i=0;i<word.length();i++){
  int index = word[i] - 'a';
  if(temp->children[index]==NULL){
    return false;
  }
  temp = temp->children[index];
  }
  if(temp->isEndOfWord==true){
  return true;
}
else{
  return false;
}


  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    if(root==NULL){
      return false;
    }
    Node* temp = root;
  for(int i=0;i<prefix.length();i++){
  int index = prefix[i] - 'a';
  if(temp->children[index]==NULL){
    return false;
  }
  temp = temp->children[index];
  }
  return true;
  }

};

/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/
