class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        int total_tasks = 0;
        for(char& task: tasks){
            int index = task - 'A';
            freq[index]++;
            total_tasks++;
        }
        // add the tasks with the freq {task, index}
        auto comp = [&](const pair<char, int >&p1, const pair<char, int>& p2){
            return freq[p1.second] < freq[p2.second];
        };
        priority_queue<pair<char, int>,vector<pair<char, int>>,decltype(comp)> pq(comp);
        for(int i = 0; i < 26; ++i){
            char task = 'A' + i;
            if(freq[i])
                pq.push({task, i});
        }

        queue<pair<char, int>> runed;
        int cycle = 0;
        while(total_tasks != 0){
            cycle++;
            if(!runed.empty()){
                // check the front with the current cycle
                auto [task, readyness] = runed.front();
                if(cycle >= readyness){
                    runed.pop();
                    int index = task - 'A';
                    pq.push({task, index});
                }
            }

            if(!pq.empty()){
                auto [task, index] = pq.top();
                pq.pop();
                freq[index]--;
                total_tasks--;
                if(freq[index])
                    runed.push({task, cycle + n + 1});
            }
            
        }
        return cycle;
    }
};