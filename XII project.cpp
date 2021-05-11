#include <iostream>
using namespace std;
#include <fstream>
#include<string.h>
#include <stdio.h>
#include <conio.h>
#include<cstdlib>
class movie
{	
	public:
	void graph();
	void mov1();
	void mov2();
	void mov3();
	void GuestMenu();
	void MainMenu();
	void Login();
	void BuyTicket();
	void UpdateMovies();
	void UpdateMovieOption(int i);
	void UpdateMovieActual(int i);
	void UpdatePassword();
	void CheckSeat(int , int );
	void ReserveSeat(int , int );
	void DisplayHeader();
	void Viewlayout();
	void DisplayScreen(int);
	void DisplayTicket(int,int,int,int);
	void date(int a[]);
	void checkrc(int , int ,int , int);
}m;
int AccessAllowed;
int mn, t,flag=0,fl;
int nCommand, nAccessLevel = 0;
char su[20], sPassword[8];
int g[3]={'0','0','0'},dt[3],endt[3];//g-count of people

int main()
{
	system(" color E0");
	m.DisplayHeader();
	cout << "  [1] Log In" << endl;
	cout << "  [2] Movie ratings" << endl;
	cout << "  [3] Theatre Layout" << endl;
	cout << "  [4] Exit Application"<<endl;
	
	cout << endl;
	cout << " Please select your comamnd: ";
	cin >> nCommand;
	switch (nCommand)
	{
		case 1:
			cout<<"enter today's date (format:dd_mm_yy)\n";
			for(int i=0;i<3;i++)
			cin>>dt[i];
			m.Login();
			main();
		case 2:
			m. graph();
		    main();
		case 3:
			m.Viewlayout();
		    main();
		case 4:
			exit(0);
		default:
			cout<<"enter valid number\n";
			system("pause");
			main();
	}
}
void movie::Login()
{
	DisplayHeader();
	cout << "  Enter your login details."<<endl;
	cout << "  If logging in as a guest, type Guest as the username."<<endl;
	cout << "  If logging in as a admin, type Admin as the username."<<endl;
	cout << "  Username: ";
	cin >> su;
	
	if (strcmpi(su,"guest")==0)	// If username is Guest
	{
		cout << " Logging in as a guest..." <<endl;
		cout << " ";
		system("pause");
		GuestMenu();
	}
	else if(strcmpi(su,"admin")==0) // If username is Admin
	{
		AccessAllowed =0;
		nAccessLevel =2;
		cout << "  Password: ";
		cin >> sPassword;
		fstream p;
		p.open("pw.txt",ios::in);
		int pos=p.tellp();
		char pw[10];
		p>>pw;
		if (p==0)
		AccessAllowed = 1;
		if (strcmp(sPassword,pw)==0)
			AccessAllowed = 1;
		if (AccessAllowed == 1)
		{
			cout << " Login successful." << endl;
			MainMenu();
		}
		else
		{
			cout << " Invalid username and/or password." << endl;
			cout << "  "; system("pause");
		}
		
	}
}	
void movie::GuestMenu()
{
	DisplayHeader();
	cout << "  [1] Buy ticket" << endl;			
	cout << "  [2] Log out" << endl;
	cout << endl;
	cout << "  Enter your command: ";
	cin >> nCommand;
	switch (nCommand)
	{
		case 1:
			BuyTicket();
			break;
		case 2:
			return;
		default:
			break;
	}
	GuestMenu();
}

