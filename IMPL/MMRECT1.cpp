#include <stdio.h>
#include <stdlib.h>

const int MAX_COORD = 100;
const int INVALID_POS = 100000;

typedef struct {
	int x, y;
} Coord;

Coord invalidCoord = { INVALID_POS, INVALID_POS };

int N;
Coord coords[MAX_COORD];

bool isEqual(Coord c1, Coord c2) 
{
	return (c1.x == c2.x && c1.y == c2.y);
}

bool isExist(int x, int y) 
{
	for(int i=0; i<N; i++) {
		if (coords[i].x == x && coords[i].y == y)
			return true;
	}

	return false;
}

Coord findY(Coord c, int from)
{
	for(int i=from; i<N; i++) {
		if (isEqual(c, coords[i])) 
			continue;
		if (c.x == coords[i].x && c.y != coords[i].y)
			return coords[i];
	}

	return invalidCoord;
}

Coord findXWithDist(Coord c, int from, int distance)
{
	for(int i=from; i<N; i++) {
		if (isEqual(c, coords[i])) 
			continue;
		if (c.x != coords[i].x && c.y == coords[i].y && abs(coords[i].x - c.x) == distance)
			return coords[i];
	}

	return invalidCoord;
}

void solve() 
{
	int minDist = INVALID_POS, maxDist = 0;

	for(int i=0; i<N; i++) {
		Coord coord = coords[i];
		for(int j=0; j<N; j++) {
			Coord y = findY(coord, j);
			if (isEqual(y, invalidCoord)) break;

			int distance = abs(y.y - coord.y);
			Coord x = findXWithDist(coord, j, distance);
			if (isEqual(x, invalidCoord)) break;

			if (isExist(x.x, y.y)) {
				minDist = minDist < distance ? minDist : distance;
				maxDist = maxDist > distance ? maxDist : distance;
			}
		}
	}

	printf("%d %d\n", minDist, maxDist);
}

int main(int argc, char const *argv[])
{
	int T;
	
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i=0; i<N; i++) {
			scanf("%d %d", &coords[i].x, &coords[i].y);
		}
		solve();
	}
	return 0;
}
