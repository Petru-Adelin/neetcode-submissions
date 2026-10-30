

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // monotonic stack used to track the smaller prev elem
        stack<int> st;
        int rect_area = -1;
        size_t n = heights.size();
        for(int i = 0; i < n; ++i){
            // if the heights[i] bigger equal then compute the Rectangular Area 
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int top = st.top();
                st.pop();

                int width = st.empty()? i : i - st.top() - 1;
                rect_area = max(rect_area, width * heights[top]);
            }
            st.push(i);
        }

        while(!st.empty()){
            int top = st.top();
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            rect_area = max(rect_area, width * heights[top]);
        }
        return rect_area;
        
    }
};