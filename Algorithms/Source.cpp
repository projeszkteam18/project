#include <vector>
#include <iostream>
#include <string>
#include <fstream> 

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
		min_dist = 0;
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
	int getMin_dist() { return min_dist; }
	Vertex* getParent() { return parent; }
	void setMin_dist(int n) { min_dist = n; }
	void setParent(Vertex*v){ parent = v; }
	vector<Edge> getEdges() { return edges; }

private:
	string name;
	vector<Edge> edges;
	int min_dist;
	Vertex*parent;

public:
	bool color;
};

class Graph	
{
public:
	vector<Vertex> vertices;
	int numberOfVertices;
	string start_vertex_name;
	string destini_vertex_name;

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
				start_vertex_name = sLine;
			}
			else
			{
				destini_vertex_name = sLine;
			}
			line++;
		}
		infile.close();
		return 0;
	}

	int findVertex(string name)
	{
		int number = 0;
		for (int i = 0; i<numberOfVertices; i++)
		{
			if (vertices[i].getName() == name)
			{
				number = i;
			}
		}
		return number;
	}
};

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
	int ret=g.read(mystring);
	if (ret == 0) cout << "A fájl megnyitása sikertelen" << endl;

	cout << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << endl;

	system("PAUSE");

	return 0;
}