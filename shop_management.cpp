/*
    Shopmanager id -- shop007
>>> password     --   111222
    Employee Id  --  elployee007
>>> password     --   000000
*/
 
#include<iostream>
#include <conio.h>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<fstream>
#include<direct.h>
#include<math.h>
#include<typeinfo>

using namespace std;

class product
{
    protected:
    string pname,pid;
    float costp,sellp;
    int qnt;
};

class earn:public product
{
    protected:
    float profit,profpercent;
    public:
    void cal(); //friend function
    void show(); //function overrriding
};

class logo   //friend function
{
    private:  
    string app_name="Grocery Shop Management System";
    public:
    friend void app_display(logo l){
    system("CLS");
    string a;
     cout<<"\t\t\t   ====================================="<<endl;
     cout<<"\t\t\t   *****************    **************** "<<endl;
     cout<<"\t\t\t   *****************    **************** "<<endl;
     cout<<"\t\t\t   ***                  ***             "<<endl;
     cout<<"\t\t\t   ***                  **************** "<<endl;
     cout<<"\t\t\t   ***       *******    **************** "<<endl;
     cout<<"\t\t\t   ***           ***                 *** "<<endl;
     cout<<"\t\t\t   *****************    **************** "<<endl;
     cout<<"\t\t\t   *****************    **************** "<<endl;
     cout<<"\t\t\t   ====================================="<<endl;
     cout<<"\t\t\t      "<<l.app_name<<endl;
     cout<<"\t\t\t   ====================================="<<endl;
     cin>>a;

    }
};

class admin
{
    protected:
    string id="admin",pass="admin";
};

class shop:public earn,public admin
{
    public:
    void getlogin(char Username[20], char Password[20],int ,int); //>
    void getlogin(char User[20], char Password1[20]); //>
    void Login(); //>
    void home(); //>
    void billing();
    void show(); //function overriding //>
    void add_product();
    void add_bill();
    void remove_product();
    void remove_file();
    void show_all();
    void search_product(); //>
    void add_file();
    void edit_file(int);
    void show_profit();
    void bill_history();
    void add_profit();
    void list_upper_margin(); //>
    void list_lower_margin(); //>
    void list_main_part(int j); //>
    


    shop() //construcor
    {
        mkdir("C:/Users/Public/shopMS");
    }
    ~shop() //distructor
    {
        system("CLS");
        cout<<"\n\n\n\n\n\t\t\t\t\t\t*THANK YOU*\n\n\n\t\t\t\t\t\t\t\t\tProject by:- Lalit & Lokesh (B-18,19)\n\n\n"<<endl;
    }
};

