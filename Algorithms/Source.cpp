#include <vector>
#include <iostream>
#include <string>
#include <fstream> 
#include <limits>
#include <queue>
#include "Graph.h"
#include "Edge.h"
#include <algorithm>

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
	return result;
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