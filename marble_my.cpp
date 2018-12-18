/*#include<iostream>
#include<list>
#include<string>
using namespace std;
int main()
{
	list<char> s;
	list<char>::iterator it = s.begin();
	string a;
	while (cin >> a)
	{
		for (int i = 0; i < a.length(); i++) {
			char ch = a[i];
			if (ch == '[')it = s.begin();
			else if (ch == ']')it = s.end();
			else {
				s.insert(it, ch);
			}
		}
		for (it = s.begin(); it != s.end(); it++)
		{
			cout << *it;
		}
		cout << endl;
		s.clear();
	}
	system("pause");
	return 0;
}*/


#include <iostream>
using namespace std;
struct Node {
	int data;
	Node *next;
};
class Linklist {
private:
	Node * Head;
public:
	Linklist();
	void CreatList1(int n);        //头插入法创建链表
	void CreatList2(int n);        //尾插入法创建链表
	void Insert(int i, int e);     //插入函数
	int Delete(int i);             //删除表中元素
	int GetData(int i);            //取得表中元素值
	int Search(int obj);           //在表中寻找匹配项
	int ListLength();              //获得表的长度
	void Display();                //遍历整个链表
};

Linklist::Linklist() {                   //构造函数
	Head = new Node;
	Head->next = NULL;
}
void Linklist::CreatList1(int n) {      //头插入法创建链表
	Node *p;
	Node *temp;
	p = Head;
	cout << "请依次输入" << n << "个链表的值:";
	for (int i = 1; i <= n; i++) {
		temp = new Node;
		cin >> temp->data;
		temp->next = p->next;
		p->next = temp;
	}
}
void Linklist::CreatList2(int n) {      //尾插入法创建链表
	Node *p;
	Node *temp;
	p = Head;
	cout << "请依次输入" << n << "个链表的值:";
	for (int i = 0; i < n; i++) {
		temp = new Node;
		cin >> temp->data;
		p->next = temp;
		p = temp;
	}
}

void Linklist::Insert(int i, int e) {       //在i处插入e
	Node *temp;
	temp = Head;
	int j = 0;
	while ( temp && j < i - 1) {
		temp = temp->next;
		j++;
	}
	if (!temp || j > i - 1) {
		cout << "插入位置错误";
	}
	else {
		Node *s;
		s = new Node;
		s->data = e;
		s->next = temp->next;
		temp->next = s;
	}
}
int Linklist::Delete(int i) {          //删除i处的数据
	Node *temp;
	temp = Head;
	int j = 0;
	while (temp&&j < i - 1) {
		temp = temp->next;
		j++;
	}
	if (!temp || j > i - 1) {
		cout << "删除位置错误";
		return -1;
	}
	else {
		Node *s;
		s = temp->next;
		temp->next = s->next;
		delete s;
	}
}
int Linklist::GetData(int i) {         //得到i处的元素
	Node *temp;
	temp = Head;
	int j = 0;
	while (temp&&j < i - 1) {
		temp = temp->next;
		j++;
	}
	if (!temp || j > i - 1) {
		cout << "寻找位置错误\n";
		return -1;
	}
	else {
		cout << i << "处的数据为：" << temp->next->data << "\n";
		return temp->data;
	}
}
int Linklist::Search(int obj) {       //寻找链表中有无与obj匹配的元素
	int j = 1;
	Node *temp;
	temp = Head->next;
	while (temp && temp->data != obj) {
		temp = temp->next;
		j++;
	}
	if (temp == NULL) {
		cout << "该链表中无此元素" << "\n";
		return 0;
	}
	else {
		cout << "在该链表中的第" << j << "个元素等于" << obj << "\n";
		return j;
	}
}
int Linklist::ListLength() {                //计算链表长度
	Node *temp;
	temp = Head;
	int j = 0;
	while (temp) {
		temp = temp->next;
		j++;
	}
	cout << "该链表的长度为：" << j - 1 << "\n";
	return j;
}
void Linklist::Display() {
	Node *temp;
	temp = Head->next;
	int e;
	cout << "该链表的遍历依次为：";
	while (temp) {
		e = temp->data;
		cout << e << " ";
		temp = temp->next;
	}
	cout << "\n";
}

void main() {   //测试小程序
	int user_num;
	cout << "请输入链表的长度:";
	cin >> user_num;
	Linklist list1;
	Linklist list2;
	list1.CreatList1(user_num);  //头插入法依次插入元素
	cout << "头插入法创造的链表\n";
	list1.Display();
	list1.Insert(2, 99);
	list1.Display();
	list1.GetData(2);
	list1.Search(11);
	list1.Search(99);
	list1.Delete(3);
	list1.Display();
	list1.ListLength();

	list2.CreatList2(4);
	list2.Display();

	system("pause");
}


