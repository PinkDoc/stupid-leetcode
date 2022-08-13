class Solution {
public:
	int majorityElement(vector<int>& nums)
	{
		auto cand = 0, count = 0;
		for (auto i : nums) 
		{
			if (count == 0) 
			{
				cand = i;
				count++;	
			} 
			else
			{
				if (cand == i) count++;
				else count--;
			}
		}
		return cand;	
	}

};	
