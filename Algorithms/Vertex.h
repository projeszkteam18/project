#ifndef __VERTEX_H_INCLUDED__   
#define __VERTEX_H_INCLUDED__ 

#include <vector>
#include "Edge.h"
using namespace std;
class Edge;
class Vertex
{
public:
	Vertex() {}
	Vertex(string id)
	{
		name = id;
		color = false;
		distance = 0;
		parent = nullptr;
	}
	void addEdge(Vertex *v, int dist)
	{
		Edge newEdge(this, v, dist);
		edges.push_back(newEdge);
	}

	string getName() { return name; }
	Vertex* getParent() { return parent; }
	void setParent(Vertex*v){ parent = v; }
	int getDistance(){ return distance; }
	void setDistance(int dist){ distance = dist; }
	vector<Edge> getEdges() { return edges; }
private:
	string name;
	int distance;
	vector<Edge> edges;
	Vertex*parent;
public:
	bool color; //rdy - not rdy
};
#endif 