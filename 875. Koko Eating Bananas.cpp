#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int lowest = 1;
        int heighest = piles[piles.size() - 1];
        
        while (heighest > lowest) {
            int mid = lowest + (heighest - lowest) / 2;
            if (possible(mid, piles) <= h) {
                heighest = mid;
            } else {
                lowest = mid + 1;
            }
        }
        
        return lowest;
    }

    int possible(int mid, const vector<int>& piles) {
        int hrs = 0;
        for (int pile : piles) {
            hrs += (pile + mid - 1) / mid; // Use integer arithmetic for ceiling
        }
        return hrs;
    }
};
