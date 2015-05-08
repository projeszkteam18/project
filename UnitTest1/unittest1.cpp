#include "stdafx.h"
#include "CppUnitTest.h"
#include "Graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Graph g;
			int ret = g.read("0");
			Assert::AreEqual(ret, -1);
		}

		TEST_METHOD(TestMethod2)
		{
			/*string fileName = "./TestFiles/test0.txt";
			Graph g;
			int ret = g.read(fileName);
			Assert::AreEqual(ret, -1);*/
		}

	};
}