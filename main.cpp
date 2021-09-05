//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<fstream.h>
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

//***************************************************************
//                   CLASSESS USED IN PROJECT
//****************************************************************

class account
{
	int ac_no;
	int age;
	char name[50];
	char name2[50];
	float deposit;
	char type;
	int fd_no;
	int month;
	float rate;
	double yr;
	float dep_fd;
public:
	void create_account();
	void show_account();
	void modify();
	void dep(int);
	void draw(int);
	void report();
	int retacno();
	float retdeposit();
	char rettype();
	void create_fd();
	void show_fd();
	void calculate();
	int retfd_no();
	void report_fd();
	void modify_fd();

};

void account::create_account()
{
	cout<<"\nYour account No. is:";
	srand(time(0));
	ac_no=rand()%500+1;
	cout<<ac_no;
	cout<<"\n\nEnter The  First Name of The account Holder : ";
	gets(name);
	cout<<"\nEnter The  Last Name of The account Holder : ";
	gets(name2);
	cout<<"\nEnter the Age of the Account Holder : ";
	cin>>age;
	if (age>95)
	{
	    cout<<"Enter a valid age: ";
	    cin>>age;
	}
	while (age<='a' && age>='z'&& age<='A'&& age>='Z')
	{
	    cout<<"\nEnter a valid age:";
	    cin>>age;
	}
	cout<<"\nEnter Type of The account to be made(C/S) : ";
	cin>>type;
	type=toupper(type);
	while (type!='c' && type!='s'&& type!='C'&& type!='S')
	{ cout <<"\nUNKNOWN CHARACTER";
	  cout<<"\nEnter 'c' or 's':";
	 cin>>type;
	}
	cout<<"\n\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	{
	while (type=='C'&& deposit<=1000)
	 {
	    cout<<"\n\nPlease deposit a minimum balance of Rs 1000 for your account is of current type";
	    cout<<"\nEnter again: ";
	    cin>>deposit;
	 }
	while(type=='S'&&deposit<=500)
	{
	    cout<<"\n\nPlease deposit a minimum balance of Rs 500 for your account is of savings type";
	    cout<<"\nEnter again: ";
	    cin>>deposit;
	}

	cout<<"\nThank you for depositing an amount of Rs "<<deposit<<" in our bank";
	}
	cout<<"\n\n\nAccount Created..";
}

void account::show_account()
{
	cout<<"\nAccount No. : "<<ac_no;
	cout<<"\nAccount Holder Name : ";
	cout<<name<<" "<<name2;
	cout<<"\nAge of the account Holder:"<<age;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
}


void account::modify()
{
	char v;
	cout<<"\nThe account No."<<ac_no;
	cout<<"\n\nEnter The First Name of The account Holder : ";
	gets(name);
	cout<<"\n\nEnter the Last name of the account Holder : ";
	gets(name2);
	cout<<"\n\nEnter the Age of the Account Holder : ";
	cin>>age;
	if (age>95 && age<9)
	{
	    cout<<"\nEnter a valid age: ";
	    cin>>age;
	}
	while (age<='a' && age>='z'&& age<='A'&& age>='Z')
	{
	    cout<<"\nEnter a valid age:";
	    cin>>age;
	}
	cout<<"\n\nEnter Type of The account (C/S) : ";
	cin>>v;
	v=toupper(v);

	if(v==toupper(type))
	   {
	    cout<<" ";
	   }
	else while(v!=toupper(type))
	{
	  cout<<"\n\n\tYOU HAVE TO DELETE YOUR ACCOUNT IF YOU WANT TO CHANGE YOUR ACCOUNT TYPE";
	  cout<<"\n\n\tenter again:";
	  cin>>v;
	}

}
void account::dep(int x)
{
	deposit+=x;
}

void account::draw(int x)
{
	deposit-=x;
}

void account::report()
{
	cout<<ac_no<<setw(10)<<" "<<name<<setw(12)<<" "<<type<<setw(8)<<deposit<<endl;
}

int account::retacno()
{
	return ac_no;
}

float account::retdeposit()
{
	return deposit;
}

