#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    
    // Declare second integer, double, and String variables.
    int a;
    double b;
    std::string stringName;
    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.

    std::cin>>a>>b;
    std::cin.get();
    std::getline(cin, stringName);
    // Print the sum of both integer variables on a new line.
    std::cout<<a+i<<std::endl;
    // Print the sum of the double variables on a new line.

    std::cout<<std::fixed<<std::setprecision(1)<<b+d<<std::endl;

    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    std::cout<<s+stringName<<std::endl;
    return 0;
}