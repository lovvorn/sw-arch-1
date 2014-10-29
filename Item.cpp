#include <string>

class Item {

	private:

		int id;
		int sellerID;
		int highestBidder;

		double highestPrice;
		double startingPrice;

		bool sold;

		std::string name;

	public:

		//Constructor
		Item() {}

		int getID() { return id; }
		int getSellerID() { return sellerID; }
		int getHighestBidder() { return highestBidder; }

		double getStartingPrice() { return startingPrice; }
		double getHighestPrice() { return highestPrice; }

		std::string getName() { return name; }

		void setSold(bool _sold) { sold = _sold; }
		void setHighestPrice(double price) {highestPrice = price; }
		void setHighestBidder(int bidder) {highestBidder = bidder; }
		
		void setData(int _id,
				double _startingPrice,
				int _sellerID,
				double _highestPrice,
				int _highestBidder,
				std::string _name,
				bool _sold)
		{
			id = _id;
			startingPrice = _startingPrice;
			sellerID = _sellerID;
			highestPrice = _highestPrice;
			highestBidder = _highestBidder;
			name = _name;
			sold = _sold;
		}

		bool isSold() { return sold; }
};
