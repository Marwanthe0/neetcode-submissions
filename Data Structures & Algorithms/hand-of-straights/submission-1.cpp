class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int> ms;
        for(auto vl:hand) ms.insert(vl);
        int mn = *ms.begin(),idx = 0;
        while(!ms.empty()){
            if(!ms.count(mn)) return false;
            else {
                ms.erase(ms.find(mn));
                mn++,idx++;
            }
            if(idx == groupSize){
                idx = 0;
                if(!ms.empty()) mn = *ms.begin();
            }
        }
        return !idx;
    }
};
