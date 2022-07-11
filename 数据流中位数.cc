struct cmp
{
    bool operator() (int m, int n)
    {
        return m > n;
    }
};

/**
	1 2 3
	4 5 6
*/
using min_queue = priority_queue<int>;
using max_queue = priority_queue<int, vector<int>, cmp>;

class MedianFinder {
public:

    min_queue min_queue_;
    max_queue max_queue_;
    size_t size_;

    MedianFinder() {}
    
    void addNum(int num) {
        max_queue_.push(num);
        min_queue_.push(max_queue_.top());
        max_queue_.pop();
        if (max_queue_.size() + 1 < min_queue_.size())
        {
            max_queue_.push(min_queue_.top());
            min_queue_.pop();
        }
        size_++;        
    }
    
    double findMedian() {
        double ret;

        if (max_queue_.size() == min_queue_.size())
        {
            return (max_queue_.top() + min_queue_.top()) / 2.0;
        }
        else if (max_queue_.size() > min_queue_.size())
        {
            return static_cast<double>(max_queue_.top());
        }
        else
        {
            return static_cast<double>(min_queue_.top());
        }
    }

};
