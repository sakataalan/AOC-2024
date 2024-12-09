#include <bits/stdc++.h>

void inputTo2DArr(std::vector<std::vector<char>>& arr, std::string inputFile);
void findGuard(const std::vector<std::vector<char>>& arr, int& posX, int& posY);
void move(std::vector<std::vector<char>>& arr, std::string direction, int& guardPositionX, int& guardPositionY);

int main() {

    std::vector<std::vector<char>> map;
    int guardPositionX = 0;
    int guardPositionY = 0;
    int index = 0;
    int steps = 0;
    std::vector<std::string> direction = {"up", "right", "down", "left"};

    inputTo2DArr(map, "input.txt");
 
    findGuard(map, guardPositionX, guardPositionY);

    while (guardPositionY != map.size() && guardPositionY != 0 && guardPositionX != map.size() && guardPositionX != 0) {
        move(map, direction[index], guardPositionX, guardPositionY); 
        std::cout << "guardPositionY: " << guardPositionY << " - " << "guardPositionX: " << guardPositionX << std::endl; 
        index = (index + 1) % direction.size();     
    }    

    for (auto& row: map) {
        for (char& c: row) {
            if (c == 'X') {
                steps++;
            }
            std::cout << c;
        }
        std::cout << std::endl;
    }

    std::cout << steps << std::endl;

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
