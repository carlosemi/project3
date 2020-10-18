#include <iostream>

using namespace std;

class Algorithms
{

public:
    //                      SELECTION SORT

    //This function is for selection sort
    void selectionSort(int numbers[], int numbersSize)
    {

        int i = 0;
        int j = 0;

        int indexSmallest = 0;
        int temp = 0;

        for (i = 0; i < numbersSize; i++)
        {

            //Find index of smallest remaining element
            indexSmallest = i;

            for (j = i + 1; j < numbersSize; j++)
            {

                if (numbers[j] < numbers[indexSmallest])
                {
                    indexSmallest = j;
                }
            }

            //Swap numbers[i] and numbers[indexSmallest]
            temp = numbers[i];
            numbers[i] = numbers[indexSmallest];
            numbers[indexSmallest] = temp;
        }

        //Print the sorted array
        cout << "Selection Sort: ";
        for (int z = 0; z < numbersSize; z++)
        {

            cout << numbers[z] << " ";
        }

        cout << endl;
    }

    //------------------------------------------------------------------------------
    //                    INSERTION SORT

    void insertionSort(int numbers[], int numbersSize)
    {
        int i = 0;
        int j = 0;

        int temp = 0; //Temporary variable for swap

        for (i = 1; i < numbersSize; i++)
        {

            j = i;
            //Insert numbers[i] into sorted array
            //stopping once numbers[i] in correct position

            while (j > 0 && numbers[j] < numbers[j - 1])
            {

                //Swap numbers[j] and numbers[j - 1]
                temp = numbers[j];
                numbers[j] = numbers[j - 1];
                numbers[j - 1] = temp;

                --j;
            }
        }

        //Print the Insertion array
        cout << "Insertion Sort: ";
        for (int z = 0; z < numbersSize; z++)
        {

            cout << numbers[z] << " ";
        }

        cout << endl;
    }
    //---------------------------------------------------------------------------------
    //                            SHELL SORT
    void shellSort()
    {
    }

    //---------------------------------------------------------------------------------
    //                             QUICK SORT

    int partition(int numbers[], int i, int k)
    {

        int l = 0;
        int h = 0;
        int midpoint = 0;
        int pivot = 0;
        int temp = 0;
        bool done = false;

        //Pick middle element as a pivot
        midpoint = i + (k - i) / 2;
        pivot = numbers[midpoint];

        l = i;
        h = k;

        while (!done)
        {

            //Increment l while numbers[l] < pivot
            while (numbers[l] < pivot)
            {
                l++;
            }

            //Decrement h while pivot < numbers[h]
            while (pivot < numbers[h])
            {
                h--;
            }

            //If there are zero or one elements remaining,
            //all numbers are partinioned. Return h
            if (l >= h)
            {
                done = true;
            }
            else
            {
                //Swap numbers[l] and numbers[h],
                //update l and h
                temp = numbers[l];
                numbers[l] = numbers[h];
                numbers[h] = temp;

                ++l;
                --h;
            }
        }

        return h;
    }

    int quickSort(int numbers[], int i, int k)
    {

        int j = 0;

        //Base case: If there are 1 or zero elements to sort
        //partition is already sorted
        if (i >= k)
        {
            return 1;
        }

        //Parition the data within the array. Value j returned
        //from partitioning is locaiton of last element in low partition.
        j = partition(numbers, i, k);

        //Recursively sort low partition (i to j) and
        //high partition (j + 1 to k)
        quickSort(numbers, i, j);
        quickSort(numbers, j + 1, k);
    }

    //----------------------------------------------------------------------------------
    //                             MERGE SORT

    void mergeSort(int numbers[], int i, int k)
    {

        // void merge(int numbers[], i, j, k){
        //     int mergedSize = k - i + 1;
        //     int mergePos = 0;
        //     int leftPos = 0;
        //     int rightPos = 0;

        // }
    }
};

int main()
{

    //cout << ("Starting Program") << endl;

    //int array[] = {4, 3, 8, 5, 6};
    int array[] = {10, 2, 78, 4, 45, 32, 7, 11};

    int size = sizeof(array) / sizeof(array[0]);
    cout << "Size of array: " << size << endl;
    cout << "Unsorted array: ";

    for (int z = 0; z < size; z++)
    {

        cout << array[z] << " ";
    }
    cout << endl;

    Algorithms algo;

    //algo.selectionSort(array, size);
    //algo.insertionSort(array, size);

    algo.quickSort(array, 0, size - 1);

    cout << "Sorted Array: " << endl;
    for (int z = 0; z < size; z++)
    {

        cout << array[z] << " ";
    }
    cout << endl;
}