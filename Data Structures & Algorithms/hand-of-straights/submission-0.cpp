class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>freq;

        for(int hands:hand){
            freq[hands]++;
        }
        for(auto it: freq){
            int card = it.first;
            int count = it.second;

            if(count==0){
                continue;
            }
            for(int i=0; i<groupSize; i++){
                int newCard = card + i;

                if(freq[newCard] < count){
                    return false;
                }
                freq[newCard] -= count;
            }
        }
        return true;
    }
};
