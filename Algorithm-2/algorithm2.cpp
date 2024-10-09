#include <iostream>
#include <vector>
using namespace std;

int findStartingCity(const vector<int>& city_distances, const vector<int>& fuel, int mpg) {
    int total_fuel = 0;      // Total fuel over all cities
    int current_fuel = 0;    // Current fuel balance during the trip
    int starting_city = 0;   // The index of the starting city
    
    // Traverse through each city
    for (int i = 0; i < city_distances.size(); ++i) {
        // Calculate fuel balance: fuel[i] * mpg gives the miles you can drive from that fuel
        current_fuel += (fuel[i] * mpg) - city_distances[i];
        
        // If current fuel is negative, we can't start from this city, so reset the start
        if (current_fuel < 0) {
            starting_city = i + 1;  // The next city might be the new start
            total_fuel += current_fuel;  // Add this fuel loss to the total fuel balance
            current_fuel = 0;  // Reset current fuel for the next possible starting point
        }
    }
    
    // Final check: If we have enough total fuel to finish the trip
    if (total_fuel + current_fuel >= 0) {
        return starting_city;
    } else {
        return -1;  // No valid starting city
    }
}

int main() {
    vector<int> city_distances = {5, 25, 15, 10, 15};
    vector<int> fuel = {1, 2, 1, 0, 3};
    int mpg = 10;
    
    int result = findStartingCity(city_distances, fuel, mpg);
    
    if (result != -1) {
        cout << "The preferred starting city is city " << result << endl;
    } else {
        cout << "No valid starting city found." << endl;
    }

    return 0;
}
