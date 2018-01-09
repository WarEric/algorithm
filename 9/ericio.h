/*
 * 这是用来处理自己定义的数据格式IO函数
 * by wareric@163.com
 * 2017-9-29
 */
#ifndef ERICIO_H_
#define ERICIO_H_

#include <stdio.h>
#include <stdlib.h>

/*
 * 输入数组的头部和尾部
 * 将数组数据打印出来
 */
void show_array(int *head,int *tail);

/* 从文件中读取数据，并且将输入的指针置为数组的起始点
 * 同时返回数组最后一位数的指针
 */
int* load_array(char *file,int **first);

#endif
