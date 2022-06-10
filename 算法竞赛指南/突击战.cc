#include <iostream>
#include <untility>
#include <algorithm>
#include <vector>

using namespace std;

// 你有n个部下， 每个部下需要完成一项任务，第i个部下需要你花Bi分钟交代任务， 然后他会
// 立即独立，不间断的执行Ji分钟后完成任务， 你需要选择交待任务的顺序，
// 使得所有任务早点执行完毕。你要选择任务的顺序，使得任务早点结束

using pii = pair<int, int>;

int Solution(vector<pii>& v)
{
	
	// 很明显只和执行时间有关系，因为你分配时间是少不了的，只能靠执行时间来作异步 ：D
	auto cmp = [](pii& m, pii& n) { return m.second > n.second;}
	sort(v.begin(), v.end(), cmp);
	
	auto cost = 0;
	auto end = 0;
	
	for (auto& i : v)
	{
		cost += i.first;
		end = max(end, cost + i.second);
	}
	
	return end;
		
}

int main() 
{
		
	
}
