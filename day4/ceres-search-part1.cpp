#include <bits/stdc++.h>


void arrTreatment(std::vector<std::vector<char>>& arr);
int check(std::vector<std::vector<char>>& arr, int posX, int posY);

int main() {
    int occurence = 0;

    std::vector<std::vector<char>> grid;
    std::string line;

    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "erro" << std::endl;
        return 1;
    }

    while (std::getline(input, line)) {
        std::vector<char> row(line.begin(), line.end());
        grid.push_back(row);
    }

    arrTreatment(grid);


    for (int i = 3; i < grid.size()-3; i++) {
        for (int j = 3; j < grid[i].size()-3; j++) {
            if (grid[i][j] == 'X') {
                occurence += check(grid, i, j);             
            }
        }
    }

    
    std::cout << occurence << std::endl;

    return 0;
}

void arrTreatment(std::vector<std::vector<char>>& arr) {

    std::vector<char> element;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < 3; j++) {
            arr[i].insert(arr[i].begin(), '.');
            arr[i].push_back('.');
        }
    }

    for (int i = 0; i < arr[0].size(); i++) {
        element.push_back('.');
    }

    for (int i = 0; i < 3; i++) {
        arr.insert(arr.begin()+i, {element});
        arr.push_back({element});
    }

}

int check(std::vector<std::vector<char>>& arr, int posX, int posY) {
    std::string string1 = "";
    std::string string2 = ""; 
    int occurence = 0;
    
    for (int i = 0; i < 4; i++) {
        string1 += arr[posX][posY+i];
        string2 += arr[posX][posY-i];
    }
    occurence += string1 == "XMAS" ? 1 : 0; 
    occurence += string2 == "XMAS" ? 1 : 0; 
    string1 = "";
    string2 = "";

    for (int i = 0; i < 4; i++) {
        string1 += arr[posX-i][posY];
        string2 += arr[posX+i][posY];
    }
    occurence += string1 == "XMAS" ? 1 : 0; 
    occurence += string2 == "XMAS" ? 1 : 0; 
    string1 = "";
    string2 = "";

    for (int i = 0; i < 4; i++) {
        string1 += arr[posX-i][posY+i];
        string2 += arr[posX+i][posY+i];
    }
    occurence += string1 == "XMAS" ? 1 : 0; 
    occurence += string2 == "XMAS" ? 1 : 0; 
    string1 = "";
    string2 = "";

    for (int i = 0; i < 4; i++) {
        string1 += arr[posX-i][posY-i];
        string2 += arr[posX+i][posY-i];
    }
    occurence += string1 == "XMAS" ? 1 : 0; 
    occurence += string2 == "XMAS" ? 1 : 0; 
    string1 = "";
    string2 = "";

    std::cout << occurence << std::endl;

    return occurence; 
}