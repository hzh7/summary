#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> arr{};
    arr[0].push_back(1);
    arr[1].push_back(1);
    arr[1].push_back(1);
    //vector<int>::iterator t;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); ++j) {
            cout << arr[i][j] << " ";
        }
    }
}
int main() {
    //std::cout << "Hello, World!" << std::endl;
    int n = 5;
    generate(n);
    return 0;
}