void shop::Login()   
{

    char Username[15];
    char Password[15];
    char User[15];
    char Password1[15];
    char Epwd;
    int true1 = 1;
    int try1 = 0;
    int i = 0;

    do
    {
        system("cls");
        cout << "\n\n\n\n\n\n";
        int a;
        cout << "\t\t\t\t    ============================================\n";
        cout << "\t\t\t\t    |   Grocery Shop Store Management System   |\n";
        cout << "\t\t\t\t    ============================================\n";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        int t;
        cout<<"Enter 1 For Shop-Manager Id login-";
        cout << "\n";
        cout << "\t\t\t\t\t";
        cout<<"Enter 2 For employee Id login-";
        cout << "\n"; 
        cout << "\t\t\t\t\t";
        cout<<">>>";
        cin>>t;
     if(t==1)
    {
        cout << "\t\t\t\t\t";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Enter Shopmanager login ID:\n";
        cout << "\t\t\t\t\t";
        cout << "Username : ";
        cin >> Username;
        cout << "\t\t\t\t\t";
        cout << "Password : ";
        for (i = 0;;)
        {
            Epwd = getch();
            if ((Epwd >= 'a' && Epwd <= 'z') || (Epwd >= 'A' && Epwd <= 'Z') || (Epwd >= '0' && Epwd <= '9'))
            {
                Password[i] = Epwd;
                ++i;
                cout << "*";
            }
            if (Epwd == '\b' && i >= 1)
            {
                cout << "\b \b";
                --i;
            }
            if (Epwd == '\r')
            {
                Password[i] = '\0';
                break;
            }
        }
        getlogin( Username, Password, true1, try1);
        
    }
    else if(t==2)
    {
        cout << "\t\t\t\t\t";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Enter Employee login ID:\n";
        cout << "\t\t\t\t\t";
        cout << "Username : ";
        cin >> User;
        cout << "\t\t\t\t\t";
        cout << "Password : ";
        for (i = 0;;)
        {
            Epwd = getch();
            if ((Epwd >= 'a' && Epwd <= 'z') || (Epwd >= 'A' && Epwd <= 'Z') || (Epwd >= '0' && Epwd <= '9'))
            {
                Password1[i] = Epwd;
                ++i;
                cout << "*";
            }
            if (Epwd == '\b' && i >= 1)
            {
                cout << "\b \b";
                --i;
            }
            if (Epwd == '\r')
            {
                Password1[i] = '\0';
                break;
            }
        }
        getlogin(User, Password1);
     }
     else
     {
         cout<<"Invalid Input"<<endl;
     }
    } while (try1 < 3);
    // home();
}
void shop::getlogin(char Username[20], char Password[20],int true1, int try1)  //function overloading
{
     if (strcmp(Username, "shop007") == 0 && strcmp(Password, "111222") == 0)
        {
            cout << "\n\n";
            cout << "\t\t\t\t";
            cout << "You are accessed to the system!\n\n";
            cout << "\t\t\t\t";
            system("pause");
            system("cls");
            true1 = 0;
            try1 = 4;
            shop::home();
        }
        else
         {
            system("cls");
            try1 = try1 + 1;
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout << "\t\t\t\t\t";
            cout << "No. of attempts remain: " << 3 - try1;
            cout << "\n\n";
            cout << "\t\t\t\t";
            system("pause");

            if (try1 >= 3)
            {
                cout << "\t\t\t\t\t\t";
                cout << "\n";
                cout << "\t\t\t\t";
                cout << "No permission to enter the system!\n\n";
                cout << "\t\t\t\t";
                system("pause");
                exit;
            }
          }
}
void shop::getlogin(char User[20], char Password1[20])  //function overloading
{
    int true1 = 1;
    int try1 = 0;
     if(strcmp(User, "employee007") == 0 && strcmp(Password1, "000000") == 0)
           {
            cout << "\n\n";
            cout << "\t\t\t\t";
            cout << "You are accessed to the system!\n\n";
            cout << "\t\t\t\t";
            system("pause");
            system("cls");
            true1 = 0;
            try1 = 4;
            shop::home();
        }
        else
        {
            system("cls");
            try1 = try1 + 1;
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout << "\t\t\t\t\t";
            cout << "No. of attempts remain: " << 3 - try1;
            cout << "\n\n";
            cout << "\t\t\t\t";
            system("pause");

            if (try1 >= 3)
            {
                cout << "\t\t\t\t\t\t";
                cout << "\n";
                cout << "\t\t\t\t";
                cout << "No permission to enter the system!\n\n";
                cout << "\t\t\t\t";
                system("pause");
                exit;
            }
        }
}



