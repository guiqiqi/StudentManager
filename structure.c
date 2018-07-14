/* 结构体定义
	
	information: 学生信息
		sex char - 性别
		char name[10] - 姓名
		int class - 班级号码

	socre: 获得的分数
		int math, physic,
			english, sport - 四科成绩

	student: 学生档案
		information* information - 学生信息
		score* score - 学生成绩
		char* index - 学号

*/

struct information{
	char* name;
	char sex;
	int class;
};

struct score{
	float math, physic;
	float english, sport;
};

typedef struct score score;
typedef struct information information;

struct student{
	information* information;
	score* score;
	char* index;
};

typedef struct student data;
// typedef struct student student;
