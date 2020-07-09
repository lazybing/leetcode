/**
 * Given a n-ary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 *
 * Nary-Tree input serializatoin is represented in their level order traversal, each group of children is separated by the null value.
 */

class Solution {
    public:
        int maxDepth(Node *root) {
            int res = 0;
            queue<Node *> q;
            if (root == nullptr) return 0;
            q.push(root);

            while (!q.empty()) {
                int count = q.size();

                while (count--) {
                    Node *n = q.front();
                    q.pop();

                    for (int i = 0; i < n->children.size(); i++)
                        q.push(n->children[i]);
                }
            }

            return res;
        }
};
