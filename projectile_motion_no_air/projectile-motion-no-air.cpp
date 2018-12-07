#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

#define PI 3.1415926535897932
#define g 9.8

class Projectile {

    private:

        double v0, theta, t0;
        double dt, tf;

    public:

    Projectile (double v0, double theta, double t0, double tf, double dt) {

        this->v0 = v0;
        this->theta = theta * (PI / 180.0);
        this->t0 = t0;
        this->tf = tf;
        this->dt = dt;
    }

    void calculate_trayectory(){

        double x, y, vx, vy;
        double v0x, v0y;
        ofstream output_file ("data.dat");
        output_file.precision(15);

        v0x = v0 * cos(theta);
        v0y = v0 * sin(theta);

        for (double t=t0; t<=tf; t = t + dt){

            x = v0x*(t-t0);
            y = v0y*(t-t0) - 0.5*g*(t-t0)*(t-t0);
            vx = v0x;
            vy = v0y - g*(t-t0);
            output_file << t << " " << x << " " << y << " " << vx << " " << vy << endl;
        }

        output_file.close();
    }

    ~Projectile (){}
};

int main(){

    double v0, theta, t0, tf, dt;

    ifstream input_file ("init_data.dat");

    input_file >> v0 >> theta >> t0 >> tf >> dt;

    Projectile P (v0, theta, t0, tf, dt);
    P.calculate_trayectory();

    return (0);
}
