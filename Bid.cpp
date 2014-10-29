class Bid{

	private: 

		int BidID;
		int BuyerID;
		int ItemID;

		double proposed_price;

	public:

		Bid() {}

		int getID() { return BidID; }

		void setData(int biid, int bid, int iid, double price)
		{
			BidID = biid;
			BuyerID = bid;
			ItemID = iid;
			proposed_price = price;
		}

		void setID(int bid) { BidID = bid; }

};
