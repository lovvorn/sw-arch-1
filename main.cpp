#include <iostream>

using namespace std;


int main()
{
	
}

menu(){
	cout<<"What you want to do?\n"
	cout<<"1. List Items\n2. Bid Items\n"
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
