class Bid{
	private: 
		int BidID;
		int BuyerID;
		int ItemID;
		double proposed_price;
	public:
		Bid(int bid, int iid, double price){BuyerID=bid; ItemID=iid; proposed_price=price;}
		int getID() { return BidID; }
		setID(int bid){BidID=bid;}
}