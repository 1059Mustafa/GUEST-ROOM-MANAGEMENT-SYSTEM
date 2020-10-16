//C++ OOP PROJECT
//IIITA VISITOR HOSTEL
#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

using namespace std;

//START OF CLASS



class visitor_hostel
{

int room_no;
char name[30];
char address[50];
char phone[10];

public:

void hostel_menu();		//to dispay the main menu of visitor hostel
void add();			//to book a room in visitor hostel
void display(); 		//to display the visitor record
void rooms();			//to display alloted rooms in visitor hostel
void edit();			//to edit the visitor record
int check(int);			//to check room status
void modify(int);		//to modify the record
void delete_rec(int);	//to delete the record
void bill(int);               //for the bill of a record
     };
    //END OF CLASS DEFINITION







void visitor_hostel::hostel_menu()
{

int choice;
while(choice!=5)
{

  system("cls");
cout<<"\n\t\t\t\t*************************";
cout<<"\n\t\t\t\t Visitor_Hostel MANAGEMENT ";
cout<<"\n\t\t\t\t      * Hostel MENU *";
cout<<"\n\t\t\t\t*************************";
cout<<"\n\n\n\t\t\t1.Book A Room";
cout<<"\n\t\t\t2.Visitor Records";
cout<<"\n\t\t\t3.Rooms Allotted";
cout<<"\n\t\t\t4.Edit Record";
cout<<"\n\t\t\t5.Exit";
cout<<"\n\n\t\t\tEnter Your Choice: ";
cin>>choice;

switch(choice)
{

case 1:	add();
break;

case 2: display();
break;

case 3: rooms();
break;

case 4:	edit();
break;

case 5: break;

default:
{

cout<<"\n\n\t\t\tWrong choice.....!!!";
cout<<"\n\t\t\tPress any key to   continue....!!";
getch();

}

}

}

}


//END OF MENU FUNCTION


//FUNCTION FOR BOOKING OF ROOM IN VISITOR HOSTEL


void visitor_hostel::add()
{

  system("cls");
int r,flag;
ofstream fout("Record.dat",ios::app);

cout<<"\n Enter visitor Detalis";
cout<<"\n ----------------------";
cout<<"\n\n Room no: ";
cout<<"\n Total no. of Rooms - 50";
cout<<"\n Single bed Rooms from 1 - 30";
cout<<"\n Double bed Rooms from 31 - 45";
cout<<"\n Meeting  Rooms from 46 - 50";
cout <<"\n Enter The Room no. you want to stay in :- "<<endl;
cin>>r;

flag=check(r);

if(flag)
cout<<"\n Sorry..!!!Room is already booked";

else
{

room_no=r;
cout<<" Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone No: ";
cin>>phone;

fout.write((char*)this,sizeof(visitor_hostel));
cout<<"\n Room is booked...!!!";

}

cout<<"\n Press any key to continue.....!!";

getch();
fout.close();

}


//END OF BOOKING FUNCTION


//FUNCTION FOR DISPLAYING A PURTICULAR VISITOR`S RECORD





