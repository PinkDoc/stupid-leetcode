class MaxQueue
{
using List = std::list<int>;

List list_;
List helper_;
public:

				MaxQueue() {}

				int max_value() {
					return list_.empty() ? -1 : helper_.front();
				}	
				
				void push_back(int value) {
					list_.push_back(value);
					while (!helper_.empty() && helper_.back() <value) {
						helper_.pop_back();
					}
					helper_.push_back(value);
				
				}

				int pop_front() {
					int ret = 0;
					
					if (list_.empty()) return -1;
					
					ret = list_.front();
					list_.pop_front();
					
					if (helper_.front() == ret) helper_.pop_front();
					
					return ret;
				}	
};
