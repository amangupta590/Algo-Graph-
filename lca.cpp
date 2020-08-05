class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        if(root->val==p->val or root->val==q->val){
            return root;
        }
        TreeNode* leftans=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans=lowestCommonAncestor(root->right,p,q);
        if(leftans!=NULL and rightans!=NULL)
            return root;
        if(leftans!=NULL)
            return leftans;
        return rightans;        
    }
};