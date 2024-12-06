#include <bits/stdc++.h>
#include <regex>

int main() {

    int ans = 0;
    std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\)|don't\(\)|do\(\))");;
    std::string line;
    std::smatch matches;

    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "erro" << std::endl;
        return 1;
    }

    
    bool ignore = false;
    while(std::getline(input, line)) {

        auto search_start = line.cbegin();

        while (std::regex_search(search_start, line.cend(), matches, pattern)) {
            if (!ignore && matches.str().substr(0, 3) == "mul") {
                std::cout << matches[0] << std::endl;
                int num1 = std::stoi(matches[1]);
                int num2 = std::stoi(matches[2]);
                ans += num1 * num2;
                search_start = matches[0].second;
            } else if (matches.str() == "do()") {
                ignore = false;
                search_start = matches[0].second;
            } else if (matches.str() == "don't()") {
                ignore = true;
                search_start = matches[0].second;
            } 
            search_start = matches[0].second;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

