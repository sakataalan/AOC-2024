#include <bits/stdc++.h>

void inputTo2DArr(std::vector<std::vector<char>>& arr, std::string inputFile);
void findGuard(const std::vector<std::vector<char>>& arr, int& posX, int& posY);
void move(std::vector<std::vector<char>>& arr, std::string direction, int& guardPositionX, int& guardPositionY);
bool findLoop(std::vector<std::vector<char>> arr, int guardPositionX, int guardPositionY);

int main() {

    std::vector<std::vector<char>> map;
    int guardPositionX = 0;
    int guardPositionY = 0;
    int index = 0;
    int loops = 0;

    inputTo2DArr(map, "input-test.txt");
 
    findGuard(map, guardPositionX, guardPositionY);


    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (map[i][j] == '.') {
                map[i][j] = '#';
                loops += findLoop(map, guardPositionX, guardPositionY) ? 1 : 0;
                map[i][j] = '.';
                std::cout << loops << std::endl;
            }
        }
    }

    return 0;
}

void inputTo2DArr(std::vector<std::vector<char>>& arr, std::string inputFile) {

    std::ifstream input(inputFile);
    std::string line;
    std::vector<char> row;

    while (std::getline(input, line)) {
        row.clear();
        for (char c: line) {
            row.push_back(c);
        }
        arr.push_back(row);
    }
}

void move(std::vector<std::vector<char>>& arr, std::string direction, int& guardPositionX, int& guardPositionY) {

    if (direction == "up") {

        while (guardPositionY >= 0) {
            if (arr[guardPositionY][guardPositionX] == '#') {
                guardPositionY++;
                arr[guardPositionY][guardPositionX] = '^';
                break;
            }
            arr[guardPositionY][guardPositionX] = 'X';
            if (guardPositionY == 0) {
                break;
            }
            guardPositionY--;
        }
    }

    if (direction == "right") {

        while (guardPositionX < arr[0].size()) {
            if (arr[guardPositionY][guardPositionX] == '#') {
                guardPositionX--;
                arr[guardPositionY][guardPositionX] = '^';
                break;
            }
            arr[guardPositionY][guardPositionX] = 'X';
            guardPositionX++;
        }
    }

    if (direction == "down") {
        int i = 0;
        while (guardPositionY < arr.size()) {
            if (arr[guardPositionY][guardPositionX] == '#') {
                guardPositionY--;
                arr[guardPositionY][guardPositionX] = '^';
                break;
            }
            arr[guardPositionY][guardPositionX] = 'X';
            guardPositionY++;
        }
    }

    if (direction == "left") {
        while (guardPositionX >= 0) {
            if (arr[guardPositionY][guardPositionX] == '#') {
                guardPositionX++;
                arr[guardPositionY][guardPositionX] = '^';
                break;
            }
            arr[guardPositionY][guardPositionX] = 'X';
            if (guardPositionX == 0) {
                break;
            } 
            guardPositionX--;
        }
    }
}

void findGuard(const std::vector<std::vector<char>>& arr, int& posX, int& posY) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == '^') {
                posX = j;
                posY = i;
            }
        }
    }
}

bool findLoop(std::vector<std::vector<char>> arr, int guardPositionX, int guardPositionY) {
    
    int index = 0;

    std::vector<std::string> direction = {"up", "right", "down", "left"};
    std::unordered_map<int, int> position;

    while (guardPositionY != arr.size() && guardPositionY != 0 && guardPositionX != arr.size() && guardPositionX != 0) {
        move(arr, direction[index], guardPositionX, guardPositionY); 
        index = (index + 1) % direction.size(); 
        // std::cout << "guardPositionY: " << guardPositionY << " - " << "guardPositionX: " << guardPositionX << std::endl; 
        
        if (position.find(guardPositionY) != position.end()) {
            if (position.at(guardPositionY) == guardPositionX) {
                return true;
            }
        }    
        position[guardPositionY] = guardPositionX;
    }    

    for (auto& row: arr) {
        for (char& c: row) {
            std::cout << c;
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------" << std::endl;

    return false;
}
