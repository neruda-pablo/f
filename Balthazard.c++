#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int count;
    double num;
    vector<double> nums;
    
    // Ask for the count of numbers
    cout << "Kaç farklı kayıp var mevcut?:\n";
    cin >> count;
    
    // Ask for the numbers and store them in a vector
    for (int i = 0; i < count; i++) {
        cout << "Kayıp oranını girin " << i + 1 << ":\n";
        cin >> num;
        nums.push_back(num);
    }
    
    // Perform the balthazar process on all the numbers
    while (nums.size() > 1) {
        double max1 = *max_element(nums.begin(), nums.end());
        nums.erase(find(nums.begin(), nums.end(), max1));
        double max2 = *max_element(nums.begin(), nums.end());
        nums.erase(find(nums.begin(), nums.end(), max2));
        
        double result = (100 - max1) * max2 / 100.0;
        max1 += result;
        
        nums.push_back(max1);
    }
    
    // Output the final result
    cout << "Sonuç: " << nums[0] << endl;

    return 0;
}
