const int alphabet_size = 26;

class TrieNode {
public:
    TrieNode* children[alphabet_size];
    bool terminal;
    TrieNode() {
        for (int i = 0; i < alphabet_size; i++) {
            children[i] = NULL;
        }
        terminal = false;
    }
};

class Trie {
private:
    TrieNode* root; // Make root a member variable

public:
    Trie() {
        root = new TrieNode(); // Properly initialize the root member variable
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (curr->children[index] == NULL) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->terminal = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (curr->children[index] == NULL) {
                return false;
            }
            curr = curr->children[index];
        }
        return curr != NULL && curr->terminal;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (curr->children[index] == NULL) {
                return false;
            }
            curr = curr->children[index];
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
