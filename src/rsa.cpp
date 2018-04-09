#include "../headers/rsa.h"

RSA::RSA(){
    generate_keys();
    srand (static_cast <unsigned> (time(0)));
}

long_int RSA::get_private_key(){
    return this->d;
}


std::vector<long_int> RSA::get_public_keys(){
    std::vector<long_int> vec;
    vec.push_back(this->n);
    vec.push_back(this->e);
    return vec;
}


std::vector<long_int> RSA::chy(std::string, int e, int n){
    

}


std::string RSA::unchy(std::string, int n, int d){
    
}


void RSA::generate_keys(){
    this->p = generate_prime();
    this->q = generate_prime();
}





long_int RSA::totient(long_int n){
    if(isprime(n)){
        return n - 1;
    }
}


bool RSA::isprime(int n){
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}


int RSA::generate_e(long_int toti_n){
    while(true){
        long_int e = this->generate_random(2, toti_n);
        if(this->mdc(n, e) == 1){
            return e;
        }
    }
}

int RSA::mdc(int x, int y){
    int rest = 1;
    while(y != 0){
        rest = x%y;
        x = y;
        y = rest;
    }
    return x;
}


long_int RSA::generate_prime(int size=2048){
    long_int e;
	do{
		e = generate_random();
	}while(!isprime(e));
    return e;
}

long_int RSA::generate_random(int from = 2, int to=pow(2,1024)){
	return static_cast <long_int> (rand()) /( static_cast <long_int> (to/(from-(-to))));
}

long_int RSA::mod(long_int x, long_int y){
    if(x < y){
        return x;
    }
    return x%y;
}


long_int RSA::private_key(long_int tot, long_int e){
    long_int d = 0;
    while(mod(d*e, tot) != 1){
        d++;
    }
    return d;
}

