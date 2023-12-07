#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
void f1();
void f2();
void f3();
void f4();
void f5();
void reput1();
void reput2();
void reput3();
int quchong(string t);

class Member
{
protected:
	string id;//编号
	string name;
	int age; 

public:
	Member(string a,string b,int c):
	   id(a),name(b),age(c){} //参数初始化表构造函数
	//~Member
	string get_id()
	{
		return id;
	}
	string get_name()
	{
		return name;
	} 
	int  get_age()
	{
		return age;
	}
};

class Colt:virtual public Member
{
protected:
	string dept;//所属队伍
	string coach;//教练姓名
public:
	Colt(string a,string b,int c,string d,string e):
	   Member(a,b,c),dept(d),coach(e){} //构造函数
	void set_Colt()
	{
		cout<<endl<<"请输入队员编号："; cin>>id;
		cout<<endl<<"请输入队员姓名："; cin>>name;
		cout<<endl<<"请输入队员年龄："; cin>>age;
		cout<<endl<<"请输入该队员所属队伍：";cin>>dept;
		cout<<endl<<"请输入教练姓名："; cin>>coach; 
	}
    void show()
    {
    	cout<<"该队员的编号是："<<id<<endl;
		cout<<"该队员的姓名是："<<name<<endl;
		cout<<"该队员的年龄是："<<age<<endl;
		cout<<"该队员所属队伍是："<<dept<<endl;
		cout<<"该队员的教练姓名是："<<coach<<endl;
    }
	void change_status()
	{
		coach="该队伍的教练已离职，等待新教练上任";
	}
	void change_status1(string s)
	{
		coach=s;
	}
    string get_dept()
	{
		return dept;
	}
	string get_coach()
	{
		return coach;
	}
};

class Coach:virtual public Member
{
protected:
	string charge;//管理的队伍
public:
	Coach(string a,string b,int c,string d):
	   Member(a,b,c),charge(d){}
	void set_Coach()
	{
		cout<<endl<<"请输入教练编号："; cin>>id;
		cout<<endl<<"请输入教练姓名："; cin>>name;
		cout<<endl<<"请输入教练年龄："; cin>>age;
		cout<<"请输入教练管理的队伍："; cin>>charge;
	}
	void show()
	{
		cout<<"该教练的编号是："<<id<<endl;
		cout<<"该教练的姓名是："<<name<<endl;
		cout<<"该教练的年龄是："<<age<<endl;
		cout<<"该教练管理的队伍是："<<charge<<endl;
	}

	string get_charge()
	{
		return charge;
	}
};

class Captain:public Colt,public Coach
{
public:
   //Captain();
   Captain(string a,string b,int c,string d,string e,string g):
       Member(a,b,c),Colt(a,b,c,d,e),Coach(a,b,c,g){}//构造函数

   void set_Captain()
   {
	   cout<<"请输入队长的编号："; cin>>id;
	   cout<<"请输入队长的姓名："; cin>>name;
	   cout<<"请输入队长的年龄："; cin>>age;
	   cout<<"请输入队长的所属队伍："; cin>>dept;
	   cout<<"请输入队长的教练姓名："; cin>>coach;
	   cout<<"请输入队长管理的队伍："; cin>>charge;
   }
   void show()
   {
	   cout<<"该队长的编号是："<<id<<endl;
	   cout<<"该队长的姓名是："<<name<<endl;
	   cout<<"该队长的年龄是："<<age<<endl;
	   cout<<"该队长的所属队伍是："<<dept<<endl;
	   cout<<"该队长的教练姓名是："<<coach<<endl;
	   cout<<"该队长管理的队伍是："<<charge<<endl;
   }
};

vector<Colt>v1;
vector<Coach>v2;
vector<Captain>v3;

