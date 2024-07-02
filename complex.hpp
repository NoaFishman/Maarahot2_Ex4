/*
ID: 319055430
Email: noa.fishman@gmail.com
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace noa{

    class Complex{

        double re, im;

        public:
        // constractors
            Complex(double r, double i){
                re = r;
                im = i;
            }

            Complex(double i){
                re = 0;
                im = i;
            }

            Complex(){
                re = 0;
                im = 0;
            }

            // represent the object as string 
            string to_string() const {
                ostringstream oss;
                oss << re << " + " << im << "i";
                return oss.str();
            }

            // for the sorting 
            bool operator<(const Complex& other) const {
                double c1 = sqrt((re*re)+(im*im));
                double c2 = sqrt((other.re*other.re)+(other.im*other.im));
                return c1 < c2;  // Compare based on the real part
            }

            
    };

    template <typename T>
    inline string to_string(const T& value) {
        ostringstream oss;
        oss << value;
        return oss.str();
    }

    template <>
    inline string to_string(const noa::Complex& value) {
        return value.to_string();
    }

}

