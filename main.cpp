#include <iostream>
using namespace std;
#include "Bid.cpp"
#include "Buyer.cpp"
#include "Item.cpp"
#include "Transaction.cpp"
#include "seller.cpp"


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

void List_Items(){
	for(int i=0;i<itemIndex;i++)
	{
		if(!items[i].isSold())
		{
			cout<<"Item %d information:"<<i;
			cout<<"Item Id: "<<items[i].getID()<<"\n";
			cout<<"Item Name: "<<items[i].getName()<<"\n";
			cout<<"Item highestPrice: "<<items[i].getHighestPrice()<<"\n";
			cout<<"Item highestBidder: "<<items[i].getHighestBidder()<<"\n";
		}

	}
}
void Display_Trans(){

	for(int i=0;i<transactionIndex;i++)
	{
		
		cout<<"Transaction %d information:\n"<<i;
		cout<<"Transaction Id: "<<transactions[i].getID()<<"\n";
		cout<<"Seller Id: "<<transactions[i].getSellerID()<<"\n";
		cout<<"Buyer Id: "<<transactions[i].getBuyerID()<<"\n";
	
	}
}


void Add_Buyer(){
	string bname;
	int bid;
	cout<<"Enter buyer name";
	cin>>bname;
	buyers[buyerIndex].setData(buyerIndex, bname);
	buyerIndex++;
}

void Add_Item(){
	string iname;
	double price;
	int sid;
	cout<<"Enter the item name: "<<endl;
	cin>>iname;
	cout<<"Enter the starting price: "<<endl;
	cin>>price;
	cout<<"Enter your seller ID#: "<< endl;
	cin>>sid;
	items[itemIndex].setData(itemIndex, price, -1, -1, iname, false);
	itemIndex++;
}

void End_Bidding()
{
	int id;
	cout<<"What is the id of the item you wish to end bidding on?\n";
	cout<<"id: ";
	cin>>id;
	items[id].setSold(true);
	cout<<"\nItem status has been set to 'sold'\n";
}

void Bid()
{
	cout<<"\nbid\n";
}
void menu(){
		int choice;
		cout<<"1. List Items\n2. Bid Items\n3. Add Buyers\n4. Add Item\n5. Display Transaction\n6. Exit\nChoice: ";
        cin>>choice;
        if(choice==1){List_Items();}
        else if (choice==2) {Bid();}
        else if (choice==3) {Add_Buyer();}
        else if (choice==4) {Add_Item();}
        else if (choice==5) {Display_Trans();}
        else if (choice==6) {End_Bidding();}

}

int main()
{
	while(1)
	{
		menu();
	}
}


