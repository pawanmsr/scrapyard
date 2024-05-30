#include <string>
#include <vector>

/*
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool found = obj->search(word);
 * bool found = obj->startsWith(prefix);
 */
class Trie {
public:
    Trie() {
        head = new Node('*');
    }
    
    void insert(std::string word) {
        Node* ptr = head;
        for (char &letter : word) {
            int id = letter - 'a';
            if (!ptr->child[id])
                ptr->child[id] = new Node(letter);
            
            ptr = ptr->child[id];
        }

        ptr->state = 1;
    }
    
    bool search(std::string word) {
        Node* ptr = head;
        for (char &letter : word) {
            int id = letter - 'a';
            if (!ptr->child[id]) return false;

            ptr = ptr->child[id];
        }

        if (ptr->state > 0) return true;
        return false;
    }
    
    bool starts_with(std::string prefix) {
        Node* ptr = head;
        for (char &letter : prefix) {
            int id = letter - 'a';
            if (!ptr->child[id]) return false;

            ptr = ptr->child[id];
        }

        return true;
    }

private:
    struct Node {
        char letter;
        int state;
        std::vector<Node*> child;
        Node(char c) : letter(c), state(-1), child(std::vector<Node*>(26)) {};
    };
    
    Node* head;
};
