class Solution {
public:

    void solve(string s, vector<string>& ans, int open, int close, int n) {

        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // Add '('
        if (open < n) {
            s.push_back('(');
            solve(s, ans, open + 1, close, n);
            s.pop_back();   // backtrack
        }

        // Add ')'
        if (close < open) {
            s.push_back(')');
            solve(s, ans, open, close + 1, n);
            s.pop_back();   // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        solve("", ans, 0, 0, n);

        return ans;
    }
};