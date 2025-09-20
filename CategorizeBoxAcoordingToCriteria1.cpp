class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        int heavy=0;
        int bulky=0;
        string result;
        long long volume=1LL*length*width*height;
        if(length>=10000 || width>=10000 || height>=10000 || volume>=1000000000){
            result="Bulky";
            bulky=1;
        }
        if(mass>=100){
            result="Heavy";
            heavy=1;
        }
        if(bulky==1 && heavy==1)
            result="Both";
        if(bulky!=1 && heavy!=1)
            result="Neither";
        if(bulky==1 && heavy!=1)
            result="Bulky";
        if(bulky!=1 && heavy==1)
            result="Heavy";
        
        return result;
    }
};
