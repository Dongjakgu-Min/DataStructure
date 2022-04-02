#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    
    // using like stack
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    cout << v.back() << endl;
    v.pop_back();
    cout << v.back() << endl;
    v.pop_back();
    cout << v.back() << endl;
    v.pop_back();
}