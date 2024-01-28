#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> coordinates;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        coordinates.push_back({x, y});
    }

    int max_area = -1;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                //calculate area of the 3 fence posts
                if ((coordinates[i].first == coordinates[j].first || coordinates[j].first == coordinates[k].first || coordinates[i].first == coordinates[k].first) && (coordinates[i].second == coordinates[j].second || coordinates[j].second == coordinates[k].second || coordinates[i].second == coordinates[k].second)){
                    int base = max(max(coordinates[i].first, coordinates[j].first), coordinates[k].first) - min(min(coordinates[i].first, coordinates[j].first), coordinates[k].first);
                    int height = max(max(coordinates[i].second, coordinates[j].second), coordinates[k].second) - min(min(coordinates[i].second, coordinates[j].second), coordinates[k].second);
                    /*cout << "(" << coordinates[i].first << ", " << coordinates[i].second << ") (" << coordinates[j].first << ", " << coordinates[j].second << ") (" << coordinates[k].first << ", " << coordinates[k].second << ")" << endl;
                    cout << base << " " << height << endl;
                    cout << base * height << endl;*/
                    max_area = max(base * height, max_area);
                }
            }
        }
    }

    cout << max_area << endl;
}
