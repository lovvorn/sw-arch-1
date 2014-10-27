class transaction{
	private:
		int TranId;
		int SellerId;
		int BuyerId;
	public:
		transaction(int sid, int bid, int tid){TranId=tid; SellerId=sid; BuyerId=bid;}
		int getID() { return TranId; }
		setId(int tid){TranId=tid;}

}