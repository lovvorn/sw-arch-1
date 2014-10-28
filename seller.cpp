class Seller { 
	private:
		int SellerID;
		string SellerName;
	public:
		void setID(int tid){SellerID=tid;}
		int getID() { return SellerID; }
		string getName() { return SellerName; }
		void setName(string tname){SellerName=tname;}
		
		//Constructor
		Seller(int, string);
		
};