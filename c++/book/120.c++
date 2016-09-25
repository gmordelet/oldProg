#include<iostream>
#include"Sales_item.h"

int main()
{
  Sales_item bookCur, bookIn;
  int count = 1;

  std::cin >> bookCur;
  while(std::cin >> bookIn)
    {
      if(bookCur.isbn() == bookIn.isbn())
	{
	  ++count;
	}
      else
	{
	  std::cout << bookCur << " apparait " << count << " fois" << std::endl;
	  bookCur = bookIn;
	  count = 1;
	}
    }

  std::cout << bookCur << " apparait " << count << " fois" << std::endl;

  return 0;
}
