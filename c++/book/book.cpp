#include<iostream>

int main()
{
  int x1, x2, temp;

  std::cout << "x1 et x2 ? " << std::endl;
  std::cin >> x1 >> x2;

  if(x1 > x2)
    {
      temp = x1;
      x1 = x2;
      x2 = temp;
    }

  while(x1 <= x2)
    {
      std::cout << x1 << std::endl;
      ++x1;
    }

  return 0;
}
