#include <bits/stdc++.h>

int main() {
    int safeReports = 0;
    int check = 0;

    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "erro" << std::endl;
        return 1;
    }

    std::string line;
    while(std::getline(input, line)) {
        std::istringstream iss(line);
        std::vector<int> numbers;
   
        int number;
    
        while(iss >> number) {
            numbers.push_back(number);
        }

        std::vector<int> sorted = numbers;
        std::vector<int> reverseSort = numbers;

        std::sort(sorted.begin(), sorted.end());
        std::sort(reverseSort.begin(), reverseSort.end(), std::greater<int>());

        if (numbers != sorted && numbers != reverseSort) {
            continue;
        }

        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i-1] == numbers[i]) {
                break;
            }

            if (std::abs(numbers[i-1] - numbers[i]) < 4) {
                check++;
            }
        }

        if (check == numbers.size()-1) {
            safeReports++;
        }
        check = 0;
    }

    std::cout << safeReports << std::endl;

    return 0;
}