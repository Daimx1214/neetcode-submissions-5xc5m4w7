/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        string result = "";
        queue<TreeNode*> pq;
        pq.push(root);

        while(!pq.empty()){
            TreeNode* node = pq.front();
            pq.pop();
            if(node==NULL){
                result = result + "null,";
            }
            else{
                result += to_string(node->val) + ",";
                pq.push(node->left);
                pq.push(node->right);
            }
        }
        if(!result.empty()){
            result.pop_back();
        } 
        return result;
    }

    TreeNode* deserialize(string data) {
    if(data == "null" || data.empty()) return nullptr;
    
    vector<string> nodes;
    string temp;
    
    for(int i = 0; i <= data.size(); i++) {
        if(i == data.size() || data[i] == ',') {
            nodes.push_back(temp);
            temp = "";
        } else {
            temp += data[i];
        }
    }
    
    // BFS tree construction
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int idx = 1;
    
    while(!q.empty()) {
        TreeNode* cur = q.front(); 
        q.pop();
        
        // Left
        if(idx < nodes.size() && nodes[idx] != "null") {
            cur->left = new TreeNode(stoi(nodes[idx]));
            q.push(cur->left);
        }
        idx++;
        
        // Right
        if(idx < nodes.size() && nodes[idx] != "null") {
            cur->right = new TreeNode(stoi(nodes[idx]));
            q.push(cur->right);
        }
        idx++;
    }
    return root;
        
    }
};
