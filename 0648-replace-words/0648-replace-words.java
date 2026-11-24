class Solution {

    class TrieNode {
        TrieNode[] children = new TrieNode[26];
        boolean isEnd = false;
    }

    TrieNode root = new TrieNode();

    private void insert(String word) {

        TrieNode curr = root;

        for (char ch : word.toCharArray()) {

            int index = ch - 'a';

            if (curr.children[index] == null) {
                curr.children[index] = new TrieNode();
            }

            curr = curr.children[index];
        }

        curr.isEnd = true;
    }

    private String findRoot(String word) {

        TrieNode curr = root;
        StringBuilder prefix = new StringBuilder();

        for (char ch : word.toCharArray()) {

            int index = ch - 'a';

            if (curr.children[index] == null) {
                return word;
            }

            prefix.append(ch);
            curr = curr.children[index];

            // Shortest root found
            if (curr.isEnd) {
                return prefix.toString();
            }
        }

        return word;
    }

    public String replaceWords(List<String> dictionary, String sentence) {

        // Build Trie
        for (String word : dictionary) {
            insert(word);
        }

        String[] words = sentence.split(" ");
        StringBuilder answer = new StringBuilder();

        for (int i = 0; i < words.length; i++) {

            if (i > 0) {
                answer.append(" ");
            }

            answer.append(findRoot(words[i]));
        }

        return answer.toString();
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna