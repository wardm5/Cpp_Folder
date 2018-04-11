#pragma once
#include <string>
#include <iostream>
#include "Node.h"

#ifndef _SETDATA
#define _SETDATA
template <class T>
class SetData
{
private:
	T value;
	int count;

public:
	SetData();
	SetData(T initalValue);
	~SetData();
	void setter(T data, bool exist);
	void setCount(T data);
	void setValue(T data);
	T getter();
	int getterCount();
};
#endif

template<class T>
SetData<T>::SetData()
{

	T value = T();
	int count = 0;
}

template<class T>
SetData<T>::SetData(T initalValue)
{
	this->value = initalValue;
	this->count = 1;
}

template<class T>
SetData<T>::~SetData() {}

template<class T>
void SetData<T>::setter(T data, bool exist)
{
	if (exist)
	{
		count++;
	}
	else
	{
		value = data;
		count++;
	}
}

template<class T>
int SetData<T>::getterCount()
{
	return count;
}

template<class T>
T SetData<T>::getter()
{
	return value;
}

template<class T>
void SetData<T>::setCount(T data)
{
	T count = data;
}

template<class T>
void SetData<T>::setValue(T data)
{
	value = data;
}
