#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

void print_vec(vector<int>& arr)
{
	cout<<"|";
	for(auto& i: arr)
	{
		cout<<i<<"|";
	}
	cout<<endl;
}

void swap_val( vector<int>& arr, int p, int q ) {
	int tmp = arr[p];
	arr[p] = arr[q];
	arr[q] = tmp;
}

void short_sort(vector<int>& arr, int p, int q)
{
	if (p == q) return;
	int smallest = p;
	int largest = q;
	for (int i = p + 1; i <= q-1; i++)
	{	
		if (arr[i] < arr[smallest]) smallest = i;
		if (arr[i] > arr[largest]) largest = i;	
	}
	swap_val(arr, p, smallest);
	swap_val(arr, q, largest);
	short_sort(arr, p+1, q-1);
}

int find_h(vector<int>& arr)
{
	int h_index = 0;
	for (int i = 0;i<arr.size(); i++ )
	{
		if (arr[i] < (arr.size() - h_index))
			h_index++;
		else
			return h_index;
	}
	return h_index;
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

	ifstream file(argv[1]);
        vector<int> arr;
	vector<int> arr2;
        int val;
        while(!file.eof())
        {
                file >> val;
                arr.push_back(val);
        }
        file.close();
	
	arr2 = arr;

	cout<<"Finding H-index.."<<endl;
	print_vec(arr);
	quick_sort(arr, 0, arr.size());	
	int h_val = find_h(arr);
	print_vec(arr);
	cout<<"H-index = "<<h_val<<endl;

        print_vec(arr2);  //Printing out vector to see initial elements
        clock_t start_time = clock();
        short_sort(arr2,0, arr.size()-1);
        clock_t final_time = clock() - start_time;
        print_vec(arr2);       //Printing out vector to see elements after sort
        cout<<"Short sort time to complete: "<<((float)final_time)/CLOCKS_PER_SEC<<"s"<<endl;


        return 0;
}
