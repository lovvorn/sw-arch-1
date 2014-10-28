class Transaction{
	private:
		int TranID;
		int SellerID;
		int BuyerID;
	public:
		Transaction(int sid, int bid, int tid){TranID=tid; SellerID=sid; BuyerID=bid;}
		int getID() { return TranID; }
		void setID(int tid){TranID=tid;}
		int getSellerID() { return SellerID; }
		void setSellerID(int sid){SellerID=sid;}
		int getBuyerID() { return BuyerID; }
		void setBuyerID(int bid){BuyerID=bid;}

};