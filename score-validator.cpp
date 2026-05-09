class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int>res;
        int score=0;
        int counter=0;
        for(int i=0;i<events.size();i++){
            if(counter>=10) break;
            if(events[i]=="W") counter++;
            else if(events[i]=="WD" || events[i]=="NB") score++;
            else{
                int curr=stoi(events[i]);
                score+=curr;
            }
        }
        res.push_back(score);
        res.push_back(counter);
        return res;
    }
};