void shop::home()
{
    char choice,choice2;
    do{
        system("CLS");
        cout<<setfill('=')<<setw(100)<<"\n";
        cout<<""<<setfill(' ')<<setw(0)<<"|"<<setw(52)<<"        "<<setw(46)<<"|"<<"\n";
        cout<<""<<setfill(' ')<<setw(0)<<"|"<<setw(54)<<"* WELCOME *"<<setw(44)<<"|"<<"\n";
        cout<<""<<setfill(' ')<<setw(0)<<"|"<<setw(52)<<"        "<<setw(46)<<"|"<<"\n";
        cout<<setw(0)<<"|"<<setw(5)<<" "<<setfill('=')<<setw(88)<<" "<<setw(1)<<"    |"<<"\n";
        cout<<""<<setfill(' ')<<setw(0)<<"|"<<setw(52)<<"        "<<setw(46)<<"|"<<"\n";
        cout<<""<<setfill(' ')<<setw(0)<<"|"<<setw(52)<<"1. Make Bill"<<setw(46)<<"|"<<"\n";
        cout<<""<<setfill(' ')<<setw(0)<<"|"<<setw(60)<<"2. Show Product List"<<setw(38)<<"|"<<"\n";
        cout<<""<<setfill(' ')<<setw(0)<<"|"<<setw(57)<<"3. Search Product"<<setw(41)<<"|"<<"\n";
        cout<<""<<setfill(' ')<<setw(0)<<"|"<<setw(54)<<"4. Show Profit"<<setw(44)<<"|"<<"\n";
        cout<<""<<setfill(' ')<<setw(0)<<"|"<<setw(54)<<"5. Add Product"<<setw(44)<<"|"<<"\n";
        cout<<""<<setfill(' ')<<setw(0)<<"|"<<setw(58)<<"6. Billing History"<<setw(40)<<"|"<<"\n";
        cout<<""<<setfill(' ')<<setw(0)<<"|"<<setw(47)<<"0. EXIT"<<setw(51)<<"|"<<"\n";
        cout<<""<<setfill(' ')<<setw(0)<<"|"<<setw(52)<<"        "<<setw(46)<<"|"<<"\n";
        cout<<setw(0)<<"|"<<setw(5)<<" "<<setfill('=')<<setw(88)<<" "<<setw(1)<<"    |"<<"\n";
        cout<<""<<setfill(' ')<<setw(0)<<"|"<<setw(52)<<"        "<<setw(46)<<"|"<<"\n";
        cout<<""<<setfill(' ')<<setw(0)<<"|"<<setw(52)<<"        "<<setw(46)<<"|"<<"\n";
        cout<<setfill('=')<<setw(100)<<"\n";
        cout<<">>>";

        cin>>choice;
        string any;

        switch(choice)
        {
            case '1':
            billing();
            break;
            case '2':
            show();
            cout<<"Enter any key to go to main menu...";
            cin>>any;
            break;
            case '3':
            do{
            search_product();
            cout<<"To search another product enter 1 or any othe key to exit.."<<endl;
            cin>>choice2;
            }while(choice2=='1');
            break;
            case '4':

            break;
            case '5':
            add_product();
            break;
            case '6':

            break;
            case '0':
            system("CLS");
            exit(0);
            break;
            default:
            system("CLS");
            cout<<"Enter the correct choice..."<<endl;
        }

    }while(choice!=0);

}

void shop::show() //show product list
{
    int i=0;
    system("CLS");
    list_upper_margin();

    ifstream fin;
    fin.open("C:\\Users\\Public\\shopMS\\0main.txt",ios::in);
    string *file=new string;
    string *item=new string;
    // string file,item;
    while(getline(fin,*file))
    {
        i++;
        ifstream fin2("C:\\Users\\Public\\shopMS\\"+*file);
        getline(fin2,pname);
        getline(fin2,pid);
        fin2>>costp;
        fin2>>sellp;
        fin2>>qnt;

        list_main_part(i);
    }
    list_lower_margin();
    fin.close();
    delete file;
    delete item;
}

void earn::show(){
    system("CLS");
    cout<<"showing profit: "<<endl;
    cout<<profit<<"\n"<<profpercent<<endl;
}

void shop::search_product() //search product
{

        string *search=new string;
        string *file=new string;
        string *results=new string[100];

        // string search,file,results[100];
        int i=0;
        cin.ignore();
        cout<<"Enter the name or id of the product to search: ";
        getline(cin,*search);
        ifstream fin;
        fin.open("C:\\Users\\Public\\shopMS\\0main.txt",ios::in);
        while(getline(fin,*file))
        {
            ifstream fin2("C:\\Users\\Public\\shopMS\\"+*file);
            getline(fin2,pname);
            getline(fin2,pid);
            if(*search==pname||*search==pid)
            {
                results[i]=*file;
                i++;
            }
            fin2.close();
    
        }
        if(i==0){
            system("CLS");
            cout<<"\n\nNo result found.\n"<<endl;
        }
        else{
            system("CLS");
            list_upper_margin();
            for(int j=0;j<i;j++)
            {
                ifstream fin3("C:\\Users\\Public\\shopMS\\"+results[j]);
                getline(fin3,pname);
                getline(fin3,pid);
                fin3>>costp;
                fin3>>sellp;
                fin3>>qnt;
                fin3.close();
                list_main_part(j+1);
            }
            list_lower_margin();
        }

}



