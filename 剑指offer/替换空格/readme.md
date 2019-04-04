# 题目链接
[牛客网剑指offer-替换空格](https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
# 题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

# 解题思路 
可以用vector来挨个保存字符串中的字符，遇到空格则保存“%20”，最后再把vector中的字符串复制到原字符串中。(也可以用string)


但是更优的解法是，先统计空格的个数，确定替换后字符串的长度，再从后往前替换，这样每个字符最多移动一次，降低时间复杂度

# 用vector的解法

```
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

```

# 更优解

```
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
```

