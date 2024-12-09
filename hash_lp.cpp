#include <cassert>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

#include "hash_lp.h"

Table::Table( )
{
   used = 0;
   for ( int i = 0; i < CAPACITY; i++ )
      table[i].key = -1;
}

void Table::insert( const RecordType& entry )
{
   bool alreadyThere;
   int index;
   
   assert( entry.key >= 0 );
   
   findIndex( entry.key, alreadyThere, index );
   if( alreadyThere ){
      table[index] = entry;  
   } 
   else
   {
      assert( size( ) < CAPACITY );
      index = hash( entry.key );
      while ( table[index].key != -1 ){
         index = ( index + 1 ) % CAPACITY;
      }
      table[index] = entry;
      used++;
   }
}

void Table::insertQuadraticHashing(const RecordType& entry){
   assert( entry.key >= 0 );
   assert( size( ) < CAPACITY );
   int attempt =  0;
   int index = QuadraticProbing (entry.key, attempt);

   while (table[index].key != -1 && table[index].key != entry.key) {
        attempt++;
        if (attempt >= CAPACITY) {
            cerr <<"Error: table is full.\n";
            return;
        }
        index = QuadraticProbing(entry.key, attempt);
    }

    if (table[index].key == -1) {
      used++;
    }
    table[index] = entry;
}

void Table::insertDoubleHashing(const RecordType& entry){
   assert( entry.key >= 0 );
   assert( size( ) < CAPACITY );
   int attempt =  0;

   int index = DoubleHashing(entry.key, attempt);
   while (table[index].key != -1 && table[index].key != entry.key) {
        attempt++;
        if (attempt >= CAPACITY) {
            cerr<<"Error: table is full.\n";
            return; 
        }
        index = DoubleHashing(entry.key, attempt);
    }

    if (table[index].key == -1) {
      used++;
    }
    table[index] = entry;
}

void Table::insertMidSquareHashing(const RecordType& entry){
   assert( entry.key >= 0 );
   assert( size( ) < CAPACITY );
   int index = MidSquareHashing(entry.key);

   while (table[index].key != -1 && table[index].key != entry.key) {
        index = (index + 1) % CAPACITY;
    }

    if (table[index].key == -1)
    {
      used++;
    }
    table[index] = entry;
}

int Table::hash( int key ) const
{
   return key % CAPACITY;
}
int Table::QuadraticProbing(int key, int attempt) const {
    return (hash(key) + attempt * attempt) % CAPACITY;
}

int Table::DoubleHashing(int key, int attempt) const {
    int hashFunc1 = hash(key);
    int hashFunc2 = 1 + (key % (CAPACITY - 1));
    return (hashFunc1 + attempt * hashFunc2) % CAPACITY;
}

int Table::MidSquareHashing(int key) const {
    long long squared = static_cast<long long>(key) * key;

    
    string sqrdSTR = to_string(squared);

   
    int length = sqrdSTR.length();
    int start = max(0, length / 2 - 1); 
    int end = min(start + 3, length);   
    string midStr = sqrdSTR.substr(start, end - start);
    int hashValue = stoi(midStr) % CAPACITY;

    return hashValue;
}


int Table::size( ) const
{
   return used;
}  



void Table::findIndex( int key, bool& found, int& i ) const
{
   int count = 0;
   
   assert( key >=0 );

   i = hash( key );
   while ( count < CAPACITY && table[i].key != -1 && table[i].key != key )
   {
      count++;
      i = (i + 1) % CAPACITY;
   }   
   found = table[i].key == key;
}

void Table::find( int key, bool& found, RecordType& result ) const
{
   int index;
   
   assert( key >=0 );
   
   findIndex( key, found, index );
   if ( found )
      result = table[index];
}

void Table::erase( int key, bool& found, RecordType& del ) {
  int index;

  assert (key >= 0);

  findIndex(key, found, index);
  if(found){
   table[index].key = -1;
   table[index].data = 0;
   used --;
  }


}

void Table::print( )
{
   cout << "The hash table is: " << endl;
   cout << "Index Key Data" << endl;
   for( int i=0; i < CAPACITY; i++ )
   {
   cout << setw(5) << i
   << setw(5) << table[i].key;
   if ( table[i].key != -1 )
   cout << setw(8) << table[i].data;
   cout << endl;
   }
   cout << endl;
}

