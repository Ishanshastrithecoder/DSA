/*
Approach 
1. initailize a undered map having a integer a value with treenode object so that both get easily mapp
2. intitialze a undered_set for the maintaining the duplicate value for the parent and child node in tree.
3. split the value of the 2d array into tree value parent, child , a flag varaible ;
4. check that the ndoe is exist in treenode .
5. Then follow main instruction in code.
6.DON'T FORGET TO  INSERT THE CHILD IN  THE  OTHER WISE THE LAST NODE VALUE WILL BE NOT DISPLAYIN IT .
7.FIND A ROOT .
*/


class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;

        for (auto &d : descriptions) {
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            // Create nodes if not exist
            if (mp.find(parent) == mp.end())
                mp[parent] = new TreeNode(parent);
            if (mp.find(child) == mp.end())
                mp[child] = new TreeNode(child);

            // Attach child
            if (isLeft == 1)
                mp[parent]->left = mp[child];
            else
                mp[parent]->right = mp[child];

            // Mark child
            children.insert(child);
        }

        // Find root (node which is never a child)
        for (auto &p : mp) {
            if (children.find(p.first) == children.end()) {
                return p.second;
            }
        }

        return NULL;
    }
};
