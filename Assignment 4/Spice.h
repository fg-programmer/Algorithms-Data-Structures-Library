#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Struct to store spice details
struct Spice {
    string name;
    int quantity;
    double total_price;
    double value_per_unit;

    Spice(string n, double tp, int q) : name(n), total_price(tp), quantity(q) {
        value_per_unit = total_price / quantity;
    }
};

// Function to parse the input file
void parseInput(const string& filename, vector<Spice>& spices, vector<int>& knapsack_capacities) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);

        // Parse spice details
        if (line.find("spice name") != string::npos) {
            string name;
            double total_price;
            int qty;
            iss.ignore(15, '='); // Skip "spice name ="
            iss >> name;
            iss.ignore(20, '='); // Skip "total_price ="
            iss >> total_price;
            iss.ignore(10, '='); // Skip "qty ="
            iss >> qty;
            spices.emplace_back(name, total_price, qty);
        }

        // Parse knapsack capacities
        if (line.find("knapsack capacity") != string::npos) {
            int capacity;
            iss.ignore(20, '='); // Skip "knapsack capacity ="
            iss >> capacity;
            knapsack_capacities.push_back(capacity);
        }
    }
    file.close();
}

