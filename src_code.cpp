//RESTAURANT BILLING
//**********************************************************
//HEADER FILES
//**********************************************************
#include<iostream.h>
#include<string.h>
#include<fstream.h>
#include<process.h>
#include<conio.h>
//**********************************************************
//FUNCTION PROTOTYPESa
//**********************************************************
void biller(void);
void Master(void);
void notfound(void);
int itcd(void);
int retprice(void);
void display(void);
void vdisplay(void);
void intro(void);
//**********************************************************
//CLASS
//**********************************************************
class item
{
char itname[20];
float price;
public:
int itcode;
float qt;
void display();
void vdisplay();
int itcd();
int retprice();
};//ENDING OF CLASS DEFINITION
//**********************************************************
int amount=0;
int item::retprice()
{
return price;
}
void item::display()
{
cout<<" "<<itcode<<" "<<itname<<" "<<price<<" ";
}
void item::vdisplay()
{
cout<<itcode<<"\t"<<itname<<"\t"<<price<<"\t";
}
int item::itcd()
{
return itcode;
}
//**********************************************************
//GLOBAL DECLARATION OF OBJECT OF CLASS ITEM
//**********************************************************
item it;
int i;
//**************************************************************************
//THE MAIN FUNCTION
//**********************************************************
void main()
{
clrscr();
start:
int it_code;
cout<<"\n\t\t\t\tHOTEL MANGALA,KODUNGALLUR\n\n";
cout<<"Welcome to the Restaurant Billing Program\n";
cout<<"1.Go to Billing \n";
cout<<"2.See the Master Data \n";
cout<<"3.Project Credits\n";
cout<<"4.Exit"<<" \n";
cout<<"\nEnter your option: ";
char ch1;
cin>>ch1;
switch(ch1)
{
case '1':biller();
break;
case '2':Master();
break;
case '3':intro();
case '4':exit(0);
default:cout<<"Invalid option ";
cout<<"Exiting...";
getch();
}
getch();
}
//**********************************************************
//FUNCTION WHICH DOES THE WHOLE BILLING PROCEDURES
//*********************************************************
void biller()
{
beg: //tag is used for goto
int j,it_code,qt;
cout<<"\nEnter Item Code: ";
cin>>it_code;
ifstream fin("master.dat",ios::in);
while(!fin.eof())
{
fin.read((char*)&it,sizeof(it));
if(it.itcd()==it_code)
{
int pri;
cout<<"Enter quantity or number of the selected food: ";
cin>>qt;
cout<<"\nItem-Code"<<" "<<"Item-Name"<<" "<<"Price"<<" "<<"Quantity"<<" "<<"Total-Price\n";
it.display();
pri=it.retprice();
cout<<qt<<"\t"<<qt*pri;
int cash=qt*pri;
amount=amount+cash;
cout<<"\n\nWant to enter more food items,if yes please enter y or enter p, it wil proceed to billing: ";
char ch;
cin>>ch;
if(ch=='p')
cout<<"\n->>>>>> TOTAL AMOUNT: "<<amount;
else
biller();
enter: //tag is used for goto
cout<<"\n\n1.Restart the Program \n";
cout<<"2.Exit the Program\n";
cout<<"Enter your choice: ";
char chr;
cin>>chr;
switch(chr)
{
case '1':amount=0;
main();
break;
case '2':exit(0);
default:cout<<"\nWrong option,Enter your choice again, ";
goto enter;
}
}
}
notfound();
}
//**********************************************************
//THE FUNCTION THAT DISPLAYS THE ITEM LIST
//**********************************************************
void Master()
{
ifstream filin2;
filin2.open("master.dat",ios::in);
cout<<"\n";
cout<<"Code"<<"\t"<<"Name"<<"\t"<<"Price\n";
for(i=0;i<15;i++)
{
filin2.read((char*)&it,sizeof(it));
it.vdisplay();
cout<<"\n";
}
cout<<"\nEnter 'y' to go back to Main Menu or Enter 'e' to exit : ";
char charac;
cin>>charac;
if(charac=='y')
main();
else
exit(0);
filin2.close();
}
//**********************************************************
//NOTFOUND() FUNCTION DISPLAYS A MESSAGE WHEN AN ITEM SEARCHED IS NOT FOUND
//**********************************************************
void notfound()
{
cout<<"Item not found\n";
cout<<"Please enter again\n";
biller();
}
//**********************************************************
//INTRODUCTION
//**********************************************************
void intro()
{
cout<<"\nRESTAURANT BILLING ";
cout<<"PROJECT";
cout<<"\n\nMADE BY : SHRIAMRUT V,ABHINAV KS,ADITH KD,VIGNESH TP";
cout<<"\n\nSCHOOL : AMRITA VIDYALAYAM,KODUNGALLUR";
}
//**********************************************************
//END OF PROJECT
//**********************************************************
