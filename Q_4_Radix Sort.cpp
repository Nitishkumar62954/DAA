//Radix Sort
/*NITISH KUMAR
20016570016
BSc(H) Computer Science
*/

#include <iostream>
using namespace std;
#include <conio.h>
#include <math.h>

void countSort(int arr[], int size, int num) {
    int x[10];
		for(int c=0; c<10; c++)
		  x[c] = 0;

    int *disp = new int[size];
    for(int i=0; i<size; i++)
        x[int(arr[i]/num)%10]++;
    for(int i=1; i<10; i++) {
        x[i] += x[i-1];
    }
    for(int i=0; i<size; i++) {
        disp[x[int(arr[i]/num)%10] - 1] = arr[i];
        x[int(arr[i]/num)%10]--;
    }
    for(int i=0; i<size; i++) {
        arr[i] = disp[i];
    }
}

void radixSort(int arr[], int size) {
    int max = arr[0];

    for(int i=1; i<size; i++)
        if(max<arr[i])
            max = arr[i];

    for(int i=1; max/i>0; i*=10)
        countSort(arr, size, i);
}

 int main()
 {
 	
 	int arr[10], size, largest, i;

	cout<<"\nEnter the size of array (max. 10): ";
	cin>>size;
	cout<<"\nEnter positive elements in the array: \n";
	for(i=0; i<size; i++)
		cin>>arr[i];

	
	cout<<"\n Your array: \n";
	for(i=0; i<size; i++)
	{
		cout<<arr[i]<<"  ";
	}

	getch();
	radixSort(arr, size);

	
	cout<<"\n Sorted array: ";
	for(i=0; i<size; i++)
	{
		cout<<arr[i]<<"  ";
	}

	getch();
 }
