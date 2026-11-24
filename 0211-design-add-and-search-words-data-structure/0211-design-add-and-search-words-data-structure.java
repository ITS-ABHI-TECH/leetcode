class WordDictionary {

    class Node {
        Node[] children = new Node[26];
        boolean isEnd = false;
    }

    Node root;

    public WordDictionary() {
        root = new Node();
    }

    public void addWord(String word) {

        Node curr = root;

        for (char ch : word.toCharArray()) {

            int index = ch - 'a';

            if (curr.children[index] == null) {
                curr.children[index] = new Node();
            }

            curr = curr.children[index];
        }

        curr.isEnd = true;
    }

    public boolean search(String word) {
        return dfs(word, 0, root);
    }

    private boolean dfs(String word, int pos, Node curr) {

        // Entire word has been processed
        if (pos == word.length()) {
            return curr.isEnd;
        }

        char ch = word.charAt(pos);

        // Wildcard: try every possible character
        if (ch == '.') {

            for (Node child : curr.children) {

                if (child != null &&
                    dfs(word, pos + 1, child)) {

                    return true;
                }
            }

            return false;
        }

        // Normal character
        int index = ch - 'a';

        if (curr.children[index] == null) {
            return false;
        }

        return dfs(word, pos + 1, curr.children[index]);
    }
}
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna