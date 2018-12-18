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
	void CreatList1(int n);        //ͷ���뷨��������
	void CreatList2(int n);        //β���뷨��������
	void Insert(int i, int e);     //���뺯��
	int Delete(int i);             //ɾ������Ԫ��
	int GetData(int i);            //ȡ�ñ���Ԫ��ֵ
	int Search(int obj);           //�ڱ���Ѱ��ƥ����
	int ListLength();              //��ñ�ĳ���
	void Display();                //������������
};

Linklist::Linklist() {                   //���캯��
	Head = new Node;
	Head->next = NULL;
}
void Linklist::CreatList1(int n) {      //ͷ���뷨��������
	Node *p;
	Node *temp;
	p = Head;
	cout << "����������" << n << "�������ֵ:";
	for (int i = 1; i <= n; i++) {
		temp = new Node;
		cin >> temp->data;
		temp->next = p->next;
		p->next = temp;
	}
}
void Linklist::CreatList2(int n) {      //β���뷨��������
	Node *p;
	Node *temp;
	p = Head;
	cout << "����������" << n << "�������ֵ:";
	for (int i = 0; i < n; i++) {
		temp = new Node;
		cin >> temp->data;
		p->next = temp;
		p = temp;
	}
}

void Linklist::Insert(int i, int e) {       //��i������e
	Node *temp;
	temp = Head;
	int j = 0;
	while ( temp && j < i - 1) {
		temp = temp->next;
		j++;
	}
	if (!temp || j > i - 1) {
		cout << "����λ�ô���";
	}
	else {
		Node *s;
		s = new Node;
		s->data = e;
		s->next = temp->next;
		temp->next = s;
	}
}
int Linklist::Delete(int i) {          //ɾ��i��������
	Node *temp;
	temp = Head;
	int j = 0;
	while (temp&&j < i - 1) {
		temp = temp->next;
		j++;
	}
	if (!temp || j > i - 1) {
		cout << "ɾ��λ�ô���";
		return -1;
	}
	else {
		Node *s;
		s = temp->next;
		temp->next = s->next;
		delete s;
	}
}
int Linklist::GetData(int i) {         //�õ�i����Ԫ��
	Node *temp;
	temp = Head;
	int j = 0;
	while (temp&&j < i - 1) {
		temp = temp->next;
		j++;
	}
	if (!temp || j > i - 1) {
		cout << "Ѱ��λ�ô���\n";
		return -1;
	}
	else {
		cout << i << "��������Ϊ��" << temp->next->data << "\n";
		return temp->data;
	}
}
int Linklist::Search(int obj) {       //Ѱ��������������objƥ���Ԫ��
	int j = 1;
	Node *temp;
	temp = Head->next;
	while (temp && temp->data != obj) {
		temp = temp->next;
		j++;
	}
	if (temp == NULL) {
		cout << "���������޴�Ԫ��" << "\n";
		return 0;
	}
	else {
		cout << "�ڸ������еĵ�" << j << "��Ԫ�ص���" << obj << "\n";
		return j;
	}
}
int Linklist::ListLength() {                //����������
	Node *temp;
	temp = Head;
	int j = 0;
	while (temp) {
		temp = temp->next;
		j++;
	}
	cout << "������ĳ���Ϊ��" << j - 1 << "\n";
	return j;
}
void Linklist::Display() {
	Node *temp;
	temp = Head->next;
	int e;
	cout << "������ı�������Ϊ��";
	while (temp) {
		e = temp->data;
		cout << e << " ";
		temp = temp->next;
	}
	cout << "\n";
}

void main() {   //����С����
	int user_num;
	cout << "����������ĳ���:";
	cin >> user_num;
	Linklist list1;
	Linklist list2;
	list1.CreatList1(user_num);  //ͷ���뷨���β���Ԫ��
	cout << "ͷ���뷨���������\n";
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


