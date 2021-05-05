#include <iostream>
#include "formulae.cpp"
using namespace std;

void data() {
    cout << "Press Enter when you're ready to begin";
    cin.get();

    // Create necessary variables to hold data set
    vector<double> numbers;
    double buffer;
    double count = 0;
    double NUMBERS = 0;

    cout << "Enter number: ";

    // Gets input and puts into vector "numbers", sums numbers, counts how many numbers

    while(cin >> buffer) {
        numbers.push_back(buffer);
        NUMBERS += buffer;
        count++;
        cout << "Enter number: ";
    }

    vector<double> sortedNums = bubbleSort(numbers, count + 1); // Arranges numbers lowest to highest

    // Displays arranged number list
    for (int i = 0; i < count; i++) {
        cout << sortedNums[i] << " ";
    }
    cout << endl;

    // Displays all the info
    cout << "Count: " << count << endl;
    cout << "Sum: " << NUMBERS << endl;
    cout << "Median: " << medianCalc(sortedNums) << endl;
    cout << "Mean: " << meanCalc(numbers, count) << endl;
    iqrCalc(sortedNums, count);                              // Interquartile Range
    cout << "Sum of Squares of Difference: " << squareSum(numbers, count) << endl;
    cout << "Population Variance: " << popVariance(numbers, count) << endl;
    cout << "Population Standard Deviation: " << populationStandardDeviation(numbers, count) << endl;
    cout << "Sample Variance: " << sampleVariance(numbers, count) << endl;
    cout << "Sample Standard Deviation: " << sampleStandardDeviation(numbers, count) << endl;
}

int main() {
    cout << "\n\nWelcome to the Data Calculator!\nThis program takes a set of data as input\nand outputs various info about the data set, such as\nthe ordered data set, mean, median, standard deviation, etc.\n";
    cout << "\nUSAGE:\nAfter you have put in your data set, enter a non-number character to display the info.\n\n";
   
    data();
    return 0;
}