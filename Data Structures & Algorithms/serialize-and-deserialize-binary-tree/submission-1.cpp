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
        if(root==NULL){
            return "null";
        }
        queue<TreeNode*> pq;
        pq.push(root);
        string result = "";

        while(!pq.empty()){
            TreeNode* node = pq.front();
            pq.pop();

            if(node == NULL){
                result += "null,";
            }
            else{
                result += to_string(node->val)+ ",";
                pq.push(node->left);
                pq.push(node->right);
            }
        }
        result.pop_back();  
        return result;
    }

    TreeNode* deserialize(string data) {
        if(data=="null" || data.empty()){
            return NULL;
        }
        vector<string>node;
        string temp="";

        for(int i=0; i<=data.size(); i++) { 
            if(i==data.size() || data[i]==',') {
                node.push_back(temp);
                temp = ""; 
            } else {
                temp += data[i];
            }
        }
        TreeNode* root = new TreeNode(stoi(node[0]));
        queue<TreeNode*> pq;
        pq.push(root);

        int idx=1;
        while(!pq.empty()){
            TreeNode* cur = pq.front();
            pq.pop();

            if(idx<node.size() && node[idx] != "null"){
                cur->left = new TreeNode(stoi(node[idx]));
                pq.push(cur->left);
            }
            idx++;

            if(idx<node.size() && node[idx] != "null"){
                cur->right = new TreeNode(stoi(node[idx]));
                pq.push(cur->right);
            }
            idx++;
        }
        return root;
    }
};