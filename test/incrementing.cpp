#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    // array<int, 5> oneArr = { 0, 1, 2, 3, 4 };
    // try
    // {
    //     for_each(oneArr.begin(), oneArr.end(), [](const int temp) {
    //         cout << temp << ' ';
    //     });
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    const size_t cols = 3;
    const size_t rows = 3;
    array<array<int, cols>, rows> twoArr = {{
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    }};

    try
    {
        for_each(twoArr.begin(), twoArr.end(), [](const auto& temp) {
            for_each(temp.begin(), temp.end(), [](const int val) {
                cout << val << ' ';
            });
            cout << '\n';
        });
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "\nHello\n";
    return 0;
}