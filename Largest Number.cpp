#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isLarge(int a, int b)
    {
        long long sumAb, sumBa;
        int aTemp = a, bTemp = b;
        int aNums = 1, bNums = 1;
        while(aTemp/10 != 0)
        {
            aNums++;
            aTemp /= 10;
        }
        while(bTemp/10 != 0)
        {
            bNums++;
            bTemp /= 10;
        }
        sumAb = a;
        sumBa = b;
        for(int i = 0; i < bNums; i++)
        {
            sumAb *= 10;
        }
        sumAb += sumBa;
        for(int i = 0; i < aNums; i++)
        {
            sumBa *= 10;
        }
        sumBa += a;
        if(sumAb >= sumBa) return true;
        else return false;
    }
    void myQuickSort(vector<int> &num, int lEdge, int rEdge)
    {
        if(lEdge < rEdge)
        {
            int k = num[lEdge];
            int L = lEdge, R = rEdge;
            while(L < R)
            {
                while(isLarge(num[R],k) && L < R)
                {
                    R--;
                }
                if(R > L)
                {
                    num[L] = num[R];
                    L++;
                }
                while(isLarge(k,num[L]) && L < R)
                {
                    L++;
                }
                if(L < R)
                {
                    num[R] = num[L];
                    R--;
                }
            }
            num[L] = k;
            myQuickSort(num,lEdge,L-1);
            myQuickSort(num,L+1,rEdge);
        }
    }

    string largestNumber(vector<int> &num)
    {
        string result = "";
        string temp = "";
        stringstream ss;
        myQuickSort(num,0,num.size()-1);
        reverse(num.begin(),num.end());
        for(vector<int>::iterator it = num.begin(); it != num.end(); it++){
            ss.clear();
            temp.clear();
            ss << *it;
            ss >> temp;
            result += temp;
        }
        return result;
    }
};

int main()
{
    Solution myslt;
    vector<int> num = {3, 30, 34, 5, 9};
    cout << myslt.largestNumber(num);
    return 0;
}
