//------------------hashmap.h--------------------
//Group 23 CSS 343 Section B
//Creation Date: 2/23/18
//Last Modification: 3/1/18
//-----------------------------------------------
//Purpose - Header file for the HashMap class
//contains all function/field declarations
//Allows the storage of items with quick lookup
//by key rather than by index
//-----------------------------------------------
//Notes - This hashmap will used seperate chaining
//to handle collisions. Note this will also manage
//the memory of the items you pass it (meaning that
//it won't copy new data you add, but will delete
//it upon the destruction of the hashmap)
//-----------------------------------------------

#ifndef HASHMAP_H
#define HASHMAP_H

template <typename K, typename V>
class HashMap {
public:
	//---------------constructor/destructors---------------
	//default constructor simply initializes the map array
	HashMap();

	//destructor which will delete the map and all the values in the map
	virtual ~HashMap();

	//------------------utility functions------------------
	//Returns the pointer to a value for the stored data for the
	//corresponding key parameter
	//Will return a null pointer if no value is found for the associated key
	V* get(const K &key) const;

	//Adds a new value with its associated key to the hashmap
	//Note you must pass in a value pointer (existing on the heap) which
	//will not be copied, but will de deleted upon destruction of this map
	//Returns true if added, or false if an entry with that key already exists
	bool put(const K &key, V* value);

	//Removes a particular value from this hashmap
	//associated with the corresponding key parameter
	//Will return true if successful, or false if it never existed
	bool remove(const K &key);
private:
	//-------------------private structs-------------------
	//Node for the linked list chains for each 'bucket' in the map array
	struct HashNode {
		K key;
		V* value;
		HashNode* next;
	}

	//------------------private functions------------------
	//this is the hashing function for the hashmap which takes in a key
	//and returns the hash which is the corresponding index for the map array
	int hashFunc(const K &key) const;

	//-----------------private fields(data)------------------
	//array of linked lists for HashNodes (the map itself)
	HashNode** map;
};

#endif