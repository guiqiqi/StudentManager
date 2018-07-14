/* 用到的函数库 */

// 通过学生的ID查找学生信息
int findById(node** header, char* index){
	if (*header == none) return undefined;
	int position = 0;
	node* current = *header;
	while (current != none){
		if (strcmp(current -> data -> index, index) == false){
			return position;
		}else{
			current = current -> next;
			position++;
		}
	}
	return undefined;
}

// 通过学生的姓名查找学生信息
int findByName(node** header, char* name){
	if (*header == none) return undefined;
	int position = 0;
	node* current = *header;
	while (current != none){
		if (strcmp(current -> data -> information -> name, name) == false){
			return position;
		}else{
			current = current -> next;
			position++;
		}
	}
	return undefined;
}

// 将学生信息转换成字符串
char* dataToString(data* data){
	int length = 0;
	length += len(data -> index) * 4;
	length += len(data -> information -> name) * 4;
	length += 7 + 5 * 4 + 1;
	char* info = malloc(length);
	sprintf(info, "%s %s %c %d %5.2f %5.2f %5.2f %5.2f",
		data -> index, data -> information -> name,
		data -> information -> sex,
		data -> information -> class,
		data -> score -> math, data -> score -> physic,
		data -> score -> english, data -> score -> sport
	);
	return info;
}

// 将信息字符串转换成结构体
data* stringToData(char* string){
	char* _string = malloc(strlen(string) * 4);
	strcpy(_string, string);
	free(string);
	data* std = malloc(sizeof(data));
	score* scores = malloc(sizeof(score));
	information* info = malloc(sizeof(information));
	std -> score = scores;
	std -> information = info;
	char* split = " ";
	char* token = strtok(_string, split);
	int round = 1;
	while (token != none){
		switch (round){
			case 1:{
					if (strlen(token) > MAX_LENGTH){
						std -> index = ERROR;
						break;
					}
					std -> index = token;
					break;
				}
			case 2:{
					if (strlen(token) > MAX_LENGTH){
						std -> index = ERROR;
						break;
					}
					std -> information -> name = token;
					break;
				}
			case 3:{
					char sex = token[0];
					if (sex != male && sex != female){
						std -> information -> sex = male;
						break;
					}
					std -> information -> sex = sex;
					break;
				}
			case 4:{
					int class = atoi(token);
					std -> information -> class = class;
					break;
				}
			case 5:{
					float math = atof(token);
					if (MAX_SCORE < math || math < MIN_SCORE){
						std -> score -> math = -1;
						break;
					}
					std -> score -> math = math;
					break;
				}
			case 6:{
					float physic = atof(token);
					if (MAX_SCORE < physic || physic < MIN_SCORE){
						std -> score -> physic = -1;
						break;
					}
					std -> score -> physic = physic;
					break;
				}
			case 7:{
					float english = atof(token);
					if (MAX_SCORE < english || english < MIN_SCORE){
						std -> score -> english = -1;
						break;
					}
					std -> score -> english = english;
					break;
				}
			case 8:{
					float sport = atof(token);
					if (MAX_SCORE < sport || sport < MIN_SCORE){
						std -> score -> sport = -1;
						break;
					}
					std -> score -> sport = sport;
					break;
				}
		}
		token = strtok(none, split);
		round++;
	}
	return std;
}

// 写入一行东西
void writeLine(FILE* filehandler, const char* content){
	if (filehandler == none) return;
	fprintf(filehandler, "%s\n", content);
}

// 读取一行东西
char* readLine(FILE* filehandler){
	if (filehandler == none) return none;
	char* result = malloc(MAX_LINE_WIDTH);
	memset(result, '\0', MAX_LINE_WIDTH);
	char buffer[MAX_LINE_WIDTH] = {'\0'};
	if (!feof(filehandler)){
		if (fgets(buffer, MAX_LINE_WIDTH, filehandler)){
			strcpy(result, buffer);
			return result;
		}
	}else{
		return none;
	}
}

// 从文件读取全部的学生信息构造表
node* initFromFile(FILE* filehandler){
	char* startline = readLine(filehandler);
	char* newline = readLine(filehandler);
	if (startline == none) return none;
	node* header = init(stringToData(startline));
	data* newdata;
	while (newline != none){
		newdata = stringToData(newline);
		insert(&(header), 0, newdata);
		newline = readLine(filehandler);
	}
	reverse(&(header));
	return header;
}

// 将所有学生信息写回文件
void* writeBack(FILE* filehandler, node* header){
	char* line;
	node* current = header;
	while (current != none){
		line = (dataToString(current -> data));
		writeLine(filehandler, line);
		current = current -> next;
	}
}

// 打印所有的学生信息
void print(node* header){
	node* current = header;
	while (current != none){
		printf("   %s\n", (dataToString(current -> data)));
		current = current -> next;
	}
}

// 单独打印一个学生的信息
void show(node* current){
	puts(dataToString(current -> data));
}
