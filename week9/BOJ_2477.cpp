#include <iostream>
#include <vector>

using namespace std;

int calculate(int k, vector<pair<int, int>>& sides) {
    int max_width = 0, max_height = 0;
    int total_width = 0, total_height = 0;
    
    for (int i = 0; i < 6; ++i) {
        if ((sides[i].first == 1 || sides[i].first == 2) && sides[i].second > max_width) {
            max_width = sides[i].second;
            total_width = i;
        }
        if ((sides[i].first == 3 || sides[i].first == 4) && sides[i].second > max_height) {
            max_height = sides[i].second;
            total_height = i;
        }
    }

    int smallWidth = abs(sides[(total_width + 5) % 6].second - sides[(total_width + 1) % 6].second);
    int smallHeight = abs(sides[(total_height + 5) % 6].second - sides[(total_height + 1) % 6].second);

    int bigArea = max_width * max_height;
    int smallArea = smallWidth * smallHeight;
    int total = (bigArea - smallArea) * k;

    return total;
}

int main() {
    int k;
    cin>>k;

    vector<pair<int, int>> sides(6);

    for (int i = 0; i < 6; ++i) {
        cin>>sides[i].first>>sides[i].second;
    }

    cout<<calculate(k, sides);

    return 0;
}
