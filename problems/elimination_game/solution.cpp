class Solution {
public:
    int lastRemaining(int n) {
      int start = 1;
      int diff = 1;
      int size = n;
      bool flip = true;
      while(size>1){
          if(flip || (!flip && size%2!=0)){
              start += diff;
          }
          diff = diff*2;
          size = size/2;
          flip = !flip;
      } 
      return start;
    }
};