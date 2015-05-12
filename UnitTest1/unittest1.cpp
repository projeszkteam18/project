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
	};
}