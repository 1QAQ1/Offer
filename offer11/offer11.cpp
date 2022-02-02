#include "iostream"

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int i = 0;
        int j = numbers.size() - 1;

        if (numbers[i] < numbers[j])
            return numbers[i];

        if (numbers[i] == numbers[(i + j)/2])
        {
            if (j == 0)
                return numbers[i];
            int k = 1;
            while(k < j + 1)
            {
                if (numbers[i] > numbers[k]||k == numbers.size()-1)
                    break;
                k++;
            }
            return numbers[k];
        }

        while (i != j-1)
        {
            if (numbers[i] > numbers[(i+j)/2])
                j = (i + j)/2;
            else
                i = (i + j)/2;
        }
        return numbers[j];
    }
};

int main()
{

}