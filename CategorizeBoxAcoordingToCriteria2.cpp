class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = false, heavy = false;
        long long volume = 1LL * length * width * height;

        if (length >= 10000 || width >= 10000 || height >= 10000 || volume >= 1000000000) {
            bulky = true;
        }
        if (mass >= 100) {
            heavy = true;
        }

        if (bulky && heavy) return "Both";
        if (bulky) return "Bulky";
        if (heavy) return "Heavy";
        return "Neither";
    }
};
