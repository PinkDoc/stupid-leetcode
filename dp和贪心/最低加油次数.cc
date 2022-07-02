// lc 871

class Solution {
public:

    struct cmp {
        bool operator()(int m, int n)
        {
            return m < n;
        }
    };

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int car_pos = startFuel;

        int index_station = 0;
        priority_queue<int, vector<int>, cmp> pq;

        int cost = 0;
        
        while (car_pos < target)
        {
            while ( index_station < stations.size() && car_pos >= stations[index_station][0])
            {
                pq.push(stations[index_station][1]);
                index_station++;
            }

            if (car_pos < target && pq.empty())
            {
                break;
            }

            if (car_pos < target && !pq.empty() )
            {
                cost++;
                cout << pq.top() << endl;
                car_pos += pq.top();
                pq.pop();
            }
        }

        return car_pos >= target ? cost : -1;
    }
};


