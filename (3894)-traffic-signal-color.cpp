class Solution {
public:
    string trafficSignal(int timer) {
        string res="Invalid";
        if(timer==0) res="Green";
        else if(timer==30) res="Orange";
        else if(timer>30 && timer<=90) res="Red";

        return res;
    }
};
