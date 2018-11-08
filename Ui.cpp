#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<cstdlib>
#include<sstream>
#include<ctime>
#include<conio.h>
int choice=0;
#include"search_buses.h"
#include"Mainpage.h"
using namespace std;



		class Transport{
        protected:
            int c,flag,pos,op;
            string s,line,token;
		    public:
		    virtual int login()=0;
		    int check(string un){
					ifstream i;
					int ulen=un.length();
					 c=0;
					 flag=0;
					i.open("formdetails.csv",ios::in);
					while(getline(i,s)){
						int len=s.length();
						c=0;
						token="\0";
						for(int i=0;i<len;i++)
						{
							if(s[i]==',')
							{
								c++;
							}
							if(c==2&&s[i]!=',')
							{
									token+=s[i];
							}
							if(c==3)
                                break;
						}
						if(un.compare(token)==0)
                        {
                            flag=1;
                        }

					}
					if(flag==0)
                    {
                        cout<<"\t\tusername created";
                        return 1;
                    }
                    else
                    {
                        cout<<"\t\tusername already exits in the database";
                        return 2;
                    }
		    }
		    int check(int bid)
{
    flag=0;
    ifstream f;
    f.open("Transport.csv");
    while(getline(f,s))
    {
        line=s;
        pos=line.find(',');
        token=line.substr(0,pos);
        c=atoi(token.c_str());
        if(c==bid)
        {
            flag=1;
        }
    }
    if(flag==0)
                    {
                        cout<<"\t\tBus id created";
                        return 1;
                    }
                    else
                    {
                        cout<<"\t\tBus number already exits in the database";
                        return 2;
                    }

}
		    void delbook()
{
	char day0[20];
	string day;
	ifstream f("booking.csv");
	time_t now=time(0);
	struct tm * ltm=localtime(&now);
	strftime (day0,20,"%d-%m-%Y",ltm);
	ofstream temp("temp0.csv");

	while(getline(f,s)){

pos=s.find(',');
int pos1=s.find('-');
	day=s.substr(pos+1,pos1-4);
	int date=atoi(day.c_str());

	if(date>=ltm->tm_mday){
		temp<<s<<endl;
	}

	}
	temp.close();
	f.close();
	remove("booking.csv");
    rename("temp0.csv","booking.csv");


}
		};

 int faq()
		    {
                int op;
                string s;
		        ifstream f;
		        f.open("faq.txt");
		        while(getline(f,s))
                {
                    cout<<s<<endl;
                }
                f.close();
                cout<<"\n\nPress 1 to return to main menu:";
                 cin>>op;
                 if(op==1)
                  return 0;

		    }


		class Admin:public Transport{
        private:
            int flag,op,bn,pos,c;
            string un,pass,s,city,time,token,line,token1;


        public:
            int login()
            {
                    flag=0;
                    cout<<"\n\t\tEnter ADMIN username:";
                    cin>>un;
                    cout<<"\t\tEnter password:";
                    cin>>pass;
                    if(un.compare("admin")==0&&pass.compare("password")==0)
                        {
                            flag=1;
                        }

            if(flag==1)
            {
                cout<<"login successful";
                return 1;
            }
             else
            {
                cout<<"login unsuccessful"<<endl<<endl;
                return 2;
            }

		}
void new_entry()
         {

            op=0;
            ofstream f;
            f.open("Transport.csv",ios::app);
            for(int i=0;i<2;i++)
            {
                if(i==0)
                    cout<<"**************ENTER UP ROUTE*****************\n";
                else
                     cout<<"**************ENTER DOWN ROUTE*****************\n";
            do
            {
            cout<<"\nEnter new bus no:";
            cin>>bn;
            }while(check(bn)!=1);
            stringstream out;
                out<<bn;
                token1=out.str();
            s=token1;
            cout<<"\nEnter START city name:";
                cin>>city;
                cin.ignore();
                cout<<"Enter time for the city:";
                cin>>time;
                cin.ignore();
                s=s+","+city+","+time;
                cout<<"Do you want to add halts   1. YES    2. NO:";
                cin>>op;
                while(op==1)
                {
                cout<<"Enter HALT city name:";
                cin>>city;
                cin.ignore();
                cout<<"Enter time for the city:";
                cin>>time;
                cin.ignore();
                s=s+","+city+","+time;
                cout<<"Do you want to add more halts   1. YES    2. NO:";
                cin>>op;
                }
                cout<<"Enter END city name:";
                cin>>city;
                cin.ignore();
                cout<<"Enter time for the city:";
                cin>>time;
                cin.ignore();
                s=s+","+city+","+time+"\n";
                f<<s;
            }
                f.close();
}
 int view_routes()
 {
     system("cls");
     mainpage::display();
     sb::searchb();
    return 0;
 }
 int delete_entry()
 {
      c=0;
      op=0;
	cout<<"\t\tEnter the bus no. which you want to delete:";
	cin>>line;
	ifstream f;
	f.open("Transport.csv");
	ofstream temp;
	temp.open("temp.csv");
	while(getline(f,s))
    {
        pos=s.find(',');
        token=s.substr(0,pos);
        if(token!=line)
        {
            temp<<s<<endl;
        }
        if(token==line)
        {
            c++;
        }
    }
    if(c==0)
        cout<<"\n\t\tNO SUCH BUS EXISTS";
    else
        cout<<"\n\t\tBUS SUCCESSFULLY REMOVED";
    temp.close();
    f.close();
    remove("Transport.csv");
    rename("temp.csv","Transport.csv");
    cout<<endl<<endl<<endl;
    cout<<"\n\nPress 1 to return to main menu:";
     cin>>op;
     if(op==1)
        return 0;

 }
 void modify_route(string bno)
{
	ofstream temp("temp.csv");
	ifstream f("Transport.csv");
	while(getline(f,line)){
            token=line;
		int pos=token.find(',');
		string busno=token.substr(0,pos);
		if(busno==bno)
		{
			cout<<"Enter START city name:";
                cin>>city;
                cin.ignore();
                cout<<"Enter time for the city:";
                cin>>time;
                cin.ignore();
                s=bno+","+city+","+time;
                cout<<"Do you want to add halts   1. YES    2. NO:";
                cin>>op;
                while(op==1)
                {
                cout<<"Enter HALT city name:";
                cin>>city;
                cin.ignore();
                cout<<"Enter time for the city:";
                cin>>time;
                cin.ignore();
                s=s+","+city+","+time;
                cout<<"Do you want to add more halts   1. YES    2. NO:";
                cin>>op;
                }
                cout<<"Enter END city name:";
                cin>>city;
                cin.ignore();
                cout<<"Enter time for the city:";
                cin>>time;
                cin.ignore();
                s=s+","+city+","+time+"\n";
                temp<<s<<endl;

		}
		else
		temp<<line<<endl;

	}
	temp.close();
		f.close();
		remove("Transport.csv");
		rename("temp.csv","Transport.csv");

}
 int user1()
 {
      pos=0;
     ifstream f;
     f.open("formdetails.csv");
     while(getline(f,s))
     {
            pos=s.find(',');
            token=s.substr(0,pos);
            cout<<"\t\t\t"<<token;
            s.erase(0,pos+1);
            pos=s.find(',');
            token=s.substr(0,pos);
            cout<<"\t\t\t\t"<<token;
            s.erase(0,pos+1);
            pos=s.find(',');
            token=s.substr(0,pos);
            cout<<"\t\t\t\t"<<token<<endl;
     }
       cout<<endl<<endl<<endl;
    cout<<"\n\nPress 1 to return to main menu:";
     cin>>op;
     if(op==1)
        return 0;

 }
 int user1(string un,int ch)
 {
      c=0;
      op=0;
	ifstream f;
	if(ch==2)
    {
	f.open("formdetails.csv");
	ofstream temp;
	temp.open("temp.csv");
	while(getline(f,s))
    {
        line=s;
        for(int i=0;i<2;i++)
        {
            pos=line.find(',');
            line.erase(0,pos+1);
        }
        pos=line.find(',');
        token=line.substr(0,pos);
        if(token!=un)
        {
            temp<<s<<endl;
        }
        if(token==un)
        {
            c++;
        }
        line="\0";
    }
    if(c==0)
        cout<<"\n\t\tNO SUCH USER EXISTS";
    else
        cout<<"\n\t\tUSER SUCCESSFULLY REMOVED";
    temp.close();
    f.close();
    remove("formdetails.csv");
    rename("temp.csv","formdetails.csv");
    cout<<endl<<endl<<endl;
    cout<<"\n\nPress 1 to return to main menu:";
     cin>>op;
     if(op==1)
        return 0;
 }
 else if(ch==1)
 {
     c=0;
     f.open("formdetails.csv");
	while(getline(f,s))
    {
        line=s;
        for(int i=0;i<2;i++)
        {
            pos=line.find(',');
            line.erase(0,pos+1);
        }
        pos=line.find(',');
        token=line.substr(0,pos);
        if(token==un)
        {
            line=s;
            cout<<"\t\t\tNAME\t\tPHONE NUMBER\t\tUSERNAME\n\n";
            pos=line.find(',');
            token1=line.substr(0,pos);
            cout<<"\t\t\t"<<token1;
            line.erase(0,pos+1);
            pos=line.find(',');
            token1=line.substr(0,pos);
            cout<<"\t\t"<<token1;
            line.erase(0,pos+1);
            pos=line.find(',');
            token1=line.substr(0,pos);
            cout<<"\t\t"<<token1;
            c+=1;

        }

        line="\0";
    }
    if(c<1)
        cout<<"NO SUCH USER EXISTS";
     cout<<"\n\nPress 1 to return to main menu:";
     cin>>op;
     if(op==1)
        return 0;
 }
 else
 {
    cout<<"Invalid choice:";
    cout<<"\n\nPress 1 to return to main menu:";
     cin>>op;
     if(op==1)
        return 0;

 }
 }
 int view_tickets()
 {
     delbook();
     pos=0;
     ifstream f;
     f.open("booking.csv");
     while(getline(f,s))
     {
            pos=s.find(',');
            token1=s.substr(0,pos);
            cout<<"\t\t\t"<<token1;
            s.erase(0,pos+1);
            pos=s.find(',');
            token1=s.substr(0,pos);
            cout<<"\t\t\t\t"<<token1;
            s.erase(0,pos+1);
            pos=s.find('\n');
            token1=s.substr(0,pos);
            cout<<"\t\t\t\t"<<token1<<endl;
     }
       cout<<endl<<endl<<endl;
    cout<<"\n\nPress 1 to return to main menu:";
     cin>>op;
     if(op==1)
        return 0;
 }

 };
