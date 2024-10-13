# Project1_CPSC335
**1st Project for Algorithm Engineering**


### Algorithm 1:
This C++ program prompts the user to input integer values to fill an array. The main objective is to sort the array such that each integer is positioned next to its corresponding paired value. To achieve this, the algorithm utilizes an unordered map to track the positions of each integer and its pair. The overall time complexity is O(n), leveraging the unordered map for efficient lookups, the find() function to locate pair values, and the swap() function to rearrange elements in constant time (O(1)). This approach ensures a swift and effective sorting of paired integers in the array.

### Algorithm 2:
This C++ program determines the best starting city for a road trip based on distances to the next cities and available fuel at each city. The function findStartingCity calculates whether it is feasible to travel through all the cities given their distances and the fuel supplied at each. It iterates through the cities, adjusting the current fuel balance and resetting the starting city index whenever the fuel becomes insufficient. After checking all cities, if there is enough total fuel to complete the trip, it returns the index of the optimal starting city; otherwise, it indicates that no valid starting city exists. The program demonstrates this logic with a sample set of city distances and fuel values.

### Algorithm 3: 
This C++ program manages and analyzes schedules for two individuals to identify available time slots for a meeting. It accepts input for each person's busy and free time intervals, parsing these times into a format suitable for processing. The program converts time strings to minutes and vice versa, computes the union of busy periods, finds the intersection of free periods, and then subtracts busy times from the free times to determine available slots. Finally, it checks if these available periods are long enough to accommodate a requested meeting duration, outputting the suitable time slots in a specified format. The program does not currently handle input errors.

---
*Each folder includes the code and a pdf breakdown of the pseudocode, time complexity, and space complexity*
