#include <iostream>
#include <stdlib.h>

#include "Bid.cpp"
#include "Buyer.cpp"
#include "Item.cpp"
#include "Transaction.cpp"
#include "seller.cpp"

using namespace std;

Item items[20];
Buyer buyers[20];
Seller sellers[20];
Transaction transactions[20];
Bid bids[200];

int itemIndex = 0;
int buyerIndex = 0;
int sellerIndex = 0;
int transactionIndex = 0;
int bidIndex = 0;

void initSellers()
{
	sellers[0].setData(0, "Bob Ross");
	sellers[1].setData(1, "Andy Warhol");
	sellers[2].setData(2, "Phil Robinson");
	sellers[3].setData(3, "Jack Williams");
	sellers[4].setData(4, "Billy the Kid");
	sellerIndex = 5;
}

void initItems()
{
	items[0].setData(0, 200.00, 4, -1, -1, "Mona Lisa", false);
	items[1].setData(1, 25.00, 3, -1, -1, "Toast with Mary Burn", false);
	items[2].setData(2, 5000.00, 2, -1, -1, "First Lightbulb", false);
	items[3].setData(3, 9000.00, 1, -1, -1, "Banana Peel", false);
	items[4].setData(4, 1000000.00, 0, -1, -1, "Happy Little Tree", false);
	itemIndex = 5;
}

void List_Items()
{
	for(int i = 0; i < itemIndex; i++)
	{
		if(!items[i].isSold())
		{
			cout << "Item Id: "
				 << items[i].getID()
				 << endl;

			cout << "Item Name: "
				 << items[i].getName()
				 << endl;

			if (items[i].getHighestPrice() > 0)
			{
				cout << "Item highestPrice: "
					 << items[i].getHighestPrice()
					 << endl;

				cout << "Item highestBidder: " 
					 << buyers[items[i].getHighestBidder()].getBuyerName()
					 << endl;
			}
			else
			{
				cout << "This item has not been bidded on.\n";
			}
		}

	}
}

void Display_Trans()
{

	for(int i = 0; i < transactionIndex; i++)
	{
		cout << "Transaction Id: "
			 << transactions[i].getID()
			 << endl;

		cout << "Seller: "
			 << sellers[transactions[i].getSellerID()].getName()
			 << endl;

		cout << "Buyer: "
			 << buyers[transactions[i].getBuyerID()].getBuyerName()
			 << endl;
	}
}


void Add_Buyer()
{
	string bname;

	cout << "Enter buyer name: ";
	cin  >> bname;
	
	buyers[buyerIndex].setData(buyerIndex, bname);
	buyerIndex++;
}

void Add_Item()
{
	string iname;
	double price;
	int sid;
	
	cout << "Enter the item name: "<<endl;
	cin  >> iname;
	
	cout << "Enter the starting price: "<<endl;
	cin  >> price;

	cout << "Enter your seller ID#: "<< endl;
	cin  >> sid;

	items[itemIndex].setData(itemIndex, price, sid, -1.00, -1, iname, false);
	itemIndex++;
}

void End_Bidding()
{
	int id;

	cout << "What is the id of the item you wish to end bidding on?" << endl
		 << "id: ";
	cin  >> id;

	items[id].setSold(true);

	cout << endl
		 << "Item status has been set to 'sold'"
		 << endl;
	
	transactions[transactionIndex].setData(transactionIndex + 1, items[id].getSellerID(), items[id].getHighestBidder());
	transactionIndex++;
}

void Bid() 
{
	int BuyerID;
	int ItemID;
	double proposed_price;

	cout << "What is the ID of the buyer: ";
	cin  >> BuyerID;

	cout << "What is the item ID: ";
	cin  >> ItemID;

	cout << "What is your bid: $";
	cin  >> proposed_price;
	
	if(proposed_price >= items[ItemID].getStartingPrice())
	{
		bids[bidIndex].setData(bidIndex + 1, BuyerID, ItemID, proposed_price);
		bidIndex++;
	}

	if((items[ItemID].getHighestPrice() < proposed_price) && (proposed_price >= items[ItemID].getStartingPrice()))
	{
		items[ItemID].setHighestPrice(proposed_price);
		items[ItemID].setHighestBidder(BuyerID);
	}
}

void menu()
{
		int choice;

		cout << "1. List Items" << endl
			 << "2. Bid Items" << endl
			 << "3. Add Buyers" << endl
			 << "4. Add Item" << endl
			 << "5. Display Transaction" << endl
			 << "6. End Bidding" << endl
			 << "7. Exit" << endl
			 << "Choice: ";
		cin  >> choice;

		if (choice == 1)      { List_Items(); }
		else if (choice == 2) { Bid(); }
		else if (choice == 3) { Add_Buyer(); }
		else if (choice == 4) { Add_Item(); }
		else if (choice == 5) { Display_Trans(); }
		else if (choice == 6) { End_Bidding(); }
		else if (choice == 7) { exit(1); }

}

int main()
{
	initItems();
	initSellers();
	while(1)
	{
		menu();
	}
}


