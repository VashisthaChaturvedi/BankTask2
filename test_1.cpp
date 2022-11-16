#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
/*
    1.- create account
    2.- login in the account
    3.- deposit money on the account
    4.- withdraw money from their account
    5. check balance
    6.- transfer money done
    7.- card no.
    8.- PIN to securely start transaction
    9.


*/
string AccNames[50];
int AccNums[50];
int AccPins[50];
double AccMoney[50];
int i=0;
int main();
void trasfer();
void crtacc()
{
    srand(time(0));
    int accnum = rand();
    for(int j=0;j<i;j++)
    {
        if(accnum != AccNums[j])
        {
            continue;
        }
        else if(accnum == AccNums[j])
        {
            crtacc();
        }// to eliminate the condition that account created might generate two same account number

    }
    string accname;

    cout << "Enter name"<<endl;
    cin >>accname;
    AccNames[i]=accname;
    AccNums[i] = accnum;

    cout << "\nYour Card number is     " << accnum<<endl;
    cout << "Enter PIN for your Login during transaction( MUST REMEMBER )"<<endl;
    cin>> AccPins[i];
    i++;

}
int j;
void login()
{
    int a;
    cout << "Enter Account Number(login to start any transaction):      "<<endl;
    cin >> a;
    for(j =0;j<=i;)
    {
        if(a== AccNums[j])
        {
            cout << "Your name is   "<< AccNames[j]<<endl;
            cout <<" If above mentioned name is yours. ENTER 1. Otherwise Enter 0."<<endl;
            int check ;
            cin>>check;
            if(check == 1)
            {
                cout << "Enter PIN"<<endl;
                int accpin;
                cin >> accpin;
                if(accpin == AccPins[j])
                {
                    cout << "Account Login Successful !"<<endl;
                    cout <<"Account Number :        "<<AccNums[j]<<endl;
                    cout << "Account Name:       "<<AccNames[j]<<endl;
                    //cout <<"TEST =  "<< j<<endl;
                    break;
                }
                else
                {
                    cout << "Incorrect PIN"<<endl;
                    check=0;
                    cout<<"if you want to try again. Enter 1. otherwise Enter 0."<<endl;
                    cin >> check;
                    if(check == 1)
                    {
                        cout << "you will get only 3 attempts to Enter correct Pin"<<endl;
                        for(check=1;check<=3;check++)
                        {
                            cout << "attempt "<<check<<" Enter:  "<<endl;
                            cin>>accpin;
                            if(accpin == AccPins[j])
                            {
                                cout <<"Login Successful!"<<endl;
                                break;
                            }
                            else if(check == 3)
                            {
                                cout << "login Unsuccessful ! ";
                                break;
                            }
                        }

                    }
                    else if (check ==0)
                    {
                        cout << "Returned to the main Page :    "<<endl;
                        main();
                    }

                }
            }
            else if(check ==0)
            {
                //think of what to do further
                cout<< "do you want to try again Enter 1 to exit program enter 0."<<endl; // THINK MORE.
                cin>> check;
                if(check == 1)
                {
                    login();
                }
                else if(check ==0)
                {
                   main();
                   break;
                }
                else
                {
                    cout <<"wrong onput"<<endl;
                }


            }

        }
        else{
            j++;
        }
    }

}
void Deposit()
{
    login();
    if(j<i+1)
    {
         double deposit;
        cout << "Enter AMOUNT to be Deposited:      "<<endl;
        cin >> deposit;
        AccMoney[j]+=deposit;
        cout << " Money deposited successfully"<<endl;
        /*for(int o=0;o<50;o++)
        {
            cout << AccMoney[o]<<endl;
        }*/

    }
    else
    {
        cout<<"Not a valid account number"<<endl;

    }



}
void withdraw()
{
    login();
    cout << "Enter amount to be Withdrawn:        "<<endl;
    double money;
    cin >> money;
    cout << "Enter PIN (3 attempt Only) for your account ("<< AccNums[j] <<") Name : ("<<AccNames[j]<<endl;
    int pin;
    cin>>pin;
    if(money<=AccMoney[j])
    {
        for(int l =0;l<3;l++)
        {
            if(pin == AccPins[j])
            {
                cout <<"Withdarwn Securely ...\n";
                AccMoney[j]-=money;
                break;

            }
            else
            {
                cout << "Wrong PIN : Try Again:     "<<endl;
                cin>>pin;
            }

        }
    }
    else if (money>AccMoney[i])
    {
        cout << "Not enough Monney. poor !"<<endl;
    }
    main();



}
void transfer()
{
    login();
    cout << "Enter account number where money is to be transferred :   "<<endl;
    int Accdep;
    cin >> Accdep;
    int k=0;
    for(k = 0;k<50;)
    {
        if(Accdep == AccNums[k])
        {
            cout << "name of the person to deposit money:       " << AccNames[k]<<endl;
            break;
        }
        else if(k<49)
        {
            k++;
            continue;}
        else if(k==49)
        {
            cout << "Account number entered not correct."<<endl;
            cout <<" do you want to try again .Enter 1, otherwise enter 0"<<endl;
            cin >> k;
            if(k==1)
            {
                transfer();

            }
            else if(k==0)
            {
                k--;

                break;

            }
            else
            {
                cout<< "Wrong Input"<<endl;
                break;
            }
        }
    }
    if (k<=49 && k>=0)
    {
        cout << "Enter amount to be Transferred:        "<<endl;
        double money;
        cin >> money;
        cout << "Enter PIN (3 attempt Only) for your account ("<<AccNums[j]<<") Name : ("<<AccNames[j]<<")\n";
        int pin;
        cin>>pin;
        if(money<=AccMoney[j])
        {
            for(int l =0;l<3;l++)
            {
                if(pin == AccPins[j])
                {
                    cout <<"Paied Securely ...\n";
                    AccMoney[k]+=money;
                    AccMoney[j]-=money;
                    break;

                }
                else
                {
                    cout << "Wrong PIN : Try Again:     "<<endl;
                    cin>>pin;
                }

            }
        }
        else if (money>AccMoney[j])
        {
            cout << "Money Trasfer not possible. POOR!"<<endl;
        }
    }
    main();
}
void checkBalance()
{
    login();
    cout<<endl << "BALANCE of Account Number:     "<<AccNums[j]<<endl;
    cout <<endl<<" $ "<<AccMoney[j]<<endl;
}
int main()
{

    for(int l=0;l>=0;)
    {
        cout << "Welcome to BANK"<<endl;
        cout << "Enter task to be performed\n";

        cout << "1.Create Account   2.Check balance   3.Deposit Money   4.Withdraw Money   5.Transfer Money   6.EXIT Bank.  \n\nEnter number"<<endl<<endl;
        cin >>l;
        switch(l)
        {
            case 1 : crtacc();
            break;
            case 2 :
                     checkBalance();
                     break;
            case 3 :
                     Deposit();
                     break;
            case 4 :
                    withdraw();
                    break;
            case 5: transfer();
                    break;
            case 6 : cout <<"Thankyou for using BANK. \n";
                    break;
            default : cout <<"WRONG INPUT\n";
        }
        if(l==6)
        {
            return 0;
            break;
        }
    }
    return 0;

}
