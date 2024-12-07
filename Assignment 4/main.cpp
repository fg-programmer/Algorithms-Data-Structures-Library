#include "Spice.h"

int main() {
    vector<Spice> spices;
    vector<int> knapsack_cpcity;
    parseInput("spice.txt", spices, knapsack_cpcity);
    fractionalKnapsack(spices, knapsack_cpcity);
    return 0;
}
