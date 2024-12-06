#include <bits/stdc++.h>

void ruleToVector(std::vector<int>& arr, std::string inputFile);
std::vector<int> lineToVector(std::string line);
int main() {

    std::vector<int> rules;
    std::vector<int> pages;
    int ans = 0;
    int check = 0;
    
    ruleToVector(rules, "rules.txt");

    std::ifstream input("page-numbers.txt");
    std::string line;
    while (std::getline(input, line)) {
        pages = lineToVector(line);
        check = 0; 
        
        for (int i = 0; i < pages.size()-1; i++) {
            for (int j = 0; j < rules.size(); j+=2) {
                if (pages[i] == rules[j] && pages[i+1] == rules[j+1]) {
                    check++;
                    break;
                }
            }
        }

        if (check+1 == pages.size()) {
            ans += pages[pages.size()/2];
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

void ruleToVector(std::vector<int>& arr, std::string inputFile) {
    std::string line, number1, number2;

    std::ifstream input(inputFile);
    if (!input.is_open()) {
        std::cerr << "erro" << std::endl;
        return;
    }

    while (std::getline(input, line) ) {
        std::istringstream stream(line);

        std::getline(stream, number1, '|');
        std::getline(stream, number2, '|');
        int n1 = stoi(number1);
        int n2 = stoi(number2);

        arr.push_back(n1);
        arr.push_back(n2);
    }
}

std::vector<int> lineToVector(std::string line) {
    std::stringstream ss(line);
    std::string tmp;
    std::vector<int> pages;

    while (std::getline(ss, tmp, ',')) {
        pages.push_back(std::stoi(tmp));
    }

    return pages;
}
