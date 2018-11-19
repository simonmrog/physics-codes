#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>
using namespace std;

/*
Motion of an anisotropic harmonic oscillator:
Two forces with frequencies wx and wy of the form:
Fx = -m(wx)²x, Fy = -mw(wy)²y
Initial values:
x(0) = A, y(0) = 0, vx(0) = 0, vy(0) = wyA t0 = 0

The format of the input_file is:
wx wy tf dt
*/

#define PI 3.1415926535897932
#define g 9.8

class A_h_oscillator {

    private:

        double A, wx, wy;

    public:

    A_h_oscillator (double A, double wx, double wy) {

        this->A = A;
        this->wx = wx;
        this->wy = wy;
    }

    double * calculate_state(double t){

        double x, y, vx, vy;
        static double data[4];

        x = A * cos(wx * t);
        y = A * sin(wy * t);
        vx = -A * wx * sin(wx * t);
        vy = A * wy * cos(wy * t);

        data[0] = x;
        data[1] = y;
        data[2] = vx;
        data[3] = vy;

        return data;
    }

    ~A_h_oscillator (){}
};

int main(){

    double A, wx, wy, tf, dt;
    double *data;

    ifstream input_file ("init_data.dat");
    input_file >> A >> wx >> wy >> tf >> dt;

    ofstream output_file ("data.dat");
    output_file.precision(15);

    A_h_oscillator p (A, wx, wy);

    for (double t=0.0; t<=tf; t += dt){

        data = p.calculate_state(t);
        output_file << t << " " << data[0] << " " << data[1] << " " << data[2] << " " << data[3] << endl;
    }

    output_file.close();

    return (0);
}
