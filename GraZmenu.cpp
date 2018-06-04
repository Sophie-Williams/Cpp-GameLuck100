#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#define MAX 80

using namespace std;

//Gra z komputerem - Traf w 100!!!


void intro()
{
cout << "                          GRA - TRAF W 100!!!                     " <<endl ;
cout << "__________________________________________________________________________________________"  <<endl;
cout << "ZASADY GRY: " <<endl <<endl;
cout << "Gracz rozpoczynajacy podaje liczbe z zakresu od 1 do 10. Kolejno gracze na przemian"<<endl;
cout << "podaja liczby, z ktorych kazda musi byc wieksza od poprzedniej co najmniej o 1,"<<endl;
cout << "a co najwyzej o 10. Wygrywa ten, kto pierwszy poda liczbe 100." <<endl;
cout << "__________________________________________________________________________________________" <<endl <<endl;
cout << "Wcisnij dowolny klawisz, aby rozpoczac...";


getch();
system("cls");
}


//*****************************************************************************************************************************************


void menu()
{
 	
 cout << "Wcisnij 1, aby rozpoczac gre z komputerem " <<endl;
 cout << "Wcisnij 2, aby rozpoczac gre dla dwoch graczy " <<endl<<endl;	
 
}

//*****************************************************************************************************************************************

void grazpc()
{
 cout << "__________________________________________________________________________________________"  <<endl;
 cout << "Gra z PC" <<endl;
 cout << "__________________________________________________________________________________________"  <<endl;
 cout << "1. Poziom latwy " <<endl ;
 cout << "2. Poziom sredni " <<endl ;
 cout << "3. Poziom trudny " <<endl ;
 
}

//*****************************************************************************************************************************************



short int ktozaczyna()													//	losowanie kto rozpoczyna gre
 {
 	srand( time ( NULL) );
 	int liczba = ( rand() % 2) + 1 ;
 	
 	return liczba;
 }
 
char wyborn()															//	wybor GRA VS PC  /  GRA NA DWOCH
{
	char wybor;
	do	
		{
			wybor=getch();
		} 
		while(wybor!='1' && wybor!='2');
	return wybor;
}

short int wprowadz_liczbe_start()										// wprowadzanie liczby przez gracza rozpoczynajacego
{
	short int a;
	bool wprowOK = false;
    do
    {
      cin >> a;
      if (cin.fail())
      {
         cin.clear();
         cout << "To nie jest liczba. Podaj liczbe od 1 do 10.\n\n";
         while (cin.get() != '\n');
         continue;
      }
      while (cin.get() != '\n');
      if (a < 1 || a > 10)
      {
        cout << "Liczba jest niepoprawna. Podaj liczbe od 1 do 10. \n\n";
        continue;
      }
      
      wprowOK = true;
    }  
    while (!wprowOK);
    return a;
}

short int wprowadz_liczbe_na_dwoch(short int a,char gracz[])			//	wprowadzanie liczby przez gracza w grze na dwóch
{
	short int b;
	 	bool wprowOK = false;
    do
    {
     cout << gracz <<": " ; cin >> b;
      if (cin.fail())
      {
         cin.clear();
         if( a <= 90 )
         cout << "Podaj liczbe od " << a + 1 <<" do " << a + 10 <<  ". \n\n";
         else 
         cout << "Podaj liczbe od " << a + 1 <<" do 100. \n\n";
         while (cin.get() != '\n');
         continue;
      }
      while (cin.get() != '\n');
      if (b<=a || b>a+10 || b>100)
      {
        if( b <= 90 )
         cout << "Podaj liczbe od " << a + 1 <<" do " << a + 10 <<  ". \n\n";
         else 
         cout << "Podaj liczbe od " << a + 1 <<" do 100. \n\n";
         while (cin.get() != '\n');
         continue;
      }
	        
      wprowOK = true;
    }  
    while (!wprowOK);
    return b;
}

short int wprowadz_liczbe(short int a)									// wprowadzanie liczby przez gracza w grze vs pc
{
	short int b;
	bool wprowOK = false;
    do
    {
      cin >> b;
      if (cin.fail())
      {
         cin.clear();
          if( a <= 90 )
         cout << "Podaj liczbe od " << a + 1 <<" do " << a + 10 <<  ". \n\n";
         else 
         cout << "Podaj liczbe od " << a + 1 <<" do 100. \n\n";
         while (cin.get() != '\n');
         continue;
      }
      while (cin.get() != '\n');
      if (b<=a || b>a+10 || b>100)
      {
      	 if( a <= 90 ) 
        cout << "Podaj liczbe od " << a + 1 <<" do " << a + 10 <<  ". \n\n";
         else 
         cout << "Podaj liczbe od " << a + 1 <<" do 100. \n\n";
        continue;
      }
      
      wprowOK = true;
    }  
    while (!wprowOK);
    return b;
}

