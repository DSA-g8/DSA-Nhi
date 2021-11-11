#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include "DataGenerator.h"
#include "algorithms.h"

using namespace std;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;

int *readDataFromFile(string input_file, int &size)
{
    ifstream fi(input_file);
    if (!fi.is_open())
    {
        cerr << "Can't open file" << endl;
    }

    string s, num;
    getline(fi, s);
    size = stoi(s);
    int *array = new int[size];

    getline(fi, s);
    stringstream ss(s);
    for (int i = 0; i < size; i++)
    {
        getline(ss, num, ' ');
        array[i] = stoi(num);
    }

    fi.close();

    return array;
}

void writeToOutputFile(string output_file, int *array, int size)
{
    ofstream fo(output_file);
    for (int i = 0; i < size; i++)
    {
        fo << array[i] << " ";
    }
    fo.close();
}

void writeToInputFile(string input_file, int array[], int size)
{
    ofstream fo(input_file);
    fo << size << endl;
    for (int i = 0; i < size; i++)
    {
        fo << array[i] << " ";
    }
    fo.close();
}

<<<<<<< HEAD
void checkInputOrder(string input_order, int &flag_order, string &order_display) {
    if (input_order == "-rand")
    {
        flag_order = 0;
        order_display = "Random";
    }
    else if (input_order == "-sorted")
    {
        flag_order = 1;
        order_display = "Sorted";
    }
    else if (input_order == "-rev")
    {
        flag_order = 2;
        order_display = "Reverse";
    }
    else
    {
        flag_order = 3;
        order_display = "Nearly sorted";
    }
}

=======
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
void selectAlgorithmWithTime(string algorithm_name, int *array, int size, double &time)
{
    duration<double, milli> exec_time;
    high_resolution_clock::time_point start_time;
    high_resolution_clock::time_point end_time;

    if (algorithm_name == "selection-sort")
    {
        start_time = high_resolution_clock::now();
        selectionSortWithTime(array, size);
        end_time = high_resolution_clock::now();
        exec_time = end_time - start_time;
    }
    else if (algorithm_name == "insertion-sort")
    {
<<<<<<< HEAD
        start_time = high_resolution_clock::now();
        insertionSortWithTime(array, size);
        end_time = high_resolution_clock::now();
        exec_time = end_time - start_time;
=======
        // insertion sort
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
    }
    else if (algorithm_name == "bubble-sort")
    {
        start_time = high_resolution_clock::now();
        bubbleSortWithTime(array, size);
        end_time = high_resolution_clock::now();
        exec_time = end_time - start_time;
    }
    else if (algorithm_name == "heap-sort")
    {
        start_time = high_resolution_clock::now();
        heapSortWithTime(array, size);
        end_time = high_resolution_clock::now();
        exec_time = end_time - start_time;
    }
    else if (algorithm_name == "merge-sort")
    {
        start_time = high_resolution_clock::now();
        mergeSortWithTime(array, 0, size - 1);
        end_time = high_resolution_clock::now();
        exec_time = end_time - start_time;
    }
    else if (algorithm_name == "quick-sort")
    {
<<<<<<< HEAD
        start_time = high_resolution_clock::now();
        quickSorWithTime(array, 0, size - 1);
        end_time = high_resolution_clock::now();
        exec_time = end_time - start_time;
=======
        // quick sort
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
    }
    else
    {
        start_time = high_resolution_clock::now();
        radixSortWithTime(array, size);
        end_time = high_resolution_clock::now();
        exec_time = end_time - start_time;
    }

    time = exec_time.count();
}

void selectAlgorithmWithComparison(string algorithm_name, int *array, int size, unsigned long long &count_compare)
{
    if (algorithm_name == "selection-sort")
    {
        selectionSortWithComparison(array, size, count_compare);
    }
    else if (algorithm_name == "insertion-sort")
    {
<<<<<<< HEAD
        insertionSortWithComparison(array, size, count_compare);
=======
        // insertion sort
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
    }
    else if (algorithm_name == "bubble-sort")
    {
        bubbleSortWithComparison(array, size, count_compare);
    }
    else if (algorithm_name == "heap-sort")
    {
        heapSortWithComparison(array, size, count_compare);
    }
    else if (algorithm_name == "merge-sort")
    {
        mergeSortWithComparison(array, 0, size - 1, count_compare);
    }
    else if (algorithm_name == "quick-sort")
    {
<<<<<<< HEAD
        quickSorWithComparison(array, 0, size - 1, count_compare);
=======
        // quick sort
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
    }
    else
    {
        radixSortWithComparison(array, size, count_compare);
    }
}

