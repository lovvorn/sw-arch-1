#include<string>

class Seller { 
	private:
		int SellerID;
        std::string SellerName;
	public:
		void setID(int tid){SellerID=tid;}
		int getID() { return SellerID; }
        std::string getName() { return SellerName; }
		void setName(std::string tname){SellerName=tname;}
		
		//Constructor
		Seller();
		void setData(int, std::string);
		
};
