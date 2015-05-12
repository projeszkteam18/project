#ifndef __EDGE_H_INCLUDED__   
#define __EDGE_H_INCLUDED__   

class Vertex;

#include "Vertex.h"

class Edge
{
public:
	Edge(Vertex *org, Vertex *dest, int dist)
	{
		origin = org;
		destination = dest;
		distance = dist;
	}
	Vertex* getOrigin() { return origin; }
	Vertex* getDestination() { return destination; }
	int getDistance() { return distance; }
private:
	Vertex* origin;
	Vertex* destination;
	int distance;
};

#endif 