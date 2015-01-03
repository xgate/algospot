#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <climits>

using namespace std;

const int MAX_COORD = 20000;

int N;

bool isExist(map<int, vector<pair<int,int> > > &coordMap, int x, int y)
{
	if (coordMap.find(x) == coordMap.end()) return false;
	
	vector<pair<int,int> > v = coordMap[x];
	for(int i=0; i<v.size(); i++) 
		if (v[i].second == y) return true;

	return false;
}

int main() 
{
	int T;

	cin >> T;

	while(T--)
	{
		cin >> N;

		map<int, vector< pair<int,int> > > coordMap;
		pair<int,int> coords[MAX_COORD];

		for(int i=0; i<N; i++) {
			pair <int, int> p;
			cin >> p.first >> p.second;
			coords[i] = p;

			map<int, vector<pair<int,int> > >::iterator it = coordMap.find(p.first);
			
			if (it != coordMap.end()) {
				it->second.push_back(p);
			} else {
				vector<pair<int,int> > v;
				v.push_back(p);
				coordMap[p.first] = v;
			}
		}

		int minDist = INT_MAX, maxDist = 0;

		for (int i=0; i<N; i++) {
			pair<int,int> p = coords[i];
			vector<pair<int,int> > v = coordMap[p.first];

			for(int j=0; j<v.size(); j++) {
				
				if (v[j].second == p.second) continue;
				
				int dist = abs(v[j].second - p.second);
				
				bool result = ((isExist(coordMap, p.first - dist, p.second) && isExist(coordMap, v[j].first - dist, v[j].second)) ||
				(isExist(coordMap, p.first + dist, p.second) && isExist(coordMap, v[j].first + dist, v[j].second)));

				if (result == true) {
					minDist = dist < minDist ? dist : minDist;
					maxDist = dist > maxDist ? dist : maxDist;
				}
			}
		}

		cout << minDist << " " << maxDist << endl;
	}

	return 0;
}
