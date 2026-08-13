class Solution {
    struct Node {
        int len;
        int pref;
        int suff;
        int max_len;
        char left_char;
        char right_char;
    };

    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.len = left.len + right.len;
        res.left_char = left.left_char;
        res.right_char = right.right_char;

        // Calculate Prefix
        res.pref = left.pref;
        if (left.pref == left.len && left.right_char == right.left_char) {
            res.pref += right.pref;
        }

        // Calculate Suffix
        res.suff = right.suff;
        if (right.suff == right.len && left.right_char == right.left_char) {
            res.suff += left.suff;
        }

        // Calculate Max Length (could be in left, in right, or crossing the middle)
        res.max_len = max(left.max_len, right.max_len);
        if (left.right_char == right.left_char) {
            res.max_len = max(res.max_len, left.suff + right.pref);
        }

        return res;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char c) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, c, c};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, c);
        } else {
            update(2 * node + 1, mid + 1, end, idx, c);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        tree.resize(4 * n);
        
        // Build the initial segment tree
        build(1, 0, n - 1, s);

        int k = queryCharacters.length();
        vector<int> ans(k);
        
        // Process each query
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            // The answer for the entire string is always stored at the root node (index 1)
            ans[i] = tree[1].max_len;
        }
        
        return ans;
    }
};