class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        int first = -1;
        int last = -1;
        
        int minDist = INT_MAX;
        
        int index = 1;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while (curr->next != NULL) {
            
            // Check if curr is a critical point
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                // First critical point
                if (first == -1) {
                    first = index;
                }
                
                // We already have a previous critical point
                if (last != -1) {
                    minDist = min(minDist, index - last);
                }
                
                last = index;
            }
            
            prev = curr;
            curr = curr->next;
            index++;
        }
        
        // Fewer than 2 critical points
        if (first == last) {
            return {-1, -1};
        }
        
        int maxDist = last - first;
        
        return {minDist, maxDist};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna