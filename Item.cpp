#include <string>

class Item {
	private:
		int id;
		double startingPrice;
		int sellerID;
		double highestPrice;
		int highestBidder;
		std::string name;
		bool sold;
	public:
		int getID() { return id; }
		double getStartingPrice() { return startingPrice; }
		int getSellerID() { return sellerID; }
		double getHighestPrice() { return highestPrice; }
		int getHighestBidder() { return highestBidder; }
		std::string getName() { return name; }
		bool isSold() { return sold; }
		void setSold(bool _sold) { sold = _sold; }
		void setHighestPrice(double price) {highestPrice = price; }
		void setHighestBidder(int bidder) {highestBidder = bidder; }
		
		//Constructor
		Item(){}
		void setData(int _id, double _startingPrice, int _sellerID, double _highestPrice, int _highestBidder, std::string _name, bool _sold) {id = _id; startingPrice = _startingPrice; sellerID = _sellerID; highestPrice = _highestPrice; highestBidder = _highestBidder; name = _name; sold = _sold;}
};
