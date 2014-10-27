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
	items[0] = new Item (0, 200.00, 4, -1, -1, "
	itemIndex = 5;
}

menu(){
	cout<<"What you want to do?\n"
    cout<<"1. List Items\n2. Bid Items\n3. Add Buyers\n4. Add Item\n5. Display Transaction\n6. Exit"
	}
