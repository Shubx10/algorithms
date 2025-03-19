#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    
    double totalValue = 0.0;
    
    for (const auto& item : items) {
        if (W >= item.weight) {
            W -= item.weight;
            totalValue += item.value;
        } else {
            totalValue += item.ratio * W;
            break;
        }
    }
    
    return totalValue;
}

int main() {
    int W = 50; // Maximum weight
    vector<Item> items = {
        {60, 10, 6.0},
        {100, 20, 5.0},
        {120, 30, 4.0}
    };

    // Calculate ratio for each item
    for (auto& item : items) {
        item.ratio = (double)item.value / item.weight;
    }

    cout << "Maximum value in Fractional Knapsack = " << fractionalKnapsack(W, items) << endl;
    return 0;
}
