/*
Carlos Guerra Falcon
Id: 20257053
CSCI 3333 
Dr. Zhang
October/21/2020
*/

#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <thread>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Algorithms
{

private:
public:
    unsigned long int counter = 0;

    //                      SELECTION SORT

    //This function is for selection sort
    void selectionSort(unsigned int numbers[], int numbersSize)
    {

        int i = 0;
        int j = 0;

        int indexSmallest = 0;
        int temp = 0;

        counter = 0; //This will determine number of comparisons
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
                counter++;
            }

            //Swap numbers[i] and numbers[indexSmallest]
            temp = numbers[i];
            numbers[i] = numbers[indexSmallest];
            numbers[indexSmallest] = temp;
        }
    }

    //------------------------------------------------------------------------------
    //                    INSERTION SORT

    void insertionSort(unsigned int numbers[], int numbersSize)
    {
        int i = 0;
        int j = 0;

        int temp = 0; //Temporary variable for swap

        counter = 0;
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

                counter++;
            }
        }
    }
    //---------------------------------------------------------------------------------
    //                            SHELL SORT
    void insertionSortInterleaved(unsigned int numbers[], int numbersSize, int startIndex, int gap)
    {
        int i = 0;
        int j = 0;
        int temp = 0;

        for (i = startIndex + gap; i < numbersSize; i = i + gap)
        {
            j = i;

            while (j - gap >= startIndex && numbers[j] < numbers[j - gap])
            {
                temp = numbers[j];
                numbers[j] = numbers[j - gap];
                numbers[j - gap] = temp;
                j = j - gap;
                counter++;
            }
            counter++;
        }
    }

    void shellSort(unsigned int numbers[], int numbersSize, int gapValues[], int gapValueSize)
    {

        for (int i = 0; i < gapValueSize; i++)
        {
            for (int z = 0; z < gapValues[z]; z++)
            {
                insertionSortInterleaved(numbers, numbersSize, i, gapValues[z]);
            }
        }
    }

    //---------------------------------------------------------------------------------
    //                             QUICK SORT

    int partition(unsigned int numbers[], int i, int k)
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
                counter++;
            }

            //Decrement h while pivot < numbers[h]
            while (pivot < numbers[h])
            {
                h--;
                counter++;
            }

            //If there are zero or one elements remaining,
            //all numbers are partinioned. Return h
            if (l >= h)
            {
                done = true;
                counter++;
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

    int quickSort(unsigned int numbers[], int i, int k)
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

    void merge(unsigned int *numbers, int i, int j, int k)
    {
        int mergedSize = k - i + 1;
        int mergePos = 0;
        int leftPos = 0;
        int rightPos = 0;

        int *mergedNumbers = new int[mergedSize];

        leftPos = i;
        rightPos = j + 1;

        while (leftPos <= j && rightPos <= k)
        {
            if (numbers[leftPos] <= numbers[rightPos])
            {
                mergedNumbers[mergePos] = numbers[leftPos];
                ++leftPos;
            }
            else
            {
                mergedNumbers[mergePos] = numbers[rightPos];
                ++rightPos;
            }
            ++mergePos;
            counter++;
        }

        //If left partition is not empty, add remaining elements to merged numbers
        while (leftPos <= j)
        {
            mergedNumbers[mergePos] = numbers[leftPos];
            ++leftPos;
            ++mergePos;
            counter++;
        }

        //If right partition is not empty, add remaining elements to merged numbers
        while (rightPos <= k)
        {
            mergedNumbers[mergePos] = numbers[rightPos];
            ++rightPos;
            ++mergePos;
            counter++;
        }

        //Copy merge number back to numbers
        for (mergePos = 0; mergePos < mergedSize; ++mergePos)
        {
            numbers[i + mergePos] = mergedNumbers[mergePos];
        }
    }

    void mergeSort(unsigned int *numbers, int i, int k)
    {
        int j = 0;

        if (i < k)
        {

            j = (i + k) / 2; //Find the midpoint in the partition

            //Recursively sort lef tand right partitions
            mergeSort(numbers, i, j);
            mergeSort(numbers, j + 1, k);

            //Merge left and right partition in sorted order
            merge(numbers, i, j, k);
        }
    }
};

//This function will generate the random arrays based on the size given
void randArray(unsigned int array[], int sizeOfArray)
{
    /*    Initialize random seed     */
    srand(time(NULL));

    cout << "Size of Array: " << sizeOfArray << endl;
    for (int i = 0; i < sizeOfArray; i++)
    {
        array[i] = rand() % sizeOfArray + 1;
    }
}

