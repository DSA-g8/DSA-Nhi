#include <iostream>
#include <string>
using namespace std;

void displayUsage() {
    cout << "Command 1: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]" << endl;
    cout << "Command 2: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]" << endl;
    cout << "Command 3: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]" << endl;
    cout << "Command 4: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]" << endl;
    cout << "Command 5: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]" << endl;
}

bool isNumber(const string& str) {
    for (char const &c : str) {
        if (isdigit(c) == 0) {
            return false;
        }
    }
    return true;
}

