class Buyer {
	private:
		int BuyerID;
		string BuyerName;
	public:
		int getBuyerID() { return id; }
		string getBuyerName() {return name;}
		void setId(int tid) {id=tid;} // not sure about it!
		void setName(String tname) {name=tname;} // not sure about it!!
		
		Buyer(int id, string name){BuyerID=id; BuyerName=name;}
}

