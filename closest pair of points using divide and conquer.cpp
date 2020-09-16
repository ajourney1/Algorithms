#include<bits/stdc++.h>
using namespace std;


vector<pair<int,int>> point;

struct op
{
    bool operator()(const pair<int,int> &a , const pair<int,int> &b) const
    {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
};

long double distance(pair<int,int> &a , pair<int,int> &b)
{
    long double foo = b.second - a.second; foo = foo * foo;
    long double res = b.first - a.first; res = res * res;
    long double sum = foo + res;
    sum = sqrt(sum);
    return sum;
}

long double brute(vector<pair<int,int>> &point , int n)
{
    long double minn = FLT_MAX;
    for(int i = 0 ; i < n ; ++i){
        for(int j = i + 1;  j < n ; ++j){
            if(distance(point[i] , point[j]) < minn) minn = distance(point[i] , point[j]);
        }
    }
    return minn ;
}

long double min(long double a , long double b)
{
    if(a <= b) return a;
    return b;
}




struct comp
{
    bool operator()(const pair<int,int> &a , const pair<int,int> &b) const
    {
        return a.second < b.second;
    }
};

long double closestsplitpoints(vector<pair<int,int>> strip , int size , long double delta)
{
    sort(strip.begin() , strip.end() , comp());
    long double minn = delta;
    for(int i = 0 ; i < size ; ++i){
        for(int j = i + 1 ; j < size && (strip[j].second - strip[i].second) < minn; ++j){
            if(distance(strip[i] , strip[j]) < minn){
                minn = distance(strip[i] , strip[j]);
            }
        }
    }
    return minn;
}

long double solve(vector<pair<int,int>> point , int n)
{
    if(n <= 3) return brute(point , n);
    int mid = n / 2 ;
    pair<int,int> midpoint = point[mid];
    vector<pair<int,int>> pointsleft , pointsright;
    for(int i = 0; i <= mid ; ++i) pointsleft.push_back({point[i].first , point[i].second});
    for(int i = mid + 1 ; i < n ; ++i) pointsright.push_back({point[i].first , point[i].second});
    long double distance_left = solve(pointsleft , mid);
    long double distance_right = solve(pointsright , n - mid);
    long double delta = min(distance_left , distance_right);
    vector<pair<int,int>> strip;
    for(int i = 0 ; i < n ; ++i){
        if(abs(point[i].first - midpoint.first) < delta){
            strip.push_back(point[i]);
        }
    }
    return min(delta , closestsplitpoints(strip , int(strip.size()) , delta));

}

int main()
{
    int n ;
    cin >> n ;
    for(int i = 1;  i <= n ; ++i){
        int x , y;
        cin >> x >> y;
        point.push_back({x,y});
    }
    sort(point.begin() , point.end(), op());
    cout << solve(point , n) ;
    return 0;
}
