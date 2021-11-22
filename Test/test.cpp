#include "pch.h"
#include <complex>
#include "../Lab3_final/ClassVector.h"

TEST(vector, Method_GetSize) {
	vector<std::complex<double>> a;
	a.Add(3);
	EXPECT_EQ(1, a.GetSize());
}

TEST(vector, Operator_SquareBrackets) {
	vector<int> a;
	a.Add(1);
	a[0] = 1;
	EXPECT_EQ(1, a[0]);
}

TEST(vector, Operator_SquareBrackets_Exception) {
	vector<std::complex<float>> a;
	EXPECT_THROW(a[-1], const char*);
}

TEST(vector, Operator_Plus) {
	vector<double> a;
	vector<double> b;
	b.Add(1);
	EXPECT_THROW(a + b, const char*);
}

TEST(vector, Operator_ScalarMultiplication) {
	vector<float> a;
	vector<float> b;
	a.Add(1);
	b.Add(1);
	b.Add(2);
	EXPECT_THROW(a * b, const char*);
}

TEST(vector, Operator_MultiplicationByNumber) {
	vector<double> a;
	a.Add(1.5);
	a.Add(1.5);
	vector<double> b = a * 2;
	EXPECT_EQ(3, b[0]);
	EXPECT_EQ(3, b[1]);
}

TEST(vector, Operator_DivisionByNumber) {
	vector<int> a;
	a.Add(2);
	a.Add(2);
	vector<int> b = a / 2;
	EXPECT_EQ(1, b[0]);
	EXPECT_EQ(1, b[1]);
}

TEST(vector, Operator_DivisionByNumber_Exception) {
	vector<int> a;
	a.Add(2);
	a.Add(2);
	a.Add(2);
	EXPECT_THROW(a / 0, const char*);
}

TEST(vector, Operator_ScalarMultiplication_Complex) {
	vector<std::complex<double>> a;
	a.Add(std::complex<double>(15, 20));
	a.Add(std::complex<double>(23, 23));
	vector<std::complex<double>> b;
	b.Add(std::complex<double>(12, 21));
	b.Add(std::complex<double>(44, 44));
	std::complex<double> result = a * b;
	EXPECT_EQ(-240, result.real());
	EXPECT_EQ(2579, result.imag());
}

TEST(vector, Iterator_Erase) {
	vector<int> a;
	a.Add(2);
	a.Add(2);
	a.Add(2);
	a.Erase(a.Begin() + 2);
	EXPECT_EQ(2, a.GetSize());
}