#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

int main()
{
    // Read names into a vector of strings
    std::string filename = "names.txt";
    std::ifstream file(filename);
    std::string line;
    getline(file, line);
    std::stringstream ss(line);
    std::string cell;
    std::vector<std::string> names;
    while (std::getline(ss, cell, ','))
    {
        names.push_back(cell.substr(1, cell.length() - 2));
    }

    // Sort names alphabetically
    std::sort(names.begin(), names.end());

    // Initialize a sum of scores
    int sum = 0;

    // For each name,
    for (int i = 0; i < names.size(); i++)
    {
        // Calculate the score
        std::string name = names[i];
        int score = 0;
        for (char character : name)
        {
            score += character - (int)('A') + 1;
        }
        score *= i + 1;

        // Add score to sum
        sum += score;
    }

    // Return result
    std::cout << sum << std::endl;
}