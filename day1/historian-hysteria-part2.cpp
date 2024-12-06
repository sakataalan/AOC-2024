#include <bits/stdc++.h>

int main() {

  std::unordered_map<int, int> map;
  std::vector<int> arr;
  
  int x, y, result;
  result = 0;

  for (int i = 0; i < 1000; i++) {
    std::cin >> x;
    std::cin >> y;

    arr.push_back(x);
    map[y]++;
  }

  for (int i = 0; i < 1000; i++) {

    if (map.find(arr[i]) != map.end()) {
      result += arr[i] * map.at(arr[i]);
    } 
  }

  std::cout << result << std::endl;

  return 0;
}