void print()
{
	while(1)
	{
		int n;string m;
		cout<<"*************************"<<endl;
		cout<<"*  1---添加成员         *"<<endl;
		cout<<"*  2---删除成员         *"<<endl;
        cout<<"*  3---修改成员         *"<<endl;
		cout<<"*  4---查询成员         *"<<endl;
		cout<<"*  5---展示所有队伍成员 *"<<endl;
		cout<<"*  0---退出系统         *"<<endl;
		cout<<"*************************"<<endl;
		cout<<"请输入选项对应的数字"<<endl;
		cin>>m;
		
		while(m!="0" && m!="1" && m!="2"&& m!="3" && m!="4" && m!="5")
		{
			cout<<"输入违法,请重新输入操作："<<endl;
			cin>>m;
		}
		n=m[0]-'0';
		
		switch(n)
		{
			case 1:
			{
				system("cls");
				f1();
				break;
			}
			case 2:
			{
				system("cls");
				f2();
				break;
			}
			case 3:
			{
				system("cls");
				f3();
				break;
			}
			case 4:
			{
				system("cls");
				f4();
				break;
			}
			case 5:
			{
				system("cls");
				f5();
				break;
			}
			case 0:
			   return;
			default:
			{
				cout<<"输入错误!!!"<<endl;
				break;
			}
		}
	}
}

void f1()
{
	int n;string m;
	cout<<"**********************"<<endl;
	cout<<"*  1---添加队员信息  *"<<endl;
	cout<<"*  2---添加教练信息  *"<<endl;
	cout<<"*  3---添加队长信息  *"<<endl;
	cout<<"*  0---退出          *"<<endl;
	cout<<"**********************"<<endl;
	while(1)
	{
		cout<<"请输入选项对应的数字"<<endl;
		cin>>m;
        
        while(m!="1" && m!="2" && m!="3" && m!="0")
		{
			cout<<"输入违法，请重新输入操作："<<endl;
			cin>>m;
		}

		n=m[0]-'0';
		switch(n)
	    {
		   case 1:
		   {
			  Colt b1("","",0,"","");
			  
			  //打印出已经存在的队伍及其教练，供用户选择
			  cout<<"当前存在的队伍及其教练如下"<<endl;
			  for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
			     cout<<it->get_charge()<<"     "<<it->get_name()<<endl;

			  cout<<"该新队员只能选择其中的一个队伍"<<endl;
			  
			  b1.set_Colt();//输入新队员信息
			  
			  //检查是否存在该队伍和教练 
			  int flag=0;
			  for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
			    if(it->get_charge()==b1.get_dept()&&it->get_name()==b1.get_coach())
			    {
			    	flag=1;
			    	break;
			    }
			  if(flag==0) {cout<<"不存在该教练或队伍！！！"<<endl<<"*********************"<<endl;break;}//提示用户出错了

			  //检查是否已经存在该人员 
			  else if(quchong(b1.get_id())==1)
			  {
				  cout<<"已存在该人员！！！"<<endl<<"*********************"<<endl;
				  break;
			  }
			  
			  //把该队员信息存入v1，同时更新文件
			  v1.push_back(b1);
			  reput1();
			  cout<<"添加成功"<<endl<<"*********************"<<endl;
			  break;
		   }
		   case 2:
		   {
			  Coach m1("","",0,"");

			  cout<<"当前存在的队伍及其教练如下"<<endl;
			  cout<<"*********************"<<endl;
			  for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
			     cout<<it->get_charge()<<"     "<<it->get_name()<<endl;
			  cout<<"*********************"<<endl;
			  cout<<"该教练及其管理队伍不得与以上相同"<<endl;

			  m1.set_Coach();//输入教练信息

              //检查是否存在该队伍和教练 
			  int flag=0;
			  for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
			    if(it->get_charge()==m1.get_charge())
			    {
			    	flag=1;
			    	break;
			    }
			  if(flag==1) {cout<<"已存在该教练或队伍！！！"<<endl<<"*********************"<<endl;break;}//提示用户出错了 

			  //检查是否已经存在该人员
              else if(quchong(m1.get_id())==1)
			  {
				  cout<<"已存在该人员！！！"<<endl<<"*********************"<<endl;
				  break;
			  }

			  v2.push_back(m1);
			  reput2();
			  for(vector<Colt>::iterator it=v1.begin();it!=v1.end();it++)
			  {
				  if(m1.get_charge()==it->get_dept())
				     it->change_status1(m1.get_name());
			  }
			  for(vector<Captain>::iterator it=v3.begin();it!=v3.end();it++)
			  {
				  if(m1.get_charge()==it->get_dept())
				     it->change_status1(m1.get_name());
			  }
			  reput1();reput3();
			  cout<<"添加成功"<<endl<<"*********************"<<endl;
			  break;
		   }
		   case 3:
		   {
			  Captain k("","",0,"","","");
			  cout<<"当前存在的队伍及其教练如下"<<endl;
			  cout<<"***************************"<<endl;
			  for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
			     cout<<it->get_charge()<<"     "<<it->get_name()<<endl;
			  cout<<"***************************"<<endl;
			  cout<<"该新队长只能选择其中的一个队伍"<<endl;

			  k.set_Captain();//输入队长信息

              //检查是否存在该队伍和教练 
			  int flag=0;
			  for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
			    if(it->get_charge()==k.get_dept()&&it->get_name()==k.get_coach())
			    {
			    	flag=1;
			    	break;
			    }
			  if(flag==0) {cout<<"不存在该教练或队伍！！！"<<endl<<"*********************"<<endl;break;}//提示用户出错了

			  //检查是否已经存在该人员 
			  else if(quchong(k.get_id())==1)
			  {
				  cout<<"已存在该人员！！！"<<endl<<"*********************"<<endl;
				  break;
			  }

			  v3.push_back(k);
			  reput3();
			  cout<<"添加成功"<<endl<<"*********************"<<endl;
			  break;
		   }
		   case 0: 
		   {
		   	  system("cls");
		   	  return;
		   }	
		   default: break;
	    }
	}
	
} 

