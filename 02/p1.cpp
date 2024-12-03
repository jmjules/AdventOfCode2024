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
    
    // turn into lists of lists of numbers
    std::vector<std::vector<int>> lines;
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream linestream(line);
        std::vector<int> row;
        int number;

        while (linestream >> number)
        {
            row.push_back(number);
        }
        lines.push_back(row);
    }
    file.close();

    int save_reports = 0;
    //for line in lines
    for (const auto& row : lines)
    {
        //test asc or desc
        std::string order = (row[0] > row[1]) ? "desc" : "asc";

        if (order == "desc")
        {
            bool save = true;
            for (size_t i = 0; i < row.size() - 1; i++)
            {
                if (row[i] < row[i+1])
                {
                    save = false;
                    break;
                }
                
                int diff_abs = std::abs(row[i] - row[i+1]);
                if (diff_abs < 1 || diff_abs > 3)
                {
                    save = false;
                    break;
                }
            }

            if (save)
            {
                save_reports++;
            }
            
            
        }
        else
        {
            bool save = true;
            for (size_t i = 0; i < row.size() - 1; i++)
            {
                if (row[i] > row[i+1])
                {
                    save = false;
                    break;
                }
                
                int diff_abs = std::abs(row[i] - row[i+1]);
                if (diff_abs < 1 || diff_abs > 3)
                {
                    save = false;
                    break;
                }
            }

            if (save)
            {
                save_reports++;
            }
        }
        
        
        
    }

    std::cout << "Number of save reports: " << save_reports << std::endl;
    

    //test num diff 1-3
    //if no break
    //if through save_reports++


    

    return 0;
}