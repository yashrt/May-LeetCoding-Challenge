class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        // Check if currunt color is not same as newColor
        if(newColor!=image[sr][sc])
            fillColor(image, sr, sc, image[sr][sc], newColor);
        
        return image;
    }
    
    void fillColor(vector<vector<int>>& image, int sr, int sc, int keyColor, int newColor)
    {
        // Condition to check value of sr and sc are in appropiate range 
        // and current pixel is same as key color
        if(sr>=0 && sr<image.size() && sc>=0 && sc<image[0].size() && image[sr][sc]==keyColor)
        {
            image[sr][sc] = newColor;
            
            // To color upside pixels
            fillColor(image, sr-1, sc, keyColor, newColor);
            // To color left pixels
            fillColor(image, sr, sc-1, keyColor, newColor);
            // To color right pixels
            fillColor(image, sr, sc+1, keyColor, newColor);
            // To color downside pixels
            fillColor(image, sr+1, sc, keyColor, newColor);
        }
    }
};
