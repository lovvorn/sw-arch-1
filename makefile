CC=g++

CFLAGS=-c -Wall

all: driver 

driver: main.o Bid.o Buyer.o Item.o Transaction.o seller.o
	$(CC) main.o Bid.o Buyer.o Item.o Transaction.o seller.o -o driver

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Bid.o: Bid.cpp
	$(CC) $(CFLAGS) Bid.cpp

Buyer.o: Buyer.cpp
	$(CC) $(CFLAGS) Buyer.cpp

Item.o: Item.cpp
	$(CC) $(CFLAGS) Item.cpp

Transaction.o: Transaction.cpp
	$(CC) $(CFLAGS) Transaction.cpp

seller.o: seller.cpp
	$(CC) $(CFLAGS) seller.cpp

clean:
	rm -rf *.o driver
