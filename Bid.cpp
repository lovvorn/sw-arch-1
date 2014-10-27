class Bid{
	private: 
		int BidId;
		int BuyerId;
		int ItemId;
		double proposed_price;
	public:
		Bid(int bid, int iid, double price){BuyerId=bid; ItemId=iid; proposed_price=price;}
		int getID() { return BidId; }
		setId(int bid){BidId=bid;}
}