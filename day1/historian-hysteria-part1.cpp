#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main() {

  int x, y, result;
  result = 0;
  std::vector<int> arr1;
  std::vector<int> arr2;

  for (int i = 0; i < 1000; i++) {
    std::cin >> x;
    std::cin >> y;
   
    arr1.push_back(x);
    arr2.push_back(y);
  }

  std::sort(arr1.begin(), arr1.end());
  std::sort(arr2.begin(), arr2.end());

  for (int i = 0; i < 1000; i++) {

    result += std::abs(arr1[i] - arr2[i]);
  }

  std::cout << result << std::endl;

  return 0;
}
