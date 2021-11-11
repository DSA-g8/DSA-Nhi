#include <iostream>
#include <string>
#include "algorithms.h"
#include "commands.h"
#include "utilities.h"
using namespace std;

int main(int argc, char *argv[])
{
    int input_size;
    string algorithm_name, algorithm_name2;
    string input_file;
    string input_order;
    string output_param;
    string temp;
    string mode = argv[1];

    if (mode == "-a")
    {
        algorithm_name = argv[2];

        cout << "ALGORITHM MODE" << endl;
        cout << "Algorithm: " << algorithm_name << endl;

        if (argc == 6)
        {
            input_size = stoi(argv[3]);
            input_order = argv[4];
            output_param = argv[5];

            runCommand2(algorithm_name, input_size, input_order, output_param);
        }
        else
        {
            temp = argv[3];
            if (isNumber(temp))
            {
                // runCommand3();
            }
            else
            {
                input_file = temp;
                output_param = argv[4];
                runCommand1(algorithm_name, input_file, output_param);
            }
        }
    }
    else if (mode == "-c")
    {
        cout << "COMPARE MODE" << endl;
        // Implement mode comparison here
        algorithm_name = argv[2];
        algorithm_name2 = argv[3];

        cout << "Algorithm: " << algorithm_name << " | " << algorithm_name2 << endl;

        if (argc == 6)
        {
<<<<<<< HEAD
            input_size = stoi(argv[4]);
            input_order = argv[5];
            runCommand5(algorithm_name, algorithm_name2, input_size, input_order);
=======
            // runCommand5();
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
        }
        else
        {
            input_file = argv[4];
<<<<<<< HEAD
            runCommand4(algorithm_name, algorithm_name2, input_file);
=======
            runCommand4(algorithm_name, algorithm_name1, input_file);
>>>>>>> ff31632aa62dac561bcb59391a53ccfe3d0d667e
        }
    }
    else if (mode == "-h" || mode == "--help")
    {
        displayUsage();
    }
    else
    {
        displayUsage();
        return 1;
    }

    return 0;
}
