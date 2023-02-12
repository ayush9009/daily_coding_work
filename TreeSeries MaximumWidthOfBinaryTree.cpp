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
class Solution
{
public:
    // bahatreen question on width of binary tree
    // approach har nodes pai indexing kar do 2*2+1,2*2+2 vale concept se lakin ye skew tree kai case mai overflow
    // ho sake result vo na ho isliye ye minimum vala concept use kiya yani
    // us node jo hai - minimum value at that level i.e node-min(min value at that nodw)
    // ye (8,1) mai jo 1 hai vo node-min vale concept se nikla
    // ab man ek level pai do nodes (8,1) and (2,4) last=4 and first=1

    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root,
                0});
        while (!q.empty())
        {
            int size = q.size();
            int curMin = q.front().second;
            int leftMost, rightMost;
            for (int i = 0; i < size; i++)
            {
                int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
                TreeNode *temp = q.front().first;
                q.pop();
                if (i == 0)
                    leftMost = cur_id;
                if (i == size - 1)
                    rightMost = cur_id;
                if (temp->left)
                    q.push({temp->left,
                            (long long)cur_id * 2 + 1});
                if (temp->right)
                    q.push({temp->right,
                            (long long)cur_id * 2 + 2});
            }
            ans = max(ans, rightMost - leftMost + 1);
        }
        return ans;
    }
};
