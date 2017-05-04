#include<iostream>
#include<cstdlib>
#include<time.h>
#include<conio.h>
using namespace std;

void CopyArray(int array1[], int array2[], int length){
	for(int i=0; i < length; i++){
		array2[i] = array1[i];	
	}	
}

void Merge(int theArray[], int length, int first, int mid, int last, int* compareCount, int* movesCount){
	int tempArray[length]; // temp array
	int first1 = first; // subarray begin
	int last1 = mid; // end of first subarray
	int first2 = mid + 1; // secnd subarry begin
	int last2 = last; // end of secnd subarry
	int index = first1;
	
	// next available location in tempArray
	for (; (first1 <= last1) && (first2 <= last2); ++index){
		*compareCount += 1;
		if (theArray[first1] < theArray[first2]){
			tempArray[index] = theArray[first1];
			++first1;
			*movesCount += 1;	
		}
		else {
			tempArray[index] = theArray[first2];
			++first2;
			*movesCount += 1;
		}
	}
	
	for (; first1 <= last1; ++first1, ++index){
		tempArray[index] = theArray[first1];
		*movesCount += 1;
	}
		
	for (; first2 <= last2; ++first2, ++index){
		tempArray[index] = theArray[first2];
		*movesCount += 1;
	}

	for (index = first; index <= last; ++index)
		theArray[index] = tempArray[index];
}

void MergeSort(int theArray[], int length, int first, int last, int* divideCount, int* compareCount, int* movesCount){
	
	if (first < last)
	{ // sort each half
		*divideCount += 1;
		int mid = (first + last)/2; // index of midpoint
		// sort left half theArray[first..mid]
		MergeSort(theArray, length, first, mid, divideCount, compareCount, movesCount);
		// sort right half theArray[mid+1..last]
		MergeSort(theArray, length, mid+1, last, divideCount, compareCount, movesCount);
		// merge the two halves
		Merge(theArray, length, first, mid, last, compareCount, movesCount);
	} // end if
}

void GenerateRandomNumbers(int numbers[], int length){
	srand(time(NULL));
	for(int i = 0; i< length; i++){
		numbers[i] = (rand() % 999) + 1;
	}
}

void PrintData(int data[], int length){
	for(int i = 0; i < 100; i++){
		
		if(i%10 == 0){
			cout<<endl;
		}
		else{
			cout<<"\t";
		}
		
		cout<<data[i];
	}
}

void OneHundredData(){
	int length = 100;
	int data[length];
	int tempdata[length];
	int divCount, comCount, movCount;
	divCount = 0;
	comCount = 0;
	movCount = 0;
	
	cout<<"Generating Random Numbers....."<<endl;
	GenerateRandomNumbers(data, length);
	CopyArray(data, tempdata, length);
	PrintData(data, length);	
	cout<<endl<<"Sorting..."<<endl<<endl;
	MergeSort(data, length, 0, length - 1, &divCount, &comCount, &movCount);
	PrintData(data, length);
	
	cout<<endl<<endl<<"Division count: "<<divCount<<endl;
	cout<<"Compare count: "<<comCount<<endl;
	cout<<"Moves count: "<<movCount<<endl;
}

void FiveHundredData(){
	
}

void OneThousandData(){
	
}

int main()
{
	OneHundredData();
	getch();
    return 0;
}

