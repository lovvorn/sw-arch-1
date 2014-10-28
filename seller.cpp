class Seller { 
	private:
		int SellerID;
		string SellerName;
	public:
		setID(int tid){SellerID=tid;}
		int getID() { return SellerID; }
		string getName() { return SellerName; }
		setName(string tname){SellerName=tname;}
		
		//Constructor
		Seller(int, string);
		
}
