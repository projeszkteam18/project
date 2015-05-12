#ifndef __GRAPH_H_INCLUDED__   
#define __GRAPH_H_INCLUDED__ 

class Vertex;
#include <limits>
#include <vector>
#include "Vertex.h"
#include <fstream> 
#include <string>
#include <stdio.h> 

using namespace std;


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

	int read(string path)
	{
		vector<string> splitLine;
		string sLine = "";
		string name;
		ifstream infile;
		int line = 1;


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
	int findVertexIndex(string name)
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

#endif