bool ruch_komputer_latwy(short int &a)									// RUCH KOMPUTERA dla poziomu trudnego
{
	if (a>=90)
  	a = 100;
else
	{
	a = ( rand() % 10) + (a + 1);
	}
 	cout << a << endl;
	  	
if (a==100)
	{
		cout<<"Wygralem";
		return true;
	}
	return false;
	
}

bool ruch_komputer_sredni(short int &a)									// RUCH KOMPUTERA dla poziomu sredniego
{
	if (a >= 50 && a < 56)
	{
		a = 56;
	}
	else if (a >= 57 && a < 67)
	{
		a = 67;
	}
	else if (a >= 68 && a < 78)
	{
		a = 78;
	}
	else if (a >= 79 && a < 89)
	{
		a = 89;
	}
	else if (a >= 90)
	{
		a = 100;
	}
else
 { 	
 	a = ( rand() % 10) + (a + 1);
 }
 	cout << a << endl;
 	if(a==100)
 	{
 		cout<<"Wygralem";
 		return true;
	 }
	 return false;
}

bool ruch_komputer_trudny(short int &a)									// RUCH KOMPUTERA dla poziomu trudnego
{
	if (a >=2  && a < 12)													
	{
		a = 12;
	}
	 else if (a >= 13 && a < 23)
	{
		a = 23;
	}
	 else if (a >= 24 && a < 34)
	{
		a = 34;
	}
    else if (a >= 35 && a < 45)
	{
		a = 45;
	}																			
    else if (a >= 46 && a < 56)
	{
		a = 56;
	}
	else if (a >= 57 && a < 67)
	{
		a = 67;
	}
	else if (a >= 68 && a < 78)
	{
		a = 78;
	}
	else if (a >= 79 && a < 89)
	{
		a = 89;
	}
	else if (a >= 90)
	{
		a = 100;
	}
	else if (a==0)
	{
		a = 1;
	}
	else
 	{	  	
		a = ( rand() % 10) + (a + 1);
 	}
 	cout << a << endl;
 	if(a==100)
 	{
 		cout<<"Wygralem";
 		return true;
	 }
	 return false;
}

void latwagra()															//	void £ATWA GRA
{
	short int a;
	cout << "Rozpoczales gre na latwym poziomie" <<endl;
  
 if (ktozaczyna() == 1)
{
 																		// GRE ROZPOCZYNA GRACZ	
 cout << " Gre rozpoczyna gracz" << endl;;
	a = wprowadz_liczbe_start();

for (int i=0;a<100;i++)
	{
 	if(ruch_komputer_latwy(a))
 	break;
 	a=wprowadz_liczbe(a);

if (a==100)
{cout << "Wygrales!"<< endl;
break;
}
	}
}  			
 
 																		//GRE ROZPOCZYNA PC
else 
{	
 cout << "Gre rozpoczyna PC" << endl;
 cout << "Wcisnij Enter, aby komputer rozpoczal gre... ";
 cout << endl;
 getch();
 a=0;
 
for (int i=0;a<=100;i++)
 {
	if(ruch_komputer_latwy(a))
	break;
	a=wprowadz_liczbe(a);
if (a==100)
  {
  cout << "Wygrales!"<< endl;
  break;
  }
};
}   
}

void sredniagra()														// void ŒREDNIA GRA
{
	short int a;
	short int b;
	cout << "Rozpoczales gre na srednim poziomie" <<endl; 
 if (ktozaczyna() == 1)
 {
 																		// GRE ROZPOCZYNA GRACZ	
 cout << " Gre rozpoczyna gracz" << endl;;
 a = wprowadz_liczbe_start();
cout << endl;
 for (int i=0;a<100;i++)
 {
	if (ruch_komputer_sredni(a))
  	break;
  	a=wprowadz_liczbe(a);
if (a==100)
  {cout << "Wygrales!"<< endl;
  break;
  }
}
}  		
 
 																		//GRE ROZPOCZYNA PC
 else 
{	
 cout << "Gre rozpoczyna PC" << endl;
 cout << "Wcisnij Enter, aby komputer rozpoczal gre... ";
 cout << endl;
 getch();
 a=0;

for (int i=0;a<=100;i++)
 {																		
																		
  	break;
  	a=wprowadz_liczbe(a);
if (a==100)
  {cout << "Wygrales!"<< endl;
  break;
  }
}			
}
}