//This function calls all the algorithms for each array which are passed as parameters
void arrayTesting(unsigned int array[], unsigned int tempArray[], int size, string x)
{

    /*                Calling all algorithms for ARRAY1             */
    Algorithms algo; //Creating the algo object which will call all algorithms for each array

    cout << endl
         << "               " << x << "TEST " << endl;

    /*                         SELECTION SORT                           */
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    algo.counter = 0;                    //Set counter to 0
    algo.selectionSort(tempArray, size); //Run selection sort algo

    // Get ending timepoint
    auto stop = high_resolution_clock::now();
    // Get duration. Substart timepoints to
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Number of comparisons using Selection sort: " << algo.counter << "  |  Running-Time: " << duration.count() << endl;

    //Assign back the values of the array to tempArray to re-sort
    for (int i = 0; i < size; i++)
    {
        tempArray[i] = array[i];
    }

    /*                          INSERTION SORT                        */
    // Get starting timepoint
    start = high_resolution_clock::now();

    algo.counter = 0;
    algo.insertionSort(tempArray, size);

    // Get ending timepoint
    stop = high_resolution_clock::now();
    // Get duration. Substart timepoints to
    // get durarion. To cast it to proper unit
    // use duration cast method
    duration = duration_cast<microseconds>(stop - start);
    cout << "Number of comparisons using Insertion sort: " << algo.counter << "    |  Running-Time: " << duration.count() << endl;

    //Assign back the values of the array to tempArray to re-sort
    for (int i = 0; i < size; i++)
    {
        tempArray[i] = array[i];
    }

    /*                           QUICK SORT                            */
    // Get starting timepoint
    start = high_resolution_clock::now();

    algo.counter = 0;
    algo.quickSort(tempArray, 0, size - 1);

    // Get ending timepoint
    stop = high_resolution_clock::now();
    // Get duration. Substart timepoints to
    // get durarion. To cast it to proper unit
    // use duration cast method
    duration = duration_cast<microseconds>(stop - start);

    cout << "Number of comparisons using Quick sort: " << algo.counter << "    |  Running-Time:  " << duration.count() << endl;

    //Assign back the values of the array to tempArray to re-sort
    for (int i = 0; i < size; i++)
    {
        tempArray[i] = array[i];
    }

    /*                            SHELL SORT                         */
    // Get starting timepoint
    start = high_resolution_clock::now();

    algo.counter = 0;
    int gapValues[size];

    //Get
    for (int z = 0; z < size; z++)
    {
        gapValues[z] = floor(pow(2, log2(size - z)) - 1);
        if (gapValues[z] < 1)
        {
            gapValues[z] = 1;
        }
    }

    int gapValueSize = sizeof(gapValues) / sizeof(gapValues[0]);
    algo.shellSort(tempArray, size, gapValues, gapValueSize);

    // Get ending timepoint
    stop = high_resolution_clock::now();
    // Get duration. Substart timepoints to
    // get durarion. To cast it to proper unit
    // use duration cast method
    duration = duration_cast<microseconds>(stop - start);

    cout << "Number of comparisons using Shell Sort: " << algo.counter << "   |  Running-Time: " << duration.count() << endl;

    for (int i = 0; i < size; i++)
    {
        tempArray[i] = array[i];
    }

    /*                           MERGE SORT                          */
    // Get starting timepoint
    start = high_resolution_clock::now();

    algo.counter = 0;
    algo.mergeSort(tempArray, 0, size - 1);

    // Get ending timepoint
    stop = high_resolution_clock::now();
    // Get duration. Substart timepoints to
    // get durarion. To cast it to proper unit
    // use duration cast method
    duration = duration_cast<microseconds>(stop - start);
    cout << "Number of comparisons using Merge Sort: " << algo.counter << "   | Running-Time: " << duration.count() << endl;

    for (int i = 0; i < size; i++)
    {
        tempArray[i] = array[i];
    }
}

// ==================================   MAIN   ==========================================
int main()
{
    //Initializing the arrays of {10^3, 5x10^3, 10^4, 5x10^4, 10^5} sizes
    unsigned int array1[1000];
    unsigned int array2[5000];
    unsigned int array3[10000];
    unsigned int array4[50000];
    unsigned int array5[100000];

    //Initializing the tempArrays of {10^3, 5x10^3, 10^4, 5x10^4, 10^5} sizes that
    //will actually be the ones being sorted and after sorting with one sorting algo
    //will be assigned the values of the originals arrays again to be re-sorted
    unsigned int tempArray1[1000];
    unsigned int tempArray2[5000];
    unsigned int tempArray3[10000];
    unsigned int tempArray4[50000];
    unsigned int tempArray5[100000];

    //Create random values for each array
    randArray(array1, sizeof(array1) / sizeof(array1[0]));
    randArray(array2, sizeof(array2) / sizeof(array2[0]));
    randArray(array3, sizeof(array3) / sizeof(array3[0]));
    randArray(array4, sizeof(array4) / sizeof(array4[0]));
    randArray(array5, sizeof(array5) / sizeof(array5[0]));

    const int size1 = sizeof(array1) / sizeof(array1[0]);
    const int size2 = sizeof(array2) / sizeof(array2[0]);
    const int size3 = sizeof(array3) / sizeof(array3[0]);
    const int size4 = sizeof(array4) / sizeof(array4[0]);
    const int size5 = sizeof(array5) / sizeof(array5[0]);

    arrayTesting(array1, tempArray1, size1, "Array1");
    arrayTesting(array2, tempArray2, size2, "Array2");
    arrayTesting(array3, tempArray3, size3, "Array3");
    arrayTesting(array4, tempArray4, size4, "Array4");
    arrayTesting(array5, tempArray5, size5, "Array5");
}