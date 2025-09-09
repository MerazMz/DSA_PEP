class Solution {
public:
    int largestInteger(int num) {
        vector<int> digits;
        int temp = num;
        while (temp > 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }
        reverse(digits.begin(), digits.end());

        priority_queue<int> pqe, pqo;
        for (int d : digits) {
            if (d % 2 == 0) pqe.push(d);
            else pqo.push(d);
        }

        long long result = 0;
        for (int d : digits) {
            result *= 10;
            if (d % 2 == 0) {
                result += pqe.top();
                pqe.pop();
            } else {
                result += pqo.top();
                pqo.pop();
            }
        }

        return (int)result;
    }
};
