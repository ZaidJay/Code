#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#define MAX 1000
using namespace std;
int Book_Count=0,Disk_Count=0,Pic_Count=0;
class Lib
{
public:
	void Item_Add()
	{
		cout<<"编号:";
		cin>>Number;
		cout<<"标题:";
		cin>>Title;
		cout<<"作者:";
		cin>>Artist;
		cout<<"评级:";
		cin>>Level;
	}
	void Item_Display()
	{
		cout<<"编号:"<<Number<<"    标题:"<<Title<<"    作者:"<<Artist<<"    评级:"<<Level;
	}
	long Number;
	string Title;
	string Artist;
	string Level;
};
class Book:public Lib
{
public:
	void Book_Add()
	{
		Lib::Item_Add();
		cout<<"出版社:";
		cin>>Publish;
		cout<<"ISBN:";
		cin>>ISBN;
		cout<<"页数:";
		cin>>Page_Num; 
	}
	void Book_Display()
	{
		Lib::Item_Display();
		cout<<"    出版社:"<<Publish<<"    ISBN:"<<ISBN<<"    页数:"<<Page_Num<<endl; 
	}
	string Publish;
	string ISBN;
	int Page_Num;
};
class Disk:public Lib
{
public:
	void Disk_Add()
	{
		Lib::Item_Add();
		cout<<"出品者姓名:";
		cin>>Producer;
		cout<<"出品年份:";
		cin>>Date;
		cout<<"视频时长:";
		cin>>Time;
	}
	void Disk_Display()
	{
		Lib::Item_Display();
		cout<<"    出品者姓名:"<<Producer<<"    出品年份:"<<Date<<"    视频时长:"<<Time<<endl;
	}
	string Producer;
	string Date;
	string Time;
};
class Pic:public Lib
{
public:
	void Pic_Add()
	{
		Lib::Item_Add();
		cout<<"出品国籍:";
		cin>>Country; 
		cout<<"作品的长:";
		cin>>Length;
		cout<<"作品的宽:";
		cin>>Width; 
	}
	void Pic_Display()
	{
		Lib::Item_Display();
		cout<<"    出品国籍:"<<Country<<"    作品的长:"<<Length<<"cm"<<"    作品的宽:"<<Width<<"cm"<<endl;
	}
	string Country;
	int Length;
	int Width;
};
Book book[MAX];
Disk disk[MAX];
Pic pic[MAX];
void SHOW_MENU()
{
	cout<<"============================================================="<<endl;
    cout<<"         1.添加物品      2.查询物品      3.显示物品库          "<<endl;
    cout<<"         4.编辑物品      5.删除物品      6.统计信息            "<<endl;
    cout<<"         7.物品存盘      8.读取物品      9.安全退出            "<<endl;
	cout<<"============================================================="<<endl<<endl;
}
void Item_Add()
{
	cout<<"==================================================="<<endl;
    cout<<"                       添加物品                   "<<endl;
    cout<<"      1.添加图书    2.添加视频光盘    3.添加图画    "<<endl;
	cout<<"==================================================="<<endl<<endl;
	int n;
    fflush(stdin);
	cin>>n;
	switch(n)
	{
		case 1:book[Book_Count++].Book_Add();break;
		case 2:disk[Disk_Count++].Disk_Add();break;
		case 3:pic[Pic_Count++].Pic_Add();break;
		default:cout<<"错误数据!终止此次操作!"<<endl;break;
	}
	cout<<"===================="<<endl;
	cout<<"1.继续添加 2.返回菜单"<<endl;
	cout<<"===================="<<endl;
	int x;
	cin>>x;
	switch(x)
	{
		case 1:Item_Add();break;
		case 2:SHOW_MENU();break;
		default:
		{
			cout<<"错误数据!默认回到菜单!"<<endl<<endl;
			SHOW_MENU();
			break;
		}
	}
}
void Item_Search()
{
	int x,n,flag=0;
	long search_num;
	string search_title; 
	cout<<"==================================================="<<endl;
    cout<<"                       查询物品                     "<<endl;
    cout<<"     1.按标题查询    2.按编号查询    3.按类别查询     "<<endl;
	cout<<"==================================================="<<endl<<endl;
	cin>>n;
	switch(n)
	{
		case 1:
		{
			cout<<"输入标题:";
			cin>>search_title;
			for(int i=0;i<Book_Count;i++)
			if(search_title==book[i].Title) 
			{
				cout<<"查询结果如下:"<<endl;
				book[i].Book_Display();
				flag=1;
				break;
			}
			if(flag==0) for(int i=0;i<Disk_Count;i++)
			if(search_title==disk[i].Title)
			{
				cout<<"查询结果如下:"<<endl;
				disk[i].Disk_Display();
				flag=1;
				break;
			}
			if(flag==0) for(int i=0;i<Pic_Count;i++)
			if(search_title==pic[i].Title)
			{
				cout<<"查询结果如下:"<<endl;
				pic[i].Pic_Display();
				flag=1;
				break;
			}
			if(flag==0)
			{
				cout<<"===================="<<endl;
				cout<<"      不存在标题     "<<endl;
				cout<<"===================="<<endl<<endl;
			}
            break;
		}
		case 2:
		{
			cout<<"输入编号:";
			cin>>search_num;
			for(int i=0;i<Book_Count;i++)
			if(search_num==book[i].Number) 
			{
				cout<<"查询结果如下:"<<endl;
				book[i].Book_Display();
				flag=1;
				break;
			}
			if(flag==0) for(int i=0;i<Disk_Count;i++)
			if(search_num==disk[i].Number)
			{
				cout<<"查询结果如下:"<<endl;
				disk[i].Disk_Display();
				flag=1;
				break;
			}
			if(flag==0) for(int i=0;i<Pic_Count;i++)
			if(search_num==pic[i].Number)
			{
				cout<<"查询结果如下:"<<endl;
				pic[i].Pic_Display();
				flag=1;
				break;
			}
			if(flag==0)
			{
				cout<<"===================="<<endl;
				cout<<"      不存在编号     "<<endl;
				cout<<"===================="<<endl<<endl;
			}
            break;
		}
		case 3:
		{
			int x;
			cout<<"========================================"<<endl;
			cout<<"1.查询图书    2.查询视频光盘    3.查询图画"<<endl;
			cout<<"========================================"<<endl;
			cin>>x;
			switch(x)
			{
				case 1:
				{
					if(Book_Count==0)
					{
						cout<<"===================="<<endl;
						cout<<"    该类别没有物品   "<<endl;
						cout<<"===================="<<endl<<endl;
					}
					else 
					{
						cout<<"=================="<<endl;
						cout<<"以下是图书类别的信息"<<endl; 
						for(int i=0;i<Book_Count;i++) book[i].Book_Display();
						cout<<"=================="<<endl<<endl;
					}
					break;
				}
				case 2:
				{
					if(Disk_Count==0) 
					{
						cout<<"===================="<<endl;
						cout<<"    该类别没有物品   "<<endl;
						cout<<"===================="<<endl<<endl;
					}
					else
					{
						cout<<"======================"<<endl;
						cout<<"以下是视频光盘类别的信息"<<endl;
						for(int i=0;i<Disk_Count;i++) disk[i].Disk_Display();
						cout<<"======================"<<endl<<endl;
					}
					break;
				}
				case 3:
				{
					if(Pic_Count==0)
					{
						cout<<"===================="<<endl;
						cout<<"    该类别没有物品   "<<endl;
						cout<<"===================="<<endl<<endl;
					}
					else
					{
						cout<<"=================="<<endl;
						cout<<"以下是图画类别的信息"<<endl; 
						for(int i=0;i<Pic_Count;i++) pic[i].Pic_Display();
						cout<<"=================="<<endl<<endl;
					}
					break;
				}
				default:cout<<"错误数据!终止此次操作!"<<endl;break;
			} 
		}
		default:cout<<"错误数据!终止此次操作!"<<endl;break;
	}
	cout<<"===================="<<endl;
	cout<<"1.继续查找 2.返回菜单"<<endl;
	cout<<"===================="<<endl;
	cin>>x;
	switch(x)
	{
		case 1:Item_Search();break;
		case 2:SHOW_MENU();break;
		default:
		{
			cout<<"错误数据!默认回到菜单!"<<endl<<endl;
			SHOW_MENU();
			break;
		}
	}
}
void Item_Show()
{
	int x,n;
	cout<<"========================================================="<<endl;
    cout<<"                        显示物品库                        "<<endl;
    cout<<"      1.显示图书库    2.显示视频光盘库    3.显示图画库      "<<endl;
	cout<<"========================================================="<<endl<<endl;
	cin>>n;
	switch(n)
	{
		case 1:
		{
			if(Book_Count==0)
			{
				cout<<"===================="<<endl;
				cout<<"    图书库中没物品   "<<endl;
				cout<<"===================="<<endl<<endl;
				break;
			}
			else
			{
				cout<<"===================="<<endl;
				cout<<"图书库中的物品如下所示"<<endl;
				for(int i=0;i<Book_Count;i++) book[i].Book_Display();
				cout<<"===================="<<endl<<endl;
			}
            break;
		}
		case 2:
		{
			if(Disk_Count==0)
			{
				cout<<"===================="<<endl;
				cout<<"  视频光盘库中没物品  "<<endl;
				cout<<"===================="<<endl<<endl;
			}
			else
			{
				cout<<"========================"<<endl;
				cout<<"视频光盘库中的物品如下所示"<<endl;
				for(int i=0;i<Disk_Count;i++) disk[i].Disk_Display();
				cout<<"========================"<<endl<<endl;
			}
            break;
		}
		case 3:
		{
			if(Pic_Count==0)
			{
				cout<<"===================="<<endl;
				cout<<"    图画库中没物品   "<<endl;
				cout<<"===================="<<endl<<endl;
			}
			else
			{
				cout<<"===================="<<endl;
				cout<<"图画库中的物品如下所示"<<endl;
				for(int i=0;i<Pic_Count;i++) pic[i].Pic_Display();
				cout<<"===================="<<endl;
			}
            break;
		}
		default:cout<<"错误数据!终止此次操作!"<<endl;break;
	}
	cout<<"===================="<<endl;
	cout<<"1.继续显示 2.返回菜单"<<endl;
	cout<<"===================="<<endl;
	cin>>x;
	switch(x)
	{
		case 1:Item_Show();break;
		case 2:SHOW_MENU();break;
		default:
		{
			cout<<"错误数据!默认回到菜单!"<<endl<<endl;
			SHOW_MENU();
			break;
		}
	}
}
void Item_Edit()
{
	int x,n,flag=0;
	cout<<"==================================================="<<endl;
    cout<<"                       编辑物品                     "<<endl;
    cout<<"      1.编辑图书    2.编辑视频光盘    3.编辑图画      "<<endl;
	cout<<"==================================================="<<endl<<endl;
    cin>>n;
    switch(n)
    {
        case 1:
        {
            if(Book_Count==0) 
			{
				cout<<"===================="<<endl;
				cout<<"    图书库中没物品   "<<endl;
				cout<<"===================="<<endl<<endl;
				break;
			}
            long edit_num;
            cout<<"编辑图书,输入图书的编号:";
            cin>>edit_num;
            for(int i=0;i<Book_Count;i++)
            if(edit_num==book[i].Number)
            {
				flag=1;
                cout<<"===================="<<endl;
                cout<<"  找到图书,进行修改  "<<endl;
				cout<<"===================="<<endl<<endl;
                book[i].Book_Add();
                break;
            }
            if(flag==0)
			{
				cout<<"===================="<<endl;
				cout<<"      不存在编号     "<<endl;
				cout<<"===================="<<endl<<endl;
			}
            break;
        }
        case 2:
        {
            if(Disk_Count==0)
			{
				cout<<"===================="<<endl;
				cout<<"  视频光盘库中没物品  "<<endl;
				cout<<"===================="<<endl<<endl;
				break;
			}
            long edit_num;
            cout<<"编辑视频光盘,输入视频光盘的编号:";
            cin>>edit_num;
            for(int i=0;i<Disk_Count;i++)
            if(edit_num==disk[i].Number)
            {
				flag=1;
                cout<<"===================="<<endl;
                cout<<"找到视频光盘,进行修改"<<endl;
				cout<<"===================="<<endl<<endl;
                disk[i].Disk_Add();
                break;
            }
            if(flag==0)
			{
				cout<<"===================="<<endl;
				cout<<"      不存在编号     "<<endl;
				cout<<"===================="<<endl<<endl;
			}
            break;
        }
        case 3:
        {
            if(Pic_Count==0) 
			{
				cout<<"===================="<<endl;
				cout<<"    图画库中没物品   "<<endl;
				cout<<"===================="<<endl<<endl;
				break;
			}
            long edit_num;
            cout<<"编辑图画,输入图画的编号:";
            cin>>edit_num;
            for(int i=0;i<Pic_Count;i++)
            if(edit_num==pic[i].Number)
            {
				flag=1;
                cout<<"===================="<<endl;
                cout<<"  找到图画,进行修改  "<<endl;
				cout<<"===================="<<endl<<endl;
                pic[i].Pic_Add();
                break;
            }
            if(flag==0)
			{
				cout<<"===================="<<endl;
				cout<<"      不存在编号     "<<endl;
				cout<<"===================="<<endl<<endl;
			}
            break;
        }
		default:cout<<"错误数据!终止此次操作!"<<endl;break;
    }
	cout<<"===================="<<endl;
	cout<<"1.继续编辑 2.返回菜单"<<endl;
	cout<<"===================="<<endl;
	cin>>x;
	switch(x)
	{
		case 1:Item_Edit();break;
		case 2:SHOW_MENU();break;
		default:
		{
			cout<<"错误数据!默认回到菜单!"<<endl<<endl;
			SHOW_MENU();
			break;
		}
	}
}
void Item_Delete()
{
    int x,n,flag=0;
	cout<<"==================================================="<<endl;
    cout<<"                       删除物品                     "<<endl;
    cout<<"      1.删除图书    2.删除视频光盘    3.删除图画      "<<endl;
	cout<<"==================================================="<<endl<<endl;
    cin>>n;
    switch(n)
    {
        case 1:
        {
            if(Book_Count==0) 
			{
				cout<<"===================="<<endl;
				cout<<"    图书库中没物品   "<<endl;
				cout<<"===================="<<endl<<endl;
				break;
			}
            long delete_num;
            cout<<"输入要删除的图书的编号:";
            cin>>delete_num;
            for(int i=0;i<Book_Count;i++)
            if(delete_num==book[i].Number)
            {
				flag=1;
				cout<<"===================="<<endl;
                cout<<"找到图书,是否进行删除?"<<endl;
				cout<<"  是(Y)/否(随意字符) "<<endl;
				cout<<"===================="<<endl<<endl;
				char ans;
				cin>>ans;
				if(ans=='Y')
				{
                	for(int j=i;j<Book_Count;j++)
                	{
                   		book[j].Number=book[j+1].Number;
                    	book[j].Title=book[j+1].Title;
                    	book[j].Artist=book[j+1].Artist;
                    	book[j].Level=book[j+1].Level;
                    	book[j].Publish=book[j+1].Publish;
                    	book[j].ISBN=book[j+1].ISBN;
                    	book[j].Page_Num=book[j+1].Page_Num;
                	}
               		Book_Count--;
					cout<<"===================="<<endl;
					cout<<"      删除成功       "<<endl;
					cout<<"===================="<<endl<<endl;
                	break;
				}
				else
				{
					cout<<"===================="<<endl;
					cout<<"      取消删除       "<<endl;
					cout<<"===================="<<endl<<endl;
					break;
				}
            }
            if(flag==0)
			{
				cout<<"===================="<<endl;
				cout<<"      不存在编号     "<<endl;
				cout<<"===================="<<endl<<endl;
			}
            break;
        }
        case 2:
        {
            if(Disk_Count==0)
			{
				cout<<"===================="<<endl;
				cout<<"  视频光盘库中没物品  "<<endl;
				cout<<"===================="<<endl<<endl;
				break;
			}
            long delete_num;
            cout<<"输入要删除的视频光盘的编号:";
            cin>>delete_num;
            for(int i=0;i<Disk_Count;i++)
            if(delete_num==disk[i].Number)
            {
				flag=1;
				cout<<"========================"<<endl;
                cout<<"找到视频光盘,是否进行删除?"<<endl;
				cout<<"    是(Y)/否(随意字符)   "<<endl;
				cout<<"========================"<<endl<<endl;
				char ans;
				cin>>ans;
				if(ans=='Y')
				{
                	for(int j=i;j<Disk_Count;j++)
                	{
                    	disk[j].Number=disk[j+1].Number;
                    	disk[j].Title=disk[j+1].Title;
                    	disk[j].Artist=disk[j+1].Artist;
                    	disk[j].Level=disk[j+1].Level;
                    	disk[j].Producer=disk[j+1].Producer;
                    	disk[j].Date=disk[j+1].Date;
                    	disk[j].Time=disk[j+1].Time;
                	}
                	Disk_Count--;
					cout<<"===================="<<endl;
					cout<<"      删除成功       "<<endl;
					cout<<"===================="<<endl<<endl;
                	break;
				}
				else
				{
					cout<<"===================="<<endl;
					cout<<"      取消删除       "<<endl;
					cout<<"===================="<<endl<<endl;
					break;
				}
            }
            if(flag==0) 
			{
				cout<<"===================="<<endl;
				cout<<"      不存在编号     "<<endl;
				cout<<"===================="<<endl<<endl;
			}
            break;
        }
        case 3:
        {
            if(Pic_Count==0) 
			{
				cout<<"===================="<<endl;
				cout<<"    图画库中没物品   "<<endl;
				cout<<"===================="<<endl<<endl;
				break;
			}
            long delete_num;
            cout<<"输入要删除的图画的编号:";
            cin>>delete_num;
            for(int i=0;i<Pic_Count;i++)
            if(delete_num==pic[i].Number)
            {
				flag=1;
                cout<<"===================="<<endl;
                cout<<"找到图书,是否进行删除?"<<endl;
				cout<<"  是(Y)/否(随意字符) "<<endl;
				cout<<"===================="<<endl<<endl;
				char ans;
				cin>>ans;
				if(ans=='Y')
				{
                	for(int j=i;j<Pic_Count;j++)
                	{
                    	pic[j].Number=pic[j+1].Number;
                    	pic[j].Title=pic[j+1].Title;
                    	pic[j].Artist=pic[j+1].Artist;
                    	pic[j].Level=pic[j+1].Level;
                    	pic[j].Country=pic[j+1].Country;
                    	pic[j].Length=pic[j+1].Length;
                    	pic[j].Width=pic[j+1].Width;
                	}
                	Pic_Count--;
					cout<<"===================="<<endl;
					cout<<"      删除成功       "<<endl;
					cout<<"===================="<<endl<<endl;
                	break;
				}
				else
				{
					cout<<"===================="<<endl;
					cout<<"      取消删除       "<<endl;
					cout<<"===================="<<endl<<endl;
					break;
				}
            }
            if(flag==0)
			{
				cout<<"===================="<<endl;
				cout<<"      不存在编号     "<<endl;
				cout<<"===================="<<endl<<endl;
			}
            break;
        }
		default:cout<<"错误数据!终止此次操作!"<<endl;break;
    }
	cout<<"===================="<<endl;
	cout<<"1.继续删除 2.返回菜单"<<endl;
	cout<<"===================="<<endl;
	cin>>x;
	switch(x)
	{
		case 1:Item_Delete();break;
		case 2:SHOW_MENU();break;
		default:
		{
			cout<<"错误数据!默认回到菜单!"<<endl<<endl;
			SHOW_MENU();
			break;
		}
	}
}
void Item_Sum()
{
	cout<<"============================================================="<<endl;
    cout<<"物品库中总物品数为:"<<(Book_Count+Disk_Count+Pic_Count)<<endl;
    cout<<"图书数量为:"<<Book_Count<<"    视频光盘数量为:"<<Disk_Count<<"    图画数量为:"<<Pic_Count<<endl;
	cout<<"============================================================="<<endl<<endl;
}
void Item_Save()
{
	ofstream book_save,disk_save,pic_save;
	book_save.open("Book.txt");
	disk_save.open("Disk.txt");
	pic_save.open("Pic.txt");
	book_save<<"图书库:"<<endl;
	disk_save<<"视频光盘库:"<<endl;
	pic_save<<"图画库:"<<endl;
	for(int i=0;i<Book_Count-1;i++)
	book_save<<book[i].Number<<"\t"<<book[i].Title<<"\t"<<book[i].Artist<<"\t"<<book[i].Level<<"\t"<<book[i].Publish<<"\t"<<book[i].ISBN<<"\t"<<book[i].Page_Num<<endl;
	book_save<<book[Book_Count-1].Number<<"\t"<<book[Book_Count-1].Title<<"\t"<<book[Book_Count-1].Artist<<"\t"<<book[Book_Count-1].Level<<"\t"<<book[Book_Count-1].Publish<<"\t"<<book[Book_Count-1].ISBN<<"\t"<<book[Book_Count-1].Page_Num;
	for(int i=0;i<Disk_Count-1;i++)
	disk_save<<disk[i].Number<<"\t"<<disk[i].Title<<"\t"<<disk[i].Artist<<"\t"<<disk[i].Level<<"\t"<<disk[i].Producer<<"\t"<<disk[i].Date<<"\t"<<disk[i].Time<<endl;
	disk_save<<disk[Disk_Count-1].Number<<"\t"<<disk[Disk_Count-1].Title<<"\t"<<disk[Disk_Count-1].Artist<<"\t"<<disk[Disk_Count-1].Level<<"\t"<<disk[Disk_Count-1].Producer<<"\t"<<disk[Disk_Count-1].Date<<"\t"<<disk[Disk_Count-1].Time;
	for(int i=0;i<Pic_Count-1;i++)
	pic_save<<pic[i].Number<<"\t"<<pic[i].Title<<"\t"<<pic[i].Artist<<"\t"<<pic[i].Level<<"\t"<<pic[i].Country<<"\t"<<pic[i].Length<<"\t"<<pic[i].Width<<endl;
	pic_save<<pic[Pic_Count-1].Number<<"\t"<<pic[Pic_Count-1].Title<<"\t"<<pic[Pic_Count-1].Artist<<"\t"<<pic[Pic_Count-1].Level<<"\t"<<pic[Pic_Count-1].Country<<"\t"<<pic[Pic_Count-1].Length<<"\t"<<pic[Pic_Count-1].Width;
	book_save.close();
	disk_save.close();
	pic_save.close();
	cout<<"==================="<<endl;
	cout<<"      保存完毕      "<<endl;
	cout<<"==================="<<endl<<endl;
}
void Item_Read()
{
	ifstream book_read,disk_read,pic_read;
	book_read.open("Book.txt",ios::in);
	disk_read.open("Disk.txt",ios::in);
	pic_read.open("Pic.txt",ios::in);
	Book_Count=Disk_Count=Pic_Count=0;
	string str;
	while(getline(book_read,str))
	{
		book_read>>book[Book_Count].Number>>book[Book_Count].Title>>book[Book_Count].Artist>>book[Book_Count].Level>>book[Book_Count].Publish>>book[Book_Count].ISBN>>book[Book_Count].Page_Num;
		Book_Count++;
	}
	while(getline(disk_read,str))
	{
		disk_read>>disk[Disk_Count].Number>>disk[Disk_Count].Title>>disk[Disk_Count].Artist>>disk[Disk_Count].Level>>disk[Disk_Count].Producer>>disk[Disk_Count].Date>>disk[Disk_Count].Time;
		Disk_Count++;
	}
	while(getline(pic_read,str))
	{
		pic_read>>pic[Pic_Count].Number>>pic[Pic_Count].Title>>pic[Pic_Count].Artist>>pic[Pic_Count].Level>>pic[Pic_Count].Country>>pic[Pic_Count].Length>>pic[Pic_Count].Width;
		Pic_Count++;
	}
	book_read.close();
	disk_read.close();
	pic_read.close();
	cout<<"==================="<<endl;
	cout<<"      读取完毕      "<<endl;
	cout<<"==================="<<endl<<endl;
}
int main()
{
	cout<<"##################################"<<endl;
    cout<<"       欢迎来到媒体库管理系统      "<<endl;
	cout<<"     输入功能前对应序号进行操作    "<<endl;
	cout<<"##################################"<<endl<<endl;
	SHOW_MENU();
    while(1)
    {
        int n;
        cin>>n;
        switch(n)
        {
            case 1:Item_Add();break;
            case 2:Item_Search();break;
            case 3:Item_Show();break;
            case 4:Item_Edit();break;
            case 5:Item_Delete();break;
            case 6:Item_Sum();break;
			case 7:Item_Save();break;
			case 8:Item_Read();break;
			case 9:Item_Save();return 0;
			default:cout<<"错误数据!终止此次操作!"<<endl;break;
        }
    }
}
