class Buyer {
	private:
		int BuyerID;
		string BuyerName;
	public:

		int getBuyerID() { return id; }
        	string getBuyerName() {return name;}
        	setId(int tid) {id=tid;} // not sure about it!
        	setName(String tname) {name=tname;} // not sure about it!!
}	

		int getID() { return BuyerID; }
        string getName() {return BuyerName;}
        setID(int tid) {BuyerID = tid;} // not sure about it!
        setName(string tname) {BuyerName = tname;} // not sure about it!!
		Buyer(int id, string name){BuyerID=id; BuyerName=name;}
}

