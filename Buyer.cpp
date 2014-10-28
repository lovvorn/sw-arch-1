class Buyer {
	private:
		int BuyerID;
		string BuyerName;
	public:
		int getBuyerID() { return BuyerID; }
		string getBuyerName() {return BuyerName;}
		void setId(int tid) {BuyerID=tid;} // not sure about it!
		void setName(string tname) {BuyerName=tname;} // not sure about it!!
		
		Buyer(int id, string name){BuyerID=id; BuyerName=name;}
};