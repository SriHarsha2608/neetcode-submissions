class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevSmaller(n), nextSmaller(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(!st.empty()) prevSmaller[i] = st.top();
            else prevSmaller[i] = -1;

            st.push(i);
        }

        st = stack<int>();

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(!st.empty()) nextSmaller[i] = st.top();
            else nextSmaller[i] = n;

            st.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int area = heights[i] * (nextSmaller[i] - prevSmaller[i] - 1);
            ans = max(ans, area);
        }

        return ans;
    }
};