void visitor_hostel::display()
{

  system("cls");

ifstream fin("Record.dat",ios::in);
int r,flag;

cout<<"\n Enter room no. for a particular visitor`s details :- "<<endl;
cin>>r;

while(!fin.eof())
{

fin.read((char*)this,sizeof(visitor_hostel));
if(room_no==r)
{

  system("cls");
cout<<"\n Visitor Details";
cout<<"\n ----------------";
cout<<"\n\n Room no: "<<room_no;
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone no: "<<phone;
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant....!!";
cout<<"\n\n Press any key to continue....!!";

getch();
fin.close();
}


//END OF DISPLAY FUNCTION

//FUNCTION TO DISPLAY ALL ROOMS OCCUPIED


void visitor_hostel::rooms()
{

  system("cls");

ifstream fin("Record.dat",ios::in);
cout<<"\n\t\t\t    List Of Rooms Allotted";
cout<<"\n\t\t\t    ----------------------";
cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\n";

while(fin.read((char*)this,sizeof(visitor_hostel)))
{


cout<<"\n\n "<<room_no<<"\t\t"<<name;
cout<<"\t\t"<<address<<"\t\t"<<phone;

}

cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
getch();
fin.close();

}


//FUNCTION FOR EDITING RECORDS AND FOR BILL


void visitor_hostel::edit()
{

  system("cls");

int choice,r;
cout<<"\n EDIT MENU";
cout<<"\n ---------";
cout<<"\n\n 1.Modify visitor Record";
cout<<"\n 2.Delete visitor Record";
cout<<"\n 3. Bill Of visitor";
cout<<"\n Enter your choice: ";

cin>>choice;
  system("cls");

cout<<"\n Enter room no: " ;
cin>>r;

switch(choice)
{

case 1:	modify(r);
break;

case 2:	delete_rec(r);
break;

case 3: bill(r);
break;

default: cout<<"\n Wrong Choice.....!!";

}
cout<<"\n Press any key to continue....!!!";

getch();
}
//checking for the availability of the room

int visitor_hostel::check(int r)
{

int flag=0;

ifstream fin("Record.dat",ios::in);

while(!fin.eof())
{

fin.read((char*)this,sizeof(visitor_hostel));
if(room_no==r)
{

flag=1;
break;

}

}

fin.close();
return(flag);

}


//FUNCTION TO MODIFY visitorS RECORD


void visitor_hostel::modify(int r)
{

long pos,flag=0;

fstream file("Record.dat",ios::in|ios::out|ios::binary);

while(!file.eof())
{

pos=file.tellg();
file.read((char*)this,sizeof(visitor_hostel));

if(room_no==r)
{

cout<<"\n Enter New Details";
cout<<"\n -----------------";
cout<<"\n Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone no: ";
cin>>phone;
file.seekg(pos);
file.write((char*)this,sizeof(visitor_hostel));
cout<<"\n Record is modified....!!";
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant...!!";
file.close();

}


//END OF MODIFY FUNCTION


//FUNCTION FOR DELETING RECORD


void visitor_hostel::delete_rec(int r)
{

int flag=0;
char ch;
ifstream fin("Record.dat",ios::in);
ofstream fout("temp.dat",ios::out);

while(!fin.eof())
{

fin.read((char*)this,sizeof(visitor_hostel));
if(room_no==r)

{

cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone No: "<<phone;
cout<<"\n\n Do you want to delete this record(y/n): ";
cin>>ch;

if(ch=='n')
fout.write((char*)this,sizeof(visitor_hostel));
flag=1;

}

else
fout.write((char*)this,sizeof(visitor_hostel));

}

fin.close();
fout.close();

if(flag==0)
cout<<"\n Sorry room no. not found or vacant...!!";

else
{

remove("Record.dat");
rename("temp.dat","Record.dat");

}

}


//END OF DELETE FUNCTION


//FUNCTION FOR visitor`S BILL

void visitor_hostel::bill(int r)
{

visitor_hostel h1;
ifstream f1;
 f1.open("record.dat",ios::in|ios::binary);

if(!f1)
 cout<<"cannot open";

 else
 {
  int temp=0;
   while(!f1.eof())
  {

  f1.read((char*)&h1,sizeof(visitor_hostel));

  

  if (h1.room_no == r)
  {
  temp=1;
  if(h1.room_no>=1&&h1.room_no<=30)
  cout<<"your bill = 2000";

  else if (h1.room_no>=35&&h1.room_no<=45)
  cout<<"your bill = 5000" ;

  else
  cout<<"your bill = 7000";
  break;

  }
}
  if(temp==0)
  { cout<<"room no. not found";}

  }

  f1.close();
  getch();

}


//START OF THE MAIN()

int main()
{

visitor_hostel h;

  system("cls");

cout<<"\n\t\t\t****************************";
cout<<"\n\t\t\t* IIITA VISITOR HOSTEL *";
cout<<"\n\t\t\t****************************";
cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";

getch();

h.hostel_menu();
return 0;
}

