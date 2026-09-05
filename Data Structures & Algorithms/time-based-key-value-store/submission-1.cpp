class TimeMap {
public:
unordered_map<string, vector<pair<int, string>>> timeMap;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
    timeMap[key].push_back({timestamp, value});        
    }
    
    string get(string key, int timestamp) {
        int low =0;
        int high = timeMap[key].size()-1;
        string ans = "";

        while(low<=high){
            int mid = (low + high)/2;
            int time = timeMap[key][mid].first;
            string value = timeMap[key][mid].second;

            if(time<= timestamp){
                ans = value;
                low = mid +1;
            }
            else{
                high = mid -1;
            }
        } 
        return ans;
    }
};
