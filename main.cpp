#include <iostream>
#include <fstream>
using namespace std;

class shopping{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void reciept();

};

void shopping::menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t ____________________________________ \n";
    cout<<"\t\t\t\t         Supermarket Main menu       \n";
    cout<<"\t\t\t\t                                     \n";
    cout<<"\t\t\t\t ____________________________________ \n";
    cout<<"\t\t\t\t                                     \n";
    cout<<"\t\t\t\t|      1) Administrator              |\n";
    cout<<"\t\t\t\t|                                    |\n";
    cout<<"\t\t\t\t|      2) Buyer                      |\n";
    cout<<"\t\t\t\t|                                    |\n";
    cout<<"\t\t\t\t|      3) Exit                       |\n";
    cout<<"\t\t\t\t|                                    |\n";

    cout<<"\n\t\t\t Please enter your choice :: ";
    cin>>choice;

    if(choice==1){
        cout<<"\t\t\t Please login \n ";
        cout<<"\t\t\t Enter email : ";
        cin>>email;
        cout<<"\t\t\t Enter password : ";
        cin>>password;

        if(email=="mohdali@gmail.com" && password=="mohdali@123"){
            administrator();
        }
        else{
            cout<<"\t\t\tInvalid email/password\n"<<endl;
        }
    }
    else if(choice==2){
        buyer();
    }
    else if(choice==3){
        exit(0);
    }
    else{
        cout<<"\t\t\tPLEASE ENTER A VALID KEY!"<<endl;
    }

    goto m;
}

void shopping::administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|______1) Add the product_________|";
    cout<<"\n\t\t\t|______2) Modify the product______|";
    cout<<"\n\t\t\t|______3) Delete the product______|";
    cout<<"\n\t\t\t|______4) Back to Main Menu_______|";

    cout<<"\n\n\t\t Please enter your choice : ";
    cin>>choice;

    if(choice==1){
        add();
    }
    else if(choice==2){
        edit();
    }
    else if(choice==3){
        rem();
    }
    else if(choice==4){
        menu();
    }
    else{
        cout<<"\t\t\tPLEASE ENTER A VALID KEY!"<<endl;
    }

    goto m;
}

void shopping::buyer(){
    m:
    int choice;
    cout<<"\t\t\t   Buyer \n";
    cout<<"\t\t\t ______________   \n";
    cout<<"\t\t\t                  \n";
    cout<<"\t\t\t 1) Buy Product   \n";
    cout<<"\t\t\t                  \n";
    cout<<"\t\t\t 2) Go Back       \n";

    cout<<"\t\t\t Please Enter your choice : ";
    cin>>choice;

    if(choice==1){
        reciept();
    }
    else if(choice==2){
        menu();
    }
    else{
        cout<<"\t\t\tPLEASE ENTER A VALID KEY!"<<endl;
    }

    goto m;
}

void shopping::add(){
    m:
    fstream data;
    int c;
    int token=0;
    float p,d;
    string n;

    cout<<"\n\n\t\t\t Add New Product";
    cout<<"\n\n\t Product code of the product : ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product : ";
    cin>>pname;
    cout<<"\n\n\t Price of the product : ";
    cin>>price;
    cout<<"\n\n\t Discount on the product : ";
    cin>>dis;

    data.open("Product_Database.txt",ios::in);

    if(!data){
        data.open("Product_Database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
        data.close();
    }
    else{
        data>>c>>n>>p>>d;

        while(!data.eof()){
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

        if(token==1){
                goto m;
        }
        else{
            data.open("Product_Database.txt",ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();
        }
    }

    cout<<"\n\n\t\t Record Inserted!"<<endl;
}

void shopping::edit(){
    fstream data,data1;
    int pkey,token=0,c;
    float p,d;
    string n;

    cout<<"\n\t\t\t Modify the Record\n\t\t\t___________________\n";
    cout<<"\n\t\t\t Product Code : ";
    cin>>pkey;

    data.open("Product_Database.txt",ios::in);
    if(!data){
        cout<<"\n\n File doesn't Exist!"<<endl;
    }
    else{
        data1.open("Product_Database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\t Product new code : ";
                cin>>c;
                cout<<"\n\t\t Name of Product : ";
                cin>>n;
                cout<<"\n\t\t Price : ";
                cin>>p;
                cout<<"\n\t\t Discount : ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited !"<<endl;
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("Product_Database.txt");
        rename("Product_Database1.txt","Product_Database.txt");

        if(token==0){
            cout<<"\n\n\t\t Record Not Found Sorry!"<<endl;
        }
    }
}

void shopping::rem(){
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t __________Delete Product__________";
    cout<<"\n\n\t Product Code : ";
    cin>>pkey;

    data.open("Product_Database.txt",ios::in);
    if(!data){
        cout<<"\tFile doesn't exist!"<<endl;
    }
    else{
        data1.open("Product_Database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
                if(pcode==pkey){
                    cout<<"\n\n\t Product Deleted Successfully"<<endl;
                    token++;
                }
                else{
                    data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
                }
                data>>pcode>>pname>>price>>dis;
        }
    }
    data.close();
    data1.close();

    remove("Product_Database.txt");
    rename("Product_Database1.txt","Product_Database.txt");

    if(token==0){
        cout<<"\n\n Record Not Found Sorry!"<<endl;
    }
}


void shopping::list(){
    fstream data;
    data.open("Product_Database.txt",ios::in);
    cout<<"\n\n__________________________________________________________________\n";
    cout<<"Prod_no \t\t Name \t\t\t Price \t\t dis\n";
    cout<<"\n\n__________________________________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<pcode<<"\t\t\t"<<pname<<"\t\t\t"<<price<<"\t\t\t"<<dis<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping::reciept(){
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0,dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t __________________RECIEPT__________________";

    data.open("Product_Database.txt",ios::in);
    if(!data){
        cout<<"\n\nEmpty Database"<<endl;
    }
    else{
        data.close();

        list();
        cout<<"\n_________________________________________________________\n";
        cout<<"\n                                                         \n";
        cout<<"\n                Please place the order                   \n";
        cout<<"\n_________________________________________________________\n";
        cout<<"\n                                                         \n";

        do{
            m:
            cout<<"\n\n Enter Product Code : ";
            cin>>arrc[c];
            cout<<"\n\n Enter Product Quantity : ";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\n Duplicate product Code, Please try again!"<<endl;
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product, if yes press y else press n : ";
            cin>>choice;
        }
        while(choice=='y');

        cout<<"\n\n\t\t\t________________________RECIEPT_______________________\n";
        cout<<"Product No \t   Product Name \t\t Product Quantity \t Price \t\t Amount \t Amount after discount\n";
        for(int i=0;i<c;i++){
            data.open("Product_Database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total+=dis;
                    cout<<pcode<<"\t\t\t"<<pname<<"\t\t\t"<<arrq[i]<<"\t\t\t"<<price<<"\t\t"<<amount<<"\t\t\t"<<dis<<"\n";
                }
                data>>pcode>>pname>>price>>dis;
            }
            data.close();
        }

    }
    cout<<"\n\n_______________________________________________________________";
    cout<<"\n Total Amount : "<<total<<endl;
}

int main()
{
    shopping s;
    s.menu();
}
