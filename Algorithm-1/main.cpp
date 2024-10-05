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
const unordered_map<int, int> pairs = {
		{0, 1},
		{2, 3},
		{4, 5},
		{6, 7},
		{8, 9},
		{10, 11},
		{12, 13},
		{14, 15},
		{16, 17},
		{18, 19},
		{20, 21},
		{22, 23},
		{24, 25},
		{26, 27},
		{28, 29}
};



int main()
{
	int rowSize = 0;
	int count = 0;
	bool duplicates = false;

	std::cout << startPrompt;
	std::cin >> rowSize;

	if (rowSize < 0 || rowSize % 2 !=0 || rowSize > 30) {
		std::cout << "Error 1:: Invalid Input for Row Size.\nExiting Program.";
		return 0;
	}

	vector<int> row;
	row.resize(rowSize);

	std::cout << inputPrompt;
	row = fill_vector(row);
	duplicates = test_for_dups(row);

	if (duplicates) {
		std::cout << "Error 2: User Input included duplicate values.\nExiting Program";
			return 0;
	}

	std::cout << "The Row is: ";
	display_vector(row);

//	swap_vector(row);

	return 0;
}

vector<int> fill_vector(vector<int>& row)
{
	for (int i = 0; i < row.size(); i++) {
		int val = 0;
		std::cin >> val;
		row.at(i) = val;
	}
	
	return row;
}

void display_vector(vector<int>& row)
{
	for (int i = 0; i < row.size(); i++) {
		std::cout << row[i] << " ";
	}
	std::cout << endl;
}

int swap_vector(vector<int>& row)
{
	int swap_count = 0; //tracks the count of swaps
	int base_value = 0;//tracks the base integer being compared
	int point = 0; //tracks the integer being compared to base_value
	int end_index = row.size() - 1; //tracks last index of the row

	for (int i = 0; i < row.size(); i+2) {
		base_value = row.at(i);
		point = row.at(i + 1);

		if (base_value == point + 1 || base_value == point - 1)
			break;

	}
	return swap_count;
}

//linear time test for duplicate input
bool test_for_dups(vector<int>& row)
{
	sort(row.begin(), row.end()); // O(N log N)
	return adjacent_find(row.begin(), row.end()) == row.end();
}

/*[3,1,2,4]*/
