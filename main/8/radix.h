/*
 * 基数排序相关的数据结构
 * 和数据读入，输出的函数
 * by wareric@163.com
 * 2017-11-5
 */
#ifndef RADIX_H_
#define RADIX_H_
//输入数据位数
#define DIGIT 4

typedef struct data Data;

struct data{
	int digit[DIGIT];
	long num;
};

/*
 * 打印数组
 * end表示最后一个data+1的位置
 */
void show_array(Data *head, Data *end);

/*
 * 加载数据
 * 返回最有一个data+1的位置
 */
Data* load_array(char *file, Data **first);

#endif
