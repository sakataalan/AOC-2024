#include <bits/stdc++.h>

void inputToVector(std::vector<std::vector<char>>& arr, std::string inputFile);
void findAntenaChar(std::vector<std::vector<char>>& arr, std::set<char>& antena);
void findAntinode(std::vector<std::vector<char>>& map, char character, std::set<std::string>& values);

int main() {

    std::vector<std::vector<char>> map;
    std::set<char> antena;
    std::set<std::string> values;

    inputToVector(map, "input.txt");
    findAntenaChar(map, antena);

    for (auto a: antena) {
        findAntinode(map, a, values);
        // std::cout << a << std::endl;
    }

    // for (std::string v: values) {
    //     std::cout << v << std::endl;
    // } 

    for (auto& row: map) {
        for (char& c: row) {
            std::cout << c;
        }
        std::cout << std::endl;
    }

    std::cout << values.size() << std::endl;

    return 0;
}

void inputToVector(std::vector<std::vector<char>>& arr, std::string inputFile) {
    std::ifstream input(inputFile);
    std::string line;

    while(std::getline(input, line)) {
        std::vector<char> row;
        for (char c: line) {
            if (!isspace(c)) {
                row.push_back(c);
            }
        }
        arr.push_back(row);
    }
}

void findAntenaChar(std::vector<std::vector<char>>& arr, std::set<char>& antena) {
    
    for (auto& row: arr) {
        for (char& value: row) {
            if (value != '.' && !isspace(value)) {
                antena.insert(value);
            }
        }
    }
}

void findAntinode(std::vector<std::vector<char>>& arr, char character, std::set<std::string>& values) {

    std::vector<std::vector<int>> position;
    std::string str;
    int antinode = 0;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == character) {
                position.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < position.size()-1; i++) {
        for (int j = i+1; j < position.size(); j++) {

            int posY1 = position[i][0] - std::abs(position[i][0] - position[j][0]);
            int posX1 = position[i][1] - std::abs(position[i][1] - position[j][1]);

            int posY2 = position[j][0] + std::abs(position[i][0] - position[j][0]);
            int posX2 = position[j][1] + std::abs(position[i][1] - position[j][1]);

          
            if (position[i][1] > position[j][1]) {
                posX1 = position[i][1] + position[i][1] - position[j][1];
                posX2 = position[j][1] - std::abs(position[i][1] - position[j][1]);
            } 
            
      
            if (posY1 >= 0 && posX1 >= 0 && posX1 <= arr[0].size()) {
                if (arr[posY1][posX1] == '.') {
                    arr[posY1][posX1] = '#';
                }
                str = std::to_string(posY1) + std::to_string(posX1);
                values.insert(str);
            }
            if (posY2 < arr.size() && posX2 >= 0 && posX2 <= arr[0].size()) {
                if (arr[posY2][posX2] == '.') {
                    arr[posY2][posX2] = '#';
                }
                str = std::to_string(posY2) + std::to_string(posX2);
                values.insert(str);
            }
        }
    }
}