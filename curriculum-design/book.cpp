#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <string.h>

struct book {
	int num;
	int sum;
	char strat[10];
	char end[10];
	char name[10];
	book *next;
};

template <class T>
class Book {
public:
	Book();//构造读取文件
	void Sort();//排序
	void Save();//保存
	void DisPlay();//打印
	void Add();//添加
	void Del();//删除
	T *Find();//查找
private:
	int       n;
	T     *head;
};
template <class T>
Book<T>::Book()
{
    n=0;
	ifstream in;
	in.open("message.txt",ios::in);
	head=new T;
	head->next=NULL;
	T *p=new T;
	p->next=NULL;
	while (in>>p->num>>p->name>>p->strat>>p->end>>p->sum) {
	    p->next=head->next;
	    head->next=p;
	    n++;
	    p=new T;
	    p->next=NULL;
	}
}
template <class T>
void Book<T>::Sort()
{
	cout<<endl<<endl<<"排序之后："<<endl;
	T *p=head;
	T *k,temp;
	for (p=head->next;p->next!=NULL;p=p->next) {
		k=p;
		for (T *q=p->next;q!=NULL;q=q->next) {
			if(strcmp(q->name,k->name)<0)
				k=q;
		}
		if (p!=k) {
			book *x,*y;
			x=p->next;
			y=k->next;
			temp=*p;
			temp.next=y;
			*p=*k;
			p->next=x;
			*k=temp;
		}
	}
}
template <class T>
T * Book<T>::Find()
{
	char name[20];
	cout<<endl<<endl<<"要查找的书名："<<endl;
	cin>>name;
	T *p=head->next;
	while (p) {
		if (strcmp(p->name,name)==0) {
			return p;
		}	
		else
			p=p->next;
	}
}
template <class T>
void Book<T>::Save()
{
	T *p=head->next;
	ofstream out;
	out.open("message.txt",ios::out);
	while (p) {
		out<<p->num<<setw(2)<<p->name<<setw(2)<<p->strat<<setw(2)<<p->end<<setw(2)<<p->sum<<endl;
		p=p->next;
	}
	out.close();
}
template <class T>
void Book<T>::DisPlay()
{
	T *p=head->next;
	while (p) {
		cout<<endl;
		cout<<"图书名称:  ";
		cout<<p->name<<"   ";
		cout<<"图书数量:  ";
		cout<<p->sum<<"   ";
		cout<<"图书编号:  ";
		cout<<p->num<<"   ";
		cout<<"借出时间:  ";
		cout<<p->strat<<"   ";
		cout<<"归还时间:  ";
		cout<<p->end<<"   ";
		p=p->next;
	}
    cout<<endl;
}
template <class T>
void Book<T>::Add()
{
	char yes='y';
	while (yes=='y') {
		n++;
		T *p=new T;
		p->next=NULL;
		cout<<endl<<endl<<"输入书名："<<endl;
		cin>>p->name;
		cout<<"输入数量："<<endl;
		cin>>p->sum;
		cout<<"输入书的ID"<<endl;
		cin>>p->num;
		cout<<"输入借出时间："<<endl;
		cin>>p->strat;
		cout<<"输入归还时间："<<endl;
		cin>>p->end;
		p->next=head->next;
		head->next=p;
		cout<<"继续插入？（y/n）";
		cin>>yes;
	}
}
template <class T>
void Book<T>::Del()
{
	char name[10];
	cout<<endl<<endl<<"输入删除图书的名字：";
	cin>>name;
	T *p=head;
	while (p) {
		if (p->next && strcmp(p->next->name,name)==0) {
			p->next=p->next->next;
			break;
		}
		else
			p=p->next;
	}
}
int main()
{
	Book<book> b;
	b.DisPlay();
	b.Add();
	b.DisPlay();
	b.Sort();
	b.DisPlay();
	book *p1=b.Find();
    if (NULL != p1) {
        cout<<"图书名称:  ";
        cout<<p1->name<<endl;
	    cout<<"图书数量:  ";
        cout<<p1->sum<<endl;
        cout<<"图书编号:  ";
	    cout<<p1->num<<endl;
	    cout<<"借出时间:  ";
	    cout<<p1->strat<<endl;
	    cout<<"归还时间:  ";
	    cout<<p1->end<<endl;
    }
	b.Del();
	b.DisPlay();
	b.Save();
	cin.get();
	return 0;
}