char account::rettype()
{
	return type;
}
void account::create_fd()
{
	cout<<"\nYour Fixed Deeposit No. is:";
	srand(time(0));
	fd_no=rand()%500+1;
	cout<<fd_no;
	cout<<"\n\nEnter The  First Name of The Fixed Deposit Holder : ";
	gets(name);
	cout<<"\nEnter The  Last Name of The Fixed Deposit Holder : ";
	gets(name2);
	cout<<"\nEnter the Age of the Fixed Deposit Holder : ";
	cin>>age;
	if (age>95 && age<9)
	{
	    cout<<"\nEnter a valid age: ";
	    cin>>age;
	}

	while (age<='a' && age>='z'&& age<='A'&& age>='Z')
	{
	    cout<<"\nEnter a vaid age :";
	    cin>>age;
	}

	   cout<<"\n\nEnter The Initial amount( >=5000 for opening an FD : ";
	   cin>>deposit;
	   while (deposit<=5000)
	{
	    cout<<"\n\nPlease deposit a minimum balance of Rs 5000 for your FD";
	    cout<<"\nEnter again: ";
	    cin>>deposit;
	}
	while (deposit<='a' && deposit>='z'&& deposit<='A'&& deposit>='Z')
	{
	    cout<<"\nEnter again:";
	    cin>>deposit;
	}
	cout<<"\n\n\nAccount Created..";


}
	void account::show_fd()
{

	cout<<"\nFixed Deposit No. : "<<fd_no;
	cout<<"\nFixed Deposit Holder Name : ";
	cout<<name<<" "<<name2;
	cout<<"\nAge of the Holder: "<<age;
	cout<<"\nDeposit in the Account:"<<deposit;
	cout<<"\n\n\nAccount Created..";


}
void account::calculate()
{
   rate=6.25;
  cout<<"\nEnter the time period of your deposit (in months): ";
  cin>>month;
  cout<<"\nThe rate of interest fixed per annum is: "<<rate<<"%";
  yr=month/12;
  dep_fd=deposit*pow((1+rate/100),yr);
  cout<<"\nTHE FIXED DEPOSIT OF THIS AMOUNT IS :"<<dep_fd;

}
int account::retfd_no()
{
     return fd_no;
}
void account::report_fd()
{
	cout<<fd_no<<setw(10)<<" "<<name<<setw(8)<<" "<<deposit<<setw(8)<<" "<<dep_fd<<endl;
}
void account::modify_fd()
{
	cout<<"\nThe account No."<<fd_no;
	cout<<"\nEnter The First Name of The account Holder : ";
	gets(name);
	cout<<"\nEnter The  Last Name of The Fixed Deposit Holder : ";
	gets(name2);
	cout<<"\nEnter the Age of the Fixed Deposit Holder : ";
	cin>>age;
	if (age>95)
	{
	    cout<<"\nEnter a valid age: ";
	    cin>>age;
	}

	while (age<='a' && age>='z'&& age<='A'&& age>='Z')
	{
	    cout<<"\nEnter a vaid age :";
	    cin>>age;
	}

}

//***************************************************************
//    	FUNCTIONS DECLARED
//****************************************************************

