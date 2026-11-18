class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int biggest_nanner_pile = -1;

        for (int i = 0; i < piles.size(); ++i) {
            if (piles[i] > biggest_nanner_pile)
                biggest_nanner_pile = piles[i];
        }

        int low = 1;
        int high = biggest_nanner_pile;

        while (low < high) {
            int mid = low + (high - low) / 2;

            int hours = 0;
            for (int i = 0; i < piles.size(); ++i) {
                hours += (piles[i] + mid - 1) / mid;
            }

            if (hours <= h)
                high = mid;
            else
                low = mid + 1;
        }

        return low;



    }
};
