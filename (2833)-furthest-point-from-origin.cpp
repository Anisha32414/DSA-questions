class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int res=0;
        int sp=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='R') res++;
            else if(moves[i]=='L') res--;
            else sp++;
        }
        res=abs(res);
        return res+sp;
    }
};
