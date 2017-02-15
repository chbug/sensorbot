#pragma once

#define HISTORY 5

enum Direction {
	DIR_E = 0,
	DIR_NE = 1,
	DIR_N = 2,
	DIR_NW = 3,
	DIR_W = 4,
	DIR_SW = 5,
	DIR_S = 6,
	DIR_SE = 7,

	DIRECTIONS = 8,
};

// Maintains the median value of a stream of distances.
struct MedianFilter {
	int last;

	int distance[HISTORY];  // ordered distances
	int index[HISTORY];     // time of distance in position p
	int position[HISTORY];  // position of distance at time t
};

// Tracks median distances in the 8 directions
struct World {
	MedianFilter dir[DIRECTIONS];
};