void trudnagra()														// void TRUDNA GRA
{
	short int a;
	cout << "Rozpoczales gre na trudnym poziomie" <<endl;  
 if (ktozaczyna() == 1)
 {
 																		// GRE ROZPOCZYNA GRACZ
 	
 cout << " Gre rozpoczyna gracz" << endl;;
a = wprowadz_liczbe_start();
cout << endl;
 for (int i=0;a<100;i++)
 {
	if (ruch_komputer_trudny(a))
  	break;
  	a=wprowadz_liczbe(a);
if (a==100)
  {cout << "Wygrales!"<< endl;
  break;
  }
}
}  		

 
 																		//GRE ROZPOCZYNA PC
 else 
{	
 cout << "Gre rozpoczyna PC" << endl;
 cout << "Wcisnij Enter, aby komputer rozpoczal gre... ";
 cout << endl;
 getch();
 a=0;
for (int i=0;a<=100;i++)
 {																		
																		
if (ruch_komputer_trudny(a))
  	break;
  	a=wprowadz_liczbe(a);
if (a==100)
  {cout << "Wygrales!"<< endl;
  break;
  }
}	
}
}

void gra_dla_dwoch()
{
	short int a;
 short int b;
 char gracz1[MAX];
 char gracz2[MAX];	
 cout << " Wprowadz imie pierwszego gracza: " ;
 cin.getline(gracz1, MAX);
 cout << endl << endl;
 cout << " Wprowadz imie drugiego gracza: ";
 cin.getline(gracz2, MAX);
 cout << endl << endl;
 
  if (ktozaczyna() == 1)
  
  {																		// Ropzoczyna gracz 1
  cout << "Gre rozpoczyna " << gracz1 <<"." <<endl <<endl;
  
  a=wprowadz_liczbe_start();
  
cout << gracz1 << ": " <<a <<endl;

do
{ 	
  	b=wprowadz_liczbe_na_dwoch(a,gracz2);
  	
 if (a == 100)
 {
  cout << gracz1 << " Wygral gre. " ;
  break;
 }
 else if (b == 100)
 {
  cout << gracz2 << " Wygral gre. " ;
  break;
 }
a = b;
b=wprowadz_liczbe_na_dwoch(a,gracz1);
	a=b;
	if(a==100)
{
	cout<<gracz1<<" wygral gre. ";
	break;
}
} while( a <= 100 );

} 
 
else
{																		// Ropzoczyna gracz 2
  cout << "Gre rozpoczyna " << gracz2 <<"." << endl << endl;
  
  a=wprowadz_liczbe_start();

cout << gracz2 << ": " << a << endl;
do
{
 	 b=wprowadz_liczbe_na_dwoch(a,gracz1);
 
 if (b == 100)
 {
  cout << gracz1 << " wygral gre. " ;
break;
 }
 else if (a == 100)
 {
  cout << gracz2 << " wygral gre. " ; 
break;	
 }
a = b;

 b=wprowadz_liczbe_na_dwoch(a,gracz2); 	
a = b;
if(a==100)
{
	cout<<gracz2<<" wygral gre. ";
	break;
}
} while( a <= 100 ); 
}
}


//*****************************************************************************************************************************************
//*****************************************************************************************************************************************

int main()
{
 char wybor;
 char poziom;
 short int a;
 short int b;
 char gracz1[MAX];
 char gracz2[MAX];	
 char klawisz;
srand( time ( NULL) );	


 intro();
 
 do																		// Chcesz zagrac jeszcze raz?
 {
 menu(); 

 wybor=wyborn();														// Wybor gra na dwoch lub z PC

  if (wybor == '1')														// Wybor GRA Z PC
  {	
 	grazpc();
 	do	
	{
		poziom=getch();
	} 
	while(poziom!='1' && poziom!='2' && poziom!='3');					// Wybor poziomu trudnosci


cout << endl;
  if (poziom == '1')													//GRA NA LATWYM POZIOMIE
 { 
 	latwagra();
 }
  if (poziom == '2')													//GRA NA SREDNIM POZIOMIE
{ 
	sredniagra();
}
 
  if (poziom == '3')													//GRA NA TRUDNYM POZIOMIE
{
	trudnagra();
}

  }
    
 else                                                       			// wybor GRA DLA DWÓCH GRACZY
 {
 	gra_dla_dwoch();
 }
		cout<< endl <<endl;
	 	cout<<"Chcesz powrocic do menu ? (t/n) ";						// Chcesz zagrac jeszcze raz?
		do													
		{
			klawisz=getch();
		}while(klawisz!='n' && klawisz!='N' && klawisz!='t' && klawisz!='T');
		system("cls");
		
	}while(klawisz!='n' && klawisz!='N');
return 0;
}
