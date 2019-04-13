class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector <int> temp;
        int i;
        for(i=0;i<array.size();i++)
            if(array[i]%2==1) temp.push_back(array[i]);
        for(i=0;i<array.size();i++)
            if(array[i]%2==0) temp.push_back(array[i]);
        for(i=0;i<array.size();i++)
            array[i]=temp[i];
    }
};
