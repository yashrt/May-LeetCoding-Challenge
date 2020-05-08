// Point (x1,y1), (x2,y2) and (x3,y3) lies on same line
// If slope of (x1,y1) and (x2,y2) is equal to slope of (x1,y1) and (x3,y3)
// or If slope of (x1,y1) and (x2,y2) is equal to slope of (x2,y2) and (x3,y3)
// or If slope of (x2,y2) and (x3,y3) is equal to slope of (x1,y1) and (x2,y2)
// and so on..

// Slope b/w (x1,y1), (x2,y2) = (y2-y1)/(x2-x1)
// Slope b/w (x1,y1), (x3,y3) = (y3-y1)/(x3-x1)
// SO (y2-y1)/(x2-x1) = (y3-y1)/(x3-x1)
// therefore, (y2-y1)*(x3-x1) = (y3-y1)*(x2-x1)

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int size = coordinates.size();
        if(size==2)
            return true;

        int num = coordinates[1][1]-coordinates[0][1];
        int deno = coordinates[1][0]-coordinates[0][0];
        int x = coordinates[0][0];
        int y = coordinates[0][1];
        
        for(int i=2; i<size; i++)
        {
            int tempNum = coordinates[i][1]-y;
            int tempDeno = coordinates[i][0]-x;
            if(tempNum*deno != tempDeno*num)
                return false;
        }
        
        return true;  
    }
};
