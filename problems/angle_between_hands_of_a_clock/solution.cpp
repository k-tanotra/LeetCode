class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hd = (hour%12)*30*1.00000 + minutes*0.5*1.00000;
        double md = 6*minutes*1.00000;
        return min(abs(hd-md),360-abs(hd-md));
    }
};