void write_account(); //function to write account  file
void display(int);  //function to display account details given by user
void modify_account(int);    //function to modify record of file
void delete_account(int);    //function to delete record of file
void display_all();     //function to display all account details
void deposit(int);      // function to desposit amount for given account
void withdraw(int);     // function to withdraw amount for given account
void write_fd();    //function to write record in file
void display_fd(int);  //function to display fixed deposit details given by user
void calc_fd(int);       // function to calculate fixed deposit  for given account
void delete_fd(int);       //function to delete record of file
void modify_fixed(int);      //function to modify record of file
void intro();      //introductory screen function

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
	char ch;
	int num;
	int op;
	clrscr();
	intro();
	do
	{
		clrscr();
		cout<<"\n\n\n\t  MAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. CALCULATE FIXED DEPOSIT";
		cout<<"\n\n\t05. BALANCE ENQUIRY";
		cout<<"\n\n\t06. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t07. CLOSE AN ACCOUNT";
		cout<<"\n\n\t08. MODIFY AN ACCOUNT";
		cout<<"\n\n\t09. EXIT";
		cout<<"\n\n\tSelect Your Option (1-9) ";
		cin>>ch;
		clrscr();
		switch(ch)
		{
		case '1':
			cout<<"\n\n\tPress 1 for Creating an Account";
			cout<<"\n\n\tPress 2 for Creating an FD ";
			cout<<"\n\n\tSelect one option from the below: ";
			cin>>op;
			while(op!=1 && op!=2)
			{
			  cout<<"\nEnter again:";
			  cin>>op;
			}
			if(op==1)
			{
				write_account();
			}
			else if (op==2)
			{
				write_fd();
			}
			else
			{
				exit(0);
			}
			break;

		case '2':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit(num);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			withdraw(num);
			break;
		case '4':
			cout<<"Enter the fixed deposit No. : ";cin>>num;
			calc_fd(num);
			break;
		case '5':
			cout<<"\n\n\tPress 1 to Display an Account";
			cout<<"\n\n\tPress 2 to Display an FD ";
			cout<<"\n\n\tSelect one option from the below: ";
			cin>>op;
			while(op!=1 && op!=2)
			{
			  cout<<"\nEnter again:";
			  cin>>op;
			}
			if(op==1)
			{
			  cout<<"\n\n\tEnter The Account No. : ";
			  cin>>num;
			  display(num);
			}
			else if (op==2)
			{
			  cout<<"\n\n\tEnter The Fixed Deposit No. : ";
			  cin>>num;
			  display_fd(num);
			}
			else
			{
			  exit(0);
			}
			break;
		case '6':
			display_all();
			break;
		case '7':
			cout<<"\n\n\tPress 1 for Deleting an Account";
			cout<<"\n\n\tPress 2 for Deleting an FD ";
			cout<<"\n\n\tSelect one option from the below: ";
			cin>>op;
			while(op!=1 && op!=2)
			{
			  cout<<"\nEnter again:";
			  cin>>op;
			}
			if(op==1)
			{
			  cout<<"\n\n\tEnter The Account No. : ";
			  cin>>num;
			  delete_account(num);
			}
			else if (op==2)
			{
			  cout<<"\n\n\tEnter The Fixed Deposit No. : ";
			  cin>>num;
			  delete_fd(num);
			}
			else
			{
			  exit(0);
			}
			break;
		 case '8':
			cout<<"\n\n\tPress 1 for Modifying an Account";
			cout<<"\n\n\tPress 2 for Modifying an FD ";
			cout<<"\n\n\tSelect one option from the below: ";
			cin>>op;
			while(op!=1 && op!=2)
			{
			  cout<<"\nEnter again:";
			  cin>>op;
			}
			if(op==1)
			{
			  cout<<"\n\n\tEnter The Account No. : ";
			  cin>>num;
			  modify_account(num);
			}
			else if (op==2)
			{
			  cout<<"\n\n\tEnter The Fixed Deposit No. : ";
			  cin>>num;
			  modify_fixed(num);
			}
			else
			{
			  exit(0);
			}
			break;
		 case '9':
			cout<<"\n\n\n\n-------------------------------------------------------------------------------";
			cout<<"\n-----------------------Thanks for using bank managemnt system-------------------" ;
			cout<<"--------------------------------------------------------------------------------";
			cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t>> EFFORTS BY : VIBHOR GROVER";
			cout<<"\n\t\t\t\t\t\t>> CLASS: 11th-E";
			cout<<"\n\t\t\t\t\t\t>> ROLL NO.:11239";
			break;
		 default :cout<<"\a";
		}
		getch();
    }while(ch!='9');
	return 0;
}

//***************************************************************
//    	function to write in file
//****************************************************************

void write_account()
{
	account ac;
	fstream f1;
	f1.open("account.dat",ios::binary|ios::app|ios::in|ios::out);
	ac.create_account();
	f1.write((char *) &ac, sizeof(account));
	f1.close();
}

//***************************************************************
//    	function to read specific record from file  (account)
//****************************************************************

void display(int r)
{
	account ac;
	int flag=0;
       fstream f2;
    f2.open("account.dat",ios::binary|ios::in|ios::out);
	if(!f2)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
    while(f2.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()==r)
		{
			ac.show_account();
			flag=1;
		}

	}
    f2.close();
	if(flag==0)
		cout<<"\n\nAccount number does not exist";
}

//**********************************************************************
//    	function to read specific record from file  (fixed deposit)
//***********************************************************************

 void display_fd(int r)
{
	account ac;
	int flag=0;
       fstream f2;
    f2.open("account1.dat",ios::binary|ios::in|ios::out);
	if(!f2)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
    while(f2.read((char *) &ac, sizeof(account)))
	{
		if(ac.retfd_no()==r)
		{
			ac.show_fd();
			flag=1;
		}

	}
    f2.close();
	if(flag==0)
		cout<<"\n\nAccount number does not exist";
}

//***************************************************************
//    	function to modify record of file    (account)
//****************************************************************

void modify_account(int r)
{
	int found=0;
	account ac;
	fstream f3;
	f3.open("account.dat",ios::binary|ios::in|ios::out);
	if(!f3)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(f3.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==r)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*sizeof(account);
			f3.seekp(pos,ios::cur);
		    f3.write((char *) &ac, sizeof(account));
		    cout<<"\n\n\t Record Updated";
		    found=1;
		  }
	}
	f3.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}

//***************************************************************
//    	function to delete record of file   (account)
//****************************************************************

void delete_account(int r)
{
	account ac;
	fstream f2;
	fstream f1;
	f2.open("account.dat",ios::binary|ios::in|ios::out);
	if(!f2)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	f1.open("Temp.dat",ios::binary|ios::in|ios::out);

	while(f2.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()!=r)
		{
			f1.write((char *) &ac, sizeof(account));
		}
	}
    f2.close();
	f1.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
}

