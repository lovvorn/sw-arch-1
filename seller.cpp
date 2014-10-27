class Seller { 
	private:
		int SellerId;
		string name;
	public:
		int getID() { return SellerId; }
		string getName() { return name; }
		setName(String tname){name=tname;}
		setId(int tid){id=tid;}
		
		//Constructor
		Seller(int, string);
		
}
