#include <assert.h>

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

/**
 * ref: https://leetcode.com/problems/binary-tree-level-order-traversal/
 * Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
 */

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> level;
        level.push(root);
        while(!level.empty()){
            std::queue<TreeNode*> nextLevel;
            std::vector<int> levelResult;
            while(!level.empty()){
                TreeNode* node = level.front();
                level.pop();
                if(node == NULL) continue;
                levelResult.push_back(node->val);
                nextLevel.push(node->left);
                nextLevel.push(node->right);
            }
            if(levelResult.size() != 0)
                result.push_back(levelResult);
            level = nextLevel;
        }
        return result;
    }
};