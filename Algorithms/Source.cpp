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