class User:public Transport{
private:
int ulen,c,len,pos,number,k,op,countx,flag,c1;
string s,v,pn,un,ps,pass,ns,np,token,line,token1;
			public:
			char status(){
				char th;
                cout<<"\n\n\n\t\t\t*************************USER PANEL******************************"<<endl;
				cout<<"\n\n\t\t1. New User\n\t\t2. Existing User \n\t\t0. Return To Main Menu\n \n\t\tEnter Your Choice :";
				cin>> th;
				try
		{
		    if(th>='a'&&th<='z')
            {

        throw th;
            }
		}
		catch(...)
		{
		    cout<<"invalid input";
		}
				return th;

				}

			void userinput()
			{
			    ofstream  *o= new ofstream();
			    cout<<"\n\n\n\t\t\t***********************ENTER DETAILS OF NEW USER******************************"<<endl;
			    o->open("formdetails.csv",ios::app);
			    cin.ignore();
				cout<<"\n\t\tEnter Your Name :";
				getline(cin,s);
				cout<<"\n\t\tEnter 10 Digit Phone Number:";
				getline(cin,pn);
				do{
				cout<<"\n\t\tEnter UserName :";
				getline(cin,un);
                }
                while(check(un)!=1);
				cout<<"\n\t\tEnter Password :";
				getline(cin,ps);
				v=s+','+pn+','+un+','+ps+"\n";
				*o<<v;
                o->close();
                delete o;


				}
				 int login()
            {
                    cout<<"\n\t\tEnter USER username:";
                    cin>>un;
                    cout<<"\n\t\tEnter password:";
                    cin>>pass;
                    ifstream i;
					int ulen=un.length();
					string s,ns,np;
					int c=0,flag=0,c1=0;
					i.open("formdetails.csv",ios::in);
					while(getline(i,s)){
						int len=s.length();
						c=0;
						c1=0;
						ns="\0";
						np="\0";
						for(int i=0;i<len;i++)
						{
							if(s[i]==',')
							{
								c++;
							}
							if(c==2&&s[i]!=',')
							{
									ns+=s[i];
							}
							if(c==3)
                                break;
						}

						for(int i=0;i<len;i++)
						{
							if(s[i]==',')
							{
								c1++;
							}
							if(c1==3&&s[i]!=',')
							{
									np+=s[i];
							}
						}
						if(ns.compare(un)==0&&np.compare(pass)==0)
                        {
                            flag=1;
                        }
            }
            if(flag==1)
            {
                cout<<"\t\t\tLogin successful";
                return 1;
            }
             else if(flag==0)
            {
                cout<<"\t\t\tLogin unsuccessful";
                return 2;
            }

		}
		int book_tkt(string fs)
{

     c=0;
     op=0;
     countx=0;
    string s,token,line,token1;
	ifstream f;
	f.open("booking.csv");
	ofstream temp;
	temp.open("temp.csv");
	 cout<<"\n\t\tEnter no. of tickets to be booked:";
        cin>>number;
	while(getline(f,s))
    {


        pos=s.find(fs);
        if(pos==-1)
        {
        temp<<s<<endl;
        }
        else if(pos>=0)
        {
            line=s;
            pos=line.find(',');
            line.erase(0,pos+1);
            pos=line.find(',');
            line.erase(0,pos+1);
            c=atoi(line.c_str());
            int k=c+number;
            if(k>50)
            {
                cout<<"\n\n\t\t\tSEAT FULL";
                temp<<s<<endl;
                countx++;
            }

            else if(k<=50)
            {
                countx++;
                c=c+number;
                stringstream out;
                out<<c;
                token1=out.str();
                fs=fs+','+token1;
            temp<<fs<<endl;
            }

        }

    }
    if(countx==0)
    {
        c=c+number;
                stringstream out;
                out<<c;
                token1=out.str();
                fs=fs+','+token1;
                temp<<fs<<endl;
    }
    temp.close();
    f.close();
    remove("booking.csv");
    rename("temp.csv","booking.csv");
    cout<<endl<<endl<<endl;
    cout<<"\n\nPress 1 to return to main menu:";
     cin>>op;
     if(op==1)
        return 0;
}

int bdate(string bn)
{
    string fs;
    delbook();
	time_t now=time(0);
  struct tm * ltm=localtime(&now);
  char day1[20],day2[20],day3[20],day4[20],day5[20],day0[20];
    strftime (day0,20,"%d-%m-%Y",ltm);
    cout<<"\n\n                                    TODAY'S DATE IS:"<<day0<<endl<<endl;
    ltm->tm_mday=ltm->tm_mday+1;
    strftime (day1,20,"%d-%m-%Y",ltm);
	cout<<"\n\t\t1.";
    cout<<"day1";
     ltm->tm_mday=ltm->tm_mday+1;
    strftime (day2,20,"%d-%m-%Y",ltm);
	cout<<" 2.";
    cout<<"day2";
     ltm->tm_mday=ltm->tm_mday+1;
    strftime (day3,20,"%d-%m-%Y",ltm);
	cout<<" 3.";
    cout<<"day3";
     ltm->tm_mday=ltm->tm_mday+1;
    strftime (day4,20,"%d-%m-%Y",ltm);
	cout<<" 4.";
    cout<<"day4";
     ltm->tm_mday=ltm->tm_mday+1;
    strftime (day5,20,"%d-%m-%Y",ltm);
	cout<<" 5.";
    cout<<"day5 \n";
	cout<<"\n\t\tChoose the Date of BOOKING:";
	cin>>choice;
	fs=bn;
	switch(choice)
	{
		case 1:
		{
			string st(day1);
			fs=fs+','+st;
			book_tkt(fs);
			return 0;
			break;
		}
		case 2:
		{
			string st(day2);
			fs=fs+','+st;
			book_tkt(fs);
			return 0;
			break;

		}
		case 3:
		{
			string st(day3);
			fs=fs+','+st;
			book_tkt(fs);
			return 0;
			break;
		}
		case 4:
		{
			string st(day4);
			fs=fs+','+st;
			book_tkt(fs);
			return 0;
			break;
		}
		case 5:
		{
			string st(day5);
			fs=fs+','+st;
			book_tkt(fs);
			return 0;
			break;
		}
		default:
		{
			cout<<"Invalid Input"<<endl;
		}
	}

}


		};
