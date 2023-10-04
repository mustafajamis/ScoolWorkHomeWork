
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
// TODO: complete prime tester function 
bool isPrime( int number){
    // TODO: complete the condition here 
    // guard negative numbers, 0 and 1, as they are not considered as prime numbers.  
    if ( number % 2 == 0 || number % 3 == 0) {
        return false; 
    }

    // TODO: complete the for loop to test all possible factors
    // possible factors starts from 2 (inclusive) and goes all the way to sqrt(n) + 1 (inclusive) 
    for (int i = 5; i *i <=number; i=i+6){ 
        if (number % i ==0 || number % (i +2)== 0)
            return false; 
        }

    // no factor found, return true
    return true; 
}

// question 2: to be completed by students. 
// TA may give general guidelines but will not help on code level. 
// develop a function to return the 10001st prime number. 
// correct answer: 104743
int the10001PrimeNumber() { 
    int counter = 0;
    // first prime number is 2 and we should start from 2
    int number =2;

    while(counter < 10001) {
        if (isPrime(number)) {
            counter++;
        }
        number++;
    }
    return number-1;
}



// TODO: please finish the main function.  
int main(){
    // question 1's main() function requirement: 
    // generate following output by using isPrime() function: 

   /*for (int i = 1; i<=19; i++) {
    if(isPrime(i)) {
        cout<<i<<"is a prime number\n";
    }
    else {
        cout<<i<<"is Not a prime number\n";
    }
   }
    */
    // question 2's code. 
    // Please complete the function the10001PrimeNumber() first, 
    // then uncomment following code to generate desired output
     std::cout << "The 10001st prime number: " << the10001PrimeNumber() << std::endl;


}