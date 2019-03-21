#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

struct PERSON{
    char Name[20];
    float Balance;
};

//Function names
void Display(PERSON *arr, int a);
void FindRichest(PERSON *arr, int a);
//New one?
void Deposit(PERSON *arr,int N,char CustName[], int amount);
//Old one
//void Deposit(char CustName[],PERSON *p, int a);
void NewCopy(string firstname, PERSON *arr, int a);
PERSON * readData(int & N);


int main()
{
    int v = 0;
    string name;
    int a=0;
    ifstream in;
    in.open("data.txt");
    string line;
    while(getline(in, line)){
        a++;
    }
    in.clear();
    in.seekg(0, ios::beg);
    PERSON *arr = new PERSON[a];
    string firstname, lastname;
    int x=0;
    while(in>>firstname>>lastname>>arr[x].Balance)
    {
        strcpy(arr[x].Name, (firstname+" "+lastname).c_str());
        x++;
    }
    Display(arr, a);
    FindRichest(arr, a);
    char CustName[20];
    cout<<"Enter your full name to deposit money:";
    getline(cin,name);
    strcpy(CustName, name.c_str());
    //cin.getline(C, 20);
    Deposit(arr, a,CustName, v);
    NewCopy("data.txt", arr, a);
    readData(a);
    return 0;
}

void Display(PERSON *p, int N){
    cout<<setprecision(2)<<fixed;
    cout<<setw(20)<<left<<"Name"<<" Balance"<<endl;
    cout<<"-------------------------------------"<<endl;
    for(int i=0; i<N; i++){
        cout<<setw(20)<<p[i].Name<<" "<<p[i].Balance<<endl;
    }
}

void FindRichest(PERSON *p, int N){
    int max=0;
    for(int i=0; i<N; i++){
        if(p[max].Balance<p[i].Balance)
        max = i;
    }
    cout<<"The customer with maximum balance is "<<p[max].Name<<endl;
}
//void Deposit(char CustName[],PERSON *p, int N)
void Deposit(PERSON *arr,int N,char CustName[], int amount)
{
  int index = 0;
  for (int i = 0; i < N; i++)
  {
    if(strcmp(CustName, arr[i].Name)==0)
    {
        index = i;
        break;
    }
  }
  float deposit;
  cout << endl;
  cout << "Amount: ";
  //cout << CustName << //", how much would you like to deposit? ";
  //cout<<"\nNow your new balance is ";
  cin>>deposit;
  arr[index].Balance+=deposit;
  cout<<"New balance: " <<arr[index].Balance<<endl;
}

void NewCopy(string firstname, PERSON *p, int N)
{
  cout << "File Updated...";
  cout << endl;
  ofstream out;
  out<<setprecision(2)<<fixed;
  out.open(firstname.c_str());
  for(int i=0; i<N; i++)
  {
      out<<p[i].Name<<" "<<p[i].Balance<<endl;
  }
  out.close();
}

PERSON * readData(int & N)
{
  PERSON *intptr;
  intptr = new PERSON[N];
  fstream read;
  read<<setprecision(2)<<fixed;
  read<<setw(20)<<left<<"Name"<<" Balance"<<endl;
  read<<"-------------------------------------"<<endl;
  for(int i=0; i<N; i++)
  {
      read<<setw(20)<<intptr[i].Name<<" "<<intptr[i].Balance<<endl;
  }
  return intptr;
}