void shop::add_product() //add product
{
    string choice;
    do{
        system("CLS");
        cin.ignore();
        cout<<"Enter product name: ";
        getline(cin,pname);
        cout<<"Enter product ID: ";
        getline(cin,pid);
        cout<<"Enter cost: ";
        cin>>costp;    //need exception handling here for non numbers
        cout<<"Enter sell: ";
        cin>>sellp;    //need exception handling here for non numbers
        cout<<"Enter qnt: ";
        cin>>qnt;      //need exception handling here for non integers
        cal();
        add_file();
        cout<<"enter 1 to add another product or any other key to exit to main menu."<<endl;
        cin>>choice;
    }while(choice=="1");
 
}

void shop::list_upper_margin()
{
    cout<<setfill('=')<<setw(122)<<"\n";
    cout<<setw(0)<<"|  "<<setfill(' ')<<setw(5)<<"Sr.no"<<setw(5)<<"  |  "
    <<setw(20)<<"Prd. ID"<<setfill(' ')<<setw(5)<<"  |  "
    <<setw(32)<<"Name"<<setfill(' ')<<setw(5)<<"  |  "
    <<setw(10)<<"Sell Prise"<<setfill(' ')<<setw(5)<<"  |  "
    <<setw(10)<<"Cost prise"<<setfill(' ')<<setw(5)<<"  |   "
    <<setw(10)<<"Quantity"<<setfill(' ')<<setw(5)<<"   |"
    <<"\n";
    cout<<setfill('=')<<setw(122)<<"\n";
}

void shop::list_lower_margin()
{
    cout<<setfill('=')<<setw(122)<<"\n";
}

void shop::list_main_part(int j)
{
    cout<<setw(0)<<"|  "<<setfill(' ')<<setw(5)<<j<<setw(5)<<"  |  "
    <<setw(20)<<pid<<setfill(' ')<<setw(5)<<"  |  "
    <<setw(32)<<pname<<setfill(' ')<<setw(5)<<"  |  "
    <<setw(10)<<sellp<<setfill(' ')<<setw(5)<<"  |  "
    <<setw(10)<<costp<<setfill(' ')<<setw(5)<<"  |  "
    <<setw(10)<<qnt<<setfill(' ')<<setw(6)<<"  |"
    <<"\n";
}

void earn::cal()
{
    profit=(sellp-costp);
    profpercent=(profit/sellp)*100;
}

void shop::add_file()
{
    ofstream fmain;
    fmain.open("C:\\Users\\Public\\shopMS\\0main.txt",ios::app | ios::out | ios::in);
    fmain<<pid<<".txt"<<"\n";
    fmain.close();
    
    string path="C:\\Users\\Public\\shopMS\\";
    string type=".txt";
    string file=path+pid+type;

    ofstream fout(file);
    fout<<pname<<"\n"<<pid<<"\n"<<costp<<"\n"<<sellp<<"\n"<<qnt<<"\n"<<profit<<"\n"<<profpercent;
    fout.close();
}

void shop::edit_file(int endqnt){
     string path="C:\\Users\\Public\\shopMS\\";
    string type=".txt";
    string file=path+pid+type;

    ofstream fout(file);
    fout<<pname<<"\n"<<pid<<"\n"<<costp<<"\n"<<sellp<<"\n"<<endqnt<<"\n"<<profit<<"\n"<<profpercent;
    fout.close();
}

template<class T>
T discount(T per,T value){
    T finalvalue;
    finalvalue=(per/100)*value;
    return finalvalue;
}

