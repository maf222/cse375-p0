// CSE 375/475 Assignment #1
// Fall 2021
//
// Description: This file specifies a custom map implemented using two vectors.
// << use templates for creating a map of generic types >>
// One vector is used for storing keys. One vector is used for storing values.
// The expectation is that items in equal positions in the two vectors correlate.
// That is, for all values of i, keys[i] is the key for the item in values[i].
// Keys in the map are not necessarily ordered.
//
// The specification for each function appears as comments.
// Students are responsible for implementing the simple map as specified.

#include <vector>
#include <cassert>
#include <unordered_map>

//using namespace std;

//template <class K, class V>
class simplemap_t
{
    //std::unordered_map<K, V> map;
        // Define the two vectors of types K and V
        // << use std::vector<K> >>

        public :

        // The constructor should just initialize the vectors to be empty
        simplemap_t()
    {
        assert("Not Implemented");
    }

    // Insert (key, val) if and only if the key is not currently present in
    // the map.  Returns true on success, false if the key was
    // already present.
    void insert(K key, V val, std::unordered_map < int, float >&map)
    {

        if (!map.insert({key, val}).second)
        {
        }
        std::unordered_map<int, float>::iterator itr;
        std::cout << "\nAll Elements : \n";
        for (itr = map.begin(); itr != map.end(); itr++)
        {
            // itr works as a pointer to pair<string, double>
            // type itr->first stores the key part  and
            // itr->second stores the value part
            std::cout << itr->first << "  " << itr->second << std::endl;
            //bankSum += itr->second;
        }
        //return true;

        // The following is just an example of using C++11 features,
        // like the 'auto' type and lambda expression
        /*
        for (auto i = keys->begin(); i != keys->end(); ++i)
            if (*i == key)
                return false;

        // insert the key and value.  Note that indices should, by default, match
        // between these two vectors.
        keys->push_back(key);
        values->push_back(val);
		*/
    }
    bool deposit(K key1, K key2, int ammount)
    {

        //printf ("key 1: %d\n", key1);
        //printf ("Key 2: %d\n", key2);
        auto it = map.find(key1);
        auto it2 = map.find(key2);
        if (it != map.end() && it2 != map.end())
        {

            float oldValue = it->second;
            //printf ("Ammount: %g\n", ammount);
            //printf ("Old Account1: %g\n", oldValue);
            //float new_value = it->second - ammount;

            float oldValue2 = it2->second;
            //printf ("Old Account2: %g\n", oldValue2);
            //float new_value2 = it2->second + ammount;

            if ((it->second-ammount) >= 0)
            {
                it->second = it->second - ammount;
                //float newValue = it->second;
                //printf ("New Account1: %g\n", newValue);

                it2->second = it2->second + ammount;
                //float newValue2 = it2->second;
                //printf ("New Account2: %g\n", newValue2);
            }
            else
            {
                //printf ("Error not enough money in account\n");
            }
        }
    }
    int balance()
    {
        int bankSum = 0;
        std::unordered_map<int, float>::iterator itr;
        std::cout << "\nAll Elements : \n";
        for (itr = map.begin(); itr != map.end(); itr++)
        {
            // itr works as a pointer to pair<string, double>
            // type itr->first stores the key part  and
            // itr->second stores the value part
            //cout << itr->first << "  " << itr->second << endl;
            bankSum += itr->second;
        }
        printf("%d\n", bankSum);
        return bankSum;
    }
    // If key is present in the data structure, replace its value with val
    // and return true; if key is not present in the data structure, return
    // false.
    bool update(K key, V val)
    {
        assert("Not Implemented");
        return false;
    }

    // Remove the (key, val) pair if it is present in the data structure.
    // Returns true on success, false if the key was not already present.
    bool remove(K key)
    {
        assert("Not Implemented");
        return false;
    }

    // If key is present in the map, return a pair consisting of
    // the corresponding value and true. Otherwise, return a pair with the
    // boolean entry set to false.
    // Be careful not to share the memory of the map with application threads, you might
    // get unexpected race conditions
    std::pair<V, bool> lookup(K key)
    {
        assert("Not Implemented");
        //TO DO: the following is a default return value, do not use it!
        return std::make_pair(0, false);
    }

    // Apply a function to each key in the map
    void apply(void (*f)(K, V))
    {
    }
};
