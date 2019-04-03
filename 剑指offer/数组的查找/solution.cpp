class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
       int i=0,j=array[0].size()-1;
       while(i<array.size()&&j>=0)
       {
           if(array[i][j]<target) i++;
           else if(array[i][j]>target) j--;
           else return true;
       }
       return false;
    }
};
