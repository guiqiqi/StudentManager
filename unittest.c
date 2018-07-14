/* 单元测试 */

#include "constant.c"
#include "structure.c"
#include "doublemix.c"
#include "functions.c"

void test_functions(void){
	// data* student1 = malloc(sizeof(data));
	// score* score1 = malloc(sizeof(score));
	// information* information1 = malloc(sizeof(information));
	// score1 -> math = 115.0;
	// score1 -> physic = 57.5;
	// score1 -> english = 108;
	// score1 -> sport = 73;
	// information1 -> name = "GUIQIQI";
	// information1 -> class = 1;
	// information1 -> sex = male;
	// student1 -> score = score1;
	// student1 -> information = information1;
	// student1 -> index = "2018102001";
	// data* student2 = malloc(sizeof(data));
	// score* score2 = malloc(sizeof(score));
	// information* information2 = malloc(sizeof(information));
	// score2 -> math = 11.0;
	// score2 -> physic = 7.5;
	// score2 -> english = 18;
	// score2 -> sport = 7;
	// information2 -> name = "CAOYUZHE";
	// information2 -> class = 2;
	// information2 -> sex = female;
	// student2 -> score = score2;
	// student2 -> information = information2;
	// student2 -> index = "2018102002";
	// node* header = init(student1);
	// append(&(header), student2);
	// char* name = findById(&(header), "2018102001") -> information -> name;
	// printf("Name of 2018102001: %s\n", name);
	// char* id = findByName(&(header), "CAOYUZHE") -> index;
	// printf("Id of CAOYUZHE: %s\n", id);
	// char* studentInfo = dataToString(student1);
	// printf("Info: %s\n", studentInfo);
	
	// data* added = stringToData(infoString);
	// printf("%s\n", added -> index);
	// printf("%f\n", added -> score -> math);
	// cls();
	// char* readen;

	// FILE* read = fopen("data.txt", "r");
	// node* header = initFromFile(read);
	// char* infoString = "123 GUI M 1 1 2 3 4";
	// data* newdata = stringToData(infoString);
	// delete(&(header), findByName(&(header), "GUIQIQI"));
	// print(header);
	// fclose(read);
	
	// system("pause");
	// FILE* write = fopen("data.txt", "a");
	// writeBack(write, header);
	// fclose(write);
	// FILE* fp = fopen("data.txt", "a");
	// if (fp != none) writeLine(fp, infoString);
	// fclose(fp);
	// if (read != none) readen = readLine(read);
	// data* added = stringToData(readen);
	// printf("Index: %s\n", added -> index);
	// 释放内存
	// free(student1);
	// free(student2);
	// free(score1);
	// free(score2);
	// free(information1);
	// free(information2);
	// free(studentInfo);
	// free(added);
	// free(readen);
}

void test_doublelink(void){
	// data* init_data = malloc(sizeof(data));
	// data* insert_data = malloc(sizeof(data));
	// data* append_data = malloc(sizeof(data));
	// data* insert_data1 = malloc(sizeof(data));
	// init_data -> index = "2018102001";
	// append_data -> index = "2018102002";
	// insert_data -> index = "2018102003";
	// insert_data1 -> index = "2018102000";
	// 测试初始化结点 init
	// node* header = init(init_data);
	// 测试增加结点 append
	// append(&(header), append_data);
	// 测试任意位置增加结点 insert
	// insert(&(header), 5, insert_data); // 超出边界检测
	// insert(&(header), 0, insert_data1); // 头部插入
	// 获取长度 count
	// printf("length: %d\n", (count(&(header))));
	// // 从中间删除 delete
	// delete(&(header), 2);
	// // 获取指定位置值 get
	// printf("pos2: %s\n", get(&(header), 2) -> index);
	// // 左侧弹出 popleft
	// printf("head: %s\n", (popleft(&(header)) -> index));
	// // 右侧弹出 pop
	// printf("tail: %s\n", (pop(&(header)) -> index));
	// 改变指定值
	// change(&(header), 2, init_data);
	// // 翻转链表
	// reverse(&(header));
	// 显示链表
	// print(header);
	// 清空链表 clear
	// clear(&(header));
	// // 判断是否为空
	// printf("empty: %d\n", empty(&(header)));
}

int main(void){
	// test_doublelink();
	// test_functions();
	system("pause");
	return 0;
}
