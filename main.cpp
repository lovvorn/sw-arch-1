#include <iostream>

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

int main()
{

}
void initSellers()
{
		sellers[0] = new Seller(0, "Bob Ross");
		sellers[1] = new Seller(1, "Andy Warhol");
		sellers[2] = new Seller(2, "Phil Robinson");
		sellers[3] = new Seller(3, "Jack Williams");
		sellers[4] = new Seller(4, "Billy the Kid");
		sellerIndex = 5;
}

void initItems()
{
	items[0] = new Item (0, 200.00, 4, -1, -1, "Mona Lisa");
	items[1] = new Item (1, 25.00, 3, -1, -1, "Toast with Mary Burn");
	items[2] = new Item (2, 5000.00, 2, -1, -1, "First Lightbullb");
	items[3] = new Item(3, 9000.00, 1, -1, -1, "Banana Peel");
	items[4] = new Item(4, 1000000.00, 0, -1, -1, "Happy Little Tree");
	itemIndex = 5;
}

Display(){
	for(int i=0;i<itemIndex;i++)
	{
		cout<<"Item %d information:"<<i;
		cout<<"Item Id: "<<items[i].getID()<<"\n";
		cout<<"Item Name: "<<items[i].getName()<<"\n";
		cout<<"Item highestPrice: "<<items[i].getHighestPrice()<<"\n";
		cout<<"Item highestBidder: "<<items[i].getHighestBidder()<<"\n";

	}
}
menu(){
		cout<<"1. List Items\n2. Bid Items\n3. Add Buyers\n4. Add Item\n5. Display Transaction\n6. Exit"
		
        cin>>choice;
		if(choice==1){Display();}
	}
        cin>>choice;
                         if (choice==2) {?();)}
            
        cin>>choice;
                         if (choice==3) {?();)}
            
        cin>>choice;
                         if (choice==4) {?();)}
                         
        cin>>choice;
                         if (choice==5) {?();)}
                         
        cin>>choice;
                         if (choice==6) {?();)}

