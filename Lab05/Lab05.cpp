#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

void print_vec(vector<int>& arr)
{
	cout<<"|";
	for (auto& i: arr)
	{
		cout<<i<<"|";
	}
	cout<<endl;
}

int partition(vector<int>& arr, int p, int r)
{
	int x = arr[p];
	int i = p;
	for (int j = p+1; j < r; j++)
	{
		if (arr[j]<=x){
			i++;
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	int tmp = arr[i];
	arr[i] = arr[p];
	arr[p] = tmp;
	return i;
}

void quick_sort(vector<int>& arr,int p, int r)
{
	if (p<r){
		int q = partition(arr,p,r);
		quick_sort(arr,p,q);
		quick_sort(arr,q+1,r);
	}
}

int main(int argc, const char * argv[])
{
	if (argc < 2)return 1;
	vector<int> a_arr;
	ifstream file(argv[1]);
	int num;
	while(!file.eof()){
		file >> num;
		a_arr.push_back(num);
	}
	print_vec(a_arr);
	clock_t start_time = clock();
        quick_sort(a_arr,0,a_arr.size());
	clock_t final_time = clock() - start_time;
	cout<<"Quick Sort time: "<<((double)final_time)/CLOCKS_PER_SEC<<"s"<<endl;
	print_vec(a_arr);
	return 0;
}
