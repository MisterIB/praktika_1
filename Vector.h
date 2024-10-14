#pragma once
#include <iostream>
#include <string>

template<typename T> struct Vector {

	int currentSize;
	int memoryCapacity;
	T* arr;

public:

	Vector()
	{
		currentSize = 0;
		arr = new T[1];
		memoryCapacity = 1;
	}

	/*~Vector()
	{
		delete[] arr;
	}*/

	T& operator[] (int index)
	{
		return arr[index];
	}

	void push(T data)
	{

		std::string formattedData = data;
		if (currentSize == memoryCapacity)
		{
			T* tempArr = new T[memoryCapacity * 2];
			for (int i = 0; i < currentSize; i++)
			{
				tempArr[i] = arr[i];
			}
			delete[] arr;
			memoryCapacity *= 2;
			arr = tempArr;
		}
		arr[currentSize] = formattedData;
		currentSize++;
	}

	void push_back(T data, int index)
	{
		std::string formattedData = data;
		if (index = currentSize) push_back(formattedData);
		else arr[index] = formattedData;
	}

	T get(int index)
	{
		if (index < currentSize) return arr[index];
		throw std::runtime_error("Index out of range");
	}

	void pop()
	{
		if (currentSize != 0) currentSize--;
		else throw std::runtime_error("Empty vector");
	}

	int size()
	{
		return currentSize;
	}

	int getmemorycapacity()
	{
		return memoryCapacity;
	}

	void print()
	{
		for (size_t i = 0; i < currentSize; i++)
		{
			std::cout << arr[i] << " ";
		}
	}

};
