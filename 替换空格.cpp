/*
题目：
	请实现一个函数，将一个字符串中的每个空格替换成“%20”。
	例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
class Solution {
public:
	void replaceSpace(char *str,int length) {
        //首先看看有多少空格
        int spaceNum = 0;
        for(int i=0; i < length; i++){
            if(str[i] == ' ')
                spaceNum++;
        }
        for(int i = length -1; i >=0; i--){
            if(str[i] == ' '){
                str[i+spaceNum*2] = '0';
                str[i+spaceNum*2-1] = '2';
                str[i+spaceNum*2-2] = '%';
                spaceNum--;
            }
            else{
                str[i+spaceNum*2] = str[i];
            }
        }
	}
};
//通过
//运行时间：6ms
//占用内存：580k