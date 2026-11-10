
struct Val{
    string label;
    int timestamp;

    Val(string label, int time){
        this->label = label;
        this->timestamp = time;
    }
};

class TimeMap {
public:

    
    unordered_map<string, vector<Val>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        // find the mp key inside 
        auto pointer = mp.find(key);
        if(pointer == mp.end()){
            return "";
        }
        // I need to binary search through the val vector within the map 
        // if we are not making the variable a reference then the havy coping problem propagates 
        const auto& whole_arr = pointer->second;
        int st = 0;
        int dr = whole_arr.size() - 1;
        int last_idx = -1;
        while(st <= dr){
            int mij = (st + dr) / 2;
            if(whole_arr[mij].timestamp == timestamp)
                return whole_arr[mij].label;
            if(whole_arr[mij].timestamp < timestamp ){
                last_idx = mij;
                st = mij + 1;
            }
            else 
                dr = mij - 1;
        }
        // if we reach this level r=we return the last prev_timestamp the timest that is closer to the one we are searching for 
        if(last_idx == -1)
            return "";
        else 
            return whole_arr[st-1].label;
    }
};

