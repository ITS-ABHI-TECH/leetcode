class Solution {

    public String shortestPalindrome(String s) {

        String rev = new StringBuilder(s).reverse().toString();

        String temp = s + "#" + rev;

        int[] lps = new int[temp.length()];

        int len = 0;
        int i = 1;

        while (i < temp.length()) {

            if (temp.charAt(i) == temp.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            }

            else {

                if (len != 0) {
                    len = lps[len - 1];
                }

                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int longestPalindrome = lps[temp.length() - 1];

        return rev.substring(0, s.length() - longestPalindrome) + s;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna