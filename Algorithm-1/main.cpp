#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> fill_vector(vector<int>& row);
static void display_vector(vector<int>& row);
static int swap_vector(vector<int>& row);
bool test_for_dups(vector<int>& row);

const std::string startPrompt = "Enter the size of the row (Even Number between 2 - 30): ";
const std::string inputPrompt = "Fill the row with the Individual integers (Do not repeat values):\n";

//static map filled with variable pairs
const unordered_map<int, int> PAIRS = 
{
		{0, 1}, {1, 0},
		{2, 3}, {3, 2},
		{4, 5}, {5, 4},
		{6, 7}, {7, 6},
		{8, 9}, {9, 8},
		{10, 11}, {11, 10},
		{12, 13}, {13, 12},
		{14, 15}, {15, 14},
		{16, 17}, {17, 16},
		{18, 19}, {19, 18},
		{20, 21}, {21, 20},
		{22, 23}, {23, 22},
		{24, 25}, {25, 24},
		{26, 27}, {27, 26},
		{28, 29}, {29, 28}
};



int main()
{
	int rowSize = 0;
	int count = 0;
	bool duplicates = false;

	std::cout << startPrompt;
	std::cin >> rowSize;

	if (rowSize < 0 || rowSize % 2 !=0 || rowSize > 30) 
	{
		std::cout << "Error 1:: Invalid Input for Row Size.\nExiting Program.";
		return 0;
	}

	vector<int> row;
	row.resize(rowSize);

	std::cout << inputPrompt;
	row = fill_vector(row);
	duplicates = test_for_dups(row);

	if (duplicates) 
	{
		std::cout << "Error 2: User Input included duplicate values.\nExiting Program";
			return 0;
	}

	std::cout << "The Row is: ";
	display_vector(row);
	std::cout << "\n";

	count = swap_vector(row);

	std::cout << "The amount of swaps: " << count << "\n\n";

	std::cout << "The new Row is: ";
	display_vector(row);

	return 0;
}

//Takes in user input of integer values
vector<int> fill_vector(vector<int>& row)
{
	for (int i = 0; i < row.size(); i++)
	{
		int val = 0;
		std::cin >> val;
		row.at(i) = val;
	}
	
	return row;
}

//Displays the vector
void display_vector(vector<int>& row)
{
	for (int i = 0; i < row.size(); i++) 
	{
		std::cout << row[i] << " ";
	}
	std::cout << endl;
}

//Swap algorithm in linear time using 2 pointer variables.
int swap_vector(vector<int>& row)
{
	int swap_count = 0; //tracks the count of swaps
	int base = 0;//tracks the base integer being compared
	int point = 0; //tracks the integer being compared to base_value

	while (base < (row.size() - 2)) 
	{
		if (row[base + 1] == PAIRS.at(row[base]) || row[base] == PAIRS.at(row[base + 1]))
		{
			base = base + 2;
			break;
		}

		// for loop begins if the couple is not paired together
		for (point = base + 2; point < row.size(); point++) {
			if (row[point] == PAIRS.at(row[base]) || row[base] == PAIRS.at(row[point])) 
			{
				int temp = row[base + 1];
				row[base + 1] = row[point];
				row[point] = temp;
				base = base + 2;
				swap_count++;
				break;
			}
		}
	}

	return swap_count;
}

//test for duplicate input using sort function which is O(N log N) time
bool test_for_dups(vector<int>& row)
{
	vector<int> temp = row;
	sort(temp.begin(), temp.end()); // O(N log N)
	for (int i = 0; i < temp.size() - 1; i++) 
	{
		if (temp[i] == temp[i + 1])
			return true;
	}

	return false;
}
