#include <iostream>
#include <string>
#include <sys/time.h>
#include <iomanip>

#if 0 // STL EXAMPLE
#include <vector>
#include <map>
namespace ft = std;
#else
#include "vector.hpp"
#include "map.hpp"
#endif

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

void print_test_time(const struct timeval &start)
{
  struct timeval end;
  gettimeofday(&end, NULL);
  std::cout << KBLU "Time spent : ";
  std::cout << (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec) << " units" << KNRM << std::endl;
}

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp
{
  bool operator()(const char &lhs, const char &rhs) const
  {
    return lhs < rhs;
  }
};

// MAIN

int main()
{
  struct timeval start_time;

  ///////////////////////////////////**VECTOR**///////////////////////////////////
  std::cout << KYEL "///////////////////////////////////**VECTOR**";
  std::cout << "///////////////////////////////////" KWHT << std::endl;
  std::cout << std::endl;
  //  CONSTRUCTING VECTORS
  {
    gettimeofday(&start_time, NULL);
    std::cout << KYEL "CONSTRUCTOR TESTS..." KWHT << std::endl;
    // The contents of fifth are: 16 2 77 29
    ft::vector<int> first;                               // empty vector of ints
    ft::vector<int> second(4, 100);                      // four ints with value 100
    ft::vector<int> third(second.begin(), second.end()); // iterating through second
    ft::vector<int> fourth(third);                       // a copy of third

    int myints[] = {16, 2, 77, 29};
    ft::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

    std::cout << "The contents of fifth are:";
    for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // OPERATOR =
  {
    std::cout << KYEL "OPERATOR = TESTS..." KWHT << std::endl;
    ft::vector<int> foo(3, 0);
    ft::vector<int> bar(5, 0);

    bar = foo;
    foo = ft::vector<int>();

    std::cout << "Size of foo: " << int(foo.size()) << '\n';
    std::cout << "Size of bar: " << int(bar.size()) << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // BEGIN ITERATOR TEST
  {
    std::cout << KYEL "BEGIN ITERATOR TESTS..." KWHT << std::endl;
    ft::vector<int> myvector;
    for (int i = 1; i <= 5; i++)
      myvector.push_back(i);

    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  // BEGIN REVERSE ITERATOR TEST
  {
    std::cout << KYEL "BEGIN REVERSE ITERATOR TESTS..." KWHT << std::endl;
    ft::vector<int> myvector(5); // 5 default-constructed ints

    int i = 0;

    ft::vector<int>::reverse_iterator rit = myvector.rbegin();
    for (; rit != myvector.rend(); ++rit)
      *rit = ++i;

    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // END ITERATOR TEST
  {
    std::cout << KYEL "END ITERATOR TESTS..." KWHT << std::endl;
    ft::vector<int> myvector;
    for (int i = 1; i <= 5; i++)
      myvector.push_back(i);

    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  // END REVERSE ITERATOR TEST
  {
    std::cout << KYEL "END REVERSE ITERATOR TESTS..." KWHT << std::endl;
    ft::vector<int> myvector(5); // 5 default-constructed ints

    ft::vector<int>::reverse_iterator rit = myvector.rbegin();

    int i = 0;
    for (rit = myvector.rbegin(); rit != myvector.rend(); ++rit)
      *rit = ++i;

    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // SIZE TEST
  {
    std::cout << KYEL "SIZE TESTS..." KWHT << std::endl;
    ft::vector<int> myints;
    std::cout << "0. size: " << myints.size() << '\n';

    for (int i = 0; i < 10; i++)
      myints.push_back(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.insert(myints.end(), 10, 100);
    std::cout << "2. size: " << myints.size() << '\n';

    myints.pop_back();
    std::cout << "3. size: " << myints.size() << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // MAX SIZE TESTS
  {
    std::cout << KYEL "MAX SIZE TESTS..." KWHT << std::endl;
    ft::vector<int> myvector;

    // set some content in the vector:
    for (int i = 0; i < 100; i++)
      myvector.push_back(i);

    std::cout << "size: " << myvector.size() << "\n";
    std::cout << "capacity: " << myvector.capacity() << "\n";
    std::cout << "max_size: " << myvector.max_size() << "\n";
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // RESIZE TESTS
  {
    std::cout << KYEL "RESIZE TESTS..." KWHT << std::endl;
    ft::vector<int> myvector;

    // set some initial content:
    for (int i = 1; i < 10; i++)
      myvector.push_back(i);

    myvector.resize(5);
    myvector.resize(8, 100);
    myvector.resize(12);

    std::cout << "myvector contains:";
    for (int i = 0; i < static_cast<int>(myvector.size()); i++)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // CAPACITY TESTS
  {
    std::cout << KYEL "CAPACITY TESTS..." KWHT << std::endl;
    ft::vector<int> myvector;

    // set some content in the vector:
    for (int i = 0; i < 100; i++)
      myvector.push_back(i);

    std::cout << "size: " << (int)myvector.size() << '\n';
    std::cout << "capacity: " << (int)myvector.capacity() << '\n';
    std::cout << "max_size: " << (int)myvector.max_size() << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // EMPTY TESTS
  {
    std::cout << KYEL "EMPTY TESTS..." KWHT << std::endl;
    ft::vector<int> myvector;
    int sum(0);

    for (int i = 1; i <= 10; i++)
      myvector.push_back(i);

    while (!myvector.empty())
    {
      sum += myvector.back();
      myvector.pop_back();
    }
    std::cout << "total: " << sum << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // RESERVE TESTS
  {
    std::cout << KYEL "RESERVE TESTS..." KWHT << std::endl;
    ft::vector<int>::size_type sz;

    ft::vector<int> foo;
    sz = foo.capacity();
    std::cout << "making foo grow:\n";
    for (int i = 0; i < 100; ++i)
    {
      foo.push_back(i);
      if (sz != foo.capacity())
      {
        sz = foo.capacity();
        std::cout << "capacity changed: " << sz << '\n';
      }
    }

    ft::vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100); // this is the only difference with foo above
    std::cout << "making bar grow:\n";
    for (int i = 0; i < 100; ++i)
    {
      bar.push_back(i);
      if (sz != bar.capacity())
      {
        sz = bar.capacity();
        std::cout << "capacity changed: " << sz << '\n';
      }
    }
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // OPERATOR [] TESTS
  {
    std::cout << KYEL "OPERATOR [] TESTS..." KWHT << std::endl;

    ft::vector<int> myvector(10); // 10 zero-initialized elements

    ft::vector<int>::size_type sz = myvector.size();

    // assign some values:
    for (unsigned i = 0; i < sz; i++)
      myvector[i] = i;

    // reverse vector using operator[]:
    for (unsigned i = 0; i < sz / 2; i++)
    {
      int temp;
      temp = myvector[sz - 1 - i];
      myvector[sz - 1 - i] = myvector[i];
      myvector[i] = temp;
    }

    std::cout << "myvector contains:";
    for (unsigned i = 0; i < sz; i++)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // AT TESTS
  {
    std::cout << KYEL "AT TESTS..." KWHT << std::endl;
    ft::vector<int> myvector(10); // 10 zero-initialized ints

    // assign some values:
    for (unsigned i = 0; i < myvector.size(); i++)
      myvector.at(i) = i;

    std::cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); i++)
      std::cout << ' ' << myvector.at(i);
    std::cout << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  //  FRONT TESTS
  {
    std::cout << KYEL "FRONT TESTS..." KWHT << std::endl;
    ft::vector<int> myvector;

    myvector.push_back(78);
    myvector.push_back(16);

    // now front equals 78, and back 16

    myvector.front() -= myvector.back();

    std::cout << "myvector.front() is now " << myvector.front() << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // BACK TESTS
  {
    std::cout << KYEL "BACK TESTS..." KWHT << std::endl;
    ft::vector<int> myvector;

    myvector.push_back(10);

    while (myvector.back() != 0)
    {
      myvector.push_back(myvector.back() - 1);
    }

    std::cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); i++)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  //  ASSIGN TESTS
  {
    std::cout << KYEL "ASSIGN TESTS..." KWHT << std::endl;
    ft::vector<int> first;
    ft::vector<int> second;
    ft::vector<int> third;

    first.assign(7, 100); // 7 ints with a value of 100

    ft::vector<int>::iterator it;
    it = first.begin() + 1;

    second.assign(it, first.end() - 1); // the 5 central values of first

    int myints[] = {1776, 7, 4};
    third.assign(myints, myints + 3); // assigning from array.

    std::cout << "Size of first: " << int(first.size()) << '\n';
    std::cout << "Size of second: " << int(second.size()) << '\n';
    std::cout << "Size of third: " << int(third.size()) << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // INSERT TESTS
  {
    std::cout << KYEL "INSERT TESTS..." KWHT << std::endl;
    ft::vector<int> myvector(3, 100);
    ft::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert(it, 200);

    myvector.insert(it, 2, 300);

    it = myvector.begin();

    ft::vector<int> anothervector(2, 400);
    myvector.insert(it + 2, anothervector.begin(), anothervector.end());

    int myarray[] = {501, 502, 503};
    myvector.insert(myvector.begin(), myarray, myarray + 3);

    std::cout << "myvector contains:";
    for (it = myvector.begin(); it < myvector.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // ERASE TESTS
  {
    std::cout << KYEL "ERASE TESTS..." KWHT << std::endl;
    ft::vector<int> myvector;
    // set some values (from 1 to 10)
    for (int i = 1; i <= 10; i++)
      myvector.push_back(i);

    // erase the 6th element
    myvector.erase(myvector.begin() + 5);

    // erase the first 3 elements:
    myvector.erase(myvector.begin(), myvector.begin() + 3);

    std::cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); ++i)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // SWAP TESTS
  {
    std::cout << KYEL "SWAP TESTS..." KWHT << std::endl;
    ft::vector<int> foo(3, 100); // three ints with a value of 100
    ft::vector<int> bar(5, 200); // five ints with a value of 200

    foo.swap(bar);

    std::cout << "foo contains:";
    for (unsigned i = 0; i < foo.size(); i++)
      std::cout << ' ' << foo[i];
    std::cout << '\n';

    std::cout << "bar contains:";
    for (unsigned i = 0; i < bar.size(); i++)
      std::cout << ' ' << bar[i];
    std::cout << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // CLEAR TESTS
  {
    std::cout << KYEL "CLEAR TESTS..." KWHT << std::endl;
    ft::vector<int> myvector;
    myvector.push_back(100);
    myvector.push_back(200);
    myvector.push_back(300);

    std::cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); i++)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';

    myvector.clear();
    myvector.push_back(1101);
    myvector.push_back(2202);

    std::cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); i++)
      std::cout << ' ' << myvector[i];
    std::cout << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // GET ALLOCATOR TESTS
  {
    std::cout << KYEL "ALLOCATOR TESTS..." KWHT << std::endl;
    ft::vector<int> myvector;
    int *p;
    unsigned int i;

    // allocate an array with space for 5 elements using vector's allocator:
    p = myvector.get_allocator().allocate(5);

    // construct values in-place on the array:
    for (i = 0; i < 5; i++)
      myvector.get_allocator().construct(&p[i], i);

    std::cout << "The allocated array contains:";
    for (i = 0; i < 5; i++)
      std::cout << ' ' << p[i];
    std::cout << '\n';

    // destroy and deallocate:
    for (i = 0; i < 5; i++)
      myvector.get_allocator().destroy(&p[i]);
    myvector.get_allocator().deallocate(p, 5);
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // NON-MEMBER RELATIONAL OPERATORS
  {
    std::cout << KYEL "NON-MEMBER RELATIONAL OPERATORS TESTS..." KWHT << std::endl;
    ft::vector<int> foo(3, 100); // three ints with a value of 100
    ft::vector<int> bar(2, 200); // two ints with a value of 200

    if (foo == bar)
      std::cout << "foo and bar are equal\n";
    if (foo != bar)
      std::cout << "foo and bar are not equal\n";
    if (foo < bar)
      std::cout << "foo is less than bar\n";
    if (foo > bar)
      std::cout << "foo is greater than bar\n";
    if (foo <= bar)
      std::cout << "foo is less than or equal to bar\n";
    if (foo >= bar)
      std::cout << "foo is greater than or equal to bar\n";
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////
  // NON-MEMBER SWAP TESTS
  {
    std::cout << KYEL "NON-MEMBER SWAP OPERATORS TESTS..." KWHT << std::endl;
    ft::vector<int> foo(3, 100); // three ints with a value of 100
    ft::vector<int> bar(5, 200); // five ints with a value of 200

    foo.swap(bar);

    std::cout << "foo contains:";
    for (ft::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "bar contains:";
    for (ft::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
    print_test_time(start_time);
  }
  std::cout << std::endl;
  /////////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////**MAP**///////////////////////////////////
  std::cout << KYEL "///////////////////////////////////**MAP**";
  std::cout << "///////////////////////////////////" KWHT << std::endl;
  std::cout << std::endl;

  //  CONSTRUCTING MAP
  {
    ft::map<char, int> mymap;
    ft::map<char, int>::iterator it;

    mymap['a'] = 50;
    mymap['b'] = 100;
    mymap['c'] = 150;
    mymap['d'] = 200;

    it = mymap.find('b');
    if (it != mymap.end())
      mymap.erase(it);

    // print content:
    std::cout << "elements in mymap:" << '\n';
    std::cout << "a => " << mymap.find('a')->second << '\n';
    std::cout << "c => " << mymap.find('c')->second << '\n';
    std::cout << "d => " << mymap.find('d')->second << '\n';
  }
}
