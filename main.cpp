class Solution {
public:
    int findMaxK(vector<int>& nums) {
        std::unordered_set<int> seen; //records the numbers seen during the iteration to be looked up later quickly
        int maxK = -1; //Keep track of the largest positive integer that has a negative version of itself
        
        for (int num : nums) { //for each loop so for each num in nums
            if (seen.find(-num) != seen.end()) { //checks if the negative counterpart is in the set, if not, it returns seen.end()
                maxK = std::max(maxK, std::abs(num)); //if found, it will return the absolute value of that current num since we know
            }                                           //there is a positive integer and the negative counterpart
            seen.insert(num); //records the current num into the set for futuree usage (I learned that insert stops duplicate numbers)
        }
        
        return maxK; //returning what is needed
    }
};
