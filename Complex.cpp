
#include <iostream>
#include <math.h>
using namespace std;
class Complex{
private:
    double RealPart;
    double ImagPart;
public:
    Complex(double=0,double=0);
    void setComplex(double,double);
    void Convert(double&,double&);
    void printCartesian();
    void printPolar();
    Complex AddComplex(Complex);
    Complex SubComplex(Complex);
    Complex MulComplex(Complex);
    Complex DivComplex(Complex);
};
Complex::Complex(double R_P,double I_P){
    setComplex(R_P,I_P);
}

void Complex::setComplex(double R_P ,double I_P){
    RealPart =R_P;
    ImagPart=I_P;
}
Complex Complex::AddComplex(Complex second){
    Complex z;
    z.RealPart=RealPart+second.RealPart;
    z.ImagPart=ImagPart+second.ImagPart;
    return z;

}
Complex Complex::SubComplex(Complex second){
    Complex z;
    z.RealPart=RealPart-second.RealPart;
    z.ImagPart=ImagPart-second.ImagPart;
        return z;



}
Complex Complex::MulComplex(Complex second){
    Complex z;
    z.RealPart=RealPart*second.RealPart-ImagPart*second.ImagPart;
    z.ImagPart=RealPart*second.ImagPart+ImagPart*second.RealPart;
        return z;
}
Complex Complex::DivComplex(Complex second){
    double r1 , t1 ,r2,t2;
    Convert( r1 , t1 );
    second.Convert( r2 , t2 );
    double r = r1 / r2 ;
    double t = t1 - t2 ;
    Complex z(r, t);
    return (z);
}

void Complex::Convert(double& r,double& theta){
    r =sqrt(pow(RealPart,2)+pow(ImagPart,2));
   theta=atan(ImagPart/RealPart);
}
void Complex::printPolar(){
    cout<<RealPart<<" * "<<"e^(i * "<<ImagPart<<")"<<endl;
}
void Complex::printCartesian(){
    if(RealPart==0)
        cout<<ImagPart<<"i"<<endl;
    if (ImagPart==0)
        cout<<RealPart<<"i"<<endl;
    if(RealPart!=0 && ImagPart!=0)
        cout<<RealPart<<" + "<<ImagPart<<"i"<<endl;
}
//

int main() {
    double R1,I1,R2,I2;
 cout<<"enter the first complex number: "<<endl;
//    shape:2 3 the first complex number
//          2 1 the second complex number
     cin>>R1>>I1;
 Complex c1(R1,I1);
 cout<<"enter the second complex number: "<<endl;
     cin>>R2>>I2;
    Complex c2(R2,I2);
    // addition:
    Complex add=c1.AddComplex(c2);
    add.printCartesian();
    // subtraction:
    Complex sub=c1.SubComplex(c2);
    sub.printCartesian();
    // multiplication:
    Complex mul=c1.MulComplex(c2);
    mul.printCartesian();
    // division:
    Complex div=c1.DivComplex(c2);
    div.printPolar();
    return 0;
}

