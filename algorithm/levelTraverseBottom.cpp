
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

vector<vector<int> > levelOrderButtom(TreeNode *root) {  
  vector<vector<int> > ret;
  if(NULL == root)
    return ret;
  
  deque<TreeNode*> d;
  vector<int> tmp;
  int n = 1, k = 0;
  
  d.push_back(root);
  while(!d.empty()){
    for(int i = 0; i < n; ++i){
      TreeNode* pNode = d.front();
      d.pop_front();
      tmp.push_back(pNode->val);

      if(pNode->left){
	d.push_back(pNode->left);
	++k;
      }
      if(pNode->right){
	d.push_back(pNode->right);
	++k;
      }
    }

    n = k; 
    k = 0;
    
    ret.push_back(tmp);
    tmp.clear();
  }

  reverse(ret.begin(), ret.end());
  
  return ret;
}
