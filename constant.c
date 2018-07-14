/* 常量定义 */

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define true 1 // boolean - true
#define false 0 // boolean - false
#define none NULL // none
#define undefined -1 // 数组下标越位

#define male 'M' // 男性
#define female 'F' // 女性

#define MIN_SCORE 0 // 最小成绩
#define MAX_SCORE 150 // 最大成绩
#define MAX_LENGTH 20// 字符串最大宽度
#define ERROR "error" // 错误的缺省值

// 最大缓冲区计算方法:
// 字符串x2, 一个汉字4个字节(最大), 加int最大长10位
// 加5位长小数x4, 加8个空格
#define MAX_LINE_WIDTH MAX_LENGTH * 2 * 4 + 10 + 5 * 4 + 8

// 定义宏函数获取长度
#define len(array) (sizeof(array) / sizeof(array[0]))
// 定义宏函数清空屏幕
#define cls() system("cls")
