#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<stdlib.h>
char f[3]="f";
char s[3]="s";int o=0,n=0;
int flag=0,d1,m;
float tamt,amc;
void reserve();
void administration();
void user();
void del();
void created();
void enquiry();
void passdetail();
void displayd();
void usermenu();
void cancel();
class canc  //class for cancellation
{
public:
int pnr;
int tno;
char tname[100];
char bp[10];
char dest[100];
char pname[10][10];
int age[20];
int i;
char clas[10];
int nosc;
int d,m,y;
double amr;
void getcancdet()
{
cout<<"\n Enter the details as follows:-\n";
cout<<" Pnr no:";cin>>pnr;
cout<<" Date of cancellation:";cin>>d>>m>>y;
cout<<"....Thank you for the details....\n";
}
void displaycancdet()
{
cout<<" Pnr no:"<<pnr;
cout<<"\n Train no:"<<tno;
cout<<"       Train name:"<<tname;
cout<<" Boarding point:"<<bp;
cout<<"       Destination pt:"<<dest;
cout<<"\n Your class:"<<clas;
cout<<"\n No. of seats to be cancelled:"<<nosc<<endl;
for(i=0;i<nosc;i++)
{
cout<<" Passenger name:"<<pname[i];
cout<<"     Passenger age:"<<age[i];
}
cout<<"\n Date of cancellation:"<<d<<"-"<<m<<"-"<<y;
cout<<"\n You can collect: Rs."<<amr<<endl;
cout<<"____Your Ticket is cancelled____";
}
}c;
class res  //class for reservation
{
public:
int pnr;
int tno;
char tname[100];
char bp[10];
char dest[100];
char pname[10][10];
int age[20];
char clas[10];
int nosr;
int i;
int d,m,y;
int con;
//float amc;
void getres()
{
cout<<"\n Enter the following details :-\n";
cout<<" Train no:";cin>>tno;
cout<<" Train name:";gets(tname);
cout<<" Boarding point:";gets(bp);
cout<<" Destination pt:";gets(dest);
cout<<" No of seats required:";cin>>nosr;
for(i=0;i<nosr ;i++)
{
cout<<" Passenger name:";gets(pname[i]);
cout<<" Passenger age:";cin>>age[i];
}
cout<<" Enter the class f-first class s-second class:";
cin>>clas;
cout<<" Date of travel:";cin>>d>>m>>y;
cout<<" Enter the concession category\n";
cout<<" 1.Military | 2.Senior citizen |";
cout<<" 3.Children below 5 yrs | 4.Student | 5.None\n ";
cin>>con;
cout<<" Thank you for entering the details\n";
}
void disres()
{
cout<<"\n\n Details ofthe reservation :-\n";
cout<<" Pnr no:"<<pnr;
cout<<"   Train no:"<<tno;
cout<<"   Train name:"<<tname;
cout<<"\n Boarding point:"<<bp;
cout<<"     Destination pt:"<<dest;
cout<<"\n No of seats reserved:"<<nosr;
for(i=0;i<nosr;i++)
{
cout<<"\n Passenger name:"<<pname[i];
cout<<"   Passenger age:"<<age[i];
}

cout<<"\n Your class:"<<clas;
cout<<"   Date of reservation:"<<d<<"-"<<m<<"-"<<y;
cout<<"\n Your concession category:";
if(con==1)
   cout<<"Military";
else if(con==2)
   cout<<"Senior citizen";
else if(con==3)
   cout<<"Children below 5 yrs";
else if(con==4)
   cout<<"Student";
else if(con==5)
   cout<<"None";
}
}r;
class database  //class for entering the train details
{
   public:
      long int tno;
      char tname[50];
      char bp[50],dp[50];//boarding pt. & destination pt.
      int d,m,y;//d-day ,m-month, y-year
      int cf,rf,cs,rs;
      void get()
      {
	 cout<<"\n Enter the following details :-\n";
	 cout<<" Train no : ";cin>>tno;
	 cout<<" Train name : ";gets(tname);
	 cout<<" Boarding point : ";gets(bp);
	 cout<<" Destination point : ";gets(dp);
	 cout<<" No of seats in first class & fare per ticket : ";
	 cin>>cf>>rf;
	 cout<<" No of seats in second class & fare per ticket : ";
	 cin>>cs>>rs;
	 cout<<" Date of travel : ";cin>>d>>m>>y;
      }
      void dis()
      {
	cout<<" Train Number : "<<tno;
	cout<<"     Name   : "<<tname;
	cout<<"\n Boarding Point : "<<bp;
	cout<<"   Destination Point : "<<dp;
	cout<<"\n No. of 1st class seat : "<<cf;
	cout<<"   Fare per ticket : "<<rf;
	cout<<"\n No. of 2nd class seat : "<<cs;
	cout<<"   Fare per ticket : "<<rs;
	cout<<"\n Date of Travel : "<<d<<"-"<<m<<"-"<<y<<endl;

      }

}d;
class login  //class for creating an account
{
   public:
      char id[20];
      char pass[10];
      void getid()
      {
	 cout<<" Enter your id : ";
	 gets(id);
	 cout<<" Enter your password : ";
	 gets(pass);
      }
}l;
void main() //the mainfunction begins
{
  clrscr();
  cout<<"\n\t\t\tWelcome To Railway Reservation System\n";
  cout<<"--------------------------------------------------------------------------------";
  int ch;
  do
  {
  cout<<" Options Are :- ";
  cout<<" (1)-Admin Mode (2)-User Mode (3)-Exit\n";
  cout<<" Enter your choice : ";
  cin>>ch;
  switch(ch)
  {
     case 1:
     {
	 int p;int c;
	 cout<<" Enter administrative password : ";
	 cin>>p;
	 if(p==1234)
	 {
	   administration();
	 }
	 else
	 {
	    cout<<" Enter the password correctly.\n";
	    cout<<" You are not permitted to logon this mode.\n";
	 }
	 break;
     }
     case 2:
	 user();
	 break;
     case 3:
	 exit(0);
	 break;
  }
  }while(ch<=4);
  getch();
}
void created() //for creating an account
{
  char c='y';
  fstream f("t.txt",ios::out|ios::binary);
  do
  {
     d.get();
     f.write((char *) & d,sizeof(d));
     cout<<"Do you want to add one more record?(Y/y-Yes & N/n-No) :-";
     cin>>c;
  }while(c=='y'||c=='Y');
  f.close();
}
void displayd() //to display train details
{
 ifstream fin("t.txt",ios::in|ios::binary);
 while(fin.read((char *) & d,sizeof(d)))
 {
   if(d.tno!=0)
   {
     d.dis();
     cout<<"\n";
   }
 }
 fin.close();
}
void administration()  //administrative menu
{
int c;
do
{
 cout<<"\n\t\t\t     ----Administrator Menu----\n";
 cout<<" (1)-Create a detail data base\n";
 cout<<" (2)-Display details\n";
 cout<<" (3)-Display Passenger Details\n";
 cout<<" (4)-Return to main menu\n";
 cout<<" Enter your choice : ";
 cin>>c;
 switch(c)
 {
   case 1:
   {
     created();
     break;
   }
   case 2:
     cout<<"\n\t____Train Details____ \n";
     displayd();
     break;
   case 3:
     cout<<"\n\t____Passenger Details____\n";
     passdetail();
     break;
   case 4:
     main();
     break;
 }
}while(c<=4);
}
void user()  //for the presence of the account entered
{
char c2,c,e;
cout<<" Do you already have an account ?( Y/y-Yes & N/n-No):- ";
cin>>c2;
c='y'||'Y';
if(c2=='n'||c2=='N')
{
   ofstream fout("id.txt",ios::out|ios::binary);
   do
   {
     l.getid();
     fout.write((char *) & l,sizeof(l));
     cout<<" Want to add one more record?(Y/y) : ";
     cin>>c;
   }while(c=='y'||c=='Y');
   fout.close();
   usermenu();
}
 else if(c2=='Y'||c2=='y')
 {
    usermenu();
 }
}

