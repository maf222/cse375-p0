// CSE 375/475 Assignment #1
// Fall 2021
//
// Description: This file implements a function 'run_custom_tests' that should be able to use
// the configuration information to drive tests that evaluate the correctness
// and performance of the map_t object.

#include <iostream>
#include <ctime>
#include "config_t.h"
#include "tests.h"
#include <unordered_map>

#include "simplemap.h"

	    void printer(int k, float v) {
			std::cout<<"<"<<k<<","<<v<<">"<< std::endl;
	}
int initialize_map ()
{
  unordered_map < int, float >simplemap;
  // Declaring simplemap_t to be of <string, double> type
  // key will be of int  type and mapped value will be type float

  // inserting values by using [] operator\
  int sum = 0;
  int maxSum = 100000;
  int i = 0;
  int sum = 0;
  int random_integer;
  int lowest = 10, highest = 1000;
  int range = (highest - lowest) + 1;
  while (sum != maxSum || sum < maxSum)
    {
      int value = lowest + rand () % range;
      if ((sum + value) <= maxSum)
	{
	  simplemap.insert (make_pair (i, value));
	  sum = sum + value;
	}
      else if ((sum + value) > maxSum)
	{
	  if (sum < maxSum)
	    {
	      value = maxSum - sum;
	      simplemap.insert (make_pair (i, value));
	      sum = sum + value;
	    }
	  else if (sum > maxSum);
	}
      i++;
    }
  printf ("%d",sum);


  //string key = "PI";

  // If key not found in map iterator to end is returned
  // if (umap.find(key) == umap.end())
  //     cout << key << " not found\n\n";

  // If key found then iterator to that key is returned
  // else
  //     cout << "Found " << key << "\n\n";

  // key = "lambda";
  // if (umap.find(key) == umap.end())
  //     cout << key << " not found\n";
  // else
  //     cout << "Found " << key << endl;

  //    iterating over all value of umap
  int bankSum = 0;
  unordered_map < int, float >::iterator itr;
  cout << "\nAll Elements : \n";
  for (itr = simplemap.begin (); itr != simplemap.end (); itr++)
    {
      // itr works as a pointer to pair<string, double>
      // type itr->first stores the key part  and
      // itr->second stores the value part
      cout << itr->first << "  " << itr->second << endl;
      bankSum += itr->second;
    }
    printf ("%d\n", bankSum);
    int mapSize = simplemap.size();
    printf("%d", mapSize);
    return simplemap.size();
}

void transaction (int key1, int key2, float ammount){
    
}
int main ()
{
  
}
	void run_custom_tests(config_t& cfg) {

    // Declaring simplemap_t to be of <string, double> type
    // key will be of int  type and mapped value will be type float
 
    // inserting values by using [] operator\
	int sum = 0;
		int size = initialize_map ();
   int random_integer;
  int lowestVal = 10, highestVal = 1000;
  int rangeVal = (highestVal - lowestVal) + 1;
   float ammount = lowestVal + rand () % rangeVal;
    int lowest = 0;
    int highest = size;
    int range = (highest - lowest) + 1;
    int key1 = lowest + rand () % range;
    int key2 = lowest + rand () % range;
    while (key1 == key2){
        key2 = lowest + rand () % range;
    }
    transaction(key1, key2, ammount);
  return 0;

 
    //string key = "PI";
 
    // If key not found in map iterator to end is returned
    // if (umap.find(key) == umap.end())
    //     cout << key << " not found\n\n";
 
    // If key found then iterator to that key is returned
    // else
    //     cout << "Found " << key << "\n\n";
 
    // key = "lambda";
    // if (umap.find(key) == umap.end())
    //     cout << key << " not found\n";
    // else
    //     cout << "Found " << key << endl;
 
    //    iterating over all value of umap
		// Step 1
		// Define a simplemap_t of types <int,float>
		// this map represents a collection of bank accounts:
		// each account has a unique ID of type int;
		// each account has an amount of fund of type float.

		// Step 2
		// Populate the entire map with the 'insert' function
		// Initialize the map in a way the sum of the amounts of
		// all the accounts in the map is 100000

		/*int sum = 0;
		int maxSum = 100000;
		i = 0;
		while sum != maxSum ||  sum < maxSum{
			int value = random(between 10 and 1000);
			if((sum + value) <= maxSum){
				insert(i, value);
				sum = sum + value;
			}
			elseif((sum + value)> maxSum){
				if (sum < maxSum){
					value = maxSum - sum;
				}
				elseif(sum > maxSum)
			}
		i++;
		}*\

		// Step 3
		// Define a function "deposit" that selects two random bank accounts
		// and an amount. This amount is subtracted from the amount
		// of the first account and summed to the amount of the second
		// account. In practice, give two accounts B1 and B2, and a value V,
		// the function performs B1-=V and B2+=V.
		// The execution of the whole function should happen atomically:
		// no operation should happen on B1 and B2 (or on the whole map?)
		// while the function executes.

		// Step 4
		// Define a function "balance" that sums the amount of all the
		// bank accounts in the map. In order to have a consistent result,
		// the execution of this function should happen atomically:
		// no other deposit operations should interleave.

		// Step 5
		// Define a function 'do_work', which has a for-loop that
		// iterates for config_t.iters times. In each iteration,
		// the function 'deposit' should be called with 95% of the probability;
		// otherwise (the rest 5%) the function 'balance' should be called.
		// The function 'do_work' should measure 'exec_time_i', which is the
		// time needed to perform the entire for-loop. This time will be shared with
		// the main thread once the thread executing the 'do_work' joins its execution
		// with the main thread.

		// Step 6
		// The evaluation should be performed in the following way:
		// - the main thread creates #threads threads (as defined in config_t)
		//   << use std:threds >>
		// - each thread executes the function 'do_work' until completion
		// - the (main) spawning thread waits for all the threads to be executed
		//   << use std::thread::join() >>
		//	 and collect all the 'exec_time_i' from each joining thread
		//   << consider using std::future for retireving 'exec_time_i' after the thread finishes its do_work>>
		// - once all the threads have joined, the function "balance" must be called

		// Make sure evey invocation of the "balance" function returns 100000.

		// Step 7
		// Now configure your application to perform the SAME TOTAL amount
		// of iterations just executed, but all done by a single thread.
		// Measure the time to perform them and compare with the time
		// previously collected.
		// Which conclusion can you draw?
		// Which optimization can you do to the single-threaded execution in
		// order to improve its performance?

		// Step 8
		// Remove all the items in the map by leveraging the 'remove' function of the map
		// Destroy all the allocated resources (if any)
		// Execution terminates.
		// If you reach this stage happy, then you did a good job!

		// Final step: Produce plot
    // I expect each submission to include at least one plot in which
    // the x-axis is the concurrent threads used {1;2;4;8}
    // the y-axis is the application execution time.
    // The performance at 1 thread must be the sequential
    // application without synchronization primitives

    // You might need the following function to print the entire map.
    // Attention if you use it while multiple threads are operating
    map.apply(printer);

	}

void test_driver(config_t &cfg) {
	run_custom_tests(cfg);
}
