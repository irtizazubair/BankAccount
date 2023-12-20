#include <iostream>
#include <string>
using namespace std;

class Account{
	protected:
		string cnic,accounttitle;
		double balance;
		static int count;
	public:
	long accountnumber;	
	Account(){}
	    void AddAccount(string c, string acc_tit, long acc_num, double b){
		this->accountnumber=acc_num;
		this->accounttitle=acc_tit;
		this->balance=b;
		this->cnic=c;
		count++;
		cout<<"\tAccount added!"<<endl;
		cout<<"\nAccount Number: "<<accountnumber<<endl;
		cout<<"Account Title: "<<accounttitle<<endl;
		cout<<"Balance: "<<balance<<endl;
		cout<<"CNIC: "<<cnic<<endl;
		}
		void withdraw(double a){
			cout<<"\nProceeding Withdrawal"<<endl;
			double amount=a;
			cout<<"Withdrawal Amount= "<<amount<<endl;
			if(amount<=balance){
				balance-=amount;
				cout<<"Updated Balance= "<<balance<<endl;
			}
			else{
			cout<<"Not enough Balance!"<<endl;	
			}
		}
		void deposit(double a){
			cout<<"\nProceeding Deposit"<<endl;
			double amount=a;
			cout<<"Deposit Amount= "<<amount<<endl;
			if(amount>0){
				balance+=amount;
				cout<<"Updated Balance= "<<balance<<endl;
			}
			else{
			cout<<"Enter valid amount!"<<endl;	
			}
		}
		static int totalaccounts(){
			return count;
		}		
};
class CurrentAccount:public Account{
	protected:
		float servicefeerate;
	public:
		CurrentAccount(){}
		void AddAccount(string c, string acc_tit, long acc_num, double b,float sf){
		this->accountnumber=acc_num;
		this->accounttitle=acc_tit;
		this->balance=b;
		this->cnic=c;
		this->servicefeerate=sf;
		count++;
		cout<<"\tCurrent Account added!"<<endl;
		cout<<"\nAccount Number: "<<accountnumber<<endl;
		cout<<"Account Title: "<<accounttitle<<endl;
		cout<<"Balance: "<<balance<<endl;
		cout<<"CNIC: "<<cnic<<endl;
		cout<<"Service Fee: "<<servicefeerate<<endl;
		}
		static int totalaccounts(){
			return count;
		}
		void setServiceFee(float s){
			this->servicefeerate=s;
			balance-=servicefeerate;
			cout<<"\nService Fee = "<<servicefeerate<<endl;
		}
		void withdraw(double a){
			cout<<"\nProceeding Withdrawal from current Account"<<endl;
			double amount=a;
			cout<<"Withdrawal Amount= "<<amount<<endl;
			if(amount<=balance){
				balance-=amount;
				cout<<"Updated Balance= "<<balance<<endl;
			}
			else{
			cout<<"Not enough Balance!"<<endl;	
			}
		}
		void deposit(double a){
			cout<<"\nProceeding Deposit from Current Account"<<endl;
			double amount=a;
			cout<<"Deposit Amount= "<<amount<<endl;
			if(amount>0){
				balance+=amount;
				cout<<"Updated Balance= "<<balance<<endl;
			}
			else{
			cout<<"Enter valid amount!"<<endl;	
			}
		}
		int CheckBalance(){
            return balance;
		}
};
class SavingAccount:public Account{
	protected:
		float monthlyinterestrate;
	public:
		SavingAccount(){}
		void AddAccount(string c, string acc_tit, long acc_num, double b,float mir){
		this->accountnumber=acc_num;
		this->accounttitle=acc_tit;
		this->balance=b;
		this->cnic=c;
		this->monthlyinterestrate=mir;
		count++;
		cout<<"\tSaving Account added!"<<endl;
		cout<<"\nAccount Number: "<<accountnumber<<endl;
		cout<<"Account Title: "<<accounttitle<<endl;
		cout<<"Balance: "<<balance<<endl;
		cout<<"CNIC: "<<cnic<<endl;
		cout<<"Monthly Interest Rate = "<<monthlyinterestrate<<endl;
		}
		void setInterestRate(float mir){
			this->monthlyinterestrate=mir;
			cout<<"\nMonthly Interest Rate = "<<monthlyinterestrate<<endl;
		}
		void CheckBalance(){
			cout<<"New Balance = "<<balance<<endl;
		}
		static int totalaccounts(){
			return count;
		}
		float calculateInterestRate(){
			float cir=monthlyinterestrate*12;
			balance+=cir;
			cout<<"Balance after addition of Interest Rate (annually) = "<<balance<<endl;
		}
		void withdraw(double a){
			cout<<"\nProceeding Withdrawal from Savings Account"<<endl;
			double amount=a;
			cout<<"Withdrawal Amount= "<<amount<<endl;
			if(amount<=balance){
				balance-=amount;
				cout<<"Updated Balance= "<<balance<<endl;
			}
			else{
			cout<<"Not enough Balance!"<<endl;	
			}
		}
		void deposit(double a){
			cout<<"\nProceeding Deposit from Savings Account"<<endl;
			double amount=a;
			cout<<"Deposit Amount= "<<amount<<endl;
			if(amount>0){
				balance+=amount;
				cout<<"Updated Balance= "<<balance<<endl;
			}
			else{
			cout<<"Enter valid amount!"<<endl;	
			}
		}
};
class AccountTest {
public:
    void start(){
        const int max_c_acc=5;
        const int max_s_acc=5;

        CurrentAccount currentAccounts[max_c_acc];
        SavingAccount savingAccounts[max_c_acc];

        int currentCount = 0;
        int savingCount = 0;

        for (int choice = 0; choice != 6;) {
            displayMenu();
            cout<<"Enter your choice: ";
            cin>>choice;

            switch (choice){
                case 1:
                    if (currentCount<max_c_acc) {
                        addCurrentAccount(currentAccounts[currentCount++]);
                    } else {
                        cout<<"Maximum number of Current Accounts reached!"<<endl;
                    }
                    break;
                case 2:
                    if (savingCount<max_s_acc) {
                        addSavingAccount(savingAccounts[savingCount++]);
                    } else {
                        cout<< "Maximum number of Saving Accounts reached!" <<endl;
                    }
                    break;
                case 3:
                    depositMoney(currentAccounts, currentCount, savingAccounts, savingCount);
                    break;
                case 4:
                    withdrawMoney(currentAccounts, currentCount, savingAccounts, savingCount);
                    break;
                case 5:
                    checkBalance(currentAccounts, currentCount, savingAccounts, savingCount);
                    break;
                case 6:
                    cout<< "Exiting..." <<endl;
                    break;
                default:
                    cout<< "Invalid choice. Please try again." <<endl;
            }
        }
    }

