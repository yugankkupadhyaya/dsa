class Solution {
public:
    int maxProduct(int n) {
        string numb=to_string(n);
        sort(numb.begin(), numb.end());
        int len=numb.size();
      int digit1 = numb[len - 1] - '0'; 
        int digit2 = numb[len - 2] - '0';
        return digit1*digit2;
    }
};