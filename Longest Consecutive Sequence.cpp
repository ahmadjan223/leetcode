class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> temp;
        int largest = 0;
        //initializing the set;
        for (int i : nums) {
            temp.insert(i);
        }
        //loop and if checks if the element is start of a sequence,
        for (int i : nums) {
            if (temp.count(i - 1) == 0) {
                cout<<i;
                int counter = 0;
                //counter the size of that particular sequence 
                while (temp.count(counter + i) != 0) {
                    counter++;
                    largest = max(counter, largest);
                }
            }
        }
        return largest;
    }
};
