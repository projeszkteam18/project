
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <queue>


using namespace std;
class Vertex;
class Edge;
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
	void printEdges()
	{
		cout << name << ":" << endl;
		for (int i = 0; i < edges.size(); i++)
		{
			Edge e = edges[i];
			cout << e.getDestination()->getName() <<
				" - " << e.getDistance() << endl;
		}
		cout << endl;
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
class Graph
{
public:
	int infinite = std::numeric_limits<int>::max();
	vector<Vertex> vertices;
	int numberOfVertices;
	string start_vertex_name;
	Vertex* start_Vertex;
	vector<string> split(string str, string delim)
	{
		unsigned start = 0;
		unsigned end;
		vector<string> v;
		while ((end = str.find(delim, start)) != string::npos)
		{
			v.push_back(str.substr(start, end - start));
			start = end + delim.length();
		}
		v.push_back(str.substr(start));
		return v;
	}
	int read(string s)
	{
		vector<string> splitLine;
		string sLine = "";
		string name;
		ifstream infile;
		int line = 1;
		string path;
		switch (stoi(s))
		{
		case 1: path = "test1.txt";
			break;
		case 2: path = "test2.txt";
			break;
		case 3: path = "test3.txt";
			break;
		}
		infile.open(path.c_str());
		if (!infile.is_open()) return -1;
		while (!infile.eof())
		{
			getline(infile, sLine);
			if (line == 1)
			{
				try
				{
					numberOfVertices = stoi(sLine);
				}
				catch (exception){}
			}
			else if (line == 2)
			{
				splitLine = split(sLine, " "); // here it is
				for (int i = 0; i<numberOfVertices; i++)
				{
					vertices.push_back(Vertex(splitLine[i]));
				}
			}
			else if (line>2 && line <= (2 + numberOfVertices))
			{
				splitLine = split(sLine, " ");
				for (int i = 0; i<numberOfVertices; i++)
				{
					int temp = stoi(splitLine[i]);
					if (temp>0)
					{
						vertices[line - 3].addEdge(&vertices[i], temp);
					}
				}
			}
			else if (line == numberOfVertices + 3)
			{
				//start_vertex_name = sLine;
				start_Vertex = findVertex(sLine);
			}
			line++;
		}
		infile.close();
		return 0;
	}
	Vertex* findVertex(string name)
	{
		Vertex* v = nullptr;
		bool finished = false;
		for (int i = 0; i<numberOfVertices && !finished; i++)
		{
			if (vertices[i].getName() == name)
			{
				v = &vertices[i];
				finished = true;
			}
		}
		return v;
	}
};

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
	vector<string> result = breathFirstTraversal(g);
	for (auto element : result)
	{
		cout << element << " ";
	}



	cout << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << endl;
	system("PAUSE");
	return 0;
}