void shop::billing()
{
    char choice='1';

    float *total_amount=new float(0);
    float *costparr=new float[100];
    float *sellparr=new float[100];
    float *profitarr=new float[100];
    string *search=new string;
    string *file=new string;
    string *results=new string[100];
    string *pnamearr=new string[100];
    string *pidarr=new string[100];
    int *qntarr=new int[100];
    int *buyqnt=new int[100];
    int *buyqntarr=new int[100];
    int k=0;

    do{
        switch(choice)
        {
        case '1':
        {
        int i=0;
        cin.ignore();
        cout<<"Enter the name or id of the product to search: ";
        getline(cin,*search);
        ifstream fin;
        fin.open("C:\\Users\\Public\\shopMS\\0main.txt",ios::in);
        while(getline(fin, *file))
        {
            ifstream fin2("C:\\Users\\Public\\shopMS\\"+ *file);
            getline(fin2,pname);
            getline(fin2,pid);
            if(*search==pname||*search==pid)
            {
                results[i]= *file;
                i++;
            }
            fin2.close();


        }
        if(i==0){
            cout<<"No result found."<<endl;
        }
        else
        {
            system("CLS");
            list_upper_margin();
            for(int j=0;j<i;j++)
            {
                ifstream fin3("C:\\Users\\Public\\shopMS\\"+results[j]);
                getline(fin3,pname);
                getline(fin3,pid);
                fin3>>costp;
                fin3>>sellp;
                fin3>>qnt;
                fin3>>profit;
                fin3.close();
                list_main_part(j+1);
            }
            list_lower_margin();

            if(i==1)
            {
                try{
                    cout<<"enter item quantity"<<endl;
                    cin>>*buyqnt;
                }catch(...){
                    cout<<"Enter integer value for quantity"<<endl;
                }

                if(*buyqnt<=qnt && *buyqnt>=0)  //need exception handling if buy qnt is not int
                {
                    pnamearr[k]=pname;
                    pidarr[k]=pid;
                    costparr[k]=costp;
                    sellparr[k]=sellp;
                    qntarr[k]=*buyqnt;
                    k++;
                    total_amount= *total_amount+(sellp(*buyqnt));
                    edit_file(qnt-(*buyqnt));
                }else{
                    cout<<"this quantity is not available..."<<endl;
                }
            }
            else
            {
                int r;
                cout<<"Enter serial no of the item to add: ";
                cin>>r;
                system("CLS");
                list_upper_margin();
                ifstream fin3("C:\\Users\\Public\\shopMS\\"+results[r-1]);
                getline(fin3,pname);
                getline(fin3,pid);
                fin3>>costp;
                fin3>>sellp;
                fin3>>qnt;
                fin3>>profit;
                fin3.close();
                list_main_part(1);
                list_lower_margin();
                
                try{
                    cout<<"enter item quantity"<<endl;
                    cin>>*buyqnt;
                }catch(...){
                    cout<<"Enter integer value for quantity"<<endl;
                }
                if(*buyqnt<=qnt && *buyqnt>=0)  //need exception handling if buy qnt is not int
                {
                    pnamearr[k]=pname;
                    pidarr[k]=pid;
                    costparr[k]=costp;
                    sellparr[k]=sellp;
                    qntarr[k]=*buyqnt;
                    k++;
                    total_amount= *total_amount+(sellp(*buyqnt));
                    edit_file(qnt-(*buyqnt));
                }else{
                    cout<<"this quantity is not available..."<<endl;
                }
            }
        }
        cout<<"enter:\n1. add another product\n0. end the bill\nor any other key to cancel the bill"<<endl;
        cin>>choice;
        break;
        }

        case '0':
        {
            system("CLS");
            list_upper_margin();
            for(int i=0;i< k;i++)
            {
                pname=pnamearr[i];
                pid=pidarr[i];
                costp=costparr[i];
                sellp=sellparr[i];
                qnt=qntarr[i];
                list_main_part(i+1);
            }
            list_lower_margin();
            float value=*total_amount;
            float disc=discount<float>(10,value);
            cout<<"total amount: "<<*total_amount<<endl;
            cout<<"total discount (10%): "<<disc<<endl;
            cout<<"total amount payable: "<<*total_amount-disc<<endl;

            cout<<"Enter y to exit: "<<endl;
            cin>>choice;
            break;
            
        }

        default:
        cout<<"bill cancelled."<<endl;
        break;
        }
        
    }while(choice=='1'||choice=='0');

    delete total_amount;
    delete [] costparr;
    delete [] sellparr;
    delete [] profitarr;
    delete [] pnamearr;
    delete [] pidarr;
    delete [] qntarr;
    delete [] buyqntarr;
    delete search;
    delete file;
    delete [] results;
    delete buyqnt;
    

}



int main()
{
    shop s;
    logo l;
    app_display(l);
    s.Login();
    return 0;
} 

// function ovewrriding is done and we could use friend function in login function