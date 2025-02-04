#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <ctime>

bool checkArgv(char **argv);
void makeVector(char **str, int argc);
void mergeInsertionSortVector(std::vector<int> &n);
void mergeInsertionSortList(std::list<int> &n);
template <typename T>
void winnerSort(T &winner)
{
	if(std::distance(winner.begin(),winner.end()) < 2)
		return ;
	typename T::iterator mid = winner.begin();
	std::advance(mid,std::distance(winner.begin(),winner.end()) / 2);
	
	T left(winner.begin(),mid);
	T right(mid,winner.end());
	
	winnerSort(left);
	winnerSort(right);
	
	typename T::iterator left_it = left.begin();
	typename T::iterator right_it = right.begin();
	typename T::iterator dest_it = winner.begin();
	
	while(left_it != left.end() && right_it != right.end())
	{
		if(*left_it < *right_it)
		{
			*dest_it = *left_it;
			++left_it;
		}
		else
		{
			*dest_it = *right_it;
			++right_it;
		}
		++dest_it;
	}
	while(left_it != left.end())
	{
		*dest_it = *left_it;
		++left_it;
		++dest_it;
	}
	while(right_it !=  right.end())
	{
		*dest_it = *right_it;
		++right_it;
		++dest_it;
	}
}

#endif