// Command 1 ------------------------------------------------------------------------
void runCommand1(string algorithm_name, string input_file, string output_param)
{
    unsigned long long count_compare = 0;
    double time = 0;
    int size = 0;
    int *array = readDataFromFile(input_file, size);

    // Display necessary informations
    cout << "Input file: " << input_file << endl;
    cout << "Input size: " << size << endl;
    cout << "------------------------" << endl;

    // Implement the algorithms
    if (output_param == "-time")
    {
        selectAlgorithmWithTime(algorithm_name, array, size, time);

        cout << "Running time: " << time << " (ms)" << endl;
    }
    else if (output_param == "-comp")
    {
        selectAlgorithmWithComparison(algorithm_name, array, size, count_compare);
        cout << "Comparisons: " << count_compare << endl;
    }
    else
    {
        //Create and copy data from main array to a second array for sorting to count comparisons
        int *second_array = new int[size];
        for (int i = 0; i < size; i++) {
            second_array[i] = array[i];
        }

        selectAlgorithmWithTime(algorithm_name, array, size, time);
        selectAlgorithmWithComparison(algorithm_name, second_array, size, count_compare);

        cout << "Running time: " << time << " (ms)" << endl;
        cout << "Comparisons: " << count_compare << endl;

        //Delete the second array as it's not needed anymore
        delete[] second_array;
    }

    // Write the sorted array to file
    writeToOutputFile("output.txt", array, size);

    delete[] array;
}

// Command 2 ----------------------------------------------------------------------------------------
void runCommand2(string algorithm_name, int size, string input_order, string output_param)
{
    double time = 0;
    unsigned long long count_compare = 0;
    int *array = new int[size];
<<<<<<< HEAD
    int flag_order = 0;
    string order_display;

    //Check input order to change flag_order and order_display accordingly
    checkInputOrder(input_order, flag_order, order_display);
=======
    int FLAG_ORDER;
    string order;

    if (input_order == "-rand")
    {
        FLAG_ORDER = 0;
        order = "Random";
    }
    else if (input_order == "-sorted")
    {
        FLAG_ORDER = 1;
        order = "Sorted";
    }
    else if (input_order == "-rev")
    {
        FLAG_ORDER = 2;
        order = "Reverse";
    }
    else
    {
        FLAG_ORDER = 3;
        order = "Nearly sorted";
    }
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e

    // Display necessary informations
    cout << "Input size: " << size << endl;
    cout << "Input order " << order_display << endl;
    cout << "------------------------" << endl;

    // Generate data for main array
<<<<<<< HEAD
    GenerateData(array, size, flag_order);
=======
    GenerateData(array, size, FLAG_ORDER);
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
    writeToInputFile("input.txt", array, size);

    // Implement the algorithm here
    if (output_param == "-time")
    {
        selectAlgorithmWithTime(algorithm_name, array, size, time);
        cout << "Running time: " << time << " (ms)" << endl;
    }
    else if (output_param == "-comp")
    {
        selectAlgorithmWithComparison(algorithm_name, array, size, count_compare);
        cout << "Comparisons: " << count_compare << endl;
    }
    else
    {
        //Create and copy data from main array to a second array for sorting to count comparisons
        int *second_array = new int[size];
        for (int i = 0; i < size; i++) {
            second_array[i] = array[i];
        }

        selectAlgorithmWithTime(algorithm_name, array, size, time);
        selectAlgorithmWithComparison(algorithm_name, second_array, size, count_compare);

        cout << "Running time: " << time << " (ms)" << endl;
        cout << "Comparisons: " << count_compare << endl;

        //Delete second array as it's not needed anymore
        delete[] second_array;
    }

    // Write sorted array to output file
    writeToOutputFile("output.txt", array, size);

    delete[] array;
}

