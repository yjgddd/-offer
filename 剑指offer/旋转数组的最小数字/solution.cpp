class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
       int i;
       for(i=0;i<rotateArray.size()-1;i++)
       if(rotateArray[i]>rotateArray[i+1]) return rotateArray[i+1];
       return 0;
    }
};
