#include<bits/stdc++.h>
using namespace std;


struct op
{
    bool operator()(const pair<int,int> &a , const pair<int,int> &b) const
    {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
};


int findcrossproduct(pair<int,int> a , pair<int,int> b , pair<int,int> c)
{
    int y1 = a.second - b.second;
    int y2 = a.second - c.second;
    int x1 = a.first - b.first;
    int x2 = a.first - c.first;
    return y2*x1 - y1*x2;
}


bool distance(pair<int,int> a , pair<int,int> b , pair<int,int> c)
{
    int y1 = a.second - b.second ;
    int y2 = a.second - c.second ;
    int x1 = a.first - b.first;
    int x2 = a.first - c.first;
    return y1*y1+x1*x1 > y2*y2 + x2*x2;
}

void findconvexhull(vector<pair<int,int>> &point)
{
    pair<int,int> start = point[0];
    for(int i = 1 ; i < int(point.size()) ; ++i){
        if(point[i].first < start.first){
            start = point[i];
        }
    }
    pair<int,int> current = start;
    set<pair<int,int>> result;
    result.insert(start);
    vector<pair<int,int>> collinearpoints;
    while(true){
        pair<int,int> nexttarget = point[0];
        for(int i = 1 ; i < int(point.size()) ; ++i){
            if(point[i] == current) continue;
            int crossproduct = findcrossproduct(current , nexttarget , point[i]);
            if(crossproduct > 0){
                nexttarget = point[i];
                collinearpoints.clear();
            }
            else if(crossproduct == 0){
                if(!distance(current , nexttarget , point[i])){
                    collinearpoints.push_back(nexttarget);
                    nexttarget = point[i];
                }
                else{
                    collinearpoints.push_back(point[i]);
                }
            }
            else{
                // do nothing
            }
        }
        for(auto x : collinearpoints){
            result.insert(x);
        }
        if(nexttarget == start){
            break;
        }
        result.insert(nexttarget);
        current = nexttarget;
    }
    cout << " hull is " << endl ;
    for(auto x : result) cout << x.first << " " << x.second << endl ;
    return ;
}

int main()
{
    vector<pair<int,int>> point;
    int n ;
    cin >> n ;
    for(int i = 1 ; i <= n ; ++i){
        int x , y;
        cin >> x >> y ;
        point.push_back({x ,y});
    }
    findconvexhull(point);
}





























