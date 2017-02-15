#include "World.h"

void swap(MedianFilter* o, int p, int k) {
	int tmp;

	tmp = o->distance[p];
	o->distance[p] = o->distance[k];
	o->distance[k] = tmp;

	int tp = o->index[p];
	int tk = o->index[k];

	o->index[p] = tk;
	o->index[k] = tp;

	tmp = o->position[tp];
	o->position[tp] = o->position[tk];
	o->position[tk] = tmp;
}

void update(World* w, Direction direction, int distance) {
	MedianFilter* o = &(w->dir[direction]);

	int p = o->position[o->last];  // insertion point
	o->distance[p] = distance;
	if (p < HISTORY - 1 && distance > o->distance[p + 1]) {
		while (p < HISTORY - 1 && distance > o->distance[p + 1]) {
			swap(o, p, p + 1);
		}
	}
	if (p > 0 && distance < o->distance[p - 1]) {
		while (p > 0 && distance < o->distance[p - 1]) {
			swap(o, p, p - 1);
		}
	}
	o->last = (o->last + 1) % HISTORY;
}

int getDistance(World* w, Direction direction) {
	return w->dir[direction].distance[HISTORY / 2];
}

