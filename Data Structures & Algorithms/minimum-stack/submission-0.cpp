#define istack stack<int>

class MinStack {

	private: 
		istack main_stack;
		istack min_stack;

public:
    MinStack() {
		
    }
    
    void push(int val) {
        // push onto the main stack regardless
		// and only onto the min_stack if its smaller then the top()
		this->main_stack.push(val);
		if(this->min_stack.empty())
			this->min_stack.push(val);
		else{
			int min_top = this->min_stack.top();
			if(val <= min_top)
				this->min_stack.push(val);
		}
			
    }
    
    void pop() {
        // pop from the main stack and then see if the value is e
		int main_val = this->main_stack.top();
		this->main_stack.pop();
		if(main_val == this->min_stack.top())
			this->min_stack.pop();
		
    }
    
    int top() {
        return this->main_stack.top();
    }
    
    int getMin() {
        return this->min_stack.top();
    }
};