void f2()
{
	int n;string m;
	cout<<"**********************"<<endl;
	cout<<"*  1---删除队员信息  *"<<endl;
	cout<<"*  2---删除教练信息  *"<<endl;
	cout<<"*  3---删除队长信息  *"<<endl;
	cout<<"*  0---退出          *"<<endl;
	cout<<"**********************"<<endl;
	while(1)
	{
    	cout<<"请输入选项对应的数字"<<endl;
		cin>>m;
		while(m!="0"&&m!="1"&&m!="2"&&m!="3")
		{
			cout<<"输入违法，请重新输入操作："<<endl;
			cin>>m;
		}

		n=m[0]-'0';

		switch(n)
		{
			case 1:
			{
				cout<<"请输入该队员编号：";
				string xh;cin>>xh;//编号 
				for(vector<Colt>::iterator it=v1.begin();it!=v1.end();it++)
				{
	                 if(it->get_id()==xh)
					 {
						 v1.erase(it,it+1);//删除该队员
						 cout<<"删除成功"<<endl;
						 reput1();//重新导入文件
						 break;
					 }
					if(it+1==v1.end()) cout<<"删除失败！！不存在该队员！！！"<<endl; 
				}
				break;
			}
			case 2://删除教练的时候需要对他的队员和队长的信息进行重置
			{
				cout<<"请输入该教练的编号：";
				string xh;cin>>xh;
				for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
				{
					if(it->get_id()==xh)
					{
						//寻找该教练对应的队员，改变队员对应信息
						for(vector<Colt>::iterator p=v1.begin();p!=v1.end();p++)
						{
							if(p->get_coach()==it->get_name())
							   p->change_status();
						}
						reput1();
                        
						//寻找该教练对应的队长，改变其信息
						for(vector<Captain>::iterator p=v3.begin();p!=v3.end();p++)
						{
							if(p->get_coach()==it->get_name())
							   p->change_status();
						}
						reput3();

                        
                        v2.erase(it);//删除该教练信息
						cout<<"删除成功"<<endl;
						reput2();

						break;
					}
					if(it+1==v2.end()) cout<<"删除失败！！不存在该教练！！！"<<endl;
				}
				break;
			}
			case 3:
			{
				string xh;
				cout<<"请输入该队长的编号：";
				cin>>xh;
				for(vector<Captain>::iterator it=v3.begin();it!=v3.end();it++)
				{
					if(it->get_id()==xh)
					{
						v3.erase(it,it+1);
	                    cout<<"删除成功"<<endl;
						reput3();
						break;
					}
					if(it+1==v3.end()) cout<<"删除失败！！不存在该队长！！！"<<endl;
				}
				break;
			}
			case 0:
			{
				system("cls"); 
	            return;
			}
			default:
			{
				cout<<"没有该操作！！！"<<endl;
			} 
		}
	}
}