void movie::MainMenu()
{
	DisplayHeader();
	cout << "  [1] Ticket Reservation"<<endl;
	cout << "  [2] Update Movies"<<endl;
	cout << "  [3] Change Password"<<endl;
	cout << "  [4] Log Out"<<endl;
	cout << endl << "  Please select your comamnd: ";
	cin >> nCommand;
	switch (nCommand)
	{
		case 1:
			GuestMenu();
			break;
		case 2:
			UpdateMovies();
			break;
		case 3:
			UpdatePassword();
			break;
		case 4:
			return;
		default:
			MainMenu();
	}
	MainMenu();
}
void movie::BuyTicket()
{
	fstream a;
	int prg,prs;
	char title[30];
	DisplayHeader();
	ifstream Reader[3];
	cout<<"booking available on following days\n\n";
	date(&dt[3]);
	/*cout<<dt[0]<<"/"<<dt[1]<<"/"<<dt[2]<<"\t";
	cout<<dt[0]+1<<"/"<<dt[1]<<"/"<<dt[2]<<"\t\n\n";*/
	
	
	Reader[0].open("M1Movie.txt");
	if (Reader[0])
	{	
		Reader[0].getline(title,30);
		cout << "  [1] Cinema 1: " << title << endl;
		Reader[0]>>prg;
		Reader[0]>>prs;
		cout<<"\t GOLD price :"<<prg<<endl;
		cout<<"\t SILVER price :"<<prs<<endl;
	}
	else
	cout << "  [1] Cinema 1: NO MOVIE" << endl;
	Reader[0].close();

	Reader[1].open("M2Movie.txt");
	if (Reader[1])
	{
		Reader[1].getline(title,30);
		cout << "  [2] Cinema 2: " << title << endl;
		Reader[1]>>prg;
		Reader[1]>>prs;
		cout<<"\t GOLD price :"<<prg<<endl;
		cout<<"\t SILVER price :"<<prs<<endl;
	}
	else
	cout << "  [2] Cinema 2: NO MOVIE" << endl;
	Reader[1].close();

	Reader[2].open("M3Movie.txt");
	if (Reader[2])
	{
		Reader[2].getline(title,30);
		cout << "  [3] Cinema 3: " << title << endl;
		Reader[2]>>prg;
		Reader[2]>>prs;
		cout<<"\t GOLD price :"<<prg<<endl;
		cout<<"\t SILVER price :"<<prs<<endl;
	}
	else
	cout << "  [3] Cinema 3: NO MOVIE" << endl;
	Reader[2].close();
	
	cout<<"Enter movie number\n";
	cin>>mn;
	switch(mn)
	{
		case 1:
			mov1();
			break;
		case 2:
			mov2();
			break;
		case 3:
			mov3();
			break;
		default:
			break;
	}
}
void movie::date(int a[])
{
	cout<<dt[0]<<"/"<<dt[1]<<"/"<<dt[2]<<"\t";
	switch(dt[1])
	{
		case 1:	case 3:	case 5:case 7:
		case 8:	case 10:case 12:
		if(dt[0]==31)
		{
			dt[0]=0;dt[1]++;
		}
		if(dt[1]==13)
		{
			dt[1]=1;
			dt[2]++;
		}	
		break;		
	
		case 4:	case 6:	case 9:case 11:
		if(dt[0]==30)
		{
			dt[0]=0;dt[1]++;
		}
		break;
		case 2:
		if(dt[2]%4==0)
		{
			if(dt[0]==29)
			{
				dt[0]=0;dt[1]++;
		 	}
		}
		else
		{
			if(dt[0]==28)
			{
				dt[0]=0;dt[1]++;
			}
		}	
	}
	
	cout<<dt[0]+1<<"/"<<dt[1]<<"/"<<dt[2]<<"\t\n\n";
}
void movie::mov1()
{
	DisplayHeader();
	cout<<"*********TIMINGS**********\n";
	cout<<"\n1. 9-12\n";
	cout<<"\n2. 1-4\n";
	cout<<"\n3. 6-9\n";
	cout<<"Enter the timings number\n";
	cin>>t;
	if(t>0&&t<4)
  	CheckSeat(mn,t);	
  	else 
  	{
	  	cout<<"invalid choice\n";
	  	system("pause");
	  	return;
  	}
}
void movie::mov2()
{
	DisplayHeader();
	cout<<"*********TIMINGS**********\n";
	cout<<"\n1. 8-11\n";
	cout<<"\n2. 12-3\n";
	cout<<"\n3. 6-9\n";
	cout<<"enter the timing number\n";
	cin>>t;
	if(t>0&&t<4)
  	CheckSeat(mn,t);	
    else 
    {
  		cout<<"invalid choice\n";
  		system("pause");
  		return;
    }
  	
}
void movie::mov3()
{
	DisplayHeader();
	cout<<"*********TIMINGS**********\n";
	cout<<"\n1. 8:30-11:30\n";
	cout<<"\n2. 11:45-3:45\n";
	cout<<"\n3. 5:30-8:30\n";
	cout<<"enter the timing number\n";
	cin>>t;
    if(t>0&&t<4)
  	CheckSeat(mn,t);	
    else 
	{
	 	cout<<"invalid choice\n";
		system("pause");
	 	return;
	}		
}
void movie::CheckSeat(int x,int y)
{	
	char m1[11][8]={'G','*','*','*',' ','*','*','*',
 					'O','*','*','*',' ','*','*','*',
  	 	     		'L','*','*','*',' ','*','*','*',
				    'D','*','*','*',' ','*','*','*',
                    ' ',' ',' ',' ',' ',' ',' ',' ',
    				'S','*','*','*',' ','*','*','*',
        			'I','*','*','*',' ','*','*','*',
                    'L','*','*','*',' ','*','*','*',
			        'V','*','*','*',' ','*','*','*',
                    'E','*','*','*',' ','*','*','*',
					'R','*','*','*',' ','*','*','*'};
					
	char m2[6][14]={'G','*','*','*','*','*','*',' ','*','*','*','*','*','*',
					'G','*','*','*','*','*','*',' ','*','*','*','*','*','*',
					' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
					'S','*','*','*','*','*','*',' ','*','*','*','*','*','*',
					'S','*','*','*','*','*','*',' ','*','*','*','*','*','*',
					'S','*','*','*','*','*','*',' ','*','*','*','*','*','*'};
					
    char m3[11][15]={'G','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					'O','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					'L','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					'D','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
					'S','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					'I','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					'L','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					'V','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					'E','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					'R','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*'};
									
	cout<<"Enter the date on which u want to book ticket\n";
	for(int i=0;i<1;i++)
	cin>>endt[i];
	int r,c;
	int a[18]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	cout<<"hi there u r checking ur seat\n";
	fstream s[18];
	s[0].open("Seatm111.txt",ios::in);//date mov time(111)
	s[1].open("Seatm112.txt",ios::in);
	s[2].open("Seatm113.txt",ios::in);
	s[3].open("Seatm121.txt",ios::in);
	s[4].open("Seatm122.txt",ios::in);
	s[5].open("Seatm123.txt",ios::in);
	s[6].open("Seatm131.txt",ios::in);
	s[7].open("Seatm132.txt",ios::in);
	s[8].open("Seatm133.txt",ios::in);
	s[9].open("Seatm211.txt",ios::in);
	s[10].open("Seatm212.txt",ios::in);
	s[11].open("Seatm213.txt",ios::in);
	s[12].open("Seatm221.txt",ios::in);
	s[13].open("Seatm222.txt",ios::in);
	s[14].open("Seatm223.txt",ios::in);
	s[15].open("Seatm231.txt",ios::in);
	s[16].open("Seatm232.txt",ios::in);
	s[17].open("Seatm233.txt",ios::in);
	
	if(endt[0]==dt[0])
	{
		if(mn==1)
		{	
			switch(t)
			{	
				case 1:
				while(s[0])
				{
					s[0]>>r;
					s[0]>>c;
					if(r!=0&&c!=0)
					{
						m1[r-1][c]='#';
						a[0]++;
					}
				}
				break;
				case 2:
				while(s[1])
				{
					s[1]>>r;
					s[1]>>c;
					if(r!=0&&c!=0)
					{
					   m2[r-1][c]='#';
		    		   a[1]++;
					}
				
				}
				break;
				case 3 :
				while(s[2])
				{
					s[2]>>r;
					s[2]>>c;
					if(r!=0&&c!=0)
					{
					    m3[r-1][c]='#';
						a[2]++;
					}
					
				}
				break;
			}
		}
		else if(mn==2)
		{
			switch(t)
			{
				case 1:
				while(s[3])
				{
					s[3]>>r;
					s[3]>>c;
					if(r!=0&&c!=0)
					{
					   m1[r-1][c]='#';
					   a[3]++;
					}
				}
				break;
				case 2:
				while(s[4])
				{
					s[4]>>r;
					s[4]>>c;
					if(r!=0&&c!=0)
					{
						m2[r-1][c]='#';
						a[4]++;
					}				
				}
				break;
				case 3 :
				while(s[5])
				{
					s[5]>>r;
					s[5]>>c;
					if(r!=0&&c!=0)
					{
					   	m3[r-1][c]='#';
						a[5]++;
					}
				}
				break;
			}
		}
		else if(mn==3)
		{
			switch(t)
			{
				case 1:
				while(s[6])
				{
					s[6]>>r;
					s[6]>>c;
					if(r!=0&&c!=0)
					{   
						m1[r-1][c]='#';
						a[6]++;
					}
				}
				break;
				case 2:
				while(s[7])
				{
					s[7]>>r;
					s[7]>>c;
					if(r!=0&&c!=0)
					{   
						m2[r-1][c]='#';
						a[7]++;
					}
				}
				break;
				case 3:
				while(s[8])
				{
					s[8]>>r;
					s[8]>>c;
					if(r!=0&&c!=0)
					{   
						m3[r-1][c]='#';
						a[8]++;
					}
				}
				break;
			 }
	     }
    }
	else if(endt[0]==dt[0]+1)
	{	
		if(mn==1)
  		{	
			switch(t)
			{	
				case 1:
				while(s[9])
				{
					s[9]>>r;
					s[9]>>c;
					if(r!=0&&c!=0)
					{
						m1[r-1][c]='#';
						a[9]++;
					}
				}
				break;
				case 2:
				while(s[10])
				{
					s[10]>>r;
					s[10]>>c;
					if(r!=0&&c!=0)
					{
					   m2[r-1][c]='#';
				    	a[10]++;
					}
				}
				break;
				case 3 :
				while(s[11])
				{
					s[11]>>r;
					s[11]>>c;
					if(r!=0&&c!=0)
					{
					   m3[r-1][c]='#';
						a[11]++;
					}
				}
			}
		}
		else if(mn==2)
		{
			switch(t)
			{
				case 1:
				while(s[12])
				{
					s[12]>>r;
					s[12]>>c;
					if(r!=0&&c!=0)
					{
						 m1[r-1][c]='#';
					     a[12]++;
					}
				}
				break;
				case 2:
				while(s[13])
				{
					s[13]>>r;
					s[13]>>c;
					if(r!=0&&c!=0)
					{
						m2[r-1][c]='#';
						a[13]++;
					}
				}
				break;
				case 3 :
				while(s[14])
				{
					s[14]>>r;
					s[14]>>c;
					if(r!=0&&c!=0)
					{
						m3[r-1][c]='#';
						a[14]++;
					}
				}
				break;
			}
		}
		else if(mn==3)
		{			
			switch(t)
			{
				case 1:
				while(s[15])
				{
					s[15]>>r;
					s[15]>>c;
					if(r!=0&&c!=0)
					{   
						m1[r-1][c]='#';
						a[15]++;
					}
				}
				break;
				case 2:
				while(s[16])
				{
					s[16]>>r;
					s[16]>>c;
					if(r!=0&&c!=0)
					{   
						m2[r-1][c]='#';
						a[16]++;
					}
				}
				break;
				case 3 :
				while(s[17])
				{
					s[17]>>r;
					s[17]>>c;
					if(r!=0&&c!=0)
					{   
						m3[r-1][c]='#';
						a[17]++;
					}
				}
				break;
			}
		}
	}
	else
	{
		cout<<"enter proper date\n";
		system("pause");
		return;
	}
	if(endt[0]==dt[0])
	{
		if(t==1)
		{	
			if(mn==1)
			cout<<"no of vacant seats:\t"<<60-a[0]<<endl;
			else if(mn==2)
			cout<<"no of vacant seats:\t"<<60-a[3]<<endl;
			else if (mn==3)
			cout<<"no of vacant seats:\t"<<60-a[6]<<endl;	
		   	cout<<"   0  1  2  3  4  5  6  7  \n";
			for(int i=0;i<11;i++)
			{	
				if(i<9)
				cout<<" "<<i+1<<" ";
				else
				cout<<i+1<<" ";
				for(int j=0;j<8;j++ )
				cout<<m1[i][j]<<"  ";
				cout<<endl;
			}
		}
		if(t==2)
		{	
			if(mn==1)
			cout<<"no of vacant seats:\t"<<60-a[1]<<endl;
			else if(mn==2)
			cout<<"no of vacant seats:\t"<<60-a[4]<<endl;
			else if (mn==3)
			cout<<"no of vacant seats:\t"<<60-a[7]<<endl;	
			cout<<"  0  1  2  3  4  5  6  7  8  9 10 11 12 13  \n";
			for(int i=0;i<6;i++)
			{
				cout<<i+1<<" ";
				for(int j=0;j<14;j++ )
				cout<<m2[i][j]<<"  ";
				cout<<endl;
			}
		}
		if(t==3)
		{	
			if(mn==1)
			cout<<"no of vacant seats:\t"<<120-a[2]<<endl;
			else if(mn==2)
			cout<<"no of vacant seats:\t"<<120-a[5]<<endl;
			else if (mn==3)
			cout<<"no of vacant seats:\t"<<120-a[8]<<endl;	
			cout<<"   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14\n";
			for(int i=0;i<11;i++)
			{	
				if(i<9)
				cout<<" "<<i+1<<" ";
				else
				cout<<i+1<<" ";
				for(int j=0;j<15;j++ )
				cout<<m3[i][j]<<"  ";
				cout<<endl;
			}
		}
	}
	else if(endt[0]==dt[0]+1)
	{
		if(t==1)
		{
			if(mn==1)
			cout<<"no of vacant seats:\t"<<60-a[9]<<endl;
			else if(mn==2)
			cout<<"no of vacant seats:\t"<<60-a[12]<<endl;
			else if (mn==3)
			cout<<"no of vacant seats:\t"<<60-a[15]<<endl;	
		   	cout<<"   0  1  2  3  4  5  6  7  \n";
			for(int i=0;i<11;i++)
			{	
				if(i<9)
				cout<<" "<<i+1<<" ";
				else
				cout<<i+1<<" ";
				for(int j=0;j<8;j++ )
				cout<<m1[i][j]<<"  ";
				cout<<endl;
			}
		}
		if(t==2)
		{	
			if(mn==1)
			cout<<"no of vacant seats:\t"<<60-a[10]<<endl;
			else if(mn==2)
			cout<<"no of vacant seats:\t"<<60-a[13]<<endl;
			else if (mn==3)
			cout<<"no of vacant seats:\t"<<60-a[16]<<endl;	
			cout<<"  0  1  2  3  4  5  6  7  8  9 10 11 12 13  \n";
			for(int i=0;i<6;i++)
			{
				cout<<i+1<<" ";
				for(int j=0;j<14;j++ )
				cout<<m2[i][j]<<"  ";
				cout<<endl;
			}
		}
		if(t==3)
		{	
			if(mn==1)
			cout<<"no of vacant seats:\t"<<120-a[11]<<endl;
			else if(mn==2)
			cout<<"no of vacant seats:\t"<<120-a[14]<<endl;
			else if (mn==3)
			cout<<"no of vacant seats:\t"<<120-a[17]<<endl;	
			cout<<"   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14\n";
			for(int i=0;i<11;i++)
			{	
				if(i<9)
				cout<<" "<<i+1<<" ";
				else
				cout<<i+1<<" ";
				for(int j=0;j<15;j++ )
				cout<<m3[i][j]<<"  ";
				cout<<endl;
			}
		}
	}
	DisplayScreen(t);	
	 ReserveSeat( mn, t);
	 s[0].close();
	 s[1].close();
     s[2].close();
     s[3].close();
     s[4].close();
	 s[5].close();
     s[6].close();
	 s[7].close();
	 s[8].close();
     s[9].close();
     s[10].close();
	 s[11].close();
     s[12].close();
     s[13].close();
     s[14].close();
	 s[15].close();
	 s[16].close();
	 s[17].close();
}
void movie::checkrc(int a, int b,int mn, int t)
{	int r,c;
	fstream s[18];
	s[0].open("Seatm111.txt",ios::in);//date mov time(111)
	s[1].open("Seatm112.txt",ios::in);
	s[2].open("Seatm113.txt",ios::in);
	s[3].open("Seatm121.txt",ios::in);
	s[4].open("Seatm122.txt",ios::in);
	s[5].open("Seatm123.txt",ios::in);
	s[6].open("Seatm131.txt",ios::in);
	s[7].open("Seatm132.txt",ios::in);
	s[8].open("Seatm133.txt",ios::in);
	s[9].open("Seatm211.txt",ios::in);
	s[10].open("Seatm212.txt",ios::in);
	s[11].open("Seatm213.txt",ios::in);
	s[12].open("Seatm221.txt",ios::in);
	s[13].open("Seatm222.txt",ios::in);
	s[14].open("Seatm223.txt",ios::in);
	s[15].open("Seatm231.txt",ios::in);
	s[16].open("Seatm232.txt",ios::in);
	s[17].open("Seatm233.txt",ios::in);
	fl=0;
	if(endt[0]==dt[0])
		{
			if(mn==1)
			{	
				switch(t)
				{	
					case 1:
					while(s[0])
					{
						s[0]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
					}
					break;
					case 2:
					while(s[1])
					{
						s[1]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
					
					}
					break;
					case 3 :
					while(s[2])
					{
						s[2]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
						
					}
					break;
				}
			}
			else if(mn==2)
			{
				switch(t)
				{
					case 1:
					while(s[3])
					{
						s[3]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
					}
					break;
					case 2:
					while(s[4])
					{
					s[4]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}			
					}
					break;
					case 3 :
					while(s[5])
					{
						s[5]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
					}
					break;
				}
			}
			else if(mn==3)
			{
				switch(t)
				{
					case 1:
					while(s[6])
					{
						s[6]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
					}
					break;
					case 2:
					while(s[7])
					{
						s[7]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
					}
					break;
					case 3:
					while(s[8])
					{
						s[8]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
					}
					break;
				 }
		     }
	    }
		else if(endt[0]==dt[0]+1)
		{	
			if(mn==1)
	  		{	
				switch(t)
				{	
					case 1:
					while(s[9])
					{
						s[9]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
					}
					break;
					case 2:
					while(s[10])
					{
						s[10]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
					}
					break;
					case 3 :
					while(s[11])
					{
						s[11]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
					}
				}
			}
			else if(mn==2)
			{
				switch(t)
				{
					case 1:
					while(s[12])
					{
						s[12]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
					}
					break;
					case 2:
					while(s[13])
					{
						s[13]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
					}
					break;
					case 3 :
					while(s[14])
					{
						s[14]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
					}
					break;
				}
			}
			else if(mn==3)
			{
				
				switch(t)
				{
					case 1:
					while(s[15])
					{
						s[15]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
					}
					break;
					case 2:
					while(s[16])
					{
						s[16]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
					}
					break;
					case 3 :
					while(s[17])
					{
						s[17]>>r>>c;
						if(r==a&&c==b)
						{
							cout<<" Seat Not Available\n";
							fl=1;break;
						}
					}
					break;
				}
			}
		}
}
void movie::ReserveSeat(int mn, int t)
{
	cout<<"*- Available Seats\t#- Booked Seats\n\n";
	fstream s[18];
	int r,c,num,row=0,col=0;
	s[0].open("Seatm111.txt",ios::out|ios::app);//date mov time(111)
	s[1].open("Seatm112.txt",ios::out|ios::app);
	s[2].open("Seatm113.txt",ios::out|ios::app);
	s[3].open("Seatm121.txt",ios::out|ios::app);
	s[4].open("Seatm122.txt",ios::out|ios::app);
	s[5].open("Seatm123.txt",ios::out|ios::app);
	s[6].open("Seatm131.txt",ios::out|ios::app);
	s[7].open("Seatm132.txt",ios::out|ios::app);
	s[8].open("Seatm133.txt",ios::out|ios::app);
	s[9].open("Seatm211.txt",ios::out|ios::app);
	s[10].open("Seatm212.txt",ios::out|ios::app);
	s[11].open("Seatm213.txt",ios::out|ios::app);
	s[12].open("Seatm221.txt",ios::out|ios::app);
	s[13].open("Seatm222.txt",ios::out|ios::app);
	s[14].open("Seatm223.txt",ios::out|ios::app);
	s[15].open("Seatm231.txt",ios::out|ios::app);
	s[16].open("Seatm232.txt",ios::out|ios::app);
	s[17].open("Seatm233.txt",ios::out|ios::app);
	
	if(flag==0)
	{
		s[0]<<row<<endl;
		s[0]<<col<<endl;
		s[1]<<row<<endl;			
		s[1]<<col<<endl;
		s[2]<<row<<endl;			
		s[2]<<col<<endl;
		s[3]<<row<<endl;			
		s[3]<<col<<endl;
		s[4]<<row<<endl;			
		s[4]<<col<<endl;
		s[5]<<row<<endl;			
		s[5]<<col<<endl;
		s[6]<<row<<endl;			
		s[6]<<col<<endl;
		s[7]<<row<<endl;			
		s[7]<<col<<endl;
		s[8]<<row<<endl;			
		s[8]<<col<<endl;
		s[9]<<row<<endl;			
		s[9]<<col<<endl;
		s[10]<<row<<endl;			
		s[10]<<col<<endl;
		s[11]<<row<<endl;			
		s[11]<<col<<endl;
		s[12]<<row<<endl;			
		s[12]<<col<<endl;
		s[13]<<row<<endl;			
		s[13]<<col<<endl;
		s[14]<<row<<endl;			
		s[14]<<col<<endl;
		s[15]<<row<<endl;			
		s[15]<<col<<endl;
		s[16]<<row<<endl;			
		s[16]<<col<<endl;
		s[17]<<row<<endl;			
		s[17]<<col<<endl;
	}
	flag++;
	cout<<"Enter the no of tickets u want to book"<<endl;
	cin>>num;
	for(int k=1;k<=num;k++)
	{
		cout<<endl<<"Enter the row no and coloumn no of the seat u want\n";
		cin>>r>>c;
		checkrc(r,c,mn,t);
		if(fl==1)
		k--;
		if(fl!=1)
		{
		
	
			if(endt[0]==dt[0])
			{
				if(mn==1)
				{
					switch(t)
					{
						case 1:		
						s[0]<<r<<endl;			
						s[0]<<c<<endl;
						break;
						case 2:					
						s[1]<<r<<endl;
						s[1]<<c<<endl;					
						break;
						case 3 :						
						s[2]<<r<<endl;
						s[2]<<c<<endl;					
						break;
					}
					DisplayTicket(mn,t,r,c);	
				}
				else if(mn==2)
				{
					switch(t)
					{
						case 1:				
						s[3]<<r<<endl;
						s[3]<<c<<endl;					
						break;
						case 2:		
						s[4]<<r<<endl;
						s[4]<<c<<endl;			
						break;
						case 3 :
						s[5]<<r<<endl;
						s[5]<<c<<endl;			
						break;				
					}
					DisplayTicket(mn,t,r,c);
				}
				else if(mn==3)
				{
					switch(t)
					{
						case 1:			
						s[6]<<r<<endl;
						s[6]<<c<<endl;				
						break;
						case 2:		
						s[7]<<r<<endl;
						s[7]<<c<<endl;			
						break;
						case 3 :						
						s[8]<<r<<endl;
						s[8]<<c<<endl;	
						break;
					}
					DisplayTicket(mn,t,r,c);
				}	
			}
			if(endt[0]==dt[0]+1)
			{
				if(mn==1)
				{
					switch(t)
					{
						case 1:		
						s[9]<<r<<endl;			
						s[9]<<c<<endl;
						break;
						case 2:					
						s[10]<<r<<endl;
						s[10]<<c<<endl;					
						break;
						case 3 :						
						s[11]<<r<<endl;
						s[11]<<c<<endl;					
						break;
					}
					DisplayTicket(mn,t,r,c);	
				}
				else if(mn==2)
				{
					switch(t)
					{
						case 1:				
						s[12]<<r<<endl;
						s[12]<<c<<endl;					
						break;
						case 2:		
						s[13]<<r<<endl;
						s[13]<<c<<endl;			
						break;
						case 3 :
						s[14]<<r<<endl;
						s[14]<<c<<endl;			
						break;				
					}
					DisplayTicket(mn,t,r,c);
				}
				else if(mn==3)
				{
					switch(t)
					{
						case 1:			
						s[15]<<r<<endl;
						s[15]<<c<<endl;				
						break;
						case 2:		
						s[16]<<r<<endl;
						s[16]<<c<<endl;			
						break;
						case 3 :						
						s[17]<<r<<endl;
						s[17]<<c<<endl;	
						break;
					}
					DisplayTicket(mn,t,r,c);
				}	
			}
	}
}
	cout<<"THANK YOU!!! "<<endl;
     s[0].close();
	 s[1].close();
     s[2].close();
     s[3].close();
     s[4].close();
     s[5].close();
     s[6].close();
     s[7].close();
     s[8].close();
     s[9].close();
	 s[10].close();
	 s[11].close();
     s[12].close();
     s[13].close();
     s[14].close();
	 s[15].close();
	 s[16].close();
	 s[17].close();
		system("pause");
}
void movie::DisplayTicket(int mn,int t,int r,int c)
{
	cout << endl;
	int prg[3],prs[3];
	ifstream reader[3];
	reader[0].open("M1Movie.txt");
	reader[1].open("M2Movie.txt");	
	reader[2].open("M3Movie.txt");
	// Upper Border
		cout << " \xC9";
		for(int i=0;i<76;i++)
		cout << "\xCD";
		cout << "\xBB";
		cout << endl;
		// Middle Border
		cout << " \xBA";
		//      [FROM_HERE                                                            TO_HERE]
		cout << "                                TICKET                                      ";
		cout << "\xBA";
		cout << endl;
		// Middle Border
		cout << " \xBA";
		//      [FROM_HERE                                                            TO_HERE]
		cout << " ========================================================================== ";
		cout << "\xBA";
		cout << endl;
		// Middle Border
		cout << " \xBA";
		//      [FROM_HERE                                                            TO_HERE]
		cout << "                                                                            ";
		cout << "\xBA";
		cout << endl;	
		// Middle Border
		cout << " \xBA";
		
		char name[15];
		if(mn==1)
		reader[0]>>name;
		else if(mn==2)
			reader[1]>>name;
		else if (mn==3)
			reader[2]>>name;
		//      [FROM_HERE                                                             nameTO_HERE]
		cout << "    MOVIE NAME: "<<name<<"                                                     ";                                          
		cout << "\xBA";
		cout << endl;
		
		//TIMINGS
		// Middle Border
		cout << " \xBA";		
		//      [FROM_HERE                                                                    TO_HERE]
		cout << "    TIMINGS: ";
		if(mn==1)
		{
			switch(t)
			{
				case 1:
		//      [FROM_HERE                                                             TO_HERE]
				cout<<" 9-12"<<"                                                          \xBA";
				break;
				case 2:
	    //      [FROM_HERE                                                             TO_HERE]		
				cout<<" 1-4"<<"                                                           \xBA";	
				break;
				case 3:
		//      [FROM_HERE                                                             TO_HERE]		
				cout<<" 6-9"<<"                                                           \xBA";
				break;
			}
		}
		if(mn==2)
		{
			switch(t)
			{
				case 1:
		//      [FROM_HERE                                                             TO_HERE]
				cout<<" 8-11"<<"                                                          \xBA";
				break;
				case 2:
	    //      [FROM_HERE                                                             TO_HERE]		
				cout<<" 12-3"<<"                                                          \xBA";	
				break;
				case 3:
		//      [FROM_HERE                                                             TO_HERE]		
				cout<<" 6-9"<<"                                                           \xBA";
				break;
			}
		}	
		if(mn==3)
		{
			switch(t)
			{
				case 1:
		//      [FROM_HERE                                                             TO_HERE]
				cout<<" 8:30-11:30"<<"                                                    \xBA";
				break;
				case 2:
	    //      [FROM_HERE                                                             TO_HERE]		
				cout<<" 11:45-3:45"<<"                                                    \xBA";	
				break;
				case 3:
		//      [FROM_HERE                                                             TO_HERE]		
				cout<<" 5:30-8:30"<<"                                                     \xBA";
				break;
			}
		}
		cout << endl;
		if(r<9&&c<<9)
		{
				// Middle Border
			cout << " \xBA";
			//      [FROM_HERE                                                                    TO_HERE]
			cout << "    ROW: "<<r <<"                                                                  ";                                          
			cout << "\xBA";
			cout << endl;
			// Middle Border
			cout << " \xBA";
			//      [FROM_HERE                                                                    TO_HERE]
			cout << "    COLUMN: "<<c <<"                                                               ";                                          
			cout << "\xBA";
			cout << endl;
		}
		else
		{
			// Middle Border
			cout << " \xBA";
			//      [FROM_HERE                                                                    TO_HERE]
			cout << "    ROW: "<<r <<"                                                                 ";                                          
			cout << "\xBA";
			cout << endl;
			// Middle Border
			cout << " \xBA";
			//      [FROM_HERE                                                                    TO_HERE]
			cout << "    COLUMN: "<<c <<"                                                              ";                                          
			cout << "\xBA";
			cout << endl;
		}
		// Middle Border
		cout << " \xBA";				
		//      [FROM_HERE                                                                    TO_HERE]
		reader[0]>>prg[0];
		reader[0]>>prs[0];
		reader[1]>>prg[1];
		reader[1]>>prs[1];
		reader[2]>>prg[2];
		reader[2]>>prs[2];
	//mn 1 start
		if(t==1&&r<4 && mn==1)
		cout << "    PRICE: "<< prg[0]<<"                                                 	      ";    
		else if(t==1 && r<11 &&mn==1)       
		cout << "    PRICE: "<< prs[0]<<"                                         		      ";
		if(t==2&&r<2 && mn==1)
		cout << "    PRICE: "<< prg[0]<<"                                                 	      ";    
		else if(t==2&& r<6 && mn==1)       
		cout << "    PRICE: "<< prs[0]<<"                                         		      ";
		if(t==3&&r<4&&mn==1)
		cout << "    PRICE: "<< prg[0]<<"                                                 	      ";    
		else if(t==3&&r<11&&mn==1)       
		cout << "    PRICE: "<< prs[0]<<"                                         		      ";                                   
	//mn 2 start
	   	else if(t==1&&r<4 && mn==2)
		cout << "    PRICE: "<< prg[1]<<"                                                 	      ";    
		else if(t==1 && r<11 &&mn==2)       
		cout << "    PRICE: "<<prs[1]<<"                                         		      ";
		if(t==2&&r<2 && mn==2)
		cout << "    PRICE: "<< prg[1]<<"                                                 	      ";    
		else if(t==2 && r<6 &&mn==2)       
		cout << "    PRICE: "<<prs[1]<<"                                         		      ";
		if(t==3&&r<4 && mn==2)
		cout << "    PRICE: "<< prg[1]<<"                                                 	      ";    
		else if(t==3 && r<11 &&mn==2)       
		cout << "    PRICE: "<<prs[1]<<"                                         		      "; 
	//mn 3 starts
		else if(t==1&&r<4 && mn==3)
		cout << "    PRICE: "<<prg[2]<<"	    	               	                              ";    
		else if(t==1 && r<11 &&mn==3)       
		cout << "    PRICE: "<<prs[2]<<"                        	                 	      ";
		if(t==2&&r<2 && mn==3)
		cout << "    PRICE: "<<prg[2]<<"	     	                                              ";    
		else if(t==2 && r<6 &&mn==3)       
		cout << "    PRICE: "<<prs[2]<<"                                         		      ";
		if(t==3&&r<4 && mn==3)
		cout << "    PRICE: "<<prg[2]<<"	   	                                              ";    
		else if(t==3 && r<11 &&mn==3)       	
		cout << "    PRICE: "<<prs[2]<<"                                         		      "; 
		cout << "\xBA";
		cout << endl;
		// Middle Border
		cout << " \xBA";
		//      [FROM_HERE                                                            TO_HERE]
		cout << "                                                                            ";
		cout << "\xBA";
		cout << endl;
		// Middle Border
		cout << " \xBA";
		//      [FROM_HERE                                                            TO_HERE]
		cout << "                       Booking Successfully Done!!!                         ";
		cout << "\xBA";
		cout << endl;
	// Upper Border
		cout << " \xC8";
		for(int i=0;i<76;i++)
			cout << "\xCD";
		cout << "\xBC";
	   cout << endl;
}
void movie::UpdateMovies()
{
	DisplayHeader();
	char title[30];
	ifstream Reader[3];
	cout << "  [0] -Cancel-" << endl;
	Reader[0].open("M1Movie.txt");
	if (Reader[0])
	{
		Reader[0].getline(title,30);
		cout << "  [1] Cinema 1: " << title << endl;
	}
	else
		cout << "  [1] Cinema 1: NO MOVIE" << endl;
	Reader[0].close();

	Reader[1].open("M2Movie.txt");
	if (Reader[1])
	{
		Reader[1].getline(title,30);
		cout << "  [2] Cinema 2: " << title << endl;
	}
	else
		cout << "  [2] Cinema 2: NO MOVIE" << endl;
	Reader[1].close();

	Reader[2].open("M3Movie.txt");
	if (Reader[2])
	{
		Reader[2].getline(title,30);
		cout << "  [3] Cinema 3: " << title << endl;
	}
	else
		cout << "  [3] Cinema 3: NO MOVIE" << endl;
	Reader[2].close();
	cout << "  Select which movie you want to update: ";
	int n;
	cin >> n;
	switch (n)
	{
		case 1:
			UpdateMovieOption(n);
			break;
		case 2:
			UpdateMovieOption(n);
			break;
		case 3:
			UpdateMovieOption(n);
			break;
		case 0:
			return;
		default:
			UpdateMovies();
	}
	UpdateMovies();
}
void movie::UpdateMovieOption(int i)
{
	ifstream Reader;
	switch (i)
	{
		case 1:
			Reader.open("M1Movie.txt");
			break;
		case 2:
			Reader.open("M2Movie.txt");
			break;
		case 3:
			Reader.open("M3Movie.txt");
			break;
		default:
			break;
	}
	DisplayHeader();
	if (Reader)
	{
		char title[30];
		Reader.getline(title,30);
		Reader.close();
		cout << "  Movie title: " << title << endl;
		cout << "  [1] Update Movie" << endl;
		cout << "  [2] Back" << endl;
		cout << endl << "  Please enter your command: ";
		int j;
		cin >> j;
		switch (j)
		{
			case 1:
			UpdateMovieActual(i);
			return;
			case 2:
			return;
		}
		UpdateMovieOption(i);
	}
	else
	{
		cout << "  [1] Add Movie" << endl;
		cout << "  [2] Back" << endl;
		cout << endl;
		cout << "  Please enter your command: ";
		int j;
		cin >> j;
		switch (j)
		{
		case 1:
			UpdateMovieActual(i);
			return;
		case 2:
			return;
		default:
			UpdateMovieOption(i);
		}
		UpdateMovieOption(i);
	}
}
void movie::UpdateMovieActual(int i)
{
	ofstream Writer;
	switch (i)
	{
		case 1:
			Writer.open("M1Movie.txt");
			break;
		case 2:
			Writer.open("M2Movie.txt");
			break;
		case 3:
			Writer.open("M3Movie.txt");
			break;
		default:
			cout << "  ERROR: Invalid movie number." << endl;
			cout << "  "; system("pause");
	}	
	DisplayHeader();
	char Input[30];
	cout << "  Enter movie title: \n";
	cin>>Input;
	Writer << Input << endl;
	cout << " Enter price gold:\n ";
	int prg;
	cin>>prg;
	cout << " Enter price silver:\n ";
	int prs;
	cin>>prs;	
	Writer<<prg<<endl;
	Writer<<prs<<endl;	
	cout << " Movie successfully updated!" << endl;
	cout << "  ";
	system("pause");
}
void movie::DisplayHeader()
{
	system("cls");
	cout << endl;
	
	// Upper Border
	cout << " \xC9";
	for(int i=0;i<76;i++)
		cout << "\xCD";
	cout << "\xBB";
	cout << endl;

	// Middle Border
	cout << " \xBA";
	//      [FROM_HERE                                                            TO_HERE]
	cout << "                          Movie Reservation System                          ";
	cout << "\xBA";
	cout << endl;

// Upper Border
	cout << " \xC8";
	for(int i=0;i<76;i++)
		cout << "\xCD";
	cout << "\xBC";
   cout << endl;
	cout << endl;
}
void movie::DisplayScreen(int n)
{
	if(n==1)
	{
		cout << endl;
		// Upper Border
		cout << " \xC9";
		for(int i=0;i<25;i++)
		cout << "\xCD";
		cout << "\xBB";
		cout << endl;
		// Middle Border
		cout << " \xBA";
		//      [FROM_HERE                TO_HERE]
		cout << "       SCREEN  "<<n<<"	   ";
		cout << "\xBA";
		cout << endl;
		// Upper Border
		cout << " \xC8";
		for(int i=0;i<25;i++)
		cout << "\xCD";
		cout << "\xBC";
	    cout << endl;
		cout << endl;	
	}
	else if(n==2)
	{
		cout << endl;	
		// Upper Border
		cout << " \xC9";
		for(int i=0;i<40;i++)
		cout << "\xCD";
		cout << "\xBB";
		cout << endl;
	
		// Middle Border
		cout << " \xBA";
		//      [FROM_HERE                					TO_HERE]
		cout << "        	 SCREEN "<<n<<"        	  ";
		cout << "\xBA";
		cout << endl;
		// Upper Border
		cout << " \xC8";
		for(int i=0;i<40;i++)
		cout << "\xCD";
		cout << "\xBC";
	    cout << endl;
		cout << endl;
	}	
	else if(n==3)
	{
		cout << endl;
		// Upper Border
		cout << " \xC9";
		for(int i=0;i<45;i++)
		cout << "\xCD";
		cout << "\xBB";
		cout << endl;
		// Middle Border
		cout << " \xBA";
		//      [FROM_HERE                					TO_HERE]
		cout << "        	   SCREEN "<<n<<"        	       ";
		cout << "\xBA";
		cout << endl;
		// Upper Border
		cout << " \xC8";
		for(int i=0;i<45;i++)
		cout << "\xCD";
		cout << "\xBC";
	    cout << endl;
		cout << endl;
	}	
}
void movie::UpdatePassword()
{
	fstream p;
	p.open("pw.txt",ios::out);
	char Input[20],pw[20];
	cout << "  Enter current password (Max 20 chars): ";
	cin>>Input;	
	if (strcmp(Input,sPassword)!=0)
	{
		cout << "  Wrong password!\n" << endl;
		//return;	
		UpdatePassword();
	}
	if (strcmp(Input,sPassword)==0)
	{
		cout << "  Enter new password (Max 20 chars): ";
		cin>>Input;
		p<<Input;
	}
}
void movie::graph()
{	
	int r,c;
	int g[3]={0,0,0};	
	fstream s[18];
	s[0].open("Seatm111.txt",ios::in);//date mov time(111)
	s[1].open("Seatm112.txt",ios::in);
	s[2].open("Seatm113.txt",ios::in);
	s[3].open("Seatm121.txt",ios::in);
	s[4].open("Seatm122.txt",ios::in);
	s[5].open("Seatm123.txt",ios::in);
	s[6].open("Seatm131.txt",ios::in);
	s[7].open("Seatm132.txt",ios::in);
	s[8].open("Seatm133.txt",ios::in);
	s[9].open("Seatm211.txt",ios::in);
	s[10].open("Seatm212.txt",ios::in);
	s[11].open("Seatm213.txt",ios::in);
	s[12].open("Seatm221.txt",ios::in);
	s[13].open("Seatm222.txt",ios::in);
	s[14].open("Seatm223.txt",ios::in);
	s[15].open("Seatm231.txt",ios::in);
	s[16].open("Seatm232.txt",ios::in);
	s[17].open("Seatm233.txt",ios::in);	
		while(s[0])
		{
			s[0]>>r;
			s[0]>>c;
			if(r!=0&&c!=0)
			{
				g[0]++;
			}
		}					
		while(s[1])
		{
			s[1]>>r;
			s[1]>>c;
			if(r!=0&&c!=0)
			{
		    	g[0]++;
			}		
		}		
		while(s[2])
		{
			s[2]>>r;
			s[2]>>c;
			if(r!=0&&c!=0)
			{
				g[0]++;
			}			
		}							
		while(s[3])
		{
			s[3]>>r;
			s[3]>>c;
			if(r!=0&&c!=0)
			{
			   g[1]++;				
			}			
		}
		while(s[4])
		{
			s[4]>>r;
			s[4]>>c;
			if(r!=0&&c!=0)
			{
				g[1]++;
			}			
		}
		while(s[5])
		{
			s[5]>>r;
			s[5]>>c;
			if(r!=0&&c!=0)
			{
			   	g[1]++;
			}		
		}		
		while(s[6])
		{
			s[6]>>r;
			s[6]>>c;
			if(r!=0&&c!=0)
			{   
				g[2]++;
			}		
		}
		while(s[7])
		{
			s[7]>>r;
			s[7]>>c;
			if(r!=0&&c!=0)
			{   
				g[2]++;
			}			
		}
		while(s[8])
		{
			s[8]>>r;
			s[8]>>c;
			if(r!=0&&c!=0)
			{   
				g[2]++;				
			}			
		}		
		while(s[9])
		{
			s[9]>>r;
			s[9]>>c;
			if(r!=0&&c!=0)
			{
				g[0]++;
			}
		}
		while(s[10])
		{
			s[10]>>r;
			s[10]>>c;
			if(r!=0&&c!=0)
			{
		    	g[0]++;
			}		
		}
		while(s[11])
		{
			s[11]>>r;
			s[11]>>c;
			if(r!=0&&c!=0)
			{			 
				g[0]++;
			}			
		}		
		while(s[12])
		{
			s[12]>>r;
			s[12]>>c;
			if(r!=0&&c!=0)
			{
			   g[1]++;
			}			
		}
		while(s[13])
		{
			s[13]>>r;
			s[13]>>c;
			if(r!=0&&c!=0)
			{
				g[1]++;
			}			
		}
		while(s[14])
		{
			s[14]>>r;
			s[14]>>c;
			if(r!=0&&c!=0)
			{
			   	g[1]++;
			}		
		}
		while(s[15])
		{
			s[15]>>r;
			s[15]>>c;
			if(r!=0&&c!=0)
			{   
				g[2]++;
			}		
		}
		while(s[16])
		{
			s[16]>>r;
			s[16]>>c;
			if(r!=0&&c!=0)
			{   
				g[2]++;
			}			
		}
		while(s[17])
		{
			s[17]>>r;
			s[17]>>c;
			if(r!=0&&c!=0)
			{   
				g[2]++;
			}			
		}	
	ifstream reader[3];
	reader[0].open("M1Movie.txt");
	reader[1].open("M2Movie.txt");	
	reader[2].open("M3Movie.txt");
	char name0[15],name1[15],name2[15];
		reader[0]>>name0;
		reader[1]>>name1;
		reader[2]>>name2;
	
	int i,j;
	cout<<"---------------------------------------------------\n";
	for(i=1;i<14;i++)
	{		
		if(i==1)
		{
			cout<<"||"<<name0<<endl;
		}
		if(i==5)
		{
			cout<<"||"<<name1<<endl;
			continue;
		}
		if(i==10)
		{
			cout<<"||"<<name2<<endl;
			continue;
		}
		if(i<=3)
		{
			cout<<"||";
			for(j=1;j<=g[0];j++)
			cout<<"* ";
			if(i==3)
			cout<<"\t["<<g[0]<<"]";
			cout<<"\n";
			
		}
	 	else if(i==4||i==9)
		{
			cout<<"||\n";
		}
		else if(i<=8)
		{
			cout<<"||";
			for(j=1;j<=g[1];j++)
			cout<<"* ";
			if(i==8)
			cout<<"\t["<<g[1]<<"]";
			cout<<"\n";
		}
		else if(i<=14)
		{
			cout<<"||";
			for(j=1;j<=g[2];j++)
			cout<<"* ";
			if(i==13)
			cout<<"\t["<<g[2]<<"]";
			cout<<"\n";
		}
	}
	system("pause");
}
void movie::Viewlayout()
{	
	char m1[11][8]={'G','*','*','*',' ','*','*','*',
 					'O','*','*','*',' ','*','*','*',
  	 	     		'L','*','*','*',' ','*','*','*',
				    'D','*','*','*',' ','*','*','*',
                    ' ',' ',' ',' ',' ',' ',' ',' ',
    				'S','*','*','*',' ','*','*','*',
        			'I','*','*','*',' ','*','*','*',
                    'L','*','*','*',' ','*','*','*',
			        'V','*','*','*',' ','*','*','*',
                    'E','*','*','*',' ','*','*','*',
					'R','*','*','*',' ','*','*','*'};
					
	char m2[6][14]={'G','*','*','*','*','*','*',' ','*','*','*','*','*','*',
					'G','*','*','*','*','*','*',' ','*','*','*','*','*','*',
					' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
					'S','*','*','*','*','*','*',' ','*','*','*','*','*','*',
					'S','*','*','*','*','*','*',' ','*','*','*','*','*','*',
					'S','*','*','*','*','*','*',' ','*','*','*','*','*','*'};
					
    char m3[11][15]={'G','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					'O','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					'L','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					'D','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
					'S','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					'I','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					'L','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					'V','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					'E','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*',
					'R','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*'};
					
			//cout<<"   SCREEN 1  \n"
			cout<<"   0  1  2  3  4  5  6  7  \n";		
			for(int i=0;i<11;i++)
			{	
				if(i<9)
				cout<<" "<<i+1<<" ";
				else
				cout<<i+1<<" ";
				for(int j=0;j<8;j++ )
				cout<<m1[i][j]<<"  ";
				cout<<endl;
			}
			DisplayScreen(1);
		 	cout<<"\n\n";
			cout<<"  0  1  2  3  4  5  6  7  8  9 10 11 12 13  \n";
			for(int i=0;i<6;i++)
			{
				cout<<i+1<<" ";
				for(int j=0;j<14;j++ )
				cout<<m2[i][j]<<"  ";
				cout<<endl;
			}
			DisplayScreen(2);
		 	cout<<"\n\n";
			
			cout<<"   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14\n";
			for(int i=0;i<11;i++)
			{	
				if(i<9)
				cout<<" "<<i+1<<" ";
				else
				cout<<i+1<<" ";
				for(int j=0;j<15;j++ )
				cout<<m3[i][j]<<"  ";
				cout<<endl;
			}		
			DisplayScreen(3);
		 	cout<<"\n\n";		
				system("pause");	
}
