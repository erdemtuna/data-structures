#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <utility>
#include <vector>
//#include <iterator>
#include <algorithm>

namespace etpc
{
	template <class T>
	void sortBubble(T* pArrHead, std::size_t sArrSize)
	{
		for(std::size_t i=0; i<sArrSize-1; i++)
		{
			for(std::size_t j=0; j<sArrSize-i-1; j++)
			{
				if(pArrHead[j]>pArrHead[j+1])
					std::swap(pArrHead[j], pArrHead[j+1]);
			}
		}
	}

	// May 2, 2020
	// Based on the following link
	// https://rosettacode.org/wiki/Sorting_algorithms/Bubble_sort#C.2B.2B
	// typename vs class
	// https://stackoverflow.com/questions/2023977/difference-of-keywords-typename-and-class-in-templates
	template <class T>
	void sortBubble(std::vector<T>& vArrHead)
	{
		typename std::vector<T>::iterator begin = std::begin(vArrHead);
		typename std::vector<T>::iterator end = std::end(vArrHead);
		while (begin != end--) {
			for (auto it = begin; it != end; ++it) {
				if (*(it + 1) < *it) {
					std::iter_swap(it, it + 1);
				}
			}
		}
	}

	template <class T>
	void sortSelection(T* pArrHead, int s32ArrSize)
	{
		std::size_t i32SmallestIndex;
		for(std::size_t i=0; i<s32ArrSize-1; i++)
		{
			i32SmallestIndex = i;
			for(std::size_t j=i+1; j<s32ArrSize; j++)
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

	// April 30, 2020
	// Based on the following answer
	// https://codereview.stackexchange.com/a/177919/206877
	// typename vs class
	// https://stackoverflow.com/questions/2023977/difference-of-keywords-typename-and-class-in-templates
	template <class T>
	void sortSelection(std::vector<T>& vArrHead)
	{
		typename std::vector<T>::iterator it;
		for(it = std::begin(vArrHead); it != std::end(vArrHead); it++)
		{
			std::iter_swap(it, std::min_element(it, std::end(vArrHead)));
		}
	}
}
#endif // SORTING_ALGORITHMS_H
