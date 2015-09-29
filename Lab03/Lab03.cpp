#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

// Function to print out the contents of the vector
// @param arr vector<int>&
void print_vec(vector<int>& arr)
{
	cout<<"|";
 	for (auto& i: arr)
 	{
 		cout<<i<<"|";
 	}
 	cout<<endl;
}


void merge(vector<int>& a_arr, vector<int> b_arr, int p, int q, int r)
{
	int i = p;
	int j = q+1;
//	cout<<"p = "<<p<<" and r = "<<r<<endl;
//	cout<<"From merge a_arr = ";
//	print_vec(a_arr);
	for (int k = p; k <= r; k++)
	{
//		cout<<"val being copied = "<<a_arr[k]<<endl;
		b_arr[k] = a_arr[k];
	}
//	cout<<"From merge b_arr = ";
//	print_vec(b_arr);
	for(int k = p; k<=r; k++)
	{
//		cout<<"i = "<<i<<" j = "<<j<<endl;
		if (i>q)
		{
			a_arr[k] = b_arr[j];
			j++;
		}
		else if (j>r)
		{
			a_arr[k] = b_arr[i];
			i++;
		}
		else if (b_arr[j] < b_arr[i])
		{
			a_arr[k] = b_arr[j];
			j++;
		}
		else 
		{
			a_arr[k]=b_arr[i];
			i++;
		}
	}
}

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


void merge_sort(vector<int>& a_arr, vector<int> b_arr,int size,int p,int r)
{
	if (size > 512)
	{
		if(p < r){
//		print_vec(a_arr);
//		cout<<"Values of p = "<<p<<" and r = "<<r<<endl;
		int q = (p+r)/2;
		merge_sort(a_arr, b_arr,size, p, q);
		merge_sort(a_arr, b_arr,size, q+1, r);
		merge(a_arr, b_arr, p, q, r);
		}
	}
	else
	{
		insertion_sort(a_arr);
	}
}



int main(int argc, const char * argv[])
{
	if (argc < 2)return 0;
	vector<int> a_arr;
	vector<int> b_arr;
	ifstream file(argv[1]);
	int num;
	while(!file.eof()){
		file >> num;
		a_arr.push_back(num);
	}
//	print_vec(a_arr);
	b_arr = a_arr;	
	clock_t start_time = clock();
	merge_sort(a_arr, b_arr,a_arr.size(), 0, a_arr.size()-1);
	clock_t final_time = clock() - start_time;

	cout<<"Merge sort time: "<<((double)final_time)/CLOCKS_PER_SEC<<"s"<<endl;

//	print_vec(a_arr);
	return 0;
}
