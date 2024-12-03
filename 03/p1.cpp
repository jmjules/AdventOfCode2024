#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

int main() {

    // read input
    std::ifstream file("input.txt");
    if (!file)
    {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }
    
    // Read the entire file into a string
    std::ostringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    //Define regex pattern
    std::regex pattern(R"(mul\((\d+),(\d+)\))");
    std::smatch match;

    int result = 0;
    //Search using regex
    while (std::regex_search(content, match, pattern))
    {
        int num1 = std::stoi(match[1]);
        int num2 = std::stoi(match[2]);

        result += num1 * num2;
        // Move to the rest of the string to find the next match
        content = match.suffix();
    }
    
    std::cout << "Total value: " << result << std::endl;

    return 0;
}