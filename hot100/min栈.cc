// 剑指 Offer 30. 包含min函数的栈
class MinStack {
public:

    vector<pair<int, int>> stack_;
    int min_num_;

    MinStack() {}
    
    void push(int x) {
        if (stack_.empty())
        {
            stack_.emplace_back(x, x);
            min_num_ = x;
        }
        else
        {
            min_num_ = ::min(min_num_, x);
            stack_.emplace_back(x, min_num_);
        }
    }
    
    void pop() {
        stack_.pop_back();
        if (!stack_.empty())
        {
            // Important
            min_num_ = stack_.back().second;
        }
    }
    
    int top() {
        return stack_.back().first;
    }
    
    int min() {
        return stack_.back().second;
    }
};
