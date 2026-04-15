class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>freq(26,0);

        for(int i=0; i<s.size(); i++){
            freq[s[i]-'a']  = i;
        }
        int current=0, total=0;
        vector<int> result;

        for(int i=0; i<s.size(); i++){
            current = max(current,  freq[s[i]-'a']);

            if(i==current){
                int size = i-total+1;
                result.push_back(size);
                total = i+1;
            }
        }
        return result;
    }
};
