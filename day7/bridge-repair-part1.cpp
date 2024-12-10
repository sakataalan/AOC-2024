#include <bits/stdc++.h>

void inputToMap(std::unordered_map<std::uint64_t, std::vector<int>>& arr, std::string input);
void combinationsGenerator(int size, std::vector<char> current, std::vector<std::vector<char>>& result);
std::uint64_t tryToFind(std::vector<int> arr, std::vector<std::vector<char>>& combinations, std::uint64_t target);
int main() {
    
    std::unordered_map<std::uint64_t, std::vector<int>> map;
    std::vector<std::vector<char>> combinations;
    std::uint64_t total = 0;

    inputToMap(map, "input.txt");

    for (auto& pair: map) {
        std::uint64_t key = pair.first;
        int result = 0;
        combinationsGenerator(pair.second.size()-1, {}, combinations);

        total += tryToFind(pair.second, combinations, pair.first);

    }

    std::cout << total << std::endl;

    return 0;
}

void inputToMap(std::unordered_map<std::uint64_t, std::vector<int>>& arr, std::string inputFile) {

    std::ifstream input(inputFile);
    std::string line;

    while(std::getline(input, line)) {
        int pos = line.find(":");
        // std::int64_t key;
        // std::istringstream iss(line.substr(0, pos));
        // iss >> key;
        std::uint64_t key = std::stoll(line.substr(0, pos));  
        std::string numbers = line.substr(pos + 2);  
        
        std::vector<int> valuesArr;
        std::istringstream iss(numbers);
        int value;

        while (iss >> value) {
            valuesArr.push_back(value);
        }

        arr[key] = valuesArr;
    }
}

void combinationsGenerator(int size, std::vector<char> current, std::vector<std::vector<char>>& result) {

    if (current.size() == size) {
        result.push_back(current);
        return;
    }
    
    current.push_back('+');
    combinationsGenerator(size, current, result);
    current.pop_back();
    
    current.push_back('*');
    combinationsGenerator(size, current, result);
    current.pop_back(); 

}

std::uint64_t tryToFind(std::vector<int> arr, std::vector<std::vector<char>>& combinations, std::uint64_t target) {

    for (int i = 0; i < combinations.size(); i++) {
        std::uint64_t result = arr[0];
        for (int j = 0; j < combinations[i].size(); j++) {
            if (combinations[i][j] == '+') {
                result += arr[j+1];
            } else if (combinations[i][j] == '*') {
                result *= arr[j+1];
            }
        }

        if (result == target) {
            return result;
        }
    }

    return 0;
}

