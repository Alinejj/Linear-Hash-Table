#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

#include "hash_lp.h"

void print_menu( );

int main( )
{
    RecordType entries[] = {
    {2, 100},  {46, 200}, {139, 500}, {17, 1200}, {48, 1300}
};
   
    //List test;     // A List to perform tests on
    char choice;   // Command entered by the user
    int key;
    bool found;
    int size;
    RecordType rec;

    Table dataTable;
    Table QuadraticTable;
    Table DoubleHashTable;
    Table MidSquareTable;
   
    

    for (const auto& rec : entries) {
        dataTable.insert(rec);   
        QuadraticTable.insertQuadraticHashing(rec); 
        DoubleHashTable.insertDoubleHashing(rec); 
        MidSquareTable.insertMidSquareHashing(rec);   
    }

    // Print initial tables
    cout << "Initial Hash Tables:\n";
    cout << "Linear Probing Table:\n";
    dataTable.print();
    cout << "Quadratic Probing Table:\n";
    QuadraticTable.print();
    cout << "Double Hashing Table:\n";
    DoubleHashTable.print();
    cout << "Mid-Square Hashing Table:\n";
    MidSquareTable.print();
    
    do
    {
        print_menu( );
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl; 
        choice = toupper(choice);
        
        switch (choice)
        {
            case 'I': //insert with linear probing
                      cout << "Enter key (int >= 0) for record: ";
                      cin >> rec.key;
                      cout << "Enter data (int) for record: ";
                      cin >> rec.data;
                      dataTable.insert( rec );
                      cout << "Record was inserted in table using Linear Probing" << endl << endl;
		              dataTable.print();
                      break;
            case 'P'://insert with quadratic
                      cout << "Enter key (int >= 0) for record: ";
                      cin >> rec.key;
                      cout << "Enter data (int) for record: ";
                      cin >> rec.data;
                      QuadraticTable.insertQuadraticHashing(rec);
                      cout << "Record was inserted in table using Quadratic Hashing" << endl << endl;
		              QuadraticTable.print();
                      break;
            case 'H'://insert with double hash
                     cout << "Enter key (int >= 0) for record: ";
                      cin >> rec.key;
                      cout << "Enter data (int) for record: ";
                      cin >> rec.data;
                      DoubleHashTable.insertDoubleHashing(rec);
                      cout << "Record was inserted in table using Double Hashing" << endl << endl;
		              DoubleHashTable.print();
                      break;
            case 'M'://insert with midsquare hashing
                      cout << "Enter key (int >= 0) for record: ";
                      cin >> rec.key;
                      cout << "Enter data (int) for record: ";
                      cin >> rec.data;
                      MidSquareTable.insertMidSquareHashing(rec);
                      cout << "Record was inserted in table using Midsquare Hashing" << endl << endl;
		              MidSquareTable.print();
                      break;
            case 'F': // find
                      cout << "Enter key (int >= 0) to search for: ";
                      cin >> key;
                      dataTable.find( key, found, rec );
                      if ( found )
                      {
                         cout << "Record was found." << endl;
                         cout << "   key            = " << setw(8) 
                              << rec.key << endl;
                         cout << "   data = " << setw(8) 
                              << rec.data << endl << endl;
                      }
                      else
                         cout << "Record with key " << key << " not found." 
                              << endl << endl;
                      break;
            case 'S': // size
                      size = dataTable.size( );
                      cout << "There are " << size << " records in the table." 
                           << endl;
                      cout << "There are " << (CAPACITY - size) 
                           << " empty slots left in the table." << endl << endl;
                      break;
            case 'D':
                      cout<<"Enter key (int >=0) to delete: ";
                      cin>>key;
                      dataTable.erase( key, found, rec );
                      if (found ){
                        cout<<"Record with key "<<key<<" was deleted"<<endl;
                      }
                      else{
                        cout<<"Record with key "<<key<<" was not found"<<endl;
                      }
                      dataTable.print();
                      break;
            case 'Q': cout << "Test program ended." << endl;
                      break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));

    return EXIT_SUCCESS;
}

void print_menu( )
{
    cout << endl; 
    cout << "The following choices are available: " << endl;
    cout << " I   Insert a new record using Linear Probing" << endl;
    cout<<" P    Insert a new record using Quadratic Probing"<<endl;
    cout<<" H    Insert a new record using Double Hashing"<<endl;
    cout<<" M    Insert a new record using Mid-Square Hashing"<<endl;
    cout << " F   Find a record" << endl;
    cout << " S   Get the number of records" << endl;
    cout<<" D   Delete a record"<<endl;
    cout << " Q   Quit this test program" << endl << endl;
}
