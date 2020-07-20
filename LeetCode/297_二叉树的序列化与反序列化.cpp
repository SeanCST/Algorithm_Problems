/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) {
            return "[]";
        }
        queue<TreeNode* > q;
        q.push(root);
        string res = "[";
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if(node != NULL) {
                q.push(node->left);
                q.push(node->right);

                res += to_string(node->val);
            } else {
                res += "null";
            }
            res += ",";
        }

        res[res.length() - 1] = ']';
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "[]" || data.length() == 0) {
            return NULL;
        }
        
        int len = data.length();
        int i = 1, j = 1;
        vector<TreeNode *> vec;
        while(i < len) {
            if(data[j] == ',' || data[j] == ']') {
                string curStr = data.substr(i, j - i);
                TreeNode *curNode = NULL;
                if(curStr != "null") {
                    curNode = new TreeNode(stoi(curStr));
                }
                vec.push_back(curNode);
                i = j + 1;
            }
            j++;
        }

        TreeNode *root = vec[0];
        queue<TreeNode *> q;
        q.push(root);
        i = 1;
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if(node == NULL) {
                continue;
            } else {
                q.push(vec[i]);
                q.push(vec[i + 1]);
                node->left = vec[i];
                node->right = vec[i + 1];
                i += 2;
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));