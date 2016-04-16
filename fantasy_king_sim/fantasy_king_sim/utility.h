#pragma once
#include "stdafx.h"
template<class arg1,class arg2,class result>
class binary_function
{
public:
	virtual result operator()(const arg1 &a, const arg2 &b) = 0;
	virtual result operator()(const arg1 &a)=0;
};


template<class T>
class power : public binary_function<T,T,T>
{
public:
	T operator()(const T &a, const T &b)
	{
		return pow(a, b);
	}
	T operator()(const T &a)
	{
		throw "Error while calculation: not enough arguments";
	}
};
template<class T>
class plus : public binary_function<T,T,T>
{
public:
	T operator()(const T &a, const T &b)
	{
		return a+b;
	}
	T operator()(const T &a)
	{
		throw "Error while calculation: not enough arguments";
	}
};
template<class T>
class minus : public binary_function<T,T,T>
{
public:
	T operator()(const T &a, const T &b)
	{
		return a-b;
	}
	T operator()(const T &a)
	{
		return -1 * a;
	}
};
template<class T>
class multiplies : public binary_function<T,T,T>
{
public:
	T operator()(const T &a, const T &b)
	{
		return a*b;
	}
	T operator()(const T &a)
	{
		throw "Error while calculation: not enough arguments";
	}
};
template<class T>
class divides : public binary_function<T,T,T>
{
public:
	T operator()(const T &a, const T &b)
	{
		return a/b;
	}
	T operator()(const T &a)
	{
		throw "Error while calculation: not enough arguments";
	}
};

template<class T>
class less_equal : public binary_function<T, T, bool>
{
public:
	bool operator()(const T &a, const T &b)
	{
		return a <= b;
	}
	bool operator()(const T &a)
	{
		throw "Error while calculation: not enough arguments";
	}
};

template<class T>
class greater_equal : public binary_function<T, T, bool>
{
public:
	bool operator()(const T &a, const T &b)
	{
		return a >= b;
	}
	bool operator()(const T &a)
	{
		throw "Error while calculation: not enough arguments";
	}
};
