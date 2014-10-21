class Item {
	private:
		int id;
		double startingPrice;
		int sellerID;
		double highestPrice;
		int highestBidder;
		string name;
	public:
		int getID() { return id; }
		double getStartingPrice() { return startingPrice; }
		int getSellerID() { return sellerID; }
		double getHighestPrice() { return highestPrice; }
		int getHighestBidder() { return highestBidder; }
		string getName() { return name; }		
}
