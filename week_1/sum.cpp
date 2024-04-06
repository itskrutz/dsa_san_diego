#include <iostream>

int sum(int first, int second){
	return (first+second);
}

int main()
{
	int a=0;
	int b=0;
	std::cin>>a>>b;
	int sum_of=sum(a,b);
	std::cout<<sum_of;
	return 0;
}
	



