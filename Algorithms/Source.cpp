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



int main()
{
	cout << "Melyik tesztet szerete futtatni?" << endl;
	cout << endl;
	cout << "1 - Dijkstra" << endl;
	cout << "2 - Bellman-Ford" << endl;
	cout << "3 - Szelessegi bejaras" << endl;
	cout << endl;
	cout << "Kerem valassszon egy szamot: ";
	bool ok = false;
	string mystring = "";
	Graph g;
	int ret = g.read("test1.txt");
	while (ok == false)
	{
		cin >> mystring;
		if (mystring == "1"){
			vector<vector<int> > result = dijkstra(g);
		}
		else if (mystring == "2"){
			vector<vector<int> > result2 = bellman_ford(g);
		}
		else if (mystring == "3"){
			vector<string> result = breathFirstTraversal(g);
		}
		else if (mystring == "q"){
			ok = true;
		}
		else
		{
			cout << "A kovetezo szamok egyiket adja meg: 1, 2, 3." << endl;
			cout << "A választott szam: ";
		}
	}
	cout << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << endl;

	
	
	if (ret != 0) cout << "A fájl megnyitása sikertelen" << endl;

	cout << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << endl;
	system("PAUSE");
	return 0;
}