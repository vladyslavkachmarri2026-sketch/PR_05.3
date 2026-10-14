#include "pch.h"
#include "CppUnitTest.h"
#define UNIT_TESTING  // Вказу. прапорець, щоб main() з основного файлу не заважав тестам
#include "../PR_05.3.cpp" // підключив свій проект

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest053
{
	TEST_CLASS(UnitTest053)
	{
	public:

		// 1. Тест для гілки |x| >= 1 (наприклад, x = 2.0)
		TEST_METHOD(TestMethod_BranchGreaterOrEqualOne)
		{
			double x = 2.0;
			double expected = (sin(2.0) + 1.0) / (sin(2.0) + cos(2.0));
			double actual = f(x);

			Assert::AreEqual(expected, actual, 1e-5);
		}

		// 2. Тест для гілки |x| < 1 (наприклад, x = 0.5)
		TEST_METHOD(TestMethod_BranchLessThanOne)
		{
			double x = 0.5;
			double expected = sinh(0.5); // Математичний еквівалент суми ряду
			double actual = f(x);

			Assert::AreEqual(expected, actual, 1e-5);
		}

		// 3. Тест для x = 0
		TEST_METHOD(TestMethod_ZeroValue)
		{
			double x = 0.0;
			double actual = f(x);

			Assert::AreEqual(0.0, actual, 1e-7);
		}
	};
}