void f3()//修改数据
{
	int n;string s;
	cout<<"***********************************"<<endl;
	cout<<"*  温馨提示，只有以下两种晋升方式 *"<<endl;
	cout<<"*  1---修改队员职务为队长       *"<<endl;
	cout<<"*  2---修改队长职务为教练       *"<<endl;
	cout<<"*  0---退出                       *"<<endl;
	cout<<"***********************************"<<endl;
	while(1)
	{
		cout<<"请输入操作选项"<<endl;
		cin>>s;
        while(s!="0"&&s!="1"&&s!="2")
		{
			cout<<"输入违法，请重新输入操作："<<endl;
			cin>>s;
		}

		n=s[0]-'0';
		switch(n)
		{
			case 1:
			{
				string xh;int flag=0;
				cout<<"请输入该队员的编号：";
				cin>>xh;
				for(vector<Colt>::iterator it=v1.begin();it!=v1.end();it++)
				{
	                 if(it->get_id()==xh)
					 {
	                    Captain m(it->get_id(),it->get_name(),it->get_age(),it->get_dept(),it->get_coach(),it->get_dept());
	                    v3.push_back(m);
						v1.erase(it,it+1);//删除该队员
					    cout<<"晋升成功"<<endl;
					    flag=1;
						reput1();reput3();
						break;
					 } 
				}
				if(flag==0)
				   cout<<"未找到该编号对应的队员，请检查您输入的编号"<<endl;
				break;
			}
			case 2:
			{
				string xh;int flag=0;
				cout<<"请输入该队长的编号：";
				cin>>xh;
				
				for(vector<Captain>::iterator it=v3.begin();it!=v3.end();it++)
				{
					if(it->get_id()==xh)//存在该编号对应的队长
					{
						flag=1;//存在该队长

                        //检查该队伍是否存在教练
						int k=0;
                        for(vector<Coach>::iterator p=v2.begin();p!=v2.end();p++)
				        {
							if(p->get_charge()==it->get_charge())//该队伍有教练，不能晋升
							{
								cout<<"该队伍有教练，该队长不能晋升！！"<<endl;
								k=1;
								break;
							}
				        }
						if(k==1) break;
                        
						Coach m(it->get_id(),it->get_name(),it->get_age(),it->get_dept());
						v2.push_back(m);//存入教练名单
						
						for(vector<Colt>::iterator p=v1.begin();p!=v1.end();p++)
						{
							if(p->get_dept()==it->get_dept())
							   p->change_status1(it->get_name());//所有这个队伍的队员的教练姓名都改为这个新晋升的教练姓名
						}

						for(vector<Captain>::iterator p=v3.begin();p!=v3.end();p++)
						{
							if(p->get_dept()==it->get_dept())
							   p->change_status1(it->get_name());//所有这个队伍的队长的教练姓名都改为这个新晋升的教练姓名
						}
						cout<<"晋升成功"<<endl;
						v3.erase(it,it+1);//从队长名单里删除

						reput1();reput2();reput3();
						break;
					}
				}
				if(flag==0)
				   cout<<"未找到该编号对应的队长，请检查您输入的编号"<<endl;
				break;
			}
			case 0:
			{
				system("cls");
				return;
			}
			default:
			{
				cout<<"没有该操作!!!"<<endl;
				break;
			}
		}
	}
}

