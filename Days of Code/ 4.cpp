using namespace std;
#include <iostream>
/*
Write a Person class with an instance variable, , and a constructor that takes an integer, , as a parameter. The constructor must assign  to  after confirming the argument passed as  is not negative; if a negative argument is passed as , the constructor should set  to  and print Age is not valid, setting age to 0.. In addition, you must write the following instance methods:

yearPasses() should increase the  instance variable by .
amIOld() should perform the following conditional actions:
If , print You are young..
If  and , print You are a teenager..
Otherwise, print You are old..
To help you learn by example and complete this challenge, much of the code is provided for you, but you'll be writing everything in the future. The code that creates each instance of your Person class is in the main method. Don't worry if you don't understand it all quite yet!

Note: Do not remove or alter the stub code in the editor.


*/
class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initialAge){
        // Add some more code to run some checks on initialAge
        if(initialAge<0){
            this->age=0;
            std::cout<<"Age is not valid, setting age to 0."<<std::endl;
        }
        else age=initialAge;
    }

    void Person::amIOld(){
        // Do some computations in here and print out the correct statement to the console 
    if(age<13){
        std::cout<<"You are young."<<std::endl;
    }
    else if(age>12&&age<18){
        std::cout<<"You are a teenager."<<std::endl;
        }
    else{
         std::cout<<"You are old."<<std::endl;
        }
    }

    void Person::yearPasses(){
        // Increment the age of the person in here
        age++;
    }

int main(){
    int t;
	int age;
    cin >> t;
    for(int i=0; i < t; i++) {
    	cin >> age;
        Person p(age);
        p.amIOld();
        for(int j=0; j < 3; j++) {
        	p.yearPasses(); 
        }
        p.amIOld();
      
		cout << '\n';
    }

    return 0;
}
