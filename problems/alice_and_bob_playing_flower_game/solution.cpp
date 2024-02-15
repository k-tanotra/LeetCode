class Solution {
public:
    long long flowerGame(long long n, long long m) {
        return (n/2*(m%2!=0 ? (m/2 + 1) : m/2)) + (m/2*(n%2!=0 ? (n/2 + 1) : n/2));
    }
};