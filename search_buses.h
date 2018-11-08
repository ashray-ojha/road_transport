#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;
namespace sb
{
int searchb()
{
	int flag=0,k=0,a=0,c=0,op=0;
	string s,s1,h;
	char s3[100][100];

	string from_city;
	string to_city;
	cout<<"\t\tEnter the starting point(in CAPITAL LETTERS):";
	cin>>from_city;
	cout<<"\t\tEnter the ending point(in CAPITAL LETTERS):";
	cin>>to_city;
	ifstream q;
	q.open("Transport.csv",ios::in);
    cout<<"\n\t\t\t*******************Available Buses*********************"<<endl<<"Bus Number\t\tStart Time\t\tEnding Time\t\t Halting stations";
		while(getline(q,s))
		{	flag=0;
			int x=s.find(from_city);
			int y=s.find(to_city);
			int l2=to_city.length();
			int l=from_city.length();
			int len=s.length();
			if(x<y){

			if(s[x-1]==','&&s[x+l]==',')
			{
				flag++;
			}
			if(s[y-1]==','&&s[y+l2]==',')
			{
			flag++;
			}
			if(flag==2)
			{



						cout<<endl<<s[0]<<s[1]<<s[2]<<"\t\t\t";
						for(int i=x+l+1;i<=x+l+5;i++)
						{
							cout<<s[i];
						}
						cout<<"\t\t\t";
						for(int i=y+l2+1;i<=y+l2+5;i++)
						{
							cout<<s[i];

						}
						for(int i=0;i<len;i++)
                        {
                            if(s[i]==',')
                                c++;
                            if(c%2==1)
                            {
                                h=h+s[i];
                            }
                        }
                        cout<<"\t\t\t";
                        for(int i=1; i<h.length();i++)
                        {
                            if(h[i]==',')
                                h[i]='-';
                           cout<<h[i];
                        }


		    }}
            h="\0";
		}q.close();
		cout<<"\n\nPress 1 to return to main menu:";
     cin>>op;
     if(op==1)
        return 0;

}
}
