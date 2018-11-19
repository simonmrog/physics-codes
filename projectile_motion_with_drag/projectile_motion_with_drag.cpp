#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <stdio.h>
using namespace std;

/*
Motion of a projectile of mass m subjected to a drag force of the form F = -mkv
with initial conditions x(0) = y(0) = 0
vx(0) = v0x = v0 * cos(theta), vy(0) = v0y = v0 * sin(theta)
Equations of motion solved mathematically and used in the algorithm.
*/

#define PI 3.1415926535897932
#define g 9.8

class Projectile {

    private:

        double v0, theta, v0x, v0y;
        double dt, tf;
        double k;

    public:

    Projectile (double k, double v0, double theta, double tf, double dt) {

        this->k = k;
        this->v0 = v0;
        this->theta = theta * (PI / 180.0);
        this->tf = tf;
        this->dt = dt;

        v0x = v0 * cos(this->theta);
        v0y = v0 * sin(this->theta);
    }

    double * calculate_state(double t){

        double x, y, vx, vy;
        static double data[4];

        x = (v0x / k) * (1.0 - exp(-k * t));
        y = (1.0 / k) * (v0y + g / k) * (1.0 - exp(-k * t)) - (g / k) * t;
        vx = v0x * exp(-k * t);
        vy = (v0y + g / k) * exp(-k * t) - g / k;

        data[0] = x;
        data[1] = y;
        data[2] = vx;
        data[3] = vy;

        return data;
    }

    ~Projectile (){}
};

int main(){

    int N;
    double k, v0, theta, tf, dt;
    double *data;

    ifstream input_file ("init_data.dat");

    input_file >> N;

    for (int i=0; i<N; i++) {

        input_file >> k >> v0 >> theta >> tf >> dt;

        ostringstream number;
        number << i + 1;
        string file_name = string("data") + number.str() + ".dat";
        ofstream output_file (file_name.c_str());
        output_file.precision(15);

        Projectile p (k, v0, theta, tf, dt);

        for (double t=0.0; t<=tf; t += dt){

            data = p.calculate_state(t);
            output_file << t << " " << data[0] << " " << data[1] << " " << data[2] << " " << data[3] << endl;
            if (data[1] < 0) t = tf + 1;
        }

        output_file.close();
    }

    return (0);
}
