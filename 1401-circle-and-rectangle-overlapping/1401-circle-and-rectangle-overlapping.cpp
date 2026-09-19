class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {
        
        // Closest point in rectangle to circle center
        int x = max(x1, min(xCenter, x2));
        int y = max(y1, min(yCenter, y2));

        // Distance squared between center and closest point
        int dx = xCenter - x;
        int dy = yCenter - y;

        return dx * dx + dy * dy <= radius * radius;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna