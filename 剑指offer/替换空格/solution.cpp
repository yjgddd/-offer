//vector解法
class Solution {
public:
	void replaceSpace(char *str,int length) {
         int i;
         vector <char> s;
         for(i=0;i<length;i++)
         {
             if(str[i]==' '){
                 s.push_back('%');
                 s.push_back('2');
                 s.push_back('0');
             }
             else s.push_back(str[i]);
         }
        for(i=0;i<s.size();i++)
        str[i]=s[i];
	}
};
//更优解
class Solution {
public:
	void replaceSpace(char *str,int length) {
         int i,len=length;
         for(i=0;i<length;i++)
         if(str[i]==' ') len+=2;//一个空格多两个字符
         len--;//最后一个元素的位置
         for(i=length-1;i>=0;i--)
         {
             if(i==len) break;
             if(str[i]!=' ') str[len--]=str[i];
             else{
                 str[len--]='0';
                 str[len--]='2';
                 str[len--]='%';
             }
         }
 	}
};
