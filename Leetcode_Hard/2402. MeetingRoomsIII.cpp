class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end());
        vector<int> roomCnt(n, 0);
        priority_queue<pair<long long, int>,  vector<pair<long long, int>>, greater<pair<long long, int>>> usedRooms;
        priority_queue<int, vector<int>, greater<int>> avlRooms;
        for(int i = 0; i < n; ++i) avlRooms.push(i);
        for(int i = 0; i < m; ++i){
            int stime = meetings[i][0], etime = meetings[i][1];
            while(!usedRooms.empty() && usedRooms.top().first <= stime){
                int room = usedRooms.top().second;
                usedRooms.pop();
                avlRooms.push(room);
            }
            if(!avlRooms.empty()){
                int room = avlRooms.top();
                avlRooms.pop();
                usedRooms.push({etime, room});
                roomCnt[room]++;
            }else{
                int room = usedRooms.top().second;
                long long endTime = usedRooms.top().first;
                usedRooms.pop();
                usedRooms.push({endTime + etime - stime, room});
                roomCnt[room]++;
            }
        }
        int ans = -1, maxi = 0;
        for(int i = 0; i < n; ++i){
            if(roomCnt[i] > maxi){
                maxi = roomCnt[i];
                ans = i;
            }
        }
        return ans;
    }
};
