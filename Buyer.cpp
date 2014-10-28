class Buyer {
	private:
		int BuyerID;
		string BuyerName;
	public:
		int getID() { return BuyerID; }
        string getName() {return BuyerName;}
        setID(int tid) {BuyerID = tid;} // not sure about it!
        setName(string tname) {BuyerName = tname;} // not sure about it!!
		//Constructor
		Buyer(int id, string name){BuyerID=id; BuyerName=name;}
}
