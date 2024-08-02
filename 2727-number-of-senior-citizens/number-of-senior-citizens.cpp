class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(auto i:details)
        {
            int n=(i[11]-'0')*10+(i[12]-'0');
            if(n>60)
            count++;
        }
        return count;
    }
};