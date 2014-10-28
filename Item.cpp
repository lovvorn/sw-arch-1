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
		void setSold(bool _sold) { sold = _sold; }
		
		//Constructor
		Item(){}
		void setData(int _id, double _startingPrice, int _sellerID, double _highestPrice, int _highestBidder, string _name, bool _sold) {id = _id; startingPrice = _startingPrice; sellerID = _sellerID; highestPrice = _highestPrice; highestBidder = _highestBidder; name = _name; sold = _sold;}
};