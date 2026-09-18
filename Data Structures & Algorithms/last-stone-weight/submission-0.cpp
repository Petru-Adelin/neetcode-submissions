class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
		// complexity already O(n*logn)
		for(int stone: stones)
			pq.push(stone);

		while(pq.size() > 1){
			int x = pq.top();
			pq.pop();
			int y = pq.top();
			pq.pop();
			if(x == y)
				continue;
			else {
				int diff = abs(x - y);
				pq.push(diff);
			}
		}
		if(pq.size() == 1)
			return pq.top();
		else 
			return 0;
    }
};