class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        stack<pair<int,int>> st;
         for(int i=0;i<heights.size();i++){
            int start = i;
            while(!st.empty() &&st.top().second > heights[i] ){
                int index = st.top().first;
                int height = st.top().second;
                maxi = max(maxi,(i-index)*height );
                st.pop();
                start=index;
            }
            st.push({start,heights[i]});
            maxi = max(maxi,heights[i]);
         }
            while(!st.empty()){
                int s_index = st.top().first;
                int height = st.top().second;
                maxi = max(maxi, ((int)heights.size() - s_index) * height);
                st.pop();
            }
            return maxi;
    };
};
