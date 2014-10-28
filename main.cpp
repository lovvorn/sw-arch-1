#include <iostream>
#include <stdlib.h>
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
            cout<<"Item Id: "<<items[i].getID()<<"\n";
            cout<<"Item Name: "<<items[i].getName()<<"\n";
			if (items[i].getHighestPrice() > 0)
			{
				cout<<"Item highestPrice: "<<items[i].getHighestPrice()<<"\n";
				cout<<"Item highestBidder: "<<items[i].getHighestBidder()<<"\n";
			} else {
				cout<<"This item has not been bidded on.\n";
			}
        }

    }
}

void Display_Trans(){

    for(int i=0;i<transactionIndex;i++)
    {
        cout<<"Transaction Id: "<<transactions[i].getID()<<"\n";
        cout<<"Seller: "<<sellers[transactions[i].getSellerID()].getName()<<"\n";
        cout<<"Buyer: "<<buyers[transactions[i].getBuyerID()].getBuyerName()<<"\n";
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
    items[itemIndex].setData(itemIndex, price, sid, -1.00, -1, iname, false);
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
	
	int TranID;
		int SellerID;
		int BuyerID;
	transactions[transactionIndex].setData(transactionIndex++, items[id].getSellerID(), items[id].getHighestBidder());
}

void Bid() {
	int BuyerID;
	int ItemID;
	double proposed_price;
	cout<<"What is the ID of the buyer: ";
	cin>>BuyerID;
	cout<<"What is the item ID: ";
	cin>>ItemID;
	cout<<"What is your bid: $";
	cin>>proposed_price;
	
	bids[bidIndex].setData(bidIndex++, BuyerID, ItemID, proposed_price);
	if(items[ItemID].getHighestPrice() < proposed_price)
		items[ItemID].setHighestPrice(proposed_price);
		items[ItemID].setHighestBidder(BuyerID);
}

void menu(){
        int choice;
        cout<<"1. List Items\n2. Bid Items\n3. Add Buyers\n4. Add Item\n5. Display Transaction\n6. End Bidding\n7. Exit\nChoice: ";
        cin>>choice;
        if(choice==1){List_Items();}
        else if (choice==2) {Bid();}
        else if (choice==3) {Add_Buyer();}
        else if (choice==4) {Add_Item();}
        else if (choice==5) {Display_Trans();}
        else if (choice==6) {End_Bidding();}
		else if (choice==7) {exit(1);}

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


