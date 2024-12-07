#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>



bool testCalibration(const std::vector<int>& numbers, long long result);
void generateCombinations(int n, std::vector<int>& temp, int i, std::vector<std::vector<int>>& combinations );


int main() {

    // read input
    std::ifstream file("input.txt");
    if (!file)
    {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    //extract numbers
    std::vector<long long> results;
    std::vector<std::vector<int>> inputNums;

    std::string line;
    while (std::getline(file, line))
    {
        size_t colonPos = line.find(':');
        if (colonPos != std::string::npos) {
            std::string leftPart = line.substr(0, colonPos);
            results.push_back(std::stoll(leftPart));

            std::string rightPart = line.substr(colonPos + 1);
            std::istringstream rightStream(rightPart);
            std::vector<int> rightVector;
            int num;
            while (rightStream >> num)
            {
                rightVector.push_back(num);
            }
            inputNums.push_back(rightVector);
        }
    }
    file.close();


    //loop through results arr
    long long totalCalibrationResult = 0;
    for (size_t i = 0; i < results.size(); i++)
    {
        bool calibrationWorks = testCalibration(inputNums[i], results[i]);
        
        if (calibrationWorks) totalCalibrationResult += results[i];
    }
    
    //result p1
    std::cout << "Total calibration result: " << totalCalibrationResult << std::endl;

    return 0;
}

bool testCalibration(const std::vector<int>& numbers, long long result){

    // std::array<char, 2> operatorArr = {'+', '*'};
    int opcount = numbers.size() - 1;

    std::vector<std::vector<int>> combinations;
    std::vector<int> temp;
    generateCombinations(opcount, temp, 0, combinations);   

    //for permutation in combinations
    for (auto &&perm : combinations)
    {
        long long testsum = numbers[0];     //put in first number
        //for opcode in permutation
        for (size_t i = 0; i < perm.size(); i++)
        {
            if (perm[i] == 0)   //if opcode == 0 do + else do *
            {
                testsum += numbers[i + 1];
            }
            else
            {
                testsum *= numbers[i + 1];
            }
        }
        if (testsum == result)
        {
            return true;
        }
    }
    //nur hier falls keine zutreffen
    return false;
}

void generateCombinations(int n, std::vector<int>& temp, int i, std::vector<std::vector<int>>& combinations ) {
    if (temp.size() < n) temp.resize(n);
    
    if (i == n) {
        combinations.push_back(temp);
        return;
    }

    temp[i] = 0;
    generateCombinations(n, temp, i + 1, combinations);

    temp[i] = 1;
    generateCombinations(n, temp, i + 1, combinations);
}