void f4()
{
	cout<<"******************"<<endl;
	cout<<"*  1---查询      *"<<endl;
	cout<<"*  0---退出查询  *"<<endl;
	cout<<"******************"<<endl;
	cout<<endl<<endl; 
	while(1)
	{
		int n;string m;
		cout<<"请输入操作对应的数字：";
		cin>>m;
		while(m!="1"&&m!="0")
		{
			cout<<"输入违法，请重新输入操作：";
			cin>>m;
		}
		
		n=m[0]-'0';//字符转整形
		switch(n)
		{
		case 1:
		{
			string xh;int flag=0;
			cout<<"***********************"<<endl;
	        cout<<"请输入您要查询的人员的编号：";
	        cin>>xh;
	        for(vector<Colt>::iterator it=v1.begin();it!=v1.end();it++)
	        {
		       if(it->get_id()==xh)
		       {
		       	  cout<<"查询成功，以下为该人员的信息"<<endl;
			      it->show();//找到该名人员，输出人员信息
			      flag=1;
			       break;
		       }
	        }
	        for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
	        {
		        if(it->get_id()==xh)
		        {
		        	cout<<"查询成功，以下为该人员的信息"<<endl;
			       it->show();//找到该名人员，输出人员信息
			       flag=1;
			       break;
		        }
	        }
	        for(vector<Captain>::iterator it=v3.begin();it!=v3.end();it++)
	        {
	           if(it->get_id()==xh)
	           {
	           	  cout<<"查询成功，以下为该人员的信息"<<endl;
			      it->show();//找到该名人员，输出人员信息
			      flag=1;
			      break;
	           }
	        }
	        if(flag==0)
	           cout<<"查无此人！！！"<<endl;
			cout<<"***********************"<<endl<<endl<<endl;
	        break;
		}
		case 0:
		{
			system("cls");
			return;
		}
		default:
		{
			cout<<"没有该操作"<<endl;
			break;
		}
	    }
	}
}

