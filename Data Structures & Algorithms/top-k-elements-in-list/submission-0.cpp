/**
 * SOLUTION: group the elements into buckets and then sort them based on the buckets
 * 				@param hashmap{elem: freq}
 * 				@param array[N] 
 * 				@param N: int -> number of elements in the input array
 */


 struct Node{
	int val;
	Node* next;
	Node(){val = -1; next=nullptr;}
	Node(int val){this->val = val; next=nullptr;}
	Node(int val, Node* next){this->val = val; this->next = next;}
 };

 #define BUCKETS vector<Node*>

class Solution {
public:

	void dealloc_buckets(BUCKETS buckets){
		for(auto it = buckets.begin(); it != buckets.end(); ++it){
			if(*it == nullptr) continue;
			Node* current = *it;
			while(current != nullptr){
				Node* next = current->next;
				delete current;
				current = next;
			}
		}
	}

    vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> mp;
		const size_t N = nums.size();
		BUCKETS buckets(N+1, nullptr);

		// add the elements with their freq in the hashmap
		for(int num: nums){
			if(mp.contains(num)){
				mp.at(num)++;
			}else{
				mp.insert({num, 1});
			}
		}

		// iterate through the array and insert the elements in the buckets
		for(auto pairing: mp){
			int elem = pairing.first, freq = pairing.second;
			// insert in an empty nucket
			if(buckets.at(freq) == nullptr){
				Node* n = new Node(elem);
				buckets.at(freq) = n;
			}else{
				// traverse the bucket
				Node* current = buckets.at(freq);
				while(current->next != nullptr){
					current = current->next;
				}
				Node* n = new Node(elem);
				current->next = n;
			}
		}
		vector<int> elems;
		// select the first k elements from buckets in reverse order form N to 1 
		for(auto it = buckets.rbegin(); it != buckets.rend() && elems.size() < k; it++){
			Node* current = *it;
			// guard on the null elem
			if(current == nullptr) continue;
			// add the current elements until nullptr
			while(current != nullptr && elems.size() < k){
				elems.push_back(current->val);
				current = current->next;
			}
		}

		// deallocate the memory from the buckets
		this->dealloc_buckets(buckets);
		return elems;
    }
};