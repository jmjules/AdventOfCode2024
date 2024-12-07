#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>



char getTile(const std::vector<std::vector<char>>& grid, int x, int y);
void turnRight(int& dirX, int& dirY);


int main() {

    // read input
    std::ifstream file("input.txt");
    if (!file)
    {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }
    
    //Read in file into 2d array !!!if doing row by row it is arr[y][x] or maybe I deliberately set them like  first do x then put into y
    //for line in text -> for char in line -> arr[char_idx][rownum] = char
    std::vector<std::string> input;
    std::string line;

    while (std::getline(file, line))
    {
        input.push_back(line);
    }

    int rows = input.size();
    int cols = input[0].size();
    std::vector<std::vector<char>> grid(cols, std::vector<char>(rows));
    //transpose for [x][y] coordinate access
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; c++)
        {
            grid[c][r] = input[r][c];
        }    
    }
    


    //set up second arr to store previous positions
    std::vector<std::vector<char>> walkedPath(cols, std::vector<char>(rows, '.'));


    //find start pos 
        //maybe reset it with .
    int startX = -1, startY = -1;
    for (int x = 0; x < cols; ++x) {
        for (int y = 0; y < rows; ++y) {
            if (grid[x][y] == '^') {
                startX = x;
                startY = y;
                grid[x][y] = '.'; //reset marker
                walkedPath[x][y] = 'x';
                break; // Exit inner loop once found
            }
        }
        if (startX != -1) break; // Exit outer loop once found
    }
    

    //record start directions as up [0, -1] x,y
    int posX = startX, posY = startY;
    int dirX = 0, dirY = -1; //up
    //set walking flag
    bool walking = true;
    //while walking
    while (true)
    {
        //look up next tile
        char tile = getTile(grid, posX + dirX, posY + dirY);
        if (tile == ' ') break; //is out of bounds? -> set walk false (break)?maybe not needed tbh

        if (tile == '#')
        {
            turnRight(dirX, dirY);
        }
        else    //tile is .
        {
            posX += dirX;
            posY += dirY;
            walkedPath[posX][posY] = 'x'; //mark tile as walked
        }  
    }


    //save the walk path to file?//use as possible new obstacle position
    //get a list of xy positions for all x's in the walked path
    
    //for each in that list
        //make temp copy of grid
        //add to grid
        //let guard run through
        //have new walked path? -> maybe with walked direction |/-
        //if walked path tile gets walked on second time with same direction -> we got a loop ->
            //record this
            //next



    // //result p1
    // std::cout << "Walked tiles: " << walkedTilesCount << std::endl;

    return 0;
}


char getTile(const std::vector<std::vector<char>>& grid, int x, int y) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
        return ' '; // Default value for out-of-bounds
    }
    return grid[x][y];
}

void turnRight(int& dirX, int& dirY) {
    if (dirX == 0) //up or down
    {
        if (dirY < 0) //up -> right
        {
            dirX = 1;
            dirY = 0;
        }
        else //down -> left
        {
            dirX = -1;
            dirY = 0;
        }
        
    }
    else //left or right
    {
        if (dirX < 0) //left -> up
        {
            dirX = 0;
            dirY = -1;
        }
        else //right - > down
        {
            dirX = 0;
            dirY = 1;
        }
    }
    
}