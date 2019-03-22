#Proyecto Final - Simón Murillo Gómez

from numpy import array
from numpy import zeros
from vpython import *
scene = canvas (width = 1000, height = 400, range = 300, title = "Particle Accelerator")

Vo = 50 #diferencia de potencial entre la fuente y el primer tubo
L1 = 100 #longitud del primer tubo (cm)
m = 10 #numero de tubos del acelerador
mp = 1.67 * 10 ** (-27) #masa particula a ser acelerada
q = 1.6 * 10 ** (-19) #carga particula a ser acelerada
d = L1 / 10 #distancia entre tubo y tubo (cm)

class accelerator: #clase acelerador
    def __init__(self, number, long1, dist): #crea el acelerador de particulas
        self.m = number
        self.L1 = long1
        self.d = dist
        self.xi = zeros(self.m) #vector que guarda las posiciones de cada tubo
        x = -800 #x inicial
        
        c = cylinder (pos=vector(x-self.d, 0, 0), radius = 50)
        #creamos un disco que simula la salida
        
        for i in range (1, self.m+1, 1):
            Ln = sqrt(i)*self.L1 #longitud del iésimo tubo

            #Extrusion que crea cada tubo
            a = shapes.circle(radius = 40)
            b = shapes.circle(radius = 50)
            s = [vec(x, 0, 0), vec(x+Ln, 0, 0)]
            # aux = Polygon([(0, -50), (0, 50), (50, 50), (50, -50)])
            # aux = shapes.hexagon (length=15);
            c = extrusion(path=s, shape = [b, a], color = color.gray (0.5))
            
            self.xi[i-1] = x #posicion del tubo iésimo
            x = x + Ln + self.d #x del próximo tubo

        
class particle: #clase particula
    def __init__ (self, mass, q0, velocity, x0):
        self.m = mass
        self.v = velocity
        self.x0 = x0
        self.q = q0
        self.p = sphere(pos=vector(x0, 0, 0), color = color.yellow, radius = 10)

    def x(self, t): #posicion de la partícula
        return self.v*t + self.x0

    def move(self):

        L = label (pos=vector(0, 100, 0)) #Muestra la velocidad que lleva en el tubo
        K = label (pos=vector(0, 200, 0)) #Muestra la energía cinética que lleva en el tubo

        for i in range (1, acc.m+1, 1): #ciclo para todos los tubos
            x0 = acc.xi[i-1] - d
            L.text = ""
            K.text = ""
            #mientras cambia de tubo
            self.v =  sqrt(self.v**2 + 4*self.q*Vo/self.m) #incrementa la velocidad
            L.text=("v = " + str(round(self.v, 2)) + " m/s")
            Ke = (1/2)*self.m*(self.v)**2
            K.text=("K = " + str(round(Ke/(1.6*10**-16), 2)) + " MeV")
            
            if (self.v != 0):
                rate(1.0e-3*self.v) #controla la velocidad de la simulacion
                Ln = sqrt(i)*acc.L1
                tn = Ln/self.v #tiempo que se demora en recorrer el tubo
                dt = tn / 100 #particion del tiempo
                ti = 0 #acumulador de tiempo
                
                for j in range(1, 101, 1): #ciclo dentro del tubo
                    
                    rate(1.0e-3*self.v)
                    self.p.pos=vector(self.v*ti + x0, 0, 0) #grafica punto a punto
                    ti = ti + dt #incrementa el tiempo

acc = accelerator(m, L1, d) #Crea el acelerador
particleA = particle(mp, q, 0, -810) #Crea la partícula
particleA.move() #Mueve la particula
