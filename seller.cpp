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
		Seller(){};
		void setData(int _SellerID, string _SellerName) { SellerID = _SellerID; SellerName = _SellerName; }
		
};