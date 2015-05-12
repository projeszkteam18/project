#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Algorithms/Graph.h"
#include "../Algorithms/Source.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
#define TEST_CASE_DIRECTORY GetDirectoryName(__FILE__)

		string GetDirectoryName(string path){
			const size_t last_slash_idx = path.rfind('\\');
			if (std::string::npos != last_slash_idx)
			{
				return path.substr(0, last_slash_idx + 1);
			}
			return "";
		}
	public:

		TEST_METHOD(TestMethodReadZero)
		{
			Graph g;
			int ret = g.read("0");
			Assert::AreEqual(ret, -1);
		}

		TEST_METHOD(TestMethodReadOne)
		{
			Graph g;
			string filename = std::string(TEST_CASE_DIRECTORY) + "test1.txt";
			int ret = g.read(filename);
			Assert::AreEqual(ret, 0);
		}

		TEST_METHOD(TestMethodReadTwo)
		{
			Graph g;
			string filename = std::string(TEST_CASE_DIRECTORY) + "test2.txt";
			int ret = g.read(filename);
			Assert::AreEqual(ret, 0);
		}

		TEST_METHOD(TestMethodReadThree)
		{
			Graph g;
			string filename = std::string(TEST_CASE_DIRECTORY) + "test3.txt";
			int ret = g.read(filename);
			Assert::AreEqual(ret, 0);
		}

		TEST_METHOD(TestMethodDijkstraValidGraph)
		{
			Graph g;
			string filename = std::string(TEST_CASE_DIRECTORY) + "test1.txt";
			int ret = g.read(filename);

			vector<vector<int> > result = dijkstra(g);

			vector<int> d;
			d.push_back(0);
			d.push_back(700);
			d.push_back(400);
			d.push_back(800);
			d.push_back(2147483647);

			vector<int> p;
			p.push_back(-1);
			p.push_back(0);
			p.push_back(0);
			p.push_back(2);
			p.push_back(-1);

			vector<vector<int> > expected;
			expected.push_back(d);
			expected.push_back(p);

			bool ok = true;

			for (int i = 0; i < expected.size() && ok; ++i){
				for (int j = 0; j < expected[i].size() && ok; ++j){
					if (expected[i][j] != result[i][j]){
						ok = false;
					}
				}
			}


			Assert::AreEqual(ok, true);

		}

		TEST_METHOD(TestMethodBellmanValidGraph)
		{
			Graph g;
			string filename = std::string(TEST_CASE_DIRECTORY) + "test1.txt";
			int ret = g.read(filename);

			vector<vector<int> > result = bellman_ford(g);

			vector<int> d;
			d.push_back(0);
			d.push_back(700);
			d.push_back(400);
			d.push_back(800);
			d.push_back(2147483647);

			vector<int> p;
			p.push_back(-1);
			p.push_back(0);
			p.push_back(0);
			p.push_back(2);
			p.push_back(-1);

			vector<vector<int> > expected;
			expected.push_back(d);
			expected.push_back(p);

			bool ok = true;

			for (int i = 0; i < expected.size() && ok; ++i){
				for (int j = 0; j < expected[i].size() && ok; ++j){
					if (expected[i][j] != result[i][j]){
						ok = false;
					}
				}
			}


			Assert::AreEqual(ok, true);
		}
	};
}