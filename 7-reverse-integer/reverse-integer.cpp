class Solution {
public:
    int reverse(int x) {
        int y=0;
        while(x!=0)
        {
            if((x>0 && y>(INT_MAX-x%10)/10)||(x<0) && y<(INT_MIN-x%10)/10)
            return 0;
            else 
            y=y*10+x%10;
            x=x/10;
            
        }
        return y;
    }
};