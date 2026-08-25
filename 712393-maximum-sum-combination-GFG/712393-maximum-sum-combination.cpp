class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>> st;
        int n =a.size();
        pq.push({a[0]+b[0],{0,0}});
        st.insert({0,0});
        vector<int> ans;
        while(k--){
            auto ele = pq.top();
            pq.pop();
            int sum = ele.first;
            int i=ele.second.first;
            int j=ele.second.second;
            ans.push_back(sum);
            if(i+1<n && st.find({i+1,j})==st.end()){
                pq.push({a[i+1]+b[j],{i+1,j}});
                st.insert({i+1,j});
            }
            if(j+1<n && st.find({i,j+1})==st.end()){
                pq.push({a[i]+b[j+1],{i,j+1}});
                st.insert({i,j+1});
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna