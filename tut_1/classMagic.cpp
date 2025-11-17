#include <iostream>
using namespace std;

class Complex
{
public:
    void set(float r, float im)
    {
        real = r;
        imag = im;
    }
    void copy(Complex c)
    {
        real = c.real;
        imag = c.imag;
    }
    void display()
    {
        cout << "[real= " << real
             << ", imag= " << imag
             << "]" << endl;
    }
    void multiply(Complex c)
    {
        float r = real * c.real - imag * c.imag;
        float i = real * c.imag + c.real * imag;
        real = r;
        imag = i;
    }
    void add(Complex c)
    {
        real += c.real;
        imag += c.imag;
    }
    void minus(Complex c)
    {
        real -= c.real;
        imag -= c.imag;
    }

private:
    float real, imag;
};

int main()
{
    float r1, i1, r2, i2, r3, i3;
    cout << "-> ";
    cin >> r1 >> i1;
    cout << "-> ";
    cin >> r2 >> i2;
    cout << "-> ";
    cin >> r3 >> i3;

    Complex equation1;
    Complex equation2;

    Complex num1;
    Complex num2;
    Complex num3;

    num1.set(r1, i1);
    num2.set(r2, i2);
    num3.set(r3, i3);

    equation1.add(num1);
    equation1.add(num2);
    equation1.add(num3);
    equation1.multiply(num1);

    equation2.copy(num2);
    equation2.multiply(num3);

    equation1.minus(equation2);

    equation1.display();

    // TODO: Write your code here
    // Begin Question
    // goal: d = ((c1+c2+c3)*c1) - (c2*c3);

    // End Question

    system("pause");
    return 0;
}