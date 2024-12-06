#include <bits/stdc++.h>

int main() {

    int result = 0;
    std::regex pattern(R"(\bmul\b\((\d{1,3}),(\d{1,3})\))");
    std::smatch matches;

    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "erro" << std::endl;
        return 1;
    }

    std::string line;
    while(std::getline(input, line)) {
        auto search_start = line.cbegin();
        while (std::regex_search(search_start, line.cend(), matches, pattern)) {
            int num1 = std::stoi(matches[1]);
            int num2 = std::stoi(matches[2]);
            
            result += num1*num2;
            
            search_start = matches.suffix().first;
        }
    }    

    std::cout << result << std::endl;


    return 0;
}