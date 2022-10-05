#pragma once
#include <fstream>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;


template<typename DataType>
struct Node
{
	DataType data;
	Node* next;
};


template<typename DataType>
struct List {
	Node<DataType>* Head;
	Node<DataType>* Tail;
};


struct STUDENT {
	char* name;
	char* id;
	float theory;
	float practice;
	double ave_mark;
};


template<typename DataType>
void InitList(List<DataType>& list);


template<typename DataType>
//Hàm kiểm tra danh sách có rỗng?
bool isEmpty(List<DataType> list);

//Khởi tạo 1 sinh viên
STUDENT init_STUDENT(STUDENT& student);

//Nhập 1 sinh viên
STUDENT input_1STUDENT(STUDENT& student);
//Đếm số node của 1 danh sách
template<typename DataType>
int countItems(List<DataType> list);
//Tạo node cho kiểu sinh viên
template<typename DataType>
Node<DataType>* createNode_custom(List<DataType>& list);
//Tạo node cho int, float, string
template<typename DataType>
Node<DataType>* createNode_classic(List<DataType>& list, DataType data);

//Khởi tạo danh sách với n node cho int, float, string
template<typename DataType>
void ListWithN(List<DataType>& list,DataType data);


//Thêm 1 node tại vị trí bất kì
template<typename DataType>
bool ListImplement(DataType item, int pos, List<DataType>& list, Node<DataType>* newNodePtr);
//Xóa 1 node tại vị trí bất kì
template <typename DataType>
bool removeItem(List<DataType>& list, int pos);
//In danh sách áp dụng cho kiểu dữ liệu int, float, string
template<class DataType>
void PrintList(List<DataType> list);
//In danh sách áp dụng cho kiểu dữ liệu Sinh viên
void PrintList_STUDENT(List<STUDENT> list);


//Hàm danh sách cho kiểu int
void menu_INT();
//Hàm danh sách cho kiểu float
void menu_FLOAT();

//Hàm danh sách cho kiểu string
void menu_STRING();

//Hàm danh sách cho kiểu Sinh viên
void menu_STUDENT();


//Hàm tìm kiếm phần tử ứng với key cho trước cho kiểu int và float
template<typename DataType>
void searchList_intfloat(List<DataType> list, DataType key);


//Hàm tìm kiếm phần tử ứng với key cho trước cho kiểu string
void searchList_string(List<string> list, string key);


//Hàm tìm kiếm sinh viên có id ứng với key cho trước cho kiểu Sinh viên
void searchList_ID(List<STUDENT> list, string key);


//Hàm sắp xếp cho int, float
template<typename DataType>
void sortList(List<DataType>& list);

//Hàm sắp xếp cho string
void sortList_String(List<string>& list);

//Hàm sắp xếp cho Student theo id
void sortList_Student(List<STUDENT>& list);

//Hàm giải phóng bộ nhớ đối với danh sách đã tồn tại
template<typename DataType>
void freeList(List<DataType>& list);
	