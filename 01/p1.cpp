#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

int main() {

    // read input
    std::ifstream file("input.txt");
    if (!file)
    {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }
    
    // turn into lists/vectors
    std::vector<int> left;
    std::vector<int> right;

    std::string line;
    while (std::getline(file, line))
    {
        size_t pos = line.find("   ");
        if (pos != std::string::npos)
        {
            int numL = std::stoi(line.substr(0, pos));
            int numR = std::stoi(line.substr(pos + 3));
            left.push_back(numL);
            right.push_back(numR);
        }
        else
        {
            std::cerr << "Error Incorrect file format on line " << line << std::endl;
        }
    }
    file.close();

    //sort lists
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    // generate vector of differences
    std::vector<int> differences;
    for (size_t i = 0; i < left.size(); i++)
    {
        differences.push_back(std::abs(left[i] - right[i]));
    }
    
    // sum up vector
    int sum;
    for (size_t i = 0; i < differences.size(); i++)
    {
        sum += differences[i];
    }
    
    std::cout << sum << std::endl;

    // std::cout << "List 1: ";
    // for (int num : left) std::cout << num  << " ";
    // std::cout << "\nList 2: ";
    // for (int num : right) std::cout << num  << " ";
    // std::cout << "\nDifferences: ";
    // for (int num : differences) std::cout << num  << " ";

    return 0;
}