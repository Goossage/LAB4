#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/structures.h"
#include "../main-project/processing.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	TEST_CLASS(unittestproject)
	{
	public:
		
		TEST_METHOD(TestProcessEmptyArray)
		{
			tell_subscribe* subscriptions[1];
			double result = process(subscriptions, 0);
			Assert::AreEqual(result, 0.0, L"Processing an empty array should return 0.");
		}

		TEST_METHOD(TestProcessSingleElement)
		{
			tell_subscribe sub1 = { "123456", {1, 1, 2022}, {10, 0, 0}, {0, 30, 0}, город, 100.0 };
			tell_subscribe* subscriptions[] = { &sub1 };
			double result = process(subscriptions, 1);
			Assert::AreEqual(result, 100.0, L"Processing an array with one element should return the cost of that element.");
		}

		TEST_METHOD(TestProcessMultipleElements)
		{
			tell_subscribe sub1 = { "123456", {1, 1, 2022}, {10, 0, 0}, {0, 30, 0}, город, 100.0 };
			tell_subscribe sub2 = { "654321", {1, 1, 2022}, {11, 0, 0}, {0, 45, 0}, межгород, 200.0 };
			tell_subscribe sub3 = { "987654", {1, 1, 2022}, {12, 0, 0}, {1, 0, 0}, международный, 300.0 };
			tell_subscribe* subscriptions[] = { &sub1, &sub2, &sub3 };
			double result = process(subscriptions, 3);
			Assert::AreEqual(result, 200.0, L"Processing an array with multiple elements should return the average cost.");
		}

		TEST_METHOD(TestProcessZeroCostElements)
		{
			tell_subscribe sub1 = { "123456", {1, 1, 2022}, {10, 0, 0}, {0, 30, 0}, город, 0.0 };
			tell_subscribe sub2 = { "654321", {1, 1, 2022}, {11, 0, 0}, {0, 45, 0}, межгород, 0.0 };
			tell_subscribe sub3 = { "987654", {1, 1, 2022}, {12, 0, 0}, {1, 0, 0}, международный, 0.0 };
			tell_subscribe* subscriptions[] = { &sub1, &sub2, &sub3 };
			double result = process(subscriptions, 3);
			Assert::AreEqual(result, 0.0, L"Processing an array with zero cost elements should return 0.");
		}

		TEST_METHOD(TestProcessNegativeCostElements)
		{
			tell_subscribe sub1 = { "123456", {1, 1, 2022}, {10, 0, 0}, {0, 30, 0}, город, -50.0 };
			tell_subscribe sub2 = { "654321", {1, 1, 2022}, {11, 0, 0}, {0, 45, 0}, межгород, -100.0 };
			tell_subscribe sub3 = { "987654", {1, 1, 2022}, {12, 0, 0}, {1, 0, 0}, международный, -150.0 };
			tell_subscribe* subscriptions[] = { &sub1, &sub2, &sub3 };
			double result = process(subscriptions, 3);
			Assert::AreEqual(result, -100.0, L"Processing an array with negative cost elements should return the average negative cost.");
		}

		TEST_METHOD(TestProcessMixedCostElements)
		{
			tell_subscribe sub1 = { "123456", {1, 1, 2022}, {10, 0, 0}, {0, 30, 0}, город, 50.0 };
			tell_subscribe sub2 = { "654321", {1, 1, 2022}, {11, 0, 0}, {0, 45, 0}, межгород, -25.0 };
			tell_subscribe sub3 = { "987654", {1, 1, 2022}, {12, 0, 0}, {1, 0, 0}, международный, 75.0 };
			tell_subscribe* subscriptions[] = { &sub1, &sub2, &sub3 };
			double result = process(subscriptions, 3);
			Assert::AreEqual(result, 33.33, 0.01, L"Processing an array with mixed cost elements should return the average cost, considering positive and negative values.");
		}
	};
}
