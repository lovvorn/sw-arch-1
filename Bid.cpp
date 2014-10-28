class Bid{
	private: 
		int BidID;
		int BuyerID;
		int ItemID;
		double proposed_price;
	public:
		Bid(){}
		void setData(int biid, int bid, int iid, double price){BidID = biid; BuyerID=bid; ItemID=iid; proposed_price=price;}
		int getID() { return BidID; }
		void setID(int bid){BidID=bid;}
};