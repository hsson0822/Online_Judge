#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#define INF 2100000000
#define F first
#define S second

using namespace std;

int N, M;
int J, S;
vector<pair<int, int>> connect[101];
priority_queue<pair<int, int>, vector<pair<int, int>>> q;
int Distance[101];
int J_Distance[101]; //J -> X를 저장
int S_Distance[101]; //S -> X를 저장

void reset_distance(){
	for(int i = 1; i <= N; i++) Distance[i] = INF;
}

void Dijstra(int st){
	reset_distance();
	Distance[st] = 0;
	q.push({-Distance[st], st});
	while(!q.empty()){
		int x = q.top().S;
		int cost = -q.top().F;
		q.pop();
		if(Distance[x] < cost) continue;
		for(int i = 0; i < connect[x].size(); i++){
			int xx = connect[x][i].F;
			int n_cost = cost + connect[x][i].S;
			if(Distance[xx] > n_cost){
				Distance[xx] = n_cost;
				q.push({-Distance[xx], xx});
			}
		}
	}
}

void solve(){
	int JS_distance = INF;
	int Point = -1, J_dis = INF;
	Dijstra(J); // 지헌이부터 출발해 다른 지점까지 걸리는 비용
	for(int i = 1; i <= N; i++){
		J_Distance[i] = Distance[i]; //지헌이를 기준으로 한 값 저장
	}
	Dijstra(S); // 성하부터 출발해 다른 지점까지 걸리는 비용
	for(int i = 1; i <= N; i++){
		S_Distance[i] = Distance[i]; //성하를 기준으로 한 값 저장
	}
	for(int i = 1; i <= N; i++){
		if(i == J || i == S) continue;
		JS_distance = min(JS_distance, J_Distance[i] + S_Distance[i]); // 최소거리를 저장
	}
	for(int i = N; i >= 1; i--){
		if(i == J || i == S) continue;
		if(JS_distance != J_Distance[i] + S_Distance[i]) continue;
		if(J_Distance[i] > S_Distance[i]) continue;
		if(J_dis >= J_Distance[i]){
			J_dis = J_Distance[i];
			Point = i;
		}
	}
	cout << Point;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i <= M; i++){
		int x, y, cost;
		cin >> x >> y >> cost;
		connect[x].push_back({y, cost});
		connect[y].push_back({x, cost});
	}
	cin >> J >> S;
	solve();
	return 0;
}