void f5()
{
	cout<<"*********************************************"<<endl;
	string a[100];int i=0;
	for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
	{
		a[i]=it->get_charge();i++;
		cout<<"队伍名称："<<it->get_charge()<<"  "<<"教练姓名："<<it->get_name()<<endl;
		cout<<"该队伍成员如下"<<endl;
		for(vector<Colt>::iterator p=v1.begin();p!=v1.end();p++)
		{
			if(p->get_coach()==it->get_name())
               cout<<"编号："<<p->get_id()<<"  "<<"姓名："<<p->get_name()<<"  职位：队员"<<endl;
		}
		for(vector<Captain>::iterator p=v3.begin();p!=v3.end();p++)
		{
			if(p->get_coach()==it->get_name())
               cout<<"编号："<<p->get_id()<<"  "<<"姓名："<<p->get_name()<<"  职位：队长"<<endl;
		}
		cout<<"*********************************************"<<endl;
	}
	for(vector<Captain>::iterator it=v3.begin();it!=v3.end();it++)
	{
		int flag=0;
		for(int j=0;j<i;j++)
		{
			if(it->get_charge()==a[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			a[i]=it->get_charge();i++;
			cout<<"队伍名称："<<it->get_charge()<<"   "<<"教练名称：该队伍教练已离职"<<endl;
		    cout<<"该队伍成员如下"<<endl;
			for(vector<Captain>::iterator p=v3.begin();p!=v3.end();p++)
		    {
			   if(p->get_charge()==it->get_charge())
                  cout<<"编号："<<p->get_id()<<"  "<<"姓名："<<p->get_name()<<"  职位：队长"<<endl;
		    }
			for(vector<Colt>::iterator p=v1.begin();p!=v1.end();p++)
		    {
			   if(p->get_dept()==it->get_charge())
                  cout<<"编号："<<p->get_id()<<"  "<<"姓名："<<p->get_name()<<"  职位：队员"<<endl;
		    }
			cout<<"*********************************************"<<endl;
		}
	}
	for(vector<Colt>::iterator it=v1.begin();it!=v1.end();it++)
	{
		int flag=0;
		for(int j=0;j<i;j++)
		{
			if(it->get_dept()==a[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			a[i]=it->get_dept();i++;
			cout<<"队伍名称："<<it->get_dept()<<"   "<<"教练名称：该队伍教练已离职"<<endl;
			cout<<"该队伍成员如下"<<endl;
			for(vector<Colt>::iterator p=v1.begin();p!=v1.end();p++)
		    {
			   if(p->get_dept()==it->get_dept())
                  cout<<"编号："<<p->get_id()<<"  "<<"姓名："<<p->get_name()<<"  职位：队员"<<endl;
		    }
			cout<<"*********************************************"<<endl;
		}
	}
	system("pause");
	system("cls");
	return;
}

int quchong(string t)
{
	for(vector<Colt>::iterator it=v1.begin();it!=v1.end();it++)
	{
		if(it->get_id()==t) return 1;
	}
	for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
	{
		if(it->get_id()==t) return 1;
	}
	for(vector<Captain>::iterator it=v3.begin();it!=v3.end();it++)
	{
		if(it->get_id()==t) return 1;
	}

	return 0;
}

void all_putin()//从文件读入三个文件，分别存入三个vector里
{
	string a,b,d,e,g;int c; 
	ifstream in;
	in.open("Colt.txt",ios::in);
	if(in.fail())
	{
		cout<<"打开文件失败"<<endl;
		exit(1);
	}
	while(in>>a>>b>>c>>d>>e)
	{
		Colt b1(a,b,c,d,e);
		v1.push_back(b1);
	}
    in.close();

	in.open("Coach.txt",ios::in);
    if(in.fail())
	{
		cout<<"打开文件失败"<<endl;
		exit(1);
	}
	while(in>>a>>b>>c>>d)
	{
		Coach b1(a,b,c,d);
		v2.push_back(b1);
	}
    in.close();
    
    in.open("Captain.txt",ios::in);
    if(in.fail())
	{
		cout<<"打开文件失败"<<endl;
		exit(1);
	}
	while(in>>a>>b>>c>>d>>e>>g)
	{
		Captain b1(a,b,c,d,e,g);
		v3.push_back(b1);
	}
    in.close();
}

void reput1()
{
	ofstream out("Colt.txt");
	for(vector<Colt>::iterator it=v1.begin();it!=v1.end();it++)
	   out<<it->get_id()<<" "<<it->get_name()<<" "<<it->get_age()<<" "<<it->get_dept()<<" "<<it->get_coach()<<" "<<endl;
	     
	out.close();
}

void reput2()
{
	ofstream out("Coach.txt");
	for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
	   out<<it->get_id()<<" "<<it->get_name()<<" "<<it->get_age()<<" "<<it->get_charge()<<" "<<endl;
	out.close();
}

void reput3()
{
	ofstream out("Captain.txt");
	for(vector<Captain>::iterator it=v3.begin();it!=v3.end();it++)
	   out<<it->get_id()<<" "<<it->get_name()<<" "<<it->get_age()<<" "<<it->get_dept()<<" "<<it->get_coach()<<" "<<it->get_charge()<<" "<<endl;
	     
	out.close();
}

int main()
{
	all_putin();
	print();
	return 0;
}
