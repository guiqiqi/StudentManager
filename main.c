/* 主程序文件 */

#include "constant.c"
#include "structure.c"
#include "doublemix.c"
#include "functions.c"

char filename[256] = {'\0'}; // 文件名全局变量
node* header = none; // 链表头部全局变量

int main();

// 打印separator
void separator(void){
	char* separator = malloc(77);
	memset(separator, '\x3D', 74);
	printf("   %s\n", separator);
	free(separator);
}

// 打印数据格式
void dataStruct(void){
	char dataStruct[] = 
	"StudentID  Name  Sex  Class  Math  Physic  English  Sport";
	printf("   %s\n", dataStruct);
}

// 打印title
void title(void){
	separator();
	char* div = malloc(21);
	memset(div, '\x20', 21);
	char titile[] = "Student Information Management System";
	printf("%s%s\n", div, titile);
	separator();
	free(div);
}

// 手动添加数据菜单
void input(){
	cls(); title();
	printf("   Add data by this order, split by space:\n");
	dataStruct();
	printf("   When finished, make a new line and press Enter.\n");
	separator();
	char line[MAX_LINE_WIDTH]; int count = 0;
	printf("   Input: "); gets(line);
	while (line[0] != '\0'){
		data* newdata = stringToData(line);
		if (header == none) header = init(newdata);
		else append(&(header), newdata);
		printf("   Added: %s\n", dataToString(newdata));
		count++;
		printf("   Input: "); gets(line);
	}
	if (header == none) input(); // 如果数据源未输入重新开始
	separator();
	printf("   Added %d record(s)\n", count);
	printf("   Press Enter to continue.");
	getchar(); main();
}

// 打印数据来源选项
void source(void){
	cls(); title();
	printf("   We need to create dataset before start...\n");
	printf("   Options:\n");
	printf("     1 - Add manully");
	printf("  2 - Import from file\n");
	separator();
	printf("   Select and Enter (1 - 2): ");
	int choice = 0;
	scanf("%d", &choice); getchar();
	switch (choice){
		case 1: {
			input(); break;
		}
		case 2: {
			printf("   Input filename: ");
			scanf("%s", filename);
			getchar();
			FILE* read = fopen(filename, "r");
			if (read == none){
				printf("   Can not open file, try again.");
				getchar(); fclose(read);
				filename[0] = '\0'; // 初始化文件名值
				source(); break;
			}
			header = initFromFile(read);
			if (header == none){
				printf("   File is empty, try again.");
				getchar(); fclose(read);
				filename[0] = '\0'; // 初始化文件名值
				source(); break;
			}
			fclose(read);
			break;
		}
		default: {
			getchar();
			source();
		}
	}
}

// 打印菜单
int menu(void){
	cls(); //先清空屏幕
	title();
	printf("   Options:\n");
	puts("     0 - Save and Exit");
	printf("     1 - Reselect Source");
	printf("     2 - Add information\n");
	printf("     3 - View information");
	printf("    4 - Edit information\n");
	printf("     5 - Find information");
	printf("    6 - Delete information\n");
	separator();
	printf("   Select and Enter (0 - 6): ");
	int choice = -1;
	scanf("%d", &choice); getchar();
	if (6 < choice || choice < 0) menu();
	return choice;
}

// 查询单个学生信息
void findStd(node* header){
	cls(); title();
	printf("   Options:\n");
	printf("     1 - Search by student id");
	printf("  2 - Search by student name\n");
	separator();
	printf("   Select and Enter (1 - 2): ");
	int choice = -1;
	scanf("%d", &choice); getchar();
	if (choice != 1 && choice != 2) findStd(header);
	char token[MAX_LINE_WIDTH];
	printf("   Input condition: ");
	scanf("%s", token); getchar();
	int position = 0;
	if (choice == 1) position = findById(&(header), token);
	if (choice == 2) position = findByName(&(header), token);
	separator();
	data* found = get(&(header), position);
	if (found == none){
		printf("   Could not find student.\n");
	}
	else{
		printf("   Find result:\n");
		dataStruct();
		printf("   %s\n", dataToString(found));
	}
	printf("   Press Enter to continue.");
	getchar(); main();
}

// 删除单个学生信息
void deleteStd(node* header){
	cls(); title();
	printf("   Options:\n");
	printf("     1 - Delete by student id");
	printf("  2 - Delete by student name\n");
	separator();
	printf("   Select and Enter (1 - 2): ");
	int choice = -1;
	scanf("%d", &choice); getchar();
	if (choice != 1 && choice != 2) findStd(header);
	char token[MAX_LINE_WIDTH];
	printf("   Input condition: ");
	scanf("%s", token); getchar();
	int position = 0;
	if (choice == 1) position = findById(&(header), token);
	if (choice == 2) position = findByName(&(header), token);
	separator();
	data* found = get(&(header), position);
	if (found == none){
		printf("   Could not find student.\n");
	}else{
		if (count(&(header)) == 1){
			printf("   Unable to delete unique record!\n");
		}else{
			delete(&(header), position);
			printf("   Delete item:\n");
			dataStruct();
			printf("   %s\n", dataToString(found));
		}
	}
	printf("   Press Enter to continue.");
	getchar(); main();
}

// 修改单个学生信息
void editStd(node* header){
	cls(); title();
	printf("   Options:\n");
	printf("     1 - Edit by student id");
	printf("  2 - Edit by student name\n");
	separator();
	printf("   Select and Enter (1 - 2): ");
	int choice = -1;
	scanf("%d", &choice); getchar();
	if (choice != 1 && choice != 2) findStd(header);
	char token[MAX_LENGTH];
	printf("   Input condition: ");
	scanf("%s", token); getchar();
	int position = 0;
	if (choice == 1) position = findById(&(header), token);
	if (choice == 2) position = findByName(&(header), token);
	data* found = get(&(header), position);
	if (found == none){
		separator();
		printf("   Could not find student.\n");
	}else{
		char newinfo[MAX_LINE_WIDTH];
		printf("   New information: ");
		gets(newinfo);
		data* newdata = stringToData(newinfo);
		change(&(header), position, newdata);
		separator();
		printf("   Edited item:\n");
		dataStruct();
		printf("   %s ->\n", dataToString(found));
		printf("   %s\n", dataToString(newdata));
	}
	printf("   Press Enter to continue.");
	getchar(); main();
}

// 打印全部学生信息
void printall(node* header){
	cls(); title();
	print(header);
	printf("   Press Enter to continue.");
	getchar(); main();
}

// 退出执行函数
void iexit(node* header){
	if (filename[0] == '\0'){
		printf("   Save in file (press Enter to skip): ");
		scanf("%s", filename); getchar();
	}
	FILE* write = fopen(filename, "w");
	if (write == none){
		cls(); title();
		printf("!!! Write back failed.\n");
		printf("!!! Here is all informations:\n");
		print(header);
		getchar();
	}else{
		writeBack(write, header);
		fclose(write);
	}
	exit(1);
}

// 主函数
int main(){
	while (header == none) source();
	int choice = menu();
	switch (choice){
		case 0: iexit(header);
		case 1: source(); main(); break;
		case 2: input(); break;
		case 3: printall(header); break;
		case 4: editStd(header); break;
		case 5: findStd(header); break;
		case 6: deleteStd(header); break;
	}
	return 0;
}
