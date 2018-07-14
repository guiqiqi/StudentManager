/* 构造一个双链表, 支持的方法如下:
	
	* 函数的第一个参数均是链表的头结点
·	init: 初始化一个新的节点, O(1) init() -> node*
·	clear: 清空链表的所有节点, O(N) clear() -> void
·	popleft: 从左侧弹出, O(1) popleft() -> data*
·	pop: 从右侧弹出, O(N) pop() -> data*
·	delete: 从中间删除, O(N) delete(int position) -> data*
·	get: 获取指定位置的值, O(N) get(int position) -> data*
·	empty: 判断链表是否为空, O(1) empty() -> boolean
·	change: 变化链表指定位置的值, O(N) change(int postiion, data* data) -> void
·	append: 向链表尾部添加新节点, O(1) append(data* data) -> void
·	insert: 向链表指定位置添加节点, O(N) insert(int position, data* data) -> void
·	reverse: 翻转链表, O(N) reverse() -> void
·	count: 获取链表数量, O(N) count() -> int

*/

struct node{
	data* data;
	struct node* prev;
	struct node* next;
};

typedef struct node node;

node* init(data* data){
	node* header;
	header = (node*)malloc(sizeof(node));
	header -> prev = none;
	header -> data = data;
	header -> next = none;
	return header;
}

void append(node** header, data* data){
	if (*header == none) return;
	node* newnode = init(data);
	node* current = *header;
	while (current -> next != none){
		current = current -> next;
	}
	current -> next = newnode;
	newnode -> prev = current;
}

void insert(node** header, int position, data* data){
	if (*header == none) return;
	int count = position;
	node* previous = none;
	node* current = *header;
	node* newnode = init(data);
	while ((count != 0) && (current != none)){
		previous = current;
		current = current -> next;
		count--;
	}
	newnode -> prev = previous;
	newnode -> next = current;
	if (position == 0) *header = newnode;
	if (current != none) current -> prev = newnode;
	if (previous != none) previous -> next = newnode;
}

void clear(node** header){
	if (*header == none) return;
	node* current;
	current = *header;
	while (current != none){
		free(current);
		current = current -> next;
	}
	free(current);
	*header = none;
}

data* popleft(node** header){
	if (*header == none) return none;
	node* oldheader;
	node* newheader;
	data* data;
	data = (*header) -> data;
	oldheader = (*header);
	newheader = (*header) -> next;
	newheader -> prev = none;
	*header = newheader;
	free(oldheader);
	return data;
}

data* pop(node** header){
	if (*header == none) return none;
	data* data;
	node* previous;
	node* current = *header;
	while ((current -> next) != none){
		current = current -> next;
	}
	previous = current -> prev;
	previous -> next = none;
	data = current -> data;
	free(current);
	return data;
}

void delete(node** header, int position){
	if (*header == none) return;
	if (position == 0){
		popleft(header);
		return;
	}
	int count = position;
	node* current = *header;
	while ((count != 0) && (current -> next != none)){
		current = current -> next;
		count--;
	}
	current -> prev -> next = current -> next;
	if (current -> next != none){
		current -> next -> prev = current -> prev;
	}
	free(current);
}

data* get(node** header, int position){
	if (*header == none) return none;
	if (position < 0) return none;
	int count = position;
	data* data = none;
	node* current = *header;
	while ((count != 0) && (current -> next != none)){
		current = current -> next;
		count--;
	}
	data = current -> data;
	return data;
}

int empty(node** header){
	if (*header == none) return true;
	return false;
}

void change(node** header, int position, data* data){
	if (*header == none) return;
	if (position < 0) return;
	int count = position;
	node* current = *header;
	while ((count !=0) && (current -> next != none)){
		current = current -> next;
		count--;
	}
	current -> data = data;
}

void reverse(node** header){
	node* next;
	node* previous;
	node* current = *header;
	while (current != none){
		next = current -> prev;
		previous = current -> next;
		current -> next = next;
		current -> prev = previous;
		current = previous;
	}
	*header = next -> prev;
}

int count(node** header){
	node* current = *header;
	int result = 0;
	while (current != none){
		current = current -> next;
		result++;
	}
	return result;
}
