#pragma once
#include <iostream>
#include <string>
#include <complex>
#include <vector>
#include <iterator>

template <typename T>
class vector {
private:
	std::vector<T> v;
public:

	void Add(T value)
	{
		v.push_back(value);
	}

	size_t  GetSize() const
	{
		return v.size();
	}

	T& operator[] (const size_t index)
	{
		if (index > v.size()) throw ("Invalid index");
		return v[index];
	}

	T  operator[] (const size_t index) const
	{
		if (index > v.size()) throw("Invalid index");
		return v[index];
	}

	vector<T>  operator+= (const vector& vec)
	{
		if (v.size() != vec.GetSize()) throw("Different sizes");
		for (size_t i = 0; i < v.size(); i++)
		{
			v[i] += vec.v[i];
		}
		return *this;
	}

	vector<T>  operator+ (const vector& vec)
	{
		if (v.size() != vec.GetSize()) throw("Different sizes");
		vector tmp(*this);
		tmp += vec;
		return tmp;
	}

	vector<T>  operator-= (const vector& vec)
	{
		if (v.size() != vec.GetSize()) throw("Different sizes");
		for (size_t i = 0; i < v.size(); i++)
		{
			v[i] -= vec.v[i];
		}
		return *this;
	}


	vector<T>  operator- (const vector& vec)
	{
		if (v.size() != vec.GetSize()) throw("Different sizes");
		vector tmp(*this);
		tmp -= vec;
		return tmp;
	}

	T  operator* (const vector& vec)
	{
		if (v.size() != vec.GetSize()) throw("Different sizes");
		T result = 0;
		for (size_t i = 0; i < v.size(); i++) {
			result += vec.v[i] * v[i];
		}
		return result;
	}

	vector<T>  operator*= (const T x) //multiplied by number
	{
		for (size_t i = 0; i < v.size(); i++) {
			v[i] = v[i] * x;
		}
		return *this;
	}

	vector<T>  operator* (const T x)  //multiplied by number
	{
		vector tmp = *this;
		tmp *= x;
		return tmp;
	}

	vector<T>  operator/= (const T x)
	{
		if (x == T(0)) throw("Invalid denominator");
		for (size_t i = 0; i < v.size(); ++i) {
			v[i] /= x;
		}
		return *this;
	}

	vector<T>  operator/ (const T x)
	{
		if (x == T(0)) throw("Invalid denominator");
		vector tmp = *this;
		tmp /= x;
		return tmp;
	}

	auto Begin() const
	{
		return v.begin();
	}

	auto Erase(typename std::vector<T>::const_iterator index) {  //Iterator example
		v.erase(index);
	}

	friend std::ostream& operator<< (std::ostream& out, const vector<T>& vec)
	{
		out << "Size:" << vec.GetSize() << std::endl;
		for (size_t i = 0; i < vec.GetSize(); i++)
		{
			out << vec[i] << std::endl;
		}
		return out;
	}

	std::complex<float> operator* (const vector<std::complex<float>>& vec) const
	{
		if (vec.GetSize() != v.size()) throw "Different sizes\n";
		std::complex<float> result = 0;
		for (size_t i = 0; i < v.size(); i++)
		{
			float real = v[i].real() * vec[i].real();
			float imag = (-1) * v[i].imag() * vec[i].imag();
			result += std::complex<float>(real, imag);
		}
		return result;
	}

	std::complex<double> operator* (const vector<std::complex<double>>& vec) const
	{
		if (vec.GetSize != v.size()) throw "Different sizes\n";
		std::complex<double> result = 0;
		for (size_t i = 0; i < v.size(); i++)
		{
			double real = v[i].real() * vec[i].real();
			double imag = (-1) * v[i].imag() * vec[i].imag();
			result += std::complex<double>(real, imag);
		}
		return result;
	}

};