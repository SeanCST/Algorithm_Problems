/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void handle(Node* &last, Node* &cur, Node* &nextStart) {
        if(last) {
            last->next = cur;
        }
        last = cur;
        if(!nextStart) {
            nextStart = cur;
        }
    }

    Node* connect(Node* root) {
        if(root == NULL) {
            return root;
        }

        Node *start = root;
        while(start != NULL) {
            Node *nextStart = NULL, *last = NULL;
            for(Node *cur = start; cur != NULL; cur = cur->next) {
                if(cur->left) {
                    handle(last, cur->left, nextStart);
                }
                if(cur->right) {
                    handle(last, cur->right, nextStart);
                }
            }
            start = nextStart;
        }

        return root;
    }
};