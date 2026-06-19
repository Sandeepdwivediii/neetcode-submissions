class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool foundX = false, foundY = false, foundZ = false;

        for (auto& triplet : triplets) {
           
            if (triplet[0] > target[0] || 
                triplet[1] > target[1] || 
                triplet[2] > target[2]) 
                continue;

            if (triplet[0] == target[0]) foundX = true;
            if (triplet[1] == target[1]) foundY = true;
            if (triplet[2] == target[2]) foundZ = true;
        }

        return foundX && foundY && foundZ;
    }
};
