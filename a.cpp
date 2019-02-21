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
void Display(PERSON *p, int a);
void FindRichest(PERSON *p, int a);
void Deposit(char CustName[],PERSON *p, int a);
void NewCopy(string firstname, PERSON *p, int a);

int main()
{
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
    PERSON *p = new PERSON[a];
    string firstname, lastname;
    int x=0;
    while(in>>firstname>>lastname>>p[x].Balance)
    {
        strcpy(p[x].Name, (firstname+" "+lastname).c_str());
        x++;
    }
    Display(p, a);
    FindRichest(p, a);
    char CustName[20];
    cout<<"Enter your full name to deposit money:";
    getline(cin,name);
    strcpy(CustName, name.c_str());
    // cin.getline(C, 20);
    Deposit(CustName, p, a);
    NewCopy("data.txt", p, a);
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

void Deposit(char CustName[],PERSON *p, int N)
{
  int index = 0;
  for (int i = 0; i < N; i++)
  {
    if(strcmp(CustName, p[i].Name)==0)
    {
        index = i;
        break;
    }
  }
  float deposit;
  cout << endl;
  cout << CustName << ", how much would you like to deposit? ";
  cout<<"\nNow your new balance is ";
  cin>>deposit;
  p[index].Balance+=deposit;
  cout<<"New balance is $"<<p[index].Balance<<endl;
}

void NewCopy(string firstname, PERSON *p, int N)
{
  ofstream out;
  out<<setprecision(2)<<fixed;
  out.open(firstname.c_str());
  for(int i=0; i<N; i++)
  {
      out<<p[i].Name<<" "<<p[i].Balance<<endl;
  }
  out.close();
}
