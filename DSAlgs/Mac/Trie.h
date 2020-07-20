#include <string>
#include <cstring>
using namespace std;

class Trie
{

private:
	class TrieNode;

public:
	Trie()
	{
		root = new TrieNode();
	}

	// Insert word into the trie
	// Time: O(N) where N is length of word
	// Space: O(N) since we are storing N characters
	void insert(string word)
	{
		TrieNode* node = root;
        for(char c : word){
            if(!node -> children[c - 'a']){
                node -> children[c - 'a'] = new TrieNode();
            }
            node = node -> children[c - 'a'];
        }
        node -> end = true;
	}

	// Search for a word within the trie
	// Time: O(N) where N is length of word
	// Space: O(1) if you aren't counting the fact that we had to store those N characters previously
	bool search(string word)
	{
		TrieNode* node = root;
        for(char c : word){
            if(!node -> children[c - 'a']){
                return false;
            }
            node = node -> children[c - 'a'];
        }
        return node -> end;
	}

	// Check if any word starts with prefix
	// Time: O(N) where N is length of prefix
	// Space: O(1) if you aren't counting the fact that we had to store those N characters previously
	bool anyStartWith(string prefix)
	{
		TrieNode* node = root;
        for(char c : prefix){
            if(!node -> children[c - 'a']){
                return false;
            }
            node = node -> children[c - 'a'];
        }
        
		return true;
	}

private:

	class TrieNode
	{
	public:
		bool end;
		TrieNode* children[26];

		TrieNode()
		{
			end = false;
			for(int i = 0; i < sizeof(children); i++) children[i] = nullptr;
		}
	};

	TrieNode* root;

};
