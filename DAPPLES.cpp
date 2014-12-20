/*
2014-12-18
DAPPLES
http://pl.spoj.com/problems/DAPPLES/
Accepted
*/

#include <iostream>
#include <climits>

#include <list>

using std::cin;
using std::cout;
using std::endl;

// All length are in cm

const long long g = 1000; // [cm/(s^2)]
long long maxVel; // [cm/s] velocity needed to kill

long long calcualteTreeHeight(long long h){
  return maxVel * maxVel / (2 * g) + h;
}


class man{
public:
  man(long long h, long long age, long long growth){
    this->h = h;
    this->age = age;
    this->growth = growth;
  }

  // Return required tree height in a given year
  long long getTreeHeight(long long year){
    return maxVel * maxVel / (2 * g) + getHeight(year);
  }


protected:
  long long h; // [cm]
  long long growth; // [cm/year]
  long long age; // [year]

  long long heightAt20;

  long long getHeight(long long year){
    long long currentAge = age + year;
    if (currentAge < 20) {
      return h + year * growth;
    } else if (currentAge == 20) {
      heightAt20 = h + year * growth;;
      return heightAt20;
    } else {
      // > 20
      return heightAt20;
    }
  }
};

int main(){
  long long tests;
  cin >> tests;
  while (tests--) {
    cin >> maxVel;
    maxVel *= 100; // to cm/s
    long long citizenNumber;
    cin >> citizenNumber;

    long long minConstTreeHeight = INT_MAX; // [cm]
    long long minTreeHeight = INT_MAX; // for said year

    std::list<man> citizens;

    // Reading data
    for (long long i = 0; i < citizenNumber; ++i) {
      long long h, age, growth;
      cin >> h >> age >> growth;
      if (age >= 20) {
        long long treeHeight = calcualteTreeHeight(h);
        if (treeHeight < minConstTreeHeight) {
          minConstTreeHeight = treeHeight;
          if (minConstTreeHeight < minTreeHeight) {
            minTreeHeight = minConstTreeHeight;
          }
        }
      } else {
        man newMan = man(h, age, growth);
        citizens.push_back(newMan);

        long long treeHeight = newMan.getTreeHeight(0);
        if (treeHeight < minTreeHeight) {
          minTreeHeight = treeHeight;
        }
      }
    }
    cout << 0 << ": " << minTreeHeight << endl;

    // Calucalting data for 20 years

    for (long long y = 1; y <= 20; ++y) {
      minTreeHeight = minConstTreeHeight;
      for (std::list<man>::iterator it = citizens.begin(); it != citizens.end(); ++it) {
        long long treeHeight = (*it).getTreeHeight(y);
        if (treeHeight < minTreeHeight) {
          minTreeHeight = treeHeight;
        }
      }
      cout << y << ": " << minTreeHeight << endl;
    }
  }
  return 0;
}
