/* DESIGN A VENDING MACHINE */
#include<iostream>
using namespace std;
class Inventory
{
	int coke,sprite,chips;
	static int coke_count,sprite_count,chips_count;
	public:
	Inventory()
	{
		coke=10;
		sprite=15;
		chips=20;
	}
	int getPrice(int item_num)
	{
		switch(item_num)
		{
			case 1: return coke;
			case 2: return sprite;
			case 3: return chips;
			default: return -1;
		}
	}
	bool isAvailable(int item_num)
	{
		switch(item_num)
		{
			case 1:
				if(coke_count==0) return false;
				else return true;
			case 2:
				if(sprite_count==0) return false;
				else return true;
			case 3:
				if(chips_count==0) return false;
				else return true;
			default: return false;
		}
	}
	int return_balance(int item_num,int cash)
	{
		int price=getPrice(item_num);
		if(price>cash) return -1;
		switch(item_num)
		{
			case 1: --coke_count;break;
			case 2: --sprite_count;break;
			case 3: --chips_count;break;
		}
		if(price==cash)
		{
			return 0;
		}
		else
		{
			return cash-price;
		}
	}
};
int Inventory::coke_count=1;
int Inventory::sprite_count=7;
int Inventory::chips_count=9;
int main()
{
	string ans;
	int item_num,cash;
	do
	{
		Inventory item;
		cout<<"\nEnter the item number to select:";
		cout<<endl<<"1.Coke ";
		cout<<endl<<"2.Sprite";
		cout<<endl<<"3.Chips";
		cout<<endl<<"-->";
		cin>>item_num;
		bool check=item.isAvailable(item_num);
		if(check)
		{
			int x=item.getPrice(item_num);
			if(x==-1)
				cout<<"\nWrong input!!";
			else
			{
				cout<<"\nPay Rs."<<x;
				cout<<"\nSubmit cash:(Enter 0 to exit):";
				cin>>cash;
				int paid=item.return_balance(item_num,cash);
				if(paid==-1) cout<<"\nNot enough cash inserted!";
				else
				{
					cout<<"\nPlease collect your balance of Rs."<<paid;
					cout<<"\nCollect the item.Thank You!!";		
				}

			}
		}
		else
		{
			cout<<"\nItem out of stock!";
		}
		cout<<"\nWant to buy more?(yes/no)";
		cin>>ans;
	}while(ans.compare("yes")==0);
	return 0;
}
