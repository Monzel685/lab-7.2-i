#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 7.2 i/lab 7.2 i.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int rowCount = 3;
            const int colCount = 5;
            int* a[rowCount];

            int row0[] = { 1, 3, 5, 7, 9 };
            int row1[] = { 2, 8, 6, 4, 10 };
            int row2[] = { 3, 1, 7, 8, 11 };
            a[0] = row0;
            a[1] = row1;
            a[2] = row2;

            int expectedSum = 15; // —ума м≥н≥мальних елемент≥в у парних стовпц€х (0, 2, 4)
            int actualSum = FindSumOfMinInEvenColumns(a, rowCount, colCount);

            Assert::AreEqual(expectedSum, actualSum);
        }
    };
}
