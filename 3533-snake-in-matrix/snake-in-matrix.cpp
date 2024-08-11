class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i=0,j=0;
        for(auto c:commands)
        {
            if(c=="RIGHT")
            j++;
            else if(c=="UP")
            i--;
            else if(c=="LEFT")
            j--;
            else
            i++;
        }
        return (i*n+j);
    }
};