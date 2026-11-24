import java.util.*;

class Solution {

    class TrieNode {
        TrieNode[] children = new TrieNode[26];
        List<String> suggestions = new ArrayList<>();
    }

    TrieNode root = new TrieNode();

    private void insert(String product) {

        TrieNode curr = root;

        for (char ch : product.toCharArray()) {

            int index = ch - 'a';

            if (curr.children[index] == null) {
                curr.children[index] = new TrieNode();
            }

            curr = curr.children[index];

            // Store only 3 suggestions
            if (curr.suggestions.size() < 3) {
                curr.suggestions.add(product);
            }
        }
    }

    public List<List<String>> suggestedProducts(
            String[] products, String searchWord) {

        // Sort products alphabetically
        Arrays.sort(products);

        // Build Trie
        for (String product : products) {
            insert(product);
        }

        List<List<String>> result = new ArrayList<>();

        TrieNode curr = root;

        for (char ch : searchWord.toCharArray()) {

            int index = ch - 'a';

            if (curr != null) {
                curr = curr.children[index];
            }

            if (curr == null) {
                result.add(new ArrayList<>());
            } else {
                result.add(curr.suggestions);
            }
        }

        return result;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna