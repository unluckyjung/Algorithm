class TrieNode {
public:
    bool is_word;
    TrieNode* children[26];

    TrieNode() {
        is_word = false;

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }

    void insert(string word) {
        int k = 0;
        TrieNode* cur = root;

        for (int i = 0; i < word.size(); i++)
        {
            k = word[i] - 'a';
            if (cur->children[k] == NULL) cur->children[k] = new TrieNode();
            cur = cur->children[k];
        }
        cur->is_word = true;
    }

    bool search(string word) {
        int k = 0;
        TrieNode* cur = root;

        for (int i = 0; i < word.size(); i++)
        {
            k = word[i] - 'a';
            cur = cur->children[k];
            if (cur == NULL) return false;
        }
        return cur->is_word;
    }


    bool startsWith(string prefix) {
        int k = 0;
        TrieNode* cur = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            k = prefix[i] - 'a';
            cur = cur->children[k];
            if (cur == NULL) return false;
        }
        return true;
    }

private:
    TrieNode* root;
};