int main()
{
	char ch,uop;
	int x=0,op;
	Transport *p;
		User u;
		Admin a;
		location:
		    system("cls");
		mainpage::display();
		cout<<"\n\n\n\t\t\t*************************MAIN PAGE******************************"<<endl;
		cout<<"\n\n\t\t1. User Login\n\t\t2. Admin Login\n\t\t3. Exit The Program\n\t\t4. Frequently Asked Questions\n\t\tEnter Your Choice :";
        cin>>ch;
		try
		{
		    if(ch>='a'&&ch<='z')
            {

        throw ch;
            }
		}
		catch(...)
		{
		    cout<<"invalid input";
		}
		if(ch=='1')
		{do{
		    system("cls");
		    mainpage::display();
		    op=u.status();
			if(op=='1')
			{
			    system("cls");
			    mainpage::display();
				u.userinput();
			}
			else if(op=='0')
                goto location;


		}while(op!='2');
		do{
            if(op=='2')
			{

			    p=&u;
                x=p->login();
            }
            else
            {
                goto location;
            }
		}while(x!=1);
        do
        {
            ulocation:
		system("cls");
		mainpage::display();
		cout<<"\n\n\n\t\t    *************************USER PANEL******************************"<<endl;
		cout<<"\n\n\t\t1. Search Buses\n\t\t2. Book Tickets\n\t\tENTER 0 TO RETURN TO MAIN MENU\n\t\tEnter Your Choice :";
		cin>>uop;
		try
		{
		    if(uop>='a'&&uop<='z')
            {

        throw uop;
            }
		}
		catch(...)
		{
		    cout<<"invalid input";
		}
		if(uop=='1')
        {

            system("cls");
            mainpage::display();
            sb::searchb();

        }
        else if(uop=='2')
        {
            system("cls");
		mainpage::display();
		cout<<"\n\n\n\t\t    *************************BOOKING PANEL******************************"<<endl;
            string bn;
            cout<<"\n\t\tEnter bus no.";
            cin>>bn;
            cout<<u.bdate(bn);

        }
        else if(uop!='1'&&uop!='2'&&uop!='0')
            goto ulocation;

		}while(uop<'3'&&uop!='0');
		if(uop=='0')
            goto location;
}
		else if(ch=='2')                              //admin block
        {
            system("cls");
		mainpage::display();
          do{

			    p=&a;
                x=p->login();
		}while(x!=1);
		do
        {
        system("cls");
		mainpage::display();
		cout<<"\n\n\n\t\t\t*************************ADMIN PANEL******************************"<<endl;
		cout<<"\n\n\t\t1. NEW ROUTE ENTRY\n\t\t2. DELETE A SPECIFIC BUS\n\t\t3. VIEW EXISTING ROUTE\n\t\t4. MODIFY EXISTING ROUTE\n\t\t5. VIEW ALL USERS\n\t\t6. VIEW SPECIFIC USER\n\t\t7. VIEW BOOKED SEATS \n\t\t0. RETURN TO MAIN MENU\n\t\tEnter Your Choice :";
		cin>>uop;
		try
		{
		    if(uop>='a'&&uop<='z')
            {

        throw uop;
            }
		}
		catch(...)
		{
		    cout<<"invalid input";
		}
		if(uop=='1')
        {
           a.new_entry();
           cout<<"\n\n\tnew entry successfully added";
        }
        else if(uop=='2')
        {
             system("cls");
		    mainpage::display();
            a.delete_entry();
        }
        else if(uop=='3')
        {
             system("cls");
		    mainpage::display();
          a.view_routes();
        }
        else if(uop=='4')
        {
            system("cls");
		    mainpage::display();
		    string bn;
		    cout<<"enter bus no. to be modified";
		    cin>>bn;
		    a.modify_route(bn);

        }

        else if(uop=='5')
        {
             system("cls");
		    mainpage::display();
           a.user1();
        }
        else if(uop=='6')
        {
             system("cls");
		    mainpage::display();
            int op;
            string uname;
            cout<<"\n\t\t1. View details of a specific user \n\t\t2. Delete a specific user:\n\t\t Enter your choice:";
            cin>>op;

            cout<<"\n\t\tEnter username of the user:";
            cin>>uname;
            a.user1(uname,op);
        }
        else if(uop=='7')
        {
             system("cls");
		    mainpage::display();
		    a.view_tickets();

        }
        else if(uop=='0')
        {
             goto location;
        }
        }while(uop<'8');
        goto location;

        }
        else if(ch=='4')
            {
                system("cls");
		    mainpage::display();
                 faq();
                 goto location;
            }
        else if(ch=='3')
            exit(0);
        else
            goto location;

}



