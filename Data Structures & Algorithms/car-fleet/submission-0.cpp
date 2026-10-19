using indeces = vector<int>;

/**
    * Sort the cars after position in reversed order 
    * Iterate over them and when time is bigger increment the number of fleets (cause the car will not join the fleet in front of it)
    * When incrementing the fleet number, update the last-fleet-time to take in consideration the last new fleet for future comparation
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        indeces idxs(position.size());
        std::iota(idxs.begin(), idxs.end(), 0);
        std::sort(idxs.begin(), idxs.end(), [&position](int i, int j)->bool{return position[i] > position[j];});
        vector<float> times(position.size());
        for(int i = 0; i < position.size(); ++i){
            times[i] = static_cast<float>(target - position[i]) / speed[i];
        }
        float last_fleet_time = times[idxs[0]];
        int fleet_count = 1;
        for(int i = 1; i < idxs.size(); ++i){
            int idx = idxs[i];
            if(times[idx] <= last_fleet_time){
                continue;
            }
            last_fleet_time = times[idx];
            fleet_count++;
        }
        return fleet_count;
    }
};