    private:
    void displayMenu() {
        cout<< "\nBanking Application Menu" <<endl;
        cout<< "1. Add Current Account" <<endl;
        cout<< "2. Add Saving Account" <<endl;
        cout<< "3. Deposit Money" <<endl;
        cout<< "4. Withdraw Money" <<endl;
        cout<< "5. Check Balance" <<endl;
        cout<< "6. Exit" <<endl;
    }

    void addCurrentAccount(CurrentAccount &account) {
    string cnic, accountTitle;
    long accountNumber;
    double balance;
    float serviceFeeRate;

    cout<< "Enter CNIC: ";
    cin>> cnic;
    cout<< "Enter Account Title: ";
    cin>> accountTitle;
    cout<< "Enter Account Number: ";
    cin>> accountNumber;
    cout<< "Enter Initial Balance: ";
    cin>> balance;
    cout<< "Enter Service Fee Rate: ";
    cin>>serviceFeeRate;

    account.AddAccount(cnic, accountTitle, accountNumber, balance, serviceFeeRate);
    cout<< "Added a Current Account!" <<endl;
}


    void addSavingAccount(SavingAccount &account) {
    string cnic, accountTitle;
    long accountNumber;
    double balance;
    float mirr;

    cout<< "Enter CNIC: ";
    cin>>cnic;
    cout<< "Enter Account Title: ";
    cin>>accountTitle;
    cout<< "Enter Account Number: ";
    cin>>accountNumber;
    cout<< "Enter Initial Balance: ";
    cin>>balance;
    cout<< "Enter Monthly Interest Rate: ";
    cin>>mirr;

    account.AddAccount(cnic, accountTitle, accountNumber, balance, mirr);
        cout<< "Added a Saving Account!" <<endl;
    }

    void depositMoney(CurrentAccount currentAccounts[], int currentCount, SavingAccount savingAccounts[], int savingCount) {
    int accnum;
    double depositAmount;

    cout<< "Enter Account Number to Deposit: ";
    cin>>accnum;
    
    if (accnum >= 1001 && accnum <= 1005) { // Assuming account numbers for CurrentAccount start from 1001
        cout<< "Enter Deposit Amount: ";
        cin>>depositAmount;

        for (int i = 0; i < currentCount; ++i) {
            if (currentAccounts[i].accountnumber == accnum) {
                currentAccounts[i].deposit(depositAmount);
                cout<< "Deposit successful!" <<endl;
                return;
            }
        }
    } else {
        cout<< "Account not found or invalid account number." <<endl;
    }
}
    void withdrawMoney(CurrentAccount currentAccounts[], int currentCount, SavingAccount savingAccounts[], int savingCount) {
    int accnum;
    double withdrawAmount;

    cout<< "Enter Account Number to Withdraw: ";
    cin>>accnum;
    
    if (accnum >= 2001 && accnum <= 2005) { // Assuming account numbers for SavingAccount start from 20000001
        cout<< "Enter Withdrawal Amount: ";
        cin>> withdrawAmount;

        
        for (int i = 0; i < savingCount; ++i) {
            if (savingAccounts[i].accountnumber == accnum) {
                savingAccounts[i].withdraw(withdrawAmount);
                cout<< "Withdrawal successful!" <<endl;
                return;
            }
        }
    } else{
        cout<< "Account not found or invalid account number." <<endl;
    }
}


    void checkBalance(CurrentAccount currentAccounts[], int currentCount, SavingAccount savingAccounts[], int savingCount) {
    int accnum;

    cout<<"Enter Account Number to Check Balance: ";
    cin>>accnum;

    if (accnum >= 1001 && accnum <= 1005) { // Assuming account numbers for CurrentAccount start from 1001
        for (int i = 0; i < currentCount; ++i) {
            if (currentAccounts[i].accountnumber == accnum){
                cout<< "Current Balance: "<<currentAccounts[i].CheckBalance()<<endl;
                return;
            }
        }
    } else {
        cout<< "Account not found or invalid account number." <<endl;
    }
}
};


int Account::count=0;
int main(){
	AccountTest a;
	
	a.start();
	
	return 0;
}
