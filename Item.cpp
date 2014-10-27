class Item {
	private:
		int id;
		double startingPrice;
		int sellerID;
		double highestPrice;
		int highestBidder;
		string name;
		bool sold;
	public:
		int getID() { return id; }
		double getStartingPrice() { return startingPrice; }
		int getSellerID() { return sellerID; }
		double getHighestPrice() { return highestPrice; }
		int getHighestBidder() { return highestBidder; }
		string getName() { return name; }
		bool isSold() { return sold; }
		
		//Constructor
		Item(int, double, int, double, int, string, bool);
}
