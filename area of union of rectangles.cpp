
const long long mod = 1e9 + 7 ;
class Solution {
public:

    struct op
    {
        bool operator()(const pair<long long , long long > &a , const pair<long long , long long > &b) const
        {
            if(a.first == b.first) return a.second < b.second ;
            return a.first < b.first ;
        }
    };

    void merge_intervals(vector<pair<long long , long long >> &intervals)
    {
        sort(intervals.begin() , intervals.end() , op());
        stack<pair<long long , long long >> s;
        for(long long i = 0 ; i < (intervals.size()) ; ++i){
            if(s.empty() == true){
                s.push({intervals[i].first , intervals[i].second});
            }
            else{
                long long current_start = intervals[i].first;
                long long previous_end =  s.top().second;
                if(current_start <= previous_end){
                    long long previous_start = s.top().first;
                    long long current_end    = intervals[i].second ;
                    s.pop();
                    current_end = max(current_end , previous_end) ;
                    s.push({previous_start , current_end});

                }
                else{
                    s.push({intervals[i].first , intervals[i].second});
                }
            }
        }
        intervals.clear();
        while(s.empty() == false){
            intervals.push_back({s.top().first , s.top().second});
            s.pop();
        }
        return ;
    }

    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<vector<long long>> v;
        for(long long i = 0 ; i < rectangles.size() ; ++i){
            vector<long long > goo ;
            goo.push_back(rectangles[i][0]);
            goo.push_back(rectangles[i][1]);
            goo.push_back(rectangles[i][2]);
            goo.push_back(rectangles[i][3]);
            v.push_back(goo);
        }
        set<long long > y;
        long long previous_y = -1;
        for(long long i = 0 ; i < (v.size()) ; ++i){
            y.insert(v[i][1]);
            y.insert(v[i][3]);
        }
        vector<long long> yy;
        long long area=  0 ;
        for(auto x : y) yy.push_back(x);

        for(long long itr = 0 ; itr < (yy.size()) -1; ++itr){
            vector<pair<long long ,long long >> intervals;
            for(long long i = 0 ; i < (v.size()) ; ++i){
                long long minx = v[i][0];
                long long maxx = v[i][2];
                long long miny = v[i][1];
                long long maxy = v[i][3];
                if(miny >= yy[itr+1] or maxy <= yy[itr]) continue;
                else{
                    intervals.push_back({minx , maxx}) ;
                }
            }
            long long coveragesum = 0;
            merge_intervals(intervals);
            for(int i = 0 ; i < (intervals.size()) ; ++i){
                long long length = abs(intervals[i].second - intervals[i].first);
                coveragesum+=length ;
                coveragesum%=mod;
            }
            area = area + (yy[itr+1] - yy[itr])*coveragesum;
            area = area % mod ;
        }
        return area;
    }
};

