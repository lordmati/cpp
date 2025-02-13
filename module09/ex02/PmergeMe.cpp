#include "PmergeMe.hpp"

bool checkArgv(char **argv)
{
	for(int i = 1; argv[i]; i++)
	{
		for(int j = 0; argv[i][j]; j++)
		{
			if(argv[i][j] >= '0' && argv[i][j] <= '9')
				;
			else
			{
				std::cout << "Error: " << std::endl;
				std::cout << argv[i][j] << std::endl;
				return (false);
			}
		}
	}
	return (true);
}

bool checkNumberDuplicate(std::vector<int> Num)
{
	for(size_t i = 0; i < Num.size(); i++)
	{
		for(size_t j = i + 1; j < Num.size(); j++)
			if (Num[i] == Num[j])
				return (false);
	}
	return (true);
}
bool checkOrder(std::vector<int> Num)
{
	for(size_t i = 0; i < Num.size() - 1; i++)
	{
		if(Num[i] > Num[i + 1])
			return(true);
	}
	return(false);
}
void makeVector(char **str, int argc)
{
	std::vector<int> numbers;
	std::list<int> numberlist;
	for (int i = 1; i < argc; ++i)
	{
		numbers.push_back(std::atoi(str[i]));
 		numberlist.push_back(std::atoi(str[i]));
	}
	if(!checkNumberDuplicate(numbers))
	{
		std::cerr << "Error: Number duplicated" << std::endl;
		return ;
	}
	if(!checkOrder(numbers))
	{
		std::cerr << "Error: Numbers Ordered" << std::endl;
		return ;
	}
	std::cout << "Before:  ";
	for(size_t i = 0; i < numbers.size();i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;
	std::clock_t start_vector = std::clock();
	mergeInsertionSortVector(numbers);
	std::clock_t end_vector = std::clock();
	double rest_vector = double(end_vector - start_vector) / CLOCKS_PER_SEC * 1000;
	std::clock_t start_list = std::clock();
	mergeInsertionSortList(numberlist);
	std::clock_t end_list = std::clock();
	double rest_list = double(end_list - start_list) / CLOCKS_PER_SEC * 1000;
	std::cout << "\nTime to process a range of " << numbers.size() << " elements with std::vector : " << rest_vector << " us" << std::endl;
	std::cout << "Time to process a range of " << numbers.size() << " elements with std::list : " << rest_list << " us" << std::endl;
}
void mergeInsertionSortVector(std::vector<int> &n)
{
	int size = n.size();

	if (size < 1)
	{
		std::cout << "One number" << std::endl;
		return ;
	}
	std::cout << "size: " << size << std::endl;
	std::vector<int> winners, losers;
	for(int i = 0; i + 1< size; i+=2)
	{
		if(n[i] < n[i + 1])
		{
			winners.push_back(n[i + 1]);
			losers.push_back(n[i]);
			std::cout << n[i + 1] << std::endl;
		}
		else
		{
			winners.push_back(n[i]);
			losers.push_back(n[i + 1]);
			std::cout << n[i] << std::endl;
		}
	}
	if(size % 2 != 0)
		winners.push_back(n[size - 1]);
	winnerSort(winners);
	for (std::vector<int>::iterator it = losers.begin(); it != losers.end(); it++)
	{
		std::vector<int>::iterator pos = std::lower_bound(winners.begin(),winners.end(),*it);
		winners.insert(pos,*it);
	}
	std::cout << "Vector After: ";
	n = winners;
	for(size_t i = 0; i < n.size(); i++)
		std::cout << n[i] << " ";
}

void mergeInsertionSortList(std::list<int> &n)
{
	int size = n.size();
	if (size < 1)
	{
		std::cout << "One number" << std::endl;
		return ;
	}
	std::list<int> winners, losers;
	std::list<int>::iterator it = n.begin();
	while (it != n.end())
    {
        std::list<int>::iterator next = it;
        ++next;

        if (next != n.end())
        {
            if (*it < *next)
            {
                winners.push_back(*next);
                losers.push_back(*it);
            }
            else
            {
                winners.push_back(*it);
                losers.push_back(*next);
            }
            it = ++next;
        }
        else
        {
            winners.push_back(*it);
            break;
        }
    }
	winnerSort(winners);
	for (std::list<int>::iterator it = losers.begin(); it != losers.end(); it++)
    {
            std::list<int>::iterator pos = std::lower_bound(winners.begin(), winners.end(), *it);
            winners.insert(pos, *it);
    }
    n = winners;
    std::cout << "\nList After:   ";
    for (std::list<int>::iterator it = n.begin(); it != n.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}