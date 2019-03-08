#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
   std::vector<int> values = {1, 5, 4, 2, 3};

   auto it = find_if(values.begin(), values.end(), [](int value) { return value > 5; });

   std::cout << *it << std::endl;

   return 0;
}
