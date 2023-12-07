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
	string id;//���
	string name;
	int age; 

public:
	Member(string a,string b,int c):
	   id(a),name(b),age(c){} //������ʼ�����캯��
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
	string dept;//��������
	string coach;//��������
public:
	Colt(string a,string b,int c,string d,string e):
	   Member(a,b,c),dept(d),coach(e){} //���캯��
	void set_Colt()
	{
		cout<<endl<<"�������Ա��ţ�"; cin>>id;
		cout<<endl<<"�������Ա������"; cin>>name;
		cout<<endl<<"�������Ա���䣺"; cin>>age;
		cout<<endl<<"������ö�Ա�������飺";cin>>dept;
		cout<<endl<<"���������������"; cin>>coach; 
	}
    void show()
    {
    	cout<<"�ö�Ա�ı���ǣ�"<<id<<endl;
		cout<<"�ö�Ա�������ǣ�"<<name<<endl;
		cout<<"�ö�Ա�������ǣ�"<<age<<endl;
		cout<<"�ö�Ա���������ǣ�"<<dept<<endl;
		cout<<"�ö�Ա�Ľ��������ǣ�"<<coach<<endl;
    }
	void change_status()
	{
		coach="�ö���Ľ�������ְ���ȴ��½�������";
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
	string charge;//����Ķ���
public:
	Coach(string a,string b,int c,string d):
	   Member(a,b,c),charge(d){}
	void set_Coach()
	{
		cout<<endl<<"�����������ţ�"; cin>>id;
		cout<<endl<<"���������������"; cin>>name;
		cout<<endl<<"������������䣺"; cin>>age;
		cout<<"�������������Ķ��飺"; cin>>charge;
	}
	void show()
	{
		cout<<"�ý����ı���ǣ�"<<id<<endl;
		cout<<"�ý����������ǣ�"<<name<<endl;
		cout<<"�ý����������ǣ�"<<age<<endl;
		cout<<"�ý�������Ķ����ǣ�"<<charge<<endl;
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
       Member(a,b,c),Colt(a,b,c,d,e),Coach(a,b,c,g){}//���캯��

   void set_Captain()
   {
	   cout<<"������ӳ��ı�ţ�"; cin>>id;
	   cout<<"������ӳ���������"; cin>>name;
	   cout<<"������ӳ������䣺"; cin>>age;
	   cout<<"������ӳ����������飺"; cin>>dept;
	   cout<<"������ӳ��Ľ���������"; cin>>coach;
	   cout<<"������ӳ�����Ķ��飺"; cin>>charge;
   }
   void show()
   {
	   cout<<"�öӳ��ı���ǣ�"<<id<<endl;
	   cout<<"�öӳ��������ǣ�"<<name<<endl;
	   cout<<"�öӳ��������ǣ�"<<age<<endl;
	   cout<<"�öӳ������������ǣ�"<<dept<<endl;
	   cout<<"�öӳ��Ľ��������ǣ�"<<coach<<endl;
	   cout<<"�öӳ�����Ķ����ǣ�"<<charge<<endl;
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
		cout<<"*  1---��ӳ�Ա         *"<<endl;
		cout<<"*  2---ɾ����Ա         *"<<endl;
        cout<<"*  3---�޸ĳ�Ա         *"<<endl;
		cout<<"*  4---��ѯ��Ա         *"<<endl;
		cout<<"*  5---չʾ���ж����Ա *"<<endl;
		cout<<"*  0---�˳�ϵͳ         *"<<endl;
		cout<<"*************************"<<endl;
		cout<<"������ѡ���Ӧ������"<<endl;
		cin>>m;
		
		while(m!="0" && m!="1" && m!="2"&& m!="3" && m!="4" && m!="5")
		{
			cout<<"����Υ��,���������������"<<endl;
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
				cout<<"�������!!!"<<endl;
				break;
			}
		}
	}
}

