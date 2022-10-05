#include"Header.h"

template<typename DataType>
bool isEmpty(List<DataType> list) {
	bool check = false;
	if (list.Head == NULL) {
		check = true;
		return check;
	}
	return check;
}
template<typename DataType>
void InitList(List<DataType>& list) {
	list.Head = list.Tail = NULL;
}
STUDENT init_STUDENT(STUDENT& student) {
	student.id = (char*)malloc(20 * sizeof(char));
	if (student.id == NULL) {
		cout << "Allocate memory for 'id' failed." << endl;
		return student;
	}
	student.name = (char*)malloc(40 * sizeof(char));
	if (student.name == NULL) {
		cout << "Allocate memory for 'name' failed." << endl;
		return student;
	}
	return student;
}
STUDENT input_1STUDENT(STUDENT& student) {
	init_STUDENT(student);
	cin.ignore();
	cout << "Input student's name: ";
	cin.getline(student.name, 40);
	cout << "Input student's id: ";
	cin.getline(student.id, 20);
	cout << "Input student's theory mark: ";
	cin >> student.theory;
	cout << "Input student's practice mark: ";
	cin >> student.practice;
	student.ave_mark = 0.7 * student.theory + 0.3 * student.practice;
	return student;
}
template<typename DataType>
int countItems(List<DataType> list) {
	int count = 0;
	for (Node<DataType>* i = list.Head; i != NULL; i = i->next) {
		count++;
	}
	return count;
}
template<typename DataType>
Node<DataType>* createNode_custom(List<DataType>& list) {
	Node<DataType>* node = new Node<DataType>;
	if (node == NULL) {
		cout << "Allocate for 'node' pointer failed!." << endl;
		return NULL;
	}
	input_1STUDENT(node->data);
	node->next = NULL;
	return node;
}
template<typename DataType>
Node<DataType>* createNode_and_addtoList__custom(List<DataType>& list) {
	Node<DataType>* node = new Node<DataType>;
	if (node == NULL) {
		cout << "Allocate for 'node' pointer failed!." << endl;
		return NULL;
	}
	node->next = NULL;
	if (list.Head == NULL) {
		list.Head = node;
		list.Tail = node;
	}
	else {
		list.Tail->next = node;		//phải viết lại code này như hàm "createNode_and_addtoList" vì datatype STUDENT này có khác với các datatype int float và string...
		list.Tail = node;				//coi như viết riêng 1 hàm
	}
	return node;
}
template<typename DataType>
Node<DataType>* createNode_classic(List<DataType>& list, DataType data) {
	Node<DataType>* node = new Node<DataType>;
	if (node == NULL) {
		cout << "Allocate for 'node' pointer failed!." << endl;
		return node;
	}
	node->data = data;
	node->next = NULL;
	if (list.Head == NULL) {
		list.Head = node;
		list.Tail = node;
	}
	else {
		list.Tail->next = node;
		list.Tail = node;
	}
	return node;
}
template<typename DataType>
void ListWithN(List<DataType>& list,DataType data) {
	if (sizeof(data) == 40) {					
		createNode_classic(list,data);
	}
	else {						
		createNode_classic(list, data);
	}
}
template<typename DataType>
bool ListImplement(DataType item, int pos, List<DataType>& list, Node<DataType>* newNodePtr) {
	int temp = countItems(list);
	bool abletoInsert = (pos >= 1) && (pos <= temp);		//kiểm tra có thể thêm phần tử vào được không?
	if (abletoInsert) {
		//code trong lệnh if này là của kiểu STUDENT
		if (sizeof(DataType) == 32) {
			if (pos == 1) {		//Chèn đầu danh sách
				newNodePtr->next = list.Head;
				list.Head = newNodePtr;
			}
			else {
				int count = 1;
				for (Node<DataType>* i = list.Head; i != NULL; i = i->next)
				{
					if (pos == count) {
						newNodePtr->next = i;	//Để lưu liên kết cũ của node trước khi bị chèn bởi node mới vào phía sau
						for (Node<DataType>* j = list.Head; j != NULL; j = j->next)
						{
							if (j->next == i) {
								j->next = newNodePtr;
								break;
							}
						}
						break;
					}
					count++;
				}
			}
		}
		//bắt đầu từ lệnh else này dành cho kiểu dữ liệu int, float, string
		else {
			Node<DataType>* newNodePtr = new Node<DataType>;
			newNodePtr->data = item;
			newNodePtr->next = NULL;
			if (pos == 1) {		//Chèn đầu danh sách
				newNodePtr->next = list.Head;
				list.Head = newNodePtr;
			}
			else {
				int count = 1;
				for (Node<DataType>* i = list.Head; i != NULL; i = i->next)
				{
					if (pos == count) {
						newNodePtr->next = i;	//Để lưu liên kết cũ của node trước khi bị chèn bởi node mới vào phía sau
						for (Node<DataType>* j = list.Head; j != NULL; j = j->next)
						{
							if (j->next == i) {
								j->next = newNodePtr;
								break;
							}
						}
						break;
					}
					count++;
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
	return false;
}
template <typename DataType>
bool removeItem(List<DataType>& list, int pos) {
	int temp = countItems(list);
	bool abletoRemove = (pos >= 1) && (pos <= temp);
	if (abletoRemove) {
		int count = 1;
		if (!isEmpty(list)) {
			if (pos == 1) {
				list.Head = list.Head->next;
			}
			else {
				for (Node<DataType>* i = list.Head; i != NULL; i = i->next) {
					if (count == pos) {
						Node<DataType>* tempnode = i->next;
						for (Node<DataType>* j = list.Head; j != NULL; j = j->next)
						{
							if (j->next == i) {
								j->next = tempnode;
								delete i;
								break;
							}
						}
						break;
					}
					count++;
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
	return false;
}
template<class DataType>
void PrintList(List<DataType> list) {
	cout << "LIST: ";
	for (Node<DataType>* i = list.Head; i !=NULL; i=i->next)
	{
		cout << i->data << "   ";
	}
	cout << endl;
}
void PrintList_STUDENT(List<STUDENT> list) {
	int count = 1;
	for (Node<STUDENT>* i = list.Head; i != NULL; i = i->next)
	{
		cout << "STUDENT " << count << ": " << endl;
		cout << "Name: " << i->data.name << endl;
		cout << "Id: " << i->data.id << endl;
		cout << "Theory mark: " << i->data.theory << endl;
		cout << "Practice mark: " << i->data.practice << endl;
		cout << "Average mark: " << i->data.ave_mark << endl;
		cout << "-----------------------------------------------------" << endl;
		count++;
	}
	cout << endl;
}
template<typename DataType>
void searchList_intfloat(List<DataType> list, DataType key) {
	if (isEmpty(list)) {
		cout << "There is no element to search!" << endl;
	}
	else {
		bool check = false;
		int count = 1;
		for (Node<DataType>* i = list.Head; i != NULL; i = i->next)
		{
			 if(i->data==key) {
				cout << "Data and position of element has value equal to key..." << endl;
				cout << "Data: " << i->data << endl;
				cout << "Position: " << count << endl;
				check = true;
			}
			count++;
		}
		if (check == false) {
			cout << "There is no element in the list equal to key!" << endl;
		}
	}
}
void searchList_string(List<string> list, string key) {
	if (isEmpty(list)) {
		cout << "There is no element to search!" << endl;
	}
	else {
		bool check = false;
		int count = 1;
		for (Node<string>* i = list.Head; i != NULL; i = i->next)
		{
			const char* cstr1 = key.c_str();
			const char* cstr2 = i->data.c_str();
			int comp = strcmp(cstr1, cstr2);
			if (comp == 0) {
				cout << "Data and position of element has value equal to key..." << endl;
				cout << "Data: " << i->data<<endl;
				cout << "Position: " << count<<endl;
				check = true;
			}
			count++;
		}
		if (check == false) {
			cout << "There is no element in the list equal to key!" << endl;
		}
	}
}
void searchList_ID(List<STUDENT> list, string key) {
	if (isEmpty(list)) {
		cout << "There is no element to search!" << endl;
	}
	else {
		bool check = false;
		int count = 1;
		for (Node<STUDENT>* i = list.Head; i != NULL; i = i->next)
		{
			const char* cstr1 = key.c_str();
			int comp = strcmp(cstr1, i->data.id);
			if (comp == 0) {
				cout << "Data and position of element has value equal to key..." << endl;
				cout << "Data: " << i->data.id << endl;
				cout << "Position: " << count << endl;
				check = true;
			}
			count++;
		}
		if (check == false) {
			cout << "There is no element in the list equal to key!" << endl;
		}
	}
}
template<typename DataType>
void sortList(List<DataType>& list) {
	if (isEmpty(list)) {
		cout << "There is no element in this list to sort!" << endl;
	}
	else {
		for (Node<DataType>* i = list.Head; i != NULL; i = i->next) {
			for (Node<DataType>* j = list.Head; j != NULL; j = j->next)
			{
				if (i->data < j->data) {
					swap(i->data, j->data);
				}
			}
		}
		cout << "Sort list process run successfully." << endl;
	}
}
void sortList_String(List<string>& list) {
	if (isEmpty(list)) {
		cout << "There is no element in this list to sort!" << endl;
	}
	else {
		for (Node<string>* i = list.Head; i != NULL; i = i->next) {
			for (Node<string>* j = list.Head; j != NULL; j = j->next)
			{
				const char* cstr1 = i->data.c_str();
				const char* cstr2 = j->data.c_str();
				int comp = strcmp(cstr1, cstr2);
				if (comp == -1) {
					swap(i->data, j->data);
				}
			}
		}
		cout << "Sort list process run successfully." << endl;
	}
}
void sortList_Student(List<STUDENT>& list) {
	if (isEmpty(list)) {
		cout << "There is no element in this list to sort!" << endl;
	}
	else {
		for (Node<STUDENT>* i = list.Head; i != NULL; i = i->next) {
			for (Node<STUDENT>* j = list.Head; j != NULL; j = j->next)
			{
				int comp = strcmp(i->data.id, j->data.id);
				if (comp == -1) {
					swap(i->data, j->data);
				}
			}
		}
		cout << "Sort list process run successfully." << endl;
	}
}
template<typename DataType>
void freeList(List<DataType>& list) {
	if (isEmpty(list)) {
		cout << "This list is empty to free!" << endl;
	}
	else{
		for (Node<DataType>* i = list.Head; i!=NULL  ; i=i->next)
		{
			delete i;
		}
		cout << "Free list process run successfully." << endl;
	}
}
void menu_INT() {
	bool to_check = true;
	List<int> list;
	int n;
	char* a = NULL;
	int pos;
	int key;
	int item;
	InitList(list);
	int data;
	Node<int>* p = NULL;
	ontop:
	cout << "======================== <STRING> LINKING LIST =======================================" << endl;
	cout << "1. Initiate list with n elements." << endl;
	cout << "2. Print list." << endl;
	cout << "3. Insert element to specific position of the list." << endl;
	cout << "4. Remove element from the list." << endl;
	cout << "5. Search element has data equal to key." << endl;
	cout << "6. Sort into ascending list." << endl;
	cout << "7. Free list that no longer be used." << endl;
	cout << "8. Clear screen." << endl;
	cout << "9. Exit program." << endl;
	cout << "======================================================================================" << endl;
	int choose;
here:
	cout << "Your choice: ";
	cin >> choose;
	switch (choose)
	{
	case 1:
		cout << "Input element numbers to initiate list or input 0 to exit the program: ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Input data: ";
			cin.ignore();
			cin >> data;
			ListWithN(list, data);
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		goto here;
	case 2:
		to_check = isEmpty(list);
		if (to_check) {
			cout << "Empty list!" << endl;
		}
		else {
			PrintList(list);
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		goto here;
	case 3:
		cout << "Input data: ";
		cin >> item;
		cout << "Input position: ";
		cin >> pos;
		to_check = ListImplement(item, pos, list, p);
		if (!to_check) {
			cout << "Implement process failed!" << endl;
		}
		else {
			cout << "Implement process succeeded!" << endl;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		goto here;
	case 4:
		cout << "Input position to remove: ";
		cin >> pos;
		to_check = removeItem(list, pos);
		if (!to_check) {
			cout << "Removing element process failed!" << endl;
		}
		else {
			cout << "Removing element process succeeded!" << endl;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		goto here;
	case 5:
		cout << "Input value to search: ";
		cin >> key;
		searchList_intfloat(list, key);
		goto here;
	case 6:
		sortList(list);
		goto here;
	case 7:
		freeList(list);
		goto here;
	case 8:
		system("cls");
		goto ontop;
	case 9:
		exit(0);
	default:
		cout << "Invalid choice!" << endl;
		goto here;
	}
}
void menu_FLOAT() {
	bool to_check = true;
	List<float> list;
	int n;
	int pos;
	float data;
	float item;
	float key;
	Node<float>* p = NULL;
	InitList(list);
ontop:
	cout << "======================== <STRING> LINKING LIST =======================================" << endl;
	cout << "1. Initiate list with n elements." << endl;
	cout << "2. Print list." << endl;
	cout << "3. Insert element to specific position of the list." << endl;
	cout << "4. Remove element from the list." << endl;
	cout << "5. Search element has data equal to key." << endl;
	cout << "6. Sort into ascending list." << endl;
	cout << "7. Free list that no longer be used." << endl;
	cout << "8. Clear screen." << endl;
	cout << "9. Exit program." << endl;
	cout << "======================================================================================" << endl;
	int choose;
here:
	cout << "Your choice: ";
	cin >> choose;
	switch (choose) {

	case 1:
		cout << "Input element numbers to initiate list or input 0 to exit the program: ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Input data: ";
			cin >> data;
			ListWithN(list, data);
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		goto here;

	case 2:
		to_check = isEmpty(list);
		if (to_check) {
			cout << "Empty list!" << endl;
		}
		else {
			PrintList(list);
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		goto here;
	case 3:
		cout << "Input data: ";
		cin >> item;
		cout << "Input position: ";
		cin >> pos;
		to_check = ListImplement(item, pos, list, p);
		if (!to_check) {
			cout << "Implement process failed!" << endl;
		}
		else {
			cout << "Implement process succeeded!" << endl;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		goto here;
	case 4:
		cout << "Input position to remove: ";
		cin >> pos;
		to_check = removeItem(list, pos);
		if (!to_check) {
			cout << "Removing element process failed!" << endl;
		}
		else {
			cout << "Removing element process succeeded!" << endl;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		goto here;
	case 5:
		cout << "Input value to search: ";
		cin >> key;
		searchList_intfloat(list, key);
		goto here;
	case 6:
		sortList(list);
		goto here;
	case 7:
		freeList(list);
		goto here;
	case 8:
		system("cls");
		goto ontop;
	case 9:
		exit(0);
	default:
		cout << "Invalid choice!" << endl;
		goto here;
	}
}
void menu_STRING() {
	bool to_check = true;
	List<string> list;
	int n;
	int pos;
	string key;
	string item;
	string data;
	Node<string>* p = NULL;
	char* a = NULL;
	InitList(list);
ontop:
	cout << "======================== <STRING> LINKING LIST =======================================" << endl;
	cout << "1. Initiate list with n elements." << endl;
	cout << "2. Print list." << endl;
	cout << "3. Insert element to specific position of the list." << endl;
	cout << "4. Remove element from the list." << endl;
	cout << "5. Search element has data equal to key." << endl;
	cout << "6. Sort into ascending list (alphabet)." << endl;
	cout << "7. Free list that no longer be used." << endl;
	cout << "8. Clear screen." << endl;
	cout << "9. Exit program." << endl;
	cout << "======================================================================================" << endl;
	int choose;
here:
	cout << "Your choice: ";
	cin >> choose;
	switch (choose)
	{
	case 1:
		cout << "Input element numbers to initiate list or input 0 to exit the program: ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Input data: ";
			cin >> data;
			ListWithN(list, data);
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		goto here;
	case 2:
		to_check = isEmpty(list);
		if (to_check) {
			cout << "Empty list!" << endl;
		}
		else {
			PrintList(list);
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		goto here;
	case 3:
		cout << "Input data: ";
		cin >> item;
		cout << "Input position: ";
		cin >> pos;
		to_check=ListImplement(item, pos, list, p);
		if (!to_check) {
			cout << "Implement process failed!" << endl;
		}
		else {
			cout << "Implement process succeeded!" << endl;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		goto here;
	case 4:
		cout << "Input position to remove: ";
		cin >> pos;
		to_check = removeItem(list, pos);
		if (!to_check) {
			cout << "Removing element process failed!" << endl;
		}
		else {
			cout << "Removing element process succeeded!" << endl;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		goto here;
	case 5:
		cout << "Input value to search: ";
		cin >> key;
		searchList_string(list, key);
		goto here;
	case 6:
		sortList_String(list);
		goto here;
	case 7:
		freeList(list);
		goto here;
	case 8:
		system("cls");
		goto ontop;
	case 9:
		exit(0);
	default:
		cout << "Invalid choice!" << endl;
		goto here;
	}
}
void menu_STUDENT() {
	bool to_check = true;
	List<STUDENT> list;
	int pos;
	int n;
	STUDENT item;
	item.ave_mark=0;
	item.id=NULL;
	item.name=NULL;
	item.theory=0;
	item.practice=0;
	fstream file;
	string key;
	string data;
	Node<STUDENT>* p = NULL;
	InitList(list);
ontop:
	cout << "======================== <STRING> LINKING LIST =======================================" << endl;
	cout << "1. Initiate list with n elements." << endl;
	cout << "2. Print list." << endl;
	cout << "3. Insert element to specific position of the list." << endl;
	cout << "4. Remove element from the list." << endl;
	cout << "5. Search student that has id equal to key." << endl;
	cout << "6. Sort into ascending list (for ID)." << endl;
	cout << "7. Free list that no longer be used." << endl;
	cout << "8. Clear screen." << endl;
	cout << "9. Exit program." << endl;
	cout << "======================================================================================" << endl;
	int choose;
here:
	cout << "Your choice: ";
	cin >> choose;
	switch (choose)
	{
	case 1:
		file.open("STUDENTLIST.txt", ios::in);
		cout << "Input element numbers to initiate list or input 0 to exit the program: ";
		cin >> n;
		if (n < 1) {
			cout << "Can not initiate the list with n <= 0 elements, the program can execute if the list has at least one." << endl;
			exit(0);
		}
		else {
			for (int i = 0; i < n; i++)
			{
				createNode_and_addtoList__custom(list);
				if (!isEmpty(list)) {
				}
			}
			for (Node<STUDENT>* i = list.Head; i != NULL; i = i->next)
			{
				init_STUDENT(i->data);
				file.getline(i->data.id, 20, ',');
				file.seekg(1, 1);
				file.getline(i->data.name, 40, ',');
				file.seekg(1, 1);
				file >> i->data.theory;
				file.seekg(1, 1);
				file >> i->data.practice;
				file.seekg(1, 1);
				i->data.ave_mark = 0.7 * i->data.theory + 0.3 * i->data.practice;
				file.ignore();
			}
			file.close();
			cout << "Read file successfully!" << endl;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		goto here;
	case 2:
		to_check=isEmpty(list);
		if (to_check) {
			cout << "Empty list!" << endl;
		}
		else {
			PrintList_STUDENT(list);
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		goto here;
	case 3:
		p=createNode_custom(list);
		cout << "Input position: ";
		cin >> pos;
		to_check = ListImplement(item, pos, list, p);
		if (!to_check) {
			cout << "Implement process failed!" << endl;
		}
		else {
			cout << "Implement process succeeded!" << endl;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		goto here;
	case 4:
		cout << "Input position to remove: ";
		cin >> pos;
		to_check=removeItem(list, pos);
		if (!to_check) {
			cout << "Removing element process failed!" << endl;
		}
		else {
			cout << "Removing element process succeeded!" << endl;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		goto here;
	case 5:
		cout << "Input value to search: ";
		cin >> key;
		searchList_ID(list, key);
		goto here;
	case 6:
		sortList_Student(list);
		goto here;
	case 7:
		freeList(list);
		goto here;
	case 8:
		system("cls");
		goto ontop;
	case 9:
		exit(0);
	default:
		cout << "Invalid choice!" << endl;
		goto here;
	}
}
int main() {
	bool to_check = true;
	int step1;
	cout << "CHOOSE DATATYPE..." << endl;
	cout << "1. Int." << endl;
	cout << "2. Float." << endl;
	cout << "3. String." << endl;
	cout << "4. STUDENT struct." << endl;
	cout << "Which datatype: " << endl;
	cin >> step1;
	switch (step1) {
	case 1:
		menu_INT();
	case 2:
		menu_FLOAT();
	case 3:
		menu_STRING();
	case 4:
		menu_STUDENT();
	}
	system("pause");
	return -1;
}