// Command 3 ----------------------------------------------------------------------------------------
void runCommand3(string algorithm_name, int size, string output_param)
{
    double time = 0;
    unsigned long long count_compare = 0;
    int* array1 = new int[size];
    int* array2 = new int[size];
    int* array3 = new int[size];
    int* array4 = new int[size];
    
     // Display necessary informations
    cout << "Input size: " << size << endl;
    
    // Implement the algorithm here
    // With Ramdom Data
    cout << "Input order: Random" << endl;
    cout << "------------------------" << endl;
    
    GenerateData(array1, size, 0);
    
    if (output_param == "-time")
    {
        selectAlgorithmWithTime(algorithm_name, array1, size, time);
        cout << "Running time: " << time << " (ms)" << endl;
    }
    else if (output_param == "-comp")
    {
        selectAlgorithmWithComparison(algorithm_name, array1, size, count_compare);
        cout << "Comparisons: " << count_compare << endl;
    }
    else
    {
        //Create and copy data from main array to a second array for sorting to count comparisons
        int *second_array1 = new int[size];
        for (int i = 0; i < size; i++) {
            second_array1[i] = array1[i];
        }

        selectAlgorithmWithTime(algorithm_name, array1, size, time);
        selectAlgorithmWithComparison(algorithm_name, second_array1, size, count_compare);

        cout << "Running time: " << time << " (ms)" << endl;
        cout << "Comparisons: " << count_compare << endl;

        //Delete second array as it's not needed anymore
        delete[] second_array1;
    }
    
    // With Sorted Data
    cout << "Input order: Sorted" << endl;
    cout << "------------------------" << endl;
    
    GenerateData(array2, size, 1);
    
    if (output_param == "-time")
    {
        selectAlgorithmWithTime(algorithm_name, array2, size, time);
        cout << "Running time: " << time << " (ms)" << endl;
    }
    else if (output_param == "-comp")
    {
        selectAlgorithmWithComparison(algorithm_name, array2, size, count_compare);
        cout << "Comparisons: " << count_compare << endl;
    }
    else
    {
        //Create and copy data from main array to a second array for sorting to count comparisons
        int *second_array2 = new int[size];
        for (int i = 0; i < size; i++) {
            second_array2[i] = array2[i];
        }

        selectAlgorithmWithTime(algorithm_name, array2, size, time);
        selectAlgorithmWithComparison(algorithm_name, second_array2, size, count_compare);

        cout << "Running time: " << time << " (ms)" << endl;
        cout << "Comparisons: " << count_compare << endl;

        //Delete second array as it's not needed anymore
        delete[] second_array2;
    }
    
    // With Reverse Data
    cout << "Input order: Reverse" << endl;
    cout << "------------------------" << endl;
    
    GenerateData(array3, size, 2);
    
    if (output_param == "-time")
    {
        selectAlgorithmWithTime(algorithm_name, array3, size, time);
        cout << "Running time: " << time << " (ms)" << endl;
    }
    else if (output_param == "-comp")
    {
        selectAlgorithmWithComparison(algorithm_name, array3, size, count_compare);
        cout << "Comparisons: " << count_compare << endl;
    }
    else
    {
        //Create and copy data from main array to a second array for sorting to count comparisons
        int *second_array3 = new int[size];
        for (int i = 0; i < size; i++) {
            second_array3[i] = array3[i];
        }

        selectAlgorithmWithTime(algorithm_name, array3, size, time);
        selectAlgorithmWithComparison(algorithm_name, second_array3, size, count_compare);

        cout << "Running time: " << time << " (ms)" << endl;
        cout << "Comparisons: " << count_compare << endl;

        //Delete second array as it's not needed anymore
        delete[] second_array3;
    }
    
     // With NearlySorted Data
    cout << "Input order: NearlySorted" << endl;
    cout << "------------------------" << endl;
    
    GenerateData(array4, size, 3);
    
    if (output_param == "-time")
    {
        selectAlgorithmWithTime(algorithm_name, array4, size, time);
        cout << "Running time: " << time << " (ms)" << endl;
    }
    else if (output_param == "-comp")
    {
        selectAlgorithmWithComparison(algorithm_name, array4, size, count_compare);
        cout << "Comparisons: " << count_compare << endl;
    }
    else
    {
        //Create and copy data from main array to a second array for sorting to count comparisons
        int *second_array4 = new int[size];
        for (int i = 0; i < size; i++) {
            second_array4[i] = array4[i];
        }

        selectAlgorithmWithTime(algorithm_name, array4, size, time);
        selectAlgorithmWithComparison(algorithm_name, second_array4, size, count_compare);

        cout << "Running time: " << time << " (ms)" << endl;
        cout << "Comparisons: " << count_compare << endl;

        //Delete second array as it's not needed anymore
        delete[] second_array4;
    }
    
    // Write sorted array to output file
    writeToOutputFile("output.txt", array1, size);
    writeToOutputFile("output.txt", array2, size);
    writeToOutputFile("output.txt", array3, size);
    writeToOutputFile("output.txt", array4, size);

    delete[] array1, array2, array3, array4;
}      

