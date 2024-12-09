#ifndef HASH_LP_H
#define HASH_LP_H

typedef int ItemType; 
const int CAPACITY = 31;

struct RecordType
{
       int key;
       ItemType data;
};

class Table
{
public:
   Table( );
   //inserting the hash functions
   void insert( const RecordType& entry );
    void insertQuadraticHashing(const RecordType& entry);
   void insertDoubleHashing(const RecordType& entry);
   void insertMidSquareHashing(const RecordType& entry);



   void find( int key, bool& found, RecordType& result ) const; 
   int size( ) const;
   void erase( int key, bool& found, RecordType& del) ; 
   void print();

private:
   // HELPER FUNCTIONS 
   int hash( int key ) const;
   void findIndex( int key, bool& found, int& i ) const;
   
   //collision methods
   int QuadraticProbing(int key, int attempt) const;
   int DoubleHashing(int key, int attempt) const;
   int MidSquareHashing(int key) const;
   

   // DATA MEMBERS
   RecordType table[CAPACITY];
   int used;
};

#endif