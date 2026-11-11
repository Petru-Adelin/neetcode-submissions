#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int correct_part(int left_max1, int right_min1, int left_max2, int right_min2) const {
        if (left_max1 > right_min2)
            return 1; // Take fewer elements from smaller
        if (left_max2 > right_min1)
            return 2; // Take more elements from smaller
        return 0;
    }

    double median(vector<int>& smaller, vector<int>& larger) {
        int n = smaller.size(), m = larger.size();
        int left = 0, right = n; 

        while (left <= right) {
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

           
            int left1  = (i == 0) ? INT_MIN : smaller[i - 1];
            int right1 = (i == n) ? INT_MAX : smaller[i];     
            int left2  = (j == 0) ? INT_MIN : larger[j - 1];
            int right2 = (j == m) ? INT_MAX : larger[j];      

            int partition_correctness = correct_part(left1, right1, left2, right2);

            if (partition_correctness == 0) {
                if ((n + m) % 2 == 1)
                    return max(left1, left2);
                else
                    return (max(left1, left2) + min(right1, right2)) / 2.0; 
            }   

            if (partition_correctness == 1)
                right = i - 1;
            else 
                left = i + 1;
        }

        return 0.0;        
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return median(nums2, nums1); // Swap parameters so first vector is smaller
        return median(nums1, nums2);
    }
};