#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "myfuncs.h"

int main()
{
	ifstream infile;
	ofstream outfile;
	infile.open("A-large-practice.in", ios::in);
	outfile.open("A-large-practice.out", ios::out);
	int testCases, credits, items;
	infile >> testCases;
	for(int i = 1;i <= testCases;++i)
	{
		infile >> credits >> items;
		int item[items], temp[items], item1, item2, index1, index2, flag = 0, temp2;
		for(int j = 0;j < items;++j)
		{
			infile >> item[j];
			temp[j] = item[j];
		}
		quicksort(temp, 0, items-1);
		int min = temp[0], max = credits - min;
		for(int j = items-1;j >= 0;--j)
		{
			if(temp[j] > max)
				continue;
			item1 = temp[j];
			item2 = credits - item1;
			if(binarysearch(temp, 0, j-1, item2) != -1)
				break;
		}
		for(int j = 0;j < items;++j)
		{
			if(item[j] == item1)
			{
				index1 = j+1;
				flag++;
				if(flag == 2)
					break;
				continue;
			}
			if(item[j] == item2)
			{
				index2 = j+1;
				flag++;
				if(flag == 2)
					break;
				continue;
			}
		}
		if(index1 > index2)
		{
			temp2 = index1;
			index1 = index2;
			index2 = temp2;
		}
		outfile << "Case #" << i << ": " << index1 << " " << index2 << endl;
	}
	infile.close();
	outfile.close();
	return 0;
}