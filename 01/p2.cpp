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

    //calculate similarity score
    int simscore;
    for (size_t i = 0; i < left.size(); i++)
    {
        //find how many times left[i] appears in right
        int count = std::count(right.begin(), right.end(), left[i]);

        //add to score
        simscore += left[i] * count;
    }
    
    
    std::cout << simscore << std::endl;



    return 0;
}