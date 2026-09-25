class Solution {
public:
    set<string> solve(string &s, int &i) {
        set<string> ans, cur;
        cur.insert("");

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                // Union
                for (auto x : cur)
                    ans.insert(x);

                cur.clear();
                cur.insert("");
                i++;
            }

            else if (s[i] == '{') {
                i++; // skip {

                set<string> temp = solve(s, i);

                i++; // skip }

                // Concatenation
                set<string> next;

                for (auto a : cur) {
                    for (auto b : temp) {
                        next.insert(a + b);
                    }
                }

                cur = next;
            }

            else {
                // Single character
                set<string> next;

                for (auto x : cur) {
                    next.insert(x + s[i]);
                }

                cur = next;
                i++;
            }
        }

        // Add last part
        for (auto x : cur)
            ans.insert(x);

        return ans;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna