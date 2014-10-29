#include<string>

class Buyer {
	private:
		int BuyerID;
		std::string BuyerName;
	public:
		int getBuyerID() { return BuyerID; }
		std::string getBuyerName() {return BuyerName;}
		void setId(int tid) {BuyerID=tid;} // not sure about it!
		void setName(std::string tname) {BuyerName=tname;} // not sure about it!!
		
		Buyer(){};
		void setData(int id, std::string name){BuyerID=id; BuyerName=name;}
};
