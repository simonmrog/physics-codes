#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

/*Format of the file init_data.dat
theta0 t0 tf dt l

*/

#define PI 3.1415926535897932
#define g 9.8

void read_init_data(double&, double&, double&, double&, double&);
void calculate_state(double, double, double, double&, double&, double&, double&, double&, double&);
void output_data(ofstream&, double, double, double, double, double, double, double);

int main(){

    double theta0, t0, dt, tf, l, x, y, vx, vy;
    double delta_t, theta, w;
    ofstream output_file ("data.dat");
    output_file.precision(15);

    read_init_data(theta0, t0, tf, dt, l);

    for (double t=t0; t<=tf; t = t + dt){
        delta_t = t - t0;
        calculate_state(theta0, l, delta_t, theta, w, x, y, vx, vy);
        output_data(output_file, t, x, y, vx, vy, theta, w);
    }

    return (0);
}

void read_init_data(double& theta0, double& t0, double& tf, double& dt, double& l){

    ifstream input_file ("init_data.dat");
    input_file >> theta0 >> t0 >> tf >> dt >> l;
}

void calculate_state(double theta0, double l, double delta_t, double& theta, double& w, double& x,
                     double& y, double& vx, double& vy){

    double omega = sqrt(g/l);

    theta = theta0*cos(omega*delta_t);
    w = -omega*theta0*sin(omega*delta_t);

    x = l*sin(theta);
    y = -l*cos(theta);
    vx = l*w*sin(theta);
    vy = l*w*cos(theta);
}

void output_data(ofstream& output_file, double t, double x, double y, double vx, double vy, double theta, double w){

    output_file << t << " " << x << " " << y << " " << vx << " " << vy << " " << theta << " " << w << endl;
}
