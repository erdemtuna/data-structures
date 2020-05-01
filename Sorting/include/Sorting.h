#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <utility>
#include <vector>
//#include <iterator>
#include <algorithm>

namespace etpc
{

	template <class T>
	void sortSelection(T* pArrHead, int i32ArrSize)
	{
		int i32SmallestIndex;
		for(int i=0; i<i32ArrSize-1; i++)
		{
			i32SmallestIndex = i;
			for(int j=i+1; j<i32ArrSize; j++)
			{
				if(pArrHead[j] < pArrHead[i32SmallestIndex])
					i32SmallestIndex = j;
			}
			if(i32SmallestIndex != i)
			{
				std::swap(pArrHead[i], pArrHead[i32SmallestIndex]);
			}
		}
	}

	// Based on the following answer
	// https://codereview.stackexchange.com/a/177919/206877
	// typename vs class
	// https://stackoverflow.com/questions/2023977/difference-of-keywords-typename-and-class-in-templates
	template <class T>
	void sortSelection(std::vector<T>& vArrHead)
	{
		typename std::vector<T>::iterator it;
		for(it = vArrHead.begin(); it != vArrHead.end(); it++)
		{
			std::iter_swap(it, std::min_element(it, vArrHead.end()));
		}
	}

}
#endif // SORTING_ALGORITHMS_H
