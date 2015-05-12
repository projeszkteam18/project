#include <vector>
#include <iostream>
#include <string>
#include <fstream> 
#include <limits>
#include <queue>
#include "Graph.h"
#include "Source.h"
#include "Edge.h"
#include <algorithm>

using namespace std;


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



int main()
{
	cout << "Melyik tesztet szerete futtatni?" << endl;
	cout << endl;
	cout << "1 - Iranyitott kormentes graf, start es vegpont kozott van ut" << endl;
	cout << "2 - Iranyitott kormentes graf, start es vegpont kozott nincs ut" << endl;
	cout << "3 - Iranyitott nem kormentes graf" << endl;
	cout << endl;
	cout << "Kerem valassszon egy szamot: ";
	bool ok = false;
	string mystring = "";
	while (ok == false)
	{
		cin >> mystring;
		if (mystring == "1" || mystring == "2" || mystring == "3") ok = true;
		else
		{
			cout << "A kovetezo szamok egyiket adja meg: 1, 2, 3." << endl;
			cout << "A választott szam: ";
		}
	}
	cout << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << endl;

	Graph g;
	int ret = g.read(mystring);
	if (ret != 0) cout << "A fájl megnyitása sikertelen" << endl;

	vector<vector<int> > result = dijkstra(g);
	vector<vector<int> > result2 = bellman_ford(g);
	cout << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << endl;
	system("PAUSE");
	return 0;
}