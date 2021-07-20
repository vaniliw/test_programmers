#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
string username,password,tmp;
string l[3];
int score,wrong_count;
void clear(){
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif

} 
void qask() //qask Function
{
	string all_list[200];
	string ask_list[100];
	string answer_list[100];
	int i=0;
	fstream f("question.txt",ios::in);
		if (f.good()==0)
		{
			clear();
			cout<<"question.txt not found.";
		}
		while (getline(f,tmp))
		{
			if (tmp=="" || tmp=="\n")
				continue;
			all_list[i]=tmp;
			i=i+1;
		}
		int i3=0;
		int i4=0;

		for (int i2=0;i2<=i;i2++)
		{
			if ((i2+1)%2==0)
			{
				answer_list[i3]=all_list[i2];
				i3=i3+1;
			}
			else
			{
				ask_list[i4]=all_list[i2];
				i4=i4+1;
			}

		}
		//-----------
		i4=-1;
		for (int i2=0;i2<=i/2;i2++)
		{
			i4=i4+1;
		}

	while (1)
	{
		cout<<"You Have "<<i4 <<"Question. select 0 - "<<i4-1<<" : ";
		cin>>tmp;
		i3=stoi(tmp);
		if (i3>i4)
		{
			clear();
			continue;
		}
		else
		{
			cout<<ask_list[i3] <<":? ";
			cin>>tmp;
			if (answer_list[i3]==tmp)
			{
				clear();
				score=score+1;
				fstream f;
				f.open(username,ios::out);
				f<<password<<endl<<score<<endl<<wrong_count; //password , score , wrong count
				f.close();
				cout<<"level up!  "<<"Score: "<<score<<" Warn: "<<wrong_count<<endl;
				
			}
			else
			{
				clear();
				wrong_count=wrong_count+1;
				if (wrong_count>=3)
				{
					score=score-1;
					wrong_count=0;
				}
				fstream f;
				f.open(username,ios::out);
				f<<password<<endl<<score<<endl<<wrong_count; //password , score , wrong count
				f.close();
				cout<<"level down!  "<<"Score: "<<score<<" Warn: "<<wrong_count<<endl;
			}
		}


	}
}
int main()
{	
	while (1)
	{
		cout<<"Register=1  Login=2  Exit=3"<<"  :";
		cin>>tmp;
		cout<<endl;
		if (tmp=="3") //exit
		{
			clear();
			cout<<"see you lata"<<endl;
			break;
		}

		if (tmp=="2") //Login
		{
					clear();
					cout<<"userName:";
					cin>>username;
					cout<<endl<<"passWord:";
					cin>>password;
					cout<<endl;
					fstream f;
					f.open(username,ios::in);
					if (f.good()==1) //username exist
					{
						int i=0;
						while (getline(f,tmp))
						{
							l[i]=tmp;
							i-=-1;;
						}
						
						if (password==l[0]) //logined
						{
							score=stoi(l[1]);
							wrong_count=stoi(l[2]);
							clear();
							cout<<"Welcome : "<<username<<" & Score: "<<score<<" & Wrong Answer: "<<wrong_count<<endl;
							qask(); //qask Function->

						}
						else
						{
							clear();
							cout<<"password is not match! try another."<<endl;
						}
					}
					else
					{
						cout<<"username not found! try another"<<endl;	
					}
		}
		if (tmp=="1") //Register
		{
					clear();
					cout<<"userName:";
					cin>>username;
					cout<<endl<<"passWord:";
					cin>>password;
					cout<<endl;
					fstream f;
					
					f.open(username);
					
					if (f.good()==1)
					{
						cout<<"username already exist. please chose another"<<endl;
					}
					else
					{
						f.open(username,ios::out);
						f<<password<<endl<<"1"<<endl<<"0"; //password , score , wrong count
						f.close();
						cout<<"Registered! please login now"<<endl;
					}


			


		}

		else //continue
		{
			continue;
		}
	}
}