#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <string.h>

struct book {
	int num;
	char name[10];
	char author[10];
	book *next;
};

struct lend {
    int id;
	char pname[10];
	char start[10];
	char end[10];
    int num;
    int is_return;
};

class Book {
public:
	Book();//构造读取文件
	void Sort();//排序
	void Save();//保存
	void DisPlay();//打印
	void Add();//添加
	void Del();//删除
	void Find();//查找
	void Lend();//借出
	void Return();//借出
private:
	int       n;
	book     *head;
    int     num_lends;
    lend    lends[100];
};
Book::Book()
{
    n=0;
	ifstream in;
	in.open("message.txt",ios::in);
	head=new book;
	head->next=NULL;
	book *p=new book;
	p->next=NULL;
	while (in>>p->num>>p->name>>p->author) {
	    p->next=head->next;
	    head->next=p;
	    n++;
	    p=new book;
	    p->next=NULL;
	}
    in.close();

	in.open("lends.txt",ios::in);
    num_lends = 0;
	while (in>>lends[num_lends].pname>>lends[num_lends].start>>lends[num_lends].end>>lends[num_lends].num) {
        lends[num_lends].is_return = 0;
        lends[num_lends].id = ++num_lends;
	}
    in.close();
}
void Book::Sort()
{
	cout<<endl<<endl<<"排序之后："<<endl;
	book *p=head;
	book *k,temp;
	for (p=head->next;p->next!=NULL;p=p->next) {
		k=p;
		for (book *q=p->next;q!=NULL;q=q->next) {
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
void Book::Find()
{
	char name[20];
	cout<<endl<<endl<<"要查找的书名："<<endl;
	cin>>name;
	book *p=head->next;
	while (p) {
		if (strcmp(p->name,name)==0) {
            cout<<"图书编号:  ";
	        cout<<p->num<<endl;
            cout<<"图书名称:  ";
            cout<<p->name<<endl;
		    cout<<"作者名称:  ";
		    cout<<p->author<<endl<<endl<<endl;
		}	
		p=p->next;
	}

	char author[20];
	cout<<endl<<endl<<"要查找的作者："<<endl;
	cin>>author;
	p=head->next;
	while (p) {
		if (strcmp(p->author,author)==0) {
            cout<<"图书编号:  ";
	        cout<<p->num<<endl;
            cout<<"图书名称:  ";
            cout<<p->name<<endl;
		    cout<<"作者名称:  ";
		    cout<<p->author<<endl<<endl<<endl;
		}	
		p=p->next;
	}
}
void Book::Save()
{
	book *p=head->next;
	FILE *fp = fopen("message.txt","w");
	while (p) {
		fprintf(fp, "%d %s %s\n", p->num, p->name, p->author);
		p=p->next;
	}
	fclose(fp);

    fp = fopen("lends.txt", "w");
	for (int i = 0;i < num_lends; i++) {
        if (lends[i].is_return == 1) 
            continue;
		fprintf(fp, "%s %s %s %d\n", lends[i].pname, lends[i].start, lends[i].end, lends[i].num);
	}
	fclose(fp);
}
void Book::DisPlay()
{
	book *p=head->next;
	while (p) {
		cout<<endl;
		cout<<"图书编号:  ";
		cout<<p->num<<"   ";
		cout<<"图书名称:  ";
		cout<<p->name<<"   ";
		cout<<"作者名称:  ";
		cout<<p->author<<"   ";
		p=p->next;
	}
    cout<<endl;

	for (int i = 0;i < num_lends; i++) {
        if (lends[i].is_return == 1) 
            continue;
		cout<<endl;
		cout<<"借书ID:  ";
		cout<<lends[i].id<<"   ";
		cout<<"借书人:  ";
		cout<<lends[i].pname<<"   ";
		cout<<"开始时间:  ";
		cout<<lends[i].start<<"   ";
		cout<<"结束时间:  ";
		cout<<lends[i].end<<"   ";
		cout<<"图书编号:  ";
		cout<<lends[i].num<<"   ";
	}
	cout<<endl<<endl;
}
void Book::Add()
{
	char yes='y';
	while (yes=='y') {
		n++;
		book *p=new book;
		p->next=NULL;
		cout<<"输入书的ID"<<endl;
		cin>>p->num;
		cout<<endl<<endl<<"输入书名："<<endl;
		cin>>p->name;
		cout<<"输入作者名称:  ";
		cin>>p->author;
		p->next=head->next;
		head->next=p;
		cout<<"继续插入？（y/n）";
		cin>>yes;
	}
}
void Book::Del()
{
	char name[10];
	cout<<endl<<endl<<"输入删除图书的名字：";
	cin>>name;
	book *p=head;
	while (p) {
		if (p->next && strcmp(p->next->name,name)==0) {
			p->next=p->next->next;
			break;
		}
		else
			p=p->next;
	}
}
void Book::Lend() 
{
	char yes='y';
	while (yes=='y') {
		cout<<"输入要借出书的ID"<<endl;
		cin>>lends[num_lends].num;
		cout<<"输入借书人名字"<<endl;
		cin>>lends[num_lends].pname;
		cout<<"输入借书开始时间"<<endl;
		cin>>lends[num_lends].start;
		cout<<"输入借书结束时间"<<endl;
		cin>>lends[num_lends].end;
        lends[num_lends].id = ++num_lends;
		cout<<"继续借出？（y/n）";
		cin>>yes;
	}
}
void Book::Return()
{
	int id_lend;
	cout<<endl<<endl<<"输入借出ID：";
	cin>>id_lend;
    for (int i = 0;i < num_lends; i++) {
        if (id_lend == lends[i].id && lends[i].is_return == 0) {
            lends[i].is_return = 1;
        }
    }
}
int main()
{
	Book b;
	b.DisPlay();
	b.Add();
	b.DisPlay();
	b.Sort();
	b.DisPlay();
	b.Find();
	b.DisPlay();
	b.Lend();
	b.DisPlay();
	b.Return();
	b.DisPlay();
	b.Del();
	b.DisPlay();
	b.Save();
	cin.get();
	return 0;
}
