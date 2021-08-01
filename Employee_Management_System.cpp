// Employee Management System With File Handling in C++.
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<fstream>
#include<windows.h>
using namespace std;
class emp
{
	public:
		int emp_id,sal,group_id;
		string name,address;
		void menu();
		void insert();
		void display();
		void search();
		void modify();
		void del();
		void group();
		void search_group();
		void show_group();
		void check_attendence();
		void search_attendence();
};
class child : public emp
{
	public:
		void login();
		void main_menu();
		void child_menu();
		void attendence();
}obj;

	void intro()
	{
		
		cout<<"\n\n\n\n\n\n\n";
		cout<<"\t\t\t==============================";
		cout<<"\n\t\t\t==============================";
		cout<<"\n\n\t\t\t  Employee Management System";
		cout<<"\n\n\t\t\t==============================";
		cout<<"\n\t\t\t==============================";
		getch();
		system("cls");
		
	}
	void child::login()
	{
		system("cls");
		char ch;
		string user,pass;
		cout<<"\n\n\n\n\n";
		cout<<"\t\t\t==============================";
		cout<<"\n\n\t\t\t\tLogin Process";
		cout<<"\n\n\t\t\t==============================";
		cout<<"\n\n\n Enter User Name : ";
		cin>>user;
		cout<<"\n\n Enter Password : ";
		for(int i=1;i<=6;i++)
		{
			ch = getch();
			pass += ch;
			cout<<"*";
		}
		getch();
		if(user == "admin" && pass == "admin1")
		{
			cout<<"\n\n\n\t\t\tCongratulation Login Successfully...";
			cout<<"\n\n\n\t\t\t\t\tLoading";
			for(int i=1;i<=5;i++)
			{
				Sleep(500);
				cout<<".";
			}
			emp::menu();
		}
		else
		{
			cout<<"\n\n\n User Name or Password Wrong....";
			getch();
			login();
		}
	}
	void child::main_menu()
	{
		int choice;
		system("cls");
		// cout<<"\n\n\t\t\t======================";
		// cout<<"\n\n\t\t\t     ";
		// cout<<"\n\n\t\t\t======================";
		cout<<"\n\n 1. Admin";
		cout<<"\n 2. Employee";
		cout<<"\n 3. Exit";
		cout<<"\n\n Enter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				login();
				break;
			case 2:
				child_menu();
				break;
			case 3:
				exit(0);
			default:
				cout<<"\n\n Invalid Value...Please Try Again...";
		}
		getch();
		main_menu();
	}
	void child::child_menu()
	{
		int choice;
		system("cls");
		// cout<<"\n\n\t\t\t======================";
		// cout<<"\n\n\t\t\t   Child Control Panel";
		// cout<<"\n\n\t\t\t======================";
		cout<<"\n\n 1. Attendence";
		cout<<"\n 2. Check Details";
		cout<<"\n 3. Go Back";
		cout<<"\n\n Enter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				attendence();
				break;
			case 2:
				emp::search();
				break;
			case 3:
				main_menu();
			default:
				cout<<"\n\n Invalid Value...Please Try Again...";
		}
		getch();
		child_menu();
	}
	void emp::menu()
	{
		p:
		system("cls");
		int x;
		cout<<"\n\n\t\t\t======================";
		cout<<"\n\n\t\t\t  Admin Control Panel";
		cout<<"\n\n\t\t\t======================";
		cout<<"\n\n\n 1. Insert Record";
		cout<<"\n 2. Display Record";
		cout<<"\n 3. Check Attendence";
		cout<<"\n 4. Search Attendence";
		cout<<"\n 5. Search Record";
		cout<<"\n 6. Modify Record";
		cout<<"\n 7. Delete Record";
		cout<<"\n 8. Group Record";
		cout<<"\n 9. Search Group";
		cout<<"\n 10. Show All Groups";
		cout<<"\n 11. Go Back";
		cout<<"\n\n Your Choice : ";
		cin>>x;
		switch(x)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				check_attendence();
				break;
			case 4:
				search_attendence();
				break;
			case 5:
				search();
				break;
			case 6:
				modify();
				break;
			case 7:
				del();
				break;
			case 8:
				group();
				break;
			case 9:
				search_group();
				break;
			case 10:
				show_group();
				break;
			case 11:
				obj.main_menu();
			default:
				cout<<"\n\n Invalid Value...Please try Again...";
		}
		getch();
		goto p;
	}
	void child::attendence()
	{
		system("cls");
		fstream file;    //file pointer
		int test_id,found=0,a_date,a_month,a_year,t_id,count=0;
		SYSTEMTIME x;    //cur time
		cout<<"\n\n\t\t\tEmployee Attendence";
		file.open("emp.txt",ios::in);   
		if(!file)
		{
			cout<<"\n\n File Opening Error....";
		}
		else
		{
			cout<<"\n\n Employee ID : ";
			cin>>test_id;
			file>>emp_id>>name>>sal>>address>>group_id;
			while(!file.eof())    //traversing file
			{
				if(test_id == emp_id)   //found given test_id
				{
					found++;
				}
				file>>emp_id>>name>>sal>>address>>group_id;
			}
			file.close();
			if(found > 0)
			{
				GetSystemTime(&x);   //gives current time
				file.open("attendence.txt",ios::in);
				if(!file)
				{
					file.open("attendence.txt",ios::app|ios::out);
					file<<" "<<test_id<<" "<<x.wDay<<" "<<x.wMonth<<" "<<x.wYear<<"\n";
					file.close();
					cout<<"\n\n Your Attendence Added Successfully...";
				}
				else
				{
					file>>t_id>>a_date>>a_month>>a_year;
					while(!file.eof())
					{
						if(test_id == t_id && a_date == x.wDay && a_month == x.wMonth && a_year == x.wYear)
						{
							cout<<"\n\n Your Attendence Already Added...";
							count++;
						}
						file>>t_id>>a_date>>a_month>>a_year;
					}
					file.close();
					if(count == 0)
					{
						file.open("attendence.txt",ios::app|ios::out);
						file<<" "<<test_id<<" "<<x.wDay<<" "<<x.wMonth<<" "<<x.wYear<<"\n";
						file.close();
						cout<<"\n\n Your Attendence Added Successfully...";
					}
				}
			}
			else
			{
				cout<<"\n\n Invalid Employee ID....";
			}
		}
	}
	void emp::check_attendence()
	{
		system("cls");
		fstream file,file1;
		int d,m,y,a_date,a_month,a_year,t_id,count=0;
		cout<<"\n\n\t\t\tCheck Employee Attendence";
		file.open("emp.txt",ios::in);
		file1.open("attendence.txt",ios::in);
		if(!file || !file1)
		{
			cout<<"\n\n File Opening Error...";
		}
		else
		{
			cout<<"\n\n Date : ";
			cin>>d;
			cout<<"\n Month : ";
			cin>>m;
			cout<<"\n Year : ";
			cin>>y;
			file1.close();
			system("cls");
			cout<<"\n\n\t\t\tCheck Employee Attendence";
			cout<<"\n\n Employee ID\tPresents\tAbsents";
			file>>emp_id>>name>>sal>>address>>group_id;
			while(!file.eof())
			{
				file1.open("attendence.txt",ios::in);
				file1>>t_id>>a_date>>a_month>>a_year;
				while(!file1.eof())
				{
					if(emp_id == t_id && d <= a_date && m == a_month && y == a_year)
					{
						count++;
					}
					file1>>t_id>>a_date>>a_month>>a_year;
				}
				file1.close();
				cout<<"\n "<<emp_id<<"\t\t"<<count<<"\t\t"<<30-count;
				count=0;
				file>>emp_id>>name>>sal>>address>>group_id;
			}
			file.close();
		}
	}
	void emp::search_attendence()
	{
		system("cls");
		fstream file,file1;
		int d,m,y,a_date,a_month,a_year,t_id,count=0;
		cout<<"\n\n\t\t\tCheck Employee Attendence";
		file.open("emp.txt",ios::in);
		file1.open("attendence.txt",ios::in);
		if(!file || !file1)
		{
			cout<<"\n\n File Opening Error...";
		}
		else
		{
			cout<<"\n\n Employee ID : ";
			cin>>emp_id;
			cout<<"\n Date : ";
			cin>>d;
			cout<<"\n Month : ";
			cin>>m;
			cout<<"\n Year : ";
			cin>>y;
			file.close();
			system("cls");
			cout<<"\n\n\t\t\tCheck Employee Attendence";
			file1>>t_id>>a_date>>a_month>>a_year;
			while(!file1.eof())
			{
				if(emp_id == t_id && d <= a_date && m == a_month && y == a_year)
				{
					count++;
				}
				file1>>t_id>>a_date>>a_month>>a_year;
			}
			file1.close();
			if(count > 0)
			{
				cout<<"\n\n Employee ID\tPresents\tAbsents";
				cout<<"\n "<<emp_id<<"\t\t"<<count<<"\t\t"<<30-count;	
			}
			else
			{
				cout<<"\n\n Employee ID Not Found...";
			}
		}
	}
	void emp::insert()
	{
		system("cls");
		int test_id,found=0;
		fstream file,file1;
		cout<<"\n\n\t\t\t\tInsert Record";
		cout<<"\n\n\n Employee ID : ";
		cin>>emp_id;
		cout<<"\n\n\nEmployee Name : ";
		cin>>name;
		cout<<"\n\n\nEmployee Sallary : ";
		cin>>sal;
		cout<<"\n\n\nEmployee Address : ";
		cin>>address;
		cout<<"\n\n\nEmployee Group ID : ";
		cin>>group_id;
		file.open("emp.txt",ios::out|ios::app);   //details of employee
		file<<" "<<emp_id<<" "<<name<<" "<<sal<<" "<<address<<" "<<group_id<<"\n";
		file.close();
		file1.open("group.txt",ios::out|ios::app);  //group wise details
		file1<<" "<<group_id<<" "<<emp_id<<" "<<sal<<"\n";
		file1.close();
		file.open("groupid.txt",ios::in);          //storing groupids
		if(!file)
		{
			file1.open("groupid.txt",ios::app|ios::out);
			file1<<" "<<group_id<<"\n";
			file1.close();
		}
		else
		{
			file>>test_id;
			while(!file.eof())
			{
				if(test_id == group_id)
				found++;
				file>>test_id;
			}
			file.close();
			if(found == 0)
			{
				file1.open("groupid.txt",ios::app|ios::out);
				file1<<" "<<group_id<<"\n";
				file1.close();
			}
		}
		cout<<"\n\n\n\t\t\tNew Record Inserted Successfully...";
	}
	void emp::display()  //display all the details of employee
	{
		system("cls");
		fstream file;
		cout<<"\n\n\t\t\t\tDisplay Record";
		file.open("emp.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
			getch();
			menu();
		}
		file>>emp_id>>name>>sal>>address>>group_id;
		while(!file.eof())
		{
			cout<<"\n\n\n\n Employee ID : "<<emp_id;
			cout<<"\n\n\t\tEmployee Name : "<<name;
			cout<<"\n\n Employee Salary : "<<sal;
			cout<<"\n\n\t\tEmloyee Address : "<<address;
			cout<<"\n\n Group ID : "<<group_id;
			file>>emp_id>>name>>sal>>address>>group_id;
		}
		file.close();
	}
	void emp::search()  //searching employee details by empid
	{
		system("cls");
		fstream file;
		int emp_idd,found=0;
		cout<<"\n\n\t\t\t\tSearch Record";
		file.open("emp.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
		}
		else
		{
			cout<<"\n\n Employee ID For Search : ";
			cin>>emp_idd;
			file>>emp_id>>name>>sal>>address>>group_id;
			
			while(!file.eof())
			{
				if(emp_idd == emp_id)
				{
				system("cls");
				cout<<"\n\nSearch Record";
				cout<<"\n\nEmployee ID : "<<emp_id;
				cout<<"\n\nEmployee Name : "<<name;
				cout<<"\n\nEmployee Salary : "<<sal;
				cout<<"\n\nEmloyee Address : "<<address;
				cout<<"\n\n Group ID : "<<group_id;
				found++;
				}
				file>>emp_id>>name>>sal>>address>>group_id;
			}
			file.close();
			if(found == 0)
			cout<<"\n\n Employee ID Can't Found...";
		}
	}
	void emp::modify()  //modifying existing details
	{
		system("cls");
		int sall,test_id,found=0;
		string name1,address1;
		fstream file,file1,file2,file3;
		cout<<"\n\n\t\t\t\tModify Record";
		file.open("emp.txt",ios::in);    //for reading
		
		if(!file || !file1)
		{
			cout<<"\n\n File Openning Error...";
			getch();
			menu();
		}
		cout<<"\n\n Employee ID For Modify : ";
		cin>>test_id;
		file2.open("emp1.txt",ios::app|ios::out); //for writing
		file>>emp_id>>name>>sal>>address>>group_id;
		while(!file.eof())
		{
			if(test_id == emp_id)
			{
				system("cls");
				cout<<"\n\n\t\t\t\tModify Record";
				cout<<"\n\n\n Employee Name : ";
				cin>>name1;
				cout<<"\n\n\t\tEmployee Salary : ";
				cin>>sall;
				cout<<"\n\n Employee Address : ";
				cin>>address1;
				file2<<" "<<emp_id<<" "<<name1<<" "<<sall<<" "<<address1<<" "<<group_id<<"\n";
				found++;
			}
			else
			{
				file2<<" "<<emp_id<<" "<<name<<" "<<sal<<" "<<address<<" "<<group_id<<"\n";
			}
			file>>emp_id>>name>>sal>>address>>group_id;
		}
		file.close();
		file2.close();
		remove("emp.txt");
		rename("emp1.txt","emp.txt");
		file1.open("group.txt",ios::in);
		file3.open("group1.txt",ios::app|ios::out);
		file1>>group_id>>emp_id>>sal;
		while(!file1.eof())
		{
			if(test_id == emp_id)
				file3<<" "<<group_id<<" "<<emp_id<<" "<<sall<<"\n";  //modifying salary
			else
				file3<<" "<<group_id<<" "<<emp_id<<" "<<sal<<"\n"; 
			file1>>group_id>>emp_id>>sal;
		}
		file1.close();
		file3.close();
		remove("group.txt");
		rename("group1.txt","group.txt");
		if(found == 0)
		cout<<"\n\n Employee ID Can't Found...";
		else
		cout<<"\n\n\t\t\t Record Modify Successfully...";
	}
	void emp::del()
	{
		system("cls");
		int test_id,found=0;
		fstream file,file1,file2,file3;
		cout<<"\n\n\t\t\t\tDelete Record";
		file.open("emp.txt",ios::in);
		
		if(!file || !file1)
		{
			cout<<"\n\n File Openning Error...";
			getch();
			menu();
		}
		cout<<"\n\n Employee ID For Delete : ";
		cin>>test_id;
		file2.open("emp1.txt",ios::app|ios::out);
		file>>emp_id>>name>>sal>>address>>group_id;
		while(!file.eof())
		{
			if(test_id == emp_id)
			{
				cout<<"\n\n Record Deleted Successfully...";
				found++;
			}
			else
			{
				file2<<" "<<emp_id<<" "<<name<<" "<<sal<<" "<<address<<" "<<group_id<<"\n";
			}
			file>>emp_id>>name>>sal>>address>>group_id;
		}
		file.close();
		file2.close();
		remove("emp.txt");
		rename("emp1.txt","emp.txt");
		file1.open("group.txt",ios::in);
		file3.open("group1.txt",ios::app|ios::out);
		file1>>group_id>>emp_id>>sal;
		while(!file1.eof())
		{
			if(test_id != emp_id)
				file3<<" "<<group_id<<" "<<emp_id<<" "<<sal<<"\n";
			file1>>group_id>>emp_id>>sal;
		}
		file1.close();
		file3.close();
		remove("group.txt");
		rename("group1.txt","group.txt");
		if(found == 0)
		cout<<"\n\n Employee ID Can't Found...";
	}
	void emp::group()   //displaying details of group file
	{
		system("cls");
		fstream file;
		cout<<"\n\n\t\t\t\tGroup Record";
		file.open("group.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
			getch();
			menu();
		}
		file>>group_id>>emp_id>>sal;
		while(!file.eof())
		{
			cout<<"\n\nGroup ID : "<<group_id;
			cout<<"\n\nEmployee ID : "<<emp_id;
			cout<<"\n\nEmployee Salary : "<<sal;
			file>>group_id>>emp_id>>sal;
		}
		file.close();
	}
	void emp::search_group() //print details of given group id
	{
		system("cls");
		int test_id,found=0,emp_count=0,sal_count=0;
		fstream file;
		cout<<"\n\n\t\t\t\tSearch Group Record";
		file.open("group.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
			getch();
			menu();
		}
		cout<<"\n\n Group ID For Search : ";
		cin>>test_id;
		system("cls");
		cout<<"\n\n\t\t\t\tSearch Group Record";
		file>>group_id>>emp_id>>sal;
		while(!file.eof())
		{
			if(test_id == group_id)
			{
				cout<<"\n\n\n Group ID : "<<group_id;
				cout<<"\n\n\t\tEmployee ID : "<<emp_id;
				cout<<"\n\n Employee Salary : "<<sal;
				found++;
				emp_count++;  
				sal_count = sal_count + sal;
			}
			file>>group_id>>emp_id>>sal;
		}
		file.close();
		if(found != 0)
		{
			cout<<"\n\n\n Group ID : "<<test_id;
			cout<<"\n\n\t\tTotal Employee : "<<emp_count;
			cout<<"\n\n Total Salary : "<<sal_count;
		}
		else
		cout<<"\n\n Group ID Can't Found...";
	}
	void emp::show_group()
	{
		system("cls");
		int test_id,emp_count=0,sal_count=0,emp_total=0,sal_total=0;
		fstream file,file1;
		cout<<"\n\n\t\t\t\tShow All Groups";
		file.open("groupid.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
			getch();
			menu();
		}
		file>>test_id;
		while(!file.eof())
		{
			file1.open("group.txt",ios::in);
			file1>>group_id>>emp_id>>sal;
			while(!file1.eof())
			{
				if(test_id == group_id)
				{
					emp_count++;
					sal_count += sal;
					emp_total++;
					sal_total += sal;
				}
				file1>>group_id>>emp_id>>sal;
			}
			file1.close();
			cout<<"\n\nGroup ID : "<<test_id;
			cout<<"\n\nTotal Employee : "<<emp_count;
			cout<<"\n\nTotal Salary : "<<sal_count;
			emp_count=0;
			sal_count=0;
			file>>test_id;
		}
		file.close();
		cout<<"\n\n\n\n Over All Employee : "<<emp_total;
		cout<<"\n\n\t\tOver All Salary : "<<sal_total;
	}
int main()
{
	intro();
	obj.main_menu();
}
