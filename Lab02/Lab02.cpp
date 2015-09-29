#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;


void insertion_sort(vector<int>& arr)
{
	for (int i = 1; i < arr.size(); i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j > -1 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j+1] = key;
	}
}

// Function to print out the contents of the vector
// @param arr vector<int>&
// void print_vec(vector<int>& arr)
// {
// 	cout<<"|";
// 	for (auto& i: arr)
// 	{
// 		cout<<i<<"|";
// 	}
// 	cout<<endl;
// }

int main(int argc, const char * argv[])
{
	ifstream file(argv[1]);
	vector<int> arr;
	int val;
	while(!file.eof())
	{
		file >> val;
		arr.push_back(val);
	}
	file.close();
	cout<<"Start Insertion Sort!"<<endl;
	//print_vec(arr);  //Printing out vector to see initial elements
	clock_t start_time = clock();
	insertion_sort(arr);
	clock_t final_time = clock() - start_time;
	cout<<"Insertion Sort Done!"<<endl;
	//print_vec(arr);	//Printing out vector to see elements after sort
	cout<<"Insertion sort time to complete: "<<((float)final_time)/CLOCKS_PER_SEC<<"s"<<endl;
	return 0;
}
