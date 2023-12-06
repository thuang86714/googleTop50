class Solution {
public:
    int totalMoney(int n) {
        int week = n/ 7, day = n%7, money = 0;
        for(int i = 0; i < week; i++){
            money += (1 + 7 + 2*i)*7/2;
        }
        for(int i = 0; i < day; i++){
            money += (week + i + 1);
        }
        return money;
    }
};