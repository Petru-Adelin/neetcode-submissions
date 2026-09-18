class KthLargest {
public:
	// min priority_queue
    priority_queue<int,vector<int>, greater<int>> pq;
	vector<int> nums;
	int k;

    KthLargest(int k, vector<int>& nums): k(k), nums(nums) {
		for(int num: nums)
			this->add(num);
    }
    
    int add(int val) {
        this->nums.push_back(val);
		this->pq.push(val);
		if(this->pq.size() > this->k)
			this->pq.pop();
		return pq.top();
    }
};