void f1()
{
	int n;string m;
	cout<<"**********************"<<endl;
	cout<<"*  1---��Ӷ�Ա��Ϣ  *"<<endl;
	cout<<"*  2---��ӽ�����Ϣ  *"<<endl;
	cout<<"*  3---��Ӷӳ���Ϣ  *"<<endl;
	cout<<"*  0---�˳�          *"<<endl;
	cout<<"**********************"<<endl;
	while(1)
	{
		cout<<"������ѡ���Ӧ������"<<endl;
		cin>>m;
        
        while(m!="1" && m!="2" && m!="3" && m!="0")
		{
			cout<<"����Υ�������������������"<<endl;
			cin>>m;
		}

		n=m[0]-'0';
		switch(n)
	    {
		   case 1:
		   {
			  Colt b1("","",0,"","");
			  
			  //��ӡ���Ѿ����ڵĶ��鼰����������û�ѡ��
			  cout<<"��ǰ���ڵĶ��鼰���������"<<endl;
			  for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
			     cout<<it->get_charge()<<"     "<<it->get_name()<<endl;

			  cout<<"���¶�Աֻ��ѡ�����е�һ������"<<endl;
			  
			  b1.set_Colt();//�����¶�Ա��Ϣ
			  
			  //����Ƿ���ڸö���ͽ��� 
			  int flag=0;
			  for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
			    if(it->get_charge()==b1.get_dept()&&it->get_name()==b1.get_coach())
			    {
			    	flag=1;
			    	break;
			    }
			  if(flag==0) {cout<<"�����ڸý�������飡����"<<endl<<"*********************"<<endl;break;}//��ʾ�û�������

			  //����Ƿ��Ѿ����ڸ���Ա 
			  else if(quchong(b1.get_id())==1)
			  {
				  cout<<"�Ѵ��ڸ���Ա������"<<endl<<"*********************"<<endl;
				  break;
			  }
			  
			  //�Ѹö�Ա��Ϣ����v1��ͬʱ�����ļ�
			  v1.push_back(b1);
			  reput1();
			  cout<<"��ӳɹ�"<<endl<<"*********************"<<endl;
			  break;
		   }
		   case 2:
		   {
			  Coach m1("","",0,"");

			  cout<<"��ǰ���ڵĶ��鼰���������"<<endl;
			  cout<<"*********************"<<endl;
			  for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
			     cout<<it->get_charge()<<"     "<<it->get_name()<<endl;
			  cout<<"*********************"<<endl;
			  cout<<"�ý������������鲻����������ͬ"<<endl;

			  m1.set_Coach();//���������Ϣ

              //����Ƿ���ڸö���ͽ��� 
			  int flag=0;
			  for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
			    if(it->get_charge()==m1.get_charge())
			    {
			    	flag=1;
			    	break;
			    }
			  if(flag==1) {cout<<"�Ѵ��ڸý�������飡����"<<endl<<"*********************"<<endl;break;}//��ʾ�û������� 

			  //����Ƿ��Ѿ����ڸ���Ա
              else if(quchong(m1.get_id())==1)
			  {
				  cout<<"�Ѵ��ڸ���Ա������"<<endl<<"*********************"<<endl;
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
			  cout<<"��ӳɹ�"<<endl<<"*********************"<<endl;
			  break;
		   }
		   case 3:
		   {
			  Captain k("","",0,"","","");
			  cout<<"��ǰ���ڵĶ��鼰���������"<<endl;
			  cout<<"***************************"<<endl;
			  for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
			     cout<<it->get_charge()<<"     "<<it->get_name()<<endl;
			  cout<<"***************************"<<endl;
			  cout<<"���¶ӳ�ֻ��ѡ�����е�һ������"<<endl;

			  k.set_Captain();//����ӳ���Ϣ

              //����Ƿ���ڸö���ͽ��� 
			  int flag=0;
			  for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
			    if(it->get_charge()==k.get_dept()&&it->get_name()==k.get_coach())
			    {
			    	flag=1;
			    	break;
			    }
			  if(flag==0) {cout<<"�����ڸý�������飡����"<<endl<<"*********************"<<endl;break;}//��ʾ�û�������

			  //����Ƿ��Ѿ����ڸ���Ա 
			  else if(quchong(k.get_id())==1)
			  {
				  cout<<"�Ѵ��ڸ���Ա������"<<endl<<"*********************"<<endl;
				  break;
			  }

			  v3.push_back(k);
			  reput3();
			  cout<<"��ӳɹ�"<<endl<<"*********************"<<endl;
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
	cout<<"*  1---ɾ����Ա��Ϣ  *"<<endl;
	cout<<"*  2---ɾ��������Ϣ  *"<<endl;
	cout<<"*  3---ɾ���ӳ���Ϣ  *"<<endl;
	cout<<"*  0---�˳�          *"<<endl;
	cout<<"**********************"<<endl;
	while(1)
	{
    	cout<<"������ѡ���Ӧ������"<<endl;
		cin>>m;
		while(m!="0"&&m!="1"&&m!="2"&&m!="3")
		{
			cout<<"����Υ�������������������"<<endl;
			cin>>m;
		}

		n=m[0]-'0';

		switch(n)
		{
			case 1:
			{
				cout<<"������ö�Ա��ţ�";
				string xh;cin>>xh;//��� 
				for(vector<Colt>::iterator it=v1.begin();it!=v1.end();it++)
				{
	                 if(it->get_id()==xh)
					 {
						 v1.erase(it,it+1);//ɾ���ö�Ա
						 cout<<"ɾ���ɹ�"<<endl;
						 reput1();//���µ����ļ�
						 break;
					 }
					if(it+1==v1.end()) cout<<"ɾ��ʧ�ܣ��������ڸö�Ա������"<<endl; 
				}
				break;
			}
			case 2://ɾ��������ʱ����Ҫ�����Ķ�Ա�Ͷӳ�����Ϣ��������
			{
				cout<<"������ý����ı�ţ�";
				string xh;cin>>xh;
				for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
				{
					if(it->get_id()==xh)
					{
						//Ѱ�Ҹý�����Ӧ�Ķ�Ա���ı��Ա��Ӧ��Ϣ
						for(vector<Colt>::iterator p=v1.begin();p!=v1.end();p++)
						{
							if(p->get_coach()==it->get_name())
							   p->change_status();
						}
						reput1();
                        
						//Ѱ�Ҹý�����Ӧ�Ķӳ����ı�����Ϣ
						for(vector<Captain>::iterator p=v3.begin();p!=v3.end();p++)
						{
							if(p->get_coach()==it->get_name())
							   p->change_status();
						}
						reput3();

                        
                        v2.erase(it);//ɾ���ý�����Ϣ
						cout<<"ɾ���ɹ�"<<endl;
						reput2();

						break;
					}
					if(it+1==v2.end()) cout<<"ɾ��ʧ�ܣ��������ڸý���������"<<endl;
				}
				break;
			}
			case 3:
			{
				string xh;
				cout<<"������öӳ��ı�ţ�";
				cin>>xh;
				for(vector<Captain>::iterator it=v3.begin();it!=v3.end();it++)
				{
					if(it->get_id()==xh)
					{
						v3.erase(it,it+1);
	                    cout<<"ɾ���ɹ�"<<endl;
						reput3();
						break;
					}
					if(it+1==v3.end()) cout<<"ɾ��ʧ�ܣ��������ڸöӳ�������"<<endl;
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
				cout<<"û�иò���������"<<endl;
			} 
		}
	}
}

void f3()//�޸�����
{
	int n;string s;
	cout<<"***********************************"<<endl;
	cout<<"*  ��ܰ��ʾ��ֻ���������ֽ�����ʽ *"<<endl;
	cout<<"*  1---�޸Ķ�Աְ��Ϊ�ӳ�       *"<<endl;
	cout<<"*  2---�޸Ķӳ�ְ��Ϊ����       *"<<endl;
	cout<<"*  0---�˳�                       *"<<endl;
	cout<<"***********************************"<<endl;
	while(1)
	{
		cout<<"���������ѡ��"<<endl;
		cin>>s;
        while(s!="0"&&s!="1"&&s!="2")
		{
			cout<<"����Υ�������������������"<<endl;
			cin>>s;
		}

		n=s[0]-'0';
		switch(n)
		{
			case 1:
			{
				string xh;int flag=0;
				cout<<"������ö�Ա�ı�ţ�";
				cin>>xh;
				for(vector<Colt>::iterator it=v1.begin();it!=v1.end();it++)
				{
	                 if(it->get_id()==xh)
					 {
	                    Captain m(it->get_id(),it->get_name(),it->get_age(),it->get_dept(),it->get_coach(),it->get_dept());
	                    v3.push_back(m);
						v1.erase(it,it+1);//ɾ���ö�Ա
					    cout<<"�����ɹ�"<<endl;
					    flag=1;
						reput1();reput3();
						break;
					 } 
				}
				if(flag==0)
				   cout<<"δ�ҵ��ñ�Ŷ�Ӧ�Ķ�Ա������������ı��"<<endl;
				break;
			}
			case 2:
			{
				string xh;int flag=0;
				cout<<"������öӳ��ı�ţ�";
				cin>>xh;
				
				for(vector<Captain>::iterator it=v3.begin();it!=v3.end();it++)
				{
					if(it->get_id()==xh)//���ڸñ�Ŷ�Ӧ�Ķӳ�
					{
						flag=1;//���ڸöӳ�

                        //���ö����Ƿ���ڽ���
						int k=0;
                        for(vector<Coach>::iterator p=v2.begin();p!=v2.end();p++)
				        {
							if(p->get_charge()==it->get_charge())//�ö����н��������ܽ���
							{
								cout<<"�ö����н������öӳ����ܽ�������"<<endl;
								k=1;
								break;
							}
				        }
						if(k==1) break;
                        
						Coach m(it->get_id(),it->get_name(),it->get_age(),it->get_dept());
						v2.push_back(m);//�����������
						
						for(vector<Colt>::iterator p=v1.begin();p!=v1.end();p++)
						{
							if(p->get_dept()==it->get_dept())
							   p->change_status1(it->get_name());//�����������Ķ�Ա�Ľ�����������Ϊ����½����Ľ�������
						}

						for(vector<Captain>::iterator p=v3.begin();p!=v3.end();p++)
						{
							if(p->get_dept()==it->get_dept())
							   p->change_status1(it->get_name());//�����������Ķӳ��Ľ�����������Ϊ����½����Ľ�������
						}
						cout<<"�����ɹ�"<<endl;
						v3.erase(it,it+1);//�Ӷӳ�������ɾ��

						reput1();reput2();reput3();
						break;
					}
				}
				if(flag==0)
				   cout<<"δ�ҵ��ñ�Ŷ�Ӧ�Ķӳ�������������ı��"<<endl;
				break;
			}
			case 0:
			{
				system("cls");
				return;
			}
			default:
			{
				cout<<"û�иò���!!!"<<endl;
				break;
			}
		}
	}
}

void f4()
{
	cout<<"******************"<<endl;
	cout<<"*  1---��ѯ      *"<<endl;
	cout<<"*  0---�˳���ѯ  *"<<endl;
	cout<<"******************"<<endl;
	cout<<endl<<endl; 
	while(1)
	{
		int n;string m;
		cout<<"�����������Ӧ�����֣�";
		cin>>m;
		while(m!="1"&&m!="0")
		{
			cout<<"����Υ�������������������";
			cin>>m;
		}
		
		n=m[0]-'0';//�ַ�ת����
		switch(n)
		{
		case 1:
		{
			string xh;int flag=0;
			cout<<"***********************"<<endl;
	        cout<<"��������Ҫ��ѯ����Ա�ı�ţ�";
	        cin>>xh;
	        for(vector<Colt>::iterator it=v1.begin();it!=v1.end();it++)
	        {
		       if(it->get_id()==xh)
		       {
		       	  cout<<"��ѯ�ɹ�������Ϊ����Ա����Ϣ"<<endl;
			      it->show();//�ҵ�������Ա�������Ա��Ϣ
			      flag=1;
			       break;
		       }
	        }
	        for(vector<Coach>::iterator it=v2.begin();it!=v2.end();it++)
	        {
		        if(it->get_id()==xh)
		        {
		        	cout<<"��ѯ�ɹ�������Ϊ����Ա����Ϣ"<<endl;
			       it->show();//�ҵ�������Ա�������Ա��Ϣ
			       flag=1;
			       break;
		        }
	        }
	        for(vector<Captain>::iterator it=v3.begin();it!=v3.end();it++)
	        {
	           if(it->get_id()==xh)
	           {
	           	  cout<<"��ѯ�ɹ�������Ϊ����Ա����Ϣ"<<endl;
			      it->show();//�ҵ�������Ա�������Ա��Ϣ
			      flag=1;
			      break;
	           }
	        }
	        if(flag==0)
	           cout<<"���޴��ˣ�����"<<endl;
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
			cout<<"û�иò���"<<endl;
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
		cout<<"�������ƣ�"<<it->get_charge()<<"  "<<"����������"<<it->get_name()<<endl;
		cout<<"�ö����Ա����"<<endl;
		for(vector<Colt>::iterator p=v1.begin();p!=v1.end();p++)
		{
			if(p->get_coach()==it->get_name())
               cout<<"��ţ�"<<p->get_id()<<"  "<<"������"<<p->get_name()<<"  ְλ����Ա"<<endl;
		}
		for(vector<Captain>::iterator p=v3.begin();p!=v3.end();p++)
		{
			if(p->get_coach()==it->get_name())
               cout<<"��ţ�"<<p->get_id()<<"  "<<"������"<<p->get_name()<<"  ְλ���ӳ�"<<endl;
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
			cout<<"�������ƣ�"<<it->get_charge()<<"   "<<"�������ƣ��ö����������ְ"<<endl;
		    cout<<"�ö����Ա����"<<endl;
			for(vector<Captain>::iterator p=v3.begin();p!=v3.end();p++)
		    {
			   if(p->get_charge()==it->get_charge())
                  cout<<"��ţ�"<<p->get_id()<<"  "<<"������"<<p->get_name()<<"  ְλ���ӳ�"<<endl;
		    }
			for(vector<Colt>::iterator p=v1.begin();p!=v1.end();p++)
		    {
			   if(p->get_dept()==it->get_charge())
                  cout<<"��ţ�"<<p->get_id()<<"  "<<"������"<<p->get_name()<<"  ְλ����Ա"<<endl;
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
			cout<<"�������ƣ�"<<it->get_dept()<<"   "<<"�������ƣ��ö����������ְ"<<endl;
			cout<<"�ö����Ա����"<<endl;
			for(vector<Colt>::iterator p=v1.begin();p!=v1.end();p++)
		    {
			   if(p->get_dept()==it->get_dept())
                  cout<<"��ţ�"<<p->get_id()<<"  "<<"������"<<p->get_name()<<"  ְλ����Ա"<<endl;
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

void all_putin()//���ļ����������ļ����ֱ��������vector��
{
	string a,b,d,e,g;int c; 
	ifstream in;
	in.open("Colt.txt",ios::in);
	if(in.fail())
	{
		cout<<"���ļ�ʧ��"<<endl;
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
		cout<<"���ļ�ʧ��"<<endl;
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
		cout<<"���ļ�ʧ��"<<endl;
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
