#include<iostream>
#include<string>
#include<map>
using namespace std;


class Solution {
public:
    string reformatDate(string date) 
    {
        int len = date.size();
        map<string,string> m;
        m["Jan"] = "01";
        m["Feb"] = "02";
        m["Mar"] = "03";
        m["Apr"] = "04";
        m["May"] = "05";
        m["Jun"] = "06";
        m["Jul"] = "07";
        m["Aug"] = "08";
        m["Sep"] = "09";
        m["Oct"] = "10";
        m["Nov"] = "11";
        m["Dec"] = "12";
        string DD;
        string MM;
        string YYYY;
        if(date[1] >='0' && date[1] <= '9')
        {
            DD = date.substr(0,2);
            MM = m[date.substr(5,3)];
            YYYY = date.substr(9,4);
        }
        else
        {
            DD = "0" + date.substr(0,1);
            MM = m[date.substr(4,3)];
            YYYY = date.substr(8,4);
        }
        return YYYY + "-" + MM + "-" + DD;
    }
};


int main()
{
    Solution s;
    cout<<s.reformatDate("20th Oct 2052")<<endl;
    system("pause");
    return 0;
}