void usermenu()     //user menu
{
   int t;
   char uid[10],p[10];
   cout<<"\n\t\t\t\t----User Menu----\n";
   cout<<" (1)-Reserve\n (2)-Cancell\n (3)-Enquiry\n (4)-Return to main menu\n";
   ifstream fin("id.txt",ios::out|ios::binary);
   fin.read((char *) & l,sizeof(l));
   cout<<" Enter your choice : ";cin>>t;
   switch(t)
   {
	case 1:
	{
	     cout<<" Enter your user id : ";gets(uid);
	     cout<<" Enter your password : ";gets(p);
	     if(strcmp(l.id,uid)==0 && strcmp(l.pass,p)==0)
	     {
	       reserve();
	       usermenu();
	     }
	     else
	     {
	       cout<<" Your password or user id is incorrect\n";
	       cout<<" Please enter correct user id and password to login\n";
	       usermenu();
	     }
	     break;
	}
	case 2:
	{
	     cout<<" Enter your user id : ";gets(uid);
	     cout<<" Enter your password : ";gets(p);
	     if(strcmp(l.id,uid)==0 && strcmp(l.pass,p)==0)
	     {
	       cancel();
	       usermenu();
	     }
	     else
	     {
	       cout<<" Your password or user id is incorrect\n";
	       cout<<" Please enter correct user id and password to login\n";
	       usermenu();
	     }
	     break;
	}
	case 3:
	{
	     cout<<"\n\t____Train Details____ \n";
	     enquiry();
	     usermenu();
	     break;
	}
	case 4:
	     main();
	     break;
   }
}
void reserve()    //for reservation
{
   randomize();
   int seats;
   res s;
   database d;
   float a,addr,ad;
   fstream f1,f2,f3;
   f1.open("t.txt",ios::in|ios::out|ios::binary);
   f2.open("p.txt",ios::in|ios::out|ios::binary);
   f3.open("temp.txt",ios::in|ios::out|ios::binary);
   int ch;int k=0;
   s.getres();
   while(f1.read((char *) &d,sizeof(d)))
   {
     if(d.tno==s.tno)
     {
	k=1;
	if(stricmp(s.clas,"f")==0)
	{
	   if(d.cf>=s.nosr)
	   {
	       a=d.rf;
	       d.cf=d.cf-s.nosr;
	       if(s.con==1)
	       {
		 cout<<" Concession category:MILITARY PERSONNEL\n";
		 amc=s.nosr*((a*50)/100);
	       }
	       else if(s.con==2)
	       {
		 cout<<" Concession category:SENIOR CITIZEN\n";
		 amc=s.nosr*((a*60)/100);
	       }
	       else if(s.con==3)
	       {
		 cout<<" Concession category:CHILDERN BELOW FIVE\n";
		 amc=0.0;
	       }
	       else if(s.con==4)
	       {
		 cout<<" Concession category:STUDENT\n";
		 amc=s.nosr*((a*50)/100);
	       }
	       else if(s.con==5)
	       {
		 cout<<" You cannot get any concession\n";
		 amc=s.nosr*a;
	       }
	       s.pnr=rand();
	       cout<<"\n End of reservation";
	       f2.write((char *) & s,sizeof(s));
	       s.disres();
	       cout<<"\n--------------------------------------------------------------------------------";
	       cout<<"\n You must pay : Rs."<<amc;
	       cout<<"\n ____Your reservation is successful____";
	   }
	   else
	       cout<<"\n Sorry the required seats are not available!!!\n";
	}
	else if(stricmp(s.clas,"s")==0)
	{
	   if(d.cs>=s.nosr)
	   {
	      a=d.rs;
	      d.cs=d.cs-s.nosr;
	      if(s.con==1)
	       {
		 cout<<" Concession category:MILITARY PERSONNEL\n";
		 amc=s.nosr*((a*50)/100);
	       }
	      else if(s.con==2)
	       {
		 cout<<" Concession category:SENIOR CITIZEN\n";
		 amc=s.nosr*((a*60)/100);
	       }
	      else if(s.con==3)
	       {
		 cout<<" Concession category:CHILDERN BELOW FIVE\n";
		 amc=0.0;
	       }
	      else if(s.con==4)
	       {
		 cout<<" Concession category:STUDENT\n";
		 amc=s.nosr*((a*50)/100);
	       }
	      else if(s.con==5)
	       {
		 cout<<" You cannot get any concession\n";
		 amc=s.nosr*a;
	       }
	      s.pnr=rand();
	      cout<<"\n End of reservation ";
	      f2.write((char *) & s,sizeof(s));
	      s.disres();
	      cout<<"\n--------------------------------------------------------------------------------";
	      cout<<" You must pay : Rs."<<amc;
	      cout<<"\n ____Your reservation is successful____";
	   }
	   else
	       cout<<"\n Sorry the required seats are not available!!!!\n";
	}
     }
     f3.write((char*)&d,sizeof(d));
   }
   if(k==0)
      cout<<" You entered wrong details";
   f1.close();f2.close();f3.close();
  remove("t.txt");rename("temp.txt","t.txt");
}
void enquiry()
{
 database d;
 ifstream f("t.txt",ios::in|ios::binary);
 while(f.read((char *) & d,sizeof(d)))
 {
    d.dis();
    cout<<"\n";
 }
 f.close();
}
void cancel()     //for cancellation of a ticket
{
   database a;res b;canc c;
   fstream f1,f2,f3,f4;
   f1.open("p.txt",ios::in|ios::out|ios::binary);
   f2.open("cn.txt",ios::in|ios::out|ios::binary);
   f3.open("t.txt",ios::in|ios::out|ios::binary);
   f4.open("temp.txt",ios::in|ios::out|ios::binary);
   c.getcancdet();
   while(f1.read((char*)&b,sizeof(b)))
   {
     if(b.pnr==c.pnr)
     {
	flag=1;
	c.tno=b.tno;
	strcpy(c.tname,b.tname);
	strcpy(c.bp,b.bp);
	strcpy(c.dest,b.dest);
	c.nosc=b.nosr;
	for(int j=0;j<c.nosc;j++)
	{
	   strcpy(c.pname[j],b.pname[j]);
	   c.age[j]=b.age[j];
	}
	strcpy(c.clas,b.clas);
	tamt=amc;

	while(f3.read((char *) & a,sizeof(a)))
	{
	 if(a.tno==c.tno && strcmp(c.clas,f)==0)
	 {
	    a.cf=a.cf+c.nosc;d1=a.d;m=a.m;
	    if((c.d==d1)&&(c.m==m))
	    {
	      cout<<" You are cancelling at the date of departure\n";
	      c.amr=tamt-((tamt*75)/100); c.displaycancdet();
	    }
	    else if(c.m==m)
	    {
	      cout<<" You are cancelling at the month of departure\n";
	      c.amr=tamt-((tamt*50)/100); c.displaycancdet();
	    }
	    else if(m-c.m==1)
	    {
	      cout<<" You are cancelling one month before the date of departure\n";
	      c.amr=tamt-((tamt*25)/100); c.displaycancdet();
	    }
	    else
	    {
	      cout<<" Cancelling after the departure\n";
	      cout<<" Your request cannot be completed\n";c.amr=0;
	    }
	    f4.write((char*)&a,sizeof(a));
	    f2.seekg(0);
	    break;
	 }
	 else if(a.tno==c.tno && strcmp(c.clas,s)==0)
	 {
	    a.cs=a.cs+c.nosc;d1=a.d;m=a.m;
	    if((c.d==d1)&&(c.m==m))
	    {
	      cout<<" You are cancelling at the date of departure\n";
	      c.amr=tamt-((tamt*25)/100); c.displaycancdet();
	    }
	    else if(c.m==m)
	    {
	      cout<<" You are cancelling at the month of departure\n";
	      c.amr=tamt-((tamt*75)/100); c.displaycancdet();
	    }
	    else if(m-c.m==1)
	    {
	      cout<<" You are cancelling one month before the date of departure\n";
	      c.amr=tamt-((tamt*50)/100); c.displaycancdet();
	    }
	    else
	    {
	      cout<<" Cancelling after the departure\n";
	      cout<<" Your request cannot be completed\n";c.amr=0;
	    }
	    f4.write((char*)&a,sizeof(a));
	    f2.seekg(0);
	    break;
	 }
	 else if(b.pnr!=c.pnr)
	   cout<<" You entered wrong details";
	}
     }
     f2.write((char*)&c,sizeof(c));
   }
   f2.close();
   f1.close();
   f3.close();
   f4.close();
   remove("t.txt");rename("temp.txt","t.txt");
   del();
}
void del()
{
  fstream f1,f2,f3;
  f1.open("p.txt",ios::in|ios::out|ios::binary);
  f2.open("cn.txt",ios::in|ios::out|ios::binary);
  f3.open("temp.txt",ios::in|ios::out|ios::binary);
  while(f2.read((char *) & c,sizeof(c)))
  {
     f1.read((char *) & r,sizeof(r));
     if(c.pnr!=r.pnr)
     {
	f3.read((char *) &r,sizeof(r));o++;
     }
  }
  f1.close();f2.close();f3.close();
  remove("p.txt");rename("temp.txt","p.txt");
}
void passdetail()   //for displaying passenger details
{
fstream f;
res b;
f.open("p.txt",ios::in|ios::out|ios::binary);
while(f.read((char *) & b,sizeof(b)))
{
if(f.eof())
 { cout<<" No passenger";break;}
else
 { b.disres();}
cout<<"\n";
}
f.close();
getch();
}
