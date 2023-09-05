class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int s, int target) {
        if (s == target) return 0; // Check if already at the destination

        int n = routes.size();
        unordered_map<int, vector<int>> mp;

        // Create a mapping of bus stops to buses
        for (int i = 0; i < n; i++) {
            for (int stop : routes[i]) {
                mp[stop].push_back(i);
            }
        }

        queue<int> q;
        q.push(s);//is queue mai sab bustops hai

        set<int> visbus;//witth help of this we come to know which bus visited ornot
        set<int> visstop;//witth help of this we come to know which bstop visited 
        int level = 0;

        while (!q.empty()) {
            int numStops = q.size();
            while (numStops--) {
                int busStop = q.front();
                q.pop();

                vector<int> buses = mp[busStop];
// we get all the buses through which u can reach this particular bus_stop
                for (int bus : buses) {
    //   here we simply if this bus is already vis or not,means but we traverse thorugh bus once or not(1,2,3 these are stops,for bus 0 we visited all the stops so visbus[bus]=1 mean this bus is visited,all its stops covered)
                    if (visbus.find(bus) != visbus.end()) {
                        continue;
                    }


                    vector<int> busStops = routes[bus];
//  if not visited then check it all corresponding stops,and if they are not visited make them visited
                    for (int stop : busStops) {
                        if (visstop.find(stop) != visstop.end()) {
                            continue;
                        }
                        if (stop == target) {
                            return level + 1; // Found the destination
                        }
                        q.push(stop); //means if this stop not visited then make visited and push to the queue so that we covered all the stops for a particaular bus
                        visstop.insert(stop);
                    }
                    visbus.insert(bus);
                }
            }
// after this one level is complete or we can say all the stops present in queue are covered with particular bus so now we move to other stops with other bus ,if possible else we reutrn -1
            level++;
        }

        return -1; // If not possible to reach the destination
    }
};
