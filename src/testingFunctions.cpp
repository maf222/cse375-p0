/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <unordered_map>
using namespace std;

  // Declaring simplemap_t to be of <string, double> type
  // key will be of int  type and mapped value will be type float

  // inserting values by using [] operator\
int sum = 0;



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
void
transaction (std::unordered_map < int, float >&simplemap)
{
  int mapSize = simplemap.size ();
  printf ("map size: %d\n", mapSize);
  int random_integer2;
  int lowestVal = 1, highestVal = 10;
  int rangeVal = (highestVal - lowestVal) + 1;

  int lowest2 = 0;
  int highest2 = mapSize;
  int range2 = (highest2 - lowest2) + 1;
    srand((unsigned int)time(NULL));
  float ammount = lowestVal + rand () % rangeVal;
  srand((unsigned int)time(NULL));
  int key1 = lowest2 + rand () % range2;
  srand((unsigned int)time(NULL));
  int key2 = lowest2 + rand () % range2;
  while (key1 == key2)
    {
        srand((unsigned int)time(NULL));
      key2 = lowest2 + rand () % range2;
    }
  printf ("key 1: %d\n", key1);
  printf ("Key 2: %d\n", key2);
  auto it = simplemap.find (key1);
  auto it2 = simplemap.find (key2);
  if (it != simplemap.end () && it2 != simplemap.end ())
    {

      float oldValue = it->second;
      printf ("Ammount: %g\n", ammount);
      printf ("Old Account1: %g\n", oldValue);
      float new_value = it->second - ammount;

      float oldValue2 = it2->second;
      printf ("Old Account2: %g\n", oldValue2);
      float new_value2 = it2->second + ammount;

      if (new_value >= 0)
	{
	  it->second = new_value;
	  float newValue = it->second;
	  printf ("New Account1: %g\n", newValue);

	  it2->second = new_value2;
	  float newValue2 = it2->second;
	  printf ("New Account2: %g\n", newValue2);
	}
      else
	{
	  printf ("Error not enough money in account\n");
	}
    }
}

void
balance (std::unordered_map < int, float >&simplemap)
{
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
}

int
main ()
{
  unordered_map < int, float >simplemap;
  int maxSum = 100000;
  int i = 0;
  int sum = 0;
  int random_integer;
  int lowest = 10, highest = 100;
  int range = (highest - lowest) + 1;
  srand((unsigned int)time(NULL));
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
  printf ("%d", sum);
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //return simplemap;
  srand((unsigned int)time(NULL));
  int choice = 1 + rand () % 100;
  printf ("choice: %d\n", choice);
  if (choice > 5){  transaction (simplemap);}
  else{balance (simplemap);}

  return 0;
}
