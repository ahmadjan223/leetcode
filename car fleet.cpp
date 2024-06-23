class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> car;
        stack<double> st;
        for(int i=0;i<position.size();i++){
            car.push_back({position[i],speed[i]});
        }
        sort(car.begin(),car.end(),greater<>());
        for(int i=0;i<car.size();i++){
             double time = static_cast<double>(target - car[i].first) / car[i].second;
                cout<<time;
            if(st.empty() || time > st.top()){
                st.push(time);
            }
        }
        return st.size();
        
    }
};
