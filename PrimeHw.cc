// Mustafa Jamshidi(T686B548)
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool isPrime( int number){
 // guard negative numbers, 0 and 1, as they are not considered as prime numbers. 
 if ( number % 2 == 0 || number % 3 == 0) {
 return false; 
 }
 // possible factors starts from 2 (inclusive) and goes all the way to sqrt(n) + 1 (inclusive) 
 for (int i = 5; i *i <=number; i=i+6){ 
 if (number % i ==0 || number % (i +2)== 0)
 return false; 
 }
 // no factor found, return true
 return true; 
}
//quadratic formula n2 + n + 41 will produce 40 primesI
int prime40(int number) {
 for (int i = 0; i < number; i++) {
 int prime = i * i + i + 41;
 if(isPrime(prime)) {
 cout<<prime<<", ";
 }
 }
}
//quadratic formula n2 – 79n + 1601 produces 80 prime
int prime80(int number) {
 for(int i = 0; i < number; i++) {
 int prime = i * i - 79 * i +1601;
 if(isPrime(prime)) {
 cout<<prime<<" ,";
 }
 }
}
// -999 <= a <= 999 and -1000 <= b <= 1000
void findMaxPrimesForQuadratic() {
 int maxConsecutivePrimes = 0;
 int bestA = 0;
 int bestB = 0;
 for (int a = -999; a <= 999; a++) {
 for (int b = -1000; b <= 1000; b++) {
 int n = 0;
 while (isPrime(n * n + a * n + b)) {
 n++;
 }
 if (n > maxConsecutivePrimes) {
 maxConsecutivePrimes = n;
 bestA = a;
 bestB = b;
 }
 }
 }
 cout << "Best 'a' = " << bestA << "\n";
 cout << "Best 'b' = " << bestB << "\n";
 cout << "Maximum prime numbers = " << maxConsecutivePrimes << "\n";
}
int main(){
 cout<<"The 40 Primes:\n";
 prime40(40);
 cout<<endl;
 cout<<endl;
 cout<<"The 80 Primes:\n";
 prime80(80);
 cout<<endl;
 findMaxPrimesForQuadratic();
}