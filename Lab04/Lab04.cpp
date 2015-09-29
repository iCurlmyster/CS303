#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

static int heap_size;

// Function to print out the contents of the vector
// // @param arr vector<int>&
void print_vec(vector<int>& arr)
{
	cout<<"|";
	for (auto& i: arr)
	{
		cout<<i<<"|";
	}
	cout<<endl;
}


void max_heapify(vector<int>& arr, int i)
{
	int left = (2*i);
	int right = (2*i)+1;
	int largest = i;
	if (left <= heap_size and arr[left] > arr[i])
		largest = left;
	else
		largest = i;
	if (right <= heap_size and arr[right] > arr[largest])
		largest = right;
	if (largest != i){
		int tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;
		max_heapify(arr,largest);
	}
}

void build_max_heap(vector<int>& arr)
{
	heap_size = arr.size()-1;
	for (int i = arr.size()/2;i>=0;i--)
	{
		max_heapify(arr,i);
	}
}


void heap_sort(vector<int>& arr)
{
	build_max_heap(arr);
	for (int i = arr.size()-1;i>=1;i--)
	{
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		heap_size = heap_size - 1;
		max_heapify(arr, 0);
	}
}


int main(int argc, const char * argv[]) {

	if (argc < 2)return 0;
	vector<int> a_arr;
	ifstream file(argv[1]);
	int num;
	while(!file.eof()){
		file >> num;
		a_arr.push_back(num);
	}
//	print_vec(a_arr);
	clock_t start_time = clock();
        heap_sort(a_arr);
	clock_t final_time = clock() - start_time;
	cout<<"Heap Sort time: "<<((double)final_time)/CLOCKS_PER_SEC<<"s"<<endl;
//	print_vec(a_arr);
	return 0;
}
