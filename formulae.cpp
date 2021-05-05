#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// INCLUDES MEAN, MEDIAN, BUBBLESORT, INTERQUARTILE RANGE, POPULATION VARIANCE, POPULATION STANDARD DEVIATION, 
// SAMPLE VARIANCE, SAMPLE STANDARD DEVIATION, AND QUADRATIC EQUATION

double meanCalc(vector<double> nums, int c) {
    double sum = 0;
    for (int i = 0; i < c; i++) {
        sum += nums[i];
    }
    return sum/c;
}

// Use bubbleSort() for actual bubblesorting. _bs() is just part of the process
vector<double> _bs(vector<double> nums, int c) {
    double temp;
    for (int i = 1; i < c; i++) {
        temp = nums[i - 1];
        if (temp > nums[i]) {
            temp = nums[i - 1];
            nums[i - 1] = nums[i];
            nums[i] = temp;
        }
    }
    return nums;
}

vector<double> bubbleSort(vector<double> nums, int c) {
    vector<double> result;
    double temp = nums[0];
    for (int i = 0; i < c; i++) {
        nums = _bs(nums, c-1);
    }
    return nums;
}

double medianCalc(vector<double> nums) {
    double median;
    int c = nums.size();
    bool even = false;
    if (c % 2 == 0) {
        even = true;
    }
    
    c = (c+1)/2;
    if (!even) {
        median = nums[c-1];
    } else {
        median = (nums[c-1] + nums[c])/2;
    }
    return median;
}

double squareSum(vector<double> nums, int c) {
    double result = 0;
    double mean = meanCalc(nums, c);
    for (int i = 0; i < c; i++) {
        result += (nums[i] - mean) * (nums[i] - mean);
    }
    return result;
}

double popVariance(vector<double> nums, int c) {
    double sumOsquares = squareSum(nums, c);
    return sumOsquares/c;
}

double populationStandardDeviation(vector<double> nums, int c) {
    return sqrt(popVariance(nums, c));
}

double sampleVariance(vector<double> nums, int c) {
    double sumOsquares = squareSum(nums, c);
    return sumOsquares/(c-1);
}

double sampleStandardDeviation(vector<double> nums, int c) {
    return sqrt(sampleVariance(nums, c));
}

double iqrCalc(vector<double> nums, int c) {
    vector<double> lowerQuartile;
    vector<double> upperQuartile;

    if (c % 2 == 0) {
        // Splits data set into upper and lower quartile for even number of vals
        for (int i = 0, j = c/2; i < j; i++) {
            lowerQuartile.push_back(nums[i]);
        }

        for (int i = c/2; i < c; i++) {
            upperQuartile.push_back(nums[i]);
        }
    } else {
        // Splits data set into upper and lower quartile for odd number of vals
        for (int i = 0, j = (c-1)/2; i < j; i++) {
            lowerQuartile.push_back(nums[i]);
        }

        for (int i = (c+1)/2; i < c; i++) {
            upperQuartile.push_back(nums[i]);
        }
    }

    double Q1 = medianCalc(lowerQuartile); // median of lowerQ
    double Q3 = medianCalc(upperQuartile); // median of upperQ
    double result = Q3 - Q1;
    cout << "Q1 = " << Q1 << endl;
    cout << "Q3 = " << Q3 << endl;
    cout << "Interquartile Range = " << Q3 - Q1 << endl;
    cout << "Lower Boundary = " << Q1 - (1.5 * result) << endl; // Calculates and displays lower bound
    cout << "Upper Boundary = " << Q3 + (1.5 * result) << endl; // Calculates and displays upper bound
    return result;
}

vector<double> quadratic(double a, double b, double c) {
    double x1, x2;
    vector<double> answer;
    double d = (b*b)-4*a*c;
    x1 = (-b + sqrt(d))/(2*a);
    x2 = (-b - sqrt(d))/(2*a);
    answer.push_back(x1);
    answer.push_back(x2);
    return answer;
}

double lowerBound() {
    double freq_lower;
    cout << "Enter the lower bound for the first frequency set: ";
    cin >> freq_lower;
    return freq_lower;
}

double upperBound() {
    double freq_upper;
    cout << "Enter the upper bound for the first frequency set: ";
    cin >> freq_upper;
    return freq_upper;
}

void freqChart(double highestNum) {
    double freq_lower = lowerBound();
    double freq_upper = upperBound();

    double range = freq_upper - freq_lower;
    vector<string> frequencySets;
    frequencySets.push_back("\n" + to_string(freq_lower) + " - " + to_string(freq_upper));
    cout << frequencySets[0] << endl;
}