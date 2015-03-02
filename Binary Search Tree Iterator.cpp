#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator{
private:
    TreeNode* treeRoot;
    stack<TreeNode*> rootStack;
    bool firstTime = true;
public:
    BSTIterator(TreeNode* root){
        treeRoot = root;
        while(root != NULL){
            rootStack.push(root);
            root = root->left;
        }
    }

    bool hasNext(){
        if(rootStack.empty()) return false;
        return true;
    }

    int next(){
        TreeNode* np = rootStack.top();
        int result = np->val;
        rootStack.pop();
        if(np->right != NULL){
            np = np->right;
            while(np != NULL){
                rootStack.push(np);
                np = np->left;
            }
        }
        return result;
    }
};
int main()
{
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    BSTIterator i = BSTIterator(root);
    while(i.hasNext()) cout << i.next() << endl;
    cout << "Hello world!" << endl;
    return 0;
}