//***************************************************************
//    	function to display all records deposit list
//****************************************************************

void display_all()
{
	account ac;
	fstream f2;
	f2.open("account.dat",ios::binary|ios::in|ios::out);
	if(!f2)
	{

	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
	while(f2.read((char *) &ac, sizeof(account)))
	{
		ac.report();
	}
	f2.close();

	f2.open("account1.dat",ios::binary|ios::in|ios::out);
	if(!f2)
	{

	}
	cout<<"\n\n :::-----------------------------------------------------------------:::";
	cout<<"\n\n\t\tFIXED DEPOSIT RATE LIST\n\n";
	cout<<"=======================================================\n";
	cout<<"FD no.      NAME          Balance      Maturity\n";
	cout<<"=======================================================\n";
	while(f2.read((char *) &ac, sizeof(account)))
	{
		ac.report_fd();
	}
	f2.close();
}

//***************************************************************
//    	function to deposit amounts
//****************************************************************

void deposit(int r)
{
	int amt;
	int found=0;
	account ac;
	fstream f3;
	f3.open("account.dat", ios::binary|ios::in|ios::out);
	if(!f3)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(f3.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==r)
		{
			ac.show_account();
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ac.dep(amt);
			}
			int pos=(-1)* sizeof(ac);
			f3.seekp(pos,ios::cur);
			f3.write((char *) &ac, sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=1;
	       }
	 }
    f3.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}

//***************************************************************
//    	function to withdraw amounts
//****************************************************************

void withdraw(int r)
{
	int amt;
	int found=0;
	account ac;
	fstream f3;
	f3.open("account.dat", ios::binary|ios::in|ios::out);
	if(!f3)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(f3.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==r)
		{
			ac.show_account();

			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)* sizeof(ac);
			f3.seekp(pos,ios::cur);
			f3.write((char *) &ac, sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=1;
	       }
	 }
    f3.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}

//***************************************************************
//    	function to write in file
//****************************************************************

void write_fd()
{
	account ac;
	fstream f1;
	f1.open("account1.dat",ios::binary|ios::app|ios::in|ios::out);
	ac.create_fd();
	f1.write((char *) &ac, sizeof(account));
	f1.close();
}

//***************************************************************
//    	function to calculate fixed deposit
//****************************************************************

void calc_fd(int r)
{
	int amt;
	int found=0;
	account ac;
	fstream f3;
	f3.open("account1.dat", ios::binary|ios::in|ios::out);
	if(!f3)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(f3.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retfd_no()==r)
		{
			ac.show_fd();
			{
				cout<<"\n\n\tTO CALCULATE FIXED DEPOSIT ";
				ac.calculate();
			}
			int pos=(-1)* sizeof(ac);
			f3.seekp(pos,ios::cur);
			f3.write((char *) &ac, sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=1;
	       }
	 }
    f3.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}

//***************************************************************
//    	function to delete record of file    (fixed deposit)
//****************************************************************

void delete_fd(int r)
{
	account ac;
	fstream f2;
	fstream f1;
	f2.open("account1.dat",ios::binary|ios::in|ios::out);
	if(!f2)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	f1.open("Temp1.dat",ios::binary|ios::in|ios::out);

	while(f2.read((char *) &ac, sizeof(account)))
	{
		if(ac.retfd_no()!=r)
		{
			f1.write((char *) &ac, sizeof(account));
		}
	}
    f2.close();
	f1.close();
	remove("account1.dat");
	rename("Temp1.dat","account1.dat");
	cout<<"\n\n\tRecord Deleted ..";
}

//***************************************************************
//    	function to modify record of file   (fixed deposit)
//****************************************************************

void modify_fixed(int r)
{
	int found=0;
	account ac;
	fstream f3;
	f3.open("account1.dat",ios::binary|ios::in|ios::out);
	if(!f3)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(f3.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retfd_no()==r)
		{
			ac.show_fd();
			cout<<"\n\nEnter The New Details of Fixed Deposit Account:-"<<endl;
			ac.modify_fd();
			int pos=(-1)*sizeof(account);
			f3.seekp(pos,ios::cur);
		    f3.write((char *) &ac, sizeof(account));
		    cout<<"\n\n\t Record Updated";
		    found=1;
		  }
	}
	f3.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}

//***************************************************************
//                   introductory function
//***************************************************************

void intro()
{
	cout<<"\n\n\n\n\n\n\n";
	cout<<"-------------------------------------------------------------------------------";
	cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  BANK <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
	cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  MANAGEMENT  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
	cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  SYSTEM  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
	cout<<"\n-------------------------------------------------------------------------------";
	getch();
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
