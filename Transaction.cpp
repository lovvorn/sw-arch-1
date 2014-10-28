class transaction{
	private:
		int TranID;
		int SellerID;
		int BuyerID;
	public:
		transaction(int sid, int bid, int tid){TranID=tid; SellerID=sid; BuyerID=bid;}
		int getID() { return TranID; }
		setID(int tid){TranID=tid;}
		int getSellerID() { return SellerID; }
		setSellerID(int sid){SellerID=sid;}
		int getBuyerID() { return BuyerID; }
		setBuyerID(int bid){BuyerID=bid;}

}