#ifndef __SOURCE_H_INCLUDED__   
#define __SOURCE_H_INCLUDED__


#include <vector>
#include "Graph.h"
#include <iostream>
#include <queue>

using namespace std;

vector<string> breathFirstTraversal(Graph &graph)
{
	vector<string> result;
	for (int i = 0; i < graph.numberOfVertices; ++i)
	{
		graph.vertices[i].color = false;
		graph.vertices[i].setDistance(graph.infinite);
		graph.vertices[i].setParent(nullptr);
	}
	graph.start_Vertex->color = true;
	graph.start_Vertex->setDistance(0);

	queue<Vertex*> queueBFT;
	queueBFT.push(graph.start_Vertex);

	while (!queueBFT.empty())
	{
		Vertex* u = queueBFT.front();
		queueBFT.pop();
		result.push_back(u->getName());

		for (Edge& neigthborEdge : u->getEdges())
		{
			Vertex* neigthborVertex = neigthborEdge.getDestination();
			if (neigthborVertex->color == false)
			{
				neigthborVertex->color = true;
				neigthborVertex->setDistance(u->getDistance() + 1);
				neigthborVertex->setParent(u);
				queueBFT.push(neigthborVertex);
			}
		}
	}
	cout << "Szelessegi bejaras: ";
	copy(result.begin(), result.end(), ostream_iterator<string>(cout, " "));
	cout << "\n";
	return result;
}

vector<vector<int> > dijkstra(Graph &graph){

	vector<int> d;
	vector<int> p;
	int infinity = std::numeric_limits<int>::max();
	for (int i = 0; i < graph.numberOfVertices; i++){
		d.push_back(infinity);
		p.push_back(-1);
	}

	int start_point = graph.findVertexIndex(graph.start_Vertex->getName());
	d[start_point] = 0;


	for (int i = 0; i < graph.numberOfVertices; i++){
		int min = infinity;
		int min_place = 0;
		for (int i = 0; i < d.size(); i++){
			if (d[i] < min && graph.vertices[i].color == false){
				min = d[i];
				min_place = i;
			}
		}
		Vertex vertex = graph.vertices[min_place];

		for (int j = 0; j < vertex.getEdges().size(); j++){

			if (d[graph.findVertexIndex(vertex.getEdges()[j].getDestination()->getName())] > d[min_place] + vertex.getEdges()[j].getDistance()){
				d[graph.findVertexIndex(vertex.getEdges()[j].getDestination()->getName())] = d[min_place] + vertex.getEdges()[j].getDistance();
				p[graph.findVertexIndex(vertex.getEdges()[j].getDestination()->getName())] = min_place;
			}
		}
		graph.vertices[min_place].color = true;
	}

	vector<vector<int> > result;
	result.push_back(d);
	result.push_back(p);

	cout << "Dijkstra: \n";
	cout << "distance: \n";

	copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));
	cout << "\n";

	cout << "parent: \n";
	copy(p.begin(), p.end(), ostream_iterator<int>(cout, " "));
	cout << "\n";
	cout << "\n";
	cout << "\n";


	return result;
}

vector<vector<int> > bellman_ford(Graph &graph){
	vector<int> d;
	vector<int> p;


	int infinity = std::numeric_limits<int>::max();
	for (int i = 0; i < graph.numberOfVertices; i++){
		d.push_back(infinity);
		p.push_back(-1);
	}

	int start_point = graph.findVertexIndex(graph.start_Vertex->getName());
	d[start_point] = 0;
	bool okke = false;
	for (int i = 0; i < graph.numberOfVertices - 1 && !okke; i++){
		for (int j = 0; j < graph.numberOfVertices; j++){
			Vertex vertex = graph.vertices[j];
			int index = (j + graph.findVertexIndex(graph.start_Vertex->getName())) % graph.numberOfVertices;
			for (int k = 0; k < vertex.getEdges().size(); k++){
				if (d[graph.findVertexIndex(vertex.getEdges()[k].getDestination()->getName())] > d[index] + vertex.getEdges()[k].getDistance()
					&& d[index] != infinity){
					d[graph.findVertexIndex(vertex.getEdges()[k].getDestination()->getName())] = d[index] + vertex.getEdges()[k].getDistance();
					p[graph.findVertexIndex(vertex.getEdges()[k].getDestination()->getName())] = index;
				}
			}
		}
	}
	vector<vector<int> > result;
	result.push_back(d);
	result.push_back(p);

	cout << "Bellman: \n";
	cout << "distance: \n";

	copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));
	cout << "\n";

	cout << "parent: \n";
	copy(p.begin(), p.end(), ostream_iterator<int>(cout, " "));
	cout << "\n";
	cout << "\n";
	cout << "\n";

	return result;
}


#endif