// Command 4 ----------------------------------------------------------------------------------------
void runCommand4(string algorithm_name, string algorithm_name1, string input_file)
{
    unsigned long long count_compare = 0, count_compare1 = 0;
    double time = 0, time1 = 0;
    int size = 0;
    int *array1 = readDataFromFile("input.txt", size);
    int *array2 = readDataFromFile("input.txt", size);
    int *array3 = readDataFromFile("input.txt", size);
    int *array4 = readDataFromFile("input.txt", size);

    // Display necessary informations
    cout << "Input file: " << input_file << endl;
    cout << "Input size: " << size << endl;
    cout << "------------------------" << endl;

    // Time and counting comparasion
    selectAlgorithmWithTime(algorithm_name, array1, size, time);
    selectAlgorithmWithTime(algorithm_name1, array2, size, time1);
    selectAlgorithmWithComparison(algorithm_name, array3, size, count_compare);
    selectAlgorithmWithComparison(algorithm_name1, array4, size, count_compare1);

    cout << "Running time: " << time << "(ms) | " << time1 << "(ms)" << endl;
    cout << "Comparisons: " << count_compare << " | " << count_compare1 << endl;

    // Write the sorted array to file
    writeToOutputFile("output.txt", array1, size);

    delete[] array1, array2, array3, array4;
<<<<<<< HEAD
}

//Command 5 ------------------------------------------------------------------------
void runCommand5(string algorithm_name1, string algorithm_name2, int size, string input_order) {
    unsigned long long count_compare1 = 0, count_compare2 = 0;
    double time1 = 0, time2 = 0;
    int* array1 = new int[size];
    int* array2 = new int[size];
    int* array3 = new int[size];
    int* array4 = new int[size];
    int flag_order = 0;
    string order_display;

    //Check input order to change flag_order and order_display accordingly
    checkInputOrder(input_order, flag_order, order_display);

    //Generate data
    GenerateData(array1, size, flag_order);
    //Copy data from array1 to other arrays
    for (int i = 0; i < size; i++) {
        array2[i] = array1[i];
        array3[i] = array1[i];
        array4[i] = array1[i];
    }

    //Write generated array to file
    writeToInputFile("input.txt", array1, size);

    //Display necessary informations
    cout << "Input size: " << size << endl;
    cout << "Input order: " << order_display << endl;
    cout << "------------------------" << endl;

    //Time and counting comparasion
    selectAlgorithmWithTime(algorithm_name1, array1, size, time1);
    selectAlgorithmWithTime(algorithm_name2, array2, size, time2);
    selectAlgorithmWithComparison(algorithm_name1, array3, size, count_compare1);
    selectAlgorithmWithComparison(algorithm_name2, array4, size, count_compare2);
    cout << "Running time: " << time1 << " (ms) | " << time2 << " (ms)" << endl;
    cout << "Comparisons: " << count_compare1 << " | " << count_compare2 << endl;

    delete[] array1, array2, array3, array4;
=======
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
}
