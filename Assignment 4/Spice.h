#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Structure to store spice details
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
            int quantity;
            iss.ignore(15, '='); // Skip "spice name ="
            iss >> name;
            iss.ignore(20, '='); // Skip "total_price ="
            iss >> total_price;
            iss.ignore(10, '='); // Skip "quantity ="
            iss >> quantity;
            spices.emplace_back(name, total_price, quantity);
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
void fractionalKnapsack(const vector<Spice>& spices, vector<int>& knapsacks) {
    vector<Spice> sorted_spices = spices;
    // Sort spices by value per unit in descending order
    sort(sorted_spices.begin(), sorted_spices.end(), [](const Spice& a, const Spice& b) {
        return a.value_per_unit > b.value_per_unit;
    });

    for (int capacity : knapsacks) {
        double total_value = 0.0;
        cout << "Knapsack capacity: " << capacity << ":\n";
        for (const Spice& spice : sorted_spices) {
            if (capacity == 0) break;

            int amnt_took = min(capacity, spice.quantity);
            double val_taken = amnt_took * spice.value_per_unit;
            total_value += val_taken;
            capacity -= amnt_took;

            cout << "  Took " << amnt_took << " of " << spice.name
                 << " (value: " << fixed << setprecision(2) << val_taken << ")\n";
        }
        cout << "Total value in knapsack: " << fixed << setprecision(2) << total_value << "\n\n";
    }
}

