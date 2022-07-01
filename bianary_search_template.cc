#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// Is blue
int binary_search(vector<int>& nums, int target)
{
	if (nums.size() <= 1) 
	{
		if (nums.size() == 0) return -1;
		return nums[0] == target ? 0 : -1;
	}

	int left = -1, right = nums.size();

	while (left + 1 != right)
	{
		auto mid = (left + right) / 2;
		if (nums[mid] <= target) {
			left = mid;
		} else {
			right = mid;
		}
	}

	if (left < nums.size() && left >= 0 && target <= nums[left]) return left;
	
	if (right < nums.size() && right >= 0 && target < nums[right]) return right;
	return -1;

}
