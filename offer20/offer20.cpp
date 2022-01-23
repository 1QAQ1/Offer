#include "iostream"
#include "string"

using namespace std;

class Solution {
private:
    //检查是不是有整数
    bool scaninteger(string s, int& i)
    {
        int j = i;
        while (s[i] >= '0' && s[i] <= '9')
            i++;
        return i > j;
    }
    //检查是不是只有一个标点
    bool scansymbol(string s, int& i)
    {
        if (s[i] == '+'||s[i] == '-')
            i++;
        return s[i] != '+' && s[i] != '-';
    }
public:
    //+ 数 。 数 e + 数 。 数
    bool isNumber(string s) {
        int index = 0;
        while (s[index] == ' ')
            s.erase(index, 1);
        if (s.size() == 0)
            return false;
        if (!scansymbol(s, index))
            return false;
        //记录e之前的两个整数是否存在
        bool sad = scaninteger(s, index);
        bool sadafter = false;

        if (s[index] == '.')
        {
            index++;
            sadafter = scaninteger(s, index);
            if (!sad && !sadafter)
                return false;
        }

        if (s[index] == 'e'||s[index] == 'E')
        {
            if (!(sad||sadafter))
                return false;
            //检查e后面是不是没有整数
            index++;
            scansymbol(s, index);
            int int_after_e = index;
            scaninteger(s, index);

            if (index == int_after_e)
                return false;
        }

        while (s[index] == ' ')
            index++;
        if (index == s.size())
            return true;
        return false;
    }
};

int main()
{
    Solution s;
    cout<<boolalpha<<s.isNumber("e9");
    return 0;
}